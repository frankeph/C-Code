#include "ThreadBase.h"

#ifdef THREADING_USE_WTHREADS
#include <windows.h>

#define THREADING_USE_RWLOCKSV2

#include "../MyThread.h"

#ifndef THREADING_USE_RWLOCKSV2
struct baserwlock_imp
{
    HANDLE AccessMutex;
    HANDLE CurSemaphore;
    HANDLE OldSemaphore;
    uint64_t StackNumber;
    int64_t ReaderCount;
    uint64_t* LockData;
};
#else // THREADING_USE_RWLOCKSV2
struct baserwlock_imp
{
    HANDLE AccessMutex;
    uint8_t HasCurWriteAccess;
    uint16_t WriterCount;
    uint16_t ReaderCount;
    uint64_t* LockData;
    uint64_t* CurLockData;
};
#endif // THREADING_USE_RWLOCKSV2

HANDLE TB_SerializeMutex = NULL;

HANDLE cthread = NULL;
HANDLE cthread_mutex = NULL;
void** cthread_Next = NULL;
void** cthread_Last = NULL;

DWORD WINAPI BaseThread_CRoutine(void* arg){
    #ifdef THREADING_DEBUG
    printf("[INFO] Starting Cleanup-Thread!\n");
    #endif // THREADING_DEBUG
    int PutToSleep;
    DWORD WaitResult;
    while(1){
        PutToSleep = 0;
        WaitResult = WaitForSingleObject(cthread_mutex,INFINITE);
        if(WaitResult != WAIT_OBJECT_0){
            printf("[CRITICAL ERROR] \"cthread_mutex\" is broken!\n");
            break;
        }
        if((cthread_Next == NULL)&&(cthread_Last == NULL)){
            PutToSleep = 1;
            ReleaseMutex(cthread_mutex);
        }else{
            BaseThread* CurThread = (BaseThread*)BASICLISTITEM_ITEM(cthread_Next);
            if(cthread_Next == cthread_Last){
                cthread_Next = NULL;
                cthread_Last = NULL;
            }else{
                cthread_Next = BASICLISTITEM_NEXT(cthread_Next);
            }
            ReleaseMutex(cthread_mutex);
            HANDLE Thread = (HANDLE)CurThread->Elem;
            WaitResult = WaitForSingleObject(Thread,INFINITE);
            if(WaitResult != WAIT_OBJECT_0){
                printf("[ERROR] Waiting for Thread to cleanup did not return the way it was supposed to!\n");
            }
            #ifdef THREADING_DEBUG
            printf("[INFO] Thread successfully terminated!\n");
            #endif // THREADING_DEBUG
            BaseThread_Dispose(CurThread);
        }
        if(PutToSleep){
            #ifdef THREADING_DEBUG
            printf("[INFO] Putting Cleanup-Thread to sleep!\n");
            #endif // THREADING_DEBUG
            SuspendThread(cthread);
            #ifdef THREADING_DEBUG
            printf("[INFO] Waking Cleanup-Thread up again!\n");
            #endif // THREADING_DEBUG
        }
    }
    return 0;
}


int ThreadBase_SignalCleanup(BaseThread* T){
    if((cthread == NULL)||(T == NULL)){return 0;}
    DWORD WaitResult = WaitForSingleObject(cthread_mutex,INFINITE);
    if(WaitResult != WAIT_OBJECT_0){
        printf("[CRITICAL ERROR] \"cthread_mutex\" is broken!\n");
        return 0;
    }
    if(cthread_Next == NULL){
        cthread_Next = &(T->CListItem[0]);
        cthread_Last = cthread_Next;
    }else{
        cthread_Last[1] = (void*)(&(T->CListItem[0]));
        cthread_Last = &(T->CListItem[0]);
    }
    ReleaseMutex(cthread_mutex);
    ResumeThread(cthread);
    return 1;
}


DWORD WINAPI BaseThread_Threadroutine(void* arg){
    BaseThread* thread = (BaseThread*)arg;
    thread->ID = ((uint64_t)GetCurrentThreadId());
    if(!ThreadManager_AddThread((MyThread*)arg)){
        printf("[ERROR] Creation of Thread failed!\n");
        printf("        Thread could not be added!\n");
        return NULL;
    }
    uint64_t ThreadID = thread->ID;

    thread->CListItem[0] = arg;
    thread->CListItem[1] = NULL;

    #ifdef THREADING_DEBUG
    printf("[INFO] Thread \"%llu\" created!\n",ThreadID);
    #endif // THREADING_DEBUG
    void* res = thread->start_routine(thread->arg);
    DWORD ThreadRes = (DWORD)res;
    if(ThreadRes >= STILL_ACTIVE){ThreadRes = ThreadRes + ((DWORD)1);}
    ThreadManager_RemoveThread(ThreadID);
    return ThreadRes;
}

int ThreadBase_SerializeMutex_Create(void){
    if(TB_SerializeMutex != NULL){return 1;}
    HANDLE Mutex = CreateMutex(NULL,FALSE,NULL);
    if(Mutex == NULL){return 0;}
    TB_SerializeMutex = Mutex;
    return 1;
}

int ThreadBase_SerializeMutex_Lock(void){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    DWORD WaitResult = WaitForSingleObject(TB_SerializeMutex,INFINITE);
    if(WaitResult == WAIT_OBJECT_0){return 1;}
    return 0;
}

int ThreadBase_SerializeMutex_Unlock(void){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    return !(!(ReleaseMutex(TB_SerializeMutex)));
}



BaseThread* BaseThread_Create(void*(start_routine(void*)),void* arg){
    if(!ThreadBase_SerializeMutex_Create()){return NULL;}
    if(cthread == NULL){
        if(!ThreadBase_SerializeMutex_Lock()){return NULL;}
        if(cthread == NULL){
            cthread_mutex = CreateMutex(NULL,FALSE,NULL);
            if(cthread_mutex == NULL){
                ThreadBase_SerializeMutex_Unlock();
                return NULL;
            }
            if(!(cthread = CreateThread(NULL,0,BaseThread_CRoutine,NULL,0,NULL))){
                CloseHandle(cthread_mutex);
                ThreadBase_SerializeMutex_Unlock();
                return NULL;
            }
        }
        ThreadBase_SerializeMutex_Unlock();
    }
    BaseThread* res = (BaseThread*)malloc(sizeof(BaseThread));
    if(res == NULL){return NULL;}
    res->arg = arg;
    res->data = NULL;
    res->start_routine = start_routine;
    res->cleanup_routine = NULL;
    res->ID = 0;
    if(!(res->Elem = (void*)CreateThread(NULL,0,BaseThread_Threadroutine,(void*)res,0,NULL))){
        free((void*)res);
        return NULL;
    }

    return res;
}

BaseThread* BaseThread_GetCurrentThread(void){
    if(!ThreadBase_SerializeMutex_Create()){return NULL;}
    uint64_t ID = BaseThread_GetCurrentID();
    return (BaseThread*)ThreadManager_GetThread(ID);
}

uint64_t BaseThread_GetCurrentID(void){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    return ((uint64_t)GetCurrentThreadId());
}

uint64_t BaseThread_GetID(BaseThread* T){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if(T == NULL){return 0;}
    return T->ID;
}

int BaseThread_WaitForTerminationOf(BaseThread* T,void** value_ptr){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if(T == NULL){*value_ptr = NULL;return 1;}
    HANDLE thread = (HANDLE)T->Elem;
    DWORD ThreadRes;
    while(1){
        if(!GetExitCodeThread(thread,&ThreadRes)){*value_ptr = NULL;return 0;}
        if(ThreadRes == STILL_ACTIVE){
            Sleep(1);
        }else{
            if(ThreadRes > STILL_ACTIVE){ThreadRes = ThreadRes - ((DWORD)1);}
            *value_ptr = (void*)ThreadRes;
            break;
        }
    }
    return 1;
}

void BaseThread_Exit(void* value_ptr){
    DWORD ThreadRes = (DWORD)value_ptr;
    if(ThreadRes >= STILL_ACTIVE){ThreadRes = ThreadRes + ((DWORD)1);}
    ExitThread(ThreadRes);
}

int BaseThread_Cancel(BaseThread* T){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if(T == NULL){return 0;}
    HANDLE thread = (HANDLE)T->Elem;
    return (!(!(TerminateThread(thread,0))));
}

void BaseThread_Dispose(BaseThread* T){
    if(T == NULL){return;}
    if(T->cleanup_routine != NULL){T->cleanup_routine(T);}
    HANDLE thread = (HANDLE)T->Elem;
    CloseHandle(thread);
    free((void*)T);
}



BaseMutex* BaseMutex_Create(void){
    if(!ThreadBase_SerializeMutex_Create()){return NULL;}
    BaseMutex* res = (BaseMutex*)malloc(sizeof(BaseMutex));
    if(res == NULL){return NULL;}

    HANDLE mutex = CreateMutex(NULL,FALSE,NULL);
    if(mutex == NULL){
        free((void*)res);
        return NULL;
    }

    res->Elem = (void*)mutex;
    return res;
}

int BaseMutex_Lock(BaseMutex* M){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if(M == NULL){return 0;}
    HANDLE mutex = (HANDLE)M->Elem;
    DWORD WaitResult = WaitForSingleObject(mutex,INFINITE);
    if(WaitResult == WAIT_OBJECT_0){return 1;}
    return 0;
}

int BaseMutex_TryLock(BaseMutex* M){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if(M == NULL){return 0;}
    HANDLE mutex = (HANDLE)M->Elem;
    DWORD WaitResult = WaitForSingleObject(mutex,0);
    if(WaitResult == WAIT_OBJECT_0){return 1;}
    return 0;
}

int BaseMutex_Unlock(BaseMutex* M){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if(M == NULL){return 0;}
    HANDLE mutex = (HANDLE)M->Elem;
    return !(!(ReleaseMutex(mutex)));
}

int BaseMutex_Dispose(BaseMutex* M){
    if(M == NULL){return 1;}
    HANDLE mutex = (HANDLE)M->Elem;
    int res = !!CloseHandle(mutex);
    if(!res){return 0;}
    free((void*)M);
    return 1;
}


#ifndef THREADING_USE_RWLOCKSV2
BaseRWLock* BaseRWLock_Create(void){
    if(!ThreadBase_SerializeMutex_Create()){return NULL;}
    BaseRWLock* res = (BaseRWLock*)malloc(sizeof(BaseRWLock));
    if(res == NULL){return NULL;}

    struct baserwlock_imp* rwlock = (struct baserwlock_imp*)malloc(sizeof(struct baserwlock_imp));
    if(rwlock == NULL){
        free((void*)res);
        return NULL;
    }
    rwlock->CurSemaphore = NULL;
    rwlock->OldSemaphore = NULL;
    rwlock->StackNumber = 0;
    rwlock->LockData = NULL;
    rwlock->ReaderCount = 0;
    rwlock->AccessMutex = CreateMutex(NULL,FALSE,NULL);
    if(rwlock->AccessMutex == NULL){
        free((void*)res);
        free((void*)rwlock);
        return NULL;
    }

    res->Elem = (void*)rwlock;
    return res;
}

int BaseRWLock_ReadLock(BaseRWLock* L){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if((L == NULL)||(L->Elem == NULL)){return 0;}
    struct baserwlock_imp* rwlock = (struct baserwlock_imp*)L->Elem;
    DWORD WaitResult = WaitForSingleObject(rwlock->AccessMutex,INFINITE);
    if(WaitResult != WAIT_OBJECT_0){return 0;}
    if(L->Elem == NULL){ReleaseMutex(rwlock->AccessMutex);return 0;}

    HANDLE MySemaphore = rwlock->CurSemaphore;
    if(rwlock->LockData == NULL){
        if(MySemaphore == NULL){
            rwlock->ReaderCount = rwlock->ReaderCount + ((int64_t)1);
            ReleaseMutex(rwlock->AccessMutex);
            return 1;
        }
        if(rwlock->ReaderCount < 0){
            rwlock->ReaderCount = rwlock->ReaderCount - ((int64_t)1);
        }else{
            rwlock->ReaderCount = rwlock->ReaderCount + ((int64_t)1);
        }
        ReleaseMutex(rwlock->AccessMutex);

        WaitResult = WaitForSingleObject(MySemaphore,INFINITE);
        if(WaitResult != WAIT_OBJECT_0){
            printf("[ERROR] WAITING FOR OBJECT IN \"%s\" FAILED!\n",__FUNCTION__);
            return 0;
        }
        ReleaseSemaphore(MySemaphore,1,NULL);
        return 1;
    }
    rwlock->LockData[1] = rwlock->LockData[1] + ((uint64_t)1);
    ReleaseMutex(rwlock->AccessMutex);

    WaitResult = WaitForSingleObject(MySemaphore,INFINITE);
    if(WaitResult != WAIT_OBJECT_0){return 0;}
    ReleaseSemaphore(MySemaphore,1,NULL);

    WaitResult = WaitForSingleObject(rwlock->AccessMutex,INFINITE);
    if(WaitResult != WAIT_OBJECT_0){return 0;}
    ReleaseMutex(rwlock->AccessMutex);
    return 1;
}

int BaseRWLock_TryReadLock(BaseRWLock* L){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if((L == NULL)||(L->Elem == NULL)){return 0;}
    struct baserwlock_imp* rwlock = (struct baserwlock_imp*)L->Elem;
    DWORD WaitResult = WaitForSingleObject(rwlock->AccessMutex,INFINITE);
    if(WaitResult != WAIT_OBJECT_0){return 0;}
    if(L->Elem == NULL){ReleaseMutex(rwlock->AccessMutex);return 0;}
    HANDLE MySemaphore = rwlock->CurSemaphore;
    if(rwlock->LockData == NULL){
        if(MySemaphore == NULL){
            rwlock->ReaderCount = rwlock->ReaderCount + ((int64_t)1);
            ReleaseMutex(rwlock->AccessMutex);
            return 1;
        }
        WaitResult = WaitForSingleObject(MySemaphore,0);
        if(WaitResult != WAIT_OBJECT_0){
            ReleaseMutex(rwlock->AccessMutex);
            return 0;
        }
        ReleaseSemaphore(MySemaphore,1,NULL);
        rwlock->ReaderCount = rwlock->ReaderCount + ((int64_t)1);
        ReleaseMutex(rwlock->AccessMutex);
        return 1;
    }
    return 0;
}

int BaseRWLock_WriteLock(BaseRWLock* L){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if((L == NULL)||(L->Elem == NULL)){return 0;}
    struct baserwlock_imp* rwlock = (struct baserwlock_imp*)L->Elem;
    HANDLE MySemaphore = CreateSemaphore(NULL,1,1,NULL);
    if(MySemaphore == NULL){return 0;}
    DWORD WaitResult = WaitForSingleObject(MySemaphore,INFINITE);
    if(WaitResult != WAIT_OBJECT_0){
        CloseHandle(MySemaphore);
        return 0;
    }

    uint64_t MyLockData[3];
    WaitResult = WaitForSingleObject(rwlock->AccessMutex,INFINITE);
    if(WaitResult != WAIT_OBJECT_0){
        ReleaseSemaphore(MySemaphore,1,NULL);
        CloseHandle(MySemaphore);
        return 0;
    }
    if(L->Elem == NULL){
        ReleaseSemaphore(MySemaphore,1,NULL);
        ReleaseMutex(rwlock->AccessMutex);
        CloseHandle(MySemaphore);
        return 0;
    }

    MyLockData[0] = (uint64_t)rwlock->LockData;
    MyLockData[1] = 0;
    MyLockData[2] = 0;
    if(rwlock->LockData != NULL){rwlock->LockData[2] = ((uint64_t)(&(MyLockData[0])));}
    HANDLE WaitSemaphore = rwlock->CurSemaphore;
    rwlock->LockData = &(MyLockData[0]);
    rwlock->CurSemaphore = MySemaphore;
    ReleaseMutex(rwlock->AccessMutex);


    if(WaitSemaphore != NULL){
        WaitResult = WaitForSingleObject(WaitSemaphore,INFINITE);
        if(WaitResult != WAIT_OBJECT_0){
            printf("[ERROR] WAITING FOR OBJECT IN \"%s\" FAILED!\n",__FUNCTION__);
            return 0;
        }
        ReleaseSemaphore(WaitSemaphore,1,NULL);
    }

    //Wait until the "ReaderCount" is 0:
    while(1){
        WaitResult = WaitForSingleObject(rwlock->AccessMutex,INFINITE);
        if(WaitResult != WAIT_OBJECT_0){
            printf("[ERROR] WAITING FOR OBJECT IN \"%s\" FAILED!\n",__FUNCTION__);
            return 0;
        }
        if(rwlock->ReaderCount == 0){break;}
        ReleaseMutex(rwlock->AccessMutex);
        Sleep(1);
    }

    if(rwlock->OldSemaphore != NULL){CloseHandle(rwlock->OldSemaphore);}
    rwlock->OldSemaphore = MySemaphore;
    rwlock->ReaderCount = ((int64_t)(MyLockData[1] + ((uint64_t)1))) * (-((int64_t)1));
    rwlock->StackNumber = ((uint64_t)(&(MyLockData[0])));
    if(&(MyLockData[0]) == rwlock->LockData){
        rwlock->LockData = NULL;
        rwlock->StackNumber = 0;
    }
    ReleaseMutex(rwlock->AccessMutex);
    return 1;
}

int BaseRWLock_TryWriteLock(BaseRWLock* L){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if((L == NULL)||(L->Elem == NULL)){return 0;}
    struct baserwlock_imp* rwlock = (struct baserwlock_imp*)L->Elem;
    HANDLE MySemaphore = CreateSemaphore(NULL,1,1,NULL);
    if(MySemaphore == NULL){return 0;}
    DWORD WaitResult = WaitForSingleObject(MySemaphore,0);
    if(WaitResult != WAIT_OBJECT_0){
        CloseHandle(MySemaphore);
        return 0;
    }

    WaitResult = WaitForSingleObject(rwlock->AccessMutex,0);
    if(WaitResult != WAIT_OBJECT_0){
        ReleaseSemaphore(MySemaphore,1,NULL);
        CloseHandle(MySemaphore);
        return 0;
    }
    if(L->Elem == NULL){
        ReleaseSemaphore(MySemaphore,1,NULL);
        ReleaseMutex(rwlock->AccessMutex);
        CloseHandle(MySemaphore);
        return 0;
    }
    if(!((rwlock->LockData == NULL)&&(rwlock->ReaderCount == 0))){
        ReleaseMutex(rwlock->AccessMutex);
        ReleaseSemaphore(MySemaphore,1,NULL);
        CloseHandle(MySemaphore);
        return 0;
    }
    rwlock->CurSemaphore = MySemaphore;
    rwlock->OldSemaphore = MySemaphore;
    rwlock->ReaderCount = ((int64_t)(-1));
    rwlock->StackNumber = 0;
    ReleaseMutex(rwlock->AccessMutex);
    return 1;
}

int BaseRWLock_Unlock(BaseRWLock* L){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if((L == NULL)||(L->Elem == NULL)){return 0;}
    struct baserwlock_imp* rwlock = (struct baserwlock_imp*)L->Elem;
    DWORD WaitResult = WaitForSingleObject(rwlock->AccessMutex,INFINITE);
    if(WaitResult != WAIT_OBJECT_0){return 0;}
    if(rwlock->ReaderCount < 0){
        if(!ReleaseSemaphore(rwlock->OldSemaphore,1,NULL)){
            ReleaseMutex(rwlock->AccessMutex);
            return 0;
        }
        rwlock->ReaderCount = (rwlock->ReaderCount + ((int64_t)1)) * (-((int64_t)1));
    }else{
        rwlock->ReaderCount = rwlock->ReaderCount - ((int64_t)1);
    }
    ReleaseMutex(rwlock->AccessMutex);
    return 1;
}

int BaseRWLock_Dispose(BaseRWLock* L){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if(L == NULL){return 1;}
    if(L->Elem == NULL){return 0;}
    struct baserwlock_imp* rwlock = (struct baserwlock_imp*)L->Elem;
    DWORD WaitResult = WaitForSingleObject(rwlock->AccessMutex,INFINITE);
    if(WaitResult != WAIT_OBJECT_0){return 0;}
    if(L->Elem == NULL){
        ReleaseMutex(rwlock->AccessMutex);
        return 0;
    }
    if(!((rwlock->LockData == NULL)&&(rwlock->ReaderCount == 0))){
        ReleaseMutex(rwlock->AccessMutex);
        return 0;
    }
    L->Elem = NULL;
    ReleaseMutex(rwlock->AccessMutex);
    if((rwlock->CurSemaphore != NULL)&&(rwlock->CurSemaphore != rwlock->OldSemaphore)){
        CloseHandle(rwlock->CurSemaphore);
        rwlock->CurSemaphore = NULL;
    }
    if(rwlock->OldSemaphore != NULL){
        CloseHandle(rwlock->OldSemaphore);
        rwlock->OldSemaphore = NULL;
    }
    CloseHandle(rwlock->AccessMutex);
    free((void*)rwlock);
    free((void*)L);
    return 1;
}
#else // THREADING_USE_RWLOCKSV2
BaseRWLock* BaseRWLock_Create(void){
    if(!ThreadBase_SerializeMutex_Create()){return NULL;}
    BaseRWLock* res = (BaseRWLock*)malloc(sizeof(BaseRWLock));
    if(res == NULL){return NULL;}

    struct baserwlock_imp* rwlock = (struct baserwlock_imp*)malloc(sizeof(struct baserwlock_imp));
    if(rwlock == NULL){
        free((void*)res);
        return NULL;
    }
    rwlock->HasCurWriteAccess = 0;
    rwlock->ReaderCount = 0;
    rwlock->WriterCount = 0;
    rwlock->LockData = NULL;
    rwlock->CurLockData = NULL;

    rwlock->AccessMutex = CreateMutex(NULL,FALSE,NULL);
    if(rwlock->AccessMutex == NULL){
        free((void*)res);
        free((void*)rwlock);
        return NULL;
    }

    res->Elem = (void*)rwlock;
    return res;
}

int BaseRWLock_ReadLock(BaseRWLock* L){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if(L == NULL){return 0;}
    struct baserwlock_imp* rwlock = (struct baserwlock_imp*)L->Elem;

    BaseThread* Thread = BaseThread_GetCurrentThread();

    uint64_t MyLockData[3];
    MyLockData[0] = 0;
    MyLockData[1] = (uint64_t)Thread;
    MyLockData[2] = 0;

    DWORD WaitResult = WaitForSingleObject(rwlock->AccessMutex,INFINITE);
    if(WaitResult != WAIT_OBJECT_0){return 0;}
    if(rwlock->WriterCount == 0){
        rwlock->ReaderCount = rwlock->ReaderCount + 1;
        ReleaseMutex(rwlock->AccessMutex);
        return 1;
    }

    if(rwlock->LockData == NULL){
        rwlock->LockData = &(MyLockData[0]);
        rwlock->CurLockData = rwlock->LockData;
    }else{
        rwlock->LockData[2] = (uint64_t)(&(MyLockData[0]));
        rwlock->LockData = &(MyLockData[0]);
    }
    ReleaseMutex(rwlock->AccessMutex);
    HANDLE thread = (HANDLE)Thread->Elem;
    SuspendThread(thread);
    return 1;
}

int BaseRWLock_TryReadLock(BaseRWLock* L){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if(L == NULL){return 0;}
    struct baserwlock_imp* rwlock = (struct baserwlock_imp*)L->Elem;

    DWORD WaitResult = WaitForSingleObject(rwlock->AccessMutex,0);
    if(WaitResult != WAIT_OBJECT_0){return 0;}
    if(rwlock->WriterCount == 0){
        rwlock->ReaderCount = rwlock->ReaderCount + 1;
        ReleaseMutex(rwlock->AccessMutex);
        return 1;
    }
    ReleaseMutex(rwlock->AccessMutex);
    return 0;
}

int BaseRWLock_WriteLock(BaseRWLock* L){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if(L == NULL){return 0;}
    struct baserwlock_imp* rwlock = (struct baserwlock_imp*)L->Elem;

    BaseThread* Thread = BaseThread_GetCurrentThread();

    uint64_t MyLockData[3];
    MyLockData[0] = 1;
    MyLockData[1] = (uint64_t)Thread;
    MyLockData[2] = 0;

    DWORD WaitResult = WaitForSingleObject(rwlock->AccessMutex,INFINITE);
    if(WaitResult != WAIT_OBJECT_0){return 0;}
    if((rwlock->WriterCount == 0)&&(rwlock->ReaderCount == 0)){
        rwlock->WriterCount = rwlock->WriterCount + 1;
        rwlock->HasCurWriteAccess = 1;
        ReleaseMutex(rwlock->AccessMutex);
        return 1;
    }

    if(rwlock->LockData == NULL){
        rwlock->LockData = &(MyLockData[0]);
        rwlock->CurLockData = rwlock->LockData;
    }else{
        rwlock->LockData[2] = (uint64_t)(&(MyLockData[0]));
        rwlock->LockData = &(MyLockData[0]);
    }
    ReleaseMutex(rwlock->AccessMutex);
    HANDLE thread = (HANDLE)Thread->Elem;
    SuspendThread(thread);
    return 1;
}

int BaseRWLock_TryWriteLock(BaseRWLock* L){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if(L == NULL){return 0;}
    struct baserwlock_imp* rwlock = (struct baserwlock_imp*)L->Elem;

    DWORD WaitResult = WaitForSingleObject(rwlock->AccessMutex,0);
    if(WaitResult != WAIT_OBJECT_0){return 0;}
    if((rwlock->WriterCount == 0)&&(rwlock->ReaderCount == 0)){
        rwlock->WriterCount = rwlock->WriterCount + 1;
        rwlock->HasCurWriteAccess = 1;
        ReleaseMutex(rwlock->AccessMutex);
        return 1;
    }
    ReleaseMutex(rwlock->AccessMutex);
    return 0;
}

int BaseRWLock_Unlock(BaseRWLock* L){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if(L == NULL){return 0;}
    struct baserwlock_imp* rwlock = (struct baserwlock_imp*)L->Elem;

    uint64_t* MyLockData;

    DWORD WaitResult = WaitForSingleObject(rwlock->AccessMutex,INFINITE);
    if(WaitResult != WAIT_OBJECT_0){return 0;}
    MyLockData = rwlock->CurLockData;
    BaseThread* Thread;
    if(rwlock->ReaderCount > 0){
        rwlock->ReaderCount--;
    }else if(rwlock->HasCurWriteAccess > 0){
        rwlock->WriterCount--;
        rwlock->HasCurWriteAccess = 0;
    }

    //Possible to start next Writer-Thread:
    if((rwlock->ReaderCount == 0)&&(MyLockData != NULL)){
        if(MyLockData[0] == 1){
            rwlock->HasCurWriteAccess = 1;
            if(rwlock->LockData == rwlock->CurLockData){
                rwlock->LockData = NULL;
                rwlock->CurLockData = NULL;
            }else{
                rwlock->CurLockData = (uint64_t*)MyLockData[2];
            }
            Thread = (BaseThread*)(MyLockData[1]);
            ReleaseMutex(rwlock->AccessMutex);
            HANDLE thread = (HANDLE)Thread->Elem;
            ResumeThread(thread);
            return 1;
        }else{
            do{
                MyLockData = rwlock->CurLockData;
                if(rwlock->LockData == rwlock->CurLockData){
                    rwlock->LockData = NULL;
                    rwlock->CurLockData = NULL;
                }else{
                    rwlock->CurLockData = (uint64_t*)MyLockData[2];
                }
                rwlock->ReaderCount++;
                Thread = (BaseThread*)(MyLockData[1]);
                HANDLE thread = (HANDLE)Thread->Elem;
                ResumeThread(thread);
            }while((rwlock->CurLockData != NULL)&&(rwlock->CurLockData[0] == 0));
            ReleaseMutex(rwlock->AccessMutex);
            return 1;
        }
    }
    ReleaseMutex(rwlock->AccessMutex);
    return 1;
}

int BaseRWLock_Dispose(BaseRWLock* L){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if(L == NULL){return 1;}
    struct baserwlock_imp* rwlock = (struct baserwlock_imp*)L->Elem;

    DWORD WaitResult = WaitForSingleObject(rwlock->AccessMutex,INFINITE);
    if(WaitResult != WAIT_OBJECT_0){return 0;}
    if((rwlock->ReaderCount > 0)||(rwlock->CurLockData != NULL)){
        ReleaseMutex(rwlock->AccessMutex);
        return 0;
    }
    L->Elem = NULL;
    ReleaseMutex(rwlock->AccessMutex);
    CloseHandle(rwlock->AccessMutex);
    free((void*)rwlock);
    free((void*)L);
    return 1;
}


#endif // THREADING_USE_RWLOCKSV2

#endif // THREADING_USE_WTHREADS
