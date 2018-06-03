#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct testpqafsim TestPQAFSim;

#include "TestEnvironment.h"
#include "TestResults.h"
#include "../Basics/PriorityQueueMM.h"

#define TESTPQAFSIM_DOCHECKS

struct testpqafsim
{
    size_t TotalSize;
    int MaxItems;
    int Count;
    int (*compare)(void* I1,void* I2);
    int (*disposeItem)(void* I,ERRVAL_T* Errval);
    void* Items[];
};

TestPQAFSim* TestPQAFSim_Create(size_t TotalSize,int MaxItems,int(*compare)(void*,void*),int(*disposeItem)(void*,ERRVAL_T*),TestResults* Res);

void TestPQAFSim_Print(TestPQAFSim* P);

PriorityQueueMMAItem* TestPQAFSim_GetInsertedItem(TestPQAFSim* P,void* Item,TestResults* Res);

void* TestPQAFSim_GetMin(TestPQAFSim* P);

void* TestPQAFSim_GetMax(TestPQAFSim* P);

int TestPQAFSim_ContainsItem(TestPQAFSim* P,PriorityQueueMMAItem* Item,TestResults* Res);

int TestPQAFSim_SetItemOfItem(TestPQAFSim* P,PriorityQueueMMAItem* Item,void* ItemValue,TestResults* Res);

int TestPQAFSim_UpdateItem(TestPQAFSim* P,PriorityQueueMMAItem* Item,TestResults* Res);

int TestPQAFSim_Remove(TestPQAFSim* P,PriorityQueueMMAItem* Item,TestResults* Res);

int TestPQAFSim_RemoveSource(TestPQAFSim* P,PriorityQueueMMAItem* Item,TestResults* Res);

int TestPQAFSim_UpdateRes1(TestPQAFSim* P,TestResults* Res,int Ret);

int TestPQAFSim_UpdateRes2(TestPQAFSim* P,TestResults* Res,void* Ret);

void TestPQAFSim_Dispose(TestPQAFSim* P);
