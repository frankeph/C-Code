#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BASICLIST void**
#define BASICLISTITEM void**
#define BASICLIST_TOP(List) (List)
#define BASICLISTITEM_ITEM(ListItem) ((ListItem)[0])
#define BASICLISTITEM_NEXT(ListItem) ((BASICLISTITEM)((ListItem)[1]))

typedef struct threadmanager ThreadManager;
typedef struct threadmanageritem ThreadManagerItem;
typedef struct threadmanageritemitem ThreadManagerItemItem;

#include "../../Basics/MyRandom.h"
#include "ThreadBase.h"
#include "../MyThread.h"


#define ThreadManagerItemCount  20
#define ThreadManagerMaxHashingAttempt 5

struct threadmanager
{
    BaseMutex* AccessMutex;
    int ThreadCount;
    BASICLIST ThreadData;
    uint64_t Prime;
    int CurrentItem;
    ThreadManagerItem** ItemArray;
    MyRandom* Random;
};

struct threadmanageritem
{
    uint64_t Alpha;
    uint64_t ThreadCount;
    BASICLIST ThreadData;
};

struct threadmanageritemitem
{
    uint64_t ID;
    MyThread* Thread;
    ThreadManagerItem* LastUsed;
    void* Prev;
};

int ThreadManager_AddThread(MyThread* T);

int ThreadManager_RemoveThread(uint64_t ID);

MyThread* ThreadManager_GetThread(uint64_t ID);





