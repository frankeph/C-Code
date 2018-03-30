#include "ThreadBase.h"

#ifdef THREADING_USE_PTHREADS
#include <pthread.h>
//#include <opa_primitives.h>   //Just used for tests under Windows

#include "../MyThread.h"

pthread_cond_t cthread_cond;
pthread_mutex_t cthread_lock;
pthread_mutex_t cthread_mutex;
pthread_t* cthread = NULL;
void** cthread_Next = NULL;
void** cthread_Last = NULL;

pthread_mutex_t* TB_SerializeMutex = NULL;

pthread_key_t pthread_thread_key;



void* BaseThread_CRoutine(void* arg){
    #ifdef THREADING_DEBUG
    printf("[INFO] Starting Cleanup-Thread!\n");
    #endif // THREADING_DEBUG
    int PutToSleep;
    while(1){
        PutToSleep = 0;
        if(pthread_mutex_lock(&cthread_mutex)){
            printf("[CRITICAL ERROR] \"cthread_mutex\" is broken!\n");
            break;
        }
        if((cthread_Next == NULL)&&(cthread_Last == NULL)){
            PutToSleep = 1;
            pthread_mutex_unlock(&cthread_mutex);
        }else{
            BaseThread* CurThread = (BaseThread*)BASICLISTITEM_ITEM(cthread_Next);
            if(cthread_Next == cthread_Last){
                cthread_Next = NULL;
                cthread_Last = NULL;
            }else{
                cthread_Next = BASICLISTITEM_NEXT(cthread_Next);
            }
            pthread_mutex_unlock(&cthread_mutex);
            pthread_t* Thread = (pthread_t*)CurThread->Elem;
            pthread_join(*Thread,NULL);
            #ifdef THREADING_DEBUG
            printf("[INFO] Thread successfully terminated!\n");
            #endif // THREADING_DEBUG
            BaseThread_Dispose(CurThread);
        }
        if(PutToSleep){
            #ifdef THREADING_DEBUG
            printf("[INFO] Putting Cleanup-Thread to sleep!\n");
            #endif // THREADING_DEBUG
            pthread_mutex_lock(&cthread_lock);
            pthread_cond_wait(&cthread_cond,&cthread_lock);
            pthread_mutex_unlock(&cthread_lock);
            #ifdef THREADING_DEBUG
            printf("[INFO] Waking Cleanup-Thread up again!\n");
            #endif // THREADING_DEBUG
        }
    }
    return NULL;
}

void* BaseThread_Threadroutine(void* arg){
    BaseThread* thread = (BaseThread*)arg;
    if(pthread_setspecific(pthread_thread_key,arg)){
        printf("[ERROR] Creation of Thread failed!\n");
        printf("        Key could not be set!\n");
        return NULL;
    }
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,NULL);
    if(!ThreadManager_AddThread((MyThread*)arg)){
        printf("[ERROR] Creation of Thread failed!\n");
        printf("        Thread could not be added!\n");
        return NULL;
    }

    thread->CListItem[0] = arg;
    thread->CListItem[1] = NULL;

    uint64_t ThreadID = thread->ID;
    #ifdef THREADING_DEBUG
    printf("[INFO] Thread \"%llu\" created!\n",ThreadID);
    #endif // THREADING_DEBUG
    void* res = thread->start_routine(thread->arg);
    ThreadManager_RemoveThread(ThreadID);
    return res;
}

int ThreadBase_SerializeMutex_Create(void){
    if(TB_SerializeMutex != NULL){return 1;}
    pthread_mutex_t* Mutex = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
    if(Mutex == NULL){return 0;}
    if(pthread_mutex_init(Mutex,NULL)){
        free((void*)Mutex);
        return 0;
    }
    TB_SerializeMutex = Mutex;
    return 1;
}

int ThreadBase_SerializeMutex_Lock(void){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    return !pthread_mutex_lock(TB_SerializeMutex);
}

int ThreadBase_SerializeMutex_Unlock(void){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    return !pthread_mutex_unlock(TB_SerializeMutex);
}


int ThreadBase_SignalCleanup(BaseThread* T){
    if((cthread == NULL)||(T == NULL)){return 0;}
    if(pthread_mutex_lock(&cthread_mutex)){
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
    pthread_mutex_unlock(&cthread_mutex);
    pthread_cond_signal(&cthread_cond);
    return 1;
}


BaseThread* BaseThread_Create(void*(start_routine(void*)),void* arg){
    if(!ThreadBase_SerializeMutex_Create()){return NULL;}

    if(cthread == NULL){
        if(!ThreadBase_SerializeMutex_Lock()){return NULL;}
        if(cthread == NULL){
            if(pthread_key_create(&pthread_thread_key,NULL)){
                ThreadBase_SerializeMutex_Unlock();
                return NULL;
            }
            cthread = (pthread_t*)malloc(sizeof(pthread_t));
            if(cthread == NULL){
                pthread_key_delete(pthread_thread_key);
                ThreadBase_SerializeMutex_Unlock();
                return NULL;
            }
            if(pthread_mutex_init(&cthread_mutex,NULL)){
                free((void*)cthread);
                cthread = NULL;
                pthread_key_delete(pthread_thread_key);
                ThreadBase_SerializeMutex_Unlock();
                return NULL;
            }
            if(pthread_mutex_init(&cthread_lock,NULL)){
                pthread_mutex_destroy(&cthread_mutex);
                free((void*)cthread);
                cthread = NULL;
                pthread_key_delete(pthread_thread_key);
                ThreadBase_SerializeMutex_Unlock();
                return NULL;
            }
            if(pthread_cond_init(&cthread_cond,NULL)){
                pthread_mutex_destroy(&cthread_mutex);
                pthread_mutex_destroy(&cthread_lock);
                free((void*)cthread);
                cthread = NULL;
                pthread_key_delete(pthread_thread_key);
                ThreadBase_SerializeMutex_Unlock();
                return NULL;
            }
            if(pthread_create(cthread,NULL,BaseThread_CRoutine,NULL)){
                pthread_mutex_destroy(&cthread_mutex);
                pthread_mutex_destroy(&cthread_lock);
                pthread_cond_destroy(&cthread_cond);
                free((void*)cthread);
                cthread = NULL;
                pthread_key_delete(pthread_thread_key);
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
    res->ID = (uint64_t)res;
    res->start_routine = start_routine;

    pthread_t* Thread = (pthread_t*)malloc(sizeof(pthread_t));
    if(Thread == NULL){
        free((void*)res);
        return NULL;
    }
    res->Elem = (void*)Thread;

    if(pthread_create(Thread,NULL,BaseThread_Threadroutine,(void*)res)){
        free((void*)Thread);
        free((void*)res);
        return NULL;
    }
    return res;
}

BaseThread* BaseThread_GetCurrentThread(void){
    if(!ThreadBase_SerializeMutex_Create()){return NULL;}
    return (BaseThread*)pthread_getspecific(pthread_thread_key);
}

uint64_t BaseThread_GetCurrentID(void){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    BaseThread* Thread = BaseThread_GetCurrentThread();
    if(Thread == NULL){return 0;}
    return Thread->ID;
}

uint64_t BaseThread_GetID(BaseThread* T){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if(T == NULL){return 0;}
    return T->ID;
}

int BaseThread_WaitForTerminationOf(BaseThread* T,void** value_ptr){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if(T == NULL){return 0;}
    pthread_t* Thread = (pthread_t*)T->Elem;
    return !(pthread_join(*(Thread),value_ptr));
}

void BaseThread_Exit(void* value_ptr){
    pthread_exit(value_ptr);
}

int BaseThread_Cancel(BaseThread* T){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if(T == NULL){return 0;}
    pthread_t* Thread = (pthread_t*)T->Elem;
    return !(pthread_cancel(*(Thread)));
}

void BaseThread_Dispose(BaseThread* T){
    if(T == NULL){return;}
    if(T->cleanup_routine != NULL){T->cleanup_routine(T);}
    free((void*)T->Elem);
    free((void*)T);
}



BaseMutex* BaseMutex_Create(void){
    if(!ThreadBase_SerializeMutex_Create()){return NULL;}
    BaseMutex* res = (BaseMutex*)malloc(sizeof(BaseMutex));
    if(res == NULL){return NULL;}

    pthread_mutex_t* mutex = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
    if(mutex == NULL){
        free((void*)res);
        return NULL;
    }

    if(pthread_mutex_init(mutex,NULL)){
        free((void*)res);
        free((void*)mutex);
        return NULL;
    }

    res->Elem = (void*)mutex;
    return res;
}

int BaseMutex_Lock(BaseMutex* M){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if(M == NULL){return 0;}
    pthread_mutex_t* mutex = (pthread_mutex_t*)M->Elem;
    return !pthread_mutex_lock(mutex);
}

int BaseMutex_TryLock(BaseMutex* M){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if(M == NULL){return 0;}
    pthread_mutex_t* mutex = (pthread_mutex_t*)M->Elem;
    return !pthread_mutex_trylock(mutex);
}

int BaseMutex_Unlock(BaseMutex* M){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if(M == NULL){return 0;}
    pthread_mutex_t* mutex = (pthread_mutex_t*)M->Elem;
    return !pthread_mutex_unlock(mutex);
}

int BaseMutex_Dispose(BaseMutex* M){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if(M == NULL){return 1;}
    pthread_mutex_t* mutex = (pthread_mutex_t*)M->Elem;
    if(pthread_mutex_destroy(mutex)){return 0;}
    free((void*)M->Elem);
    free((void*)M);
    return 1;
}



BaseRWLock* BaseRWLock_Create(void){
    if(!ThreadBase_SerializeMutex_Create()){return NULL;}
    BaseRWLock* res = (BaseRWLock*)malloc(sizeof(BaseRWLock));
    if(res == NULL){return NULL;}

    pthread_rwlock_t* rwlock = (pthread_rwlock_t*)malloc(sizeof(pthread_rwlock_t));
    if(rwlock == NULL){
        free((void*)res);
        return NULL;
    }

    if(pthread_rwlock_init(rwlock,NULL)){
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
    pthread_rwlock_t* rwlock = (pthread_rwlock_t*)L->Elem;
    return !pthread_rwlock_rdlock(rwlock);
}

int BaseRWLock_TryReadLock(BaseRWLock* L){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if(L == NULL){return 0;}
    pthread_rwlock_t* rwlock = (pthread_rwlock_t*)L->Elem;
    return !pthread_rwlock_tryrdlock(rwlock);
}

int BaseRWLock_WriteLock(BaseRWLock* L){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if(L == NULL){return 0;}
    pthread_rwlock_t* rwlock = (pthread_rwlock_t*)L->Elem;
    return !pthread_rwlock_wrlock(rwlock);
}

int BaseRWLock_TryWriteLock(BaseRWLock* L){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if(L == NULL){return 0;}
    pthread_rwlock_t* rwlock = (pthread_rwlock_t*)L->Elem;
    return !pthread_rwlock_trywrlock(rwlock);
}

int BaseRWLock_Unlock(BaseRWLock* L){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if(L == NULL){return 0;}
    pthread_rwlock_t* rwlock = (pthread_rwlock_t*)L->Elem;
    return !pthread_rwlock_unlock(rwlock);
}

int BaseRWLock_Dispose(BaseRWLock* L){
    if(!ThreadBase_SerializeMutex_Create()){return 0;}
    if(L == NULL){return 1;}
    pthread_rwlock_t* rwlock = (pthread_rwlock_t*)L->Elem;
    if(pthread_rwlock_destroy(rwlock)){return 0;}
    free((void*)L->Elem);
    free((void*)L);
    return 1;
}

#endif // THREADING_USE_PTHREADS
