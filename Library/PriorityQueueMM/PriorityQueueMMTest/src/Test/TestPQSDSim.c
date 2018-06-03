#include "TestPQSDSim.h"

extern int TestResults_IsDispItemNULL;
extern int TestResults_DispItem;

static int TestPQSDSimChunk_Create(TestPQSDSim* Owner){
    if(Owner == NULL){
        printf("[ERROR] Creation of \"TestPQSDSimChunk\"-object failed!\n");
        printf("        \"Owner\" not available! (NULL)\n");
        return 0;
    }
    TestPQSDSimChunk* res = (TestPQSDSimChunk*)malloc(sizeof(TestPQSDSimChunk) + (sizeof(void*) * 32));
    if(res == NULL){
        printf("[ERROR] Creation of \"TestPQSDSimChunk\"-object failed!\n");
        printf("        Memory could not be allocated!\n");
        return 0;
    }
    res->Owner = Owner;
    if(Owner->ChunkCount <= 0){
        Owner->FirstChunk = res;
        Owner->LastChunk = res;
        res->Next = NULL;
        res->Prev = NULL;
        Owner->ChunkCount = 1;
    }else{
        res->Prev = Owner->LastChunk;
        Owner->LastChunk->Next = res;
        res->Next = NULL;
        Owner->LastChunk = res;
        Owner->ChunkCount++;
    }
    return 1;
}

static int TestPQSDSimChunk_Dispose(TestPQSDSimChunk* C){
    if(C == NULL){return 1;}
    if(C->Next != NULL){return 0;}
    if(C->Prev != NULL){C->Prev->Next = NULL;}
    C->Owner->ChunkCount--;
    free((void*)C);
    return 1;
}




TestPQSDSim* TestPQSDSim_Create(int(*compare)(void*,void*),int(*disposeItem)(void*,ERRVAL_T*),TestResults* Res){

    if(compare == NULL){
        printf("[ERROR] Creation of \"TestPQSDSim\"-object failed!\n");
        printf("        \"compare\"-function-ptr invalid!\n");
        return NULL;
    }

    if(disposeItem == NULL){
        printf("[ERROR] Creation of \"TestPQSDSim\"-object failed!\n");
        printf("        \"disposeItem\"-function-ptr invalid!\n");
        return NULL;
    }

    TestPQSDSim* res = (TestPQSDSim*)malloc(sizeof(TestPQSDSim));
    if(res == NULL){
        printf("[ERROR] Creation of \"TestPQSDSim\"-object failed!\n");
        printf("        Memory could not be allocated!\n");
        return NULL;
    }

    res->ChunkCount = 0;
    res->Count = 0;

    if(!TestPQSDSimChunk_Create(res)){
        printf("        Creation of \"TestPQSDSim\"-object failed!\n");
        free((void*)res);
        return NULL;
    }

    res->compare = compare;
    res->disposeItem = disposeItem;
    if(!TestPQSDSim_UpdateRes1(res,Res,0)){
        printf("        Creation of \"TestPQSDSim\"-object failed!\n");
        free((void*)res);
        return NULL;
    }
    return res;
}

int TestPQSDSim_Insert(TestPQSDSim* P,void* Item,TestResults* Res){
    if(P == NULL){return -1;}
    int ret = 0;
    if(Item == NULL){goto END;}
    if((P->Count >= P->ChunkCount * 32)&&(!TestPQSDSimChunk_Create(P))){
        printf("        Function \"TestPQSDSim_Insert\" failed!\n");
        return -1;
    }
    if(!(P->Count)){
        P->FirstChunk->Items[0] = Item;
        P->Count++;
        ret = 1;
        goto END;
    }
    void** Item1Ptr;
    void** Item2Ptr;
    TestPQSDSimChunk* CurChunk = P->LastChunk;
    int ChunkIndex = (P->Count - 1) & 31;
    if(!(P->Count & 31)){
        if(P->LastChunk->Next != NULL){P->LastChunk = P->LastChunk->Next;}
        Item1Ptr = (void**)(&(P->LastChunk->Items[0]));
        CurChunk = P->LastChunk->Prev;
    }else{
        Item1Ptr = (void**)(&(CurChunk->Items[(P->Count & 31)]));
    }
    int i;
    int Stop = 0;
    while(CurChunk != NULL){
        for(i = ChunkIndex;i >= 0;i--){
            Item2Ptr = (void**)(&(CurChunk->Items[i]));
            if(P->compare(*Item2Ptr,Item) >= 0){
                *Item1Ptr = Item;
                Stop = 1;
                break;
            }
            *Item1Ptr = *Item2Ptr;
            Item1Ptr = Item2Ptr;
        }
        if(Stop){break;}
        ChunkIndex = 31;
        CurChunk = CurChunk->Prev;
    }
    if(!Stop){
        P->FirstChunk->Items[0] = Item;
    }
    P->Count++;
    ret = 1;

    END:
    if(!TestPQSDSim_UpdateRes1(P,Res,ret)){return -1;}
    return ret;
}

void* TestPQSDSim_GetMin(TestPQSDSim* P){
    if((P == NULL)||(P->Count <= 0)){return NULL;}
    return P->FirstChunk->Items[0];
}

void* TestPQSDSim_GetMax(TestPQSDSim* P){
    if((P == NULL)||(P->Count <= 0)){return NULL;}
    return P->LastChunk->Items[(P->Count - 1) & 31];
}

int TestPQSDSim_RemoveMin(TestPQSDSim* P,TestResults* Res){
    if(P == NULL){return -1;}
    int ret = 0;
    if(P->Count <= 0){goto END;}
    if(P->Count == 1){
        P->Count = 0;
        ret = 1;
        goto END;
    }
    int ChunkIndex = 1;
    TestPQSDSimChunk* CurChunk = P->FirstChunk;
    void** Item1Ptr = (void**)(&(P->FirstChunk->Items[0]));
    void** Item2Ptr;

    int i;
    int EndIndex;
    while(CurChunk != NULL){
        EndIndex = 32;
        if(CurChunk == P->LastChunk){EndIndex = ((P->Count - 1) & 31) + 1;}
        for(i = ChunkIndex;i < EndIndex;i++){
            Item2Ptr = (void**)(&(CurChunk->Items[i]));
            *Item1Ptr = *Item2Ptr;Item1Ptr = Item2Ptr;
        }
        ChunkIndex = 0;
        CurChunk = CurChunk->Next;
    }
    P->Count--;
    if(!(P->Count & 31)){P->LastChunk = P->LastChunk->Prev;}
    if(P->ChunkCount * 32 - P->Count > 48){TestPQSDSimChunk_Dispose(P->LastChunk->Next);}
    ret = 1;

    END:
    if(!TestPQSDSim_UpdateRes1(P,Res,ret)){return -1;}
    return ret;
}

int TestPQSDSim_RemoveMax(TestPQSDSim* P,TestResults* Res){
    if(P == NULL){return -1;}
    int ret = 0;
    if(P->Count <= 0){goto END;}
    if(P->Count == 1){
        P->Count = 0;
        ret = 1;
        goto END;
    }
    P->Count--;
    if(!(P->Count & 31)){P->LastChunk = P->LastChunk->Prev;}
    if(P->ChunkCount * 32 - P->Count > 48){TestPQSDSimChunk_Dispose(P->LastChunk->Next);}
    ret = 1;

    END:
    if(!TestPQSDSim_UpdateRes1(P,Res,ret)){return -1;}
    return ret;
}

int TestPQSDSim_RemoveMinSource(TestPQSDSim* P,TestResults* Res){
    if(P == NULL){return -1;}
    int ret = 0;
    if(P->Count <= 0){goto END;}
    if(P->Count == 1){
        if(!P->disposeItem(P->FirstChunk->Items[0],NULL)){goto END;}
        P->Count = 0;
        ret = 1;
        goto END;
    }
    int ChunkIndex = 1;
    TestPQSDSimChunk* CurChunk = P->FirstChunk;
    void** Item1Ptr = (void**)(&(P->FirstChunk->Items[0]));
    void** Item2Ptr;

    if(!P->disposeItem(*Item1Ptr,NULL)){goto END;}

    int i;
    int EndIndex;
    while(CurChunk != NULL){
        EndIndex = 32;
        if(CurChunk == P->LastChunk){EndIndex = ((P->Count - 1) & 31) + 1;}
        for(i = ChunkIndex;i < EndIndex;i++){
            Item2Ptr = (void**)(&(CurChunk->Items[i]));
            *Item1Ptr = *Item2Ptr;Item1Ptr = Item2Ptr;
        }
        ChunkIndex = 0;
        CurChunk = CurChunk->Next;
    }
    P->Count--;
    if(!(P->Count & 31)){P->LastChunk = P->LastChunk->Prev;}
    if(P->ChunkCount * 32 - P->Count > 48){TestPQSDSimChunk_Dispose(P->LastChunk->Next);}
    ret = 1;

    END:
    if(!TestPQSDSim_UpdateRes1(P,Res,ret)){return -1;}
    return ret;
}

int TestPQSDSim_RemoveMaxSource(TestPQSDSim* P,TestResults* Res){
    if(P == NULL){return -1;}
    int ret = 0;
    if(P->Count <= 0){goto END;}
    if(P->Count == 1){
        if(!P->disposeItem(P->FirstChunk->Items[0],NULL)){goto END;}
        P->Count = 0;
        ret = 1;
        goto END;
    }
    if(!P->disposeItem(P->LastChunk->Items[(P->Count - 1) & 31],NULL)){goto END;}
    P->Count--;
    if(!(P->Count & 31)){P->LastChunk = P->LastChunk->Prev;}
    if(P->ChunkCount * 32 - P->Count > 48){TestPQSDSimChunk_Dispose(P->LastChunk->Next);}
    ret = 1;

    END:
    if(!TestPQSDSim_UpdateRes1(P,Res,ret)){return -1;}
    return ret;
}

int TestPQSDSim_UpdateRes1(TestPQSDSim* P,TestResults* Res,int Ret){
    if((P == NULL)||(Res == NULL)){return 0;}

    //Header:
    Res->ReservedMemory = sizeof(TestPQSDSim) + P->ChunkCount * (sizeof(TestPQSDSimChunk) + sizeof(void*) * 32);
    Res->ReservedItems = P->ChunkCount * 32;
    Res->IsFixedSize = 0;
    Res->Count = P->Count;


    //Elems:
    Res->DispItem = -1;
    if(Res->Count <= 0){
        Res->IsMaxNULL = 1;
        Res->IsMinNULL = 1;
        Res->Max = -1;
        Res->Min = -1;
    }else{
        Res->IsMaxNULL = 0;
        Res->IsMinNULL = 0;
        Res->Min = *((int*)TestPQSDSim_GetMin(P));
        Res->Max = *((int*)TestPQSDSim_GetMax(P));
    }

    Res->IsDispItemNULL = TestResults_IsDispItemNULL;
    if(!Res->IsDispItemNULL){Res->DispItem = TestResults_DispItem;}

    TestResults_IsDispItemNULL = 1;
    TestResults_DispItem = -1;

    //Function-Res:
    Res->Res.RetPtr = NULL;
    Res->Res.RetInt = Ret;
    return 1;
}

int TestPQSDSim_UpdateRes2(TestPQSDSim* P,TestResults* Res,void* Ret){
    if((P == NULL)||(Res == NULL)){return 0;}

    //Header:
    Res->ReservedMemory = sizeof(TestPQSDSim) + P->ChunkCount * (sizeof(TestPQSDSimChunk) + sizeof(void*) * 32);
    Res->ReservedItems = P->ChunkCount * 32;
    Res->IsFixedSize = 0;
    Res->Count = P->Count;


    //Elems:
    Res->DispItem = -1;
    if(Res->Count <= 0){
        Res->IsMaxNULL = 1;
        Res->IsMinNULL = 1;
        Res->Max = -1;
        Res->Min = -1;
    }else{
        Res->IsMaxNULL = 0;
        Res->IsMinNULL = 0;
        Res->Min = *((int*)TestPQSDSim_GetMin(P));
        Res->Max = *((int*)TestPQSDSim_GetMax(P));
    }

    Res->IsDispItemNULL = TestResults_IsDispItemNULL;
    if(!Res->IsDispItemNULL){Res->DispItem = TestResults_DispItem;}

    TestResults_IsDispItemNULL = 1;
    TestResults_DispItem = -1;

    //Function-Res:
    Res->Res.RetInt = 0;
    Res->Res.RetPtr = Ret;
    return 1;
}

void TestPQSDSim_Dispose(TestPQSDSim* P){
    if(P == NULL){return;}
    TestPQSDSimChunk* CurChunk = P->LastChunk;
    TestPQSDSimChunk* NxtChunk;
    if(CurChunk->Next != NULL){CurChunk = CurChunk->Next;}
    while(CurChunk != NULL){
        NxtChunk = CurChunk->Prev;
        TestPQSDSimChunk_Dispose(CurChunk);
        CurChunk = NxtChunk;
    }
    free((void*)P);
}
