#include "TestResults.h"

int TestResults_IsDispItemNULL = 1;
int TestResults_DispItem = -1;

int TestResults_SetFromPQ1(TestResults* R,PriorityQueueMM* P,int Res){
    if((R == NULL)||(P == NULL)){return 0;}
    R->Res.RetPtr = NULL;
    R->Res.RetInt = Res;

    R->Count = PriorityQueueMM_GetCount(P,NULL);
    R->IsFixedSize = PriorityQueueMM_HasFixedSize(P,NULL);
    R->IsMaxNULL = (PriorityQueueMM_GetMax(P,NULL) == NULL);
    R->IsMinNULL = (PriorityQueueMM_GetMin(P,NULL) == NULL);
    R->IsDispItemNULL = TestResults_IsDispItemNULL;
    R->ReservedItems = PriorityQueueMM_GetReservedItems(P,NULL);
    R->ReservedMemory = PriorityQueueMM_GetReservedMemory(P,NULL);

    R->Min = -1;
    R->Max = -1;
    R->DispItem = -1;

    if(!R->IsMaxNULL){R->Max = *((int*)PriorityQueueMM_GetMax(P,NULL));}
    if(!R->IsMinNULL){R->Min = *((int*)PriorityQueueMM_GetMin(P,NULL));}
    if(!R->IsDispItemNULL){R->DispItem = TestResults_DispItem;}

    TestResults_IsDispItemNULL = 1;
    TestResults_DispItem = -1;

    return 1;
}

int TestResults_SetFromPQ2(TestResults* R,PriorityQueueMM* P,void* Res){
    if((R == NULL)||(P == NULL)){return 0;}
    R->Res.RetInt = 0;
    R->Res.RetPtr = Res;

    R->Count = PriorityQueueMM_GetCount(P,NULL);
    R->IsFixedSize = PriorityQueueMM_HasFixedSize(P,NULL);
    R->IsMaxNULL = (PriorityQueueMM_GetMax(P,NULL) == NULL);
    R->IsMinNULL = (PriorityQueueMM_GetMin(P,NULL) == NULL);
    R->IsDispItemNULL = TestResults_IsDispItemNULL;
    R->ReservedItems = PriorityQueueMM_GetReservedItems(P,NULL);
    R->ReservedMemory = PriorityQueueMM_GetReservedMemory(P,NULL);

    R->Min = -1;
    R->Max = -1;
    R->DispItem = -1;

    if(!R->IsMaxNULL){R->Max = *((int*)PriorityQueueMM_GetMax(P,NULL));}
    if(!R->IsMinNULL){R->Min = *((int*)PriorityQueueMM_GetMin(P,NULL));}
    if(!R->IsDispItemNULL){R->DispItem = TestResults_DispItem;}

    TestResults_IsDispItemNULL = 1;
    TestResults_DispItem = -1;

    return 1;
}

int TestResults_Equal(TestResults* R1,TestResults* R2){
    if((R1 == NULL)||(R2 == NULL)){return -1;}
    int res = 1;
    res = res * ((!(R1->IsFixedSize)) == (!(R2->IsFixedSize)));
    if(R1->IsFixedSize | R2->IsFixedSize){
        res = res * (R1->ReservedMemory == R2->ReservedMemory);
        res = res * (R1->ReservedItems == R2->ReservedItems);
    }
    if(!res){return 0;}
    res = res * (R1->Count == R2->Count);
    res = res * ((R1->Res.RetInt == R2->Res.RetInt)&&(R1->Res.RetPtr == R2->Res.RetPtr));
    res = res * ((!(R1->IsMaxNULL)) == (!(R2->IsMaxNULL)));
    res = res * ((!(R1->IsMinNULL)) == (!(R2->IsMinNULL)));
    res = res * ((!(R1->IsDispItemNULL)) == (!(R2->IsDispItemNULL)));
    if(!res){return 0;}
    if(!R1->IsMaxNULL){res = res * (R1->Max == R2->Max);}
    if(!R1->IsMinNULL){res = res * (R1->Min == R2->Min);}
    if(!R1->IsDispItemNULL){res = res * (R1->DispItem == R2->DispItem);}
    return res;
}

char* TestResults_Size_ToString(TestResults* R){
    if(R == NULL){return NULL;}
    return StringOP_ConcatR(StringOP_Copy("Size:\0"),StringOP_LongToString(((long long)R->ReservedMemory)));
}
char* TestResults_MaxItems_ToString(TestResults* R){
    if(R == NULL){return NULL;}
    return StringOP_ConcatR(StringOP_Copy("MaxItems:\0"),StringOP_LongToString(((long long)R->ReservedItems)));
}
char* TestResults_IsFixedSize_ToString(TestResults* R){
    if(R == NULL){return NULL;}
    if(R->IsFixedSize){return StringOP_Copy("FixedSize:TRUE\0");}
    return StringOP_Copy("FixedSize:FALSE\0");
}
char* TestResults_Count_ToString(TestResults* R){
    if(R == NULL){return NULL;}
    return StringOP_ConcatR(StringOP_Copy("Count:\0"),StringOP_LongToString(((long long)R->Count)));
}
char* TestResults_Max_ToString(TestResults* R){
    if(R == NULL){return NULL;}
    if(R->IsMaxNULL){return StringOP_Copy("Max:NULL\0");}
    return StringOP_ConcatR(StringOP_Copy("Max:\0"),StringOP_LongToString(((long long)R->Max)));
}
char* TestResults_Min_ToString(TestResults* R){
    if(R == NULL){return NULL;}
    if(R->IsMinNULL){return StringOP_Copy("Min:NULL\0");}
    return StringOP_ConcatR(StringOP_Copy("Min:\0"),StringOP_LongToString(((long long)R->Min)));
}
char* TestResults_Dsp_ToString(TestResults* R){
    if(R == NULL){return NULL;}
    if(R->IsDispItemNULL){return StringOP_Copy("Dsp:NULL\0");}
    return StringOP_ConcatR(StringOP_Copy("Dsp:\0"),StringOP_LongToString(((long long)R->DispItem)));
}
char* TestResults_Res_ToString(TestResults* R){
    if(R == NULL){return NULL;}
    char* str_sep = StringOP_Copy(", \0");
    char* str_resint = StringOP_ConcatR(StringOP_Copy("ResInt:\0"),StringOP_LongToString(((long long)R->Res.RetInt)));
    char* str_resptr = StringOP_ConcatR(StringOP_Copy("ResPtr:\0"),StringOP_PointerToString(R->Res.RetPtr));
    return StringOP_ConcatR(StringOP_ConcatR(str_resint,str_sep),str_resptr);
}

char* TestResults_ToString(TestResults* R){
    if(R == NULL){return NULL;}
    char* str_sep = StringOP_Copy(", \0");
    char* str_head = StringOP_ConcatR(StringOP_ConcatR(StringOP_ConcatR1(TestResults_Size_ToString(R),str_sep),
                                                       StringOP_ConcatR1(TestResults_MaxItems_ToString(R),str_sep)),
                                      StringOP_ConcatR(StringOP_ConcatR1(TestResults_IsFixedSize_ToString(R),str_sep),
                                                       StringOP_ConcatR1(TestResults_Count_ToString(R),str_sep)));

    char* str_elem = StringOP_ConcatR(StringOP_ConcatR(StringOP_ConcatR1(TestResults_Min_ToString(R),str_sep),
                                                       StringOP_ConcatR1(TestResults_Max_ToString(R),str_sep)),
                                      StringOP_ConcatR(StringOP_ConcatR1(TestResults_Dsp_ToString(R),str_sep),
                                                       TestResults_Res_ToString(R)));

    char* str_cont = StringOP_ConcatR(str_head,str_elem);

    free((void*)str_sep);

    return StringOP_ConcatR(StringOP_ConcatR(StringOP_Copy("TestResults[\0"),str_cont),StringOP_Copy("]\0"));
}

int TestResults_DiffToStrings(TestResults* R1,TestResults* R2,char** s1,char** s2){
    if((R1 == NULL)||(R2 == NULL)||(s1 == NULL)||(s2 == NULL)){return 0;}
    if(TestResults_Equal(R1,R2) != 0){return 0;}
    char* res1 = NULL;
    char* res2 = NULL;

    char* str_sep = StringOP_Copy(", \0");

    if(R1->IsFixedSize | R2->IsFixedSize){
        if(R1->ReservedMemory != R2->ReservedMemory){
            res1 = TestResults_Size_ToString(R1);
            res2 = TestResults_Size_ToString(R2);
        }

        if(R1->ReservedItems != R2->ReservedItems){
            if(res1 == NULL){
                res1 = TestResults_MaxItems_ToString(R1);
            }else{
                res1 = StringOP_ConcatR(StringOP_ConcatR1(res1,str_sep),TestResults_MaxItems_ToString(R1));
            }

            if(res2 == NULL){
                res2 = TestResults_MaxItems_ToString(R2);
            }else{
                res2 = StringOP_ConcatR(StringOP_ConcatR1(res2,str_sep),TestResults_MaxItems_ToString(R2));
            }
        }

        if((!(R1->IsFixedSize)) != (!(R2->IsFixedSize))){
            if(res1 == NULL){
                res1 = TestResults_IsFixedSize_ToString(R1);
            }else{
                res1 = StringOP_ConcatR(StringOP_ConcatR1(res1,str_sep),TestResults_IsFixedSize_ToString(R1));
            }

            if(res2 == NULL){
                res2 = TestResults_IsFixedSize_ToString(R2);
            }else{
                res2 = StringOP_ConcatR(StringOP_ConcatR1(res2,str_sep),TestResults_IsFixedSize_ToString(R2));
            }
        }
    }



    if(R1->Count != R2->Count){
        if(res1 == NULL){
            res1 = TestResults_Count_ToString(R1);
        }else{
            res1 = StringOP_ConcatR(StringOP_ConcatR1(res1,str_sep),TestResults_Count_ToString(R1));
        }

        if(res2 == NULL){
            res2 = TestResults_Count_ToString(R2);
        }else{
            res2 = StringOP_ConcatR(StringOP_ConcatR1(res2,str_sep),TestResults_Count_ToString(R2));
        }
    }

    if(!((((!(R1->IsMinNULL)) == (!(R2->IsMinNULL))))&&(R1->Min == R2->Min))){
        if(res1 == NULL){
            res1 = TestResults_Min_ToString(R1);
        }else{
            res1 = StringOP_ConcatR(StringOP_ConcatR1(res1,str_sep),TestResults_Min_ToString(R1));
        }

        if(res2 == NULL){
            res2 = TestResults_Min_ToString(R2);
        }else{
            res2 = StringOP_ConcatR(StringOP_ConcatR1(res2,str_sep),TestResults_Min_ToString(R2));
        }
    }

    if(!((((!(R1->IsMaxNULL)) == (!(R2->IsMaxNULL))))&&(R1->Max == R2->Max))){
        if(res1 == NULL){
            res1 = TestResults_Max_ToString(R1);
        }else{
            res1 = StringOP_ConcatR(StringOP_ConcatR1(res1,str_sep),TestResults_Max_ToString(R1));
        }

        if(res2 == NULL){
            res2 = TestResults_Max_ToString(R2);
        }else{
            res2 = StringOP_ConcatR(StringOP_ConcatR1(res2,str_sep),TestResults_Max_ToString(R2));
        }
    }

    if(!((((!(R1->IsDispItemNULL)) == (!(R2->IsDispItemNULL))))&&(R1->DispItem == R2->DispItem))){
        if(res1 == NULL){
            res1 = TestResults_Dsp_ToString(R1);
        }else{
            res1 = StringOP_ConcatR(StringOP_ConcatR1(res1,str_sep),TestResults_Dsp_ToString(R1));
        }

        if(res2 == NULL){
            res2 = TestResults_Dsp_ToString(R2);
        }else{
            res2 = StringOP_ConcatR(StringOP_ConcatR1(res2,str_sep),TestResults_Dsp_ToString(R2));
        }
    }

    if(!((R1->Res.RetInt == R2->Res.RetInt)&&(R1->Res.RetPtr == R2->Res.RetPtr))){
        if(res1 == NULL){
            res1 = TestResults_Res_ToString(R1);
        }else{
            res1 = StringOP_ConcatR(StringOP_ConcatR1(res1,str_sep),TestResults_Res_ToString(R1));
        }

        if(res2 == NULL){
            res2 = TestResults_Res_ToString(R2);
        }else{
            res2 = StringOP_ConcatR(StringOP_ConcatR1(res2,str_sep),TestResults_Res_ToString(R2));
        }
    }

    *s1 = StringOP_ConcatR(StringOP_ConcatR(StringOP_Copy("TestResults[\0"),res1),StringOP_Copy("]\0"));
    *s2 = StringOP_ConcatR(StringOP_ConcatR(StringOP_Copy("TestResults[\0"),res2),StringOP_Copy("]\0"));

    free((void*)str_sep);
    return 1;
}

