#include "../MyThread.h"

MyThread* MyThread_Create(void* Data,void*(start_routine(void*)),void* arg,void(cleanup_routine(MyThread*))){
    BaseThread* res = BaseThread_Create(start_routine,arg);
    if(res == NULL){
        printf("[ERROR] Creation of Thread failed!\n");
        return NULL;
    }
    res->data = Data;
    res->cleanup_routine = cleanup_routine;
    return (MyThread*)res;
}

MyThread* MyThread_GetThreadFromID(uint64_t ID){
    return ThreadManager_GetThread(ID);
}

MyThread* MyThread_GetCurrentThread(void){
    return (MyThread*)BaseThread_GetCurrentThread();
}

uint64_t MyThread_GetID(MyThread* T){
    if(T == NULL){return 0;}
    return BaseThread_GetID((BaseThread*)T);
}

void* MyThread_GetArgument(MyThread* T){
    if(T == NULL){return NULL;}
    BaseThread* thread = (BaseThread*)T;
    return thread->arg;
}

void* MyThread_GetData(MyThread* T){
    if(T == NULL){return NULL;}
    BaseThread* thread = (BaseThread*)T;
    return thread->data;
}

int MyThread_SetData(MyThread* T,void* Data){
    if(T == NULL){return 0;}
    BaseThread* thread = (BaseThread*)T;
    thread->data = Data;
    return 1;
}

int MyThread_SetCleanupRoutine(MyThread* T,void(cleanup_routine(MyThread*))){
    if(T == NULL){return 0;}
    BaseThread* thread = (BaseThread*)T;
    thread->cleanup_routine = cleanup_routine;
    return 1;
}

int MyThread_Terminate(MyThread* T){
    if(T == NULL){return 0;}
    uint64_t ID1 = BaseThread_GetCurrentID();
    BaseThread* thread = (BaseThread*)T;
    uint64_t ID2 = BaseThread_GetID(thread);
    if(ID1 == ID2){
        MyThread_Exit(NULL);
        return 1;
    }
    BaseThread_Cancel(thread);
    ThreadManager_RemoveThread(ID2);
    return 1;
}

int MyThread_Exit(void* ExitValue){
    MyThread* T = MyThread_GetCurrentThread();
    uint64_t ID = MyThread_GetID(T);
    if(T == NULL){return 0;}
    ThreadManager_RemoveThread(ID);
    BaseThread_Exit(ExitValue);
    return 1;
}

int MyThread_WaitForTerminationOf(MyThread* T,void** ExitValue){
    if(T == NULL){*ExitValue = NULL;return 0;}
    BaseThread* thread = (BaseThread*)T;
    return BaseThread_WaitForTerminationOf(thread,ExitValue);
}

int MyThread_IsRunning(MyThread* T){
    if(T == NULL){return 0;}
    BaseThread* thread = (BaseThread*)T;
    uint64_t ID = BaseThread_GetID(thread);
    return (ThreadManager_GetThread(ID) != NULL);
}
