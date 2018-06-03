#include "TestPQSFSim.h"

extern int TestResults_IsDispItemNULL;
extern int TestResults_DispItem;

TestPQSFSim* TestPQSFSim_Create(size_t TotalSize,int MaxItems,int(*compare)(void*,void*),int(*disposeItem)(void*,ERRVAL_T*),TestResults* Res){

    if(MaxItems <= 0){
        printf("[ERROR] Creation of \"TestPQSFSim\"-object failed!\n");
        printf("        \"MaxItems\"-Value invalid!\n");
        return NULL;
    }

    if(compare == NULL){
        printf("[ERROR] Creation of \"TestPQSFSim\"-object failed!\n");
        printf("        \"compare\"-function-ptr invalid!\n");
        return NULL;
    }

    if(disposeItem == NULL){
        printf("[ERROR] Creation of \"TestPQSFSim\"-object failed!\n");
        printf("        \"disposeItem\"-function-ptr invalid!\n");
        return NULL;
    }

    TestPQSFSim* res = (TestPQSFSim*)malloc(sizeof(TestPQSFSim) + sizeof(void*) * MaxItems);
    if(res == NULL){
        printf("[ERROR] Creation of \"TestPQSFSim\"-object failed!\n");
        printf("        Memory could not be allocated!\n");
        return NULL;
    }

    res->TotalSize = TotalSize;
    res->Count = 0;
    res->MaxItems = MaxItems;
    res->compare = compare;
    res->disposeItem = disposeItem;
    if(!TestPQSFSim_UpdateRes1(res,Res,0)){
        printf("        Creation of \"TestPQSFSim\"-object failed!\n");
        free((void*)res);
        return NULL;
    }
    return res;
}

int TestPQSFSim_Insert(TestPQSFSim* P,void* Item,TestResults* Res){
    if(P == NULL){return -1;}
    int ret = 0;
    if(Item == NULL){goto END;}
    if(P->Count >= P->MaxItems){goto END;}
    int i = P->Count - 1;
    while(i >= 0){
        if(P->compare(P->Items[i],Item)>= 0){
            P->Items[i + 1] = Item;
            break;
        }
        P->Items[i + 1] = P->Items[i];
        i--;
    }
    if(i < 0){P->Items[0] = Item;}
    P->Count++;
    ret = 1;

    END:
    if(!TestPQSFSim_UpdateRes1(P,Res,ret)){return -1;}
    return ret;
}

void* TestPQSFSim_GetMin(TestPQSFSim* P){
    if((P == NULL)||(P->Count <= 0)){return NULL;}
    return P->Items[0];
}

void* TestPQSFSim_GetMax(TestPQSFSim* P){
    if((P == NULL)||(P->Count <= 0)){return NULL;}
    return P->Items[P->Count - 1];
}

int TestPQSFSim_RemoveMin(TestPQSFSim* P,TestResults* Res){
    if(P == NULL){return -1;}
    int ret = 0;
    if(P->Count <= 0){goto END;}
    int i;
    for(i = 1;i < P->Count;i++){P->Items[i - 1] = P->Items[i];}
    P->Count--;
    ret = 1;

    END:
    if(!TestPQSFSim_UpdateRes1(P,Res,ret)){return -1;}
    return ret;
}

int TestPQSFSim_RemoveMax(TestPQSFSim* P,TestResults* Res){
    if(P == NULL){return -1;}
    int ret = 0;
    if(P->Count <= 0){goto END;}
    P->Count--;
    ret = 1;

    END:
    if(!TestPQSFSim_UpdateRes1(P,Res,ret)){return -1;}
    return ret;
}

int TestPQSFSim_RemoveMinSource(TestPQSFSim* P,TestResults* Res){
    if(P == NULL){return -1;}
    int ret = 0;
    if(P->Count <= 0){goto END;}
    int i;
    if(!P->disposeItem(P->Items[0],NULL)){goto END;}
    for(i = 1;i < P->Count;i++){P->Items[i - 1] = P->Items[i];}
    P->Count--;
    ret = 1;

    END:
    if(!TestPQSFSim_UpdateRes1(P,Res,ret)){return -1;}
    return ret;
}

int TestPQSFSim_RemoveMaxSource(TestPQSFSim* P,TestResults* Res){
    if(P == NULL){return -1;}
    int ret = 0;
    if(P->Count <= 0){goto END;}
    if(!P->disposeItem(P->Items[P->Count - 1],NULL)){goto END;}
    P->Count--;
    ret = 1;

    END:
    if(!TestPQSFSim_UpdateRes1(P,Res,ret)){return -1;}
    return ret;
}

int TestPQSFSim_UpdateRes1(TestPQSFSim* P,TestResults* Res,int Ret){
    if((P == NULL)||(Res == NULL)){return 0;}

    //Header:
    Res->ReservedMemory = P->TotalSize;
    Res->ReservedItems = P->MaxItems;
    Res->IsFixedSize = 1;
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
        Res->Min = *((int*)P->Items[0]);
        Res->Max = *((int*)P->Items[P->Count - 1]);
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

int TestPQSFSim_UpdateRes2(TestPQSFSim* P,TestResults* Res,void* Ret){
    if((P == NULL)||(Res == NULL)){return 0;}

    //Header:
    Res->ReservedMemory = P->TotalSize;
    Res->ReservedItems = P->MaxItems;
    Res->IsFixedSize = 1;
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
        Res->Min = *((int*)P->Items[0]);
        Res->Max = *((int*)P->Items[P->Count - 1]);
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

void TestPQSFSim_Dispose(TestPQSFSim* P){
    if(P == NULL){return;}
    free((void*)P);
}
