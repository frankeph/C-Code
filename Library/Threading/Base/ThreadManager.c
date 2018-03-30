#include "ThreadManager.h"

ThreadManager* ThreadingManager = NULL;

static ThreadManagerItemItem* ThreadManager_GetThreadItem(uint64_t ID);
static double ThreadManager_SimulateItem(uint64_t Alpha);
static ThreadManagerItem* ThreadManager_CreateItem(uint64_t Alpha);
static int ThreadManager_GetHash(uint64_t Alpha,uint64_t Beta,uint64_t ID);
static void ThreadManagerItem_Dispose(ThreadManagerItem* I);

int ThreadManager_Init(void){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if(ThreadingManager != NULL){return 1;}

    if(!ThreadBase_SerializeMutex_Lock()){return 0;}
    if(ThreadingManager != NULL){
        ThreadBase_SerializeMutex_Unlock();
        return 1;
    }

    ThreadManager* res = (ThreadManager*)malloc(sizeof(ThreadManager));
    if(res == NULL){
        ThreadBase_SerializeMutex_Unlock();
        return 0;
    }
    res->ThreadCount = 0;
    res->ThreadData = NULL;
    res->Prime = 2147483647;
    res->CurrentItem = 0;
    res->ItemArray = (ThreadManagerItem**)calloc(ThreadManagerItemCount,sizeof(ThreadManagerItem*));
    if(res->ItemArray == NULL){
        free((void*)res);
        ThreadBase_SerializeMutex_Unlock();
        return 0;
    }

    res->Random = MyRandom_Create();
    if(res->Random == NULL){
        free((void*)res->ItemArray);
        free((void*)res);
        ThreadBase_SerializeMutex_Unlock();
        return 0;
    }

    res->AccessMutex = BaseMutex_Create();
    if(res->AccessMutex == NULL){
        MyRandom_Dispose(res->Random);
        free((void*)res->ItemArray);
        free((void*)res);
        ThreadBase_SerializeMutex_Unlock();
        return 0;
    }
    ThreadingManager = res;
    ThreadBase_SerializeMutex_Unlock();
    return 1;
}

int ThreadManager_AddThread(MyThread* T){
    if(!ThreadManager_Init()){return 0;}
    if(T == NULL){return 0;}
    if(!BaseMutex_Lock(ThreadingManager->AccessMutex)){return 0;}

    ThreadManagerItemItem* NewTMIItem = (ThreadManagerItemItem*)malloc(sizeof(ThreadManagerItemItem));
    if(NewTMIItem == NULL){
        BaseMutex_Unlock(ThreadingManager->AccessMutex);
        return 0;
    }
    NewTMIItem->ID = MyThread_GetID(T);
    NewTMIItem->Thread = T;
    NewTMIItem->LastUsed = NULL;
    NewTMIItem->Prev = NULL;

    ThreadManagerItemItem* NxtTMIItem = NULL;
    if(ThreadingManager->ThreadData != NULL){
        NxtTMIItem = (ThreadManagerItemItem*)(ThreadingManager->ThreadData[0]);
    }

    void** NewItem = (void**)malloc(sizeof(void*) * 2);
    if(NewItem == NULL){
        free((void*)NewTMIItem);
        BaseMutex_Unlock(ThreadingManager->AccessMutex);
        return 0;
    }
    NewItem[0] = (void*)NewTMIItem;
    NewItem[1] = (void*)(ThreadingManager->ThreadData);
    ThreadingManager->ThreadData = (void**)(&(NewItem[0]));
    ThreadingManager->ThreadCount++;

    int NewTMItemIndex = (ThreadingManager->CurrentItem + 1) % ThreadManagerItemCount;
    ThreadManagerItem* OldTMItem = ThreadingManager->ItemArray[NewTMItemIndex];

    uint64_t CurAlpha = (uint64_t)MyRandom_GetInt(ThreadingManager->Random);
    uint64_t BestAlpha = CurAlpha;
    double CurBalance = ThreadManager_SimulateItem(CurAlpha);
    double BestBalance = CurBalance;

    int i;
    for(i = 1;i < ThreadManagerMaxHashingAttempt;i++){
        if(BestBalance <= 0.0f){break;}
        CurAlpha = (uint64_t)MyRandom_GetInt(ThreadingManager->Random);
        CurBalance = ThreadManager_SimulateItem(CurAlpha);
        if(CurBalance < BestBalance){
            BestBalance = CurBalance;
            BestAlpha = CurAlpha;
        }
    }

    ThreadManagerItem* NewTMItem = ThreadManager_CreateItem(BestAlpha);
    if(NewTMItem == NULL){
        ThreadingManager->ThreadData = (void**)(NewItem[1]);
        free((void*)NewTMIItem);
        free((void*)NewItem);
        ThreadingManager->ThreadCount--;
        BaseMutex_Unlock(ThreadingManager->AccessMutex);
        return 0;
    }
    if(NxtTMIItem != NULL){NxtTMIItem->Prev = (void*)(&(NewItem[0]));}
    ThreadingManager->ItemArray[NewTMItemIndex] = NewTMItem;
    ThreadManagerItem_Dispose(OldTMItem);
    ThreadingManager->CurrentItem = NewTMItemIndex;
    BaseMutex_Unlock(ThreadingManager->AccessMutex);
    #ifdef THREADING_DEBUG
    int InBalance = (int)(BestBalance * 100.0);
    printf("[INFO] Finished \"%s\" with inbalance:%i%%!\n",__FUNCTION__,InBalance);
    #endif // THREADING_DEBUG
    return 1;
}

int ThreadManager_RemoveThread(uint64_t ID){
    if(!ThreadManager_Init()){return 0;}
    if(!BaseMutex_Lock(ThreadingManager->AccessMutex)){return 0;}
    ThreadManagerItemItem* Result = ThreadManager_GetThreadItem(ID);
    if(Result == NULL){
        BaseMutex_Unlock(ThreadingManager->AccessMutex);
        return 0;
    }

    MyThread* Backup = Result->Thread;
    Result->Thread = NULL;
    ThreadingManager->ThreadCount--;

    int NewTMItemIndex = (ThreadingManager->CurrentItem + 1) % ThreadManagerItemCount;
    ThreadManagerItem* OldTMItem = ThreadingManager->ItemArray[NewTMItemIndex];

    uint64_t CurAlpha = (uint64_t)MyRandom_GetInt(ThreadingManager->Random);
    uint64_t BestAlpha = CurAlpha;
    double CurBalance = ThreadManager_SimulateItem(CurAlpha);
    double BestBalance = CurBalance;

    int i;
    for(i = 1;i < ThreadManagerMaxHashingAttempt;i++){
        if(BestBalance <= 0.0f){break;}
        CurAlpha = (uint64_t)MyRandom_GetInt(ThreadingManager->Random);
        CurBalance = ThreadManager_SimulateItem(CurAlpha);
        if(CurBalance < BestBalance){
            BestBalance = CurBalance;
            BestAlpha = CurAlpha;
        }
    }

    ThreadManagerItem* NewTMItem = ThreadManager_CreateItem(BestAlpha);
    if((NewTMItem == NULL)&&(ThreadingManager->ThreadCount > 0)){
        Result->Thread = Backup;
        ThreadingManager->ThreadCount++;
        BaseMutex_Unlock(ThreadingManager->AccessMutex);
        return 0;
    }

    ThreadingManager->ItemArray[NewTMItemIndex] = NewTMItem;
    ThreadManagerItem_Dispose(OldTMItem);
    ThreadingManager->CurrentItem = NewTMItemIndex;
    BaseMutex_Unlock(ThreadingManager->AccessMutex);
    ThreadBase_SignalCleanup((BaseThread*)Backup);
    #ifdef THREADING_DEBUG
    int InBalance = (int)(BestBalance * 100.0);
    printf("[INFO] Finished \"%s\" with inbalance:%i%%!\n",__FUNCTION__,InBalance);
    #endif // THREADING_DEBUG
    return 1;
}

MyThread* ThreadManager_GetThread(uint64_t ID){
    if(!ThreadManager_Init()){return NULL;}
    ThreadManagerItemItem* Result = ThreadManager_GetThreadItem(ID);
    if(Result == NULL){return NULL;}
    return Result->Thread;
}




static ThreadManagerItemItem* ThreadManager_GetThreadItem(uint64_t ID){
    int ItemIndex = ThreadingManager->CurrentItem;
    ThreadManagerItem* TMItem = ThreadingManager->ItemArray[ItemIndex];
    if(TMItem == NULL){return NULL;}
    int I = ThreadManager_GetHash(TMItem->Alpha,TMItem->ThreadCount,ID);
    BASICLISTITEM CurItem = &(TMItem->ThreadData[I << 1]);
    ThreadManagerItemItem* Result = NULL;
    ThreadManagerItemItem* CurThreadItem;
    while(CurItem != NULL){
        CurThreadItem = (ThreadManagerItemItem*)BASICLISTITEM_ITEM(CurItem);
        if(CurThreadItem->ID == ID){
            Result = CurThreadItem;
            break;
        }
        CurItem = BASICLISTITEM_NEXT(CurItem);
    }
    return Result;
}

static double ThreadManager_SimulateItem(uint64_t Alpha){
    if(ThreadingManager->ThreadCount <= 1){return 0.0f;}
    int Beta = ThreadingManager->ThreadCount;
    int i;
    int Elem[Beta];
    for(i = 0;i < Beta;i++){Elem[i] = 0;}
    BASICLISTITEM CurItem = BASICLIST_TOP(ThreadingManager->ThreadData);
    ThreadManagerItemItem* CurThreadItem;
    while(CurItem != NULL){
        CurThreadItem = (ThreadManagerItemItem*)BASICLISTITEM_ITEM(CurItem);
        if(CurThreadItem->Thread != NULL){
            i = ThreadManager_GetHash(Alpha,(uint64_t)Beta,CurThreadItem->ID);
            Elem[i] = Elem[i] + 1;
        }
        CurItem = BASICLISTITEM_NEXT(CurItem);
    }
    int MissplacementCount = 0;
    #ifdef THREADING_DEBUG
    printf("[INFO] Table: ");
    for(i = 0;i < Beta;i++){
        printf("[%i]",Elem[i]);
        MissplacementCount = MissplacementCount + abs(Elem[i] - 1);
    }
    MissplacementCount = MissplacementCount >> 1;
    printf(" => %i\n",MissplacementCount);
    return ((double)MissplacementCount) / ((double)(ThreadingManager->ThreadCount - 1));
    #else // THREADING_DEBUG
    for(i = 0;i < Beta;i++){MissplacementCount = MissplacementCount + abs(Elem[i] - 1);}
    MissplacementCount = MissplacementCount >> 1;
    return ((double)MissplacementCount) / ((double)(ThreadingManager->ThreadCount - 1));
    #endif // THREADING_DEBUG
}

static ThreadManagerItem* ThreadManager_CreateItem(uint64_t Alpha){
    if(ThreadingManager->ThreadCount < 1){return NULL;}
    ThreadManagerItem* res = (ThreadManagerItem*)malloc(sizeof(ThreadManagerItem));
    if(res == NULL){return NULL;}
    res->Alpha = Alpha;
    res->ThreadCount = ThreadingManager->ThreadCount;
    res->ThreadData = (void**)calloc(2 * ThreadingManager->ThreadCount,sizeof(void*));
    if(res->ThreadData == NULL){
        free((void*)res);
        return NULL;
    }
    int CollisionStackIndex = 0;
    void* CollisionStack[ThreadingManager->ThreadCount];

    int i;
    int j;
    BASICLISTITEM CurItem = BASICLIST_TOP(ThreadingManager->ThreadData);
    ThreadManagerItemItem* CurThreadItem;
    while(CurItem != NULL){
        CurThreadItem = (ThreadManagerItemItem*)BASICLISTITEM_ITEM(CurItem);
        if(CurThreadItem->Thread != NULL){
            CurThreadItem->LastUsed = res;
            i = ThreadManager_GetHash(Alpha,res->ThreadCount,CurThreadItem->ID);
            if(res->ThreadData[(i << 1)] != NULL){
                CollisionStack[CollisionStackIndex] = (void*)CurThreadItem;
                CollisionStackIndex++;
            }else{
                res->ThreadData[(i << 1)] = (void*)CurThreadItem;
            }
        }
        CurItem = BASICLISTITEM_NEXT(CurItem);
    }

    int LastEmptyIndex = -1;
    while(CollisionStackIndex > 0){
        CurThreadItem = (ThreadManagerItemItem*)CollisionStack[CollisionStackIndex - 1];
        i = ThreadManager_GetHash(Alpha,res->ThreadCount,CurThreadItem->ID);
        CurItem = &(res->ThreadData[(i << 1)]);
        while(BASICLISTITEM_NEXT(CurItem) != NULL){CurItem = BASICLISTITEM_NEXT(CurItem);}
        for(j = LastEmptyIndex + 1;j < res->ThreadCount;j++){
            if(res->ThreadData[(j << 1)] == NULL){LastEmptyIndex = j;break;}
        }
        res->ThreadData[(LastEmptyIndex << 1)] = (void*)CurThreadItem;
        CurItem[1] = (void*)(&(res->ThreadData[(LastEmptyIndex << 1)]));
        CollisionStackIndex--;
    }
    return res;
}

static int ThreadManager_GetHash(uint64_t Alpha,uint64_t Beta,uint64_t ID){
    if(!ThreadManager_Init()){return -1;}
    uint64_t Mask1 = ((~((uint64_t)0)) >> ((uint64_t)32));
    uint64_t V1 = ID & Mask1;
    uint64_t V2 = (ID & (~Mask1)) >> ((uint64_t)32);
    return (int)(((((Alpha * V1) % ThreadingManager->Prime) % Beta) + (((Alpha * V2) % ThreadingManager->Prime) % Beta)) % Beta);
}

static void ThreadManagerItem_Dispose(ThreadManagerItem* I){
    if(I == NULL){return;}
    int i;
    BASICLISTITEM PrevItem = NULL;
    BASICLISTITEM NextItem = NULL;
    ThreadManagerItemItem* CurThreadItem;
    ThreadManagerItemItem* PrevThreadItem;
    ThreadManagerItemItem* NextThreadItem;
    for(i = 0;i < I->ThreadCount;i++){
        CurThreadItem = (ThreadManagerItemItem*)I->ThreadData[(i << 1)];
        if((CurThreadItem->Thread == NULL)&&(CurThreadItem->LastUsed == I)){
            BASICLISTITEM CurItem = NULL;
            PrevThreadItem = NULL;
            NextThreadItem = NULL;
            if(CurThreadItem->Prev == NULL){
                PrevItem = NULL;
                CurItem = ThreadingManager->ThreadData;
                NextItem = BASICLISTITEM_NEXT(CurItem);
                ThreadingManager->ThreadData = NextItem;
                if(NextItem != NULL){
                    NextThreadItem = (ThreadManagerItemItem*)BASICLISTITEM_ITEM(NextItem);
                    NextThreadItem->Prev = NULL;
                }
            }else{
                PrevItem = (void**)CurThreadItem->Prev;
                CurItem = BASICLISTITEM_NEXT(PrevItem);
                NextItem = BASICLISTITEM_NEXT(CurItem);
                PrevItem[1] = (void*)NextItem;
                if(NextItem != NULL){
                    NextThreadItem = (ThreadManagerItemItem*)BASICLISTITEM_ITEM(NextItem);
                    NextThreadItem->Prev = (void*)PrevItem;
                }
            }
            free((void*)CurThreadItem);
        }
    }
    free((void*)I->ThreadData);
    free((void*)I);
}

