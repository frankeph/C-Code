#include "TestPQADSim.h"

#ifndef TESTPQADSIM_DOCHECKS
#define TestPQADSim_Check(P)    (1)
#endif // TESTPQADSIM_DOCHECKS

extern int TestResults_IsDispItemNULL;
extern int TestResults_DispItem;

static int TestPQADSimChunk_Create(TestPQADSim* Owner){
    if(Owner == NULL){
        printf("[ERROR] Creation of \"TestPQADSimChunk\"-object failed!\n");
        printf("        \"Owner\" not available! (NULL)\n");
        return 0;
    }
    TestPQADSimChunk* res = (TestPQADSimChunk*)malloc(sizeof(TestPQADSimChunk) + (sizeof(void*) * 32));
    if(res == NULL){
        printf("[ERROR] Creation of \"TestPQADSimChunk\"-object failed!\n");
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

static int TestPQADSimChunk_CreateA(TestPQADSim* Owner){
    if(Owner == NULL){
        printf("[ERROR] Creation of \"TestPQADSimChunk\"-object failed!\n");
        printf("        \"Owner\" not available! (NULL)\n");
        return 0;
    }
    TestPQADSimChunk* res = (TestPQADSimChunk*)calloc(1,sizeof(TestPQADSimChunk) + (sizeof(void*) * 32));
    if(res == NULL){
        printf("[ERROR] Creation of \"TestPQADSimChunk\"-object failed!\n");
        printf("        Memory could not be allocated!\n");
        return 0;
    }
    res->Owner = Owner;
    if(Owner->AChunkCount <= 0){
        Owner->ALastChunk = res;
        Owner->ACurChunk = res;
        res->Next = NULL;
        res->Prev = NULL;
        Owner->AChunkCount = 1;
    }else{
        res->Prev = Owner->ALastChunk;
        Owner->ALastChunk->Next = res;
        res->Next = NULL;
        Owner->ALastChunk = res;
        Owner->ACurChunk = res;
        Owner->AChunkCount++;
    }
    return 1;
}




static int TestPQADSimChunk_Dispose(TestPQADSimChunk* C){
    if(C == NULL){return 1;}
    if(C->Next != NULL){return 0;}
    if(C->Prev != NULL){C->Prev->Next = NULL;}
    C->Owner->ChunkCount--;
    free((void*)C);
    return 1;
}

static int TestPQADSimChunk_DisposeA(TestPQADSimChunk* C){
    if(C == NULL){return 1;}
    if(C->Next != NULL){return 0;}
    if(C->Prev != NULL){C->Prev->Next = NULL;}
    C->Owner->AChunkCount--;
    free((void*)C);
    return 1;
}

static PriorityQueueMMAItem* TestPQADSim_GetNewChunkItem(TestPQADSim* P){
    if(P == NULL){return NULL;}
    PriorityQueueMMAItem* res = NULL;
    int i;
    while(P->ACurChunk != NULL){
        for(i = 0;i < 31;i = i + 2){
            if(P->ACurChunk->Items[i] == NULL){
                res = (PriorityQueueMMAItem*)(&(P->ACurChunk->Items[i]));
                break;
            }
        }
        if(res != NULL){break;}
        P->ACurChunk = P->ACurChunk->Next;
    }
    if(res != NULL){return res;}
    if(!TestPQADSimChunk_CreateA(P)){return NULL;}
    return ((PriorityQueueMMAItem*)(&(P->ACurChunk->Items[0])));
}

static TestPQADSimChunk* TestPQADSim_FindChunk(TestPQADSim* P,PriorityQueueMMAItem* I){
    if((P == NULL)||(I == NULL)){return NULL;}
    TestPQADSimChunk* CurChunk = P->ALastChunk;
    TestPQADSimChunk* res = NULL;
    uintptr_t MinPos;
    uintptr_t MaxPos;
    uintptr_t CurPos = (uintptr_t)I;
    while(CurChunk != NULL){
        MinPos = (uintptr_t)CurChunk;
        MaxPos = (uintptr_t)(&(CurChunk->Items[31]));
        if((CurPos >= MinPos)&&(CurPos <= MaxPos)){res = CurChunk;break;}
        CurChunk = CurChunk->Prev;
    }
    if(res == NULL){return NULL;}
    MinPos = (uintptr_t)(&(CurChunk->Items[0]));
    MaxPos = (uintptr_t)(&(CurChunk->Items[30]));
    if((CurPos < MinPos)||(CurPos > MaxPos)){return NULL;}
    if(((CurPos - MinPos) / sizeof(void*)) & 1){return NULL;}
    return res;
}

static int TestPQADSim_RemoveChunkItem(TestPQADSim* P,PriorityQueueMMAItem* I){
    if((P == NULL)||(I == NULL)){return 0;}
    TestPQADSimChunk* Chunk = TestPQADSim_FindChunk(P,I);
    if(Chunk == NULL){return 0;}
    void** Item = (void**)I;
    if(Item[0] == NULL){return 0;}
    Item[0] = NULL;
    Item[1] = NULL;
    if(Chunk != P->ACurChunk){
        if(Chunk != P->ALastChunk){
            TestPQADSimChunk* Prev = Chunk->Prev;
            TestPQADSimChunk* Next = Chunk->Next;

            if(Prev != NULL){Prev->Next = Next;}
            if(Next != NULL){Next->Prev = Prev;}

            Prev = P->ACurChunk->Prev;

            Chunk->Next = P->ACurChunk;
            Chunk->Prev = Prev;
            if(Prev != NULL){Prev->Next = Chunk;}
            P->ACurChunk->Prev = Chunk;
            P->ACurChunk = Chunk;
        }
    }
    return 1;
}



TestPQADSim* TestPQADSim_Create(int(*compare)(void*,void*),int(*disposeItem)(void*,ERRVAL_T*),TestResults* Res){

    if(compare == NULL){
        printf("[ERROR] Creation of \"TestPQADSim\"-object failed!\n");
        printf("        \"compare\"-function-ptr invalid!\n");
        return NULL;
    }

    if(disposeItem == NULL){
        printf("[ERROR] Creation of \"TestPQADSim\"-object failed!\n");
        printf("        \"disposeItem\"-function-ptr invalid!\n");
        return NULL;
    }

    TestPQADSim* res = (TestPQADSim*)malloc(sizeof(TestPQADSim));
    if(res == NULL){
        printf("[ERROR] Creation of \"TestPQADSim\"-object failed!\n");
        printf("        Memory could not be allocated!\n");
        return NULL;
    }
    res->AChunkCount = 0;
    res->ChunkCount = 0;
    res->Count = 0;

    if(!TestPQADSimChunk_Create(res)){
        printf("        Creation of \"TestPQADSim\"-object failed!\n");
        free((void*)res);
        return NULL;
    }

    if(!TestPQADSimChunk_CreateA(res)){
        printf("        Creation of \"TestPQADSim\"-object failed!\n");
        TestPQADSimChunk_Dispose(res->ACurChunk);
        free((void*)res);
        return NULL;
    }

    res->compare = compare;
    res->disposeItem = disposeItem;
    if(!TestPQADSim_UpdateRes1(res,Res,0)){
        printf("        Creation of \"TestPQADSim\"-object failed!\n");
        free((void*)res);
        return NULL;
    }
    return res;
}

void TestPQADSim_Print(TestPQADSim* P){
    if(P == NULL){return;}
    printf("[INFO] Printing \"TestPQADSim\":\n");
    printf("      ");
    int i;
    void** Item2Ptr;
    void** AItem2;
    TestPQADSimChunk* CurChunk = P->FirstChunk;
    for(i = 0;i < P->Count;i++){
        if((!(i & 31))&&(i > 0)){CurChunk = CurChunk->Next;}
        Item2Ptr = (void**)(&(CurChunk->Items[(i & 31)]));
        AItem2 = (void**)(*Item2Ptr);
        printf("%3i ",*((int*)(AItem2[1])));
    }
    printf("\n");
}

#ifdef TESTPQADSIM_DOCHECKS
static int TestPQADSim_Check(TestPQADSim* P){
    if(P == NULL){return 0;}
    if(P->Count <= 1){return 1;}
    int i;
    void** Item2Ptr;
    void** AItem1;
    void** AItem2;
    TestPQADSimChunk* CurChunk = P->FirstChunk;
    Item2Ptr = (void**)(&(CurChunk->Items[0]));
    AItem2 = (void**)(*Item2Ptr);
    for(i = 0;i + 1 < P->Count;i++){
        if(!((i + 1) & 31)){CurChunk = CurChunk->Next;}
        AItem1 = AItem2;
        Item2Ptr = (void**)(&(CurChunk->Items[((i + 1) & 31)]));
        AItem2 = (void**)(*Item2Ptr);
        if(P->compare(AItem1[1],AItem2[1]) < 0){
            printf("[ERROR] Invariant of \"TestPQADSim\" broken!\n");
            TestPQADSim_Print(P);
            return 0;
        }
    }
    return 1;
}
#endif // TESTPQADSIM_DOCHECKS

static void TestPQADSim_Swap(PriorityQueueMMAItem* I1,PriorityQueueMMAItem* I2){
    void** Item1 = (void**)I1;
    void** Item2 = (void**)I2;
    void** Slot1 = (void**)(Item1[0]);
    void** Slot2 = (void**)(Item2[0]);
    *Slot1 = (void*)I2;
    *Slot2 = (void*)I1;
    Item1[0] = (void*)Slot2;
    Item2[0] = (void*)Slot1;
}

PriorityQueueMMAItem* TestPQADSim_GetInsertedItem(TestPQADSim* P,void* Item,TestResults* Res){
    if(P == NULL){return NULL;}
    void* ret = NULL;
    if(Item == NULL){goto END;}
    void** AItem1 = (void**)TestPQADSim_GetNewChunkItem(P);
    if(AItem1 == NULL){
        printf("        Function \"TestPQADSim_GetInsertedItem\" failed!\n");
        return NULL;
    }
    if((P->Count >= P->ChunkCount * 32)&&(!TestPQADSimChunk_Create(P))){
        printf("        Function \"TestPQADSim_GetInsertedItem\" failed!\n");
        return NULL;
    }
    void** Item1Ptr;
    void** Item2Ptr;
    TestPQADSimChunk* CurChunk = P->LastChunk;
    //int ChunkIndex = P->Count & 31;
    void** AItem2;
    if((P->Count)&&(!(P->Count & 31))){
        if(P->LastChunk->Next != NULL){P->LastChunk = P->LastChunk->Next;}
        Item1Ptr = (void**)(&(P->LastChunk->Items[0]));
        CurChunk = P->LastChunk->Prev;
    }else{
        Item1Ptr = (void**)(&(CurChunk->Items[(P->Count & 31)]));
    }
    *Item1Ptr = (void*)AItem1;
    AItem1[0] = (void*)Item1Ptr;
    AItem1[1] = Item;
    int i = P->Count - 1;
    while(i >= 0){
        Item2Ptr = (void**)(&(CurChunk->Items[(i & 31)]));
        AItem2 = (void**)(*Item2Ptr);

        if(P->compare(AItem2[1],AItem1[1]) >= 0){break;}
        TestPQADSim_Swap(((PriorityQueueMMAItem*)AItem2),((PriorityQueueMMAItem*)AItem1));
        if(!(i & 31)){
            CurChunk = CurChunk->Prev;
        }
        i--;
    }
    P->Count++;
    ret = Item;

    END:
    if(!TestPQADSim_UpdateRes2(P,Res,ret)){return NULL;}
    if(ret == NULL){return NULL;}
    return ((PriorityQueueMMAItem*)AItem1);
}

void* TestPQADSim_GetMin(TestPQADSim* P){
    if((P == NULL)||(P->Count <= 0)){return NULL;}
    return ((void**)(P->FirstChunk->Items[0]))[1];
}

void* TestPQADSim_GetMax(TestPQADSim* P){
    if((P == NULL)||(P->Count <= 0)){return NULL;}
    return ((void**)(P->LastChunk->Items[(P->Count - 1) & 31]))[1];
}

int TestPQADSim_ContainsItem(TestPQADSim* P,PriorityQueueMMAItem* Item,TestResults* Res){
    if(P == NULL){return -1;}
    TestPQADSimChunk* Chunk = TestPQADSim_FindChunk(P,Item);
    int ret = ((Chunk != NULL)&&(((void**)Item)[0] != NULL));

    if(!TestPQADSim_UpdateRes1(P,Res,ret)){return -1;}
    return ret;
}

int TestPQADSim_SetItemOfItem(TestPQADSim* P,PriorityQueueMMAItem* Item,void* ItemValue,TestResults* Res){
    if(P == NULL){return -1;}
    TestPQADSimChunk* Chunk = TestPQADSim_FindChunk(P,Item);
    int ret = 0;
    if(!((Chunk != NULL)&&(((void**)Item)[0] != NULL))){
        #ifdef TESTENVIRONMENT_SHOWALL
        printf("[INFO] Item INVALID!\n");
        #endif // TESTENVIRONMENT_SHOWALL
        #ifdef TESTENVIRONMENT_VALIDCALLS
        return -1;
        #endif // TESTENVIRONMENT_VALIDCALLS
        goto END;
    }
    #ifndef TESTENVIRONMENT_VALIDCALLS
    if((((void**)Item)[1]) == ((void*)ItemValue)){return TestPQADSim_UpdateItem(P,Item,Res);}
    #else // TESTENVIRONMENT_VALIDCALLS
    if((((void**)Item)[1]) == ItemValue){return -1;}
    #endif // TESTENVIRONMENT_VALIDCALLS

    int CurIndex = 0;
    TestPQADSimChunk* CurChunk = P->FirstChunk;
    uintptr_t CurPos = (uintptr_t)(((void**)Item)[0]);
    uintptr_t MinPos;
    uintptr_t MaxPos;
    while(CurChunk != NULL){
        MinPos = (uintptr_t)(&(CurChunk->Items[0]));
        MaxPos = (uintptr_t)(&(CurChunk->Items[31]));
        if((MinPos <= CurPos)&&(MaxPos >= CurPos)){break;}
        CurIndex = CurIndex + 32;
        CurChunk = CurChunk->Next;
    }
    if(CurChunk == NULL){return -1;}

    int i = CurIndex + (int)(((int)(CurPos - MinPos)) / sizeof(void*));
    void** Item2Ptr;
    void** AItem2;
    if(P->compare((((void**)Item)[1]),ItemValue) > 0){
        ((void**)Item)[1] = ItemValue;
        while(i + 1 < P->Count){
            if(!((i + 1) & 31)){CurChunk = CurChunk->Next;}
            Item2Ptr = (void**)(&(CurChunk->Items[((i + 1) & 31)]));
            AItem2 = (void**)(*Item2Ptr);

            if(P->compare(AItem2[1],ItemValue) <= 0){break;}
            TestPQADSim_Swap(((PriorityQueueMMAItem*)AItem2),Item);
            i++;
        }
    }else{
        ((void**)Item)[1] = ItemValue;
        if(!(i & 31)){CurChunk = CurChunk->Prev;}
        while(i - 1 >= 0){

            Item2Ptr = (void**)(&(CurChunk->Items[((i - 1) & 31)]));
            AItem2 = (void**)(*Item2Ptr);

            if(P->compare(AItem2[1],ItemValue) >= 0){break;}
            TestPQADSim_Swap(((PriorityQueueMMAItem*)AItem2),Item);
            i--;
            if(!(i & 31)){CurChunk = CurChunk->Prev;}
        }
    }
    ret = 1;

    END:
    if(!TestPQADSim_Check(P)){return -1;}
    if(!TestPQADSim_UpdateRes1(P,Res,ret)){return -1;}
    return ret;
}

int TestPQADSim_UpdateItem(TestPQADSim* P,PriorityQueueMMAItem* Item,TestResults* Res){
    if(P == NULL){return -1;}
    int ret = 0;
    if(P->Count <= 0){goto END;}
    TestPQADSimChunk* Chunk = TestPQADSim_FindChunk(P,Item);
    if(!((Chunk != NULL)&&(((void**)Item)[0] != NULL))){
        #ifdef TESTENVIRONMENT_SHOWALL
        printf("[INFO] Item INVALID!\n");
        #endif // TESTENVIRONMENT_SHOWALL
        #ifdef TESTENVIRONMENT_VALIDCALLS
        return -1;
        #endif // TESTENVIRONMENT_VALIDCALLS
        goto END;
    }

    int CurIndex = 0;
    TestPQADSimChunk* CurChunk = P->FirstChunk;
    uintptr_t CurPos = (uintptr_t)(((void**)Item)[0]);
    uintptr_t MinPos;
    uintptr_t MaxPos;
    while(CurChunk != NULL){
        MinPos = (uintptr_t)(&(CurChunk->Items[0]));
        MaxPos = (uintptr_t)(&(CurChunk->Items[31]));
        if((MinPos <= CurPos)&&(MaxPos >= CurPos)){break;}
        CurIndex = CurIndex + 32;
        CurChunk = CurChunk->Next;
    }
    if(CurChunk == NULL){return -1;}

    int i = CurIndex + (int)(((int)(CurPos - MinPos)) / sizeof(void*));
    void** Item2Ptr;
    void** AItem2;
    #ifdef TESTENVIRONMENT_SHOWALL
    printf("[INFO] Index:%i\n",i);
    #endif // TESTENVIRONMENT_SHOWALL
    if(i != 0){
        if(!(i & 31)){CurChunk = CurChunk->Prev;}
        Item2Ptr = (void**)(&(CurChunk->Items[((i - 1) & 31)]));
        AItem2 = (void**)(*Item2Ptr);
        if(!(i & 31)){CurChunk = CurChunk->Next;}
    }
    if((i == 0)||(P->compare(AItem2[1],(((void**)Item)[1])) >= 0)){
        while(i + 1 < P->Count){
            if(!((i + 1) & 31)){CurChunk = CurChunk->Next;}
            Item2Ptr = (void**)(&(CurChunk->Items[((i + 1) & 31)]));
            AItem2 = (void**)(*Item2Ptr);

            if(P->compare(AItem2[1],(((void**)Item)[1])) <= 0){
                #ifdef TESTENVIRONMENT_SHOWALL
                printf("[INFO] [+1] Comp1:%i Comp2:%i\n",*((int*)(AItem2[1])),*((int*)(((void**)Item)[1])));
                #endif // TESTENVIRONMENT_SHOWALL
                break;
            }
            TestPQADSim_Swap(((PriorityQueueMMAItem*)AItem2),Item);
            i++;
        }
    }else{
        if(!(i & 31)){CurChunk = CurChunk->Prev;}
        while(i - 1 >= 0){
            Item2Ptr = (void**)(&(CurChunk->Items[((i - 1) & 31)]));
            AItem2 = (void**)(*Item2Ptr);

            if(P->compare(AItem2[1],(((void**)Item)[1])) >= 0){
                #ifdef TESTENVIRONMENT_SHOWALL
                printf("[INFO] [-1] Comp1:%i Comp2:%i\n",*((int*)(AItem2[1])),*((int*)(((void**)Item)[1])));
                #endif // TESTENVIRONMENT_SHOWALL
                break;
            }
            TestPQADSim_Swap(((PriorityQueueMMAItem*)AItem2),Item);
            i--;
            if(!(i & 31)){CurChunk = CurChunk->Prev;}
        }
    }
    ret = 1;

    END:
    if(!TestPQADSim_Check(P)){return -1;}
    if(!TestPQADSim_UpdateRes1(P,Res,ret)){return -1;}
    return ret;
}

int TestPQADSim_Remove(TestPQADSim* P,PriorityQueueMMAItem* Item,TestResults* Res){
    if(P == NULL){return -1;}
    int ret = 0;
    if(P->Count <= 0){goto END;}
    TestPQADSimChunk* Chunk = TestPQADSim_FindChunk(P,Item);
    if(!((Chunk != NULL)&&(((void**)Item)[0] != NULL))){
        #ifdef TESTENVIRONMENT_VALIDCALLS
        return -1;
        #endif // TESTENVIRONMENT_VALIDCALLS
        goto END;
    }

    int CurIndex = 0;
    TestPQADSimChunk* CurChunk = P->FirstChunk;
    uintptr_t CurPos = (uintptr_t)(((void**)Item)[0]);
    uintptr_t MinPos;
    uintptr_t MaxPos;
    while(CurChunk != NULL){
        MinPos = (uintptr_t)(&(CurChunk->Items[0]));
        MaxPos = (uintptr_t)(&(CurChunk->Items[31]));
        if((MinPos <= CurPos)&&(MaxPos >= CurPos)){break;}
        CurIndex = CurIndex + 32;
        CurChunk = CurChunk->Next;
    }
    if(CurChunk == NULL){return -1;}

    int i = CurIndex + (int)(((int)(CurPos - MinPos)) / sizeof(void*));
    void** Item2Ptr;
    void** AItem2;
    while(i + 1 < P->Count){
            if(!((i + 1) & 31)){CurChunk = CurChunk->Next;}
            Item2Ptr = (void**)(&(CurChunk->Items[((i + 1) & 31)]));
            AItem2 = (void**)(*Item2Ptr);
            TestPQADSim_Swap(((PriorityQueueMMAItem*)AItem2),Item);
            i++;
    }
    if(!TestPQADSim_RemoveChunkItem(P,Item)){return -1;}
    P->Count--;
    if((P->Count)&&(!(P->Count & 31))){P->LastChunk = P->LastChunk->Prev;}
    if(P->ChunkCount * 32 - P->Count > 48){TestPQADSimChunk_Dispose(P->LastChunk->Next);}
    ret = 1;

    END:
    if(!TestPQADSim_Check(P)){return -1;}
    if(!TestPQADSim_UpdateRes1(P,Res,ret)){return -1;}
    return ret;
}

int TestPQADSim_RemoveSource(TestPQADSim* P,PriorityQueueMMAItem* Item,TestResults* Res){
    if(P == NULL){return -1;}
    int ret = 0;
    if(P->Count <= 0){goto END;}
    TestPQADSimChunk* Chunk = TestPQADSim_FindChunk(P,Item);
    if(!((Chunk != NULL)&&(((void**)Item)[0] != NULL))){
        #ifdef TESTENVIRONMENT_VALIDCALLS
        return -1;
        #endif // TESTENVIRONMENT_VALIDCALLS
        goto END;
    }

    int CurIndex = 0;
    TestPQADSimChunk* CurChunk = P->FirstChunk;
    uintptr_t CurPos = (uintptr_t)(((void**)Item)[0]);
    uintptr_t MinPos;
    uintptr_t MaxPos;
    while(CurChunk != NULL){
        MinPos = (uintptr_t)(&(CurChunk->Items[0]));
        MaxPos = (uintptr_t)(&(CurChunk->Items[31]));
        if((MinPos <= CurPos)&&(MaxPos >= CurPos)){break;}
        CurIndex = CurIndex + 32;
        CurChunk = CurChunk->Next;
    }
    if(CurChunk == NULL){return -1;}

    int i = CurIndex + (int)(((int)(CurPos - MinPos)) / sizeof(void*));
    void** Item2Ptr;
    void** AItem2;
    if(!P->disposeItem((((void**)Item)[1]),NULL)){goto END;}
    while(i + 1 < P->Count){
            if(!((i + 1) & 31)){CurChunk = CurChunk->Next;}
            Item2Ptr = (void**)(&(CurChunk->Items[((i + 1) & 31)]));
            AItem2 = (void**)(*Item2Ptr);
            TestPQADSim_Swap(((PriorityQueueMMAItem*)AItem2),Item);
            i++;
    }
    if(!TestPQADSim_RemoveChunkItem(P,Item)){return -1;}
    P->Count--;
    if((P->Count)&&(!(P->Count & 31))){P->LastChunk = P->LastChunk->Prev;}
    if(P->ChunkCount * 32 - P->Count > 48){TestPQADSimChunk_Dispose(P->LastChunk->Next);}
    ret = 1;

    END:
    if(!TestPQADSim_Check(P)){return -1;}
    if(!TestPQADSim_UpdateRes1(P,Res,ret)){return -1;}
    return ret;
}

int TestPQADSim_UpdateRes1(TestPQADSim* P,TestResults* Res,int Ret){
    if((P == NULL)||(Res == NULL)){return 0;}

    //Header:
    Res->ReservedMemory = sizeof(TestPQADSim) + (P->ChunkCount + P->AChunkCount) * (sizeof(TestPQADSimChunk) + sizeof(void*) * 32);
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
        Res->Min = *((int*)(TestPQADSim_GetMin(P)));
        Res->Max = *((int*)(TestPQADSim_GetMax(P)));
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

int TestPQADSim_UpdateRes2(TestPQADSim* P,TestResults* Res,void* Ret){
    if((P == NULL)||(Res == NULL)){return 0;}

    //Header:
    Res->ReservedMemory = sizeof(TestPQADSim) + (P->ChunkCount + P->AChunkCount) * (sizeof(TestPQADSimChunk) + sizeof(void*) * 32);
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
        Res->Min = *((int*)(TestPQADSim_GetMin(P)));
        Res->Max = *((int*)(TestPQADSim_GetMax(P)));
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

void TestPQADSim_Dispose(TestPQADSim* P){
    if(P == NULL){return;}
    TestPQADSimChunk* CurChunk = P->LastChunk;
    TestPQADSimChunk* NxtChunk;
    if(CurChunk->Next != NULL){CurChunk = CurChunk->Next;}
    while(CurChunk != NULL){
        NxtChunk = CurChunk->Prev;
        TestPQADSimChunk_Dispose(CurChunk);
        CurChunk = NxtChunk;
    }
    CurChunk = P->ALastChunk;
    if(CurChunk->Next != NULL){CurChunk = CurChunk->Next;}
    while(CurChunk != NULL){
        NxtChunk = CurChunk->Prev;
        TestPQADSimChunk_DisposeA(CurChunk);
        CurChunk = NxtChunk;
    }
    free((void*)P);
}
