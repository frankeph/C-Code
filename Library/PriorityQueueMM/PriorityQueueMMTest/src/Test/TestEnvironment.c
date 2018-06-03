#include "TestEnvironment.h"

extern int TestResults_IsDispItemNULL;
extern int TestResults_DispItem;

static int TestEnvironment_Compare(void* I1,void* I2){
    if((I1 == NULL)||(I2 == NULL)){return ((I1 == NULL) - (I2 == NULL));}
    int* Item1 = (int*)I1;
    int* Item2 = (int*)I2;
    return ((*Item1 < *Item2) - (*Item1 > *Item2));
}

static int TestEnvironment_DisposeItem(void* I,ERRVAL_T* Errval){
    if(I == NULL){return 0;}
    TestResults_IsDispItemNULL = 0;
    TestResults_DispItem = *((int*)I);
    return 1;
}

static int TestEnvironment_BaseTest_PriorityQueueMMSF_Print(PriorityQueueMMSF* PQSF){
    if(PQSF == NULL){return 0;}
    printf("        Printing Queue:\n");
    printf("        [Max:%i Count:%i LLS:%i]\n",(int)PriorityQueueMMSF_GetReservedItems(PQSF,NULL),PQSF->Count,(int)PQSF->LstLayerStart);
    int i;
    int CurLayerStart = 0;
    int CurLayerOffset = (CurLayerStart >> 1) + 1;
    int LowerTreeStart = CurLayerStart + CurLayerOffset;
    int NxtLayerStart = (CurLayerStart << 1) + 2;
    printf("        ");
    for(i = 0;i < PQSF->Count;i++){
        if((i >= NxtLayerStart)&&(NxtLayerStart < PQSF->Count)){
            printf("\n        ");
            CurLayerStart = NxtLayerStart;
            CurLayerOffset = (CurLayerStart >> 1) + 1;
            LowerTreeStart = CurLayerStart + CurLayerOffset;
            NxtLayerStart = (CurLayerStart << 1) + 2;
        }
        if(i == LowerTreeStart){
            printf("    ");
        }
        printf("%3i ",*((int*)PQSF->Items[i]));
    }
    printf("\n");
    return 1;
}

static int TestEnvironment_BaseTest_PriorityQueueMMAF_Print(PriorityQueueMMAF* PQAF){
    if(PQAF == NULL){return 0;}
    printf("        Printing Queue:\n");
    printf("        [Max:%i Count:%i LLS:%i]\n",(int)PriorityQueueMMAF_GetReservedItems(PQAF,NULL),PQAF->Count,(int)PQAF->LstLayerStart);
    int i;
    int CurLayerStart = 0;
    int CurLayerOffset = (CurLayerStart >> 1) + 1;
    int LowerTreeStart = CurLayerStart + CurLayerOffset;
    int NxtLayerStart = (CurLayerStart << 1) + 2;
    void** Item;
    printf("        ");
    for(i = 0;i < PQAF->Count;i++){
        if((i >= NxtLayerStart)&&(NxtLayerStart < PQAF->Count)){
            printf("\n        ");
            CurLayerStart = NxtLayerStart;
            CurLayerOffset = (CurLayerStart >> 1) + 1;
            LowerTreeStart = CurLayerStart + CurLayerOffset;
            NxtLayerStart = (CurLayerStart << 1) + 2;
        }
        if(i == LowerTreeStart){
            printf("    ");
        }
        if(PQAF->Items[i] != NULL){
            Item = (void**)PQAF->Items[i];
            printf("%3i ",*((int*)Item[1]));
        }else{
            printf("NLL ");
        }
    }
    printf("\n");
    return 1;
}

#define PriorityQueueMMDUnit_Prev(Unit)                         ((Unit)->Prev->UnitPtr)
#define PriorityQueueMMDUnit_Next(Unit)                         ((Unit)->Next->UnitPtr)
#define PriorityQueueMMDUnit_FirstBlock(Unit)                   ((Unit)->Prev->UnitPtr->Next)
#define PriorityQueueMMDUnit_LastBlock(Unit)                    ((Unit)->Next->UnitPtr->Prev)

#define PriorityQueueMMDBlock_Get(Ptr)                          (*((PriorityQueueMMDBlock**)(((uintptr_t)(Ptr)) & PriorityQueueMMDBlock_SizeMask)))
#define PriorityQueueMMDBlock_IsFirst(BlockPtr)                 (!((BlockPtr)->Offset + ((intptr_t)2)))
#define PriorityQueueMMDBlock_GetItemPtr(BlockPtr,Index)        ((Index)?(&(((void**)((BlockPtr)->BackPtr))[(Index)])):(&((BlockPtr)->FrstItem)))
#define PriorityQueueMMDBlock_GetItem(BlockPtr,Index)           ((Index)?(((void**)((BlockPtr)->BackPtr))[(Index)]):((BlockPtr)->FrstItem))
#define PriorityQueueMMDBlock_SetItem(BlockPtr,Index,Value)     ({void** _Item = PriorityQueueMMDBlock_GetItemPtr((BlockPtr),(Index));*_Item = (void*)(Value);})
#define PriorityQueueMMDBlock_GetIndexPtr(BlockPtr,Index)       ((void*)(&(((void**)(BlockPtr)->BackPtr)[(Index)])))
#define PriorityQueueMMDBlock_GetIndexValue(BlockPtr,IndexPtr)  ((int)((((uintptr_t)(IndexPtr)) - ((uintptr_t)((BlockPtr)->BackPtr))) >> PriorityQueueMMD_Shift))

#define PriorityQueueMMDBlock_GetPrev(BlockPtr)                 (((BlockPtr) != PriorityQueueMMDUnit_FirstBlock(((BlockPtr)->UnitPtr)))?(*((PriorityQueueMMDBlock**)(((BlockPtr)->BackPtr) - PriorityQueueMMDBlock_Size))):((BlockPtr)->UnitPtr->Prev))
#define PriorityQueueMMDBlock_GetNext(BlockPtr)                 (((BlockPtr) != PriorityQueueMMDUnit_LastBlock(((BlockPtr)->UnitPtr)))?(*((PriorityQueueMMDBlock**)(((BlockPtr)->BackPtr) + PriorityQueueMMDBlock_Size))):((BlockPtr)->UnitPtr->Next))
#define PriorityQueueMMDBlock_GetNumber(BlockPtr)               (((int)((BlockPtr)->Offset + 2)) >> 5)
#define PriorityQueueMMDBlock_GetParentIndex(BlockPtr,Index)    ((PriorityQueueMMDBlock_IsFirst((BlockPtr)))?((((int)((Index) + (BlockPtr)->Offset)) >> 1) - 3 - ((BlockPtr)->Parent->Offset + ((intptr_t)2))):((Index) >> 1))

extern const size_t PriorityQueueMMDBlock_Size;
extern const uintptr_t PriorityQueueMMDBlock_SizeMask;
extern int PriorityQueueMMD_Shift;

static int TestEnvironment_BaseTest_PriorityQueueMMSD_Print(PriorityQueueMMSD* PQSD){
    if(PQSD == NULL){return 0;}
    printf("        Printing Queue:\n");
    printf("        [Count:%i LLS:%i]\n",PQSD->Count,(int)PQSD->LstLayerStart);
    int i;
    int CurLayerStart = 0;
    int CurLayerOffset = (CurLayerStart >> 1) + 1;
    int LowerTreeStart = CurLayerStart + CurLayerOffset;
    int NxtLayerStart = (CurLayerStart << 1) + 2;
    void** Item;
    int BlockIndex = 0;
    PriorityQueueMMDBlock* CurBlock = PQSD->Top;
    printf("        ");
    for(i = 0;i < PQSD->Count;i++){
        if((i >= NxtLayerStart)&&(NxtLayerStart < PQSD->Count)){
            printf("\n        ");
            CurLayerStart = NxtLayerStart;
            CurLayerOffset = (CurLayerStart >> 1) + 1;
            LowerTreeStart = CurLayerStart + CurLayerOffset;
            NxtLayerStart = (CurLayerStart << 1) + 2;
        }
        if(i == LowerTreeStart){
            printf("    ");
        }
        if(i == (BlockIndex + 1) * 32 - 2){
            BlockIndex++;
            CurBlock = PriorityQueueMMDBlock_GetNext(CurBlock);
        }
        Item = PriorityQueueMMDBlock_GetItemPtr(CurBlock,(i - BlockIndex * 32 + 2));
        printf("%3i ",*((int*)(*Item)));
    }
    printf("\n");
    return 1;
}

static int TestEnvironment_BaseTest_PriorityQueueMMAD_Print(PriorityQueueMMAD* PQAD){
    if(PQAD == NULL){return 0;}
    printf("        Printing Queue:\n");
    printf("        [Count:%i LLS:%i]\n",PQAD->Count,(int)PQAD->LstLayerStart);
    int i;
    int CurLayerStart = 0;
    int CurLayerOffset = (CurLayerStart >> 1) + 1;
    int LowerTreeStart = CurLayerStart + CurLayerOffset;
    int NxtLayerStart = (CurLayerStart << 1) + 2;
    void** Item;
    void* ItemVal;
    int BlockIndex = 0;
    PriorityQueueMMDBlock* CurBlock = PQAD->Top;
    //PriorityQueueMMDBlock* PrvBlock;
    printf("        ");
    for(i = 0;i < PQAD->Count;i++){
        if((i >= NxtLayerStart)&&(NxtLayerStart < PQAD->Count)){
            printf("\n        ");
            CurLayerStart = NxtLayerStart;
            CurLayerOffset = (CurLayerStart >> 1) + 1;
            LowerTreeStart = CurLayerStart + CurLayerOffset;
            NxtLayerStart = (CurLayerStart << 1) + 2;
        }
        if(i == LowerTreeStart){
            printf("    ");
        }
        if(i == (BlockIndex + 1) * 32 - 2){
            BlockIndex++;
            CurBlock = PriorityQueueMMDBlock_GetNext(CurBlock);
        }
        Item = PriorityQueueMMDBlock_GetItemPtr(CurBlock,(i - BlockIndex * 32 + 2));
        ItemVal = PriorityQueueMMAD_GetItemOfItem(PQAD,(PriorityQueueMMAItem*)(*Item),NULL);
        printf("%3i ",*((int*)ItemVal));
    }
    printf("\n");
    return 1;
}

#undef PriorityQueueMMDUnit_Prev
#undef PriorityQueueMMDUnit_Next
#undef PriorityQueueMMDUnit_FirstBlock
#undef PriorityQueueMMDUnit_LastBlock

#undef PriorityQueueMMDBlock_Get
#undef PriorityQueueMMDBlock_IsFirst
#undef PriorityQueueMMDBlock_GetItemPtr
#undef PriorityQueueMMDBlock_GetItem
#undef PriorityQueueMMDBlock_SetItem
#undef PriorityQueueMMDBlock_GetIndexPtr
#undef PriorityQueueMMDBlock_GetIndexValue

#undef PriorityQueueMMDBlock_GetPrev
#undef PriorityQueueMMDBlock_GetNext
#undef PriorityQueueMMDBlock_GetNumber
#undef PriorityQueueMMDBlock_GetParentIndex

int TestEnvironment_BaseTest_PriorityQueueMMSF(int TestOps){
    MyRandom* Random = MyRandom_Create();

    #ifndef TESTENVIRONMENT_ENDLESS
    int i;
    #else // TESTENVIRONMENT_ENDLESS
    unsigned int i;
    #endif // TESTENVIRONMENT_ENDLESS
    int Items[256];

    TestItemProvider* ItemP = TestItemProvider_Create(256);
    if(ItemP == NULL){
        printf("        Function \"%s\" failed!\n",__FUNCTION__);
        MyRandom_Dispose(Random);
        return 0;
    }

    for(i = 0;i < 256;i++){
        Items[i] = i + 1;
        TestItemProvider_Add(ItemP,(void*)(&(Items[i])));
    }

    TestResults R1;     //Actual    Results
    TestResults R2;     //Expected  Results

    int MaxItems = MyRandom_GetInt2(Random,40,50);
    size_t NecessarySize = PriorityQueueMMSF_GetSizeFor(MaxItems,NULL);

    TestPQSFSim* Sim = TestPQSFSim_Create(NecessarySize,MaxItems,TestEnvironment_Compare,TestEnvironment_DisposeItem,&R2);

    void* MemPtr = malloc(NecessarySize);
    if(MemPtr == NULL){
        printf("[ERROR] Function \"%s\" failed!\n",__FUNCTION__);
        printf("        \"MemPtr\" could not be allocated!\n");
        MyRandom_Dispose(Random);
        TestItemProvider_Dispose(ItemP);
        TestPQSFSim_Dispose(Sim);
        return 0;
    }

    PriorityQueueMMSF* PQSF = PriorityQueueMMSF_Create(MemPtr,NecessarySize,TestEnvironment_Compare,TestEnvironment_DisposeItem,NULL,NULL,NULL);
    PriorityQueueMM* PQ = PriorityQueueMMSF_Get_PriorityQueueMM(PQSF,NULL);

    TestResults_SetFromPQ1(&R1,PQ,0);

    TestResults_IsDispItemNULL = 1;
    TestResults_DispItem = -1;

    char* expectedRes;
    char* actualRes;

    if(!TestResults_Equal(&R1,&R2)){
        printf("[ERROR] Operation \"PriorityQueueMMSF_Create\" indicates an error!\n");
        if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
            printf("        Expected Results:\n");
            printf("        %s\n",expectedRes);
            printf("        Actual Results:\n");
            printf("        %s\n",actualRes);
        }
        MyRandom_Dispose(Random);
        TestItemProvider_Dispose(ItemP);
        TestPQSFSim_Dispose(Sim);
        return 0;
    }

    #ifndef TESTENVIRONMENT_ENDLESS
    printf("[INFO] Starting %i Operations:\n",TestOps);
    #else // TESTENVIRONMENT_ENDLESS
    printf("[INFO] Starting \"infinite\" Operations:\n");
    #endif // TESTENVIRONMENT_ENDLESS
    int OpType;
    int Index;
    void* Item;
    int OpRes;
    int OPCount_Insert = 0;
    int OPCount_RemMin = 0;
    int OPCount_RemMax = 0;
    int OPCount_RemMinS = 0;
    int OPCount_RemMaxS = 0;
    time_t LastDispTime;
    time_t CurTime;
    time(&LastDispTime);
    #ifndef TESTENVIRONMENT_ENDLESS
    for(i = 0;i < TestOps;i++){
    #else // TESTENVIRONMENT_ENDLESS
    for(i = 0;i >= 0;i++){
    #endif // TESTENVIRONMENT_ENDLESS
        #ifdef TESTENVIRONMENT_SHOWTRE
        TestEnvironment_BaseTest_PriorityQueueMMSF_Print(PQSF);
        #endif // TESTENVIRONMENT_SHOWTRE
        OpType = MyRandom_GetInt2(Random,0,1);
        if(OpType == 0){    //Remove item:
            OpType = MyRandom_GetInt2(Random,0,3);
            if(OpType < 2){
                Item = TestPQSFSim_GetMin(Sim);

                #ifdef TESTENVIRONMENT_SHOWALL
                if(OpType == 0){
                    if(Item != NULL){
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMin\" (%i)\n",(i + 1),*((int*)Item));
                    }else{
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMin\" (NULL)\n",(i + 1));
                    }
                }else{
                    if(Item != NULL){
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMinSource\" (%i)\n",(i + 1),*((int*)Item));
                    }else{
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMinSource\" (NULL)\n",(i + 1));
                    }
                }

                #endif // TESTENVIRONMENT_SHOWALL
                if(OpType == 0){
                    OpRes = PriorityQueueMM_RemoveMin(PQ,NULL);
                }else{
                    OpRes = PriorityQueueMM_RemoveMinSource(PQ,NULL);
                }
                TestResults_SetFromPQ1(&R1,PQ,OpRes);
                TestResults_IsDispItemNULL = 1;
                TestResults_DispItem = -1;

                if(OpType == 0){
                    OpRes = TestPQSFSim_RemoveMin(Sim,&R2);
                }else{
                    OpRes = TestPQSFSim_RemoveMinSource(Sim,&R2);
                }
                TestResults_IsDispItemNULL = 1;
                TestResults_DispItem = -1;
                if(!TestResults_Equal(&R1,&R2)){
                    if(OpType == 0){
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMin\" indicates an error!\n",(i + 1));
                    }else{
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMinSource\" indicates an error!\n",(i + 1));
                    }
                    if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                        printf("        Expected Results:\n");
                        printf("        %s\n",expectedRes);
                        printf("        Actual Results:\n");
                        printf("        %s\n",actualRes);
                        printf("\n");
                        free((void*)actualRes);
                        actualRes = TestResults_ToString(&R1);
                        printf("        Actual Results (Complete):\n");
                        printf("        %s\n",actualRes);
                        printf("\n");
                        TestEnvironment_BaseTest_PriorityQueueMMSF_Print(PQSF);
                    }
                    MyRandom_Dispose(Random);
                    TestItemProvider_Dispose(ItemP);
                    TestPQSFSim_Dispose(Sim);
                    PriorityQueueMM_Dispose(PQ,NULL);
                    return 0;
                }
                if(OpRes == -1){
                    if(OpType == 0){
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMin\" caused an unexpected exception!\n",(i + 1));
                    }else{
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMinSource\" caused an unexpected exception!\n",(i + 1));
                    }
                    MyRandom_Dispose(Random);
                    TestItemProvider_Dispose(ItemP);
                    TestPQSFSim_Dispose(Sim);
                    PriorityQueueMM_Dispose(PQ,NULL);
                    return 0;
                }
                if(OpType == 0){
                    OPCount_RemMin++;
                }else{
                    OPCount_RemMinS++;
                }
            }else{
                Item = TestPQSFSim_GetMax(Sim);

                #ifdef TESTENVIRONMENT_SHOWALL
                if(OpType == 2){
                    if(Item != NULL){
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMax\" (%i)\n",(i + 1),*((int*)Item));
                    }else{
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMax\" (NULL)\n",(i + 1));
                    }
                }else{
                    if(Item != NULL){
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMaxSource\" (%i)\n",(i + 1),*((int*)Item));
                    }else{
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMaxSource\" (NULL)\n",(i + 1));
                    }
                }
                #endif // TESTENVIRONMENT_SHOWALL

                if(OpType == 2){
                    OpRes = PriorityQueueMM_RemoveMax(PQ,NULL);
                }else{
                    OpRes = PriorityQueueMM_RemoveMaxSource(PQ,NULL);
                }
                TestResults_SetFromPQ1(&R1,PQ,OpRes);
                TestResults_IsDispItemNULL = 1;
                TestResults_DispItem = -1;

                if(OpType == 2){
                    OpRes = TestPQSFSim_RemoveMax(Sim,&R2);
                }else{
                    OpRes = TestPQSFSim_RemoveMaxSource(Sim,&R2);
                }
                TestResults_IsDispItemNULL = 1;
                TestResults_DispItem = -1;
                if(!TestResults_Equal(&R1,&R2)){
                    if(OpType == 2){
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMax\" indicates an error!\n", (i + 1));
                    }else{
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMaxSource\" indicates an error!\n", (i + 1));
                    }
                    if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                        printf("        Expected Results:\n");
                        printf("        %s\n",expectedRes);
                        printf("        Actual Results:\n");
                        printf("        %s\n",actualRes);
                        printf("\n");
                        free((void*)actualRes);
                        actualRes = TestResults_ToString(&R1);
                        printf("        Actual Results (Complete):\n");
                        printf("        %s\n",actualRes);
                        printf("\n");
                        TestEnvironment_BaseTest_PriorityQueueMMSF_Print(PQSF);
                    }
                    MyRandom_Dispose(Random);
                    TestItemProvider_Dispose(ItemP);
                    TestPQSFSim_Dispose(Sim);
                    PriorityQueueMM_Dispose(PQ,NULL);
                    return 0;
                }
                if(OpRes == -1){
                    if(OpType == 2){
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMax\" caused an unexpected exception!\n",(i + 1));
                    }else{
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMaxSource\" caused an unexpected exception!\n",(i + 1));
                    }
                    MyRandom_Dispose(Random);
                    TestItemProvider_Dispose(ItemP);
                    TestPQSFSim_Dispose(Sim);
                    PriorityQueueMM_Dispose(PQ,NULL);
                    return 0;
                }
                if(OpType == 2){
                    OPCount_RemMax++;
                }else{
                    OPCount_RemMaxS++;
                }
            }
            if(OpRes == 1){TestItemProvider_Add(ItemP,Item);}
        }else{
            Index = MyRandom_GetInt2(Random,0,TestItemProvider_GetCount(ItemP) - 1);
            Item = TestItemProvider_Get(ItemP,Index);

            #ifdef TESTENVIRONMENT_SHOWALL
            printf("[INFO] Operation %i: \"PriorityQueueMM_Insert(%i)\"\n",(i + 1),*((int*)Item));
            #endif // TESTENVIRONMENT_SHOWALL

            OpRes = PriorityQueueMM_Insert(PQ,Item,NULL);
            TestResults_SetFromPQ1(&R1,PQ,OpRes);
            TestResults_IsDispItemNULL = 1;
            TestResults_DispItem = -1;

            OpRes = TestPQSFSim_Insert(Sim,Item,&R2);
            TestResults_IsDispItemNULL = 1;
            TestResults_DispItem = -1;
            if(!TestResults_Equal(&R1,&R2)){
                printf("[ERROR] Operation %i, \"PriorityQueueMM_Insert(%i)\" indicates an error!\n",(i + 1),*((int*)Item));
                if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                    printf("        Expected Results:\n");
                    printf("        %s\n",expectedRes);
                    printf("        Actual Results:\n");
                    printf("        %s\n",actualRes);
                    printf("\n");
                    free((void*)actualRes);
                    actualRes = TestResults_ToString(&R1);
                    printf("        Actual Results (Complete):\n");
                    printf("        %s\n",actualRes);
                    printf("\n");
                    TestEnvironment_BaseTest_PriorityQueueMMSF_Print(PQSF);
                }
                MyRandom_Dispose(Random);
                TestItemProvider_Dispose(ItemP);
                TestPQSFSim_Dispose(Sim);
                PriorityQueueMM_Dispose(PQ,NULL);
                return 0;
            }
            if(OpRes == 1){TestItemProvider_Remove(ItemP,Index);}
            if(OpRes == -1){
                printf("[ERROR] Operation %i, \"PriorityQueueMM_Insert(%i)\" caused an unexpected exception!\n",(i + 1),*((int*)Item));
                MyRandom_Dispose(Random);
                TestItemProvider_Dispose(ItemP);
                TestPQSFSim_Dispose(Sim);
                PriorityQueueMM_Dispose(PQ,NULL);
                return 0;
            }
            OPCount_Insert++;
        }

        time(&CurTime);
        if(difftime(CurTime,LastDispTime) >= 1.0){
            time(&LastDispTime);
            #ifndef TESTENVIRONMENT_ENDLESS
            printf("[INFO] %i Operations of %i done! (%i%%)\n",(i + 1),(TestOps),(((i + 1) * 100) / TestOps));
            #else // TESTENVIRONMENT_ENDLESS
            printf("[INFO] %i Operations done!\n",(i + 1));
            #endif // TESTENVIRONMENT_ENDLESS
        }
    }
    printf("\n");
    printf("[INFO] All Operations done!\n");
    printf("       Inserts       : %i\n",OPCount_Insert);
    printf("       Removes  (Min): %i\n",OPCount_RemMin);
    printf("       Removes  (Max): %i\n",OPCount_RemMax);
    printf("       RemovesS (Min): %i\n",OPCount_RemMinS);
    printf("       RemovesS (Max): %i\n",OPCount_RemMaxS);

    return 1;
}

int TestEnvironment_BaseTest_PriorityQueueMMAF(int TestOps){
    MyRandom* Random = MyRandom_Create();

    #ifndef TESTENVIRONMENT_ENDLESS
    int i;
    #else // TESTENVIRONMENT_ENDLESS
    unsigned int i;
    #endif // TESTENVIRONMENT_ENDLESS
    int Items[256];

    TestItemProvider* ItemP = TestItemProvider_Create(256);
    if(ItemP == NULL){
        printf("        Function \"%s\" failed!\n",__FUNCTION__);
        MyRandom_Dispose(Random);
        return 0;
    }

    for(i = 0;i < 256;i++){
        Items[i] = i + 1;
        TestItemProvider_Add(ItemP,(void*)(&(Items[i])));
    }

    TestResults R1;     //Actual    Results
    TestResults R2;     //Expected  Results

    int MaxItems = MyRandom_GetInt2(Random,40,50);
    size_t NecessarySize = PriorityQueueMMAF_GetSizeFor(MaxItems,NULL);

    TestPQSFSim* Sim = TestPQSFSim_Create(NecessarySize,MaxItems,TestEnvironment_Compare,TestEnvironment_DisposeItem,&R2);

    void* MemPtr = malloc(NecessarySize);
    if(MemPtr == NULL){
        printf("[ERROR] Function \"%s\" failed!\n",__FUNCTION__);
        printf("        \"MemPtr\" could not be allocated!\n");
        MyRandom_Dispose(Random);
        TestItemProvider_Dispose(ItemP);
        TestPQSFSim_Dispose(Sim);
        return 0;
    }

    PriorityQueueMMAF* PQAF = PriorityQueueMMAF_Create(MemPtr,NecessarySize,TestEnvironment_Compare,TestEnvironment_DisposeItem,NULL,NULL,NULL);
    PriorityQueueMM* PQ = PriorityQueueMMAF_Get_PriorityQueueMM(PQAF,NULL);

    TestResults_SetFromPQ1(&R1,PQ,0);

    TestResults_IsDispItemNULL = 1;
    TestResults_DispItem = -1;

    char* expectedRes;
    char* actualRes;

    if(!TestResults_Equal(&R1,&R2)){
        printf("[ERROR] Operation \"PriorityQueueMMAF_Create\" indicates an error!\n");
        if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
            printf("        Expected Results:\n");
            printf("        %s\n",expectedRes);
            printf("        Actual Results:\n");
            printf("        %s\n",actualRes);
        }
        MyRandom_Dispose(Random);
        TestItemProvider_Dispose(ItemP);
        TestPQSFSim_Dispose(Sim);
        return 0;
    }

    #ifndef TESTENVIRONMENT_ENDLESS
    printf("[INFO] Starting %i Operations:\n",TestOps);
    #else // TESTENVIRONMENT_ENDLESS
    printf("[INFO] Starting \"infinite\" Operations:\n");
    #endif // TESTENVIRONMENT_ENDLESS
    int OpType;
    int Index;
    void* Item;
    int OpRes;
    int OPCount_Insert = 0;
    int OPCount_RemMin = 0;
    int OPCount_RemMax = 0;
    int OPCount_RemMinS = 0;
    int OPCount_RemMaxS = 0;
    time_t LastDispTime;
    time_t CurTime;
    time(&LastDispTime);
    #ifndef TESTENVIRONMENT_ENDLESS
    for(i = 0;i < TestOps;i++){
    #else // TESTENVIRONMENT_ENDLESS
    for(i = 0;i >= 0;i++){
    #endif // TESTENVIRONMENT_ENDLESS
        #ifdef TESTENVIRONMENT_SHOWTRE
        TestEnvironment_BaseTest_PriorityQueueMMAF_Print(PQAF);
        #endif // TESTENVIRONMENT_SHOWTRE
        OpType = MyRandom_GetInt2(Random,0,1);
        if(OpType == 0){    //Remove item:
            OpType = MyRandom_GetInt2(Random,0,3);
            if(OpType < 2){
                Item = TestPQSFSim_GetMin(Sim);

                #ifdef TESTENVIRONMENT_SHOWALL
                if(OpType == 0){
                    if(Item != NULL){
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMin\" (%i)\n",(i + 1),*((int*)Item));
                    }else{
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMin\" (NULL)\n",(i + 1));
                    }
                }else{
                    if(Item != NULL){
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMinSource\" (%i)\n",(i + 1),*((int*)Item));
                    }else{
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMinSource\" (NULL)\n",(i + 1));
                    }
                }

                #endif // TESTENVIRONMENT_SHOWALL
                if(OpType == 0){
                    OpRes = PriorityQueueMM_RemoveMin(PQ,NULL);
                }else{
                    OpRes = PriorityQueueMM_RemoveMinSource(PQ,NULL);
                }
                TestResults_SetFromPQ1(&R1,PQ,OpRes);
                TestResults_IsDispItemNULL = 1;
                TestResults_DispItem = -1;

                if(OpType == 0){
                    OpRes = TestPQSFSim_RemoveMin(Sim,&R2);
                }else{
                    OpRes = TestPQSFSim_RemoveMinSource(Sim,&R2);
                }
                TestResults_IsDispItemNULL = 1;
                TestResults_DispItem = -1;
                if(!TestResults_Equal(&R1,&R2)){
                    if(OpType == 0){
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMin\" indicates an error!\n",(i + 1));
                    }else{
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMinSource\" indicates an error!\n",(i + 1));
                    }
                    if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                        printf("        Expected Results:\n");
                        printf("        %s\n",expectedRes);
                        printf("        Actual Results:\n");
                        printf("        %s\n",actualRes);
                        printf("\n");
                        free((void*)actualRes);
                        actualRes = TestResults_ToString(&R1);
                        printf("        Actual Results (Complete):\n");
                        printf("        %s\n",actualRes);
                        printf("\n");
                        TestEnvironment_BaseTest_PriorityQueueMMAF_Print(PQAF);
                    }
                    MyRandom_Dispose(Random);
                    TestItemProvider_Dispose(ItemP);
                    TestPQSFSim_Dispose(Sim);
                    PriorityQueueMM_Dispose(PQ,NULL);
                    return 0;
                }
                if(OpRes == -1){
                    if(OpType == 0){
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMin\" caused an unexpected exception!\n",(i + 1));
                    }else{
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMinSource\" caused an unexpected exception!\n",(i + 1));
                    }
                    MyRandom_Dispose(Random);
                    TestItemProvider_Dispose(ItemP);
                    TestPQSFSim_Dispose(Sim);
                    PriorityQueueMM_Dispose(PQ,NULL);
                    return 0;
                }
                if(OpType == 0){
                    OPCount_RemMin++;
                }else{
                    OPCount_RemMinS++;
                }
            }else{
                Item = TestPQSFSim_GetMax(Sim);

                #ifdef TESTENVIRONMENT_SHOWALL
                if(OpType == 2){
                    if(Item != NULL){
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMax\" (%i)\n",(i + 1),*((int*)Item));
                    }else{
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMax\" (NULL)\n",(i + 1));
                    }
                }else{
                    if(Item != NULL){
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMaxSource\" (%i)\n",(i + 1),*((int*)Item));
                    }else{
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMaxSource\" (NULL)\n",(i + 1));
                    }
                }
                #endif // TESTENVIRONMENT_SHOWALL

                if(OpType == 2){
                    OpRes = PriorityQueueMM_RemoveMax(PQ,NULL);
                }else{
                    OpRes = PriorityQueueMM_RemoveMaxSource(PQ,NULL);
                }
                TestResults_SetFromPQ1(&R1,PQ,OpRes);
                TestResults_IsDispItemNULL = 1;
                TestResults_DispItem = -1;

                if(OpType == 2){
                    OpRes = TestPQSFSim_RemoveMax(Sim,&R2);
                }else{
                    OpRes = TestPQSFSim_RemoveMaxSource(Sim,&R2);
                }
                TestResults_IsDispItemNULL = 1;
                TestResults_DispItem = -1;
                if(!TestResults_Equal(&R1,&R2)){
                    if(OpType == 2){
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMax\" indicates an error!\n", (i + 1));
                    }else{
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMaxSource\" indicates an error!\n", (i + 1));
                    }
                    if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                        printf("        Expected Results:\n");
                        printf("        %s\n",expectedRes);
                        printf("        Actual Results:\n");
                        printf("        %s\n",actualRes);
                        printf("\n");
                        free((void*)actualRes);
                        actualRes = TestResults_ToString(&R1);
                        printf("        Actual Results (Complete):\n");
                        printf("        %s\n",actualRes);
                        printf("\n");
                        TestEnvironment_BaseTest_PriorityQueueMMAF_Print(PQAF);
                    }
                    MyRandom_Dispose(Random);
                    TestItemProvider_Dispose(ItemP);
                    TestPQSFSim_Dispose(Sim);
                    PriorityQueueMM_Dispose(PQ,NULL);
                    return 0;
                }
                if(OpRes == -1){
                    if(OpType == 2){
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMax\" caused an unexpected exception!\n",(i + 1));
                    }else{
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMaxSource\" caused an unexpected exception!\n",(i + 1));
                    }
                    MyRandom_Dispose(Random);
                    TestItemProvider_Dispose(ItemP);
                    TestPQSFSim_Dispose(Sim);
                    PriorityQueueMM_Dispose(PQ,NULL);
                    return 0;
                }
                if(OpType == 2){
                    OPCount_RemMax++;
                }else{
                    OPCount_RemMaxS++;
                }
            }
            if(OpRes == 1){TestItemProvider_Add(ItemP,Item);}
        }else{
            Index = MyRandom_GetInt2(Random,0,TestItemProvider_GetCount(ItemP) - 1);
            Item = TestItemProvider_Get(ItemP,Index);

            #ifdef TESTENVIRONMENT_SHOWALL
            printf("[INFO] Operation %i: \"PriorityQueueMM_Insert(%i)\"\n",(i + 1),*((int*)Item));
            #endif // TESTENVIRONMENT_SHOWALL

            OpRes = PriorityQueueMM_Insert(PQ,Item,NULL);
            TestResults_SetFromPQ1(&R1,PQ,OpRes);
            TestResults_IsDispItemNULL = 1;
            TestResults_DispItem = -1;

            OpRes = TestPQSFSim_Insert(Sim,Item,&R2);
            TestResults_IsDispItemNULL = 1;
            TestResults_DispItem = -1;
            if(!TestResults_Equal(&R1,&R2)){
                printf("[ERROR] Operation %i, \"PriorityQueueMM_Insert(%i)\" indicates an error!\n",(i + 1),*((int*)Item));
                if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                    printf("        Expected Results:\n");
                    printf("        %s\n",expectedRes);
                    printf("        Actual Results:\n");
                    printf("        %s\n",actualRes);
                    printf("\n");
                    free((void*)actualRes);
                    actualRes = TestResults_ToString(&R1);
                    printf("        Actual Results (Complete):\n");
                    printf("        %s\n",actualRes);
                    printf("\n");
                    TestEnvironment_BaseTest_PriorityQueueMMAF_Print(PQAF);
                }
                MyRandom_Dispose(Random);
                TestItemProvider_Dispose(ItemP);
                TestPQSFSim_Dispose(Sim);
                PriorityQueueMM_Dispose(PQ,NULL);
                return 0;
            }
            if(OpRes == 1){TestItemProvider_Remove(ItemP,Index);}
            if(OpRes == -1){
                printf("[ERROR] Operation %i, \"PriorityQueueMM_Insert(%i)\" caused an unexpected exception!\n",(i + 1),*((int*)Item));
                MyRandom_Dispose(Random);
                TestItemProvider_Dispose(ItemP);
                TestPQSFSim_Dispose(Sim);
                PriorityQueueMM_Dispose(PQ,NULL);
                return 0;
            }
            OPCount_Insert++;
        }

        time(&CurTime);
        if(difftime(CurTime,LastDispTime) >= 1.0){
            time(&LastDispTime);
            #ifndef TESTENVIRONMENT_ENDLESS
            printf("[INFO] %i Operations of %i done! (%i%%)\n",(i + 1),(TestOps),(((i + 1) * 100) / TestOps));
            #else // TESTENVIRONMENT_ENDLESS
            printf("[INFO] %i Operations done!\n",(i + 1));
            #endif // TESTENVIRONMENT_ENDLESS
        }
    }
    printf("\n");
    printf("[INFO] All Operations done!\n");
    printf("       Inserts       : %i\n",OPCount_Insert);
    printf("       Removes  (Min): %i\n",OPCount_RemMin);
    printf("       Removes  (Max): %i\n",OPCount_RemMax);
    printf("       RemovesS (Min): %i\n",OPCount_RemMinS);
    printf("       RemovesS (Max): %i\n",OPCount_RemMaxS);

    return 1;
}

int TestEnvironment_BaseTest_PriorityQueueMMSD(int TestOps){
    MyRandom* Random = MyRandom_Create();

    #ifndef TESTENVIRONMENT_ENDLESS
    int i;
    #else // TESTENVIRONMENT_ENDLESS
    unsigned int i;
    #endif // TESTENVIRONMENT_ENDLESS
    int Items[256];

    TestItemProvider* ItemP = TestItemProvider_Create(256);
    if(ItemP == NULL){
        printf("        Function \"%s\" failed!\n",__FUNCTION__);
        MyRandom_Dispose(Random);
        return 0;
    }

    for(i = 0;i < 256;i++){
        Items[i] = i + 1;
        TestItemProvider_Add(ItemP,(void*)(&(Items[i])));
    }

    TestResults R1;     //Actual    Results
    TestResults R2;     //Expected  Results

    TestPQSDSim* Sim = TestPQSDSim_Create(TestEnvironment_Compare,TestEnvironment_DisposeItem,&R2);

    void* MemPtr = malloc(sizeof(PriorityQueueMMSD));
    if(MemPtr == NULL){
        printf("[ERROR] Function \"%s\" failed!\n",__FUNCTION__);
        printf("        \"MemPtr\" could not be allocated!\n");
        MyRandom_Dispose(Random);
        TestItemProvider_Dispose(ItemP);
        TestPQSDSim_Dispose(Sim);
        return 0;
    }

    PriorityQueueMMSD* PQSD = PriorityQueueMMSD_Create(MemPtr,sizeof(PriorityQueueMMSD),TestEnvironment_Compare,TestEnvironment_DisposeItem,NULL,NULL,NULL);
    PriorityQueueMM* PQ = PriorityQueueMMSD_Get_PriorityQueueMM(PQSD,NULL);

    TestResults_SetFromPQ1(&R1,PQ,0);

    TestResults_IsDispItemNULL = 1;
    TestResults_DispItem = -1;

    char* expectedRes;
    char* actualRes;

    if(!TestResults_Equal(&R1,&R2)){
        printf("[ERROR] Operation \"PriorityQueueMMSD_Create\" indicates an error!\n");
        if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
            printf("        Expected Results:\n");
            printf("        %s\n",expectedRes);
            printf("        Actual Results:\n");
            printf("        %s\n",actualRes);
        }
        MyRandom_Dispose(Random);
        TestItemProvider_Dispose(ItemP);
        TestPQSDSim_Dispose(Sim);
        return 0;
    }

    //#define TESTENVIRONMENT_BASETEST_SPECTEST

    int OpType;
    int Index;
    void* Item;
    int OpRes;
    int OPCount_Insert = 0;
    int OPCount_RemMin = 0;
    int OPCount_RemMax = 0;
    int OPCount_RemMinS = 0;
    int OPCount_RemMaxS = 0;
    #ifdef TESTENVIRONMENT_BASETEST_SPECTEST
    int Indizes[5];
    Indizes[0] = 27;
    Indizes[1] = 248;
    Indizes[2] = 208;
    Indizes[3] = 148;
    Indizes[4] = 242;
    Indizes[5] = 143;
    printf("[INFO] Additional Test-Case:\n");
    for(i = 0;i < 6;i++){
        //Index = MyRandom_GetInt2(Random,0,TestItemProvider_GetCount(ItemP) - 1);
        Index = Indizes[i];
        Item = TestItemProvider_Get(ItemP,Index);

        #ifdef TESTENVIRONMENT_SHOWALL
        printf("[INFO] Operation %i: \"PriorityQueueMM_Insert(%i)\"\n",(i + 1),*((int*)Item));
        #endif // TESTENVIRONMENT_SHOWALL

        OpRes = PriorityQueueMM_Insert(PQ,Item,NULL);
        TestResults_SetFromPQ1(&R1,PQ,OpRes);
        TestResults_IsDispItemNULL = 1;
        TestResults_DispItem = -1;

        OpRes = TestPQSDSim_Insert(Sim,Item,&R2);
        TestResults_IsDispItemNULL = 1;
        TestResults_DispItem = -1;
        if(!TestResults_Equal(&R1,&R2)){
            printf("[ERROR] Operation %i, \"PriorityQueueMM_Insert(%i)\" indicates an error!\n",(i + 1),*((int*)Item));
            if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                printf("        Expected Results:\n");
                printf("        %s\n",expectedRes);
                printf("        Actual Results:\n");
                printf("        %s\n",actualRes);
                printf("\n");
                free((void*)actualRes);
                actualRes = TestResults_ToString(&R1);
                printf("        Actual Results (Complete):\n");
                printf("        %s\n",actualRes);
                printf("\n");
                TestEnvironment_BaseTest_PriorityQueueMMSD_Print(PQSD);
            }
            MyRandom_Dispose(Random);
            TestItemProvider_Dispose(ItemP);
            TestPQSDSim_Dispose(Sim);
            PriorityQueueMM_Dispose(PQ,NULL);
            return 0;
        }
        if(OpRes == 1){TestItemProvider_Remove(ItemP,Index);}
        if(OpRes == -1){
            printf("[ERROR] Operation %i, \"PriorityQueueMM_Insert(%i)\" caused an unexpected exception!\n",(i + 1),*((int*)Item));
            MyRandom_Dispose(Random);
            TestItemProvider_Dispose(ItemP);
            TestPQSDSim_Dispose(Sim);
            PriorityQueueMM_Dispose(PQ,NULL);
            return 0;
        }
        OPCount_Insert++;
    }
    #endif // TESTENVIRONMENT_BASETEST_SPECTEST

    #ifndef TESTENVIRONMENT_ENDLESS
    printf("[INFO] Starting %i Operations:\n",TestOps);
    #else // TESTENVIRONMENT_ENDLESS
    printf("[INFO] Starting \"infinite\" Operations:\n");
    #endif // TESTENVIRONMENT_ENDLESS

    time_t LastDispTime;
    time_t CurTime;
    time(&LastDispTime);
    #ifndef TESTENVIRONMENT_ENDLESS
    for(i = 0;i < TestOps;i++){
    #else // TESTENVIRONMENT_ENDLESS
    for(i = 0;i >= 0;i++){
    #endif // TESTENVIRONMENT_ENDLESS
        #ifdef TESTENVIRONMENT_SHOWTRE
        TestEnvironment_BaseTest_PriorityQueueMMSD_Print(PQSD);
        #endif // TESTENVIRONMENT_SHOWTRE
        if(TestItemProvider_GetCount(ItemP) > 0){
            OpType = MyRandom_GetInt2(Random,0,1);
        }else{OpType = 0;}

        //Special test (to check some very specific error-cases):
        if(i < 94){OpType = 1;}
        if(TestItemProvider_GetCount(ItemP) <= 160){OpType = 0;}
        if(TestItemProvider_GetCount(ItemP) > 166){OpType = 1;}

        if(OpType == 0){    //Remove item:
            OpType = MyRandom_GetInt2(Random,0,3);
            if(OpType < 2){
                Item = TestPQSDSim_GetMin(Sim);

                #ifdef TESTENVIRONMENT_SHOWALL
                if(OpType == 0){
                    if(Item != NULL){
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMin\" (%i)\n",(i + 1),*((int*)Item));
                    }else{
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMin\" (NULL)\n",(i + 1));
                    }
                }else{
                    if(Item != NULL){
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMinSource\" (%i)\n",(i + 1),*((int*)Item));
                    }else{
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMinSource\" (NULL)\n",(i + 1));
                    }
                }

                #endif // TESTENVIRONMENT_SHOWALL
                if(OpType == 0){
                    OpRes = PriorityQueueMM_RemoveMin(PQ,NULL);
                }else{
                    OpRes = PriorityQueueMM_RemoveMinSource(PQ,NULL);
                }
                TestResults_SetFromPQ1(&R1,PQ,OpRes);
                TestResults_IsDispItemNULL = 1;
                TestResults_DispItem = -1;

                if(OpType == 0){
                    OpRes = TestPQSDSim_RemoveMin(Sim,&R2);
                }else{
                    OpRes = TestPQSDSim_RemoveMinSource(Sim,&R2);
                }
                TestResults_IsDispItemNULL = 1;
                TestResults_DispItem = -1;
                if(!TestResults_Equal(&R1,&R2)){
                    if(OpType == 0){
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMin\" indicates an error!\n",(i + 1));
                    }else{
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMinSource\" indicates an error!\n",(i + 1));
                    }
                    if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                        printf("        Expected Results:\n");
                        printf("        %s\n",expectedRes);
                        printf("        Actual Results:\n");
                        printf("        %s\n",actualRes);
                        printf("\n");
                        free((void*)actualRes);
                        actualRes = TestResults_ToString(&R1);
                        printf("        Actual Results (Complete):\n");
                        printf("        %s\n",actualRes);
                        printf("\n");
                        TestEnvironment_BaseTest_PriorityQueueMMSD_Print(PQSD);
                    }
                    MyRandom_Dispose(Random);
                    TestItemProvider_Dispose(ItemP);
                    TestPQSDSim_Dispose(Sim);
                    PriorityQueueMM_Dispose(PQ,NULL);
                    return 0;
                }
                if(OpRes == -1){
                    if(OpType == 0){
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMin\" caused an unexpected exception!\n",(i + 1));
                    }else{
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMinSource\" caused an unexpected exception!\n",(i + 1));
                    }
                    MyRandom_Dispose(Random);
                    TestItemProvider_Dispose(ItemP);
                    TestPQSDSim_Dispose(Sim);
                    PriorityQueueMM_Dispose(PQ,NULL);
                    return 0;
                }
                if(OpType == 0){
                    OPCount_RemMin++;
                }else{
                    OPCount_RemMinS++;
                }
            }else{
                Item = TestPQSDSim_GetMax(Sim);

                #ifdef TESTENVIRONMENT_SHOWALL
                if(OpType == 2){
                    if(Item != NULL){
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMax\" (%i)\n",(i + 1),*((int*)Item));
                    }else{
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMax\" (NULL)\n",(i + 1));
                    }
                }else{
                    if(Item != NULL){
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMaxSource\" (%i)\n",(i + 1),*((int*)Item));
                    }else{
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMaxSource\" (NULL)\n",(i + 1));
                    }
                }
                #endif // TESTENVIRONMENT_SHOWALL

                if(OpType == 2){
                    OpRes = PriorityQueueMM_RemoveMax(PQ,NULL);
                }else{
                    OpRes = PriorityQueueMM_RemoveMaxSource(PQ,NULL);
                }
                TestResults_SetFromPQ1(&R1,PQ,OpRes);
                TestResults_IsDispItemNULL = 1;
                TestResults_DispItem = -1;

                if(OpType == 2){
                    OpRes = TestPQSDSim_RemoveMax(Sim,&R2);
                }else{
                    OpRes = TestPQSDSim_RemoveMaxSource(Sim,&R2);
                }
                TestResults_IsDispItemNULL = 1;
                TestResults_DispItem = -1;
                if(!TestResults_Equal(&R1,&R2)){
                    if(OpType == 2){
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMax\" indicates an error!\n", (i + 1));
                    }else{
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMaxSource\" indicates an error!\n", (i + 1));
                    }
                    if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                        printf("        Expected Results:\n");
                        printf("        %s\n",expectedRes);
                        printf("        Actual Results:\n");
                        printf("        %s\n",actualRes);
                        printf("\n");
                        free((void*)actualRes);
                        actualRes = TestResults_ToString(&R1);
                        printf("        Actual Results (Complete):\n");
                        printf("        %s\n",actualRes);
                        printf("\n");
                        TestEnvironment_BaseTest_PriorityQueueMMSD_Print(PQSD);
                    }
                    MyRandom_Dispose(Random);
                    TestItemProvider_Dispose(ItemP);
                    TestPQSDSim_Dispose(Sim);
                    PriorityQueueMM_Dispose(PQ,NULL);
                    return 0;
                }
                if(OpRes == -1){
                    if(OpType == 2){
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMax\" caused an unexpected exception!\n",(i + 1));
                    }else{
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMaxSource\" caused an unexpected exception!\n",(i + 1));
                    }
                    MyRandom_Dispose(Random);
                    TestItemProvider_Dispose(ItemP);
                    TestPQSDSim_Dispose(Sim);
                    PriorityQueueMM_Dispose(PQ,NULL);
                    return 0;
                }
                if(OpType == 2){
                    OPCount_RemMax++;
                }else{
                    OPCount_RemMaxS++;
                }
            }
            if(OpRes == 1){TestItemProvider_Add(ItemP,Item);}
        }else{
            Index = MyRandom_GetInt2(Random,0,TestItemProvider_GetCount(ItemP) - 1);
            Item = TestItemProvider_Get(ItemP,Index);

            #ifdef TESTENVIRONMENT_SHOWALL
            printf("[INFO] Operation %i: \"PriorityQueueMM_Insert(%i)\"\n",(i + 1),*((int*)Item));
            #endif // TESTENVIRONMENT_SHOWALL

            OpRes = PriorityQueueMM_Insert(PQ,Item,NULL);
            TestResults_SetFromPQ1(&R1,PQ,OpRes);
            TestResults_IsDispItemNULL = 1;
            TestResults_DispItem = -1;

            OpRes = TestPQSDSim_Insert(Sim,Item,&R2);
            TestResults_IsDispItemNULL = 1;
            TestResults_DispItem = -1;
            if(!TestResults_Equal(&R1,&R2)){
                printf("[ERROR] Operation %i, \"PriorityQueueMM_Insert(%i)\" indicates an error!\n",(i + 1),*((int*)Item));
                if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                    printf("        Expected Results:\n");
                    printf("        %s\n",expectedRes);
                    printf("        Actual Results:\n");
                    printf("        %s\n",actualRes);
                    printf("\n");
                    free((void*)actualRes);
                    actualRes = TestResults_ToString(&R1);
                    printf("        Actual Results (Complete):\n");
                    printf("        %s\n",actualRes);
                    printf("\n");
                    TestEnvironment_BaseTest_PriorityQueueMMSD_Print(PQSD);
                }
                MyRandom_Dispose(Random);
                TestItemProvider_Dispose(ItemP);
                TestPQSDSim_Dispose(Sim);
                PriorityQueueMM_Dispose(PQ,NULL);
                return 0;
            }
            if(OpRes == 1){TestItemProvider_Remove(ItemP,Index);}
            if(OpRes == -1){
                printf("[ERROR] Operation %i, \"PriorityQueueMM_Insert(%i)\" caused an unexpected exception!\n",(i + 1),*((int*)Item));
                MyRandom_Dispose(Random);
                TestItemProvider_Dispose(ItemP);
                TestPQSDSim_Dispose(Sim);
                PriorityQueueMM_Dispose(PQ,NULL);
                return 0;
            }
            OPCount_Insert++;
        }

        time(&CurTime);
        if(difftime(CurTime,LastDispTime) >= 1.0){
            time(&LastDispTime);
            #ifndef TESTENVIRONMENT_ENDLESS
            printf("[INFO] %i Operations of %i done! (%i%%)\n",(i + 1),(TestOps),(((i + 1) * 100) / TestOps));
            #else // TESTENVIRONMENT_ENDLESS
            printf("[INFO] %i Operations done!\n",(i + 1));
            #endif // TESTENVIRONMENT_ENDLESS
        }
    }
    printf("\n");
    printf("[INFO] All Operations done!\n");
    printf("       Inserts       : %i\n",OPCount_Insert);
    printf("       Removes  (Min): %i\n",OPCount_RemMin);
    printf("       Removes  (Max): %i\n",OPCount_RemMax);
    printf("       RemovesS (Min): %i\n",OPCount_RemMinS);
    printf("       RemovesS (Max): %i\n",OPCount_RemMaxS);

    return 1;
}

int TestEnvironment_BaseTest_PriorityQueueMMAD(int TestOps){
    MyRandom* Random = MyRandom_Create();

    #ifndef TESTENVIRONMENT_ENDLESS
    int i;
    #else // TESTENVIRONMENT_ENDLESS
    unsigned int i;
    #endif // TESTENVIRONMENT_ENDLESS
    int Items[256];

    TestItemProvider* ItemP = TestItemProvider_Create(256);
    if(ItemP == NULL){
        printf("        Function \"%s\" failed!\n",__FUNCTION__);
        MyRandom_Dispose(Random);
        return 0;
    }

    for(i = 0;i < 256;i++){
        Items[i] = i + 1;
        TestItemProvider_Add(ItemP,(void*)(&(Items[i])));
    }

    TestResults R1;     //Actual    Results
    TestResults R2;     //Expected  Results

    TestPQSDSim* Sim = TestPQSDSim_Create(TestEnvironment_Compare,TestEnvironment_DisposeItem,&R2);

    void* MemPtr = malloc(sizeof(PriorityQueueMMAD));
    if(MemPtr == NULL){
        printf("[ERROR] Function \"%s\" failed!\n",__FUNCTION__);
        printf("        \"MemPtr\" could not be allocated!\n");
        MyRandom_Dispose(Random);
        TestItemProvider_Dispose(ItemP);
        TestPQSDSim_Dispose(Sim);
        return 0;
    }

    PriorityQueueMMAD* PQAD = PriorityQueueMMAD_Create(MemPtr,sizeof(PriorityQueueMMAD),TestEnvironment_Compare,TestEnvironment_DisposeItem,NULL,NULL,NULL);
    PriorityQueueMM* PQ = PriorityQueueMMAD_Get_PriorityQueueMM(PQAD,NULL);

    TestResults_SetFromPQ1(&R1,PQ,0);

    TestResults_IsDispItemNULL = 1;
    TestResults_DispItem = -1;

    char* expectedRes;
    char* actualRes;

    if(!TestResults_Equal(&R1,&R2)){
        printf("[ERROR] Operation \"PriorityQueueMMAD_Create\" indicates an error!\n");
        if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
            printf("        Expected Results:\n");
            printf("        %s\n",expectedRes);
            printf("        Actual Results:\n");
            printf("        %s\n",actualRes);
        }
        MyRandom_Dispose(Random);
        TestItemProvider_Dispose(ItemP);
        TestPQSDSim_Dispose(Sim);
        return 0;
    }

    #ifndef TESTENVIRONMENT_ENDLESS
    printf("[INFO] Starting %i Operations:\n",TestOps);
    #else // TESTENVIRONMENT_ENDLESS
    printf("[INFO] Starting \"infinite\" Operations:\n");
    #endif // TESTENVIRONMENT_ENDLESS
    int OpType;
    int Index;
    void* Item;
    int OpRes;
    int OPCount_Insert = 0;
    int OPCount_RemMin = 0;
    int OPCount_RemMax = 0;
    int OPCount_RemMinS = 0;
    int OPCount_RemMaxS = 0;
    time_t LastDispTime;
    time_t CurTime;
    time(&LastDispTime);
    #ifndef TESTENVIRONMENT_ENDLESS
    for(i = 0;i < TestOps;i++){
    #else // TESTENVIRONMENT_ENDLESS
    for(i = 0;i >= 0;i++){
    #endif // TESTENVIRONMENT_ENDLESS
        #ifdef TESTENVIRONMENT_SHOWTRE
        TestEnvironment_BaseTest_PriorityQueueMMAD_Print(PQAD);
        #endif // TESTENVIRONMENT_SHOWTRE
        if(TestItemProvider_GetCount(ItemP) > 0){
            OpType = MyRandom_GetInt2(Random,0,1);
        }else{OpType = 0;}
        if(OpType == 0){    //Remove item:
            OpType = MyRandom_GetInt2(Random,0,3);
            if(OpType < 2){
                Item = TestPQSDSim_GetMin(Sim);

                #ifdef TESTENVIRONMENT_SHOWALL
                if(OpType == 0){
                    if(Item != NULL){
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMin\" (%i)\n",(i + 1),*((int*)Item));
                    }else{
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMin\" (NULL)\n",(i + 1));
                    }
                }else{
                    if(Item != NULL){
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMinSource\" (%i)\n",(i + 1),*((int*)Item));
                    }else{
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMinSource\" (NULL)\n",(i + 1));
                    }
                }

                #endif // TESTENVIRONMENT_SHOWALL
                if(OpType == 0){
                    OpRes = PriorityQueueMM_RemoveMin(PQ,NULL);
                }else{
                    OpRes = PriorityQueueMM_RemoveMinSource(PQ,NULL);
                }
                TestResults_SetFromPQ1(&R1,PQ,OpRes);
                TestResults_IsDispItemNULL = 1;
                TestResults_DispItem = -1;

                if(OpType == 0){
                    OpRes = TestPQSDSim_RemoveMin(Sim,&R2);
                }else{
                    OpRes = TestPQSDSim_RemoveMinSource(Sim,&R2);
                }
                TestResults_IsDispItemNULL = 1;
                TestResults_DispItem = -1;
                if(!TestResults_Equal(&R1,&R2)){
                    if(OpType == 0){
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMin\" indicates an error!\n",(i + 1));
                    }else{
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMinSource\" indicates an error!\n",(i + 1));
                    }
                    if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                        printf("        Expected Results:\n");
                        printf("        %s\n",expectedRes);
                        printf("        Actual Results:\n");
                        printf("        %s\n",actualRes);
                        printf("\n");
                        free((void*)actualRes);
                        actualRes = TestResults_ToString(&R1);
                        printf("        Actual Results (Complete):\n");
                        printf("        %s\n",actualRes);
                        printf("\n");
                        TestEnvironment_BaseTest_PriorityQueueMMAD_Print(PQAD);
                    }
                    MyRandom_Dispose(Random);
                    TestItemProvider_Dispose(ItemP);
                    TestPQSDSim_Dispose(Sim);
                    PriorityQueueMM_Dispose(PQ,NULL);
                    return 0;
                }
                if(OpRes == -1){
                    if(OpType == 0){
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMin\" caused an unexpected exception!\n",(i + 1));
                    }else{
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMinSource\" caused an unexpected exception!\n",(i + 1));
                    }
                    MyRandom_Dispose(Random);
                    TestItemProvider_Dispose(ItemP);
                    TestPQSDSim_Dispose(Sim);
                    PriorityQueueMM_Dispose(PQ,NULL);
                    return 0;
                }
                if(OpType == 0){
                    OPCount_RemMin++;
                }else{
                    OPCount_RemMinS++;
                }
            }else{
                Item = TestPQSDSim_GetMax(Sim);

                #ifdef TESTENVIRONMENT_SHOWALL
                if(OpType == 2){
                    if(Item != NULL){
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMax\" (%i)\n",(i + 1),*((int*)Item));
                    }else{
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMax\" (NULL)\n",(i + 1));
                    }
                }else{
                    if(Item != NULL){
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMaxSource\" (%i)\n",(i + 1),*((int*)Item));
                    }else{
                        printf("[INFO] Operation %i: \"PriorityQueueMM_RemoveMaxSource\" (NULL)\n",(i + 1));
                    }
                }
                #endif // TESTENVIRONMENT_SHOWALL

                if(OpType == 2){
                    OpRes = PriorityQueueMM_RemoveMax(PQ,NULL);
                }else{
                    OpRes = PriorityQueueMM_RemoveMaxSource(PQ,NULL);
                }
                TestResults_SetFromPQ1(&R1,PQ,OpRes);
                TestResults_IsDispItemNULL = 1;
                TestResults_DispItem = -1;

                if(OpType == 2){
                    OpRes = TestPQSDSim_RemoveMax(Sim,&R2);
                }else{
                    OpRes = TestPQSDSim_RemoveMaxSource(Sim,&R2);
                }
                TestResults_IsDispItemNULL = 1;
                TestResults_DispItem = -1;
                if(!TestResults_Equal(&R1,&R2)){
                    if(OpType == 2){
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMax\" indicates an error!\n", (i + 1));
                    }else{
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMaxSource\" indicates an error!\n", (i + 1));
                    }
                    if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                        printf("        Expected Results:\n");
                        printf("        %s\n",expectedRes);
                        printf("        Actual Results:\n");
                        printf("        %s\n",actualRes);
                        printf("\n");
                        free((void*)actualRes);
                        actualRes = TestResults_ToString(&R1);
                        printf("        Actual Results (Complete):\n");
                        printf("        %s\n",actualRes);
                        printf("\n");
                        TestEnvironment_BaseTest_PriorityQueueMMAD_Print(PQAD);
                    }
                    MyRandom_Dispose(Random);
                    TestItemProvider_Dispose(ItemP);
                    TestPQSDSim_Dispose(Sim);
                    PriorityQueueMM_Dispose(PQ,NULL);
                    return 0;
                }
                if(OpRes == -1){
                    if(OpType == 2){
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMax\" caused an unexpected exception!\n",(i + 1));
                    }else{
                        printf("[ERROR] Operation %i, \"PriorityQueueMM_RemoveMaxSource\" caused an unexpected exception!\n",(i + 1));
                    }
                    MyRandom_Dispose(Random);
                    TestItemProvider_Dispose(ItemP);
                    TestPQSDSim_Dispose(Sim);
                    PriorityQueueMM_Dispose(PQ,NULL);
                    return 0;
                }
                if(OpType == 2){
                    OPCount_RemMax++;
                }else{
                    OPCount_RemMaxS++;
                }
            }
            if(OpRes == 1){TestItemProvider_Add(ItemP,Item);}
        }else{
            Index = MyRandom_GetInt2(Random,0,TestItemProvider_GetCount(ItemP) - 1);
            Item = TestItemProvider_Get(ItemP,Index);

            #ifdef TESTENVIRONMENT_SHOWALL
            printf("[INFO] Operation %i: \"PriorityQueueMM_Insert(%i)\"\n",(i + 1),*((int*)Item));
            #endif // TESTENVIRONMENT_SHOWALL

            OpRes = PriorityQueueMM_Insert(PQ,Item,NULL);
            TestResults_SetFromPQ1(&R1,PQ,OpRes);
            TestResults_IsDispItemNULL = 1;
            TestResults_DispItem = -1;

            OpRes = TestPQSDSim_Insert(Sim,Item,&R2);
            TestResults_IsDispItemNULL = 1;
            TestResults_DispItem = -1;
            if(!TestResults_Equal(&R1,&R2)){
                printf("[ERROR] Operation %i, \"PriorityQueueMM_Insert(%i)\" indicates an error!\n",(i + 1),*((int*)Item));
                if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                    printf("        Expected Results:\n");
                    printf("        %s\n",expectedRes);
                    printf("        Actual Results:\n");
                    printf("        %s\n",actualRes);
                    printf("\n");
                    free((void*)actualRes);
                    actualRes = TestResults_ToString(&R1);
                    printf("        Actual Results (Complete):\n");
                    printf("        %s\n",actualRes);
                    printf("\n");
                    TestEnvironment_BaseTest_PriorityQueueMMAD_Print(PQAD);
                }
                MyRandom_Dispose(Random);
                TestItemProvider_Dispose(ItemP);
                TestPQSDSim_Dispose(Sim);
                PriorityQueueMM_Dispose(PQ,NULL);
                return 0;
            }
            if(OpRes == 1){TestItemProvider_Remove(ItemP,Index);}
            if(OpRes == -1){
                printf("[ERROR] Operation %i, \"PriorityQueueMM_Insert(%i)\" caused an unexpected exception!\n",(i + 1),*((int*)Item));
                MyRandom_Dispose(Random);
                TestItemProvider_Dispose(ItemP);
                TestPQSDSim_Dispose(Sim);
                PriorityQueueMM_Dispose(PQ,NULL);
                return 0;
            }
            OPCount_Insert++;
        }

        time(&CurTime);
        if(difftime(CurTime,LastDispTime) >= 1.0){
            time(&LastDispTime);
            #ifndef TESTENVIRONMENT_ENDLESS
            printf("[INFO] %i Operations of %i done! (%i%%)\n",(i + 1),(TestOps),(((i + 1) * 100) / TestOps));
            #else // TESTENVIRONMENT_ENDLESS
            printf("[INFO] %i Operations done!\n",(i + 1));
            #endif // TESTENVIRONMENT_ENDLESS
        }
    }
    printf("\n");
    printf("[INFO] All Operations done!\n");
    printf("       Inserts       : %i\n",OPCount_Insert);
    printf("       Removes  (Min): %i\n",OPCount_RemMin);
    printf("       Removes  (Max): %i\n",OPCount_RemMax);
    printf("       RemovesS (Min): %i\n",OPCount_RemMinS);
    printf("       RemovesS (Max): %i\n",OPCount_RemMaxS);

    return 1;
}



int TestEnvironment_AdvTest_PriorityQueueMMAF(int TestOps){
    MyRandom* Random = MyRandom_Create();

    #ifndef TESTENVIRONMENT_ENDLESS
    int i;
    #else // TESTENVIRONMENT_ENDLESS
    unsigned int i;
    #endif // TESTENVIRONMENT_ENDLESS
    int Items[256];
    void** Inserts = (void**)malloc(sizeof(void*) * 768);
    void** Insert;

    TestItemProvider* ItemP = TestItemProvider_Create(256);
    if(ItemP == NULL){
        printf("        Function \"%s\" failed!\n",__FUNCTION__);
        MyRandom_Dispose(Random);
        return 0;
    }

    TestItemProvider* EmptyInserts = TestItemProvider_Create(256);
    if(EmptyInserts == NULL){
        printf("        Function \"%s\" failed!\n",__FUNCTION__);
        MyRandom_Dispose(Random);
        TestItemProvider_Dispose(ItemP);
        return 0;
    }

    TestItemProvider* ActiveInserts = TestItemProvider_Create(256);
    if(ActiveInserts == NULL){
        printf("        Function \"%s\" failed!\n",__FUNCTION__);
        MyRandom_Dispose(Random);
        TestItemProvider_Dispose(ItemP);
        TestItemProvider_Dispose(EmptyInserts);
        return 0;
    }

    for(i = 0;i < 256;i++){
        Items[i] = i + 1;
        TestItemProvider_Add(ItemP,(void*)(&(Items[i])));
        TestItemProvider_Add(EmptyInserts,((void*)(&(Inserts[(i * 3)]))));
    }

    TestResults R1;     //Actual    Results
    TestResults R2;     //Expected  Results

    int MaxItems = MyRandom_GetInt2(Random,40,50);
    size_t NecessarySize = PriorityQueueMMAF_GetSizeFor(MaxItems,NULL);

    TestPQAFSim* Sim = TestPQAFSim_Create(NecessarySize,MaxItems,TestEnvironment_Compare,TestEnvironment_DisposeItem,&R2);

    void* MemPtr = malloc(NecessarySize);
    if(MemPtr == NULL){
        printf("[ERROR] Function \"%s\" failed!\n",__FUNCTION__);
        printf("        \"MemPtr\" could not be allocated!\n");
        MyRandom_Dispose(Random);
        TestItemProvider_Dispose(ItemP);
        TestItemProvider_Dispose(EmptyInserts);
        TestItemProvider_Dispose(ActiveInserts);
        TestPQAFSim_Dispose(Sim);
        return 0;
    }

    PriorityQueueMMAF* PQAF = PriorityQueueMMAF_Create(MemPtr,NecessarySize,TestEnvironment_Compare,TestEnvironment_DisposeItem,NULL,NULL,NULL);
    PriorityQueueMMA* PQA = PriorityQueueMMAF_Get_PriorityQueueMMA(PQAF,NULL);
    PriorityQueueMM* PQ = PriorityQueueMMAF_Get_PriorityQueueMM(PQAF,NULL);

    TestResults_SetFromPQ1(&R1,PQ,0);

    TestResults_IsDispItemNULL = 1;
    TestResults_DispItem = -1;

    char* expectedRes;
    char* actualRes;

    if(!TestResults_Equal(&R1,&R2)){
        printf("[ERROR] Operation \"PriorityQueueMMAF_Create\" indicates an error!\n");
        if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
            printf("        Expected Results:\n");
            printf("        %s\n",expectedRes);
            printf("        Actual Results:\n");
            printf("        %s\n",actualRes);
        }
        MyRandom_Dispose(Random);
        TestItemProvider_Dispose(ItemP);
        TestItemProvider_Dispose(EmptyInserts);
        TestItemProvider_Dispose(ActiveInserts);
        TestPQAFSim_Dispose(Sim);
        return 0;
    }

    //#define TESTENVIRONMENT_ADVTEST_SPECTEST

    int OpType;
    int Index;
    void* Item;
    int OpRes;
    int OPCount_Insert = 0;
    int OPCount_Rem = 0;
    int OPCount_RemS = 0;
    int OPCount_Contains = 0;
    int OPCount_Set = 0;
    int OPCount_Update = 0;
    #ifdef TESTENVIRONMENT_ADVTEST_SPECTEST
    int Indizes[5];
    Indizes[0] = 9;
    Indizes[1] = 65;
    Indizes[2] = 124;
    Indizes[3] = 201;
    Indizes[4] = 18;
    printf("[INFO] Additional Test-Case:\n");
    for(i = 0;i < 5;i++){
        #ifdef TESTENVIRONMENT_SHOWTRE
        TestEnvironment_BaseTest_PriorityQueueMMAF_Print(PQAF);
        #endif // TESTENVIRONMENT_SHOWTRE
        Index = Indizes[i];
        Item = TestItemProvider_Get(ItemP,Index); //Should contain Value "10"
        Insert = (void**)TestItemProvider_Get(EmptyInserts,TestItemProvider_GetCount(EmptyInserts) - 1);
        Insert[2] = Item;

        #ifdef TESTENVIRONMENT_SHOWALL
        printf("[INFO] Operation %i: \"PriorityQueueMMA_GetInsertedItem(%i)\"\n",(i + 1),*((int*)Item));
        #endif // TESTENVIRONMENT_SHOWALL

        Insert[1] = (void*)PriorityQueueMMA_GetInsertedItem(PQA,Item,NULL);
        TestResults_SetFromPQ2(&R1,PQ,PriorityQueueMMA_GetItemOfItem(PQA,Insert[1],NULL));
        TestResults_IsDispItemNULL = 1;
        TestResults_DispItem = -1;

        Insert[0] = (void*)TestPQAFSim_GetInsertedItem(Sim,Item,&R2);
        TestResults_IsDispItemNULL = 1;
        TestResults_DispItem = -1;
        if(!TestResults_Equal(&R1,&R2)){
            printf("[ERROR] Operation %i, \"PriorityQueueMMA_GetInsertedItem(%i)\" indicates an error!\n",(i + 1),*((int*)Item));
            if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                printf("        Expected Results:\n");
                printf("        %s\n",expectedRes);
                printf("        Actual Results:\n");
                printf("        %s\n",actualRes);
                printf("\n");
                free((void*)actualRes);
                actualRes = TestResults_ToString(&R1);
                printf("        Actual Results (Complete):\n");
                printf("        %s\n",actualRes);
                printf("\n");
                TestPQAFSim_Print(Sim);
                printf("\n");
                TestEnvironment_BaseTest_PriorityQueueMMAF_Print(PQAF);
            }
            MyRandom_Dispose(Random);
            TestItemProvider_Dispose(ItemP);
            TestItemProvider_Dispose(EmptyInserts);
            TestItemProvider_Dispose(ActiveInserts);
            TestPQAFSim_Dispose(Sim);
            PriorityQueueMM_Dispose(PQ,NULL);
            return 0;
        }
        if(Insert[0] != NULL){
            TestItemProvider_Remove(ItemP,Index);
            TestItemProvider_Remove(EmptyInserts,TestItemProvider_GetCount(EmptyInserts) - 1);
            TestItemProvider_Add(ActiveInserts,((void*)(&(Insert[0]))));
            #ifdef TESTENVIRONMENT_SHOWTRE
            TestEnvironment_BaseTest_PriorityQueueMMAF_Print(PQAF);
            #endif // TESTENVIRONMENT_SHOWTRE
        }
        /*
        if(Insert[0] == NULL){
            printf("[ERROR] Operation %i, \"PriorityQueueMMA_GetInsertedItem(%i)\" caused an unexpected exception!\n",(i + 1),*((int*)Item));
            MyRandom_Dispose(Random);
            TestItemProvider_Dispose(ItemP);
            TestItemProvider_Dispose(EmptyInserts);
            TestItemProvider_Dispose(ActiveInserts);
            TestPQAFSim_Dispose(Sim);
            PriorityQueueMM_Dispose(PQ,NULL);
            return 0;
        }
        */
        OPCount_Insert++;
    }
    #endif // TESTENVIRONMENT_ADVTEST_SPECTEST

    #ifndef TESTENVIRONMENT_ENDLESS
    printf("[INFO] Starting %i Operations:\n",TestOps);
    #else // TESTENVIRONMENT_ENDLESS
    printf("[INFO] Starting \"infinite\" Operations:\n");
    #endif // TESTENVIRONMENT_ENDLESS
    time_t LastDispTime;
    time_t CurTime;
    time(&LastDispTime);
    #ifndef TESTENVIRONMENT_ENDLESS
    for(i = 0;i < TestOps;i++){
    #else // TESTENVIRONMENT_ENDLESS
    for(i = 0;i >= 0;i++){
    #endif // TESTENVIRONMENT_ENDLESS
        #ifdef TESTENVIRONMENT_SHOWTRE
        TestEnvironment_BaseTest_PriorityQueueMMAF_Print(PQAF);
        #endif // TESTENVIRONMENT_SHOWTRE
        OpType = MyRandom_GetInt2(Random,0,4);
        if((TestItemProvider_GetCount(ActiveInserts) == 0)&&(OpType != 1)){OpType = 1;}
        if(OpType == 0){    //Remove item:
            #ifndef TESTENVIRONMENT_VALIDCALLS
            OpType = MyRandom_GetInt2(Random,0,3);
            #else // TESTENVIRONMENT_VALIDCALLS
            OpType = MyRandom_GetInt2(Random,0,1) * 2;
            #endif // TESTENVIRONMENT_VALIDCALLS
            if(OpType < 2){
                Index = MyRandom_GetInt2(Random,0,TestItemProvider_GetCount(ActiveInserts) - 1);
                Insert = (void**)TestItemProvider_Get(ActiveInserts,Index);

                #ifdef TESTENVIRONMENT_SHOWALL
                if(OpType == 0){
                    printf("[INFO] Operation %i: \"PriorityQueueMMA_RemoveItem\" (%i)\n",(i + 1),*((int*)(Insert[2])));
                }else{
                    printf("[INFO] Operation %i: \"PriorityQueueMMA_RemoveItem\" (INV)\n",(i + 1));
                }
                #endif // TESTENVIRONMENT_SHOWALL

                if(OpType == 0){
                    OpRes = PriorityQueueMMA_RemoveItem(PQA,Insert[1],NULL);
                }else{
                    OpRes = PriorityQueueMMA_RemoveItem(PQA,Insert[0],NULL);
                }
                TestResults_SetFromPQ1(&R1,PQ,OpRes);
                TestResults_IsDispItemNULL = 1;
                TestResults_DispItem = -1;

                if(OpType == 0){
                    OpRes = TestPQAFSim_Remove(Sim,Insert[0],&R2);
                }else{
                    OpRes = TestPQAFSim_Remove(Sim,Insert[1],&R2);
                }
                TestResults_IsDispItemNULL = 1;
                TestResults_DispItem = -1;
                if(!TestResults_Equal(&R1,&R2)){
                    printf("[ERROR] Operation %i, \"PriorityQueueMMA_RemoveItem\" indicates an error!\n",(i + 1));
                    if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                        printf("        Expected Results:\n");
                        printf("        %s\n",expectedRes);
                        printf("        Actual Results:\n");
                        printf("        %s\n",actualRes);
                        printf("\n");
                        free((void*)actualRes);
                        actualRes = TestResults_ToString(&R1);
                        printf("        Actual Results (Complete):\n");
                        printf("        %s\n",actualRes);
                        printf("\n");
                        TestPQAFSim_Print(Sim);
                        printf("\n");
                        TestEnvironment_BaseTest_PriorityQueueMMAF_Print(PQAF);
                    }
                    MyRandom_Dispose(Random);
                    TestItemProvider_Dispose(ItemP);
                    TestItemProvider_Dispose(EmptyInserts);
                    TestItemProvider_Dispose(ActiveInserts);
                    TestPQAFSim_Dispose(Sim);
                    PriorityQueueMM_Dispose(PQ,NULL);
                    return 0;
                }
                if(OpRes == -1){
                    printf("[ERROR] Operation %i, \"PriorityQueueMMA_RemoveItem\" caused an unexpected exception!\n",(i + 1));
                    MyRandom_Dispose(Random);
                    TestItemProvider_Dispose(ItemP);
                    TestItemProvider_Dispose(EmptyInserts);
                    TestItemProvider_Dispose(ActiveInserts);
                    TestPQAFSim_Dispose(Sim);
                    PriorityQueueMM_Dispose(PQ,NULL);
                    return 0;
                }
                OPCount_Rem++;
            }else{
                Index = MyRandom_GetInt2(Random,0,TestItemProvider_GetCount(ActiveInserts) - 1);
                Insert = (void**)TestItemProvider_Get(ActiveInserts,Index);

                #ifdef TESTENVIRONMENT_SHOWALL
                if(OpType == 2){
                    printf("[INFO] Operation %i: \"PriorityQueueMMA_RemoveItemSource\" (%i)\n",(i + 1),*((int*)(Insert[2])));
                }else{
                    printf("[INFO] Operation %i: \"PriorityQueueMMA_RemoveItemSource\" (INV)\n",(i + 1));
                }
                #endif // TESTENVIRONMENT_SHOWALL

                if(OpType == 2){
                    OpRes = PriorityQueueMMA_RemoveItemSource(PQA,Insert[1],NULL);
                }else{
                    OpRes = PriorityQueueMMA_RemoveItemSource(PQA,Insert[0],NULL);
                }
                TestResults_SetFromPQ1(&R1,PQ,OpRes);
                TestResults_IsDispItemNULL = 1;
                TestResults_DispItem = -1;

                if(OpType == 2){
                    OpRes = TestPQAFSim_RemoveSource(Sim,Insert[0],&R2);
                }else{
                    OpRes = TestPQAFSim_RemoveSource(Sim,Insert[1],&R2);
                }
                TestResults_IsDispItemNULL = 1;
                TestResults_DispItem = -1;
                if(!TestResults_Equal(&R1,&R2)){
                    printf("[ERROR] Operation %i, \"PriorityQueueMMA_RemoveItemSource\" indicates an error!\n",(i + 1));
                    if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                        printf("        Expected Results:\n");
                        printf("        %s\n",expectedRes);
                        printf("        Actual Results:\n");
                        printf("        %s\n",actualRes);
                        printf("\n");
                        free((void*)actualRes);
                        actualRes = TestResults_ToString(&R1);
                        printf("        Actual Results (Complete):\n");
                        printf("        %s\n",actualRes);
                        printf("\n");
                        TestPQAFSim_Print(Sim);
                        printf("\n");
                        TestEnvironment_BaseTest_PriorityQueueMMAF_Print(PQAF);
                    }
                    MyRandom_Dispose(Random);
                    TestItemProvider_Dispose(ItemP);
                    TestItemProvider_Dispose(EmptyInserts);
                    TestItemProvider_Dispose(ActiveInserts);
                    TestPQAFSim_Dispose(Sim);
                    PriorityQueueMM_Dispose(PQ,NULL);
                    return 0;
                }
                if(OpRes == -1){
                    printf("[ERROR] Operation %i, \"PriorityQueueMMA_RemoveItemSource\" caused an unexpected exception!\n",(i + 1));
                    MyRandom_Dispose(Random);
                    TestItemProvider_Dispose(ItemP);
                    TestItemProvider_Dispose(EmptyInserts);
                    TestItemProvider_Dispose(ActiveInserts);
                    TestPQAFSim_Dispose(Sim);
                    PriorityQueueMM_Dispose(PQ,NULL);
                    return 0;
                }
                OPCount_RemS++;
            }
            if(OpRes == 1){
                TestItemProvider_Add(ItemP,Insert[2]);
                TestItemProvider_Add(EmptyInserts,((void*)Insert));
                TestItemProvider_Remove(ActiveInserts,Index);
            }
        }else if(OpType == 1){      //Insert Item:
            Index = MyRandom_GetInt2(Random,0,TestItemProvider_GetCount(ItemP) - 1);
            Item = TestItemProvider_Get(ItemP,Index);
            Insert = (void**)TestItemProvider_Get(EmptyInserts,TestItemProvider_GetCount(EmptyInserts) - 1);
            Insert[2] = Item;

            #ifdef TESTENVIRONMENT_SHOWALL
            printf("[INFO] Operation %i: \"PriorityQueueMMA_GetInsertedItem(%i)\"\n",(i + 1),*((int*)Item));
            #endif // TESTENVIRONMENT_SHOWALL

            Insert[1] = (void*)PriorityQueueMMA_GetInsertedItem(PQA,Item,NULL);
            TestResults_SetFromPQ2(&R1,PQ,PriorityQueueMMA_GetItemOfItem(PQA,Insert[1],NULL));
            TestResults_IsDispItemNULL = 1;
            TestResults_DispItem = -1;

            Insert[0] = (void*)TestPQAFSim_GetInsertedItem(Sim,Item,&R2);
            TestResults_IsDispItemNULL = 1;
            TestResults_DispItem = -1;
            if(!TestResults_Equal(&R1,&R2)){
                printf("[ERROR] Operation %i, \"PriorityQueueMMA_GetInsertedItem(%i)\" indicates an error!\n",(i + 1),*((int*)Item));
                if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                    printf("        Expected Results:\n");
                    printf("        %s\n",expectedRes);
                    printf("        Actual Results:\n");
                    printf("        %s\n",actualRes);
                    printf("\n");
                    free((void*)actualRes);
                    actualRes = TestResults_ToString(&R1);
                    printf("        Actual Results (Complete):\n");
                    printf("        %s\n",actualRes);
                    printf("\n");
                    TestPQAFSim_Print(Sim);
                    printf("\n");
                    TestEnvironment_BaseTest_PriorityQueueMMAF_Print(PQAF);
                }
                MyRandom_Dispose(Random);
                TestItemProvider_Dispose(ItemP);
                TestItemProvider_Dispose(EmptyInserts);
                TestItemProvider_Dispose(ActiveInserts);
                TestPQAFSim_Dispose(Sim);
                PriorityQueueMM_Dispose(PQ,NULL);
                return 0;
            }
            if(Insert[0] != NULL){
                TestItemProvider_Remove(ItemP,Index);
                TestItemProvider_Remove(EmptyInserts,TestItemProvider_GetCount(EmptyInserts) - 1);
                TestItemProvider_Add(ActiveInserts,((void*)(&(Insert[0]))));
            }
            /*
            if(Insert[0] == NULL){
                printf("[ERROR] Operation %i, \"PriorityQueueMMA_GetInsertedItem(%i)\" caused an unexpected exception!\n",(i + 1),*((int*)Item));
                MyRandom_Dispose(Random);
                TestItemProvider_Dispose(ItemP);
                TestItemProvider_Dispose(EmptyInserts);
                TestItemProvider_Dispose(ActiveInserts);
                TestPQAFSim_Dispose(Sim);
                PriorityQueueMM_Dispose(PQ,NULL);
                return 0;
            }
            */
            OPCount_Insert++;
        }else if(OpType == 2){      //Contains Item:
            #ifndef TESTENVIRONMENT_VALIDCALLS
            OpType = MyRandom_GetInt2(Random,0,1);
            #else // TESTENVIRONMENT_VALIDCALLS
            OpType = 0;
            #endif // TESTENVIRONMENT_VALIDCALLS
            Index = MyRandom_GetInt2(Random,0,TestItemProvider_GetCount(ActiveInserts) - 1);
            Insert = (void**)TestItemProvider_Get(ActiveInserts,Index);

            #ifdef TESTENVIRONMENT_SHOWALL
            if(OpType == 0){
                printf("[INFO] Operation %i: \"PriorityQueueMMA_ContainsItem\" (%i)\n",(i + 1),*((int*)(Insert[2])));
            }else{
                printf("[INFO] Operation %i: \"PriorityQueueMMA_ContainsItem\" (INV)\n",(i + 1));
            }
            #endif // TESTENVIRONMENT_SHOWALL

            if(OpType == 0){
                OpRes = PriorityQueueMMA_ContainsItem(PQA,Insert[1],NULL);
            }else{
                OpRes = PriorityQueueMMA_ContainsItem(PQA,Insert[0],NULL);
            }
            TestResults_SetFromPQ1(&R1,PQ,OpRes);
            TestResults_IsDispItemNULL = 1;
            TestResults_DispItem = -1;

            if(OpType == 0){
                OpRes = TestPQAFSim_ContainsItem(Sim,Insert[0],&R2);
            }else{
                OpRes = TestPQAFSim_ContainsItem(Sim,Insert[1],&R2);
            }
            TestResults_IsDispItemNULL = 1;
            TestResults_DispItem = -1;
            if(!TestResults_Equal(&R1,&R2)){
                printf("[ERROR] Operation %i, \"PriorityQueueMMA_ContainsItem\" indicates an error!\n",(i + 1));
                if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                    printf("        Expected Results:\n");
                    printf("        %s\n",expectedRes);
                    printf("        Actual Results:\n");
                    printf("        %s\n",actualRes);
                    printf("\n");
                    free((void*)actualRes);
                    actualRes = TestResults_ToString(&R1);
                    printf("        Actual Results (Complete):\n");
                    printf("        %s\n",actualRes);
                    printf("\n");
                    TestPQAFSim_Print(Sim);
                    printf("\n");
                    TestEnvironment_BaseTest_PriorityQueueMMAF_Print(PQAF);
                }
                MyRandom_Dispose(Random);
                TestItemProvider_Dispose(ItemP);
                TestItemProvider_Dispose(EmptyInserts);
                TestItemProvider_Dispose(ActiveInserts);
                TestPQAFSim_Dispose(Sim);
                PriorityQueueMM_Dispose(PQ,NULL);
                return 0;
            }
            if(OpRes == -1){
                printf("[ERROR] Operation %i, \"PriorityQueueMMA_ContainsItem\" caused an unexpected exception!\n",(i + 1));
                MyRandom_Dispose(Random);
                TestItemProvider_Dispose(ItemP);
                TestItemProvider_Dispose(EmptyInserts);
                TestItemProvider_Dispose(ActiveInserts);
                TestPQAFSim_Dispose(Sim);
                PriorityQueueMM_Dispose(PQ,NULL);
                return 0;
            }
            OPCount_Contains++;
        }else if(OpType == 3){      //Set Item:
            #ifndef TESTENVIRONMENT_VALIDCALLS
            OpType = MyRandom_GetInt2(Random,0,1);
            #else // TESTENVIRONMENT_VALIDCALLS
            OpType = 0;
            #endif // TESTENVIRONMENT_VALIDCALLS
            Index = MyRandom_GetInt2(Random,0,TestItemProvider_GetCount(ActiveInserts) - 1);
            Insert = (void**)TestItemProvider_Get(ActiveInserts,Index);
            Index = MyRandom_GetInt2(Random,0,TestItemProvider_GetCount(ItemP) - 1);
            Item = TestItemProvider_Get(ItemP,Index);

            #ifdef TESTENVIRONMENT_SHOWALL
            if(OpType == 0){
                printf("[INFO] Operation %i: \"PriorityQueueMMA_SetItemOfItem\" (Old:%i New:%i)\n",(i + 1),*((int*)(Insert[2])),*((int*)Item));
            }else{
                printf("[INFO] Operation %i: \"PriorityQueueMMA_SetItemOfItem\" (Old:INV New:%i)\n",(i + 1),*((int*)Item));
            }
            #endif // TESTENVIRONMENT_SHOWALL

            if(OpType == 0){
                OpRes = PriorityQueueMMA_SetItemOfItem(PQA,Insert[1],Item,NULL);
            }else{
                OpRes = PriorityQueueMMA_SetItemOfItem(PQA,Insert[0],Item,NULL);
            }
            TestResults_SetFromPQ1(&R1,PQ,OpRes);
            TestResults_IsDispItemNULL = 1;
            TestResults_DispItem = -1;

            if(OpType == 0){
                OpRes = TestPQAFSim_SetItemOfItem(Sim,Insert[0],Item,&R2);
            }else{
                OpRes = TestPQAFSim_SetItemOfItem(Sim,Insert[1],Item,&R2);
            }
            TestResults_IsDispItemNULL = 1;
            TestResults_DispItem = -1;
            if(!TestResults_Equal(&R1,&R2)){
                printf("[ERROR] Operation %i, \"PriorityQueueMMA_SetItemOfItem\" indicates an error!\n",(i + 1));
                if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                    printf("        Expected Results:\n");
                    printf("        %s\n",expectedRes);
                    printf("        Actual Results:\n");
                    printf("        %s\n",actualRes);
                    printf("\n");
                    free((void*)actualRes);
                    actualRes = TestResults_ToString(&R1);
                    printf("        Actual Results (Complete):\n");
                    printf("        %s\n",actualRes);
                    printf("\n");
                    TestPQAFSim_Print(Sim);
                    printf("\n");
                    TestEnvironment_BaseTest_PriorityQueueMMAF_Print(PQAF);
                }
                MyRandom_Dispose(Random);
                TestItemProvider_Dispose(ItemP);
                TestItemProvider_Dispose(EmptyInserts);
                TestItemProvider_Dispose(ActiveInserts);
                TestPQAFSim_Dispose(Sim);
                PriorityQueueMM_Dispose(PQ,NULL);
                return 0;
            }
            if(OpRes == -1){
                printf("[ERROR] Operation %i, \"PriorityQueueMMA_SetItemOfItem\" caused an unexpected exception!\n",(i + 1));
                MyRandom_Dispose(Random);
                TestItemProvider_Dispose(ItemP);
                TestItemProvider_Dispose(EmptyInserts);
                TestItemProvider_Dispose(ActiveInserts);
                TestPQAFSim_Dispose(Sim);
                PriorityQueueMM_Dispose(PQ,NULL);
                return 0;
            }
            if(OpRes == 1){
                TestItemProvider_Remove(ItemP,Index);
                TestItemProvider_Add(ItemP,Insert[2]);
                Insert[2] = Item;
            }
            OPCount_Set++;
        }else{                      //Update Item:
            #ifndef TESTENVIRONMENT_VALIDCALLS
            OpType = MyRandom_GetInt2(Random,0,1);
            #else // TESTENVIRONMENT_VALIDCALLS
            OpType = 0;
            #endif // TESTENVIRONMENT_VALIDCALLS
            Index = MyRandom_GetInt2(Random,0,TestItemProvider_GetCount(ActiveInserts) - 1);
            Insert = (void**)TestItemProvider_Get(ActiveInserts,Index);
            Index = MyRandom_GetInt2(Random,0,TestItemProvider_GetCount(ItemP) - 1);
            Item = TestItemProvider_Get(ItemP,Index);

            #ifdef TESTENVIRONMENT_SHOWALL
            if(OpType == 0){
                printf("[INFO] Operation %i: \"PriorityQueueMMA_UpdateItem\" (Old:%i New:%i)\n",(i + 1),*((int*)(Insert[2])),*((int*)Item));
            }else{
                printf("[INFO] Operation %i: \"PriorityQueueMMA_UpdateItem\" (Old:INV New:%i)\n",(i + 1),*((int*)Item));
            }
            #endif // TESTENVIRONMENT_SHOWALL

            if(OpType == 0){
                //printf("\n");
                //TestEnvironment_BaseTest_PriorityQueueMMAF_Print(PQAF);

                //Temporary Use of "OpType" for swapping:
                OpType = *((int*)(Insert[2]));
                *((int*)(Insert[2])) = *((int*)Item);
                *((int*)Item) = OpType;OpType = 0;

                OpRes = PriorityQueueMMA_UpdateItem(PQA,Insert[1],NULL);
            }else{
                OpRes = PriorityQueueMMA_UpdateItem(PQA,Insert[0],NULL);
            }
            TestResults_SetFromPQ1(&R1,PQ,OpRes);
            TestResults_IsDispItemNULL = 1;
            TestResults_DispItem = -1;

            if(OpType == 0){
                OpRes = TestPQAFSim_UpdateItem(Sim,Insert[0],&R2);
            }else{
                OpRes = TestPQAFSim_UpdateItem(Sim,Insert[1],&R2);
            }
            TestResults_IsDispItemNULL = 1;
            TestResults_DispItem = -1;
            if(!TestResults_Equal(&R1,&R2)){
                printf("[ERROR] Operation %i, \"PriorityQueueMMA_UpdateItem\" indicates an error!\n",(i + 1));
                if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                    printf("        Expected Results:\n");
                    printf("        %s\n",expectedRes);
                    printf("        Actual Results:\n");
                    printf("        %s\n",actualRes);
                    printf("\n");
                    free((void*)actualRes);
                    actualRes = TestResults_ToString(&R1);
                    printf("        Actual Results (Complete):\n");
                    printf("        %s\n",actualRes);
                    printf("\n");
                    TestPQAFSim_Print(Sim);
                    printf("\n");
                    TestEnvironment_BaseTest_PriorityQueueMMAF_Print(PQAF);
                }
                MyRandom_Dispose(Random);
                TestItemProvider_Dispose(ItemP);
                TestItemProvider_Dispose(EmptyInserts);
                TestItemProvider_Dispose(ActiveInserts);
                TestPQAFSim_Dispose(Sim);
                PriorityQueueMM_Dispose(PQ,NULL);
                return 0;
            }
            if(OpRes == -1){
                printf("[ERROR] Operation %i, \"PriorityQueueMMA_UpdateItem\" caused an unexpected exception!\n",(i + 1));
                MyRandom_Dispose(Random);
                TestItemProvider_Dispose(ItemP);
                TestItemProvider_Dispose(EmptyInserts);
                TestItemProvider_Dispose(ActiveInserts);
                TestPQAFSim_Dispose(Sim);
                PriorityQueueMM_Dispose(PQ,NULL);
                return 0;
            }
            OPCount_Update++;
            //printf("\n");
            //TestEnvironment_BaseTest_PriorityQueueMMAF_Print(PQAF);
        }

        time(&CurTime);
        if(difftime(CurTime,LastDispTime) >= 1.0){
            time(&LastDispTime);
            #ifndef TESTENVIRONMENT_ENDLESS
            printf("[INFO] %i Operations of %i done! (%i%%)\n",(i + 1),(TestOps),(((i + 1) * 100) / TestOps));
            #else // TESTENVIRONMENT_ENDLESS
            printf("[INFO] %i Operations done!\n",(i + 1));
            #endif // TESTENVIRONMENT_ENDLESS
        }
    }

    printf("\n");
    printf("[INFO] All Operations done!\n");
    printf("       Inserts : %i\n",OPCount_Insert);
    printf("       Removes : %i\n",OPCount_Rem);
    printf("       RemovesS: %i\n",OPCount_RemS);
    printf("       Contains: %i\n",OPCount_Contains);
    printf("       Sets    : %i\n",OPCount_Set);
    printf("       Updates : %i\n",OPCount_Update);
    return 1;
}

int TestEnvironment_AdvTest_PriorityQueueMMAD(int TestOps){
    MyRandom* Random = MyRandom_Create();

    #ifndef TESTENVIRONMENT_ENDLESS
    int i;
    #else // TESTENVIRONMENT_ENDLESS
    unsigned int i;
    #endif // TESTENVIRONMENT_ENDLESS
    int Items[256];
    void** Inserts = (void**)malloc(sizeof(void*) * 768);
    void** Insert;

    TestItemProvider* ItemP = TestItemProvider_Create(256);
    if(ItemP == NULL){
        printf("        Function \"%s\" failed!\n",__FUNCTION__);
        MyRandom_Dispose(Random);
        return 0;
    }

    TestItemProvider* EmptyInserts = TestItemProvider_Create(256);
    if(EmptyInserts == NULL){
        printf("        Function \"%s\" failed!\n",__FUNCTION__);
        MyRandom_Dispose(Random);
        TestItemProvider_Dispose(ItemP);
        return 0;
    }

    TestItemProvider* ActiveInserts = TestItemProvider_Create(256);
    if(ActiveInserts == NULL){
        printf("        Function \"%s\" failed!\n",__FUNCTION__);
        MyRandom_Dispose(Random);
        TestItemProvider_Dispose(ItemP);
        TestItemProvider_Dispose(EmptyInserts);
        return 0;
    }

    for(i = 0;i < 256;i++){
        Items[i] = i + 1;
        TestItemProvider_Add(ItemP,(void*)(&(Items[i])));
        TestItemProvider_Add(EmptyInserts,((void*)(&(Inserts[(i * 3)]))));
    }

    TestResults R1;     //Actual    Results
    TestResults R2;     //Expected  Results

    TestPQADSim* Sim = TestPQADSim_Create(TestEnvironment_Compare,TestEnvironment_DisposeItem,&R2);

    void* MemPtr = malloc(sizeof(PriorityQueueMMAD));
    if(MemPtr == NULL){
        printf("[ERROR] Function \"%s\" failed!\n",__FUNCTION__);
        printf("        \"MemPtr\" could not be allocated!\n");
        MyRandom_Dispose(Random);
        TestItemProvider_Dispose(ItemP);
        TestPQSDSim_Dispose(Sim);
        return 0;
    }

    PriorityQueueMMAD* PQAD = PriorityQueueMMAD_Create(MemPtr,sizeof(PriorityQueueMMAD),TestEnvironment_Compare,TestEnvironment_DisposeItem,NULL,NULL,NULL);
    PriorityQueueMMA* PQA = PriorityQueueMMAD_Get_PriorityQueueMMA(PQAD,NULL);
    PriorityQueueMM* PQ = PriorityQueueMMAD_Get_PriorityQueueMM(PQAD,NULL);

    TestResults_SetFromPQ1(&R1,PQ,0);

    TestResults_IsDispItemNULL = 1;
    TestResults_DispItem = -1;

    char* expectedRes;
    char* actualRes;

    if(!TestResults_Equal(&R1,&R2)){
        printf("[ERROR] Operation \"PriorityQueueMMAD_Create\" indicates an error!\n");
        if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
            printf("        Expected Results:\n");
            printf("        %s\n",expectedRes);
            printf("        Actual Results:\n");
            printf("        %s\n",actualRes);
        }
        MyRandom_Dispose(Random);
        TestItemProvider_Dispose(ItemP);
        TestItemProvider_Dispose(EmptyInserts);
        TestItemProvider_Dispose(ActiveInserts);
        TestPQADSim_Dispose(Sim);
        return 0;
    }

    #define TESTENVIRONMENT_ADVTEST_SPECTEST

    int OpType;
    int Index;
    void* Item;
    int OpRes;
    int OPCount_Insert = 0;
    int OPCount_Rem = 0;
    int OPCount_RemS = 0;
    int OPCount_Contains = 0;
    int OPCount_Set = 0;
    int OPCount_Update = 0;
    #ifdef TESTENVIRONMENT_ADVTEST_SPECTEST
    int Indizes[6];
    Indizes[0] = 27;
    Indizes[1] = 248;
    Indizes[2] = 208;
    Indizes[3] = 148;
    Indizes[4] = 242;
    Indizes[5] = 143;
    printf("[INFO] Additional Test-Case:\n");
    for(i = 0;i < 6;i++){
        #ifdef TESTENVIRONMENT_SHOWTRE
        TestEnvironment_BaseTest_PriorityQueueMMAD_Print(PQAD);
        #endif // TESTENVIRONMENT_SHOWTRE
        Index = Indizes[i];
        Item = TestItemProvider_Get(ItemP,Index); //Should contain Value "10"
        Insert = (void**)TestItemProvider_Get(EmptyInserts,TestItemProvider_GetCount(EmptyInserts) - 1);
        Insert[2] = Item;

        #ifdef TESTENVIRONMENT_SHOWALL
        printf("[INFO] Operation %i: \"PriorityQueueMMA_GetInsertedItem(%i)\"\n",(i + 1),*((int*)Item));
        #endif // TESTENVIRONMENT_SHOWALL

        Insert[1] = (void*)PriorityQueueMMA_GetInsertedItem(PQA,Item,NULL);
        TestResults_SetFromPQ2(&R1,PQ,PriorityQueueMMA_GetItemOfItem(PQA,Insert[1],NULL));
        TestResults_IsDispItemNULL = 1;
        TestResults_DispItem = -1;

        Insert[0] = (void*)TestPQADSim_GetInsertedItem(Sim,Item,&R2);
        TestResults_IsDispItemNULL = 1;
        TestResults_DispItem = -1;
        if(!TestResults_Equal(&R1,&R2)){
            printf("[ERROR] Operation %i, \"PriorityQueueMMA_GetInsertedItem(%i)\" indicates an error!\n",(i + 1),*((int*)Item));
            if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                printf("        Expected Results:\n");
                printf("        %s\n",expectedRes);
                printf("        Actual Results:\n");
                printf("        %s\n",actualRes);
                printf("\n");
                free((void*)actualRes);
                actualRes = TestResults_ToString(&R1);
                printf("        Actual Results (Complete):\n");
                printf("        %s\n",actualRes);
                printf("\n");
                TestPQAFSim_Print(Sim);
                printf("\n");
                TestEnvironment_BaseTest_PriorityQueueMMAD_Print(PQAD);
            }
            MyRandom_Dispose(Random);
            TestItemProvider_Dispose(ItemP);
            TestItemProvider_Dispose(EmptyInserts);
            TestItemProvider_Dispose(ActiveInserts);
            TestPQADSim_Dispose(Sim);
            PriorityQueueMM_Dispose(PQ,NULL);
            return 0;
        }
        if(Insert[0] != NULL){
            TestItemProvider_Remove(ItemP,Index);
            TestItemProvider_Remove(EmptyInserts,TestItemProvider_GetCount(EmptyInserts) - 1);
            TestItemProvider_Add(ActiveInserts,((void*)(&(Insert[0]))));
            #ifdef TESTENVIRONMENT_SHOWTRE
            TestEnvironment_BaseTest_PriorityQueueMMAD_Print(PQAD);
            #endif // TESTENVIRONMENT_SHOWTRE
        }
        /*
        if(Insert[0] == NULL){
            printf("[ERROR] Operation %i, \"PriorityQueueMMA_GetInsertedItem(%i)\" caused an unexpected exception!\n",(i + 1),*((int*)Item));
            MyRandom_Dispose(Random);
            TestItemProvider_Dispose(ItemP);
            TestItemProvider_Dispose(EmptyInserts);
            TestItemProvider_Dispose(ActiveInserts);
            TestPQADSim_Dispose(Sim);
            PriorityQueueMM_Dispose(PQ,NULL);
            return 0;
        }
        */
        OPCount_Insert++;
    }
    #endif // TESTENVIRONMENT_ADVTEST_SPECTEST

    #ifndef TESTENVIRONMENT_ENDLESS
    printf("[INFO] Starting %i Operations:\n",TestOps);
    #else // TESTENVIRONMENT_ENDLESS
    printf("[INFO] Starting \"infinite\" Operations:\n");
    #endif // TESTENVIRONMENT_ENDLESS
    time_t LastDispTime;
    time_t CurTime;
    time(&LastDispTime);
    #ifndef TESTENVIRONMENT_ENDLESS
    for(i = 0;i < TestOps;i++){
    #else // TESTENVIRONMENT_ENDLESS
    for(i = 0;i >= 0;i++){
    #endif // TESTENVIRONMENT_ENDLESS
        #ifdef TESTENVIRONMENT_SHOWTRE
        TestEnvironment_BaseTest_PriorityQueueMMAD_Print(PQAD);
        #endif // TESTENVIRONMENT_SHOWTRE
        if(TestItemProvider_GetCount(ItemP) > 0){
            OpType = MyRandom_GetInt2(Random,0,4);
        }else{OpType = 0;}
        if((TestItemProvider_GetCount(ActiveInserts) == 0)&&(OpType != 1)){OpType = 1;}
        //if(i < 94){OpType = 1;}
        //if(TestItemProvider_GetCount(ActiveInserts) >= 94){OpType = 0;}
        //if(TestItemProvider_GetCount(ActiveInserts) < 90){OpType = 1;}
        if(OpType == 0){    //Remove item:
            #ifndef TESTENVIRONMENT_VALIDCALLS
            OpType = MyRandom_GetInt2(Random,0,3);
            #else // TESTENVIRONMENT_VALIDCALLS
            OpType = MyRandom_GetInt2(Random,0,1) * 2;
            #endif // TESTENVIRONMENT_VALIDCALLS
            if(OpType < 2){
                Index = MyRandom_GetInt2(Random,0,TestItemProvider_GetCount(ActiveInserts) - 1);
                Insert = (void**)TestItemProvider_Get(ActiveInserts,Index);

                #ifdef TESTENVIRONMENT_SHOWALL
                if(OpType == 0){
                    printf("[INFO] Operation %i: \"PriorityQueueMMA_RemoveItem\" (%i)\n",(i + 1),*((int*)(Insert[2])));
                }else{
                    printf("[INFO] Operation %i: \"PriorityQueueMMA_RemoveItem\" (INV)\n",(i + 1));
                }
                #endif // TESTENVIRONMENT_SHOWALL

                if(OpType == 0){
                    OpRes = PriorityQueueMMA_RemoveItem(PQA,Insert[1],NULL);
                }else{
                    OpRes = PriorityQueueMMA_RemoveItem(PQA,Insert[0],NULL);
                }
                TestResults_SetFromPQ1(&R1,PQ,OpRes);
                TestResults_IsDispItemNULL = 1;
                TestResults_DispItem = -1;

                if(OpType == 0){
                    OpRes = TestPQADSim_Remove(Sim,Insert[0],&R2);
                }else{
                    OpRes = TestPQADSim_Remove(Sim,Insert[1],&R2);
                }
                TestResults_IsDispItemNULL = 1;
                TestResults_DispItem = -1;
                if(!TestResults_Equal(&R1,&R2)){
                    printf("[ERROR] Operation %i, \"PriorityQueueMMA_RemoveItem\" indicates an error!\n",(i + 1));
                    if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                        printf("        Expected Results:\n");
                        printf("        %s\n",expectedRes);
                        printf("        Actual Results:\n");
                        printf("        %s\n",actualRes);
                        printf("\n");
                        free((void*)actualRes);
                        actualRes = TestResults_ToString(&R1);
                        printf("        Actual Results (Complete):\n");
                        printf("        %s\n",actualRes);
                        printf("\n");
                        TestPQADSim_Print(Sim);
                        printf("\n");
                        TestEnvironment_BaseTest_PriorityQueueMMAD_Print(PQAD);
                    }
                    MyRandom_Dispose(Random);
                    TestItemProvider_Dispose(ItemP);
                    TestItemProvider_Dispose(EmptyInserts);
                    TestItemProvider_Dispose(ActiveInserts);
                    TestPQADSim_Dispose(Sim);
                    PriorityQueueMM_Dispose(PQ,NULL);
                    return 0;
                }
                if(OpRes == -1){
                    printf("[ERROR] Operation %i, \"PriorityQueueMMA_RemoveItem\" caused an unexpected exception!\n",(i + 1));
                    MyRandom_Dispose(Random);
                    TestItemProvider_Dispose(ItemP);
                    TestItemProvider_Dispose(EmptyInserts);
                    TestItemProvider_Dispose(ActiveInserts);
                    TestPQADSim_Dispose(Sim);
                    PriorityQueueMM_Dispose(PQ,NULL);
                    return 0;
                }
                OPCount_Rem++;
            }else{
                Index = MyRandom_GetInt2(Random,0,TestItemProvider_GetCount(ActiveInserts) - 1);
                Insert = (void**)TestItemProvider_Get(ActiveInserts,Index);

                #ifdef TESTENVIRONMENT_SHOWALL
                if(OpType == 2){
                    printf("[INFO] Operation %i: \"PriorityQueueMMA_RemoveItemSource\" (%i)\n",(i + 1),*((int*)(Insert[2])));
                }else{
                    printf("[INFO] Operation %i: \"PriorityQueueMMA_RemoveItemSource\" (INV)\n",(i + 1));
                }
                #endif // TESTENVIRONMENT_SHOWALL

                if(OpType == 2){
                    OpRes = PriorityQueueMMA_RemoveItemSource(PQA,Insert[1],NULL);
                }else{
                    OpRes = PriorityQueueMMA_RemoveItemSource(PQA,Insert[0],NULL);
                }
                TestResults_SetFromPQ1(&R1,PQ,OpRes);
                TestResults_IsDispItemNULL = 1;
                TestResults_DispItem = -1;

                if(OpType == 2){
                    OpRes = TestPQADSim_RemoveSource(Sim,Insert[0],&R2);
                }else{
                    OpRes = TestPQADSim_RemoveSource(Sim,Insert[1],&R2);
                }
                TestResults_IsDispItemNULL = 1;
                TestResults_DispItem = -1;
                if(!TestResults_Equal(&R1,&R2)){
                    printf("[ERROR] Operation %i, \"PriorityQueueMMA_RemoveItemSource\" indicates an error!\n",(i + 1));
                    if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                        printf("        Expected Results:\n");
                        printf("        %s\n",expectedRes);
                        printf("        Actual Results:\n");
                        printf("        %s\n",actualRes);
                        printf("\n");
                        free((void*)actualRes);
                        actualRes = TestResults_ToString(&R1);
                        printf("        Actual Results (Complete):\n");
                        printf("        %s\n",actualRes);
                        printf("\n");
                        TestPQADSim_Print(Sim);
                        printf("\n");
                        TestEnvironment_BaseTest_PriorityQueueMMAD_Print(PQAD);
                    }
                    MyRandom_Dispose(Random);
                    TestItemProvider_Dispose(ItemP);
                    TestItemProvider_Dispose(EmptyInserts);
                    TestItemProvider_Dispose(ActiveInserts);
                    TestPQAFSim_Dispose(Sim);
                    PriorityQueueMM_Dispose(PQ,NULL);
                    return 0;
                }
                if(OpRes == -1){
                    printf("[ERROR] Operation %i, \"PriorityQueueMMA_RemoveItemSource\" caused an unexpected exception!\n",(i + 1));
                    MyRandom_Dispose(Random);
                    TestItemProvider_Dispose(ItemP);
                    TestItemProvider_Dispose(EmptyInserts);
                    TestItemProvider_Dispose(ActiveInserts);
                    TestPQADSim_Dispose(Sim);
                    PriorityQueueMM_Dispose(PQ,NULL);
                    return 0;
                }
                OPCount_RemS++;
            }
            if(OpRes == 1){
                TestItemProvider_Add(ItemP,Insert[2]);
                TestItemProvider_Add(EmptyInserts,((void*)Insert));
                TestItemProvider_Remove(ActiveInserts,Index);
            }
        }else if(OpType == 1){      //Insert Item:
            Index = MyRandom_GetInt2(Random,0,TestItemProvider_GetCount(ItemP) - 1);
            Item = TestItemProvider_Get(ItemP,Index);
            Insert = (void**)TestItemProvider_Get(EmptyInserts,TestItemProvider_GetCount(EmptyInserts) - 1);
            Insert[2] = Item;

            #ifdef TESTENVIRONMENT_SHOWALL
            printf("[INFO] Operation %i: \"PriorityQueueMMA_GetInsertedItem(%i)\"\n",(i + 1),*((int*)Item));
            #endif // TESTENVIRONMENT_SHOWALL

            Insert[1] = (void*)PriorityQueueMMA_GetInsertedItem(PQA,Item,NULL);
            TestResults_SetFromPQ2(&R1,PQ,PriorityQueueMMA_GetItemOfItem(PQA,Insert[1],NULL));
            TestResults_IsDispItemNULL = 1;
            TestResults_DispItem = -1;

            Insert[0] = (void*)TestPQADSim_GetInsertedItem(Sim,Item,&R2);
            TestResults_IsDispItemNULL = 1;
            TestResults_DispItem = -1;
            if(!TestResults_Equal(&R1,&R2)){
                printf("[ERROR] Operation %i, \"PriorityQueueMMA_GetInsertedItem(%i)\" indicates an error!\n",(i + 1),*((int*)Item));
                if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                    printf("        Expected Results:\n");
                    printf("        %s\n",expectedRes);
                    printf("        Actual Results:\n");
                    printf("        %s\n",actualRes);
                    printf("\n");
                    free((void*)actualRes);
                    actualRes = TestResults_ToString(&R1);
                    printf("        Actual Results (Complete):\n");
                    printf("        %s\n",actualRes);
                    printf("\n");
                    TestPQADSim_Print(Sim);
                    printf("\n");
                    TestEnvironment_BaseTest_PriorityQueueMMAD_Print(PQAD);
                }
                MyRandom_Dispose(Random);
                TestItemProvider_Dispose(ItemP);
                TestItemProvider_Dispose(EmptyInserts);
                TestItemProvider_Dispose(ActiveInserts);
                TestPQADSim_Dispose(Sim);
                PriorityQueueMM_Dispose(PQ,NULL);
                return 0;
            }
            if(Insert[0] != NULL){
                TestItemProvider_Remove(ItemP,Index);
                TestItemProvider_Remove(EmptyInserts,TestItemProvider_GetCount(EmptyInserts) - 1);
                TestItemProvider_Add(ActiveInserts,((void*)(&(Insert[0]))));
            }
            /*
            if(Insert[0] == NULL){
                printf("[ERROR] Operation %i, \"PriorityQueueMMA_GetInsertedItem(%i)\" caused an unexpected exception!\n",(i + 1),*((int*)Item));
                MyRandom_Dispose(Random);
                TestItemProvider_Dispose(ItemP);
                TestItemProvider_Dispose(EmptyInserts);
                TestItemProvider_Dispose(ActiveInserts);
                TestPQADSim_Dispose(Sim);
                PriorityQueueMM_Dispose(PQ,NULL);
                return 0;
            }
            */
            OPCount_Insert++;
        }else if(OpType == 2){      //Contains Item:
            #ifndef TESTENVIRONMENT_VALIDCALLS
            OpType = MyRandom_GetInt2(Random,0,1);
            #else // TESTENVIRONMENT_VALIDCALLS
            OpType = 0;
            #endif // TESTENVIRONMENT_VALIDCALLS
            Index = MyRandom_GetInt2(Random,0,TestItemProvider_GetCount(ActiveInserts) - 1);
            Insert = (void**)TestItemProvider_Get(ActiveInserts,Index);

            #ifdef TESTENVIRONMENT_SHOWALL
            if(OpType == 0){
                printf("[INFO] Operation %i: \"PriorityQueueMMA_ContainsItem\" (%i)\n",(i + 1),*((int*)(Insert[2])));
            }else{
                printf("[INFO] Operation %i: \"PriorityQueueMMA_ContainsItem\" (INV)\n",(i + 1));
            }
            #endif // TESTENVIRONMENT_SHOWALL

            if(OpType == 0){
                OpRes = PriorityQueueMMA_ContainsItem(PQA,Insert[1],NULL);
            }else{
                OpRes = PriorityQueueMMA_ContainsItem(PQA,Insert[0],NULL);
            }
            TestResults_SetFromPQ1(&R1,PQ,OpRes);
            TestResults_IsDispItemNULL = 1;
            TestResults_DispItem = -1;

            if(OpType == 0){
                OpRes = TestPQADSim_ContainsItem(Sim,Insert[0],&R2);
            }else{
                OpRes = TestPQADSim_ContainsItem(Sim,Insert[1],&R2);
            }
            TestResults_IsDispItemNULL = 1;
            TestResults_DispItem = -1;
            if(!TestResults_Equal(&R1,&R2)){
                printf("[ERROR] Operation %i, \"PriorityQueueMMA_ContainsItem\" indicates an error!\n",(i + 1));
                if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                    printf("        Expected Results:\n");
                    printf("        %s\n",expectedRes);
                    printf("        Actual Results:\n");
                    printf("        %s\n",actualRes);
                    printf("\n");
                    free((void*)actualRes);
                    actualRes = TestResults_ToString(&R1);
                    printf("        Actual Results (Complete):\n");
                    printf("        %s\n",actualRes);
                    printf("\n");
                    TestPQADSim_Print(Sim);
                    printf("\n");
                    TestEnvironment_BaseTest_PriorityQueueMMAD_Print(PQAD);
                }
                MyRandom_Dispose(Random);
                TestItemProvider_Dispose(ItemP);
                TestItemProvider_Dispose(EmptyInserts);
                TestItemProvider_Dispose(ActiveInserts);
                TestPQADSim_Dispose(Sim);
                PriorityQueueMM_Dispose(PQ,NULL);
                return 0;
            }
            if(OpRes == -1){
                printf("[ERROR] Operation %i, \"PriorityQueueMMA_ContainsItem\" caused an unexpected exception!\n",(i + 1));
                MyRandom_Dispose(Random);
                TestItemProvider_Dispose(ItemP);
                TestItemProvider_Dispose(EmptyInserts);
                TestItemProvider_Dispose(ActiveInserts);
                TestPQADSim_Dispose(Sim);
                PriorityQueueMM_Dispose(PQ,NULL);
                return 0;
            }
            OPCount_Contains++;
        }else if(OpType == 3){      //Set Item:
            #ifndef TESTENVIRONMENT_VALIDCALLS
            OpType = MyRandom_GetInt2(Random,0,1);
            #else // TESTENVIRONMENT_VALIDCALLS
            OpType = 0;
            #endif // TESTENVIRONMENT_VALIDCALLS
            Index = MyRandom_GetInt2(Random,0,TestItemProvider_GetCount(ActiveInserts) - 1);
            Insert = (void**)TestItemProvider_Get(ActiveInserts,Index);
            Index = MyRandom_GetInt2(Random,0,TestItemProvider_GetCount(ItemP) - 1);
            Item = TestItemProvider_Get(ItemP,Index);

            #ifdef TESTENVIRONMENT_SHOWALL
            if(OpType == 0){
                printf("[INFO] Operation %i: \"PriorityQueueMMA_SetItemOfItem\" (Old:%i New:%i)\n",(i + 1),*((int*)(Insert[2])),*((int*)Item));
            }else{
                printf("[INFO] Operation %i: \"PriorityQueueMMA_SetItemOfItem\" (Old:INV New:%i)\n",(i + 1),*((int*)Item));
            }
            #endif // TESTENVIRONMENT_SHOWALL

            if(OpType == 0){
                OpRes = PriorityQueueMMA_SetItemOfItem(PQA,Insert[1],Item,NULL);
            }else{
                OpRes = PriorityQueueMMA_SetItemOfItem(PQA,Insert[0],Item,NULL);
            }
            TestResults_SetFromPQ1(&R1,PQ,OpRes);
            TestResults_IsDispItemNULL = 1;
            TestResults_DispItem = -1;

            if(OpType == 0){
                OpRes = TestPQADSim_SetItemOfItem(Sim,Insert[0],Item,&R2);
            }else{
                OpRes = TestPQADSim_SetItemOfItem(Sim,Insert[1],Item,&R2);
            }
            TestResults_IsDispItemNULL = 1;
            TestResults_DispItem = -1;
            if(!TestResults_Equal(&R1,&R2)){
                printf("[ERROR] Operation %i, \"PriorityQueueMMA_SetItemOfItem\" indicates an error!\n",(i + 1));
                if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                    printf("        Expected Results:\n");
                    printf("        %s\n",expectedRes);
                    printf("        Actual Results:\n");
                    printf("        %s\n",actualRes);
                    printf("\n");
                    free((void*)actualRes);
                    actualRes = TestResults_ToString(&R1);
                    printf("        Actual Results (Complete):\n");
                    printf("        %s\n",actualRes);
                    printf("\n");
                    TestPQADSim_Print(Sim);
                    printf("\n");
                    TestEnvironment_BaseTest_PriorityQueueMMAD_Print(PQAD);
                }
                MyRandom_Dispose(Random);
                TestItemProvider_Dispose(ItemP);
                TestItemProvider_Dispose(EmptyInserts);
                TestItemProvider_Dispose(ActiveInserts);
                TestPQADSim_Dispose(Sim);
                PriorityQueueMM_Dispose(PQ,NULL);
                return 0;
            }
            if(OpRes == -1){
                printf("[ERROR] Operation %i, \"PriorityQueueMMA_SetItemOfItem\" caused an unexpected exception!\n",(i + 1));
                MyRandom_Dispose(Random);
                TestItemProvider_Dispose(ItemP);
                TestItemProvider_Dispose(EmptyInserts);
                TestItemProvider_Dispose(ActiveInserts);
                TestPQADSim_Dispose(Sim);
                PriorityQueueMM_Dispose(PQ,NULL);
                return 0;
            }
            if(OpRes == 1){
                TestItemProvider_Remove(ItemP,Index);
                TestItemProvider_Add(ItemP,Insert[2]);
                Insert[2] = Item;
            }
            OPCount_Set++;
        }else{                      //Update Item:
            #ifndef TESTENVIRONMENT_VALIDCALLS
            OpType = MyRandom_GetInt2(Random,0,1);
            #else // TESTENVIRONMENT_VALIDCALLS
            OpType = 0;
            #endif // TESTENVIRONMENT_VALIDCALLS
            Index = MyRandom_GetInt2(Random,0,TestItemProvider_GetCount(ActiveInserts) - 1);
            Insert = (void**)TestItemProvider_Get(ActiveInserts,Index);
            Index = MyRandom_GetInt2(Random,0,TestItemProvider_GetCount(ItemP) - 1);
            Item = TestItemProvider_Get(ItemP,Index);

            #ifdef TESTENVIRONMENT_SHOWALL
            if(OpType == 0){
                printf("[INFO] Operation %i: \"PriorityQueueMMA_UpdateItem\" (Old:%i New:%i)\n",(i + 1),*((int*)(Insert[2])),*((int*)Item));
            }else{
                printf("[INFO] Operation %i: \"PriorityQueueMMA_UpdateItem\" (Old:INV New:%i)\n",(i + 1),*((int*)Item));
            }
            #endif // TESTENVIRONMENT_SHOWALL

            if(OpType == 0){
                //printf("\n");
                //TestEnvironment_BaseTest_PriorityQueueMMAF_Print(PQAF);

                //Temporary Use of "OpType" for swapping:
                OpType = *((int*)(Insert[2]));
                *((int*)(Insert[2])) = *((int*)Item);
                *((int*)Item) = OpType;OpType = 0;

                OpRes = PriorityQueueMMA_UpdateItem(PQA,Insert[1],NULL);
            }else{
                OpRes = PriorityQueueMMA_UpdateItem(PQA,Insert[0],NULL);
            }
            TestResults_SetFromPQ1(&R1,PQ,OpRes);
            TestResults_IsDispItemNULL = 1;
            TestResults_DispItem = -1;

            if(OpType == 0){
                OpRes = TestPQADSim_UpdateItem(Sim,Insert[0],&R2);
            }else{
                OpRes = TestPQADSim_UpdateItem(Sim,Insert[1],&R2);
            }
            TestResults_IsDispItemNULL = 1;
            TestResults_DispItem = -1;
            if(!TestResults_Equal(&R1,&R2)){
                printf("[ERROR] Operation %i, \"PriorityQueueMMA_UpdateItem\" indicates an error!\n",(i + 1));
                if(TestResults_DiffToStrings(&R1,&R2,&actualRes,&expectedRes)){
                    printf("        Expected Results:\n");
                    printf("        %s\n",expectedRes);
                    printf("        Actual Results:\n");
                    printf("        %s\n",actualRes);
                    printf("\n");
                    free((void*)actualRes);
                    actualRes = TestResults_ToString(&R1);
                    printf("        Actual Results (Complete):\n");
                    printf("        %s\n",actualRes);
                    printf("\n");
                    TestPQADSim_Print(Sim);
                    printf("\n");
                    TestEnvironment_BaseTest_PriorityQueueMMAD_Print(PQAD);
                }
                MyRandom_Dispose(Random);
                TestItemProvider_Dispose(ItemP);
                TestItemProvider_Dispose(EmptyInserts);
                TestItemProvider_Dispose(ActiveInserts);
                TestPQADSim_Dispose(Sim);
                PriorityQueueMM_Dispose(PQ,NULL);
                return 0;
            }
            if(OpRes == -1){
                printf("[ERROR] Operation %i, \"PriorityQueueMMA_UpdateItem\" caused an unexpected exception!\n",(i + 1));
                MyRandom_Dispose(Random);
                TestItemProvider_Dispose(ItemP);
                TestItemProvider_Dispose(EmptyInserts);
                TestItemProvider_Dispose(ActiveInserts);
                TestPQADSim_Dispose(Sim);
                PriorityQueueMM_Dispose(PQ,NULL);
                return 0;
            }
            OPCount_Update++;
            //printf("\n");
            //TestEnvironment_BaseTest_PriorityQueueMMAF_Print(PQAF);
        }

        time(&CurTime);
        if(difftime(CurTime,LastDispTime) >= 1.0){
            time(&LastDispTime);
            #ifndef TESTENVIRONMENT_ENDLESS
            printf("[INFO] %i Operations of %i done! (%i%%)\n",(i + 1),(TestOps),(((i + 1) * 100) / TestOps));
            #else // TESTENVIRONMENT_ENDLESS
            printf("[INFO] %i Operations done!\n",(i + 1));
            #endif // TESTENVIRONMENT_ENDLESS
        }
    }

    printf("\n");
    printf("[INFO] All Operations done!\n");
    printf("       Inserts : %i\n",OPCount_Insert);
    printf("       Removes : %i\n",OPCount_Rem);
    printf("       RemovesS: %i\n",OPCount_RemS);
    printf("       Contains: %i\n",OPCount_Contains);
    printf("       Sets    : %i\n",OPCount_Set);
    printf("       Updates : %i\n",OPCount_Update);
    return 1;
}

