#include "Stringbuilder.h"

#ifdef STRINGBUILDER_OLD

Stringbuilder* Stringbuilder_Create(){
    Stringbuilder* res = (Stringbuilder*) malloc(sizeof(Stringbuilder));
    if(res == NULL){
        printf("[ERROR] Erstellung des Stringbuilder-Objektes gescheitert!\n");
        printf("        Speicher konnte nicht reserviert werden!\n");
        return NULL;
    }
    res->FirstItem = NULL;
    res->Itemcount = 0;
    res->LastItem = NULL;
    return res;
}

int Stringbuilder_AddLetter(Stringbuilder* S, char c){
    if(S == NULL){
        printf("[ERROR] AddLetter-Operation des Stringbuilders gescheitert!\n");
        printf("        Stringbuilder nicht vorhanden!\n");
        return 0;
    }
    Stringbuilder_Item* i = (Stringbuilder_Item*) malloc(sizeof(Stringbuilder_Item));
    if(i == NULL){
        printf("[ERROR] AddLetter-Operation des Stringbuilders gescheitert!\n");
        printf("        Speicher konnte nicht reserviert werden!\n");
        return 0;
    }
    i->letter = c;
    i->NextItem = NULL;
    if(S->Itemcount == 0){
        S->FirstItem = i;
        S->LastItem = i;
        S->Itemcount = 1;
    }else{
        S->LastItem->NextItem = i;
        S->Itemcount = S->Itemcount + 1;
        S->LastItem = i;
    }
    return 1;
}
char * Stringbuilder_CreateString(Stringbuilder* S){
    if(S == NULL){
        printf("[ERROR] CreateString-Operation des Stringbuilders gescheitert!\n");
        printf("        Stringbuilder nicht vorhanden!\n");
        return NULL;
    }
    if(S->Itemcount <= 0){
        printf("[ERROR] CreateString-Operation des Stringbuilders gescheitert!\n");
        printf("        Stringbuilder leer!\n");
        return NULL;
    }
    char * res = (char*) malloc((S->Itemcount + 1) * sizeof(char));
    if(res == NULL){
        printf("[ERROR] CreateString-Operation des Stringbuilders gescheitert!\n");
        printf("        Speicher fuer String konnte nicht reserviert werden!\n");
        return NULL;
    }
    Stringbuilder_Item* CurrentItem = NULL;
    int i = 0;
    for(i = 0;i < S->Itemcount;i++){
        if(i == 0){
            CurrentItem = S->FirstItem;
        }else{
            CurrentItem = CurrentItem->NextItem;
        }
        res[i] = CurrentItem->letter;
    }
    res[S->Itemcount] = '\0';
    return res;
}

void Stringbuilder_Dispose(Stringbuilder* S){
    if(S != NULL){
        if(S->Itemcount != 0){
            Stringbuilder_Item* CurrentItem = S->FirstItem;
            Stringbuilder_Item* NextItem = NULL;
            while(CurrentItem != NULL){
                NextItem = CurrentItem->NextItem;
                free((void*)CurrentItem);
                CurrentItem = NULL;
                CurrentItem = NextItem;
            }
        }
        free((void*)S);
        S = NULL;
    }
}

#else

static int Stringbuilder_Item_Count = 0;

Stringbuilder* Stringbuilder_Create(){
    Stringbuilder* res = (Stringbuilder*)malloc(sizeof(Stringbuilder));
    if(res == NULL){
        printf("[ERROR] Creation of \"Stringbuilder\"-object failed!\n");
        printf("        Memory could not be allocated!\n");
        return NULL;
    }
    if(!Stringbuilder_Item_Count){
        Stringbuilder_Item_Count = (int)((64 - sizeof(Stringbuilder_Item)) / sizeof(char));
        if(Stringbuilder_Item_Count == 0){
            printf("[ERROR] Creation of \"Stringbuilder\"-object failed!\n");
            printf("        \"Stringbuilder_Item_Count\" could not be initialized!\n");
            free((void*)res);
            return NULL;
        }
    }
    res->FirstItem = NULL;
    res->Itemcount = 0;
    res->LastItem = NULL;
    return res;
}

int Stringbuilder_AddLetter(Stringbuilder* S, char c){
    if(S == NULL){
        printf("[ERROR] \"Stringbuilder_AddLetter\"-function failed!\n");
        printf("        Stringbuilder is not available!\n");
        return 0;
    }
    int index;
    if(index = (S->Itemcount % Stringbuilder_Item_Count)){
        S->LastItem->letter[index] = c;
        S->Itemcount++;
        return 1;
    }
    if(S->FirstItem == NULL){
        S->FirstItem = (Stringbuilder_Item*)malloc(sizeof(Stringbuilder_Item) + Stringbuilder_Item_Count * sizeof(char));
        if(S->FirstItem == NULL){
            printf("[ERROR] \"Stringbuilder_AddLetter\"-function failed!\n");
            printf("        Allocation of \"Stringbuilder_Item\"-Object failed!\n");
            return 0;
        }
        S->LastItem = S->FirstItem;
    }else{
        S->LastItem->NextItem = (Stringbuilder_Item*)malloc(sizeof(Stringbuilder_Item) + Stringbuilder_Item_Count * sizeof(char));
        if(S->LastItem->NextItem == NULL){
            printf("[ERROR] \"Stringbuilder_AddLetter\"-function failed!\n");
            printf("        Allocation of \"Stringbuilder_Item\"-Object failed!\n");
            return 0;
        }
        S->LastItem = S->LastItem->NextItem;
    }
    S->LastItem->NextItem = NULL;
    S->LastItem->letter[0] = c;
    S->Itemcount++;
    return 1;
}

char* Stringbuilder_CreateString(Stringbuilder* S){
    if(S == NULL){
        printf("[ERROR] \"Stringbuilder_CreateString\"-function failed!\n");
        printf("        Stringbuilder is not available!\n");
        return NULL;
    }
    char* res;
    if(S->Itemcount <= 0){
        res = (char*)malloc(sizeof(char));
        if(res == NULL){
            printf("[ERROR] \"Stringbuilder_CreateString\"-function failed!\n");
            printf("        Memory could not be allocated!\n");
            return NULL;
        }
        res[0] = '\0';
        return res;
    }
    res = (char*)malloc(sizeof(char) * (S->Itemcount + 1));
    if(res == NULL){
        printf("[ERROR] \"Stringbuilder_CreateString\"-function failed!\n");
        printf("        Memory could not be allocated!\n");
        return NULL;
    }
    Stringbuilder_Item* CurItem = S->FirstItem;
    int TotalIndex = 0;
    int i;
    while(CurItem->NextItem != NULL){
        memcpy(((void*)(&(res[TotalIndex]))),((void*)(&(CurItem->letter[0]))),Stringbuilder_Item_Count);
        TotalIndex += Stringbuilder_Item_Count;
        CurItem = CurItem->NextItem;
    }
    int MaxIndex = S->Itemcount - TotalIndex;
    memcpy(((void*)(&(res[TotalIndex]))),((void*)(&(CurItem->letter[0]))),MaxIndex);
    res[S->Itemcount] = '\0';
    return res;
}


char* Stringbuilder_CreateStringDisposing(Stringbuilder* S){
    if(S == NULL){
        printf("[ERROR] \"Stringbuilder_CreateStringDisposing\"-function failed!\n");
        printf("        Stringbuilder is not available!\n");
        return NULL;
    }
    char* res;
    if(S->Itemcount <= 0){
        res = (char*)malloc(sizeof(char));
        if(res == NULL){
            printf("[ERROR] \"Stringbuilder_CreateStringDisposing\"-function failed!\n");
            printf("        Memory could not be allocated!\n");
            return NULL;
        }
        res[0] = '\0';
        free((void*)S);
        return res;
    }
    res = (char*)malloc(sizeof(char) * (S->Itemcount + 1));
    if(res == NULL){
        printf("[ERROR] \"Stringbuilder_CreateStringDisposing\"-function failed!\n");
        printf("        Memory could not be allocated!\n");
        return NULL;
    }
    Stringbuilder_Item* CurItem = S->FirstItem;
    Stringbuilder_Item* LstItem = NULL;
    int TotalIndex = 0;
    int i;
    while(CurItem->NextItem != NULL){
        memcpy(((void*)(&(res[TotalIndex]))),((void*)(&(CurItem->letter[0]))),Stringbuilder_Item_Count);
        TotalIndex += Stringbuilder_Item_Count;
        LstItem = CurItem;
        CurItem = CurItem->NextItem;
        free((void*)LstItem);
    }
    int MaxIndex = S->Itemcount - TotalIndex;
    memcpy(((void*)(&(res[TotalIndex]))),((void*)(&(CurItem->letter[0]))),MaxIndex);
    free((void*)CurItem);
    res[S->Itemcount] = '\0';
    free((void*)S);
    return res;
}


void Stringbuilder_Dispose(Stringbuilder* S){
    if(S == NULL){return;}
    if(S->Itemcount > 0){
        Stringbuilder_Item* CurrentItem = S->FirstItem;
        Stringbuilder_Item* NextItem = NULL;
        while(CurrentItem != NULL){
            NextItem = CurrentItem->NextItem;
            free((void*)CurrentItem);
            CurrentItem = NULL;
            CurrentItem = NextItem;
        }
    }
    free((void*)S);
}

#endif //STRINGBUILDER_OLD
