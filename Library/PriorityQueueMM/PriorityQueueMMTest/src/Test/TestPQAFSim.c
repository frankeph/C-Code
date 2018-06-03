#include "TestPQAFSim.h"

#ifndef TESTPQAFSIM_DOCHECKS
#define TestPQAFSim_Check(P)    (1)
#endif // TESTPQAFSIM_DOCHECKS

extern int TestResults_IsDispItemNULL;
extern int TestResults_DispItem;

TestPQAFSim* TestPQAFSim_Create(size_t TotalSize,int MaxItems,int(*compare)(void*,void*),int(*disposeItem)(void*,ERRVAL_T*),TestResults* Res){

    if(MaxItems <= 0){
        printf("[ERROR] Creation of \"TestPQAFSim\"-object failed!\n");
        printf("        \"MaxItems\"-Value invalid!\n");
        return NULL;
    }

    if(compare == NULL){
        printf("[ERROR] Creation of \"TestPQAFSim\"-object failed!\n");
        printf("        \"compare\"-function-ptr invalid!\n");
        return NULL;
    }

    if(disposeItem == NULL){
        printf("[ERROR] Creation of \"TestPQAFSim\"-object failed!\n");
        printf("        \"disposeItem\"-function-ptr invalid!\n");
        return NULL;
    }

    TestPQAFSim* res = (TestPQAFSim*)malloc(sizeof(TestPQAFSim) + sizeof(void*) * (MaxItems * 3));
    if(res == NULL){
        printf("[ERROR] Creation of \"TestPQAFSim\"-object failed!\n");
        printf("        Memory could not be allocated!\n");
        return NULL;
    }

    res->TotalSize = TotalSize;
    res->Count = 0;
    res->MaxItems = MaxItems;
    res->compare = compare;
    res->disposeItem = disposeItem;

    int i;
    for(i = 0;i < res->MaxItems;i++){
        res->Items[i] = (void*)(&(res->Items[MaxItems + (i << 1)]));
    }
    if(!TestPQAFSim_UpdateRes1(res,Res,0)){
        printf("        Creation of \"TestPQAFSim\"-object failed!\n");
        free((void*)res);
        return NULL;
    }
    return res;
}

void TestPQAFSim_Print(TestPQAFSim* P){
    if(P == NULL){return;}
    printf("[INFO] Printing \"TestPQAFSim\":\n");
    printf("      ");
    int i;
    for(i = 0;i < P->Count;i++){printf("%3i ",*((int*)(((void**)P->Items[i])[1])));}
    printf("\n");
}

#ifdef TESTPQAFSIM_DOCHECKS
static int TestPQAFSim_Check(TestPQAFSim* P){
    if(P == NULL){return 0;}
    if(P->Count <= 1){return 1;}
    int i;
    for(i = 0;i + 1 < P->Count;i++){
        if(P->compare(((void**)P->Items[i])[1],((void**)P->Items[i + 1])[1]) < 0){
            printf("[ERROR] Invariant of \"TestPQAFSim\" broken!\n");
            TestPQAFSim_Print(P);
            return 0;
        }
    }
    return 1;
}
#endif // TESTPQAFSIM_DOCHECKS

static void TestPQAFSim_Swap(PriorityQueueMMAItem* I1,PriorityQueueMMAItem* I2){
    void** Item1 = (void**)I1;
    void** Item2 = (void**)I2;
    void** Slot1 = (void**)(Item1[0]);
    void** Slot2 = (void**)(Item2[0]);
    *Slot1 = (void*)I2;
    *Slot2 = (void*)I1;
    Item1[0] = (void*)Slot2;
    Item2[0] = (void*)Slot1;
}

static int TestPQAFSim_ContainsItem_internal(TestPQAFSim* P,PriorityQueueMMAItem* Item){
    uintptr_t MinPos = (uintptr_t)(&(P->Items[P->MaxItems]));
    uintptr_t MaxPos = (uintptr_t)(&(P->Items[P->MaxItems * 3 - 2]));
    if((((uintptr_t)Item) < MinPos)||(((uintptr_t)Item) > MaxPos)){return 0;}
    MinPos = (uintptr_t)(&(P->Items[0]));
    MaxPos = (uintptr_t)(&(P->Items[P->Count - 1]));
    void** I = (void**)Item;
    if((((uintptr_t)(I[0])) < MinPos)||(((uintptr_t)(I[0])) > MaxPos)){return 0;}
    if(*((void**)(I[0])) != ((void*)I)){return 0;}
    return 1;
}

PriorityQueueMMAItem* TestPQAFSim_GetInsertedItem(TestPQAFSim* P,void* Item,TestResults* Res){
    if(P == NULL){return NULL;}
    void* ret = NULL;
    void** res = NULL;
    if(Item == NULL){goto END;}
    if(P->Count >= P->MaxItems){goto END;}
    res = (void**)P->Items[P->Count];
    res[0] = (void*)(&(P->Items[P->Count]));
    res[1] = Item;
    int i = P->Count - 1;
    while(i >= 0){
        if(P->compare((((void**)P->Items[i])[1]),Item) >= 0){break;}
        TestPQAFSim_Swap(((PriorityQueueMMAItem*)P->Items[i]),((PriorityQueueMMAItem*)P->Items[i + 1]));
        i--;
    }
    P->Count++;
    ret = Item;

    END:
    if(!TestPQAFSim_UpdateRes2(P,Res,ret)){return NULL;}
    if(ret == NULL){return NULL;}
    return ((PriorityQueueMMAItem*)(&(res[0])));
}

void* TestPQAFSim_GetMin(TestPQAFSim* P){
    if((P == NULL)||(P->Count <= 0)){return NULL;}
    return (((void**)P->Items[0])[1]);
}

void* TestPQAFSim_GetMax(TestPQAFSim* P){
    if((P == NULL)||(P->Count <= 0)){return NULL;}
    return (((void**)P->Items[P->Count - 1])[1]);
}

int TestPQAFSim_ContainsItem(TestPQAFSim* P,PriorityQueueMMAItem* Item,TestResults* Res){
    if(P == NULL){return -1;}
    int ret = TestPQAFSim_ContainsItem_internal(P,Item);

    if(!TestPQAFSim_UpdateRes1(P,Res,ret)){return -1;}
    return ret;
}

int TestPQAFSim_SetItemOfItem(TestPQAFSim* P,PriorityQueueMMAItem* Item,void* ItemValue,TestResults* Res){
    if(P == NULL){return -1;}
    int ret = 0;
    if(!TestPQAFSim_ContainsItem_internal(P,Item)){
        #ifdef TESTENVIRONMENT_SHOWALL
        printf("[INFO] Item INVALID!\n");
        #endif // TESTENVIRONMENT_SHOWALL
        #ifdef TESTENVIRONMENT_VALIDCALLS
        return -1;
        #endif // TESTENVIRONMENT_VALIDCALLS
        goto END;
    }
    #ifndef TESTENVIRONMENT_VALIDCALLS
    if((((void**)Item)[1]) == ItemValue){return TestPQAFSim_UpdateItem(P,Item,Res);}
    #else // TESTENVIRONMENT_VALIDCALLS
    if((((void**)Item)[1]) == ItemValue){return -1;}
    #endif // TESTENVIRONMENT_VALIDCALLS


    int i = ((int)(((uintptr_t)(((void**)Item)[0])) - ((uintptr_t)(&(P->Items[0]))))) / ((int)sizeof(void*));
    if(P->compare((((void**)Item)[1]),ItemValue) > 0){
        ((void**)Item)[1] = ItemValue;
        while(i + 1 < P->Count){
            if(P->compare((((void**)(P->Items[i + 1]))[1]),ItemValue) <= 0){break;}
            TestPQAFSim_Swap(((PriorityQueueMMAItem*)P->Items[i]),((PriorityQueueMMAItem*)P->Items[i + 1]));
            i++;
        }
    }else{
        ((void**)Item)[1] = ItemValue;
        while(i - 1 >= 0){
            if(P->compare((((void**)(P->Items[i - 1]))[1]),ItemValue) >= 0){break;}
            TestPQAFSim_Swap(((PriorityQueueMMAItem*)P->Items[i]),((PriorityQueueMMAItem*)P->Items[i - 1]));
            i--;
        }
    }
    ret = 1;

    END:
    if(!TestPQAFSim_Check(P)){return -1;}
    if(!TestPQAFSim_UpdateRes1(P,Res,ret)){return -1;}
    return ret;
}

int TestPQAFSim_UpdateItem(TestPQAFSim* P,PriorityQueueMMAItem* Item,TestResults* Res){
    if(P == NULL){return -1;}
    int ret = 0;
    if(P->Count <= 0){goto END;}
    if(!TestPQAFSim_ContainsItem_internal(P,Item)){
        #ifdef TESTENVIRONMENT_SHOWALL
        printf("[INFO] Item INVALID!\n");
        #endif // TESTENVIRONMENT_SHOWALL
        #ifdef TESTENVIRONMENT_VALIDCALLS
        return -1;
        #endif // TESTENVIRONMENT_VALIDCALLS
        goto END;
    }
    int i = ((int)(((uintptr_t)(((void**)Item)[0])) - ((uintptr_t)(&(P->Items[0]))))) / ((int)sizeof(void*));
    #ifdef TESTENVIRONMENT_SHOWALL
    printf("[INFO] Index:%i\n",i);
    #endif // TESTENVIRONMENT_SHOWALL
    if((i == 0)||(P->compare((((void**)(P->Items[i - 1]))[1]),(((void**)Item)[1])) >= 0)){
        while(i + 1 < P->Count){
            if(P->compare((((void**)(P->Items[i + 1]))[1]),(((void**)(P->Items[i]))[1])) <= 0){
                #ifdef TESTENVIRONMENT_SHOWALL
                printf("[INFO] [+1] Comp1:%i Comp2:%i\n",*((int*)(((void**)(P->Items[i + 1]))[1])),*((int*)(((void**)Item)[1])));
                #endif // TESTENVIRONMENT_SHOWALL
                break;
            }
            TestPQAFSim_Swap(((PriorityQueueMMAItem*)P->Items[i]),((PriorityQueueMMAItem*)P->Items[i + 1]));
            i++;
        }
    }else{
        while(i - 1 >= 0){
            if(P->compare((((void**)(P->Items[i - 1]))[1]),(((void**)(P->Items[i]))[1])) >= 0){
                #ifdef TESTENVIRONMENT_SHOWALL
                printf("[INFO] [-1] Comp1:%i Comp2:%i\n",*((int*)(((void**)(P->Items[i - 1]))[1])),*((int*)(((void**)Item)[1])));
                #endif // TESTENVIRONMENT_SHOWALL
                break;
            }
            TestPQAFSim_Swap(((PriorityQueueMMAItem*)P->Items[i]),((PriorityQueueMMAItem*)P->Items[i - 1]));
            i--;
        }
    }
    ret = 1;

    END:
    if(!TestPQAFSim_Check(P)){return -1;}
    if(!TestPQAFSim_UpdateRes1(P,Res,ret)){return -1;}
    return ret;
}

int TestPQAFSim_Remove(TestPQAFSim* P,PriorityQueueMMAItem* Item,TestResults* Res){
    if(P == NULL){return -1;}
    int ret = 0;
    if(P->Count <= 0){goto END;}
    if(!TestPQAFSim_ContainsItem_internal(P,Item)){
        #ifdef TESTENVIRONMENT_VALIDCALLS
        return -1;
        #endif // TESTENVIRONMENT_VALIDCALLS
        goto END;
    }
    int i = ((int)(((uintptr_t)(((void**)Item)[0])) - ((uintptr_t)(&(P->Items[0]))))) / ((int)sizeof(void*));
    while(i + 1 < P->Count){
        TestPQAFSim_Swap(((PriorityQueueMMAItem*)P->Items[i]),((PriorityQueueMMAItem*)P->Items[i + 1]));
        i++;
    }
    P->Count--;
    ret = 1;

    END:
    if(!TestPQAFSim_Check(P)){return -1;}
    if(!TestPQAFSim_UpdateRes1(P,Res,ret)){return -1;}
    return ret;
}

int TestPQAFSim_RemoveSource(TestPQAFSim* P,PriorityQueueMMAItem* Item,TestResults* Res){
    if(P == NULL){return -1;}
    int ret = 0;
    if(P->Count <= 0){goto END;}
    if(!TestPQAFSim_ContainsItem_internal(P,Item)){
        #ifdef TESTENVIRONMENT_SHOWALL
        printf("[INFO] Item INVALID!\n");
        #endif // TESTENVIRONMENT_SHOWALL
        goto END;
    }
    int i = ((int)(((uintptr_t)(((void**)Item)[0])) - ((uintptr_t)(&(P->Items[0]))))) / ((int)sizeof(void*));
    if(!P->disposeItem((((void**)P->Items[i])[1]),NULL)){goto END;}
    while(i + 1 < P->Count){
        TestPQAFSim_Swap(((PriorityQueueMMAItem*)P->Items[i]),((PriorityQueueMMAItem*)P->Items[i + 1]));
        i++;
    }
    P->Count--;
    ret = 1;

    END:
    if(!TestPQAFSim_Check(P)){return -1;}
    if(!TestPQAFSim_UpdateRes1(P,Res,ret)){return -1;}
    return ret;
}

int TestPQAFSim_UpdateRes1(TestPQAFSim* P,TestResults* Res,int Ret){
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
        Res->Min = *((int*)(TestPQAFSim_GetMin(P)));
        Res->Max = *((int*)(TestPQAFSim_GetMax(P)));
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

int TestPQAFSim_UpdateRes2(TestPQAFSim* P,TestResults* Res,void* Ret){
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
        Res->Min = *((int*)(TestPQAFSim_GetMin(P)));
        Res->Max = *((int*)(TestPQAFSim_GetMax(P)));
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

void TestPQAFSim_Dispose(TestPQAFSim* P){
    if(P == NULL){return;}
    free((void*)P);
}
