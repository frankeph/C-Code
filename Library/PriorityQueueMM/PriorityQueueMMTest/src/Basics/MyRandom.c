#include "MyRandom.h"

struct myrandom
{
    uint64_t Seed;
    uint64_t Counter;
    uint64_t Alpha;
    uint64_t Beta;
};

const uint64_t MyRandomPrime = 2147483647;

MyRandom* MyRandom_Create(void){
    time_t t;
    time(&t);
    return MyRandom_Create3((uint64_t)t);
}

MyRandom* MyRandom_Create2(uint32_t Seed){
    return MyRandom_Create3((uint64_t)Seed);
}

MyRandom* MyRandom_Create3(uint64_t Seed){
    struct myrandom* res = (struct myrandom*)malloc(sizeof(struct myrandom));
    if(res == NULL){
        printf("[ERROR] Creation of \"MyRandom\"-object failed!\n");
        printf("        Memory could not be allocated!\n");
        return NULL;
    }
    res->Seed = Seed;

    uint64_t Mask32 = (((uint64_t)1) << ((uint64_t)32)) - ((uint64_t)1);
    uint64_t HalfPrime = MyRandomPrime >> ((uint64_t)1);

    res->Alpha = ((res->Seed & Mask32) % HalfPrime) + HalfPrime;
    res->Beta = (res->Seed & Mask32) % MyRandomPrime;
    res->Counter = (res->Seed & (~Mask32)) >> ((uint64_t)32);

    return ((MyRandom*)res);
}

uint32_t MyRandom_GetInt(MyRandom* R){
    if(R == NULL){return 0;}
    struct myrandom* r = (struct myrandom*)R;
    r->Counter = r->Counter + ((uint64_t)1);
    uint64_t Value1 = (r->Beta + r->Counter) % MyRandomPrime;
    uint64_t Value2 = r->Counter % MyRandomPrime;
    uint64_t Value3 = (Value1 * Value2) % MyRandomPrime;
    r->Beta = (r->Alpha * Value3) % MyRandomPrime;
    return ((uint32_t)r->Beta);
}

int MyRandom_GetInt2(MyRandom* R,int Min,int Max){
    if((R == NULL)||(Min > Max)){return Min - 1;}
    uint32_t CurBeta = MyRandom_GetInt(R);
    return (Min + ((int)(CurBeta % ((uint32_t)(Max - Min + 1)))));
}

uint64_t MyRandom_GetSeed(MyRandom* R){
    if(R == NULL){return 0;}
    struct myrandom* r = (struct myrandom*)R;
    return r->Seed;
}

uint64_t MyRandom_GetCounter(MyRandom* R){
    if(R == NULL){return 0;}
    struct myrandom* r = (struct myrandom*)R;
    uint64_t Mask32 = (((uint64_t)1) << ((uint64_t)32)) - ((uint64_t)1);
    uint64_t Counter0 = (r->Seed & (~Mask32)) >> ((uint64_t)32);
    if(Counter0 > r->Counter){
        return ((~((uint64_t)0)) - Counter0) + r->Counter + ((uint64_t)1);
    }
    return r->Counter - Counter0;
}

int MyRandom_Reset(MyRandom* R){
    if(R == NULL){return 0;}
    struct myrandom* r = (struct myrandom*)R;
    uint64_t Mask32 = (((uint64_t)1) << ((uint64_t)32)) - ((uint64_t)1);
    uint64_t HalfPrime = MyRandomPrime >> ((uint64_t)1);

    r->Alpha = ((r->Seed & Mask32) % HalfPrime) + HalfPrime;
    r->Beta = (r->Seed & Mask32) % MyRandomPrime;
    r->Counter = (r->Seed & (~Mask32)) >> ((uint64_t)32);
    return 1;
}

void MyRandom_Dispose(MyRandom* R){
    if(R == NULL){return;}
    struct myrandom* r = (struct myrandom*)R;
    free((void*)r);
}
