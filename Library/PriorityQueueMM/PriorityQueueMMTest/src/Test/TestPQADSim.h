#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct testpqadsim TestPQADSim;
typedef struct testpqadsimchunk TestPQADSimChunk;

#include "TestEnvironment.h"
#include "TestResults.h"
#include "../Basics/PriorityQueueMM.h"

#define TESTPQADSIM_DOCHECKS

struct testpqadsim
{
    int ChunkCount;    //Count for Tree-Items
    int AChunkCount;    //Count for Indirection-Items
    int Count;
    int (*compare)(void* I1,void* I2);
    int (*disposeItem)(void* I,ERRVAL_T* Errval);

    TestPQADSimChunk* ACurChunk;
    TestPQADSimChunk* ALastChunk;

    TestPQADSimChunk* FirstChunk;
    TestPQADSimChunk* LastChunk;
};

struct testpqadsimchunk
{
    TestPQADSim* Owner;
    TestPQADSimChunk* Prev;
    TestPQADSimChunk* Next;
    void* Items[];
};

TestPQADSim* TestPQADSim_Create(int(*compare)(void*,void*),int(*disposeItem)(void*,ERRVAL_T*),TestResults* Res);

void TestPQADSim_Print(TestPQADSim* P);

PriorityQueueMMAItem* TestPQADSim_GetInsertedItem(TestPQADSim* P,void* Item,TestResults* Res);

void* TestPQADSim_GetMin(TestPQADSim* P);

void* TestPQADSim_GetMax(TestPQADSim* P);

int TestPQADSim_ContainsItem(TestPQADSim* P,PriorityQueueMMAItem* Item,TestResults* Res);

int TestPQADSim_SetItemOfItem(TestPQADSim* P,PriorityQueueMMAItem* Item,void* ItemValue,TestResults* Res);

int TestPQADSim_UpdateItem(TestPQADSim* P,PriorityQueueMMAItem* Item,TestResults* Res);

int TestPQADSim_Remove(TestPQADSim* P,PriorityQueueMMAItem* Item,TestResults* Res);

int TestPQADSim_RemoveSource(TestPQADSim* P,PriorityQueueMMAItem* Item,TestResults* Res);

int TestPQADSim_UpdateRes1(TestPQADSim* P,TestResults* Res,int Ret);

int TestPQADSim_UpdateRes2(TestPQADSim* P,TestResults* Res,void* Ret);

void TestPQADSim_Dispose(TestPQADSim* P);
