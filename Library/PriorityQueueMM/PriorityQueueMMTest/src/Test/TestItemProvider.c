#include "TestItemProvider.h"

TestItemProvider* TestItemProvider_Create(int Max){
    if(Max <= 0){
        printf("[ERROR] Creation of \"TestItemProvider\"-object failed!\n");
        printf("        \"Max\"-Parameter invalid!\n");
        return NULL;
    }

    TestItemProvider* res = (TestItemProvider*)malloc(sizeof(TestItemProvider) + sizeof(void*) * Max);
    if(res == NULL){
        printf("[ERROR] Creation of \"TestItemProvider\"-object failed!\n");
        printf("        Memory could not be allocated!\n");
        return NULL;
    }

    res->Count = 0;
    res->Max = Max;
    return res;
}

int TestItemProvider_GetMax(TestItemProvider* P){
    if(P == NULL){return 0;}
    return P->Max;
}

int TestItemProvider_GetCount(TestItemProvider* P){
    if(P == NULL){return 0;}
    return P->Count;
}

int TestItemProvider_Add(TestItemProvider* P,void* I){
    if(P == NULL){return 0;}
    if(P->Count >= P->Max){return 0;}
    P->Items[P->Count] = I;
    P->Count++;
    return 1;
}

void* TestItemProvider_Get(TestItemProvider* P,int Index){
    if(P == NULL){return NULL;}
    if((Index < 0)||(Index >= P->Count)){return NULL;}
    return P->Items[Index];
}

int TestItemProvider_Remove(TestItemProvider* P,int Index){
    if(P == NULL){return 0;}
    if((Index < 0)||(Index >= P->Count)){return 0;}
    P->Count--;
    if(Index == P->Count){return 1;}
    P->Items[Index] = P->Items[P->Count];
    return 1;
}

void TestItemProvider_Dispose(TestItemProvider* P){
    if(P == NULL){return;}
    free((void*)P);
}
