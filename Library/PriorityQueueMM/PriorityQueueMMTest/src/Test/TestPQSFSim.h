#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct testpqsfsim TestPQSFSim;

#include "TestEnvironment.h"
#include "TestResults.h"
#include "../Basics/PriorityQueueMM.h"

struct testpqsfsim
{
    size_t TotalSize;
    int MaxItems;
    int Count;
    int (*compare)(void* I1,void* I2);
    int (*disposeItem)(void* I,ERRVAL_T* Errval);
    void* Items[];
};

TestPQSFSim* TestPQSFSim_Create(size_t TotalSize,int MaxItems,int(*compare)(void*,void*),int(*disposeItem)(void*,ERRVAL_T*),TestResults* Res);

int TestPQSFSim_Insert(TestPQSFSim* P,void* Item,TestResults* Res);

void* TestPQSFSim_GetMin(TestPQSFSim* P);

void* TestPQSFSim_GetMax(TestPQSFSim* P);

int TestPQSFSim_RemoveMin(TestPQSFSim* P,TestResults* Res);

int TestPQSFSim_RemoveMax(TestPQSFSim* P,TestResults* Res);

int TestPQSFSim_RemoveMinSource(TestPQSFSim* P,TestResults* Res);

int TestPQSFSim_RemoveMaxSource(TestPQSFSim* P,TestResults* Res);

int TestPQSFSim_UpdateRes1(TestPQSFSim* P,TestResults* Res,int Ret);

int TestPQSFSim_UpdateRes2(TestPQSFSim* P,TestResults* Res,void* Ret);

void TestPQSFSim_Dispose(TestPQSFSim* P);
