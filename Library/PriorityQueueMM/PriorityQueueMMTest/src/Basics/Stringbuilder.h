#pragma once
#include <stdio.h>
#ifdef STRINGBUILDER_OLD
typedef struct Stringbuilder_item Stringbuilder_Item;

struct Stringbuilder_item
{
    char letter;
    Stringbuilder_Item* NextItem;
};

typedef struct {
    int Itemcount;
    Stringbuilder_Item* FirstItem;
    Stringbuilder_Item* LastItem;
} Stringbuilder;
#else
#define STRINGBUILDER_NEW
typedef struct stringbuilder_item Stringbuilder_Item;
typedef struct stringbuilder Stringbuilder;

struct stringbuilder_item
{
    Stringbuilder_Item* NextItem;
    char letter[];
};

struct stringbuilder
{
    int Itemcount;
    Stringbuilder_Item* FirstItem;
    Stringbuilder_Item* LastItem;
};
#endif // STRINGBUILDER_OLD

Stringbuilder* Stringbuilder_Create();

int Stringbuilder_AddLetter(Stringbuilder* S, char c);

char* Stringbuilder_CreateString(Stringbuilder* S);

#ifdef STRINGBUILDER_NEW
char* Stringbuilder_CreateStringDisposing(Stringbuilder* S);
#endif // STRINGBUILDER_NEW

void Stringbuilder_Dispose(Stringbuilder* S);



