#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct testpqsdsim TestPQSDSim;
typedef struct testpqsdsimchunk TestPQSDSimChunk;

#include "TestEnvironment.h"
#include "TestResults.h"
#include "../Basics/PriorityQueueMM.h"

struct testpqsdsim
{
    int ChunkCount;
    int Count;
    int (*compare)(void* I1,void* I2);
    int (*disposeItem)(void* I,ERRVAL_T* Errval);
    TestPQSDSimChunk* FirstChunk;
    TestPQSDSimChunk* LastChunk;
};

struct testpqsdsimchunk
{
    TestPQSDSim* Owner;
    TestPQSDSimChunk* Prev;
    TestPQSDSimChunk* Next;
    void* Items[];
};

TestPQSDSim* TestPQSDSim_Create(int(*compare)(void*,void*),int(*disposeItem)(void*,ERRVAL_T*),TestResults* Res);

int TestPQSDSim_Insert(TestPQSDSim* P,void* Item,TestResults* Res);

void* TestPQSDSim_GetMin(TestPQSDSim* P);

void* TestPQSDSim_GetMax(TestPQSDSim* P);

int TestPQSDSim_RemoveMin(TestPQSDSim* P,TestResults* Res);

int TestPQSDSim_RemoveMax(TestPQSDSim* P,TestResults* Res);

int TestPQSDSim_RemoveMinSource(TestPQSDSim* P,TestResults* Res);

int TestPQSDSim_RemoveMaxSource(TestPQSDSim* P,TestResults* Res);

int TestPQSDSim_UpdateRes1(TestPQSDSim* P,TestResults* Res,int Ret);

int TestPQSDSim_UpdateRes2(TestPQSDSim* P,TestResults* Res,void* Ret);

void TestPQSDSim_Dispose(TestPQSDSim* P);
