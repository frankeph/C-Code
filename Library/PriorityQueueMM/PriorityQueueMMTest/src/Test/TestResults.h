#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef union testfuncres TestFuncRes;
typedef struct testresults TestResults;

#include "../Basics/PriorityQueueMM.h"
#include "../Basics/StringOP.h"

union testfuncres
{
    int RetInt;
    void* RetPtr;
};

struct testresults
{
    TestFuncRes Res;
    int IsFixedSize;
    int IsMaxNULL;
    int IsMinNULL;
    int IsDispItemNULL;
    int Max;
    int Min;
    int DispItem;
    int Count;
    int ReservedItems;
    size_t ReservedMemory;
};

int TestResults_SetFromPQ1(TestResults* R,PriorityQueueMM* P,int Res);

int TestResults_SetFromPQ2(TestResults* R,PriorityQueueMM* P,void* Res);

int TestResults_Equal(TestResults* R1,TestResults* R2);


char* TestResults_Size_ToString(TestResults* R);
char* TestResults_MaxItems_ToString(TestResults* R);
char* TestResults_IsFixedSize_ToString(TestResults* R);
char* TestResults_Count_ToString(TestResults* R);
char* TestResults_Max_ToString(TestResults* R);
char* TestResults_Min_ToString(TestResults* R);
char* TestResults_Dsp_ToString(TestResults* R);
char* TestResults_Res_ToString(TestResults* R);

char* TestResults_ToString(TestResults* R);

int TestResults_DiffToStrings(TestResults* R1,TestResults* R2,char** s1,char** s2);


