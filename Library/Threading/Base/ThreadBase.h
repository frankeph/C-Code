#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct basethread BaseThread;
typedef struct cont_struct BaseMutex;
typedef struct cont_struct BaseRWLock;

struct basethread
{
    void* Elem;
    uint64_t ID;
    void* arg;
    void* data;
    void* (*start_routine)(void* arg);
    void (*cleanup_routine)(BaseThread* T);

    void* CListItem[2];
};

struct cont_struct
{
    void* Elem;
};

//Important Constants:
#ifdef __linux__
#define THREADING_USE_PTHREADS
#define THREADING_SUPPORTED
#endif // __linux__

#ifdef 	__WINDOWS__
#define THREADING_USE_WTHREADS
#define THREADING_SUPPORTED
#endif // __WINDOWS__

#ifdef 	_WIN32
#define THREADING_USE_WTHREADS
#define THREADING_SUPPORTED
#endif // _WIN32

#ifdef  _WIN64
#define THREADING_USE_WTHREADS
#define THREADING_SUPPORTED
#endif // _WIN64

//#define THREADING_DEBUG

#ifdef THREADING_SUPPORTED
int ThreadBase_SerializeMutex_Create(void);

int ThreadBase_SerializeMutex_Lock(void);

int ThreadBase_SerializeMutex_Unlock(void);


int ThreadBase_SignalCleanup(BaseThread* T);


BaseThread* BaseThread_Create(void*(start_routine(void*)),void* arg);

BaseThread* BaseThread_GetCurrentThread(void);

uint64_t BaseThread_GetCurrentID(void);

uint64_t BaseThread_GetID(BaseThread* T);

int BaseThread_WaitForTerminationOf(BaseThread* T,void** value_ptr);

void BaseThread_Exit(void* value_ptr);

int BaseThread_Cancel(BaseThread* T);

void BaseThread_Dispose(BaseThread* T);



BaseMutex* BaseMutex_Create(void);

int BaseMutex_Lock(BaseMutex* M);

int BaseMutex_TryLock(BaseMutex* M);

int BaseMutex_Unlock(BaseMutex* M);

int BaseMutex_Dispose(BaseMutex* M);



BaseRWLock* BaseRWLock_Create(void);

int BaseRWLock_ReadLock(BaseRWLock* L);

int BaseRWLock_TryReadLock(BaseRWLock* L);

int BaseRWLock_WriteLock(BaseRWLock* L);

int BaseRWLock_TryWriteLock(BaseRWLock* L);

int BaseRWLock_Unlock(BaseRWLock* L);

int BaseRWLock_Dispose(BaseRWLock* L);

#else // THREADING_SUPPORTED

static inline int ThreadBase_SerializeMutex_Create(void){
    printf("[ERROR] Function \"%s\" not supported!\n",__FUNCTION__);
    return 0;
}

static inline int ThreadBase_SerializeMutex_Lock(void){
    printf("[ERROR] Function \"%s\" not supported!\n",__FUNCTION__);
    return 0;
}

static inline int ThreadBase_SerializeMutex_Unlock(void){
    printf("[ERROR] Function \"%s\" not supported!\n",__FUNCTION__);
    return 0;
}


static inline int ThreadBase_SignalCleanup(BaseThread* T){
    printf("[ERROR] Function \"%s\" not supported!\n",__FUNCTION__);
    return 0;
}


static inline BaseThread* BaseThread_Create(void*(start_routine(void*)),void* arg){
    printf("[ERROR] Function \"%s\" not supported!\n",__FUNCTION__);
    return NULL;
}

static inline BaseThread* BaseThread_GetCurrentThread(void){
    printf("[ERROR] Function \"%s\" not supported!\n",__FUNCTION__);
    return NULL;
}

static inline uint64_t BaseThread_GetCurrentID(void){
    printf("[ERROR] Function \"%s\" not supported!\n",__FUNCTION__);
    return 0;
}

static inline uint64_t BaseThread_GetID(BaseThread* T){
    printf("[ERROR] Function \"%s\" not supported!\n",__FUNCTION__);
    return 0;
}

static inline int BaseThread_WaitForTerminationOf(BaseThread* T,void** value_ptr){
    printf("[ERROR] Function \"%s\" not supported!\n",__FUNCTION__);
    return 0;
}

static inline void BaseThread_Exit(void* value_ptr){
    printf("[ERROR] Function \"%s\" not supported!\n",__FUNCTION__);
}

static inline int BaseThread_Cancel(BaseThread* T){
    printf("[ERROR] Function \"%s\" not supported!\n",__FUNCTION__);
    return 0;
}

static inline void BaseThread_Dispose(BaseThread* T){
    printf("[ERROR] Function \"%s\" not supported!\n",__FUNCTION__);
}



static inline BaseMutex* BaseMutex_Create(void){
    printf("[ERROR] Function \"%s\" not supported!\n",__FUNCTION__);
    return NULL;
}

static inline int BaseMutex_Lock(BaseMutex* M){
    printf("[ERROR] Function \"%s\" not supported!\n",__FUNCTION__);
    return 0;
}

static inline int BaseMutex_TryLock(BaseMutex* M){
    printf("[ERROR] Function \"%s\" not supported!\n",__FUNCTION__);
    return 0;
}

static inline int BaseMutex_Unlock(BaseMutex* M){
    printf("[ERROR] Function \"%s\" not supported!\n",__FUNCTION__);
    return 0;
}

static inline int BaseMutex_Dispose(BaseMutex* M){
    printf("[ERROR] Function \"%s\" not supported!\n",__FUNCTION__);
    return 0;
}



static inline BaseRWLock* BaseRWLock_Create(void){
    printf("[ERROR] Function \"%s\" not supported!\n",__FUNCTION__);
    return NULL;
}

static inline int BaseRWLock_ReadLock(BaseRWLock* L){
    printf("[ERROR] Function \"%s\" not supported!\n",__FUNCTION__);
    return 0;
}

static inline int BaseRWLock_TryReadLock(BaseRWLock* L){
    printf("[ERROR] Function \"%s\" not supported!\n",__FUNCTION__);
    return 0;
}

static inline int BaseRWLock_WriteLock(BaseRWLock* L){
    printf("[ERROR] Function \"%s\" not supported!\n",__FUNCTION__);
    return 0;
}

static inline int BaseRWLock_TryWriteLock(BaseRWLock* L){
    printf("[ERROR] Function \"%s\" not supported!\n",__FUNCTION__);
    return 0;
}

static inline int BaseRWLock_Unlock(BaseRWLock* L){
    printf("[ERROR] Function \"%s\" not supported!\n",__FUNCTION__);
    return 0;
}

static inline int BaseRWLock_Dispose(BaseRWLock* L){
    printf("[ERROR] Function \"%s\" not supported!\n",__FUNCTION__);
    return 0;
}

#endif // THREADING_SUPPORTED


