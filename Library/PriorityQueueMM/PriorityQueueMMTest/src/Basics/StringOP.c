#include "StringOP.h"

int StringOP_IsEmpty(char* s){
    if(s == NULL){return 1;}
    return (s[0] == '\0');
}

char* StringOP_Empty(void){
    char* res = (char*)malloc(sizeof(char));
    if(res == NULL){return NULL;}
    res[0] = '\0';
    return res;
}

char* StringOP_Concat(char* s1, char* s2){
    int i = 0;
    char c = '0';
    int NoError = 1;
    Stringbuilder* sb = Stringbuilder_Create();
    if(!StringOP_IsEmpty(s1)){
        i = 0;
        while(1){
            c = s1[i];
            if(c == '\0'){break;}
            if(!Stringbuilder_AddLetter(sb,c)){goto ERR;}
            i = i + 1;
        }
    }
    if(!StringOP_IsEmpty(s2)){
        i = 0;
        while(1){
            c = s2[i];
            if(c == '\0'){break;}
            if(!Stringbuilder_AddLetter(sb,c)){goto ERR;}
            i = i + 1;
        }
    }
    #ifndef STRINGBUILDER_NEW
    char* res = Stringbuilder_CreateString(sb);
    Stringbuilder_Dispose(sb);
    #else
    char * res = Stringbuilder_CreateStringDisposing(sb);
    #endif // STRINGBUILDER_NEW

    return res;
ERR:
    Stringbuilder_Dispose(sb);
    return NULL;
}

char* StringOP_ConcatR(char* s1, char* s2){
    if((s1 != NULL)&&(s2 != NULL)){
        char* res = StringOP_Concat(s1,s2);
        free((void*)s1);free((void*)s2);
        return res;
    }else{
        if(s1 != NULL){free((void*)s1);}
        if(s2 != NULL){free((void*)s2);}
        return NULL;
    }
}

char* StringOP_ConcatR1(char* s1, char* s2){
    if((s1 != NULL)&&(s2 != NULL)){
        char* res = StringOP_Concat(s1,s2);
        free((void*)s1);
        return res;
    }else{
        if(s1 != NULL){free((void*)s1);}
        return NULL;
    }
}

char* StringOP_ConcatR2(char* s1, char* s2){
    if((s1 != NULL)&&(s2 != NULL)){
        char* res = StringOP_Concat(s1,s2);
        free((void*)s2);
        return res;
    }else{
        if(s2 != NULL){free((void*)s2);}
        return NULL;
    }
}

char* StringOP_Substring(char* s, int index){
    int i = 0;
    char * res = NULL;
    if(index < -1){return NULL;}
    if(StringOP_IsEmpty(s)){return StringOP_Empty();}
    Stringbuilder* sb = Stringbuilder_Create();
    while(1){
        if(s[i] == '\0'){break;}
        if((i >= index)&&(!Stringbuilder_AddLetter(sb,s[i]))){goto ERR;}
        i = i + 1;
    }
    if(i < index){goto ERR;}
    #ifndef STRINGBUILDER_NEW
    if(i >= index){res = Stringbuilder_CreateString(sb);}
    Stringbuilder_Dispose(sb);
    #else
    if(i >= index){
        res = Stringbuilder_CreateStringDisposing(sb);
    }else{
        Stringbuilder_Dispose(sb);
    }
    #endif // STRINGBUILDER_NEW
    return res;
ERR:
    Stringbuilder_Dispose(sb);
    return NULL;
}

char* StringOP_SubstringR(char* s, int index){
    if(s == NULL){return NULL;}
    char* res = StringOP_Substring(s,index);
    free((void*)s);
    return res;
}

char* StringOP_Replace(char* s,char* f,char* r){
    if((StringOP_IsEmpty(s))||(StringOP_IsEmpty(f))){return StringOP_Copy(s);}
    Stringbuilder* sb = Stringbuilder_Create();
    int rEmpty = StringOP_IsEmpty(r);
    int i = 0;
    int j;
    int fit = -1;
    while(1){
        if((fit == -1)&&(s[i] == f[0])){
            fit = i;
        }else if((fit == -1)&&(s[i] != '\0')){
            if(!Stringbuilder_AddLetter(sb,s[i])){goto ERR;}
        }
        if(fit != -1){
            if(f[i - fit] == '\0'){
                if(!rEmpty){
                    j = 0;
                    while(r[j] != '\0'){
                        if(!Stringbuilder_AddLetter(sb,r[j])){goto ERR;}
                        j++;
                    }
                }
                i--;
                fit = -1;
            }else if(s[i] != f[i - fit]){
                i = fit;
                fit = -1;
                if(!Stringbuilder_AddLetter(sb,s[i])){goto ERR;}
            }
        }
        if(s[i] == '\0'){break;}
        i = i + 1;
    }
    #ifndef STRINGBUILDER_NEW
    char * res = Stringbuilder_CreateString(sb);
    Stringbuilder_Dispose(sb);
    #else
    char * res = Stringbuilder_CreateStringDisposing(sb);
    #endif // STRINGBUILDER_NEW
    return res;
ERR:
    Stringbuilder_Dispose(sb);
    return NULL;
}

char* StringOP_ReplaceR(char* s,char* f,char* r){
    if((s == NULL)||(f == NULL)||(r == NULL)){
        if(s != NULL){free((void*)s);}
        if(f != NULL){free((void*)f);}
        if(r != NULL){free((void*)r);}
        return NULL;
    }
    char* res = StringOP_Replace(s,f,r);
    free((void*)s);free((void*)f);free((void*)r);
    return res;
}

char* StringOP_ReplaceR1(char* s,char* f,char* r){
    if((s == NULL)||(f == NULL)||(r == NULL)){
        if(s != NULL){free((void*)s);}
        return NULL;
    }
    char* res = StringOP_Replace(s,f,r);
    free((void*)s);
    return res;
}

char* StringOP_ReplaceR2(char* s,char* f,char* r){
    if((s == NULL)||(f == NULL)||(r == NULL)){
        if(f != NULL){free((void*)f);}
        return NULL;
    }
    char* res = StringOP_Replace(s,f,r);
    free((void*)f);
    return res;
}

char* StringOP_ReplaceR3(char* s,char* f,char* r){
    if((s == NULL)||(f == NULL)||(r == NULL)){
        if(r != NULL){free((void*)r);}
        return NULL;
    }
    char* res = StringOP_Replace(s,f,r);
    free((void*)r);
    return res;
}

char* StringOP_ReplaceR12(char* s,char* f,char* r){
    if((s == NULL)||(f == NULL)||(r == NULL)){
        if(s != NULL){free((void*)s);}
        if(f != NULL){free((void*)f);}
        return NULL;
    }
    char* res = StringOP_Replace(s,f,r);
    free((void*)s);free((void*)f);
    return res;
}

char* StringOP_ReplaceR13(char* s,char* f,char* r){
    if((s == NULL)||(f == NULL)||(r == NULL)){
        if(s != NULL){free((void*)s);}
        if(r != NULL){free((void*)r);}
        return NULL;
    }
    char* res = StringOP_Replace(s,f,r);
    free((void*)s);free((void*)r);
    return res;
}

char* StringOP_ReplaceR23(char* s,char* f,char* r){
    if((s == NULL)||(f == NULL)||(r == NULL)){
        if(f != NULL){free((void*)f);}
        if(r != NULL){free((void*)r);}
        return NULL;
    }
    char* res = StringOP_Replace(s,f,r);
    free((void*)f);free((void*)r);
    return res;
}

char* StringOP_Remove(char* s, int index){
    int i = 0;
    char * res = NULL;
    if(index < -1){return NULL;}
    if(StringOP_IsEmpty(s)){return StringOP_Empty();}
    Stringbuilder* sb = Stringbuilder_Create();
    while(1){
        if((s[i] == '\0')||(i >= index)){break;}
        if(!Stringbuilder_AddLetter(sb,s[i])){goto ERR;}
        i = i + 1;
    }
    if(i == 0){
        Stringbuilder_Dispose(sb);
        return StringOP_Empty();
    }
    #ifndef STRINGBUILDER_NEW
    if(i > 0){res = Stringbuilder_CreateString(sb);}
    Stringbuilder_Dispose(sb);
    #else
    if(i > 0){
        res = Stringbuilder_CreateStringDisposing(sb);
    }else{
        Stringbuilder_Dispose(sb);
    }
    #endif // STRINGBUILDER_NEW
    return res;
ERR:
    Stringbuilder_Dispose(sb);
    return NULL;
}

char* StringOP_RemoveR(char* s, int index){
    if(s == NULL){return NULL;}
    char* res = StringOP_Remove(s,index);
    free((void*)s);
    return res;
}

char* StringOP_RemoveRange(char* s, int index, int length){
    int i = 0;
    char * res = NULL;
    if(index < -1){return NULL;}
    if(StringOP_IsEmpty(s)){return StringOP_Empty();}
    Stringbuilder* sb = Stringbuilder_Create();
    int notempty = 0;
    while(1){
        if(s[i] == '\0'){break;}
        if((i < index)||(i >= index + length)){
            if(!Stringbuilder_AddLetter(sb,s[i])){goto ERR;}
            notempty = 1;
        }
        i = i + 1;
    }
    if(!notempty){
        Stringbuilder_Dispose(sb);
        return StringOP_Empty();
    }
    #ifndef STRINGBUILDER_NEW
    if(notempty){res = Stringbuilder_CreateString(sb);}
    Stringbuilder_Dispose(sb);
    #else
    if(notempty){
        res = Stringbuilder_CreateStringDisposing(sb);
    }else{
        Stringbuilder_Dispose(sb);
    }
    #endif // STRINGBUILDER_NEW

    return res;
ERR:
    Stringbuilder_Dispose(sb);
    return NULL;
}

char* StringOP_RemoveRangeR(char* s, int index, int length){
    if(s == NULL){return NULL;}
    char* res = StringOP_RemoveRange(s,index,length);
    free((void*)s);
    return res;
}

char* StringOP_Copy(char* s){
    int i = 0;
    char c = '0';
    char * res = NULL;
    if(StringOP_IsEmpty(s)){
        if(s == NULL){return NULL;}
        return StringOP_Empty();
    }
    Stringbuilder* sb = Stringbuilder_Create();
    i = 0;
    while(1){
        c = s[i];
        if(c == '\0'){break;}
        if(!Stringbuilder_AddLetter(sb,c)){goto ERR;}
        i = i + 1;
    }
    #ifndef STRINGBUILDER_NEW
    res = Stringbuilder_CreateString(sb);
    Stringbuilder_Dispose(sb);
    #else
    res = Stringbuilder_CreateStringDisposing(sb);
    #endif // STRINGBUILDER_NEW

    return res;
ERR:
    Stringbuilder_Dispose(sb);
    return NULL;
}

char* StringOP_IntToString(int v){
    return StringOP_LongToString((long long)v);
}

char* StringOP_LongToString(long long v){
    Stringbuilder* sb = Stringbuilder_Create();
    char* res = NULL;
    int MaxIndex = 29;
    int Index = 0;
    int CurIndex;
    char Letters[MaxIndex + 1];
    long long v2 = v;
    if(v == 0){
        if(!Stringbuilder_AddLetter(sb,'0')){goto ERR;}
        #ifndef STRINGBUILDER_NEW
        res = Stringbuilder_CreateString(sb);
        Stringbuilder_Dispose(sb);
        #else
        res = Stringbuilder_CreateStringDisposing(sb);
        #endif // STRINGBUILDER_NEW
        return res;
    }
    if(v2 < 0ll){v2 = -v2;}
    while(v2 > 0ll){
        CurIndex = MaxIndex - Index;
        Letters[CurIndex] = (char)(v2 % 10ll);
        v2 = v2 - (long long)(Letters[CurIndex]);
        v2 = v2 / 10ll;
        Index++;
        Letters[CurIndex] = Letters[CurIndex] + ((char)48);
    }
    int i;
    if((v < 0)&&(!Stringbuilder_AddLetter(sb,'-'))){goto ERR;}
    CurIndex = MaxIndex - Index + 1;
    for(i = CurIndex;i <= MaxIndex;i++){
        if(!Stringbuilder_AddLetter(sb,Letters[i])){goto ERR;}
    }
    #ifndef STRINGBUILDER_NEW
    res = Stringbuilder_CreateString(sb);
    Stringbuilder_Dispose(sb);
    #else
    res = Stringbuilder_CreateStringDisposing(sb);
    #endif // STRINGBUILDER_NEW
    return res;
ERR:
    Stringbuilder_Dispose(sb);
    return NULL;
}

char* StringOP_UnsignedLongToString(unsigned long long v){
    Stringbuilder* sb = Stringbuilder_Create();
    char* res = NULL;
    int MaxIndex = 29;
    int Index = 0;
    int CurIndex;
    char Letters[MaxIndex + 1];
    if(v == 0){
        if(!Stringbuilder_AddLetter(sb,'0')){goto ERR;}
        #ifndef STRINGBUILDER_NEW
        res = Stringbuilder_CreateString(sb);
        Stringbuilder_Dispose(sb);
        #else
        res = Stringbuilder_CreateStringDisposing(sb);
        #endif // STRINGBUILDER_NEW
        return res;
    }
    unsigned long long v2 = v;
    while(v2 > 0ull){
        CurIndex = MaxIndex - Index;
        Letters[CurIndex] = (char)(v2 % 10ull);
        v2 = v2 - (unsigned long long)(Letters[CurIndex]);
        v2 = v2 / 10ull;
        Index++;
        Letters[CurIndex] = Letters[CurIndex] + ((char)48);
    }
    int i;
    CurIndex = MaxIndex - Index + 1;
    for(i = CurIndex;i <= MaxIndex;i++){
        if(!Stringbuilder_AddLetter(sb,Letters[i])){goto ERR;}
    }
    #ifndef STRINGBUILDER_NEW
    res = Stringbuilder_CreateString(sb);
    Stringbuilder_Dispose(sb);
    #else
    res = Stringbuilder_CreateStringDisposing(sb);
    #endif // STRINGBUILDER_NEW
    return res;
ERR:
    Stringbuilder_Dispose(sb);
    return NULL;
}

char* StringOP_DoubleToString(double v){
    int p1 = (int)v;
    char* part1 = StringOP_IntToString(p1);
    if(part1 == NULL){return NULL;}
    double v0 = v - ((double)p1);
    if(v0 < 0.0){v0 = v0 * -1.0;}

    Stringbuilder* sb = Stringbuilder_Create();
    if(!Stringbuilder_AddLetter(sb,'.')){goto ERR;}
    char* part2 = NULL;
    char* res = NULL;
    if(v0 == 0.0){
        if(!Stringbuilder_AddLetter(sb,'0')){goto ERR;}
        #ifndef STRINGBUILDER_NEW
        part2 = Stringbuilder_CreateString(sb);
        Stringbuilder_Dispose(sb);
        #else
        part2 = Stringbuilder_CreateStringDisposing(sb);
        #endif // STRINGBUILDER_NEW
        res = StringOP_ConcatR(part1,part2);
        return res;
    }
    int digitcounter = 0;
    int v2;
    char Letter;
    while((v0 > 0.0)&&(digitcounter < 10)){
        v0 = v0 * 10.0;
        v2 = (int)v0;
        Letter = (char)(v2 + 48);
        if(!Stringbuilder_AddLetter(sb,Letter)){goto ERR;}
        v0 = v0 - ((double)v2);
        digitcounter++;
    }
    #ifndef STRINGBUILDER_NEW
    part2 = Stringbuilder_CreateString(sb);
    Stringbuilder_Dispose(sb);
    #else
    part2 = Stringbuilder_CreateStringDisposing(sb);
    #endif // STRINGBUILDER_NEW
    res = StringOP_ConcatR(part1,part2);
    return res;
ERR:
    Stringbuilder_Dispose(sb);
    free((void*)part1);
    return NULL;
}

char* StringOP_PointerToString(void* v){
    if(v == NULL){return StringOP_Copy("NULL\0");}

    Stringbuilder* sb = Stringbuilder_Create();
    if(!Stringbuilder_AddLetter(sb,'0')){goto ERR;}
    if(!Stringbuilder_AddLetter(sb,'x')){goto ERR;}

    int PtrLength = sizeof(void*);
    uintptr_t PtrValue = (uintptr_t)v;
    int MaxIndex = PtrLength - 1;
    uint8_t CurByte;
    uint8_t CurHexaDec;
    int i;
    int IgnoreZeroes = 1;
    char c;
    for(i = 0;i < PtrLength;i++){
        CurByte = (uint8_t)((PtrValue >> ((MaxIndex - i) << 3)) & 255);
        CurHexaDec = CurByte >> 4;
        if(!((CurHexaDec == 0)&&(IgnoreZeroes))){
            IgnoreZeroes = 0;
            c = (char)(48 + CurHexaDec);
            if(CurHexaDec > 9){c = (char)(87 + CurHexaDec);}
            if(!Stringbuilder_AddLetter(sb,c)){goto ERR;}
        }
        CurHexaDec = CurByte & 15;
        if(!((CurHexaDec == 0)&&(IgnoreZeroes))){
            IgnoreZeroes = 0;
            c = (char)(48 + CurHexaDec);
            if(CurHexaDec > 9){c = (char)(87 + CurHexaDec);}
            if(!Stringbuilder_AddLetter(sb,c)){goto ERR;}
        }
    }
    return Stringbuilder_CreateStringDisposing(sb);

    ERR:
    Stringbuilder_Dispose(sb);
    return NULL;
}

int StringOP_IndexOf(char* s1, char* s2){
    if((StringOP_IsEmpty(s1))||(StringOP_IsEmpty(s2))){return -1;}
    int res = -1;
    int i = 0;
    int fit = -1;
    while(1){
        if((fit == -1)&&(s1[i] == s2[0])){
            fit = i;
        }
        if(fit != -1){
            if(s2[i - fit] == '\0'){
                res = fit;
                break;
            }
            if(s1[i] != s2[i - fit]){
                i = fit;
                fit = -1;
                res = -1;
            }
        }
        if(s1[i] == '\0'){break;}
        i = i + 1;
    }
    return res;
}

int StringOP_IndexOfR(char* s1, char* s2){
    if((s1 == NULL)||(s2 == NULL)){
        if(s1 != NULL){free((void*)s1);}
        if(s2 != NULL){free((void*)s2);}
        return ((int)(~((~(0u)) >> 2u)));
    }
    int res = StringOP_IndexOf(s1,s2);
    free((void*)s1);free((void*)s2);
    return res;
}

int StringOP_IndexOfR1(char* s1, char* s2){
    if((s1 == NULL)||(s2 == NULL)){
        if(s2 != NULL){free((void*)s2);}
        return ((int)(~((~(0u)) >> 2u)));
    }
    int res = StringOP_IndexOf(s1,s2);
    free((void*)s1);
    return res;
}

int StringOP_IndexOfR2(char* s1, char* s2){
    if((s1 == NULL)||(s2 == NULL)){
        if(s2 != NULL){free((void*)s2);}
        return ((int)(~((~(0u)) >> 2u)));
    }
    int res = StringOP_IndexOf(s1,s2);
    free((void*)s2);
    return res;
}

int StringOP_LastIndexOf(char* s1, char* s2){
    if((StringOP_IsEmpty(s1))||(StringOP_IsEmpty(s2))){return -1;}
    int res = -1;
    int i = 0;
    int fit = -1;
    while(1){
        if((fit == -1)&&(s1[i] == s2[0])){
            fit = i;
        }
        if(fit != -1){
            if(s2[i - fit] == '\0'){
                res = fit;
                i = fit;
                fit = -1;
            }else if(s1[i] != s2[i - fit]){
                i = fit;
                fit = -1;
            }
        }
        if(s1[i] == '\0'){break;}
        i = i + 1;
    }
    return res;
}

int StringOP_LastIndexOfR(char* s1, char* s2){
    if((s1 == NULL)||(s2 == NULL)){
        if(s1 != NULL){free((void*)s1);}
        if(s2 != NULL){free((void*)s2);}
        return ((int)(~((~(0u)) >> 2u)));
    }
    int res = StringOP_LastIndexOf(s1,s2);
    free((void*)s1);free((void*)s2);
    return res;
}

int StringOP_LastIndexOfR1(char* s1, char* s2){
    if((s1 == NULL)||(s2 == NULL)){
        if(s1 != NULL){free((void*)s1);}
        return ((int)(~((~(0u)) >> 2u)));
    }
    int res = StringOP_LastIndexOf(s1,s2);
    free((void*)s1);
    return res;
}

int StringOP_LastIndexOfR2(char* s1, char* s2){
    if((s1 == NULL)||(s2 == NULL)){
        if(s2 != NULL){free((void*)s2);}
        return ((int)(~((~(0u)) >> 2u)));
    }
    int res = StringOP_LastIndexOf(s1,s2);
    free((void*)s2);
    return res;
}

int StringOP_Length(char* s){
    if(s == NULL){return 0;}
    int res = 0;
    while(1){
        if(s[res] == '\0'){return res;}
        res = res + 1;
    }
}

long long StringOP_ToInt(char* s){
    if(StringOP_IsEmpty(s)){return 0;}
    long long res = 0;
    int isNegative = 0;
    int numberstarted = 0;
    char c;
    int i = 0;
    while(1){
        if((s[i] >= 48)&&(s[i] <= 57)){
            numberstarted = 1;
            res = res * 10ll;
            res = res + (long long)((int)(s[i] - 48));
        }else{
            if((numberstarted)||(s[i] == '\0')||(s[i] == '\n')){break;}
            if((isNegative)&&(!numberstarted)&&(s[i] != ' ')){isNegative = 0;}
            if(s[i] == '-'){isNegative = 1;}
        }
        i = i + 1;
    }
    if(isNegative){res = -res;}
    return res;
}

long long StringOP_ToIntR(char* s){
    long long res = StringOP_ToInt(s);
    free((void*)s);
    return res;
}

double StringOP_ToDouble(char* s){
    if(StringOP_IsEmpty(s)){return 0.0;}
    long double res = 0.0;
    long double t = 1.0;
    int isNegative = 0;
    int numberstarted = 0;
    int teiler = 0;
    char c;
    int i = 0;
    while(1){
        if((s[i] >= 48)&&(s[i] <= 57)){
            numberstarted = 1;
            res = res * 10.0;
            res = res + (long double)((int)(s[i] - 48));
            if(teiler){t = t * 10.0;}
        }else{
            if(((numberstarted)&&((s[i] != '.')&&(s[i] != ',')&&(!teiler)))||(s[i] == '\0')||(s[i] == '\n')){break;}
            if((numberstarted)&&(!teiler)&&((s[i] == '.')||(s[i] == ','))){teiler = 1;}
            if((isNegative)&&(!numberstarted)&&(s[i] != ' ')){isNegative = 0;}
            if(s[i] == '-'){isNegative = 1;}
        }
        i = i + 1;
    }
    if(teiler){res = res / t;}
    double res2 = (double)res;
    if(isNegative){res2 = res2 * -1.0;}
    return res2;
}

double StringOP_ToDoubleR(char* s){
    double res = StringOP_ToDouble(s);
    free((void*)s);
    return res;
}

int StringOP_Compare(char* s1, char* s2){
    if((s1 == NULL)&&(s2 == NULL)){return 0;}
    if((s1 != NULL)&&(s2 == NULL)){return -1;}
    if((s1 == NULL)&&(s2 != NULL)){return 1;}
    int i = 0;
    while(1){
        if((s1[i] == '\0')&&(s2[i] == '\0')){return 0;}
        if((s1[i] != '\0')&&(s2[i] == '\0')){return -1;}
        if((s1[i] == '\0')&&(s2[i] != '\0')){return 1;}
        if(s1[i] > s2[i]){return -1;}
        if(s1[i] < s2[i]){return 1;}
        i = i + 1;
    }
}

char* StringOP_Center(char* s,int Length,char Filler){
    if((s == NULL)||(Length <= 0)||(Filler == '\0')){return NULL;}
    int OriginalLength = StringOP_Length(s);
    if(OriginalLength > Length){return NULL;}
    if(OriginalLength == Length){return StringOP_Copy(s);}
    char* res = (char*)malloc(sizeof(char) * (Length + 1));
    if(res == NULL){return NULL;}
    int i;
    res[Length] = '\0';
    if(OriginalLength <= 0){
        for(i = 0;i < Length;i++){res[i] = Filler;}
        return res;
    }
    int InsertParts = (Length - OriginalLength) >> 1;
    for(i = 0;i < InsertParts;i++){
        res[i] = Filler;
        res[Length - 1 - i] = Filler;
    }

    //In case (Length - OriginalLength) % 2 != 0:
    res[Length - 2 - InsertParts] = Filler;
    res[InsertParts] = Filler;

    InsertParts++;
    for(i = 0;i < OriginalLength;i++){
        res[InsertParts + i] = s[i];
    }

    return res;
}
