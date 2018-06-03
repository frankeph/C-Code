#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct testitemprovider TestItemProvider;

struct testitemprovider
{
    int Count;
    int Max;
    void* Items[];
};

TestItemProvider* TestItemProvider_Create(int Max);

int TestItemProvider_GetMax(TestItemProvider* P);

int TestItemProvider_GetCount(TestItemProvider* P);

int TestItemProvider_Add(TestItemProvider* P,void* I);

void* TestItemProvider_Get(TestItemProvider* P,int Index);

int TestItemProvider_Remove(TestItemProvider* P,int Index);

void TestItemProvider_Dispose(TestItemProvider* P);


