#include "PriorityQueueMM.h"

#define INCLUDE_PRIORITYQUEUEMM

#ifdef INCLUDE_PRIORITYQUEUEMM
#ifdef HIDE_ALL_MSGS
#undef PRIORITYQUEUEMM_DISP_ERRORS
#undef PRIORITYQUEUEMM_DISP_INFO
#undef PRIORITYQUEUEMM_DISP_WARNING
#endif // HIDE_ALL_MSGS


#ifndef PRIORITYQUEUEMM_DISP_INFO
    #ifdef PRIORITYQUEUEMM_REM_DEF_INFO
        #undef PRIORITYQUEUEMM_REM_DEF_INFO
    #endif // PRIORITYQUEUEMM_REM_DEF_INFO
    #ifdef PRIORITYQUEUEMM_REM_AVL_INFO
        #undef PRIORITYQUEUEMM_REM_AVL_INFO
    #endif // PRIORITYQUEUEMM_REM_AVL_INFO
    #ifdef PRIORITYQUEUEMM_REM_SDU_INFO
        #undef PRIORITYQUEUEMM_REM_SDU_INFO
    #endif // PRIORITYQUEUEMM_REM_SDU_INFO
    #ifdef PRIORITYQUEUEMM_REM_ADU_INFO
        #undef PRIORITYQUEUEMM_REM_ADU_INFO
    #endif // PRIORITYQUEUEMM_REM_ADU_INFO
    #ifdef PRIORITYQUEUEMM_REM_SEG_INFO
        #undef PRIORITYQUEUEMM_REM_SEG_INFO
    #endif // PRIORITYQUEUEMM_REM_SEG_INFO
#endif // PRIORITYQUEUEMM_DISP_INFO


#ifdef PRIORITYQUEUEMM_DISP_ERRORS
#define PRINT_ERROR(msg)    ({\
                             printf("[ERROR] Function \"%s\" (Line %i in \"PriorityQueueMM.c\") failed!\n",__FUNCTION__,__LINE__);\
                             printf("        %s\n",msg);})

#define PRINT_ERROR2(msg)   printf("        %s\n",msg)
#define PRINT_ERROR3        printf("        Function \"%s\" (Line %i in \"PriorityQueueMM.c\") failed!\n",__FUNCTION__,__LINE__)
#else // PRIORITYQUEUEMM_DISP_ERRORS
#define PRINT_ERROR(msg)    do{ }while(0)
#define PRINT_ERROR2(msg)   do{ }while(0)
#define PRINT_ERROR3        do{ }while(0)
#endif // PRIORITYQUEUEMM_DISP_ERRORS


#ifdef PRIORITYQUEUEMM_DISP_INFO
#define _PRINT_INFO(msg)     printf("[INFO] %s\n",msg)
#define _PRINT_INFO2(msg)    printf("       %s\n",msg)
#else // PRIORITYQUEUEMM_DISP_INFO
#define _PRINT_INFO(msg)     do{ }while(0)
#define _PRINT_INFO2(msg)    do{ }while(0)
#endif // PRIORITYQUEUEMM_DISP_INFO

#define PRINT_INFO(msg)     _PRINT_INFO(msg)
#define PRINT_INFO2(msg)    _PRINT_INFO2(msg)


#ifdef PRIORITYQUEUEMM_DISP_WARNING
#define PRINT_WARNING(msg)  ({\
                             printf("[WARNING] In Function \"%s\" (Line %i in \"PriorityQueueMM.c\"):\n",__FUNCTION__,__LINE__);\
                             printf("          %s\n",msg);})
#else // PRIORITYQUEUEMM_DISP_WARNING
#define PRINT_WARNING(msg)  do{ }while(0)
#endif // PRIORITYQUEUEMM_DISP_WARNING


#ifdef PRIORITYQUEUEMM_REM_DEF_INFO
#undef PRIORITYQUEUEMM_DISP_INFO
#undef PRINT_INFO
#undef PRINT_INFO2
#define PRINT_INFO(msg)     do{ }while(0)
#define PRINT_INFO2(msg)    do{ }while(0)
#endif // PRIORITYQUEUEMM_REM_DEF_INFO


#ifdef PRIORITYQUEUEMM_INHERITANCE

#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMA
static PriorityQueueMMA* _PriorityQueueMM_Get_PriorityQueueMMA_True(PriorityQueueMM* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    return ((PriorityQueueMMA*)Q);
}
#ifdef INCLUDE_S_TYPE_PRIORITYQUEUEMM
static PriorityQueueMMA* _PriorityQueueMM_Get_PriorityQueueMMA_False(PriorityQueueMM* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    return NULL;
}
#endif // INCLUDE_S_TYPE_PRIORITYQUEUEMM
#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMA


#ifdef INCLUDE_PRIORITYQUEUEMMSF
static PriorityQueueMMSF* _PriorityQueueMM_Get_PriorityQueueMMSF_True(PriorityQueueMM* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    return ((PriorityQueueMMSF*)Q);
}
#ifdef PRIORITYQUEUEMM_MULT_B_TYPE
static PriorityQueueMMSF* _PriorityQueueMM_Get_PriorityQueueMMSF_False(PriorityQueueMM* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    return NULL;
}
#endif // PRIORITYQUEUEMM_MULT_B_TYPE
#endif // INCLUDE_PRIORITYQUEUEMMSF


#ifdef INCLUDE_PRIORITYQUEUEMMAF
static PriorityQueueMMAF* _PriorityQueueMM_Get_PriorityQueueMMAF_True(PriorityQueueMM* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    return ((PriorityQueueMMAF*)Q);
}
#ifdef PRIORITYQUEUEMM_MULT_B_TYPE
static PriorityQueueMMAF* _PriorityQueueMM_Get_PriorityQueueMMAF_False(PriorityQueueMM* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    return NULL;
}
#endif // PRIORITYQUEUEMM_MULT_B_TYPE
#endif // INCLUDE_PRIORITYQUEUEMMAF


#ifdef INCLUDE_PRIORITYQUEUEMMSD
static PriorityQueueMMSD* _PriorityQueueMM_Get_PriorityQueueMMSD_True(PriorityQueueMM* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    return ((PriorityQueueMMSD*)Q);
}
#ifdef PRIORITYQUEUEMM_MULT_B_TYPE
static PriorityQueueMMSD* _PriorityQueueMM_Get_PriorityQueueMMSD_False(PriorityQueueMM* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    return NULL;
}
#endif // PRIORITYQUEUEMM_MULT_B_TYPE
#endif // INCLUDE_PRIORITYQUEUEMMSD


#ifdef INCLUDE_PRIORITYQUEUEMMAD
static PriorityQueueMMAD* _PriorityQueueMM_Get_PriorityQueueMMAD_True(PriorityQueueMM* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    return ((PriorityQueueMMAD*)Q);
}
#ifdef PRIORITYQUEUEMM_MULT_B_TYPE
static PriorityQueueMMAD* _PriorityQueueMM_Get_PriorityQueueMMAD_False(PriorityQueueMM* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    return NULL;
}
#endif // PRIORITYQUEUEMM_MULT_B_TYPE
#endif // INCLUDE_PRIORITYQUEUEMMAD

#ifdef INCLUDE_F_SIZE_PRIORITYQUEUEMM
static int _PriorityQueueMM_HasFixedSize_True(PriorityQueueMM* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    return 1;
}
#endif // INCLUDE_F_SIZE_PRIORITYQUEUEMM

#ifdef INCLUDE_D_SIZE_PRIORITYQUEUEMM
static int _PriorityQueueMM_HasFixedSize_False(PriorityQueueMM* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    return 0;
}
#endif // INCLUDE_D_SIZE_PRIORITYQUEUEMM


#ifdef INCLUDE_PRIORITYQUEUEMMSF
static int _PriorityQueueMMSF_GetCount(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMSF_GetCount((PriorityQueueMMSF*)Q,Errval);
}
static int _PriorityQueueMMSF_GetReservedItems(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMSF_GetReservedItems((PriorityQueueMMSF*)Q,Errval);
}
static size_t _PriorityQueueMMSF_GetReservedMemory(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMSF_GetReservedMemory((PriorityQueueMMSF*)Q,Errval);
}
static void* _PriorityQueueMMSF_GetMin(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMSF_GetMin((PriorityQueueMMSF*)Q,Errval);
}
static void* _PriorityQueueMMSF_GetMax(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMSF_GetMax((PriorityQueueMMSF*)Q,Errval);
}
static int _PriorityQueueMMSF_Insert(PriorityQueueMM* Q,void* Item,ERRVAL_T* Errval){
    return PriorityQueueMMSF_Insert((PriorityQueueMMSF*)Q,Item,Errval);
}
static int _PriorityQueueMMSF_RemoveMin(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMSF_RemoveMin((PriorityQueueMMSF*)Q,Errval);
}
static int _PriorityQueueMMSF_RemoveMax(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMSF_RemoveMax((PriorityQueueMMSF*)Q,Errval);
}
static int _PriorityQueueMMSF_RemoveMinSource(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMSF_RemoveMinSource((PriorityQueueMMSF*)Q,Errval);
}
static int _PriorityQueueMMSF_RemoveMaxSource(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMSF_RemoveMaxSource((PriorityQueueMMSF*)Q,Errval);
}
static int _PriorityQueueMMSF_Clear(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMSF_Clear((PriorityQueueMMSF*)Q,Errval);
}
static int _PriorityQueueMMSF_ClearSource(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMSF_ClearSource((PriorityQueueMMSF*)Q,Errval);
}
static int _PriorityQueueMMSF_Dispose(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMSF_Dispose((PriorityQueueMMSF*)Q,Errval);
}
static int _PriorityQueueMMSF_DisposeSource(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMSF_DisposeSource((PriorityQueueMMSF*)Q,Errval);
}

#ifdef PRIORITYQUEUEMM_FAILABLE_COMP
#define PriorityQueueMMSF_Compare(PQueuePtr,Item1Ptr,Item2Ptr,ErrvalPtr)    (((PriorityQueueMM*)(PQueuePtr))->Compare((Item1Ptr),(Item2Ptr),(ErrvalPtr)))
#else // PRIORITYQUEUEMM_FAILABLE_COMP
#define PriorityQueueMMSF_Compare(PQueuePtr,Item1Ptr,Item2Ptr,ErrvalPtr)    (((PriorityQueueMM*)(PQueuePtr))->Compare((Item1Ptr),(Item2Ptr)))
#endif // PRIORITYQUEUEMM_FAILABLE_COMP
#define PriorityQueueMMSF_DisposeItem(PQueuePtr,ItemPtr,ErrvalPtr)          (((PriorityQueueMM*)(PQueuePtr))->DisposeItem((ItemPtr),(ErrvalPtr)))
#define PriorityQueueMMSF_DisposeSelf(PQueuePtr,ErrvalPtr)                  (((((PriorityQueueMM*)(PQueuePtr))->DisposeSelf) != NULL)?(((PriorityQueueMM*)(PQueuePtr))->DisposeSelf(((void*)(PQueuePtr)),((PriorityQueueMM*)(PQueuePtr))->arg,(ErrvalPtr))):(1))

const I_PriorityQueueMM PriorityQueueMMSF_Funcs = {
    #ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMA
    .get_PriorityQueueMMA   = _PriorityQueueMM_Get_PriorityQueueMMA_False,
    #endif // INCLUDE_STRUCT_PRIORITYQUEUEMMA
    #ifdef INCLUDE_PRIORITYQUEUEMMSF
    .get_PriorityQueueMMSF  = _PriorityQueueMM_Get_PriorityQueueMMSF_True,
    #endif // INCLUDE_PRIORITYQUEUEMMSF
    #ifdef INCLUDE_PRIORITYQUEUEMMAF
    .get_PriorityQueueMMAF  = _PriorityQueueMM_Get_PriorityQueueMMAF_False,
    #endif // INCLUDE_PRIORITYQUEUEMMAF
    #ifdef INCLUDE_PRIORITYQUEUEMMSD
    .get_PriorityQueueMMSD  = _PriorityQueueMM_Get_PriorityQueueMMSD_False,
    #endif // INCLUDE_PRIORITYQUEUEMMSD
    #ifdef INCLUDE_PRIORITYQUEUEMMAD
    .get_PriorityQueueMMAD  = _PriorityQueueMM_Get_PriorityQueueMMAD_False,
    #endif // INCLUDE_PRIORITYQUEUEMMAD
    .hasFixedSize           = _PriorityQueueMM_HasFixedSize_True,
    .getCount               = _PriorityQueueMMSF_GetCount,
    .getReservedItems       = _PriorityQueueMMSF_GetReservedItems,
    .getReservedMemory      = _PriorityQueueMMSF_GetReservedMemory,
    .getMin                 = _PriorityQueueMMSF_GetMin,
    .getMax                 = _PriorityQueueMMSF_GetMax,
    .Insert                 = _PriorityQueueMMSF_Insert,
    .RemoveMin              = _PriorityQueueMMSF_RemoveMin,
    .RemoveMax              = _PriorityQueueMMSF_RemoveMax,
    .RemoveMinSource        = _PriorityQueueMMSF_RemoveMinSource,
    .RemoveMaxSource        = _PriorityQueueMMSF_RemoveMaxSource,
    .Clear                  = _PriorityQueueMMSF_Clear,
    .ClearSource            = _PriorityQueueMMSF_ClearSource,
    .Dispose                = _PriorityQueueMMSF_Dispose,
    .DisposeSource          = _PriorityQueueMMSF_DisposeSource
};
#endif // INCLUDE_PRIORITYQUEUEMMSF

#ifdef INCLUDE_PRIORITYQUEUEMMAF
static int _PriorityQueueMMAF_GetCount(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAF_GetCount((PriorityQueueMMAF*)Q,Errval);
}
static int _PriorityQueueMMAF_GetReservedItems(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAF_GetReservedItems((PriorityQueueMMAF*)Q,Errval);
}
static size_t _PriorityQueueMMAF_GetReservedMemory(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAF_GetReservedMemory((PriorityQueueMMAF*)Q,Errval);
}
static void* _PriorityQueueMMAF_GetMin(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAF_GetMin((PriorityQueueMMAF*)Q,Errval);
}
static void* _PriorityQueueMMAF_GetMax(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAF_GetMax((PriorityQueueMMAF*)Q,Errval);
}
static int _PriorityQueueMMAF_Insert(PriorityQueueMM* Q,void* Item,ERRVAL_T* Errval){
    return PriorityQueueMMAF_Insert((PriorityQueueMMAF*)Q,Item,Errval);
}
static int _PriorityQueueMMAF_RemoveMin(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAF_RemoveMin((PriorityQueueMMAF*)Q,Errval);
}
static int _PriorityQueueMMAF_RemoveMax(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAF_RemoveMax((PriorityQueueMMAF*)Q,Errval);
}
static int _PriorityQueueMMAF_RemoveMinSource(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAF_RemoveMinSource((PriorityQueueMMAF*)Q,Errval);
}
static int _PriorityQueueMMAF_RemoveMaxSource(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAF_RemoveMaxSource((PriorityQueueMMAF*)Q,Errval);
}
static int _PriorityQueueMMAF_Clear(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAF_Clear((PriorityQueueMMAF*)Q,Errval);
}
static int _PriorityQueueMMAF_ClearSource(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAF_ClearSource((PriorityQueueMMAF*)Q,Errval);
}
static int _PriorityQueueMMAF_Dispose(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAF_Dispose((PriorityQueueMMAF*)Q,Errval);
}
static int _PriorityQueueMMAF_DisposeSource(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAF_DisposeSource((PriorityQueueMMAF*)Q,Errval);
}

#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMA
static PriorityQueueMMAItem* _PriorityQueueMMAF_getMinItem(PriorityQueueMMA* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAF_GetMinItem((PriorityQueueMMAF*)Q,Errval);
}
static PriorityQueueMMAItem* _PriorityQueueMMAF_getMaxItem(PriorityQueueMMA* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAF_GetMaxItem((PriorityQueueMMAF*)Q,Errval);
}
static PriorityQueueMMAItem* _PriorityQueueMMAF_GetInsertedItem(PriorityQueueMMA* Q,void* Item,ERRVAL_T* Errval){
    return PriorityQueueMMAF_GetInsertedItem((PriorityQueueMMAF*)Q,Item,Errval);
}
static void* _PriorityQueueMMAF_GetItemOfItem(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval){
    return PriorityQueueMMAF_GetItemOfItem((PriorityQueueMMAF*)Q,Item,Errval);
}
static int _PriorityQueueMMAF_SetItemOfItem(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,void* ItemValue,ERRVAL_T* Errval){
    return PriorityQueueMMAF_SetItemOfItem((PriorityQueueMMAF*)Q,Item,ItemValue,Errval);
}
static int _PriorityQueueMMAF_ContainsItem(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval){
    return PriorityQueueMMAF_ContainsItem((PriorityQueueMMAF*)Q,Item,Errval);
}
static int _PriorityQueueMMAF_UpdateItem(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval){
    return PriorityQueueMMAF_UpdateItem((PriorityQueueMMAF*)Q,Item,Errval);
}
static int _PriorityQueueMMAF_RemoveItem(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval){
    return PriorityQueueMMAF_RemoveItem((PriorityQueueMMAF*)Q,Item,Errval);
}
static int _PriorityQueueMMAF_RemoveItemSource(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval){
    return PriorityQueueMMAF_RemoveItemSource((PriorityQueueMMAF*)Q,Item,Errval);
}
#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMA

#ifdef PRIORITYQUEUEMM_FAILABLE_COMP
#define PriorityQueueMMAF_Compare(PQueuePtr,Item1Ptr,Item2Ptr,ErrvalPtr)    (((PriorityQueueMM*)(PQueuePtr))->Compare((Item1Ptr),(Item2Ptr),(ErrvalPtr)))
#else // PRIORITYQUEUEMM_FAILABLE_COMP
#define PriorityQueueMMAF_Compare(PQueuePtr,Item1Ptr,Item2Ptr,ErrvalPtr)    (((PriorityQueueMM*)(PQueuePtr))->Compare((Item1Ptr),(Item2Ptr)))
#endif // PRIORITYQUEUEMM_FAILABLE_COMP
#define PriorityQueueMMAF_DisposeItem(PQueuePtr,ItemPtr,ErrvalPtr)          (((PriorityQueueMM*)(PQueuePtr))->DisposeItem((ItemPtr),(ErrvalPtr)))
#define PriorityQueueMMAF_DisposeSelf(PQueuePtr,ErrvalPtr)                  (((((PriorityQueueMM*)(PQueuePtr))->DisposeSelf) != NULL)?(((PriorityQueueMM*)(PQueuePtr))->DisposeSelf(((void*)(PQueuePtr)),((PriorityQueueMM*)(PQueuePtr))->arg,(ErrvalPtr))):(1))

const I_PriorityQueueMM PriorityQueueMMAF_Funcs = {
    #ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMA
    .get_PriorityQueueMMA   = _PriorityQueueMM_Get_PriorityQueueMMA_True,
    #endif // INCLUDE_STRUCT_PRIORITYQUEUEMMA
    #ifdef INCLUDE_PRIORITYQUEUEMMSF
    .get_PriorityQueueMMSF  = _PriorityQueueMM_Get_PriorityQueueMMSF_False,
    #endif // INCLUDE_PRIORITYQUEUEMMSF
    #ifdef INCLUDE_PRIORITYQUEUEMMAF
    .get_PriorityQueueMMAF  = _PriorityQueueMM_Get_PriorityQueueMMAF_True,
    #endif // INCLUDE_PRIORITYQUEUEMMAF
    #ifdef INCLUDE_PRIORITYQUEUEMMSD
    .get_PriorityQueueMMSD  = _PriorityQueueMM_Get_PriorityQueueMMSD_False,
    #endif // INCLUDE_PRIORITYQUEUEMMSD
    #ifdef INCLUDE_PRIORITYQUEUEMMAD
    .get_PriorityQueueMMAD  = _PriorityQueueMM_Get_PriorityQueueMMAD_False,
    #endif // INCLUDE_PRIORITYQUEUEMMAD
    .hasFixedSize           = _PriorityQueueMM_HasFixedSize_True,
    .getCount               = _PriorityQueueMMAF_GetCount,
    .getReservedItems       = _PriorityQueueMMAF_GetReservedItems,
    .getReservedMemory      = _PriorityQueueMMAF_GetReservedMemory,
    .getMin                 = _PriorityQueueMMAF_GetMin,
    .getMax                 = _PriorityQueueMMAF_GetMax,
    .Insert                 = _PriorityQueueMMAF_Insert,
    .RemoveMin              = _PriorityQueueMMAF_RemoveMin,
    .RemoveMax              = _PriorityQueueMMAF_RemoveMax,
    .RemoveMinSource        = _PriorityQueueMMAF_RemoveMinSource,
    .RemoveMaxSource        = _PriorityQueueMMAF_RemoveMaxSource,
    .Clear                  = _PriorityQueueMMAF_Clear,
    .ClearSource            = _PriorityQueueMMAF_ClearSource,
    .Dispose                = _PriorityQueueMMAF_Dispose,
    .DisposeSource          = _PriorityQueueMMAF_DisposeSource
};

#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMA
const I_PriorityQueueMMA PriorityQueueMMAF_AFuncs = {
    .getMinItem             = _PriorityQueueMMAF_getMinItem,
    .getMaxItem             = _PriorityQueueMMAF_getMaxItem,
    .GetInsertedItem        = _PriorityQueueMMAF_GetInsertedItem,
    .GetItemOfItem          = _PriorityQueueMMAF_GetItemOfItem,
    .SetItemOfItem          = _PriorityQueueMMAF_SetItemOfItem,
    .ContainsItem           = _PriorityQueueMMAF_ContainsItem,
    .UpdateItem             = _PriorityQueueMMAF_UpdateItem,
    .RemoveItem             = _PriorityQueueMMAF_RemoveItem,
    .RemoveItemSource       = _PriorityQueueMMAF_RemoveItemSource
};
#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMA
#endif // INCLUDE_PRIORITYQUEUEMMAF

#ifdef INCLUDE_PRIORITYQUEUEMMSD
static int _PriorityQueueMMSD_GetCount(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMSD_GetCount((PriorityQueueMMSD*)Q,Errval);
}
static int _PriorityQueueMMSD_GetReservedItems(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMSD_GetReservedItems((PriorityQueueMMSD*)Q,Errval);
}
static size_t _PriorityQueueMMSD_GetReservedMemory(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMSD_GetReservedMemory((PriorityQueueMMSD*)Q,Errval);
}
static void* _PriorityQueueMMSD_GetMin(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMSD_GetMin((PriorityQueueMMSD*)Q,Errval);
}
static void* _PriorityQueueMMSD_GetMax(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMSD_GetMax((PriorityQueueMMSD*)Q,Errval);
}
static int _PriorityQueueMMSD_Insert(PriorityQueueMM* Q,void* Item,ERRVAL_T* Errval){
    return PriorityQueueMMSD_Insert((PriorityQueueMMSD*)Q,Item,Errval);
}
static int _PriorityQueueMMSD_RemoveMin(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMSD_RemoveMin((PriorityQueueMMSD*)Q,Errval);
}
static int _PriorityQueueMMSD_RemoveMax(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMSD_RemoveMax((PriorityQueueMMSD*)Q,Errval);
}
static int _PriorityQueueMMSD_RemoveMinSource(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMSD_RemoveMinSource((PriorityQueueMMSD*)Q,Errval);
}
static int _PriorityQueueMMSD_RemoveMaxSource(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMSD_RemoveMaxSource((PriorityQueueMMSD*)Q,Errval);
}
static int _PriorityQueueMMSD_Clear(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMSD_Clear((PriorityQueueMMSD*)Q,Errval);
}
static int _PriorityQueueMMSD_ClearSource(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMSD_ClearSource((PriorityQueueMMSD*)Q,Errval);
}
static int _PriorityQueueMMSD_Dispose(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMSD_Dispose((PriorityQueueMMSD*)Q,Errval);
}
static int _PriorityQueueMMSD_DisposeSource(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMSD_DisposeSource((PriorityQueueMMSD*)Q,Errval);
}

#ifdef PRIORITYQUEUEMM_FAILABLE_COMP
#define PriorityQueueMMSD_Compare(PQueuePtr,Item1Ptr,Item2Ptr,ErrvalPtr)    (((PriorityQueueMM*)(PQueuePtr))->Compare((Item1Ptr),(Item2Ptr),(ErrvalPtr)))
#else // PRIORITYQUEUEMM_FAILABLE_COMP
#define PriorityQueueMMSD_Compare(PQueuePtr,Item1Ptr,Item2Ptr,ErrvalPtr)    (((PriorityQueueMM*)(PQueuePtr))->Compare((Item1Ptr),(Item2Ptr)))
#endif // PRIORITYQUEUEMM_FAILABLE_COMP
#define PriorityQueueMMSD_DisposeItem(PQueuePtr,ItemPtr,ErrvalPtr)          (((PriorityQueueMM*)(PQueuePtr))->DisposeItem((ItemPtr),(ErrvalPtr)))
#define PriorityQueueMMSD_DisposeSelf(PQueuePtr,ErrvalPtr)                  (((((PriorityQueueMM*)(PQueuePtr))->DisposeSelf) != NULL)?(((PriorityQueueMM*)(PQueuePtr))->DisposeSelf(((void*)(PQueuePtr)),((PriorityQueueMM*)(PQueuePtr))->arg,(ErrvalPtr))):(1))

const I_PriorityQueueMM PriorityQueueMMSD_Funcs = {
    #ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMA
    .get_PriorityQueueMMA   = _PriorityQueueMM_Get_PriorityQueueMMA_False,
    #endif // INCLUDE_STRUCT_PRIORITYQUEUEMMA
    #ifdef INCLUDE_PRIORITYQUEUEMMSF
    .get_PriorityQueueMMSF  = _PriorityQueueMM_Get_PriorityQueueMMSF_False,
    #endif // INCLUDE_PRIORITYQUEUEMMSF
    #ifdef INCLUDE_PRIORITYQUEUEMMAF
    .get_PriorityQueueMMAF  = _PriorityQueueMM_Get_PriorityQueueMMAF_False,
    #endif // INCLUDE_PRIORITYQUEUEMMAF
    #ifdef INCLUDE_PRIORITYQUEUEMMSD
    .get_PriorityQueueMMSD  = _PriorityQueueMM_Get_PriorityQueueMMSD_True,
    #endif // INCLUDE_PRIORITYQUEUEMMSD
    #ifdef INCLUDE_PRIORITYQUEUEMMAD
    .get_PriorityQueueMMAD  = _PriorityQueueMM_Get_PriorityQueueMMAD_False,
    #endif // INCLUDE_PRIORITYQUEUEMMAD
    .hasFixedSize           = _PriorityQueueMM_HasFixedSize_False,
    .getCount               = _PriorityQueueMMSD_GetCount,
    .getReservedItems       = _PriorityQueueMMSD_GetReservedItems,
    .getReservedMemory      = _PriorityQueueMMSD_GetReservedMemory,
    .getMin                 = _PriorityQueueMMSD_GetMin,
    .getMax                 = _PriorityQueueMMSD_GetMax,
    .Insert                 = _PriorityQueueMMSD_Insert,
    .RemoveMin              = _PriorityQueueMMSD_RemoveMin,
    .RemoveMax              = _PriorityQueueMMSD_RemoveMax,
    .RemoveMinSource        = _PriorityQueueMMSD_RemoveMinSource,
    .RemoveMaxSource        = _PriorityQueueMMSD_RemoveMaxSource,
    .Clear                  = _PriorityQueueMMSD_Clear,
    .ClearSource            = _PriorityQueueMMSD_ClearSource,
    .Dispose                = _PriorityQueueMMSD_Dispose,
    .DisposeSource          = _PriorityQueueMMSD_DisposeSource
};
#endif // INCLUDE_PRIORITYQUEUEMMSD

#ifdef INCLUDE_PRIORITYQUEUEMMAD
static int _PriorityQueueMMAD_GetCount(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAD_GetCount((PriorityQueueMMAD*)Q,Errval);
}
static int _PriorityQueueMMAD_GetReservedItems(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAD_GetReservedItems((PriorityQueueMMAD*)Q,Errval);
}
static size_t _PriorityQueueMMAD_GetReservedMemory(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAD_GetReservedMemory((PriorityQueueMMAD*)Q,Errval);
}
static void* _PriorityQueueMMAD_GetMin(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAD_GetMin((PriorityQueueMMAD*)Q,Errval);
}
static void* _PriorityQueueMMAD_GetMax(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAD_GetMax((PriorityQueueMMAD*)Q,Errval);
}
static int _PriorityQueueMMAD_Insert(PriorityQueueMM* Q,void* Item,ERRVAL_T* Errval){
    return PriorityQueueMMAD_Insert((PriorityQueueMMAD*)Q,Item,Errval);
}
static int _PriorityQueueMMAD_RemoveMin(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAD_RemoveMin((PriorityQueueMMAD*)Q,Errval);
}
static int _PriorityQueueMMAD_RemoveMax(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAD_RemoveMax((PriorityQueueMMAD*)Q,Errval);
}
static int _PriorityQueueMMAD_RemoveMinSource(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAD_RemoveMinSource((PriorityQueueMMAD*)Q,Errval);
}
static int _PriorityQueueMMAD_RemoveMaxSource(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAD_RemoveMaxSource((PriorityQueueMMAD*)Q,Errval);
}
static int _PriorityQueueMMAD_Clear(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAD_Clear((PriorityQueueMMAD*)Q,Errval);
}
static int _PriorityQueueMMAD_ClearSource(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAD_ClearSource((PriorityQueueMMAD*)Q,Errval);
}
static int _PriorityQueueMMAD_Dispose(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAD_Dispose((PriorityQueueMMAD*)Q,Errval);
}
static int _PriorityQueueMMAD_DisposeSource(PriorityQueueMM* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAD_DisposeSource((PriorityQueueMMAD*)Q,Errval);
}

#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMA
static PriorityQueueMMAItem* _PriorityQueueMMAD_getMinItem(PriorityQueueMMA* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAD_GetMinItem((PriorityQueueMMAD*)Q,Errval);
}
static PriorityQueueMMAItem* _PriorityQueueMMAD_getMaxItem(PriorityQueueMMA* Q,ERRVAL_T* Errval){
    return PriorityQueueMMAD_GetMaxItem((PriorityQueueMMAD*)Q,Errval);
}
static PriorityQueueMMAItem* _PriorityQueueMMAD_GetInsertedItem(PriorityQueueMMA* Q,void* Item,ERRVAL_T* Errval){
    return PriorityQueueMMAD_GetInsertedItem((PriorityQueueMMAD*)Q,Item,Errval);
}
static void* _PriorityQueueMMAD_GetItemOfItem(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval){
    return PriorityQueueMMAD_GetItemOfItem((PriorityQueueMMAD*)Q,Item,Errval);
}
static int _PriorityQueueMMAD_SetItemOfItem(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,void* ItemValue,ERRVAL_T* Errval){
    return PriorityQueueMMAD_SetItemOfItem((PriorityQueueMMAD*)Q,Item,ItemValue,Errval);
}
static int _PriorityQueueMMAD_ContainsItem(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval){
    return PriorityQueueMMAD_ContainsItem((PriorityQueueMMAD*)Q,Item,Errval);
}
static int _PriorityQueueMMAD_UpdateItem(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval){
    return PriorityQueueMMAD_UpdateItem((PriorityQueueMMAD*)Q,Item,Errval);
}
static int _PriorityQueueMMAD_RemoveItem(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval){
    return PriorityQueueMMAD_RemoveItem((PriorityQueueMMAD*)Q,Item,Errval);
}
static int _PriorityQueueMMAD_RemoveItemSource(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval){
    return PriorityQueueMMAD_RemoveItemSource((PriorityQueueMMAD*)Q,Item,Errval);
}
#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMA

#ifdef PRIORITYQUEUEMM_FAILABLE_COMP
#define PriorityQueueMMAD_Compare(PQueuePtr,Item1Ptr,Item2Ptr,ErrvalPtr)    (((PriorityQueueMM*)(PQueuePtr))->Compare((Item1Ptr),(Item2Ptr),(ErrvalPtr)))
#else // PRIORITYQUEUEMM_FAILABLE_COMP
#define PriorityQueueMMAD_Compare(PQueuePtr,Item1Ptr,Item2Ptr,ErrvalPtr)    (((PriorityQueueMM*)(PQueuePtr))->Compare((Item1Ptr),(Item2Ptr)))
#endif // PRIORITYQUEUEMM_FAILABLE_COMP
#define PriorityQueueMMAD_DisposeItem(PQueuePtr,ItemPtr,ErrvalPtr)          (((PriorityQueueMM*)(PQueuePtr))->DisposeItem((ItemPtr),(ErrvalPtr)))
#define PriorityQueueMMAD_DisposeSelf(PQueuePtr,ErrvalPtr)                  (((((PriorityQueueMM*)(PQueuePtr))->DisposeSelf) != NULL)?(((PriorityQueueMM*)(PQueuePtr))->DisposeSelf(((void*)(PQueuePtr)),((PriorityQueueMM*)(PQueuePtr))->arg,(ErrvalPtr))):(1))

const I_PriorityQueueMM PriorityQueueMMAD_Funcs = {
    #ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMA
    .get_PriorityQueueMMA   = _PriorityQueueMM_Get_PriorityQueueMMA_True,
    #endif // INCLUDE_STRUCT_PRIORITYQUEUEMMA
    #ifdef INCLUDE_PRIORITYQUEUEMMSF
    .get_PriorityQueueMMSF  = _PriorityQueueMM_Get_PriorityQueueMMSF_False,
    #endif // INCLUDE_PRIORITYQUEUEMMSF
    #ifdef INCLUDE_PRIORITYQUEUEMMAF
    .get_PriorityQueueMMAF  = _PriorityQueueMM_Get_PriorityQueueMMAF_False,
    #endif // INCLUDE_PRIORITYQUEUEMMAF
    #ifdef INCLUDE_PRIORITYQUEUEMMSD
    .get_PriorityQueueMMSD  = _PriorityQueueMM_Get_PriorityQueueMMSD_False,
    #endif // INCLUDE_PRIORITYQUEUEMMSD
    #ifdef INCLUDE_PRIORITYQUEUEMMAD
    .get_PriorityQueueMMAD  = _PriorityQueueMM_Get_PriorityQueueMMAD_True,
    #endif // INCLUDE_PRIORITYQUEUEMMAD
    .hasFixedSize           = _PriorityQueueMM_HasFixedSize_False,
    .getCount               = _PriorityQueueMMAD_GetCount,
    .getReservedItems       = _PriorityQueueMMAD_GetReservedItems,
    .getReservedMemory      = _PriorityQueueMMAD_GetReservedMemory,
    .getMin                 = _PriorityQueueMMAD_GetMin,
    .getMax                 = _PriorityQueueMMAD_GetMax,
    .Insert                 = _PriorityQueueMMAD_Insert,
    .RemoveMin              = _PriorityQueueMMAD_RemoveMin,
    .RemoveMax              = _PriorityQueueMMAD_RemoveMax,
    .RemoveMinSource        = _PriorityQueueMMAD_RemoveMinSource,
    .RemoveMaxSource        = _PriorityQueueMMAD_RemoveMaxSource,
    .Clear                  = _PriorityQueueMMAD_Clear,
    .ClearSource            = _PriorityQueueMMAD_ClearSource,
    .Dispose                = _PriorityQueueMMAD_Dispose,
    .DisposeSource          = _PriorityQueueMMAD_DisposeSource
};

#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMA
const I_PriorityQueueMMA PriorityQueueMMAD_AFuncs = {
    .getMinItem             = _PriorityQueueMMAD_getMinItem,
    .getMaxItem             = _PriorityQueueMMAD_getMaxItem,
    .GetInsertedItem        = _PriorityQueueMMAD_GetInsertedItem,
    .GetItemOfItem          = _PriorityQueueMMAD_GetItemOfItem,
    .SetItemOfItem          = _PriorityQueueMMAD_SetItemOfItem,
    .ContainsItem           = _PriorityQueueMMAD_ContainsItem,
    .UpdateItem             = _PriorityQueueMMAD_UpdateItem,
    .RemoveItem             = _PriorityQueueMMAD_RemoveItem,
    .RemoveItemSource       = _PriorityQueueMMAD_RemoveItemSource
};
#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMA
#endif // INCLUDE_PRIORITYQUEUEMMAD


#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMA
PriorityQueueMMA* PriorityQueueMM_Get_PriorityQueueMMA(PriorityQueueMM* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMM \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->get_PriorityQueueMMA(Q,Errval);
}
#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMA

#ifdef INCLUDE_PRIORITYQUEUEMMSF
PriorityQueueMMSF* PriorityQueueMM_Get_PriorityQueueMMSF(PriorityQueueMM* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMM \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->get_PriorityQueueMMSF(Q,Errval);
}
#endif // INCLUDE_PRIORITYQUEUEMMSF

#ifdef INCLUDE_PRIORITYQUEUEMMAF
PriorityQueueMMAF* PriorityQueueMM_Get_PriorityQueueMMAF(PriorityQueueMM* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMM \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->get_PriorityQueueMMAF(Q,Errval);
}
#endif // INCLUDE_PRIORITYQUEUEMMAF

#ifdef INCLUDE_PRIORITYQUEUEMMSD
PriorityQueueMMSD* PriorityQueueMM_Get_PriorityQueueMMSD(PriorityQueueMM* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMM \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->get_PriorityQueueMMSD(Q,Errval);
}
#endif // INCLUDE_PRIORITYQUEUEMMSD

int PriorityQueueMM_HasFixedSize(PriorityQueueMM* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMM \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->hasFixedSize(Q,Errval);
}

int PriorityQueueMM_GetCount(PriorityQueueMM* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMM \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->getCount(Q,Errval);
}

int PriorityQueueMM_GetReservedItems(PriorityQueueMM* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMM \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->getReservedItems(Q,Errval);
}

size_t PriorityQueueMM_GetReservedMemory(PriorityQueueMM* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMM \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->getReservedMemory(Q,Errval);
}

void* PriorityQueueMM_GetMin(PriorityQueueMM* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMM \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->getMin(Q,Errval);
}

void* PriorityQueueMM_GetMax(PriorityQueueMM* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMM \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->getMax(Q,Errval);
}

int PriorityQueueMM_Insert(PriorityQueueMM* Q,void* Item,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMM \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->Insert(Q,Item,Errval);
}

int PriorityQueueMM_RemoveMin(PriorityQueueMM* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMM \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->RemoveMin(Q,Errval);
}

int PriorityQueueMM_RemoveMax(PriorityQueueMM* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMM \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->RemoveMax(Q,Errval);
}

int PriorityQueueMM_RemoveMinSource(PriorityQueueMM* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMM \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->RemoveMinSource(Q,Errval);
}

int PriorityQueueMM_RemoveMaxSource(PriorityQueueMM* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMM \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->RemoveMaxSource(Q,Errval);
}

int PriorityQueueMM_Clear(PriorityQueueMM* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMM \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->Clear(Q,Errval);
}

int PriorityQueueMM_ClearSource(PriorityQueueMM* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMM \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->ClearSource(Q,Errval);
}

int PriorityQueueMM_Dispose(PriorityQueueMM* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMM \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->Dispose(Q,Errval);
}

int PriorityQueueMM_DisposeSource(PriorityQueueMM* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMM \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->DisposeSource(Q,Errval);
}


#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMA

PriorityQueueMM* PriorityQueueMMA_Get_PriorityQueueMM(PriorityQueueMMA* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMA \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return (PriorityQueueMM*)Q;
}

#ifdef INCLUDE_PRIORITYQUEUEMMAF
PriorityQueueMMAF* PriorityQueueMMA_Get_PriorityQueueMMAF(PriorityQueueMMA* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMA \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->Base.IFunc->get_PriorityQueueMMAF((PriorityQueueMM*)Q,Errval);
}
#endif // INCLUDE_PRIORITYQUEUEMMAF

int PriorityQueueMMA_HasFixedSize(PriorityQueueMMA* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMA \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->Base.IFunc->hasFixedSize((PriorityQueueMM*)Q,Errval);
}

int PriorityQueueMMA_GetCount(PriorityQueueMMA* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMA \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->Base.IFunc->getCount((PriorityQueueMM*)Q,Errval);
}

int PriorityQueueMMA_GetReservedItems(PriorityQueueMMA* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMA \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->Base.IFunc->getReservedItems((PriorityQueueMM*)Q,Errval);
}

size_t PriorityQueueMMA_GetReservedMemory(PriorityQueueMMA* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMA \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->Base.IFunc->getReservedMemory((PriorityQueueMM*)Q,Errval);
}

void* PriorityQueueMMA_GetMin(PriorityQueueMMA* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMA \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->Base.IFunc->getMin((PriorityQueueMM*)Q,Errval);
}

void* PriorityQueueMMA_GetMax(PriorityQueueMMA* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMA \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->Base.IFunc->getMax((PriorityQueueMM*)Q,Errval);
}

PriorityQueueMMAItem* PriorityQueueMMA_GetMinItem(PriorityQueueMMA* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMA \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->getMinItem(Q,Errval);
}

PriorityQueueMMAItem* PriorityQueueMMA_GetMaxItem(PriorityQueueMMA* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMA \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->getMaxItem(Q,Errval);
}

int PriorityQueueMMA_Insert(PriorityQueueMMA* Q,void* Item,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMA \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->Base.IFunc->Insert((PriorityQueueMM*)Q,Item,Errval);
}

PriorityQueueMMAItem* PriorityQueueMMA_GetInsertedItem(PriorityQueueMMA* Q,void* Item,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMA \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->GetInsertedItem(Q,Item,Errval);
}

void* PriorityQueueMMA_GetItemOfItem(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMA \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->GetItemOfItem(Q,Item,Errval);
}

int PriorityQueueMMA_SetItemOfItem(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,void* ItemValue,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMA \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->SetItemOfItem(Q,Item,ItemValue,Errval);
}

int PriorityQueueMMA_ContainsItem(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMA \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->ContainsItem(Q,Item,Errval);
}

int PriorityQueueMMA_UpdateItem(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMA \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->UpdateItem(Q,Item,Errval);
}

int PriorityQueueMMA_RemoveMin(PriorityQueueMMA* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMA \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->Base.IFunc->RemoveMin((PriorityQueueMM*)Q,Errval);
}

int PriorityQueueMMA_RemoveMax(PriorityQueueMMA* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMA \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->Base.IFunc->RemoveMax((PriorityQueueMM*)Q,Errval);
}

int PriorityQueueMMA_RemoveItem(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMA \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->RemoveItem(Q,Item,Errval);
}

int PriorityQueueMMA_RemoveMinSource(PriorityQueueMMA* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMA \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->Base.IFunc->RemoveMinSource((PriorityQueueMM*)Q,Errval);
}

int PriorityQueueMMA_RemoveMaxSource(PriorityQueueMMA* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMA \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->Base.IFunc->RemoveMaxSource((PriorityQueueMM*)Q,Errval);
}

int PriorityQueueMMA_RemoveItemSource(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMA \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->IFunc->RemoveItemSource(Q,Item,Errval);
}

int PriorityQueueMMA_Clear(PriorityQueueMMA* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMA \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->Base.IFunc->Clear((PriorityQueueMM*)Q,Errval);
}

int PriorityQueueMMA_ClearSource(PriorityQueueMMA* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMA \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->Base.IFunc->ClearSource((PriorityQueueMM*)Q,Errval);
}

int PriorityQueueMMA_Dispose(PriorityQueueMMA* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMA \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->Base.IFunc->Dispose((PriorityQueueMM*)Q,Errval);
}

int PriorityQueueMMA_DisposeSource(PriorityQueueMMA* Q,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMA \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->Base.IFunc->DisposeSource((PriorityQueueMM*)Q,Errval);
}
#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMA
#endif // PRIORITYQUEUEMM_INHERITANCE



#ifdef INCLUDE_PRIORITYQUEUEMMSF

#ifndef PriorityQueueMMSF_Compare
#ifdef PRIORITYQUEUEMM_FAILABLE_COMP
#define PriorityQueueMMSF_Compare(PQueuePtr,Item1Ptr,Item2Ptr,ErrvalPtr)    (((PriorityQueueMMSF*)(PQueuePtr))->Compare((Item1Ptr),(Item2Ptr),(ErrvalPtr)))
#else // PRIORITYQUEUEMM_FAILABLE_COMP
#define PriorityQueueMMSF_Compare(PQueuePtr,Item1Ptr,Item2Ptr,ErrvalPtr)    (((PriorityQueueMMSF*)(PQueuePtr))->Compare((Item1Ptr),(Item2Ptr)))
#endif // PRIORITYQUEUEMM_FAILABLE_COMP
#endif // PriorityQueueMMSF_Compare

#ifndef PriorityQueueMMSF_DisposeItem
#define PriorityQueueMMSF_DisposeItem(PQueuePtr,ItemPtr,ErrvalPtr)          (((PriorityQueueMMSF*)(PQueuePtr))->DisposeItem((ItemPtr),(ErrvalPtr)))
#endif // PriorityQueueMMSF_DisposeItem

#ifndef PriorityQueueMMSF_DisposeSelf
#define PriorityQueueMMSF_DisposeSelf(PQueuePtr,ErrvalPtr)                  (((((PriorityQueueMMSF*)(PQueuePtr))->DisposeSelf) != NULL)?(((PriorityQueueMMSF*)(PQueuePtr))->DisposeSelf(((void*)(PQueuePtr)),((PriorityQueueMMSF*)(PQueuePtr))->arg,(ErrvalPtr))):(1))
#endif // PriorityQueueMMSF_DisposeSelf

static int PriorityQueueMMSF_SiftUp(PriorityQueueMMSF* Q,int Index,int Modifier,ERRVAL_T* Errval){
    //Modifier = 1: Upper Tree with Min at Root (Root has Index "0")
    //Modifier =-1: Lower Tree with Max at Root (Root has Index "1")
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if((Index < 0)||(Index >= Q->Size)){
        PRINT_ERROR("Index is out of range!\0");
        if(Errval != NULL){*Errval = ERRVAL_OUT_OF_RANGE;}
        return 0;
    }
    if((Modifier != -1)&&(Modifier != 1)){
        PRINT_ERROR("Modifier is invalid!\0");
        if(Errval != NULL){*Errval = ERRVAL_INVALID_VAL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    int i = Index;
    void* SwapItem;
    int ParentIndex;
    #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
    int CompRes;
    #endif // PRIORITYQUEUEMM_FAILABLE_COMP
    while(i > 1){
        ParentIndex = (i >> 1) - 1;

        #define PriorityQueueMMSF_SiftUp_comp   (PriorityQueueMMSF_Compare(Q,Q->Items[i],Q->Items[ParentIndex],Errval) != Modifier)
        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        CompRes = PriorityQueueMMSF_SiftUp_comp;
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return 0;
        }

        #undef PriorityQueueMMSF_SiftUp_comp
        #define PriorityQueueMMSF_SiftUp_comp   (CompRes)
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP

        if(PriorityQueueMMSF_SiftUp_comp){return 1;}
        #undef PriorityQueueMMSF_SiftUp_comp
        SwapItem = Q->Items[i];
        Q->Items[i] = Q->Items[ParentIndex];
        Q->Items[ParentIndex] = SwapItem;
        i = ParentIndex;
    }
    return 1;
}

static int PriorityQueueMMSF_SiftDown(PriorityQueueMMSF* Q,int Index,int Modifier,ERRVAL_T* Errval){
    //Modifier = 1: Upper Tree with Min at Root (Root has Index "0")
    //Modifier =-1: Lower Tree with Max at Root (Root has Index "1")
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if((Index < 0)||(Index >= Q->Size)){
        PRINT_ERROR("Index is out of range!\0");
        if(Errval != NULL){*Errval = ERRVAL_OUT_OF_RANGE;}
        return 0;
    }
    if((Modifier != -1)&&(Modifier != 1)){
        PRINT_ERROR("Modifier is invalid!\0");
        if(Errval != NULL){*Errval = ERRVAL_INVALID_VAL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL2

    int i = Index;
    void* SwapItem;
    int ChildIndex;
    int StopIndex = (Q->Count >> 1) - 1;
    #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
    int CompRes;
    #endif // PRIORITYQUEUEMM_FAILABLE_COMP
    while(i < StopIndex){
        ChildIndex = (i << 1) + 2;
        //-------------------------------------------------------------------------------------------------------
        //Definition "CompObject": Type with comparison-operator defined on it.

        //Definition "Child1": Child with lower Index  (left child)                         (type: CompObject)
        //Definition "Child2": Child with higher Index (right child)                        (type: CompObject)
        //Definition "ChildI0": Index of Child1                                             (type: whole number)
        //Definition "ChildIR": Index of Child that should be compared with the parent      (type: whole number)

        //Definition "Modifier": Input with the number having the following meaning:        (type: whole number)
        // Modifier =  1: Children should be greater than their parents
        // Modifier = -1: Children should be smaller than their parents

        //Definition "PriorityQueueMMSF_Compare": conditional with whole number as result with:
        //(Child1 > Child2) <=> PriorityQueueMMSF_Compare := -1
        //(Child1 = Child2) <=> PriorityQueueMMSF_Compare :=  0
        //(Child1 < Child2) <=> PriorityQueueMMSF_Compare :=  1

        // TRUE => 1        (true statements will be "replaced" with the value "1" within an formula with ":=" and a whole number as type)
        // FALSE => 0       (false statements will be "replaced" with the value "0" within a formula with ":=" and a whole number as type)


        // The following Conditions should be valid:
        // -----------------------------------------
        //((Child1 > Child2) && (Modifier =  1)) => "Right child should be taken"
        //((Child1 < Child2) && (Modifier =  1)) => "Left child should be taken"
        //((Child1 > Child2) && (Modifier = -1)) => "Left child should be taken"
        //((Child1 < Child2) && (Modifier = -1)) => "Right child should be taken"

        // Reason for these Conditions:
        // The child that should be taken should be the item that is more likely to be able to be swapped with its parent and that does
        // not require being swapped with the other child directly after the first swap (if the swap is allowed)
        // => The Smaller-Child for (Modifier =  1)
        // => The Greater-Child for (Modifier = -1)


        // Translation "Right child should be taken": ChildIR := ChildI0 + 1
        // Translation "Left child should be taken" : ChildIR := ChildI0 + 0

        //With the translations we will get the following conditions:
        //((Child1 > Child2) && (Modifier =  1)) => ChildIR := ChildI0 + 1
        //((Child1 < Child2) && (Modifier =  1)) => ChildIR := ChildI0 + 0
        //((Child1 > Child2) && (Modifier = -1)) => ChildIR := ChildI0 + 0
        //((Child1 < Child2) && (Modifier = -1)) => ChildIR := ChildI0 + 1

        //Can be changed to:
        //((PriorityQueueMMSF_Compare = -1) && (Modifier =  1)) => ChildIR := ChildI0 + 1
        //((PriorityQueueMMSF_Compare =  1) && (Modifier =  1)) => ChildIR := ChildI0 + 0
        //((PriorityQueueMMSF_Compare = -1) && (Modifier = -1)) => ChildIR := ChildI0 + 0
        //((PriorityQueueMMSF_Compare =  1) && (Modifier = -1)) => ChildIR := ChildI0 + 1

        //Can be changed to:
        //((PriorityQueueMMSF_Compare = -1) && (Modifier =  1)) => ChildIR := ChildI0 + TRUE
        //((PriorityQueueMMSF_Compare =  1) && (Modifier =  1)) => ChildIR := ChildI0 + FALSE
        //((PriorityQueueMMSF_Compare = -1) && (Modifier = -1)) => ChildIR := ChildI0 + FALSE
        //((PriorityQueueMMSF_Compare =  1) && (Modifier = -1)) => ChildIR := ChildI0 + TRUE

        //Can be changed to:
        //((PriorityQueueMMSF_Compare = -1) && (Modifier =  1)) => ChildIR := ChildI0 + (PriorityQueueMMSF_Compare != Modifier)
        //((PriorityQueueMMSF_Compare =  1) && (Modifier =  1)) => ChildIR := ChildI0 + (PriorityQueueMMSF_Compare != Modifier)
        //((PriorityQueueMMSF_Compare = -1) && (Modifier = -1)) => ChildIR := ChildI0 + (PriorityQueueMMSF_Compare != Modifier)
        //((PriorityQueueMMSF_Compare =  1) && (Modifier = -1)) => ChildIR := ChildI0 + (PriorityQueueMMSF_Compare != Modifier)

        //if we make the following definitions:
        //Definition: C1 := ((PriorityQueueMMSF_Compare = -1) && (Modifier =  1))
        //Definition: C2 := ((PriorityQueueMMSF_Compare =  1) && (Modifier =  1))
        //Definition: C3 := ((PriorityQueueMMSF_Compare = -1) && (Modifier = -1))
        //Definition: C4 := ((PriorityQueueMMSF_Compare =  1) && (Modifier = -1))

        //Then we can combine and shorten the formula because of the fact that all "then-cases" are identical to:
        // (C1 || C2 || C3 || C4) => ChildIR := ChildI0 + (PriorityQueueMMSF_Compare != Modifier)

        //And because it does not matter which child is taken if both children are equal in regards to the comparison-function we just assume that
        //this case can not occur.

        //Then we will get:
        //(C1 || C2 || C3 || C4) <=> TRUE

        //With that we come to the result:
        //ChildIR := ChildI0 + (PriorityQueueMMSF_Compare != Modifier)
        //----------------------------------------------------------------------------------------------------------------------
        ChildIndex = ChildIndex + (PriorityQueueMMSF_Compare(Q,Q->Items[ChildIndex],Q->Items[ChildIndex + 1],Errval) != Modifier);      //"Proof" directly above
        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return 0;
        }
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP

        #define PriorityQueueMMSF_SiftDown_comp     (PriorityQueueMMSF_Compare(Q,Q->Items[ChildIndex],Q->Items[i],Errval) != Modifier)

        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        CompRes = PriorityQueueMMSF_SiftDown_comp;
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return 0;
        }

        #undef PriorityQueueMMSF_SiftDown_comp
        #define PriorityQueueMMSF_SiftDown_comp     (CompRes)
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP

        if(PriorityQueueMMSF_SiftDown_comp){return 1;}
        #undef PriorityQueueMMSF_SiftDown_comp
        SwapItem = Q->Items[i];
        Q->Items[i] = Q->Items[ChildIndex];
        Q->Items[ChildIndex] = SwapItem;
        i = ChildIndex;
    }

    //Border-Case:
    if(((i << 1) + 3) == Q->Count){
        ChildIndex = Q->Count - 1;

        #define PriorityQueueMMSF_SiftDown_comp     (PriorityQueueMMSF_Compare(Q,Q->Items[ChildIndex],Q->Items[i],Errval) != Modifier)

        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        CompRes = PriorityQueueMMSF_SiftDown_comp;
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return 0;
        }

        #undef PriorityQueueMMSF_SiftDown_comp
        #define PriorityQueueMMSF_SiftDown_comp     (CompRes)
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP

        if(PriorityQueueMMSF_SiftDown_comp){return 1;}
        #undef PriorityQueueMMSF_SiftDown_comp
        SwapItem = Q->Items[i];
        Q->Items[i] = Q->Items[ChildIndex];
        Q->Items[ChildIndex] = SwapItem;
        i = ChildIndex;
    }

    //In Case the Change-Area is reached:
    ChildIndex = ((i + (i < Q->LstLayerStart)) << (i < Q->LstLayerStart)) + (Modifier * ((Q->LstLayerStart >> 1) + 1));
    if((ChildIndex == Q->Count)&&(ChildIndex & 1)){ChildIndex = Q->Count - 1;}
    if(ChildIndex >= Q->Count){ChildIndex = (ChildIndex >> 1) - 1;}
    if(ChildIndex < StopIndex){ChildIndex = (ChildIndex << 1) + 2;}
    if(((i < Q->LstLayerStart)&&(ChildIndex >= Q->LstLayerStart)&&(ChildIndex + 1 < Q->Count))||((Modifier == -1)&&(i + 1 == Q->Count)&&(!(i & 1)))){
        ChildIndex = ChildIndex + (PriorityQueueMMSF_Compare(Q,Q->Items[ChildIndex],Q->Items[ChildIndex + 1],Errval) != Modifier);
        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return 0;
        }
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP
    }



    #define PriorityQueueMMSF_SiftDown_comp     (PriorityQueueMMSF_Compare(Q,Q->Items[ChildIndex],Q->Items[i],Errval) != Modifier)

    #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
    CompRes = PriorityQueueMMSF_SiftDown_comp;
    if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
        PRINT_ERROR3;
        return 0;
    }
    #undef PriorityQueueMMSF_SiftDown_comp
    #define PriorityQueueMMSF_SiftDown_comp     (CompRes)
    #endif // PRIORITYQUEUEMM_FAILABLE_COMP

    if(PriorityQueueMMSF_SiftDown_comp){return 1;}
    #undef PriorityQueueMMSF_SiftDown_comp
    SwapItem = Q->Items[i];
    Q->Items[i] = Q->Items[ChildIndex];
    Q->Items[ChildIndex] = SwapItem;
    return PriorityQueueMMSF_SiftUp(Q,ChildIndex,-Modifier,Errval);
}

#ifdef PRIORITYQUEUEMM_INHERITANCE
PriorityQueueMM* PriorityQueueMMSF_Get_PriorityQueueMM(PriorityQueueMMSF* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return (PriorityQueueMM*)Q;
}
#endif // PRIORITYQUEUEMM_INHERITANCE

PriorityQueueMMSF* PriorityQueueMMSF_Create(void* MemPtr,size_t Size,PRIORITYQUEUEMM_COMP_FUNC_PTR,int(*disposeItem)(void*,ERRVAL_T*),int(*disposeSelf)(void*,void*,ERRVAL_T*),void* arg,ERRVAL_T* Errval){
    uint16_t ItemCount = PriorityQueueMMSF_GetItemCountForSize(Size,Errval);
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(MemPtr == NULL){
        PRINT_ERROR("Pointer to Memory \"MemPtr\" must not be NULL!\0");
        if(Errval != NULL){*Errval = ERRVAL_NO_MEM;}
        return NULL;
    }
    if(ItemCount <= 0){
        PRINT_ERROR("\"Size\" too small!\0");
        if(Errval != NULL){*Errval = ERRVAL_NO_MEM;}
        return NULL;
    }
    if(compare == NULL){
        PRINT_ERROR("\"compare\"-function pointer must not be NULL!\0");
        if(Errval != NULL){*Errval = ERRVAL_OP_MISSING;}
        return NULL;
    }
    if(disposeItem == NULL){
        PRINT_ERROR("\"disposeItem\"-function pointer must not be NULL!\0");
        if(Errval != NULL){*Errval = ERRVAL_OP_MISSING;}
        return NULL;
    }
    if((disposeSelf == NULL)&&(arg != NULL)){
        PRINT_ERROR("\"arg\"-parameter must be NULL if \"disposeSelf\" is NULL!\0");
        if(Errval != NULL){*Errval = ERRVAL_INVALID_VAL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1

    PriorityQueueMMSF* res = (PriorityQueueMMSF*)MemPtr;

    #ifdef PRIORITYQUEUEMM_INHERITANCE
    res->Base.IFunc = &PriorityQueueMMSF_Funcs;
    res->Base.Compare = compare;
    res->Base.DisposeItem = disposeItem;
    res->Base.DisposeSelf = disposeSelf;
    res->Base.arg = arg;
    #else // PRIORITYQUEUEMM_INHERITANCE
    res->Compare = compare;
    res->DisposeItem = disposeItem;
    res->DisposeSelf = disposeSelf;
    res->arg = arg;
    #endif // PRIORITYQUEUEMM_INHERITANCE

    res->Count = 0;
    res->LstLayerStart = 0;
    res->Size = (size_t)ItemCount;
    #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
    int i;
    for(i = 0;i < res->Size;i++){res->Items[i] = NULL;}
    #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
    return res;
}

size_t PriorityQueueMMSF_GetSizeFor(uint16_t ItemCount,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    return sizeof(PriorityQueueMMSF) + sizeof(void*) * ItemCount;
}

uint16_t PriorityQueueMMSF_GetItemCountForSize(size_t Size,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    if(Size <= sizeof(PriorityQueueMMSF)){return 0;}
    return (uint16_t)((Size - sizeof(PriorityQueueMMSF)) / sizeof(void*));
}

int PriorityQueueMMSF_GetCount(PriorityQueueMMSF* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->Count;
}

int PriorityQueueMMSF_GetReservedItems(PriorityQueueMMSF* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return (int)Q->Size;
}

size_t PriorityQueueMMSF_GetReservedMemory(PriorityQueueMMSF* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return ((Q->Size * sizeof(void*)) + sizeof(PriorityQueueMMSF));
}

void* PriorityQueueMMSF_GetMin(PriorityQueueMMSF* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->Items[0];
}

void* PriorityQueueMMSF_GetMax(PriorityQueueMMSF* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q->Count == 1){return Q->Items[0];}
    return Q->Items[1];
}

int PriorityQueueMMSF_Insert(PriorityQueueMMSF* Q,void* Item,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(Q->Count >= Q->Size){
        PRINT_ERROR("PriorityQueue is filled!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_FULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    int i = Q->Count;
    Q->Items[i] = Item;
    Q->Count++;
    if(Q->Count == 1){return 1;}
    if((Q->LstLayerStart << 1) + 2 == i){Q->LstLayerStart = i;}
    //int LayerOffset = (Q->LstLayerStart >> 1) + 1;

    int Modifier2 = ((i - Q->LstLayerStart) < (Q->LstLayerStart >> 1) + 1); //TRUE if item is a Upper-Tree item
    int Modifier = Modifier2 - !Modifier2;                                  //-1: Lower-Tree-Item, +1: Upper-Tree-Item
    int ChildIndex = ((i - 1) + Modifier * (Q->LstLayerStart >> 1)) >> Modifier2;

    if((!Modifier2)&&(Q->Count & 1)){
        ChildIndex = ChildIndex + (PriorityQueueMMSF_Compare(Q,Q->Items[ChildIndex],Q->Items[ChildIndex + 1],Errval) != Modifier);
        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return NULL;
        }
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP
    }

    // Has the same number of Operations (both with one Multiplication) but upper version does not have a "if" => "removed"
    //int Modifier = ((i - Q->LstLayerStart) >= LayerOffset); //TRUE if item is a lower-Tree item
    //Modifier = !Modifier - Modifier;                        //-1: Lower-Tree-Item, +1: Upper-Tree-Item
    //int ChildIndex = i + Modifier * LayerOffset;
    //if(ChildIndex >= Q->Count){ChildIndex = (ChildIndex >> 1) - 1;}

    // Branch should not be accessible:
    //if(ChildIndex < (Q->Count >> 1) - 1){
    //    ChildIndex = (ChildIndex << 1) + 2;
    //    if(ChildIndex + 1 < Q->Count){
    //    ChildIndex = ChildIndex + (PriorityQueueMMSF_Compare(Q,Q->Items[ChildIndex],Q->Items[ChildIndex + 1],Errval) != Modifier);
    //    #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
    //    if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
    //        PRINT_ERROR3;
    //        return 0;
    //    }
    //    #endif // PRIORITYQUEUEMM_FAILABLE_COMP
    //    }
    //}

    #define PriorityQueueMMSF_Insert_Comp   (PriorityQueueMMSF_Compare(Q,Q->Items[ChildIndex],Q->Items[i],Errval) == Modifier)

    #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
    int CompRes = (PriorityQueueMMSF_Compare(Q,Q->Items[ChildIndex],Q->Items[i],Errval) == Modifier);
    if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
        PRINT_ERROR3;
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Items[i] = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Count--;
        return 0;
    }
    #undef PriorityQueueMMSF_Insert_Comp
    #define PriorityQueueMMSF_Insert_Comp   (CompRes)
    #endif // PRIORITYQUEUEMM_FAILABLE_COMP

    if(PriorityQueueMMSF_Insert_Comp){
        Q->Items[i] = Q->Items[ChildIndex];
        Q->Items[ChildIndex] = Item;
        return PriorityQueueMMSF_SiftUp(Q,ChildIndex,-Modifier,Errval);
    }
    #undef PriorityQueueMMSF_Insert_Comp
    return PriorityQueueMMSF_SiftUp(Q,i,Modifier,Errval);
}

int PriorityQueueMMSF_RemoveMin(PriorityQueueMMSF* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q->Count == 1){
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Items[0] = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Count = 0;
        return 1;
    }
    Q->Count--;
    Q->Items[0] = Q->Items[Q->Count];
    #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
    Q->Items[Q->Count] = NULL;
    #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
    if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
    if(Q->Count == 1){return 1;}
    int res = PriorityQueueMMSF_SiftDown(Q,0,1,Errval);

    if((res == 0)||(Q->Count < 5)){return res;}
    if((Q->Count & 1)&&(((Q->Count - 1) - Q->LstLayerStart) >= (Q->LstLayerStart >> 1) + 1)){return PriorityQueueMMSF_SiftDown(Q,Q->Count - 1,-1,Errval);}
    return res;
}

int PriorityQueueMMSF_RemoveMax(PriorityQueueMMSF* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    int res = 0;
    if(Q->Count > 2){
        Q->Count--;
        Q->Items[1] = Q->Items[Q->Count];
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Items[Q->Count] = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
        res = PriorityQueueMMSF_SiftDown(Q,1,-1,Errval);
        goto END;
    }

    Q->LstLayerStart = 0;

    if(Q->Count == 1){
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Items[0] = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Count = 0;
        return 1;
    }
    #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
    Q->Items[1] = NULL;
    #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
    Q->Count = 1;
    return 1;

    END:
    if((res == 0)||(Q->Count < 5)){return res;}
    if((Q->Count & 1)&&(((Q->Count - 1) - Q->LstLayerStart) >= (Q->LstLayerStart >> 1) + 1)){return PriorityQueueMMSF_SiftDown(Q,Q->Count - 1,-1,Errval);}
    return res;
}

int PriorityQueueMMSF_RemoveMinSource(PriorityQueueMMSF* Q,ERRVAL_T* Errval){
if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(!PriorityQueueMMSF_DisposeItem(Q,Q->Items[0],Errval)){
        PRINT_ERROR3;
        return 0;
    }
    if(Q->Count == 1){
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Items[0] = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Count = 0;
        return 1;
    }
    Q->Count--;
    Q->Items[0] = Q->Items[Q->Count];
    #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
    Q->Items[Q->Count] = NULL;
    #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
    if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
    if(Q->Count == 1){return 1;}
    int res = PriorityQueueMMSF_SiftDown(Q,0,1,Errval);

    if((res == 0)||(Q->Count < 5)){return res;}
    if((Q->Count & 1)&&(((Q->Count - 1) - Q->LstLayerStart) >= (Q->LstLayerStart >> 1) + 1)){return PriorityQueueMMSF_SiftDown(Q,Q->Count - 1,-1,Errval);}
    return res;
}

int PriorityQueueMMSF_RemoveMaxSource(PriorityQueueMMSF* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    int res = 0;
    if(Q->Count > 2){
        if(!PriorityQueueMMSF_DisposeItem(Q,Q->Items[1],Errval)){
            PRINT_ERROR3;
            return 0;
        }
        Q->Count--;
        Q->Items[1] = Q->Items[Q->Count];
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Items[Q->Count] = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
        res = PriorityQueueMMSF_SiftDown(Q,1,-1,Errval);
        goto END;
    }

    Q->LstLayerStart = 0;

    if(Q->Count == 1){
        if(!PriorityQueueMMSF_DisposeItem(Q,Q->Items[0],Errval)){
            PRINT_ERROR3;
            return 0;
        }
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Items[0] = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Count = 0;
        return 1;
    }
    if(!PriorityQueueMMSF_DisposeItem(Q,Q->Items[1],Errval)){
        PRINT_ERROR3;
        return 0;
    }
    #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
    Q->Items[1] = NULL;
    #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
    Q->Count = 1;
    return 1;

    END:
    if((res == 0)||(Q->Count < 5)){return res;}
    if((Q->Count & 1)&&(((Q->Count - 1) - Q->LstLayerStart) >= (Q->LstLayerStart >> 1) + 1)){return PriorityQueueMMSF_SiftDown(Q,Q->Count - 1,-1,Errval);}
    return res;
}

int PriorityQueueMMSF_Clear(PriorityQueueMMSF* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
    int i;
    for(i = Q->Count - 1;i >= 0;i--){Q->Items[i] = NULL;}
    #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
    Q->Count = 0;
    Q->LstLayerStart = 0;
    return 1;
}

int PriorityQueueMMSF_ClearSource(PriorityQueueMMSF* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    int i;
    for(i = Q->Count - 1;i >= 0;i--){
        if(!PriorityQueueMMSF_DisposeItem(Q,Q->Items[i],Errval)){
            PRINT_ERROR3;
            return 0;
        }
        Q->Count--;
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Items[Q->Count] = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
    }
    return 1;
}

int PriorityQueueMMSF_Dispose(PriorityQueueMMSF* Q,ERRVAL_T* Errval){
    if(!PriorityQueueMMSF_Clear(Q,Errval)){
        PRINT_ERROR3;
        return 0;
    }
    return PriorityQueueMMSF_DisposeSelf(Q,Errval);
}

int PriorityQueueMMSF_DisposeSource(PriorityQueueMMSF* Q,ERRVAL_T* Errval){
    if(!PriorityQueueMMSF_ClearSource(Q,Errval)){
        PRINT_ERROR3;
        return 0;
    }
    return PriorityQueueMMSF_DisposeSelf(Q,Errval);
}
#endif // INCLUDE_PRIORITYQUEUEMMSF


#ifdef INCLUDE_PRIORITYQUEUEMMAF

#ifndef PriorityQueueMMAF_Compare
#ifdef PRIORITYQUEUEMM_FAILABLE_COMP
#define PriorityQueueMMAF_Compare(PQueuePtr,Item1Ptr,Item2Ptr,ErrvalPtr)    (((PriorityQueueMMAF*)(PQueuePtr))->Compare((Item1Ptr),(Item2Ptr),(ErrvalPtr)))
#else // PRIORITYQUEUEMM_FAILABLE_COMP
#define PriorityQueueMMAF_Compare(PQueuePtr,Item1Ptr,Item2Ptr,ErrvalPtr)    (((PriorityQueueMMAF*)(PQueuePtr))->Compare((Item1Ptr),(Item2Ptr)))
#endif // PRIORITYQUEUEMM_FAILABLE_COMP
#endif // PriorityQueueMMAF_Compare

#ifndef PriorityQueueMMAF_DisposeItem
#define PriorityQueueMMAF_DisposeItem(PQueuePtr,ItemPtr,ErrvalPtr)          (((PriorityQueueMMAF*)(PQueuePtr))->DisposeItem((ItemPtr),(ErrvalPtr)))
#endif // PriorityQueueMMAF_DisposeItem

#ifndef PriorityQueueMMAF_DisposeSelf
#define PriorityQueueMMAF_DisposeSelf(PQueuePtr,ErrvalPtr)                  (((((PriorityQueueMMAF*)(PQueuePtr))->DisposeSelf) != NULL)?(((PriorityQueueMMAF*)(PQueuePtr))->DisposeSelf(((void*)(PQueuePtr)),((PriorityQueueMMAF*)(PQueuePtr))->arg,(ErrvalPtr))):(1))
#endif // PriorityQueueMMAF_DisposeSelf


static int PriorityQueueMMAF_SiftUp(PriorityQueueMMAF* Q,int Index,int Modifier,ERRVAL_T* Errval){
    //Modifier = 1: Upper Tree with Min at Root (Root has Index "0")
    //Modifier =-1: Lower Tree with Max at Root (Root has Index "1")
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if((Index < 0)||(Index >= Q->Size)){
        PRINT_ERROR("Index is out of range!\0");
        if(Errval != NULL){*Errval = ERRVAL_OUT_OF_RANGE;}
        return 0;
    }
    if((Modifier != -1)&&(Modifier != 1)){
        PRINT_ERROR("Modifier is invalid!\0");
        if(Errval != NULL){*Errval = ERRVAL_INVALID_VAL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    int i = Index;
    void** I1 = (void**)(Q->Items[Index]);
    void** I2;
    int ParentIndex;
    #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
    int CompRes;
    #endif // PRIORITYQUEUEMM_FAILABLE_COMP
    while(i > 1){
        ParentIndex = (i >> 1) - 1;
        I2 = (void**)(Q->Items[ParentIndex]);

        #define PriorityQueueMMAF_SiftUp_Comp   (PriorityQueueMMAF_Compare(Q,I1[1],I2[1],Errval) != Modifier)

        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        CompRes = PriorityQueueMMAF_SiftUp_Comp;
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return 0;
        }

        #undef PriorityQueueMMAF_SiftUp_Comp
        #define PriorityQueueMMAF_SiftUp_Comp   (CompRes)
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP

        if(PriorityQueueMMAF_SiftUp_Comp){return 1;}
        #undef PriorityQueueMMAF_SiftUp_Comp
        I1[0] = &(Q->Items[ParentIndex]);
        I2[0] = &(Q->Items[i]);
        Q->Items[ParentIndex] = (void*)I1;
        Q->Items[i] = (void*)I2;
        i = ParentIndex;
    }
    return 1;
}

static int PriorityQueueMMAF_SiftDown(PriorityQueueMMAF* Q,int Index,int Modifier,ERRVAL_T* Errval){
    //Modifier = 1: Upper Tree with Min at Root (Root has Index "0")
    //Modifier =-1: Lower Tree with Max at Root (Root has Index "1")
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if((Index < 0)||(Index >= Q->Size)){
        PRINT_ERROR("Index is out of range!\0");
        if(Errval != NULL){*Errval = ERRVAL_OUT_OF_RANGE;}
        return 0;
    }
    if((Modifier != -1)&&(Modifier != 1)){
        PRINT_ERROR("Modifier is invalid!\0");
        if(Errval != NULL){*Errval = ERRVAL_INVALID_VAL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    int i = Index;
    void** I1 = (void**)(Q->Items[Index]);
    void** I2;
    void*** I3;
    int ChildIndex;
    int StopIndex = (Q->Count >> 1) - 1;
    int CompRes;
    while(i < StopIndex){
        ChildIndex = (i << 1) + 2;
        I3 = (void***)(&(Q->Items[ChildIndex]));
        CompRes = (PriorityQueueMMAF_Compare(Q,I3[0][1],I3[1][1],Errval) != Modifier);  //"Proof" similar to that for "PriorityQueueMMSF_SiftDown()"
        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return 0;
        }
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP

        ChildIndex = ChildIndex + CompRes;
        I2 = I3[CompRes];

        #define PriorityQueueMMAF_SiftDown_Comp     (PriorityQueueMMAF_Compare(Q,I2[1],I1[1],Errval) != Modifier)

        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        CompRes = PriorityQueueMMAF_SiftDown_Comp;
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return 0;
        }

        #undef PriorityQueueMMAF_SiftDown_Comp
        #define PriorityQueueMMAF_SiftDown_Comp     (CompRes)
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP

        if(PriorityQueueMMAF_SiftDown_Comp){return 1;}
        #undef PriorityQueueMMAF_SiftDown_Comp
        I1[0] = &(Q->Items[ChildIndex]);
        I2[0] = &(Q->Items[i]);
        Q->Items[ChildIndex] = (void*)I1;
        Q->Items[i] = (void*)I2;
        i = ChildIndex;
    }

    //Border-Case:
    if(((i << 1) + 3) == Q->Count){
        ChildIndex = Q->Count - 1;
        I2 = (void**)(Q->Items[ChildIndex]);

        #define PriorityQueueMMAF_SiftDown_Comp     (PriorityQueueMMAF_Compare(Q,I2[1],I1[1],Errval) != Modifier)

        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        CompRes = PriorityQueueMMAF_SiftDown_Comp;
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return 0;
        }

        #undef PriorityQueueMMAF_SiftDown_Comp
        #define PriorityQueueMMAF_SiftDown_Comp     (CompRes)
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP

        if(PriorityQueueMMAF_SiftDown_Comp){return 1;}
        #undef PriorityQueueMMAF_SiftDown_Comp

        I1[0] = &(Q->Items[ChildIndex]);
        I2[0] = &(Q->Items[i]);
        Q->Items[ChildIndex] = (void*)I1;
        Q->Items[i] = (void*)I2;
        i = ChildIndex;
    }


    //In Case the Change-Area is reached:
    ChildIndex = ((i + (i < Q->LstLayerStart)) << (i < Q->LstLayerStart)) + (Modifier * ((Q->LstLayerStart >> 1) + 1));
    if((ChildIndex == Q->Count)&&(ChildIndex & 1)){ChildIndex = Q->Count - 1;}
    if(ChildIndex >= Q->Count){ChildIndex = (ChildIndex >> 1) - 1;}
    if(ChildIndex < StopIndex){ChildIndex = (ChildIndex << 1) + 2;}
    if(((i < Q->LstLayerStart)&&(ChildIndex >= Q->LstLayerStart)&&(ChildIndex + 1 < Q->Count))||((Modifier == -1)&&(i + 1 == Q->Count)&&(!(i & 1)))){
        I3 = (void***)(&(Q->Items[ChildIndex]));
        CompRes = (PriorityQueueMMAF_Compare(Q,I3[0][1],I3[1][1],Errval) != Modifier);  //"Proof" similar to that for "PriorityQueueMMSF_SiftDown()"
        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return 0;
        }
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP

        ChildIndex = ChildIndex + CompRes;
        I2 = I3[CompRes];
    }else{
        I2 = (void**)(Q->Items[ChildIndex]);
    }

    #define PriorityQueueMMAF_SiftDown_Comp     (PriorityQueueMMAF_Compare(Q,I2[1],I1[1],Errval) != Modifier)

    #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
    CompRes = PriorityQueueMMAF_SiftDown_Comp;
    if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
        PRINT_ERROR3;
        return 0;
    }

    #undef PriorityQueueMMAF_SiftDown_Comp
    #define PriorityQueueMMAF_SiftDown_Comp     (CompRes)
    #endif // PRIORITYQUEUEMM_FAILABLE_COMP

    if(PriorityQueueMMAF_SiftDown_Comp){return 1;}
    #undef PriorityQueueMMAF_SiftDown_Comp

    I1[0] = &(Q->Items[ChildIndex]);
    I2[0] = &(Q->Items[i]);
    Q->Items[ChildIndex] = (void*)I1;
    Q->Items[i] = (void*)I2;
    return PriorityQueueMMAF_SiftUp(Q,ChildIndex,-Modifier,Errval);
}

#define PriorityQueueMMAF_GetItemIndex(Q,Item)      ((int)((((uintptr_t)(((void**)Item)[0])) - ((uintptr_t)(&(Q->Items[0])))) / sizeof(void*)))
static int PriorityQueueMMAF_ContainsItem_intern2(PriorityQueueMMAF* Q,PriorityQueueMMAItem* Item,int* ItemIndex){
    void** _ItemsStart = (void**)(&(Q->Items[Q->Size]));
    uintptr_t _MinPtr = (uintptr_t)_ItemsStart;\
    uintptr_t _MyPtr = (uintptr_t)(Item);\
    if(_MyPtr < _MinPtr){return 0;}
    int _Index = (int)((_MyPtr - _MinPtr) / sizeof(void*));
    if((_Index & 1)||((_Index >> 1) >= (Q)->Size)){return 0;}
    int _Index2 = PriorityQueueMMAF_GetItemIndex(Q,Item);
    if(ItemIndex != NULL){*ItemIndex = _Index2;}
    return ((_Index2 >= 0)&&(_Index2 < Q->Count));
}
#define PriorityQueueMMAF_ContainsItem_intern(Q,Item)   (PriorityQueueMMAF_ContainsItem_intern2((Q),(Item),NULL))

#ifdef PRIORITYQUEUEMM_INHERITANCE
PriorityQueueMM* PriorityQueueMMAF_Get_PriorityQueueMM(PriorityQueueMMAF* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return (PriorityQueueMM*)Q;
}
#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMA
PriorityQueueMMA* PriorityQueueMMAF_Get_PriorityQueueMMA(PriorityQueueMMAF* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return (PriorityQueueMMA*)Q;
}
#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMA
#endif // PRIORITYQUEUEMM_INHERITANCE

PriorityQueueMMAF* PriorityQueueMMAF_Create(void* MemPtr,size_t Size,PRIORITYQUEUEMM_COMP_FUNC_PTR,int(*disposeItem)(void*,ERRVAL_T*),int(*disposeSelf)(void*,void*,ERRVAL_T*),void* arg,ERRVAL_T* Errval){
    uint16_t ItemCount = PriorityQueueMMAF_GetItemCountForSize(Size,Errval);
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(MemPtr == NULL){
        PRINT_ERROR("Pointer to Memory \"MemPtr\" must not be NULL!\0");
        if(Errval != NULL){*Errval = ERRVAL_NO_MEM;}
        return NULL;
    }
    if(ItemCount <= 0){
        PRINT_ERROR("\"Size\" too small!\0");
        if(Errval != NULL){*Errval = ERRVAL_NO_MEM;}
        return NULL;
    }
    if(compare == NULL){
        PRINT_ERROR("\"compare\"-function pointer must not be NULL!\0");
        if(Errval != NULL){*Errval = ERRVAL_OP_MISSING;}
        return NULL;
    }
    if(disposeItem == NULL){
        PRINT_ERROR("\"disposeItem\"-function pointer must not be NULL!\0");
        if(Errval != NULL){*Errval = ERRVAL_OP_MISSING;}
        return NULL;
    }

    if((disposeSelf == NULL)&&(arg != NULL)){
        PRINT_ERROR("\"arg\"-parameter must be NULL if \"disposeSelf\" is NULL!\0");
        if(Errval != NULL){*Errval = ERRVAL_INVALID_VAL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1

    PriorityQueueMMAF* res = (PriorityQueueMMAF*)MemPtr;

    #ifdef PRIORITYQUEUEMM_INHERITANCE
    res->Base.IFunc = &PriorityQueueMMAF_AFuncs;
    res->Base.Base.IFunc = &PriorityQueueMMAF_Funcs;
    res->Base.Base.Compare = compare;
    res->Base.Base.DisposeItem = disposeItem;
    res->Base.Base.DisposeSelf = disposeSelf;
    res->Base.Base.arg = arg;
    #else // PRIORITYQUEUEMM_INHERITANCE
    res->Compare = compare;
    res->DisposeItem = disposeItem;
    res->DisposeSelf = disposeSelf;
    res->arg = arg;
    #endif // PRIORITYQUEUEMM_INHERITANCE

    res->Count = 0;
    res->LstLayerStart = 0;
    res->Size = (size_t)ItemCount;
    int i;
    for(i = 0;i < res->Size;i++){
        res->Items[i] = (void*)(&(res->Items[res->Size + (i << 1)]));
        res->Items[res->Size + (i << 1)] = (void*)(&(res->Items[i]));
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        res->Items[res->Size + (i << 1) + 1] = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
    }
    return res;
}

size_t PriorityQueueMMAF_GetSizeFor(uint16_t ItemCount,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    return sizeof(PriorityQueueMMAF) + (sizeof(void*) * ItemCount) * 3;
}

uint16_t PriorityQueueMMAF_GetItemCountForSize(size_t Size,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    if(Size <= sizeof(PriorityQueueMMAF)){return 0;}
    return (uint16_t)((Size - sizeof(PriorityQueueMMAF)) / ((size_t)(sizeof(void*) * 3)));
}

int PriorityQueueMMAF_GetCount(PriorityQueueMMAF* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->Count;
}

int PriorityQueueMMAF_GetReservedItems(PriorityQueueMMAF* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return (int)Q->Size;
}

size_t PriorityQueueMMAF_GetReservedMemory(PriorityQueueMMAF* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return ((((int)Q->Size) * 3 * sizeof(void*)) + sizeof(PriorityQueueMMAF));
}

void* PriorityQueueMMAF_GetMin(PriorityQueueMMAF* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }

    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    void** I = (void**)(Q->Items[0]);
    return I[1];
}

void* PriorityQueueMMAF_GetMax(PriorityQueueMMAF* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    void** I;
    if(Q->Count > 1){
        I = (void**)(Q->Items[1]);
        return I[1];
    }
    I = (void**)(Q->Items[0]);
    return I[1];
}

PriorityQueueMMAItem* PriorityQueueMMAF_GetMinItem(PriorityQueueMMAF* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }

    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return (PriorityQueueMMAItem*)(Q->Items[0]);
}

PriorityQueueMMAItem* PriorityQueueMMAF_GetMaxItem(PriorityQueueMMAF* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q->Count > 1){return (PriorityQueueMMAItem*)Q->Items[1];}
    return (PriorityQueueMMAItem*)(Q->Items[0]);
}

int PriorityQueueMMAF_Insert(PriorityQueueMMAF* Q,void* Item,ERRVAL_T* Errval){
    return (PriorityQueueMMAF_GetInsertedItem(Q,Item,Errval) != NULL);
}

PriorityQueueMMAItem* PriorityQueueMMAF_GetInsertedItem(PriorityQueueMMAF* Q,void* Item,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    if(Q->Count >= Q->Size){
        PRINT_ERROR("PriorityQueue is filled!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_FULL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    int i = Q->Count;
    void** I1 = (void**)(Q->Items[i]);
    I1[0] = (void*)(&(Q->Items[i]));
    I1[1] = Item;
    Q->Count++;
    if(Q->Count == 1){return (PriorityQueueMMAItem*)(Q->Items[0]);}
    if((Q->LstLayerStart << 1) + 2 == i){Q->LstLayerStart = i;}
    //int LayerOffset = (Q->LstLayerStart >> 1) + 1;

    void** I2;

    int Modifier2 = ((i - Q->LstLayerStart) < (Q->LstLayerStart >> 1) + 1); //TRUE if item is a Upper-Tree item
    int Modifier = Modifier2 - !Modifier2;                                  //-1: Lower-Tree-Item, +1: Upper-Tree-Item
    int ChildIndex = ((i - 1) + Modifier * (Q->LstLayerStart >> 1)) >> Modifier2;

    if((!Modifier2)&&(Q->Count & 1)){
        void*** I3 = (void***)(&(Q->Items[ChildIndex]));
        int CompRes = (PriorityQueueMMAF_Compare(Q,I3[0][1],I3[1][1],Errval) != Modifier);
        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return NULL;
        }
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP
        ChildIndex = ChildIndex + CompRes;
        I2 = I3[CompRes];
    }else{
        I2 = (void**)(Q->Items[ChildIndex]);
    }

    //int Modifier = ((i - Q->LstLayerStart) >= LayerOffset); //TRUE if item is a lower-Tree item
    //Modifier = !Modifier - Modifier;                        //-1: Lower-Tree-Item, +1: Upper-Tree-Item
    //int ChildIndex = i + Modifier * LayerOffset;
    //if(ChildIndex >= Q->Count){ChildIndex = (ChildIndex >> 1) - 1;}
    //if(ChildIndex < (Q->Count >> 1) - 1){
    //    ChildIndex = (ChildIndex << 1) + 2;
    //    if(ChildIndex + 1 < Q->Count){
    //        void*** I3 = (void***)(&(Q->Items[ChildIndex]));
    //        CompRes = (PriorityQueueMMAF_Compare(Q,I3[0][1],I3[1][1],Errval) != Modifier);
    //        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
    //        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
    //            PRINT_ERROR3;
    //            return 0;
    //        }
    //        #endif // PRIORITYQUEUEMM_FAILABLE_COMP
    //        ChildIndex = ChildIndex + CompRes;
    //        I2 = I3[CompRes];
    //    }else{
    //        I2 = (void**)(Q->Items[ChildIndex]);
    //    }
    //}

    #define PriorityQueueMMAF_Insert_Comp   (PriorityQueueMMAF_Compare(Q,I2[1],I1[1],Errval) == Modifier)

    #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
    int CompRes = (PriorityQueueMMAF_Compare(Q,I2[1],I1[1],Errval) == Modifier);
    if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
        PRINT_ERROR3;
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        I1[1] = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Count--;
        return NULL;
    }
    #undef PriorityQueueMMAF_Insert_Comp
    #define PriorityQueueMMAF_Insert_Comp   (CompRes)
    #endif // PRIORITYQUEUEMM_FAILABLE_COMP

    if(PriorityQueueMMAF_Insert_Comp){
        I1[0] = (void*)(&(Q->Items[ChildIndex]));
        I2[0] = (void*)(&(Q->Items[i]));
        Q->Items[i] = (void*)I2;
        Q->Items[ChildIndex] = (void*)I1;
        if(!PriorityQueueMMAF_SiftUp(Q,ChildIndex,-Modifier,Errval)){return NULL;}
        return (PriorityQueueMMAItem*)I1;
    }
    #undef PriorityQueueMMAF_Insert_Comp
    if(!PriorityQueueMMAF_SiftUp(Q,i,Modifier,Errval)){return NULL;}
    return (PriorityQueueMMAItem*)I1;
}

void* PriorityQueueMMAF_GetItemOfItem(PriorityQueueMMAF* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    if(Item == NULL){
        PRINT_ERROR("PriorityQueueMMAItem \"Item\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    if(!PriorityQueueMMAF_ContainsItem_intern(Q,Item)){
        PRINT_ERROR("PriorityQueueMMAItem \"Item\" not member of the PriorityQueue!\0");
        if(Errval != NULL){*Errval = ERRVAL_NOT_MEMBER;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    void** I = (void**)Item;
    return I[1];
}

int PriorityQueueMMAF_SetItemOfItem(PriorityQueueMMAF* Q,PriorityQueueMMAItem* Item,void* ItemValue,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    int Index;
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(Item == NULL){
        PRINT_ERROR("PriorityQueueMMAItem \"Item\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(!PriorityQueueMMAF_ContainsItem_intern2(Q,Item,&Index)){
        PRINT_ERROR("PriorityQueueMMAItem \"Item\" not member of the PriorityQueue!\0");
        if(Errval != NULL){*Errval = ERRVAL_NOT_MEMBER;}
        return 0;
    }
    #else // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    Index = PriorityQueueMMAF_GetItemIndex(Q,Item);
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    void** I = (void**)Item;
    if(I[1] == ItemValue){return PriorityQueueMMAF_UpdateItem(Q,Item,Errval);}
    int Modifier = 1;
    if(Index > 1){
        uint16_t LayerStart = ((uint16_t)Index + 2);
        LayerStart |= LayerStart >> 1;
        LayerStart |= LayerStart >> 2;
        LayerStart |= LayerStart >> 4;
        LayerStart |= LayerStart >> 8;
        LayerStart = (LayerStart - 3) >> 1;

        Modifier = ((Index - LayerStart) < (LayerStart >> 1) + 1); //TRUE if item is a Upper-Tree item
        Modifier = Modifier - !Modifier;                           //-1: Lower-Tree-Item, +1: Upper-Tree-Item

        //Upper-Tree => Sift up smaller item : Comp(New,Old) ==  1 == Modifier
        //Lower-Tree => Sift up greater item : Comp(New,Old) == -1 == Modifier

        #define PriorityQueueMMAF_SetItemOfItem_Comp    (PriorityQueueMMAF_Compare(Q,ItemValue,I[1],Errval) == Modifier)
        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        int CompRes = PriorityQueueMMAF_SetItemOfItem_Comp;
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return 0;
        }
        #undef PriorityQueueMMAF_SetItemOfItem_Comp
        #define PriorityQueueMMAF_SetItemOfItem_Comp    (CompRes)
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP

        if(PriorityQueueMMAF_SetItemOfItem_Comp){
            I[1] = ItemValue;
            return PriorityQueueMMAF_SiftUp(Q,Index,Modifier,Errval);
        }
        #undef PriorityQueueMMAF_SetItemOfItem_Comp
    }
    if(Index == 1){Modifier =-1;}
    I[1] = ItemValue;
    if(Q->Count == 1){return 1;}
    return PriorityQueueMMAF_SiftDown(Q,Index,Modifier,Errval);
}

int PriorityQueueMMAF_ContainsItem(PriorityQueueMMAF* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(Item == NULL){
        PRINT_ERROR("PriorityQueueMMAItem \"Item\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return PriorityQueueMMAF_ContainsItem_intern(Q,Item);
}

int PriorityQueueMMAF_UpdateItem(PriorityQueueMMAF* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    int Index;
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(Item == NULL){
        PRINT_ERROR("PriorityQueueMMAItem \"Item\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(!PriorityQueueMMAF_ContainsItem_intern2(Q,Item,&Index)){
        PRINT_ERROR("PriorityQueueMMAItem \"Item\" not member of the PriorityQueue!\0");
        if(Errval != NULL){*Errval = ERRVAL_NOT_MEMBER;}
        return 0;
    }
    #else // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    Index = PriorityQueueMMAF_GetItemIndex(Q,Item);
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q->Count == 1){return 1;}
    void** I1 = (void**)Item;
    int Modifier = 1;
    if(Index > 1){
        uint16_t LayerStart = ((uint16_t)Index + 2);
        LayerStart |= LayerStart >> 1;
        LayerStart |= LayerStart >> 2;
        LayerStart |= LayerStart >> 4;
        LayerStart |= LayerStart >> 8;
        LayerStart = (LayerStart - 3) >> 1;

        Modifier = ((Index - LayerStart) < (LayerStart >> 1) + 1);     //TRUE if item is a Upper-Tree item
        Modifier = Modifier - !Modifier;                               //-1: Lower-Tree-Item, +1: Upper-Tree-Item

        //Upper-Tree => Sift up smaller item : Comp(New,Old) ==  1 == Modifier
        //Lower-Tree => Sift up greater item : Comp(New,Old) == -1 == Modifier

        void** I2 = (void**)Q->Items[((Index >> 1) - 1)];

        #define PriorityQueueMMAF_UpdateItem_Comp    (PriorityQueueMMAF_Compare(Q,I1[1],I2[1],Errval) == Modifier)
        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        int CompRes = PriorityQueueMMAF_UpdateItem_Comp;
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return 0;
        }
        #undef PriorityQueueMMAF_UpdateItem_Comp
        #define PriorityQueueMMAF_UpdateItem_Comp    (CompRes)
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP

        if(PriorityQueueMMAF_UpdateItem_Comp){
            return PriorityQueueMMAF_SiftUp(Q,Index,Modifier,Errval);
        }
        #undef PriorityQueueMMAF_UpdateItem_Comp
    }
    if(Index == 1){Modifier =-1;}
    return PriorityQueueMMAF_SiftDown(Q,Index,Modifier,Errval);
}

int PriorityQueueMMAF_RemoveMin(PriorityQueueMMAF* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    int res = 0;
    void** I1 = (void**)Q->Items[0];
    if(Q->Count == 1){
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        I1[1] = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Count = 0;
        return 1;
    }
    Q->Count--;
    void** I2 = (void**)Q->Items[Q->Count];
    I1[0] = (void*)(&(Q->Items[Q->Count]));
    I2[0] = (void*)(&(Q->Items[0]));
    Q->Items[Q->Count] = (void*)I1;
    Q->Items[0] = (void*)I2;
    #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
    I1[1] = NULL;
    #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
    if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
    if(Q->Count == 1){return 1;}
    res = PriorityQueueMMAF_SiftDown(Q,0,1,Errval);

    if((res == 0)||(Q->Count < 5)){return res;}
    if((Q->Count & 1)&&(((Q->Count - 1) - Q->LstLayerStart) >= (Q->LstLayerStart >> 1) + 1)){return PriorityQueueMMAF_SiftDown(Q,Q->Count - 1,-1,Errval);}
    return res;
}

int PriorityQueueMMAF_RemoveMax(PriorityQueueMMAF* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    int res = 0;
    void** I1;
    if(Q->Count > 2){
        I1 = (void**)Q->Items[1];
        Q->Count--;
        void** I2 = (void**)Q->Items[Q->Count];
        I1[0] = (void*)(&(Q->Items[Q->Count]));
        I2[0] = (void*)(&(Q->Items[1]));
        Q->Items[Q->Count] = (void*)I1;
        Q->Items[1] = (void*)I2;
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        I1[1] = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
        res = PriorityQueueMMAF_SiftDown(Q,1,-1,Errval);
        goto END;
    }
    if(Q->Count == 1){
        I1 = (void**)Q->Items[0];
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        I1[1] = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Count = 0;
        return 1;
    }
    I1 = (void**)Q->Items[1];
    #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
    I1[1] = NULL;
    #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
    Q->Count = 1;
    return 1;

    END:
    if((res == 0)||(Q->Count < 5)){return res;}
    if((Q->Count & 1)&&(((Q->Count - 1) - Q->LstLayerStart) >= (Q->LstLayerStart >> 1) + 1)){return PriorityQueueMMAF_SiftDown(Q,Q->Count - 1,-1,Errval);}
    return res;
}

int PriorityQueueMMAF_RemoveItem(PriorityQueueMMAF* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    int Index;
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(Item == NULL){
        PRINT_ERROR("PriorityQueueMMAItem \"Item\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(!PriorityQueueMMAF_ContainsItem_intern2(Q,Item,&Index)){
        PRINT_ERROR("PriorityQueueMMAItem \"Item\" not member of the PriorityQueue!\0");
        if(Errval != NULL){*Errval = ERRVAL_NOT_MEMBER;}
        return 0;
    }
    #else // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    Index = PriorityQueueMMAF_GetItemIndex(Q,Item);
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    int res = 0;
    void** I1 = (void**)Item;
    if(Index > 1){
        if(Index == Q->Count - 1){
            Q->Count--;
            #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
            I1[1] = NULL;
            #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
            if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
            res = 1;
            goto END;
        }

        uint16_t LayerStart = ((uint16_t)Index + 2);
        LayerStart |= LayerStart >> 1;
        LayerStart |= LayerStart >> 2;
        LayerStart |= LayerStart >> 4;
        LayerStart |= LayerStart >> 8;
        LayerStart = (LayerStart - 3) >> 1;

        int IsUpper = ((Index - LayerStart) < (LayerStart >> 1) + 1); //TRUE if item is a Upper-Tree item
        int Modifier = IsUpper - !IsUpper;                            //-1: Lower-Tree-Item, +1: Upper-Tree-Item

        Q->Count--;
        void** I2 = (void**)Q->Items[Q->Count];
        I1[0] = (void*)(&(Q->Items[Q->Count]));
        I2[0] = (void*)(&(Q->Items[Index]));
        Q->Items[Q->Count] = (void*)I1;
        Q->Items[Index] = (void*)I2;

        int CompRes = PriorityQueueMMAF_Compare(Q,I1[1],I2[1],Errval);
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        I1[1] = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
        if(CompRes == 0){res = 1;goto END;}
        if(CompRes == Modifier){
            res = PriorityQueueMMAF_SiftDown(Q,Index,Modifier,Errval);
            goto END;
        }
        res = PriorityQueueMMAF_SiftUp(Q,Index,Modifier,Errval);
        goto END;
    }
    if(Index == 1){return PriorityQueueMMAF_RemoveMax(Q,Errval);}
    return PriorityQueueMMAF_RemoveMin(Q,Errval);

    END:
    if((res == 0)||(Q->Count < 5)){return res;}
    if((Q->Count & 1)&&(((Q->Count - 1) - Q->LstLayerStart) >= (Q->LstLayerStart >> 1) + 1)){return PriorityQueueMMAF_SiftDown(Q,Q->Count - 1,-1,Errval);}
    return res;
}

int PriorityQueueMMAF_RemoveMinSource(PriorityQueueMMAF* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    void** I1 = (void**)Q->Items[0];
    if(!PriorityQueueMMAF_DisposeItem(Q,I1[1],Errval)){
        PRINT_ERROR3;
        return 0;
    }
    if(Q->Count == 1){
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        I1[1] = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Count = 0;
        return 1;
    }
    Q->Count--;
    void** I2 = (void**)Q->Items[Q->Count];
    I1[0] = (void*)(&(Q->Items[Q->Count]));
    I2[0] = (void*)(&(Q->Items[0]));
    Q->Items[Q->Count] = (void*)I1;
    Q->Items[0] = (void*)I2;
    #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
    I1[1] = NULL;
    #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
    if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
    if(Q->Count == 1){return 1;}
    int res = PriorityQueueMMAF_SiftDown(Q,0,1,Errval);

    if((res == 0)||(Q->Count < 5)){return res;}
    if((Q->Count & 1)&&(((Q->Count - 1) - Q->LstLayerStart) >= (Q->LstLayerStart >> 1) + 1)){return PriorityQueueMMAF_SiftDown(Q,Q->Count - 1,-1,Errval);}
    return res;
}

int PriorityQueueMMAF_RemoveMaxSource(PriorityQueueMMAF* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    int res = 0;
    void** I1;
    if(Q->Count > 2){
        I1 = (void**)Q->Items[1];
        if(!PriorityQueueMMAF_DisposeItem(Q,I1[1],Errval)){
            PRINT_ERROR3;
            return 0;
        }
        Q->Count--;
        void** I2 = (void**)Q->Items[Q->Count];
        I1[0] = (void*)(&(Q->Items[Q->Count]));
        I2[0] = (void*)(&(Q->Items[1]));
        Q->Items[Q->Count] = (void*)I1;
        Q->Items[1] = (void*)I2;
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        I1[1] = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
        res = PriorityQueueMMAF_SiftDown(Q,1,-1,Errval);
        goto END;
    }
    if(Q->Count == 1){
        I1 = (void**)Q->Items[0];
        if(!PriorityQueueMMAF_DisposeItem(Q,I1[1],Errval)){
            PRINT_ERROR3;
            return 0;
        }
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        I1[1] = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Count = 0;
        return 1;
    }
    I1 = (void**)Q->Items[1];
    if(!PriorityQueueMMAF_DisposeItem(Q,I1[1],Errval)){
        PRINT_ERROR3;
        return 0;
    }
    #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
    I1[1] = NULL;
    #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
    Q->Count = 1;
    return 1;

    END:
    if((res == 0)||(Q->Count < 5)){return res;}
    if((Q->Count & 1)&&(((Q->Count - 1) - Q->LstLayerStart) >= (Q->LstLayerStart >> 1) + 1)){return PriorityQueueMMAF_SiftDown(Q,Q->Count - 1,-1,Errval);}
    return res;
}

int PriorityQueueMMAF_RemoveItemSource(PriorityQueueMMAF* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    int Index;
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(Item == NULL){
        PRINT_ERROR("PriorityQueueMMAItem \"Item\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(!PriorityQueueMMAF_ContainsItem_intern2(Q,Item,&Index)){
        PRINT_ERROR("PriorityQueueMMAItem \"Item\" not member of the PriorityQueue!\0");
        if(Errval != NULL){*Errval = ERRVAL_NOT_MEMBER;}
        return 0;
    }
    #else // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    Index = PriorityQueueMMAF_GetItemIndex(Q,Item);
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    int res = 0;
    void** I1 = (void**)Item;
    if(Index > 1){
        if(Index == Q->Count - 1){
            if(!PriorityQueueMMAF_DisposeItem(Q,I1[1],Errval)){
                PRINT_ERROR3;
                return 0;
            }
            Q->Count--;
            #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
            I1[1] = NULL;
            #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
            if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
            res = 1;
            goto END;
        }

        uint16_t LayerStart = ((uint16_t)Index + 2);
        LayerStart |= LayerStart >> 1;
        LayerStart |= LayerStart >> 2;
        LayerStart |= LayerStart >> 4;
        LayerStart |= LayerStart >> 8;
        //LayerStart = ((LayerStart + 1) >> 1) - 2;
        LayerStart = (LayerStart - 3) >> 1;

        int IsUpper = ((Index - LayerStart) < (LayerStart >> 1) + 1); //TRUE if item is a Upper-Tree item
        int Modifier = IsUpper - !IsUpper;                            //-1: Lower-Tree-Item, +1: Upper-Tree-Item

        Q->Count--;
        void** I2 = (void**)Q->Items[Q->Count];
        I1[0] = (void*)(&(Q->Items[Q->Count]));
        I2[0] = (void*)(&(Q->Items[Index]));
        Q->Items[Q->Count] = (void*)I1;
        Q->Items[Index] = (void*)I2;

        int CompRes = PriorityQueueMMAF_Compare(Q,I1[1],I2[1],Errval);
        if(!PriorityQueueMMAF_DisposeItem(Q,I1[1],Errval)){
            PRINT_ERROR3;
            return 0;
        }
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        I1[1] = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
        if(CompRes == 0){res = 1;goto END;}
        if(CompRes == Modifier){
            res = PriorityQueueMMAF_SiftDown(Q,Index,Modifier,Errval);
            goto END;
        }
        res = PriorityQueueMMAF_SiftUp(Q,Index,Modifier,Errval);
        goto END;
    }
    if(Index == 1){return PriorityQueueMMAF_RemoveMaxSource(Q,Errval);}
    return PriorityQueueMMAF_RemoveMinSource(Q,Errval);

    END:
    if((res == 0)||(Q->Count < 5)){return res;}
    if((Q->Count & 1)&&(((Q->Count - 1) - Q->LstLayerStart) >= (Q->LstLayerStart >> 1) + 1)){return PriorityQueueMMAF_SiftDown(Q,Q->Count - 1,-1,Errval);}
    return res;
}

int PriorityQueueMMAF_Clear(PriorityQueueMMAF* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
    int i;
    void** I;
    for(i = Q->Count - 1;i >= 0;i--){
        I = (void**)Q->Items[i];
        I[1] = NULL;
    }
    #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
    Q->Count = 0;
    Q->LstLayerStart = 0;
    return 1;
}

int PriorityQueueMMAF_ClearSource(PriorityQueueMMAF* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAF \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    int i;
    void** I;
    for(i = Q->Count - 1;i >= 0;i--){
        I = (void**)Q->Items[i];
        if(!PriorityQueueMMAF_DisposeItem(Q,I[1],Errval)){
            PRINT_ERROR3;
            return 0;
        }
        Q->Count--;
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        I[1] = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
    }
    Q->Count = 0;
    Q->LstLayerStart = 0;
    return 1;
}

int PriorityQueueMMAF_Dispose(PriorityQueueMMAF* Q,ERRVAL_T* Errval){
    if(!PriorityQueueMMAF_Clear(Q,Errval)){
        PRINT_ERROR3;
        return 0;
    }
    return PriorityQueueMMAF_DisposeSelf(Q,Errval);
}
int PriorityQueueMMAF_DisposeSource(PriorityQueueMMAF* Q,ERRVAL_T* Errval){
    if(!PriorityQueueMMAF_ClearSource(Q,Errval)){
        PRINT_ERROR3;
        return 0;
    }
    return PriorityQueueMMAF_DisposeSelf(Q,Errval);
}

#undef PriorityQueueMMAF_GetItemIndex
#undef PriorityQueueMMAF_ContainsItem_intern

#endif // INCLUDE_PRIORITYQUEUEMMAF

#ifdef PRIORITYQUEUEMM_REM_DEF_INFO
#define PRIORITYQUEUEMM_DISP_INFO
#undef PRINT_INFO
#undef PRINT_INFO2
#define PRINT_INFO(msg)     _PRINT_INFO((msg))
#define PRINT_INFO2(msg)    _PRINT_INFO2((msg))
#endif // PRIORITYQUEUEMM_REM_DEF_INFO


#ifdef INCLUDE_D_SIZE_PRIORITYQUEUEMM

#ifdef PRIORITYQUEUEMM_REM_SDU_INFO
#undef PRIORITYQUEUEMM_DISP_INFO
#undef PRINT_INFO
#undef PRINT_INFO2
#define PRINT_INFO(msg)     do{ }while(0)
#define PRINT_INFO2(msg)    do{ }while(0)
#endif // PRIORITYQUEUEMM_REM_SDU_INFO

const size_t PriorityQueueMMDBlock_Size = sizeof(void*) << 5;
const uintptr_t PriorityQueueMMDBlock_SizeMask = (~((uintptr_t)((sizeof(void*) << 5) - 1)));
int PriorityQueueMMD_Shift = -1;

static PriorityQueueMMDUnit* PriorityQueueMMDUnit_Create(ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}

    if(PriorityQueueMMD_Shift < 0){
        if(sizeof(void*) == 1){PriorityQueueMMD_Shift = 0;}
        if(sizeof(void*) == 2){PriorityQueueMMD_Shift = 1;}
        if(sizeof(void*) == 4){PriorityQueueMMD_Shift = 2;}
        if(sizeof(void*) == 8){PriorityQueueMMD_Shift = 3;}

        //For Future systems:
        if(sizeof(void*) == 16){PriorityQueueMMD_Shift = 4;}
        if(sizeof(void*) == 32){PriorityQueueMMD_Shift = 5;}
        if(sizeof(void*) == 64){PriorityQueueMMD_Shift = 6;}
    }
    if(PriorityQueueMMD_Shift < 0){
        PRINT_ERROR("The Dynamic versions of \"PriorityQueueMM\" are currently not supported for Pointer-sizes that are not a power of 2!\0");
        if(Errval != NULL){*Errval = ERRVAL_NOT_SUPP;}
        return NULL;
    }

    void** Mem = (void**)PRIORITYQUEUEMM_ALLOCATE_MEM;

    if(Mem == NULL){
        PRINT_ERROR("Memory for \"PriorityQueueMMDUnit\" could not be allocated!\0");
        if(Errval != NULL){*Errval = ERRVAL_NO_MEM;}
        return NULL;
    }


    int FirstBlockIndex = (int)(((uintptr_t)Mem) & (PriorityQueueMMDBlock_Size - 1));
    if(FirstBlockIndex){FirstBlockIndex = (PriorityQueueMMDBlock_Size - FirstBlockIndex) >> PriorityQueueMMD_Shift;}
    int FrontMem = FirstBlockIndex;
    int BackMem = 32 - FrontMem;
    PriorityQueueMMDBlock* Block[3];
    PriorityQueueMMDUnit* UnitPtr = NULL;
    int i = 0;
    while(FrontMem >= 8){
        Block[i] = (PriorityQueueMMDBlock*)(&(Mem[(i << 3)]));
        FrontMem = FrontMem - 8;
        i++;
        if(i > 2){break;}
    }
    if(FrontMem >= 4){UnitPtr = (PriorityQueueMMDUnit*)(&(Mem[FirstBlockIndex - 4]));}
    int j = 0;
    if(i < 3){
        while(BackMem >= 8){
            Block[i] = (PriorityQueueMMDBlock*)(&(Mem[FirstBlockIndex + 96 + (j << 3)]));
            BackMem = BackMem - 8;
            i++;
            j++;
            if(i > 2){break;}
        }
    }
    if(UnitPtr == NULL){UnitPtr = (PriorityQueueMMDUnit*)(&(Mem[124]));}

    UnitPtr->Alloc_Start = (void*)Mem;
    UnitPtr->Next = Block[0];
    UnitPtr->Prev = Block[2];
    UnitPtr->Owner = NULL;

    Mem[FirstBlockIndex] = (void*)(Block[0]);
    Mem[FirstBlockIndex + 32] = (void*)(Block[1]);
    Mem[FirstBlockIndex + 64] = (void*)(Block[2]);

    for(i = 0;i < 3;i++){
        Block[i]->UnitPtr = UnitPtr;
        Block[i]->BackPtr = (void*)(&(Mem[FirstBlockIndex + (i << 5)]));
    }
    //Block[0]->BackPtr = (void*)(&(Mem[FirstBlockIndex]));
    //Block[1]->BackPtr = (void*)(&(Mem[FirstBlockIndex + 32]));
    //Block[2]->BackPtr = (void*)(&(Mem[FirstBlockIndex + 64]));
    Block[0]->Offset = ((intptr_t)(-2));
    Block[0]->Other = Block[0];
    Block[0]->Parent = Block[0];
    Block[0]->Child = Block[1];
    Block[1]->Offset = 30;
    Block[1]->Other = Block[1];
    Block[1]->Parent = Block[0];
    Block[1]->Child = Block[2];
    Block[2]->Offset = 62;
    Block[2]->Other = NULL;
    Block[2]->Parent = Block[1];
    Block[2]->Child = NULL;

    return UnitPtr;
}

#define PriorityQueueMMDUnit_Prev(Unit)                         ((Unit)->Prev->UnitPtr)
#define PriorityQueueMMDUnit_Next(Unit)                         ((Unit)->Next->UnitPtr)
#define PriorityQueueMMDUnit_FirstBlock(Unit)                   ((Unit)->Prev->UnitPtr->Next)
#define PriorityQueueMMDUnit_LastBlock(Unit)                    ((Unit)->Next->UnitPtr->Prev)

#define PriorityQueueMMDBlock_Get(Ptr)                          (*((PriorityQueueMMDBlock**)(((uintptr_t)(Ptr)) & PriorityQueueMMDBlock_SizeMask)))
#define PriorityQueueMMDBlock_IsFirst(BlockPtr)                 (!((int)((BlockPtr)->Offset + 2)))
#define PriorityQueueMMDBlock_GetItemPtr(BlockPtr,Index)        ((Index)?(&(((void**)((BlockPtr)->BackPtr))[(Index)])):(&((BlockPtr)->FrstItem)))
#define PriorityQueueMMDBlock_GetItem(BlockPtr,Index)           ((Index)?(((void**)((BlockPtr)->BackPtr))[(Index)]):((BlockPtr)->FrstItem))
#define PriorityQueueMMDBlock_SetItem(BlockPtr,Index,Value)     ({void** _Item = PriorityQueueMMDBlock_GetItemPtr((BlockPtr),(Index));*_Item = (void*)(Value);})
#define PriorityQueueMMDBlock_GetIndexPtr(BlockPtr,Index)       ((void*)(&(((void**)(BlockPtr)->BackPtr)[(Index)])))
#define PriorityQueueMMDBlock_GetIndexValue(BlockPtr,IndexPtr)  ((int)((((uintptr_t)(IndexPtr)) - ((uintptr_t)((BlockPtr)->BackPtr))) >> PriorityQueueMMD_Shift))

#define PriorityQueueMMDBlock_GetPrev(BlockPtr)                 (((BlockPtr) != PriorityQueueMMDUnit_FirstBlock(((BlockPtr)->UnitPtr)))?(*((PriorityQueueMMDBlock**)(((BlockPtr)->BackPtr) - PriorityQueueMMDBlock_Size))):((BlockPtr)->UnitPtr->Prev))
#define PriorityQueueMMDBlock_GetNext(BlockPtr)                 (((BlockPtr) != PriorityQueueMMDUnit_LastBlock(((BlockPtr)->UnitPtr)))?(*((PriorityQueueMMDBlock**)(((BlockPtr)->BackPtr) + PriorityQueueMMDBlock_Size))):((BlockPtr)->UnitPtr->Next))
#define PriorityQueueMMDBlock_GetNumber(BlockPtr)               (((int)((BlockPtr)->Offset + 2)) >> 5)
#define PriorityQueueMMDBlock_GetParentIndex(BlockPtr,Index)    ((PriorityQueueMMDBlock_IsFirst((BlockPtr)))?((((int)((Index) + (BlockPtr)->Offset)) >> 1) - 3 - ((BlockPtr)->Parent->Offset + ((intptr_t)2))):((Index) >> 1))

#ifdef PRIORITYQUEUEMM_DISP_INFO
#define PriorityQueueMMDBlock_PrintIndexPtr(Ptr)                ({\
                                                                 PriorityQueueMMDBlock* _Block = PriorityQueueMMDBlock_Get((Ptr));\
                                                                 int _Index = PriorityQueueMMDBlock_GetIndexValue(_Block,(Ptr));\
                                                                 printf("[INFO] %p resolves to Totalindex %i\n",(Ptr),(_Index + _Block->Offset));\
                                                                 })
#else // PRIORITYQUEUEMM_DISP_INFO
#define PriorityQueueMMDBlock_PrintIndexPtr(Ptr)                do{ }while(0)
#endif // PRIORITYQUEUEMM_DISP_INFO

static PriorityQueueMMDUnit* PriorityQueueMMDUnit_Create2(PriorityQueueMMDUnit* Prev,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    if(Prev == NULL){
        PRINT_ERROR("\"Prev\" is not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    PriorityQueueMMDUnit* res = PriorityQueueMMDUnit_Create(Errval);
    if(res == NULL){PRINT_ERROR3;return NULL;}
    PriorityQueueMMDUnit* Fst = PriorityQueueMMDUnit_Next(Prev);
    PriorityQueueMMDBlock* FUFBlock = PriorityQueueMMDUnit_FirstBlock(Fst);         //"FUFBlock" stands for "First-Unit-First-Block"
    PriorityQueueMMDBlock* LULBlock = PriorityQueueMMDUnit_LastBlock(Prev);         //"LULBlock" stands for "Last-Unit-Last-Block"
    PriorityQueueMMDBlock* CUFBlock = PriorityQueueMMDUnit_FirstBlock(res);         //"CUFBlock" stands for "Current-Unit-First-Block"
    PriorityQueueMMDBlock* CUMBlock = PriorityQueueMMDBlock_GetNext(CUFBlock);      //"CUMBlock" stands for "Current-Unit-Middle-Block"
    PriorityQueueMMDBlock* CULBlock = PriorityQueueMMDUnit_LastBlock(res);          //"CULBlock" stands for "Current-Unit-Last-Block"
    Fst->Prev = CULBlock;
    Prev->Next = CUFBlock;
    res->Prev = LULBlock;
    res->Next = FUFBlock;
    CUFBlock->Offset = LULBlock->Offset + 32;
    CUMBlock->Offset = LULBlock->Offset + 64;
    CULBlock->Offset = LULBlock->Offset + 96;
    res->Owner = Prev->Owner;
    CUFBlock->Child = NULL;
    CUMBlock->Child = NULL;
    CUFBlock->Other = NULL;
    CUMBlock->Other = NULL;
    PriorityQueueMMDBlock* PrtBlock = LULBlock->Parent;
    if(PrtBlock->Child == LULBlock){
        CUFBlock->Parent = PrtBlock;
        PrtBlock = PriorityQueueMMDBlock_GetNext(PrtBlock);
        CUMBlock->Parent = PrtBlock;
        PrtBlock->Child = CUMBlock;
        CULBlock->Parent = PrtBlock;

        //Computing the "Other"-Values:
        if(((int)(CUFBlock->Offset)) == 94){
            CUFBlock->Other = LULBlock;
            LULBlock->Other = CUFBlock;
        }else{
            CUFBlock->Other = CUFBlock->Parent->Other->Child;
            if(CUFBlock->Other != NULL){
                CUFBlock->Other = PriorityQueueMMDBlock_GetNext(CUFBlock->Other);
                CUFBlock->Other->Other = CUFBlock;
            }
        }
        CUMBlock->Other = CUMBlock->Parent->Other->Child;
        if(CUMBlock->Other != NULL){
            CUMBlock->Other->Other = CUMBlock;
            CULBlock->Other = PriorityQueueMMDBlock_GetNext(CUMBlock->Other);
            CULBlock->Other->Other = CULBlock;
        }

    }else{
        PrtBlock = PriorityQueueMMDBlock_GetNext(PrtBlock);
        CUFBlock->Parent = PrtBlock;
        PrtBlock->Child = CUFBlock;
        CUMBlock->Parent = PrtBlock;
        PrtBlock = PriorityQueueMMDBlock_GetNext(PrtBlock);
        CULBlock->Parent = PrtBlock;
        PrtBlock->Child = CULBlock;

        //Computing the "Other"-Values:
        CUFBlock->Other = CUFBlock->Parent->Other->Child;
        if(CUFBlock->Other != NULL){
            CUFBlock->Other->Other = CUFBlock;
            CUMBlock->Other = PriorityQueueMMDBlock_GetNext(CUFBlock->Other);
            CUMBlock->Other->Other = CUMBlock;
        }
        CULBlock->Other = CULBlock->Parent->Other->Child;
        if(CULBlock->Other != NULL){
            CULBlock->Other->Other = CULBlock;
        }
    }

    #ifdef PRIORITYQUEUEMM_DISP_INFO
    printf("[INFO] Created Unit %i (Start:%p UnitPtr:%p):\n",(((int)(CUFBlock->Offset + 2)) / 96),res->Alloc_Start,res);
    printf("       Block %i: %p (Items: %p)\n",(((int)(CUFBlock->Offset + 2)) >> 5),CUFBlock,CUFBlock->BackPtr);
    printf("       Block %i: %p (Items: %p)\n",(((int)(CUMBlock->Offset + 2)) >> 5),CUMBlock,CUMBlock->BackPtr);
    printf("       Block %i: %p (Items: %p)\n",(((int)(CULBlock->Offset + 2)) >> 5),CULBlock,CULBlock->BackPtr);
    #endif // PRIORITYQUEUEMM_DISP_INFO

    return res;
}

static int PriorityQueueMMDUnit_Dispose(PriorityQueueMMDUnit* U,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    if(U == NULL){
        PRINT_ERROR("\"U\" is not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    PriorityQueueMMDBlock* PULBlock = U->Prev;                              //"PULBlock" stands for "Previous-Unit-Last-Block"
    PriorityQueueMMDBlock* NUFBlock = U->Next;                              //"NUFBlock" stands for "Next-Unit-First-Block"
    PriorityQueueMMDUnit* PrevUnit = PULBlock->UnitPtr;
    PriorityQueueMMDUnit* NextUnit = NUFBlock->UnitPtr;
    PriorityQueueMMDBlock* Blocks[3];
    Blocks[0] = PriorityQueueMMDUnit_FirstBlock(U);
    Blocks[1] = PriorityQueueMMDBlock_GetNext(Blocks[0]);
    Blocks[2] = PriorityQueueMMDBlock_GetNext(Blocks[1]);
    int i;
    for(i = 0;i < 3;i++){
        if(Blocks[i]->Other != NULL){Blocks[i]->Other->Other = NULL;}
        if((Blocks[i]->Parent != NULL)&&(Blocks[i]->Parent->Child == Blocks[i])){Blocks[i]->Parent->Child = NULL;}
    }
    if(PrevUnit != U){
        PrevUnit->Next = NUFBlock;
        NextUnit->Prev = PULBlock;
    }
    PRIORITYQUEUEMM_RELEASE_MEM(U->Alloc_Start);
    return 1;
}

#ifdef PRIORITYQUEUEMM_REM_SDU_INFO
#define PRIORITYQUEUEMM_DISP_INFO
#undef PRINT_INFO
#undef PRINT_INFO2
#define PRINT_INFO(msg)     _PRINT_INFO((msg))
#define PRINT_INFO2(msg)    _PRINT_INFO2((msg))
#endif // PRIORITYQUEUEMM_REM_SDU_INFO


#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMAD

#ifdef PRIORITYQUEUEMM_REM_ADU_INFO
#undef PRIORITYQUEUEMM_DISP_INFO
#undef PRINT_INFO
#undef PRINT_INFO2
#define PRINT_INFO(msg)     do{ }while(0)
#define PRINT_INFO2(msg)    do{ }while(0)
#endif // PRIORITYQUEUEMM_REM_ADU_INFO

#define PRIORITYQUEUEMMAD_REF32(Ptr)                            (!(((uintptr_t)(Ptr)) & (~PriorityQueueMMDBlock_SizeMask)))
#define PRIORITYQUEUEMMAD_REF31(Ptr)                            (PRIORITYQUEUEMMAD_REF32((((void**)Ptr) + 1)))

const int PriorityQueueMMADUnit_BufferItems = 48 * PRIORITYQUEUEMMAD_BUFFER + 24;

#ifndef USE_PRIORITYQUEUEMMAD_V2

//Unit-Basics:
//------------

//"Owner": the data-structure this "PriorityQueueMMADUnit" belongs to
#define PriorityQueueMMADUnit_GetOwner(Unit)                    ((Unit)->SpecBlock[0])
#define PriorityQueueMMADUnit_SetOwner(Unit,Value)              ((Unit)->SpecBlock[0] = ((void*)(Value)))

//"Alloc_Start": Pointer returned from the Allocation of the Unit. (Necessary to dispose the unit)
#define PriorityQueueMMADUnit_GetAlloc_Start(Unit)              ((Unit)->SpecBlock[1])
#define PriorityQueueMMADUnit_SetAlloc_Start(Unit,Value)        ((Unit)->SpecBlock[1] = ((void*)(Value)))



//Unit-AVL-Tree:
//--------------

//"Parent": Parent-Unit in the AVL-Tree that is used to check the "PriorityQueueMMAItem"s
#define PriorityQueueMMADUnit_GetParent(Unit)                   ((PriorityQueueMMADUnit*)((Unit)->Block3->Ptr1))
#define PriorityQueueMMADUnit_GetParentRef(Unit)                ((PriorityQueueMMADUnit**)(&((Unit)->Block3->Ptr1)))
#define PriorityQueueMMADUnit_SetParent(Unit,Value)             (((Unit)->Block3->Ptr1) = ((void*)(Value)))

//"Child1": Child1-Unit in the AVL-Tree that is used to check the "PriorityQueueMMAItem"s
#define PriorityQueueMMADUnit_GetChild1(Unit)                   ((PriorityQueueMMADUnit*)((Unit)->Block2->Ptr1))
#define PriorityQueueMMADUnit_GetChild1Ref(Unit)                ((PriorityQueueMMADUnit**)(&((Unit)->Block2->Ptr1)))
#define PriorityQueueMMADUnit_SetChild1(Unit,Value)             (((Unit)->Block2->Ptr1) = ((void*)(Value)))

//"Child2": Child2-Unit in the AVL-Tree that is used to check the "PriorityQueueMMAItem"s
#define PriorityQueueMMADUnit_GetChild2(Unit)                   ((PriorityQueueMMADUnit*)((Unit)->Block2->Ptr2))
#define PriorityQueueMMADUnit_GetChild2Ref(Unit)                ((PriorityQueueMMADUnit**)(&((Unit)->Block2->Ptr2)))
#define PriorityQueueMMADUnit_SetChild2(Unit,Value)             (((Unit)->Block2->Ptr2) = ((void*)(Value)))

//"Balance": Balance-Value in the AVL-Tree that is used to check the "PriorityQueueMMAItem"s
#define PriorityQueueMMADUnit_GetBalance(Unit)                  ((int)((Unit)->Block2->Val1))
#define PriorityQueueMMADUnit_SetBalance(Unit,Value)            (((Unit)->Block2->Val1) = ((intptr_t)(Value)))

//"Maxlength": Maxlength-Value in the AVL-Tree that is used to check the "PriorityQueueMMAItem"s
#define PriorityQueueMMADUnit_GetMaxlength(Unit)                ((int)((Unit)->Block3->Val1))
#define PriorityQueueMMADUnit_SetMaxlength(Unit,Value)          (((Unit)->Block3->Val1) = ((intptr_t)(Value)))



//Unit-Item-Management:
//---------------------

//"PrevEmptyUnit": Advances to the previous Unit that is not filled. (Necessary to Remove a unit from a list of not-filled-Units)
//                 The returned unit does not have to be empty, but it must not be filled!
#define PriorityQueueMMADUnit_GetPrevEmptyUnit(Unit)            ((PriorityQueueMMADUnit*)((Unit)->Block1->Ptr1))
#define PriorityQueueMMADUnit_SetPrevEmptyUnit(Unit,Value)      (((Unit)->Block1->Ptr1) = ((void*)(Value)))

//"NextEmptyUnit": Advances to the next Unit in case "NextEmptyItem" can not return an unused item in this unit.
//                 The returned unit does not have to be empty, but it must not be filled!
#define PriorityQueueMMADUnit_GetNextEmptyUnit(Unit)            ((PriorityQueueMMADUnit*)((Unit)->Block1->Ptr2))
#define PriorityQueueMMADUnit_SetNextEmptyUnit(Unit,Value)      (((Unit)->Block1->Ptr2) = ((void*)(Value)))

//"NextEmptyItem": Item-Management to find the next unused item if available.
#define PriorityQueueMMADUnit_GetNextEmptyItem(Unit)            ((PriorityQueueMMAItem*)((Unit)->Block3->Ptr2))
#define PriorityQueueMMADUnit_SetNextEmptyItem(Unit,Value)      (((Unit)->Block3->Ptr2) = ((void*)(Value)))

//"ItemCount":The Number of Items this Unit contains. Must not exceed 48
#define PriorityQueueMMADUnit_GetItemCount(Unit)                ((int)((Unit)->Block1->Val1))
#define PriorityQueueMMADUnit_SetItemCount(Unit,Value)          (((Unit)->Block1->Val1) = ((intptr_t)(Value)))



#define PriorityQueueMMADUnit_Prev(Unit)                        (((Unit)->Block1->Prev != NULL)?((Unit)->Block1->Prev->UnitPtr):(NULL))
#define PriorityQueueMMADUnit_Next(Unit)                        (((Unit)->Block3->Next != NULL)?((Unit)->Block3->Next->UnitPtr):(NULL))
#define PriorityQueueMMADUnit_SetPrev(Unit,Value)               ((Unit)->Block1->Prev = (((Value) != NULL)?(((PriorityQueueMMADUnit*)(Value))->Block3):(NULL)))
#define PriorityQueueMMADUnit_SetNext(Unit,Value)               ((Unit)->Block3->Next = (((Value) != NULL)?(((PriorityQueueMMADUnit*)(Value))->Block1):(NULL)))


#define PriorityQueueMMADBlock_Get(Ptr)                         (*((PriorityQueueMMADBlock**)(((uintptr_t)(Ptr)) & PriorityQueueMMDBlock_SizeMask)))
#define PriorityQueueMMADBlock_GetItemPtr(BlockPtr,Index)       ((Index)?(&(((void**)((BlockPtr)->BackPtr))[(Index)])):(&((BlockPtr)->FrstItem)))
#define PriorityQueueMMADBlock_GetIndexPtr(BlockPtr,Index)      ((void*)(&(((void**)(BlockPtr)->BackPtr)[(Index)])))
#define PriorityQueueMMADBlock_GetIndexValue(BlockPtr,IndexPtr) ((int)((((uintptr_t)(IndexPtr)) - ((uintptr_t)((BlockPtr)->BackPtr))) >> PriorityQueueMMD_Shift))





#define PriorityQueueMMADUnit_GetChild1Maxlength(Unit)          ((PriorityQueueMMADUnit_GetChild1((Unit)) == NULL)?(0):(PriorityQueueMMADUnit_GetMaxlength(PriorityQueueMMADUnit_GetChild1((Unit))) + 1))
#define PriorityQueueMMADUnit_GetChild2Maxlength(Unit)          ((PriorityQueueMMADUnit_GetChild2((Unit)) == NULL)?(0):(PriorityQueueMMADUnit_GetMaxlength(PriorityQueueMMADUnit_GetChild2((Unit))) + 1))

#define PriorityQueueMMADUnit_Get(Ptr)                          ((PriorityQueueMMADBlock_Get((Ptr)))->UnitPtr)
#define PriorityQueueMMADUnit_GetItemStart(Unit)                ((Unit)->Block1->BackPtr)


#define PriorityQueueMMAItem_GetPtr1(AItem)                     ((PRIORITYQUEUEMMAD_REF32(AItem))?((*((PriorityQueueMMADBlock**)(AItem)))->FrstItem):(*((void**)(AItem))))
#define PriorityQueueMMAItem_GetPtr1Ref(AItem)                  ((PRIORITYQUEUEMMAD_REF32(AItem))?(&((*((PriorityQueueMMADBlock**)(AItem)))->FrstItem)):((void**)(AItem)))
#define PriorityQueueMMAItem_GetPtr2(AItem)                     (*(((void**)(AItem)) + 1))
#define PriorityQueueMMAItem_GetPtr2Ref(AItem)                  (((void**)(AItem)) + 1)
#define PriorityQueueMMAItem_SetPtr1(AItem,Value)               ((PRIORITYQUEUEMMAD_REF32(AItem))?(((*((PriorityQueueMMADBlock**)(AItem)))->FrstItem) = ((void*)(Value))):((*((void**)(AItem))) = ((void*)(Value))))
#define PriorityQueueMMAItem_SetPtr2(AItem,Value)               (PriorityQueueMMAItem_GetPtr2((AItem)) = ((void*)(Value)))



#else // USE_PRIORITYQUEUEMMAD_V2



#define PTR_ADD(Ptr,Value)              ((void*)(((char*)(Ptr)) + ((int)(Value))))
#define PTR_SUB(Ptr,Value)              ((void*)(((char*)(Ptr)) - ((int)(Value))))
#define VOIDPTR_ADD(Ptr,Value)          ((void*)(((void**)(Ptr)) + ((int)(Value))))
#define VOIDPTR_SUB(Ptr,Value)          ((void*)(((void**)(Ptr)) - ((int)(Value))))

//#define UPTRVAL_GETBYTE1(PtrVal)        ((PtrVal) & ((uintptr_t)255))
#define UPTRVAL_GETBYTE1(PtrVal)        ((uintptr_t)(*((uint8_t*)(&(PtrVal)))))
//#define UPTRVAL_GETBYTE2(PtrVal)        (((PtrVal) >> ((uintptr_t)8)) & ((uintptr_t)255))
#define UPTRVAL_GETBYTE2(PtrVal)        ((uintptr_t)(*(((uint8_t*)(&(PtrVal))) + 1)))

//"UPTRVAL_SETBYTE1": Sets the first byte (bit-range of 1 to 128) of the uintptr_t type "PtrVal" to "Value"
//#define UPTRVAL_SETBYTE1(PtrVal,Value)  ((PtrVal) = (((PtrVal) & (~((uintptr_t)255))) | (((uintptr_t)(Value)) & ((uintptr_t)255))))
#define UPTRVAL_SETBYTE1(PtrVal,Value)  ((*((uint8_t*)(&(PtrVal)))) = ((uint8_t)((Value) & 255)))

//"UPTRVAL_SETBYTE2": Sets the second byte (bit-range of 256 to 32768) of the uintptr_t type "PtrVal" to "Value"
//#define UPTRVAL_SETBYTE2(PtrVal,Value)  ((PtrVal) = (((PtrVal) & (~((uintptr_t)65280))) | ((((uintptr_t)(Value)) & ((uintptr_t)255)) << ((uintptr_t)8))))
#define UPTRVAL_SETBYTE2(PtrVal,Value)  ((*(((uint8_t*)(&(PtrVal))) + 1)) = ((uint8_t)((Value) & 255)))



//Unit-Basics:
//------------

//"Owner": the data-structure this "PriorityQueueMMADUnit" belongs to
#define PriorityQueueMMADUnit_GetOwner(Unit)                    ((Unit)->Owner)
#define PriorityQueueMMADUnit_SetOwner(Unit,Value)              ((Unit)->Owner = ((void*)(Value)))

//"Alloc_Start": Pointer returned from the Allocation of the Unit. (Necessary to dispose the unit)
#define PriorityQueueMMADUnit_GetAlloc_Start(Unit)              (VOIDPTR_SUB(((Unit)->BackPtr),(UPTRVAL_GETBYTE2(((Unit)->Data1)))))
#define PriorityQueueMMADUnit_SetAlloc_Start(Unit,Value)        (UPTRVAL_SETBYTE2(((Unit)->Data1),((((void**)((Unit)->BackPtr)) - ((void**)(Value))))))



//Unit-AVL-Tree:
//--------------

//"Parent": Parent-Unit in the AVL-Tree that is used to check the "PriorityQueueMMAItem"s
#define PriorityQueueMMADUnit_GetParent(Unit)                   ((Unit)->Parent)
#define PriorityQueueMMADUnit_GetParentRef(Unit)                (&((Unit)->Parent))
#define PriorityQueueMMADUnit_SetParent(Unit,Value)             ((Unit)->Parent = (Value))

//"Child1": Child1-Unit in the AVL-Tree that is used to check the "PriorityQueueMMAItem"s
#define PriorityQueueMMADUnit_GetChild1(Unit)                   ((Unit)->Child1)
#define PriorityQueueMMADUnit_GetChild1Ref(Unit)                (&((Unit)->Child1))
#define PriorityQueueMMADUnit_SetChild1(Unit,Value)             ((Unit)->Child1 = (Value))

//"Child2": Child2-Unit in the AVL-Tree that is used to check the "PriorityQueueMMAItem"s
#define PriorityQueueMMADUnit_GetChild2(Unit)                   ((Unit)->Child2)
#define PriorityQueueMMADUnit_GetChild2Ref(Unit)                (&((Unit)->Child2))
#define PriorityQueueMMADUnit_SetChild2(Unit,Value)             ((Unit)->Child2 = (Value))

//"Maxlength": Maxlength-Value in the AVL-Tree that is used to check the "PriorityQueueMMAItem"s
#define PriorityQueueMMADUnit_GetMaxlength(Unit)                ((int)((Unit)->Maxlength))
#define PriorityQueueMMADUnit_SetMaxlength(Unit,Value)          (((Unit)->Maxlength) = ((intptr_t)(Value)))

#define PriorityQueueMMADUnit_GetChild1Maxlength(Unit)          ((PriorityQueueMMADUnit_GetChild1((Unit)) == NULL)?(0):(PriorityQueueMMADUnit_GetMaxlength(PriorityQueueMMADUnit_GetChild1((Unit))) + 1))
#define PriorityQueueMMADUnit_GetChild2Maxlength(Unit)          ((PriorityQueueMMADUnit_GetChild2((Unit)) == NULL)?(0):(PriorityQueueMMADUnit_GetMaxlength(PriorityQueueMMADUnit_GetChild2((Unit))) + 1))

//"Balance": Balance-Value in the AVL-Tree that is used to check the "PriorityQueueMMAItem"s
#define PriorityQueueMMADUnit_GetBalance(Unit)                  ((int)(PriorityQueueMMADUnit_GetChild2Maxlength((Unit)) - PriorityQueueMMADUnit_GetChild1Maxlength((Unit))))



//Unit-Item-Management:
//---------------------

//"PrevEmptyUnit": Advances to the previous Unit that is not filled. (Necessary to Remove a unit from a list of not-filled-Units)
//                 The returned unit does not have to be empty, but it must not be filled!
#define PriorityQueueMMADUnit_GetPrevEmptyUnit(Unit)            ((Unit)->Prev)
#define PriorityQueueMMADUnit_SetPrevEmptyUnit(Unit,Value)      ((Unit)->Prev = (Value))

//"NextEmptyUnit": Advances to the next Unit in case "NextEmptyItem" can not return an unused item in this unit.
//                 The returned unit does not have to be empty, but it must not be filled!
#define PriorityQueueMMADUnit_GetNextEmptyUnit(Unit)            ((Unit)->Next)
#define PriorityQueueMMADUnit_SetNextEmptyUnit(Unit,Value)      ((Unit)->Next = (Value))

//"ItemCount":The Number of Items this Unit contains. Must not exceed 48
#define PriorityQueueMMADUnit_GetItemCount(Unit)                ((int)(UPTRVAL_GETBYTE2(((Unit)->Data2))))
#define PriorityQueueMMADUnit_SetItemCount(Unit,Value)          (UPTRVAL_SETBYTE2(((Unit)->Data2),(Value)))

//"NextEmptyItem": Item-Management to find the next unused item if available.
#define PriorityQueueMMADUnit_GetNextEmptyItem(Unit)            ((PriorityQueueMMAItem*)(((UPTRVAL_GETBYTE1(((Unit)->Data2))) == 255)?(NULL):(VOIDPTR_ADD(((Unit)->BackPtr),(UPTRVAL_GETBYTE1(((Unit)->Data2)))))))
#define PriorityQueueMMADUnit_SetNextEmptyItem(Unit,Value)      (UPTRVAL_SETBYTE1(((Unit)->Data2),((uintptr_t)(((Value) == NULL)?(255):(((void**)(Value)) - ((void**)((Unit)->BackPtr)))))))


//Alternative to "Value / 31". Should work at least up to 961 (which is much higher than any value that should be divided by 31 in this data-structure):
#define DIV31(Value)                                            (((Value) + 1 + ((Value) >> 5)) >> 5)

#define PriorityQueueMMADUnit_CorrectIndex(Index)               (DIV31((Index)) + 1 + (Index))


#define PriorityQueueMMADUnit_Prev(Unit)                        ((Unit)->Prev)
#define PriorityQueueMMADUnit_Next(Unit)                        ((Unit)->Next)

#define PriorityQueueMMADUnit_Get(Ptr)                          (*((PriorityQueueMMADUnit**)(((uintptr_t)(Ptr)) & PriorityQueueMMDBlock_SizeMask)))
#define PriorityQueueMMADUnit_GetItemPtr(Unit,Index)            (&(((void**)(Unit)->BackPtr)[(Index)]))
#define PriorityQueueMMADUnit_GetIndexPtr(Unit,Index)           ((void*)(&(((void**)(Unit)->BackPtr)[(Index)])))
#define PriorityQueueMMADUnit_GetIndexValue(Unit,IndexPtr)      ((int)((((uintptr_t)(IndexPtr)) - ((uintptr_t)((Unit)->BackPtr))) >> PriorityQueueMMD_Shift))

//Special
//-------

#define PriorityQueueMMADUnit_GetMaxPtrCount(Unit)              (((int)(UPTRVAL_GETBYTE1(((Unit)->Data1)) & ((uintptr_t)31))) + 93)
#define PriorityQueueMMADUnit_SetMaxPtrCount(Unit,Value)        (UPTRVAL_SETBYTE1(((Unit)->Data1),((UPTRVAL_GETBYTE1((((Unit)->Data1))) & ((uintptr_t)224)) | ((((uintptr_t)(Value)) - ((uintptr_t)93)) & ((uintptr_t)31)))))

#define PriorityQueueMMADUnit_IsItemFilled(Unit)                ((PriorityQueueMMADUnit_GetItemCount((Unit))) >= ((PriorityQueueMMADUnit_GetMaxPtrCount((Unit))) >> 1))

#define PriorityQueueMMADUnit_GetProp(Unit)                     (((uint8_t)UPTRVAL_GETBYTE1(((Unit)->Data1))) >> ((uint8_t)5))
#define PriorityQueueMMADUnit_SetProp(Unit,Value)               (UPTRVAL_SETBYTE1(((Unit)->Data1),(((Value) << ((uintptr_t)5)) | (UPTRVAL_GETBYTE1(((Unit)->Data1)) & ((uintptr_t)31)))))

#define PriorityQueueMMADUnit_NeedsToMigrate(Unit)              (PriorityQueueMMADUnit_GetProp((Unit)) == 1)
#define PriorityQueueMMADUnit_CouldLodge(Unit)                  ({int _res = (int)PriorityQueueMMADUnit_GetProp((Unit));_res = (_res & 6);_res;})
#define PriorityQueueMMADUnit_CanLodge(Unit)                    ({int _res = (int)PriorityQueueMMADUnit_GetProp((Unit));_res = ((_res & 6)&&((~_res) & 3));_res;})
#define PriorityQueueMMADUnit_DoesLodge(Unit)                   ({int _res = (int)PriorityQueueMMADUnit_GetProp((Unit));_res = ((_res == 3)||(_res > 4));_res;})
#define PriorityQueueMMADUnit_DoesMaxLodge(Unit)                ({int _res = (int)PriorityQueueMMADUnit_GetProp((Unit));_res = ((_res & 3) == 3);_res;})


#define PriorityQueueMMADUnit_IsCommoner(Unit)                  ((!(PriorityQueueMMADUnit_IsItemFilled((Unit))))||(!(PriorityQueueMMADUnit_CouldLodge((Unit)))))
#define PriorityQueueMMADUnit_IsFilledLodger(Unit)              ((PriorityQueueMMADUnit_IsItemFilled((Unit)))&&(PriorityQueueMMADUnit_DoesMaxLodge((Unit))))
#define PriorityQueueMMADUnit_IsItemFilledLodger(Unit)          ((PriorityQueueMMADUnit_IsItemFilled((Unit)))&&(PriorityQueueMMADUnit_CanLodge((Unit))))
#define PriorityQueueMMADUnit_IsWaitingImmigrant(Unit)          ((PriorityQueueMMADUnit_IsItemFilled((Unit)))&&(PriorityQueueMMADUnit_NeedsToMigrate((Unit))))

#define PriorityQueueMMADUnit_IsFirst(Unit)                     ((((Unit)->Prev == NULL)&&(PriorityQueueMMADUnit_IsCommoner((Unit))))||((PriorityQueueMMADUnit_IsItemFilledLodger((Unit)))&&((Unit)->Prev == (Unit)))||((PriorityQueueMMADUnit_IsFilledLodger((Unit)))&&((((Unit)->Prev == (Unit))&&(((Unit)->Next == (Unit))||(!(PriorityQueueMMADUnit_IsFilledLodger((((Unit)->Next)))))))||(((Unit)->Prev != (Unit))&&(PriorityQueueMMADUnit_IsFilledLodger((((Unit)->Prev))))&&(!(PriorityQueueMMADUnit_IsFilledLodger((((Unit)->Prev->Next)))))))))

#define PriorityQueueMMADUnit_GetItemStart(Unit)                ((Unit)->BackPtr)

#define PriorityQueueMMAItem_GetPtr1(AItem)                     (*((void**)(AItem)))
#define PriorityQueueMMAItem_GetPtr1Ref(AItem)                  ((void**)(AItem))
#define PriorityQueueMMAItem_GetPtr2(AItem)                     (*(((void**)(AItem)) + (1 + PRIORITYQUEUEMMAD_REF31(AItem))))
#define PriorityQueueMMAItem_GetPtr2Ref(AItem)                  (((void**)(AItem)) + (1 + PRIORITYQUEUEMMAD_REF31(AItem)))
#define PriorityQueueMMAItem_SetPtr1(AItem,Value)               (PriorityQueueMMAItem_GetPtr1((AItem)) = ((void*)(Value)))
#define PriorityQueueMMAItem_SetPtr2(AItem,Value)               (PriorityQueueMMAItem_GetPtr2((AItem)) = ((void*)(Value)))

#define _PriorityQueueMMADUnit_IsSegmentStart(Unit,LUnit)       (((Unit)->Prev == (LUnit))||((Unit)->Prev != (Unit)->Prev->Next->Prev))
#define _PriorityQueueMMADUnit_IsSegmentEnd(Unit,LUnit)         (((Unit) == (LUnit))||(_PriorityQueueMMADUnit_IsSegmentStart((Unit)->Next,(LUnit))))

#define PriorityQueueMMADUnit_IsSegmentStart(Unit)              (_PriorityQueueMMADUnit_IsSegmentStart((Unit),*LstUnitRef))
#define PriorityQueueMMADUnit_IsSegmentEnd(Unit)                (_PriorityQueueMMADUnit_IsSegmentEnd((Unit),*LstUnitRef))


#ifdef PRIORITYQUEUEMM_DISP_INFO
static void PriorityQueueMMADUnit_PrintSegmentList(PriorityQueueMMADUnit** CurUnitRef,PriorityQueueMMADUnit** LstUnitRef,int UnitCount){
    printf("       ------------------------------------------------\n");
    printf("                    Printing Segment-List:   (Count:%i)\n",UnitCount);
    printf("       ------------------------------------------------\n");
    PriorityQueueMMADUnit* FstUnit = (*LstUnitRef)->Next;
    PriorityQueueMMADUnit* CurUnit = FstUnit;
    PriorityQueueMMADUnit* EndUnit;
    int CurRefFound = 0;
    int ToCount = UnitCount;
    while(1){
        EndUnit = CurUnit->Prev;
        while(CurUnit != EndUnit){
            printf("       ");
            if(CurUnit == *CurUnitRef){printf("=>");CurRefFound = 1;}else{printf("  ");}
            printf("AUnit:%p [Items:%p Prop:%i I:%i\\%i]\n",CurUnit,CurUnit->BackPtr,PriorityQueueMMADUnit_GetProp(CurUnit),(PriorityQueueMMADUnit_GetMaxPtrCount(CurUnit) >> 1),PriorityQueueMMADUnit_GetItemCount(CurUnit));
            CurUnit = CurUnit->Next;
            ToCount--;
            if(ToCount < -1){break;}
        }
        printf("       ");
        if(CurUnit == *CurUnitRef){printf("=>");CurRefFound = 1;}else{printf("  ");}
        printf("AUnit:%p [Items:%p Prop:%i I:%i\\%i]\n",CurUnit,CurUnit->BackPtr,PriorityQueueMMADUnit_GetProp(CurUnit),(PriorityQueueMMADUnit_GetMaxPtrCount(CurUnit) >> 1),PriorityQueueMMADUnit_GetItemCount(CurUnit));
        ToCount--;
        if(CurUnit == *LstUnitRef){break;}
        printf("           ---\n");
        CurUnit = CurUnit->Next;
        if(ToCount < -1){break;}
    }
    if(!CurRefFound){printf("\n       CurUnit:%p LstUnit:%p\n",*CurUnitRef,*LstUnitRef);}else{printf("\n       LstUnit:%p\n",*LstUnitRef);}
    printf("       ------------------------------------------------\n");
    if((ToCount >= 1)||(ToCount < -1)){
        printf("[INFO] Causing Artificial Crash (for Debug)\n");
        void** CrashVar1 = NULL;
        void* CrashVar2 = *CrashVar1;
        printf("[INFO] CrashVar2:%p\n",CrashVar2);
    }
}
#endif // PRIORITYQUEUEMM_DISP_INFO


static int PriorityQueueMMADUnit_RemoveSegmentItem(PriorityQueueMMADUnit* U,PriorityQueueMMADUnit** CurUnitRef,PriorityQueueMMADUnit** LstUnitRef){
    #ifdef PRIORITYQUEUEMM_DISP_INFO
    printf("[INFO] Remove Segment Item (prior):\n");
    printf("       Removing:%p [Items:%p Prv:%p Nxt:%p]\n",U,U->BackPtr,U->Prev,U->Next);
    if(*LstUnitRef != NULL){
        printf("       LstRef  :%p [Items:%p Prv:%p Nxt:%p]\n",*LstUnitRef,(*LstUnitRef)->BackPtr,(*LstUnitRef)->Prev,(*LstUnitRef)->Next);
    }else{
        printf("       LstRef  :%p\n",*LstUnitRef);
    }
    if(*CurUnitRef != NULL){
        printf("       CurRef  :%p [Items:%p Prv:%p Nxt:%p]\n",*CurUnitRef,(*CurUnitRef)->BackPtr,(*CurUnitRef)->Prev,(*CurUnitRef)->Next);
    }else{
        printf("       CurRef  :%p\n",*CurUnitRef);
    }

    #endif // PRIORITYQUEUEMM_DISP_INFO
    if((U->Prev == NULL)&&(U->Next == NULL)){return 1;}

    //Rules for Segment-Lists:
    //------------------------
    //For a unit "u" the following rules have to apply:
    //(A) if "u" IS the first unit of a segment => "u->Prev->Next != u"
    //(B) if "u" IS the last unit of a segment => "u->Next->Prev != u"
    //(C) if "u" IS NOT the first unit of a segment => "u->Prev->Next == u"
    //(D) if "u" IS NOT the last unit of a segment => "u->Next->Prev == u"
    //(E) if "u" IS the first unit of a segment => "u->Prev" IS the last unit of the same segment
    //(F) if "u" IS the last unit of a segment => "u->Next" IS the first unit of the next segment (can be the same segment if there is only 1 (one) segment in the segment-list)


    //Definitions:
    //SEG(U1,U2) : Is TRUE ("1") if Units "U1" and "U2" are part of the same segment, otherwise FALSE ("0")
    //PREV       : Unit that fulfills the following condition: "PREV->Next == U"
    //STRT       : First Unit of the segment "U" is part of

    //PriorityQueueMMADUnit* FstUnit = (*LstUnitRef)->Next;
    if(U == *CurUnitRef){*CurUnitRef = ((*CurUnitRef != *LstUnitRef)?((*CurUnitRef)->Next):(NULL));}
    if(!PriorityQueueMMADUnit_IsSegmentStart(U)){
        //"U" IS NOT the start of a segment                 //(1)
        // (1) => "U->Prev->Next == U"
        // (1) => The segment of "U" consists of AT LEAST 2 units(!)
        //        (Otherwise "U" would be the start of the segment)
        // (1) => "STRT != U"

        if(PriorityQueueMMADUnit_IsSegmentEnd(U)){
            //"U" IS last Item of a Segment                 //(2)
            // (2) <=> "STRT->Prev == U"
            // (1) => "U->Prev->Next == U"
            // (2) => "U->Next->Prev != U"
            // (2) => "SEG(U->Next,U) == FALSE"

            //Target:
            //"U->Prev->Next == U->Next"
            //"STRT->Prev == U->Prev"

            if(U == *LstUnitRef){*LstUnitRef = U->Prev;}
            PriorityQueueMMADUnit* SttUnit = U->Next;
            //(C0): "STRT->Prev == U"
            //(C1): "SttUnit == U->Next"
            //(C2): (C0) and (C1) => "SttUnit == STRT->Prev->Next"
            //(C3): (C0) and (C1) => "PriorityQueueMMADUnit_IsSegmentStart(SttUnit) == TRUE"
            while(SttUnit->Prev != U){
                //Loop-Condition "LC1"
                //(LC1): "SttUnit->Prev != U"

                //Loop-Invariant "LI1":
                //(LI1): "PriorityQueueMMADUnit_IsSegmentStart(SttUnit) == TRUE"
                //Initially: (C3), Afterwards: (L3)

                //(L1): (LI1) and (E) => "PriorityQueueMMADUnit_IsSegmentEnd(SttUnit->Prev) == TRUE"
                //(L2): (L1) and (F) => "PriorityQueueMMADUnit_IsSegmentStart(SttUnit->Prev->Next) == TRUE"
                SttUnit = SttUnit->Prev->Next;
                //(L3) (L2) and "SttUnit := SttUnit->Prev->Next" => "PriorityQueueMMADUnit_IsSegmentStart(SttUnit) == TRUE"
            }
            //Loop-End-Condition "LE1"
            //(LE1): "SttUnit->Prev == U"

            //Loop-Invariant "LI1":
            //(LI1): "PriorityQueueMMADUnit_IsSegmentStart(SttUnit) == TRUE"

            //(C4): (LI1) and (E) => "PriorityQueueMMADUnit_IsSegmentEnd(SttUnit->Prev) == TRUE"
            //(C5): (LI1) and (C4) and (LE1) ~> "SttUnit == STRT"

            SttUnit->Prev = U->Prev;
        }else{
            //"U" IS NOT last Item of a Segment             //(3)
            // (1) => "U->Prev->Next == U"
            // (3) => "U->Next->Prev == U"

            //Target:
            //"U->Prev->Next == U->Next"
            //"U->Next->Prev == U->Prev"

            U->Next->Prev = U->Prev;
        }
        U->Prev->Next = U->Next;
    }else{
        //"U" IS the start of a segment                     //(4)
        // (4) => "U->Prev->Next != U"
        // (4) => "STRT == U"

        //Target:
        //"PREV->Next == U->Next"
        //"PriorityQueueMMADUnit_IsSegmentEnd(U) == FALSE" => "U->Next->Prev == U->Prev"

        //(C0): "STRT == U"
        //(C1): (C0) => "PriorityQueueMMADUnit_IsSegmentStart(U) == TRUE"
        //(C2): (C1) and (E) => "PriorityQueueMMADUnit_IsSegmentEnd(U->Prev) == TRUE"
        PriorityQueueMMADUnit* PrvUnit = U->Prev;
        //(C3): (C2) and "PrvUnit := U->Prev" => "PriorityQueueMMADUnit_IsSegmentEnd(PrvUnit) == TRUE"

        while(PrvUnit->Next != U){
            //Loop-Condition "LC1"
            //(LC1): "PrvUnit->Next != U"

            //Loop-Invariant "LI1":
            //(LI1): "PriorityQueueMMADUnit_IsSegmentEnd(PrvUnit) == TRUE"
            //Initially: (C3), Afterwards: (L3)

            //(L1): (LI1) and (F) => "PriorityQueueMMADUnit_IsSegmentStart(PrvUnit->Next) == TRUE"
            //(L2): (L1) and (E) => "PriorityQueueMMADUnit_IsSegmentEnd(PrvUnit->Next->Prev) == TRUE"
            PrvUnit = PrvUnit->Next->Prev;
            //(L3): (L2) and "PrvUnit := PrvUnit->Next->Prev" => "PriorityQueueMMADUnit_IsSegmentEnd(PrvUnit) == TRUE"
        }
        //Loop-End-Condition "LE1"
        //(LE1): "PrvUnit->Next == U"

        //Loop-Invariant "LI1":
        //(LI1): "PriorityQueueMMADUnit_IsSegmentEnd(PrvUnit) == TRUE"

        //(C4): (LI1) and (F) => "PriorityQueueMMADUnit_IsSegmentStart(PrvUnit->Next) == TRUE"
        //(C5): (LI1) and (C4) and (LE1) and (C1) => "PREV == PrvUnit"

        if(!PriorityQueueMMADUnit_IsSegmentEnd(U)){U->Next->Prev = U->Prev;}
        PrvUnit->Next = U->Next;
        if(U == *LstUnitRef){*LstUnitRef = PrvUnit;}
    }
    U->Prev = NULL;
    U->Next = NULL;
    #ifdef PRIORITYQUEUEMM_DISP_INFO
    printf("[INFO] Remove Segment Item (afterwards):\n");
    printf("       Removing:%p [Items:%p Prv:%p Nxt:%p]\n",U,U->BackPtr,U->Prev,U->Next);
    if(*LstUnitRef != NULL){
        printf("       LstRef  :%p [Items:%p Prv:%p Nxt:%p]\n",*LstUnitRef,(*LstUnitRef)->BackPtr,(*LstUnitRef)->Prev,(*LstUnitRef)->Next);
    }else{
        printf("       LstRef  :%p\n",*LstUnitRef);
    }
    if(*CurUnitRef != NULL){
        printf("       CurRef  :%p [Items:%p Prv:%p Nxt:%p]\n",*CurUnitRef,(*CurUnitRef)->BackPtr,(*CurUnitRef)->Prev,(*CurUnitRef)->Next);
    }else{
        printf("       CurRef  :%p\n",*CurUnitRef);
    }
    #endif // PRIORITYQUEUEMM_DISP_INFO
    return 1;
}

static int PriorityQueueMMADUnit_InsertNewSegment(PriorityQueueMMADUnit* U,PriorityQueueMMADUnit** PrevSegLstUnitRef,PriorityQueueMMADUnit** LstUnitRef){
    #ifdef PRIORITYQUEUEMM_DISP_INFO
    #ifndef PRIORITYQUEUEMM_REM_SEG_INFO
    printf("       (InsertNewSegment)\n");
    #endif // PRIORITYQUEUEMM_REM_SEG_INFO
    #endif // PRIORITYQUEUEMM_DISP_INFO
    U->Next = (*PrevSegLstUnitRef)->Next;
    U->Prev = U;
    (*PrevSegLstUnitRef)->Next = U;
    return 1;
}
static int PriorityQueueMMADUnit_InsertNewSegmentBack(PriorityQueueMMADUnit* U,PriorityQueueMMADUnit** PrevSegLstUnitRef,PriorityQueueMMADUnit** LstUnitRef){
    #ifdef PRIORITYQUEUEMM_DISP_INFO
    #ifndef PRIORITYQUEUEMM_REM_SEG_INFO
    printf("       (InsertNewSegmentBack)\n");
    #endif // PRIORITYQUEUEMM_REM_SEG_INFO
    #endif // PRIORITYQUEUEMM_DISP_INFO
    U->Next = (*PrevSegLstUnitRef)->Next;
    U->Prev = U;
    (*PrevSegLstUnitRef)->Next = U;
    if(*PrevSegLstUnitRef == *LstUnitRef){*LstUnitRef = U;}
    return 1;
}
static int PriorityQueueMMADUnit_InsertSegmentFront(PriorityQueueMMADUnit* U,PriorityQueueMMADUnit** PrevSegLstUnitRef,PriorityQueueMMADUnit** LstUnitRef){
    #ifdef PRIORITYQUEUEMM_DISP_INFO
    #ifndef PRIORITYQUEUEMM_REM_SEG_INFO
    printf("       (InsertSegmentFront)\n");
    #endif // PRIORITYQUEUEMM_REM_SEG_INFO
    #endif // PRIORITYQUEUEMM_DISP_INFO
    U->Next = (*PrevSegLstUnitRef)->Next;
    U->Prev = U->Next->Prev;
    U->Next->Prev = U;
    (*PrevSegLstUnitRef)->Next = U;
    return 1;
}
static int PriorityQueueMMADUnit_InsertSegmentBack(PriorityQueueMMADUnit* U,PriorityQueueMMADUnit** PrevSegLstUnitRef,PriorityQueueMMADUnit** LstUnitRef){
    #ifdef PRIORITYQUEUEMM_DISP_INFO
    #ifndef PRIORITYQUEUEMM_REM_SEG_INFO
    printf("       (InsertSegmentBack)\n");
    #endif // PRIORITYQUEUEMM_REM_SEG_INFO
    #endif // PRIORITYQUEUEMM_DISP_INFO
    U->Prev = (*PrevSegLstUnitRef)->Next->Prev;
    U->Next = U->Prev->Next;
    if(U->Prev == *LstUnitRef){*LstUnitRef = U;}
    U->Prev->Next = U;
    (*PrevSegLstUnitRef)->Next->Prev = U;
    return 1;
}


static int PriorityQueueMMADUnit_InsertFilledLodger(PriorityQueueMMADUnit* U,PriorityQueueMMADUnit** CurUnitRef,PriorityQueueMMADUnit** LstUnitRef){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    if(!PriorityQueueMMADUnit_IsFilledLodger(U)){
        PRINT_ERROR("\"U\" is not a FilledLodger!\0");
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL2

    #ifdef PRIORITYQUEUEMM_DISP_INFO
    printf("[INFO] Insert Filled-Lodger AUnit with:\n");
    printf("       AUnit:%p (Start:%p Items:%p Prop:%i)\n",U,PriorityQueueMMADUnit_GetAlloc_Start(U),U->BackPtr,PriorityQueueMMADUnit_GetProp(U));
    #endif // PRIORITYQUEUEMM_DISP_INFO

    PriorityQueueMMADUnit_RemoveSegmentItem(U,CurUnitRef,LstUnitRef);
    PriorityQueueMMADUnit* FstUnit = (*LstUnitRef)->Next;
    if(PriorityQueueMMADUnit_IsFilledLodger(FstUnit)){
       return PriorityQueueMMADUnit_InsertSegmentFront(U,LstUnitRef,LstUnitRef);
    }
    return PriorityQueueMMADUnit_InsertNewSegment(U,LstUnitRef,LstUnitRef);
}

static int PriorityQueueMMADUnit_InsertItemFilledUnit(PriorityQueueMMADUnit* U,PriorityQueueMMADUnit** CurUnitRef,PriorityQueueMMADUnit** LstUnitRef){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    if(!PriorityQueueMMADUnit_IsItemFilled(U)){
        PRINT_ERROR("\"U\" is not an ItemFilledUnit!\0");
        return 0;
    }
    if(PriorityQueueMMADUnit_IsFilledLodger(U)){
        PRINT_ERROR("\"U\" is a FilledLodger!\0");
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL2

    #ifdef PRIORITYQUEUEMM_DISP_INFO
    printf("[INFO] Insert Item-Filled AUnit with:\n");
    printf("       AUnit:%p (Start:%p Items:%p Prop:%i)\n",U,PriorityQueueMMADUnit_GetAlloc_Start(U),U->BackPtr,PriorityQueueMMADUnit_GetProp(U));
    #endif // PRIORITYQUEUEMM_DISP_INFO

    if((*LstUnitRef)->Next != *LstUnitRef){
        PriorityQueueMMADUnit_RemoveSegmentItem(U,CurUnitRef,LstUnitRef);
    }else if(*LstUnitRef == U){return 1;}

    PriorityQueueMMADUnit* FstUnit = (*LstUnitRef)->Next;
    int FstFilledLodger = PriorityQueueMMADUnit_IsFilledLodger(FstUnit);
    PriorityQueueMMADUnit** SelUnit = ((FstFilledLodger)?(&(FstUnit->Prev)):(LstUnitRef));

    if((PriorityQueueMMADUnit_IsItemFilledLodger(U))||(PriorityQueueMMADUnit_IsWaitingImmigrant(U))){
        if(PriorityQueueMMADUnit_IsItemFilled((*SelUnit)->Next)){return PriorityQueueMMADUnit_InsertSegmentFront(U,SelUnit,LstUnitRef);}
        if((*SelUnit == *LstUnitRef)&&(FstFilledLodger)){return PriorityQueueMMADUnit_InsertNewSegmentBack(U,SelUnit,LstUnitRef);}
        return PriorityQueueMMADUnit_InsertNewSegment(U,SelUnit,LstUnitRef);
    }else{
        if(PriorityQueueMMADUnit_IsItemFilled((*SelUnit)->Next)){return PriorityQueueMMADUnit_InsertSegmentBack(U,SelUnit,LstUnitRef);}
        if((*SelUnit == *LstUnitRef)&&(FstFilledLodger)){return PriorityQueueMMADUnit_InsertNewSegmentBack(U,SelUnit,LstUnitRef);}
        return PriorityQueueMMADUnit_InsertNewSegment(U,SelUnit,LstUnitRef);
    }
    return 1;
}

static int PriorityQueueMMADUnit_InsertLodgerUnit(PriorityQueueMMADUnit* U,PriorityQueueMMADUnit** CurUnitRef,PriorityQueueMMADUnit** LstUnitRef){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    if((PriorityQueueMMADUnit_IsItemFilled(U))||(!PriorityQueueMMADUnit_DoesLodge(U))){
        PRINT_ERROR("\"U\" is not a LodgerUnit!\0");
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL2

    #ifdef PRIORITYQUEUEMM_DISP_INFO
    printf("[INFO] Insert Lodger AUnit with:\n");
    printf("       AUnit:%p (Start:%p Items:%p Prop:%i)\n",U,PriorityQueueMMADUnit_GetAlloc_Start(U),U->BackPtr,PriorityQueueMMADUnit_GetProp(U));
    #endif // PRIORITYQUEUEMM_DISP_INFO

    if((*LstUnitRef)->Next != *LstUnitRef){
        PriorityQueueMMADUnit_RemoveSegmentItem(U,CurUnitRef,LstUnitRef);
        PriorityQueueMMADUnit* FstUnit = (*LstUnitRef)->Next;
        *CurUnitRef = U;
        if(PriorityQueueMMADUnit_IsItemFilled(*LstUnitRef)){return PriorityQueueMMADUnit_InsertNewSegmentBack(U,LstUnitRef,LstUnitRef);}
        PriorityQueueMMADUnit** SelUnit = ((PriorityQueueMMADUnit_IsFilledLodger(FstUnit))?(&(FstUnit->Prev)):(LstUnitRef));
        SelUnit = ((PriorityQueueMMADUnit_IsItemFilled((*SelUnit)->Next))?(&((*SelUnit)->Next->Prev)):(SelUnit));

        if(PriorityQueueMMADUnit_DoesLodge((*SelUnit)->Next)){return PriorityQueueMMADUnit_InsertSegmentFront(U,SelUnit,LstUnitRef);}
        return PriorityQueueMMADUnit_InsertNewSegment(U,SelUnit,LstUnitRef);
    }
    return 1;
}

static int PriorityQueueMMADUnit_InsertCommonerUnit(PriorityQueueMMADUnit* U,PriorityQueueMMADUnit** CurUnitRef,PriorityQueueMMADUnit** LstUnitRef){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    if((PriorityQueueMMADUnit_IsItemFilled(U))||(PriorityQueueMMADUnit_DoesLodge(U))){
        PRINT_ERROR("\"U\" is not a CommonerUnit!\0");
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL2

    #ifdef PRIORITYQUEUEMM_DISP_INFO
    printf("[INFO] Insert Commoner AUnit with:\n");
    printf("       AUnit:%p (Start:%p Items:%p Prop:%i)\n",U,PriorityQueueMMADUnit_GetAlloc_Start(U),U->BackPtr,PriorityQueueMMADUnit_GetProp(U));
    #endif // PRIORITYQUEUEMM_DISP_INFO

    if((*LstUnitRef)->Next != *LstUnitRef){
        PriorityQueueMMADUnit_RemoveSegmentItem(U,CurUnitRef,LstUnitRef);
    }else if(*LstUnitRef == U){return 1;}

    PriorityQueueMMADUnit* FstUnit = (*LstUnitRef)->Next;

    if(PriorityQueueMMADUnit_IsItemFilled(*LstUnitRef)){
        *CurUnitRef = U;
        return PriorityQueueMMADUnit_InsertNewSegmentBack(U,LstUnitRef,LstUnitRef);
    }

    PriorityQueueMMADUnit** SelUnit = ((PriorityQueueMMADUnit_IsFilledLodger(FstUnit))?(&(FstUnit->Prev)):(LstUnitRef));
    SelUnit = ((PriorityQueueMMADUnit_IsItemFilled((*SelUnit)->Next))?(&((*SelUnit)->Next->Prev)):(SelUnit));
    SelUnit = ((PriorityQueueMMADUnit_DoesLodge((*SelUnit)->Next))?(&((*SelUnit)->Next->Prev)):(SelUnit));
    if(*SelUnit == *LstUnitRef){return PriorityQueueMMADUnit_InsertNewSegmentBack(U,LstUnitRef,LstUnitRef);}

    if(PriorityQueueMMADUnit_GetItemCount(U)){
        *CurUnitRef = (((*CurUnitRef == NULL)||(!PriorityQueueMMADUnit_DoesLodge(*CurUnitRef)))?(U):(*CurUnitRef));
        return PriorityQueueMMADUnit_InsertSegmentFront(U,SelUnit,LstUnitRef);
    }
    *CurUnitRef = ((*CurUnitRef == NULL)?(U):(*CurUnitRef));
    return PriorityQueueMMADUnit_InsertSegmentBack(U,SelUnit,LstUnitRef);

    if(PriorityQueueMMADUnit_DoesLodge((*SelUnit)->Next)){return PriorityQueueMMADUnit_InsertSegmentFront(U,SelUnit,LstUnitRef);}
    return PriorityQueueMMADUnit_InsertNewSegment(U,LstUnitRef,LstUnitRef);
}

static int PriorityQueueMMADUnit_Migrate(PriorityQueueMMADUnit** U,PriorityQueueMMADUnit** RootRef,PriorityQueueMMADUnit** CurUnitRef,PriorityQueueMMADUnit** LstUnitRef){
    PriorityQueueMMADUnit* SrcUnit = *U;
    PriorityQueueMMADUnit* TarUnit = NULL;
    PriorityQueueMMADUnit* LdgUnit = NULL;
    PriorityQueueMMADUnit* FstUnit = (*LstUnitRef)->Next;
    PriorityQueueMMADUnit* BufUnit = NULL;

    #ifdef PRIORITYQUEUEMM_DISP_INFO
    printf("[INFO] Migrate AUnit (Start:%p UnitPtr:%p Items:%p):\n",PriorityQueueMMADUnit_GetAlloc_Start(SrcUnit),SrcUnit,SrcUnit->BackPtr);
    #endif // PRIORITYQUEUEMM_DISP_INFO


    if(PriorityQueueMMADUnit_IsCommoner(FstUnit)){PRINT_INFO2("Migration failed! (FstUnit Commoner)\0");return 0;}
    if(PriorityQueueMMADUnit_IsFilledLodger(FstUnit)){
        LdgUnit = FstUnit->Prev->Next;
        if(!PriorityQueueMMADUnit_IsItemFilledLodger(LdgUnit)){PRINT_INFO2("Migration failed! (No Lodger)\0");return 0;}
    }else if(PriorityQueueMMADUnit_IsItemFilledLodger(FstUnit)){
        LdgUnit = FstUnit;
    }else{
        PRINT_INFO2("Migration failed! (No Lodger)\0");return 0;
        return 0;
    }

    int Slot = ~(PriorityQueueMMADUnit_GetProp(LdgUnit));
    if(Slot & 1){
        PriorityQueueMMADUnit_SetProp(LdgUnit,((~Slot)|1));
        TarUnit = (PriorityQueueMMADUnit*)(((void**)LdgUnit) + 10);
        #ifdef PRIORITYQUEUEMM_DISP_INFO
        Slot = 1;
        #endif // PRIORITYQUEUEMM_DISP_INFO
    }else if(Slot & 2){
        PriorityQueueMMADUnit_SetProp(LdgUnit,((~Slot)|2));
        TarUnit = (PriorityQueueMMADUnit*)(((void**)LdgUnit) + 20);
        #ifdef PRIORITYQUEUEMM_DISP_INFO
        Slot = 2;
        #endif // PRIORITYQUEUEMM_DISP_INFO
    }else{
        PRINT_INFO2("Migration failed! (Corrupted Slot)\0");
        return 0;
    }

    #ifdef PRIORITYQUEUEMM_DISP_INFO
    printf("       Lodger:%p (Start:%p Items:%p) [Slot:%i]\n",LdgUnit,PriorityQueueMMADUnit_GetAlloc_Start(LdgUnit),LdgUnit->BackPtr,Slot);
    printf("       Target:%p\n",TarUnit);
    #endif // PRIORITYQUEUEMM_DISP_INFO

    //#ifdef PRIORITYQUEUEMM_DISP_INFO
    //printf("[INFO] Created AUnit (Start:%p UnitPtr:%p Items:%p):\n",PriorityQueueMMADUnit_GetAlloc_Start(UnitPtr),UnitPtr,UnitPtr->BackPtr);
    //if(PriorityQueueMMADUnit_GetProp(UnitPtr) > 1){
    //    printf("       Type: Lodger[Prop:%i] (Can lodge %i)\n",PriorityQueueMMADUnit_GetProp(UnitPtr),(PriorityQueueMMADUnit_GetProp(UnitPtr) >> 1));
    //    printf("       Max Capacity: %i AItems\n",(PriorityQueueMMADUnit_GetMaxPtrCount(UnitPtr) >> 1));
    //}else if(PriorityQueueMMADUnit_GetProp(UnitPtr) == 1){
    //    printf("       Type: Immigrant[Prop:%i] (Needs to migrate)\n",PriorityQueueMMADUnit_GetProp(UnitPtr));
    //    printf("       Cur Capacity: %i AItems\n",(PriorityQueueMMADUnit_GetMaxPtrCount(UnitPtr) >> 1));
    //}else{
    //    printf("       Type: Commoner[Prop:%i]\n",PriorityQueueMMADUnit_GetProp(UnitPtr));
    //    printf("       Max Capacity: %i AItems\n",(PriorityQueueMMADUnit_GetMaxPtrCount(UnitPtr) >> 1));
    //}
    //#endif // PRIORITYQUEUEMM_DISP_INFO

    void* Alloc_Start = PriorityQueueMMADUnit_GetAlloc_Start(SrcUnit);
    int MaxPtrCount = PriorityQueueMMADUnit_GetMaxPtrCount(SrcUnit);
    int ItemCount = PriorityQueueMMADUnit_GetItemCount(SrcUnit);
    TarUnit->BackPtr = SrcUnit->BackPtr;

    //Update AVL-Parent:
    BufUnit = PriorityQueueMMADUnit_GetParent(SrcUnit);
    if(BufUnit != NULL){
        if(PriorityQueueMMADUnit_GetChild1(BufUnit) == SrcUnit){
            PriorityQueueMMADUnit_SetChild1(BufUnit,TarUnit);
        }else{
            PriorityQueueMMADUnit_SetChild2(BufUnit,TarUnit);
        }
    }
    PriorityQueueMMADUnit_SetParent(TarUnit,BufUnit);

    //Update AVL-Child1:
    BufUnit = PriorityQueueMMADUnit_GetChild1(SrcUnit);
    if(BufUnit != NULL){PriorityQueueMMADUnit_SetParent(BufUnit,TarUnit);}
    PriorityQueueMMADUnit_SetChild1(TarUnit,BufUnit);

    //Update AVL-Child2:
    BufUnit = PriorityQueueMMADUnit_GetChild2(SrcUnit);
    if(BufUnit != NULL){PriorityQueueMMADUnit_SetParent(BufUnit,TarUnit);}
    PriorityQueueMMADUnit_SetChild2(TarUnit,BufUnit);

    PriorityQueueMMADUnit_RemoveSegmentItem(SrcUnit,CurUnitRef,LstUnitRef);
    TarUnit->Prev = NULL;
    TarUnit->Next = NULL;

    //Update external references:
    if(*RootRef == SrcUnit){*RootRef = TarUnit;}

    ((void**)TarUnit->BackPtr)[0] = (void*)TarUnit;
    ((void**)TarUnit->BackPtr)[32] = (void*)TarUnit;
    ((void**)TarUnit->BackPtr)[64] = (void*)TarUnit;
    ((void**)TarUnit->BackPtr)[96] = (void*)TarUnit;

    MaxPtrCount = MaxPtrCount + 10;
    PriorityQueueMMADUnit_SetAlloc_Start(TarUnit,Alloc_Start);
    PriorityQueueMMADUnit_SetMaxPtrCount(TarUnit,MaxPtrCount);
    PriorityQueueMMADUnit_SetProp(TarUnit,0);
    PriorityQueueMMADUnit_SetMaxlength(TarUnit,PriorityQueueMMADUnit_GetMaxlength(SrcUnit));
    PriorityQueueMMADUnit_SetOwner(TarUnit,PriorityQueueMMADUnit_GetOwner(SrcUnit));
    PriorityQueueMMADUnit_SetItemCount(TarUnit,ItemCount);

    int i = 0;
    void** ItemArray = (void**)TarUnit->BackPtr;
    PriorityQueueMMAItem* NxtItem = NULL;
    PriorityQueueMMAItem* CurItem = NULL;
    for(i = (MaxPtrCount & 254) - 2;i >= ItemCount << 1;i = i - 2){
            CurItem = (PriorityQueueMMAItem*)(&(ItemArray[PriorityQueueMMADUnit_CorrectIndex(i)]));
            PriorityQueueMMAItem_SetPtr1(CurItem,NULL);
            PriorityQueueMMAItem_SetPtr2(CurItem,NxtItem);
            NxtItem = CurItem;
    }

    PriorityQueueMMADUnit_SetNextEmptyItem(TarUnit,((void*)CurItem));
    *U = TarUnit;

    PriorityQueueMMADUnit_InsertCommonerUnit(TarUnit,CurUnitRef,LstUnitRef);
    if(PriorityQueueMMADUnit_IsFilledLodger(LdgUnit)){PriorityQueueMMADUnit_InsertFilledLodger(LdgUnit,CurUnitRef,LstUnitRef);}


    #ifdef PRIORITYQUEUEMM_DISP_INFO
    printf("[INFO] Migrating AUnit %p done with:\n",SrcUnit);
    printf("       LdgUnit:%p [Items:%p Prop:%i I:%i\\%i]\n",LdgUnit,LdgUnit->BackPtr,PriorityQueueMMADUnit_GetProp(LdgUnit),(PriorityQueueMMADUnit_GetMaxPtrCount(LdgUnit) >> 1),PriorityQueueMMADUnit_GetItemCount(LdgUnit));
    printf("       TarUnit:%p [Items:%p Prop:%i I:%i\\%i]\n",TarUnit,TarUnit->BackPtr,PriorityQueueMMADUnit_GetProp(TarUnit),(PriorityQueueMMADUnit_GetMaxPtrCount(TarUnit) >> 1),PriorityQueueMMADUnit_GetItemCount(TarUnit));
    printf("       LstUnit:%p [Items:%p Prop:%i I:%i\\%i]\n",*LstUnitRef,(*LstUnitRef)->BackPtr,PriorityQueueMMADUnit_GetProp((*LstUnitRef)),(PriorityQueueMMADUnit_GetMaxPtrCount((*LstUnitRef)) >> 1),PriorityQueueMMADUnit_GetItemCount((*LstUnitRef)));
    if(*CurUnitRef != NULL){
        printf("       CurUnit:%p [Items:%p Prop:%i I:%i\\%i]\n",*CurUnitRef,(*CurUnitRef)->BackPtr,PriorityQueueMMADUnit_GetProp((*CurUnitRef)),(PriorityQueueMMADUnit_GetMaxPtrCount((*CurUnitRef)) >> 1),PriorityQueueMMADUnit_GetItemCount((*CurUnitRef)));
    }else{
        printf("       CurUnit:%p\n",*CurUnitRef);
    }
    #endif // PRIORITYQUEUEMM_DISP_INFO


    return 1;
}


#endif // USE_PRIORITYQUEUEMMAD_V2

#ifdef PRIORITYQUEUEMM_DISP_INFO
#define PriorityQueueMMAItem_Print1A(AItem)                     printf("[INFO] AItem:%p => AUnit:%p (Stt:%p) rf1:%p rf2:%p\n",(AItem),PriorityQueueMMADUnit_Get((AItem)),PriorityQueueMMADUnit_GetItemStart(PriorityQueueMMADUnit_Get((AItem))),PriorityQueueMMAItem_GetPtr1Ref((AItem)),PriorityQueueMMAItem_GetPtr2Ref((AItem)))
#define PriorityQueueMMAItem_Print1B(AItem)                     printf("[INFO] AItem:%p => AUnit:%p (Stt:%p) vl1:%p vl2:%p\n",(AItem),PriorityQueueMMADUnit_Get((AItem)),PriorityQueueMMADUnit_GetItemStart(PriorityQueueMMADUnit_Get((AItem))),*(PriorityQueueMMAItem_GetPtr1Ref((AItem))),*(PriorityQueueMMAItem_GetPtr2Ref((AItem))))
#define PriorityQueueMMAItem_Print2A(AItem)                     printf("       AItem:%p => AUnit:%p (Stt:%p) rf1:%p rf2:%p\n",(AItem),PriorityQueueMMADUnit_Get((AItem)),PriorityQueueMMADUnit_GetItemStart(PriorityQueueMMADUnit_Get((AItem))),PriorityQueueMMAItem_GetPtr1Ref((AItem)),PriorityQueueMMAItem_GetPtr2Ref((AItem)))
#define PriorityQueueMMAItem_Print2B(AItem)                     printf("       AItem:%p => AUnit:%p (Stt:%p) vl1:%p vl2:%p\n",(AItem),PriorityQueueMMADUnit_Get((AItem)),PriorityQueueMMADUnit_GetItemStart(PriorityQueueMMADUnit_Get((AItem))),*(PriorityQueueMMAItem_GetPtr1Ref((AItem))),*(PriorityQueueMMAItem_GetPtr2Ref((AItem))))
#define PriorityQueueMMAItem_Print3A(AItem)                     printf("%p => AUnit:%p (Stt:%p) rf1:%p rf2:%p\n",(AItem),PriorityQueueMMADUnit_Get((AItem)),PriorityQueueMMADUnit_GetItemStart(PriorityQueueMMADUnit_Get((AItem))),PriorityQueueMMAItem_GetPtr1Ref((AItem)),PriorityQueueMMAItem_GetPtr2Ref((AItem)))
#define PriorityQueueMMAItem_Print3B(AItem)                     printf("%p => AUnit:%p (Stt:%p) vl1:%p vl2:%p\n",(AItem),PriorityQueueMMADUnit_Get((AItem)),PriorityQueueMMADUnit_GetItemStart(PriorityQueueMMADUnit_Get((AItem))),*(PriorityQueueMMAItem_GetPtr1Ref((AItem))),*(PriorityQueueMMAItem_GetPtr2Ref((AItem))))
#else // PRIORITYQUEUEMM_DISP_INFO
#define PriorityQueueMMAItem_Print1A(AItem)                     do{}while(0)
#define PriorityQueueMMAItem_Print1B(AItem)                     do{}while(0)
#define PriorityQueueMMAItem_Print2A(AItem)                     do{}while(0)
#define PriorityQueueMMAItem_Print2B(AItem)                     do{}while(0)
#define PriorityQueueMMAItem_Print3A(AItem)                     do{}while(0)
#define PriorityQueueMMAItem_Print3B(AItem)                     do{}while(0)
#endif // PRIORITYQUEUEMM_DISP_INFO

static PriorityQueueMMADUnit* PriorityQueueMMADUnit_Create2(PriorityQueueMMADUnit** RootRef,ERRVAL_T* Errval);
static PriorityQueueMMAItem* PriorityQueueMMADUnit_GetNewItem(void* Owner,PriorityQueueMMADUnit** RootRef,PriorityQueueMMADUnit** CurUnitRef,PriorityQueueMMADUnit** LstUnitRef,int* UnitCount,int* ResItemCount,int TotalItemCount,ERRVAL_T* Errval);
static PriorityQueueMMADUnit* PriorityQueueMMADUnit_LookUpAVL(PriorityQueueMMAItem* Item,PriorityQueueMMADUnit** RootRef,ERRVAL_T* Errval);
static int PriorityQueueMMADUnit_RemoveItem(PriorityQueueMMAItem* Item,PriorityQueueMMADUnit** RootRef,PriorityQueueMMADUnit** CurUnitRef,PriorityQueueMMADUnit** LstUnitRef,int* UnitCount,int* ResItemCount,int TotalItemCount,ERRVAL_T* Errval);
static int PriorityQueueMMADUnit_Dispose(PriorityQueueMMADUnit* U,PriorityQueueMMADUnit** RootRef,PriorityQueueMMADUnit** CurUnitRef,PriorityQueueMMADUnit** LstUnitRef,int* UnitCount,int* ResItemCount,int TotalItemCount,ERRVAL_T* Errval);

#ifdef PRIORITYQUEUEMM_REM_ADU_INFO
#define PRIORITYQUEUEMM_DISP_INFO
#undef PRINT_INFO
#undef PRINT_INFO2
#define PRINT_INFO(msg)     _PRINT_INFO((msg))
#define PRINT_INFO2(msg)    _PRINT_INFO2((msg))
#endif // PRIORITYQUEUEMM_REM_ADU_INFO


#ifdef PRIORITYQUEUEMM_REM_AVL_INFO
#undef PRIORITYQUEUEMM_DISP_INFO
#undef PRINT_INFO
#undef PRINT_INFO2
#define PRINT_INFO(msg)     do{ }while(0)
#define PRINT_INFO2(msg)    do{ }while(0)
#endif // PRIORITYQUEUEMM_REM_AVL_INFO

static int PriorityQueueMMADUnit_RemoveFromAVL(PriorityQueueMMADUnit* U,PriorityQueueMMADUnit** RootRef,ERRVAL_T* Errval);
static int PriorityQueueMMADUnit_UpdateBalanceAVL(PriorityQueueMMADUnit* U,PriorityQueueMMADUnit** RootRef,int Updates,ERRVAL_T* Errval);

static int PriorityQueueMMADUnit_RebalanceAVL(PriorityQueueMMADUnit* U,PriorityQueueMMADUnit** RootRef,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    if(U == NULL){
        PRINT_ERROR("\"U\" is not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if((RootRef == NULL)||(*RootRef == NULL)){
        PRINT_ERROR("\"RootRef\" is not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    PriorityQueueMMADUnit* Parent = PriorityQueueMMADUnit_GetParent(U);
    PriorityQueueMMADUnit** PParent = NULL;
    if(Parent != NULL){
        PParent = PriorityQueueMMADUnit_GetChild1Ref(Parent);
        if(*PParent != U){PParent = PriorityQueueMMADUnit_GetChild2Ref(Parent);}
    }else{
        PParent = RootRef;
    }

    PriorityQueueMMADUnit* UnitU = NULL;
    PriorityQueueMMADUnit* UnitV = NULL;
    PriorityQueueMMADUnit* UnitW = NULL;

    //PriorityQueueMMADUnit* UnitA = NULL;
    PriorityQueueMMADUnit* UnitB = NULL;
    PriorityQueueMMADUnit* UnitC = NULL;
    //PriorityQueueMMADUnit* UnitD = NULL;

    if(PriorityQueueMMADUnit_GetBalance(U) == -2){
        UnitU = U;
        UnitV = PriorityQueueMMADUnit_GetChild1(U);
        UnitW = PriorityQueueMMADUnit_GetChild2(UnitV);

        if(PriorityQueueMMADUnit_GetBalance(UnitV) <= 0){   //Single Rotation
            UnitB = UnitW;
            #ifdef PRIORITYQUEUEMM_DISP_INFO
            printf("[INFO] Rebalance[SL] (U:%p V:%p B:%p)\n",UnitU,UnitV,UnitB);
            #endif // PRIORITYQUEUEMM_DISP_INFO

            PriorityQueueMMADUnit_SetChild2(UnitV,UnitU);
            PriorityQueueMMADUnit_SetParent(UnitU,UnitV);

            PriorityQueueMMADUnit_SetChild1(UnitU,UnitB);
            if(UnitB != NULL){PriorityQueueMMADUnit_SetParent(UnitB,UnitU);}

            PriorityQueueMMADUnit_SetParent(UnitV,Parent);
            *PParent = UnitV;
        }else{                                              //Double Rotation
            UnitB = PriorityQueueMMADUnit_GetChild1(UnitW);
            UnitC = PriorityQueueMMADUnit_GetChild2(UnitW);

            #ifdef PRIORITYQUEUEMM_DISP_INFO
            printf("[INFO] Rebalance[DL] (U:%p V:%p W:%p B:%p C:%p)\n",UnitU,UnitV,UnitW,UnitB,UnitC);
            #endif // PRIORITYQUEUEMM_DISP_INFO

            PriorityQueueMMADUnit_SetChild1(UnitW,UnitV);
            PriorityQueueMMADUnit_SetParent(UnitV,UnitW);
            PriorityQueueMMADUnit_SetChild2(UnitW,UnitU);
            PriorityQueueMMADUnit_SetParent(UnitU,UnitW);

            PriorityQueueMMADUnit_SetChild2(UnitV,UnitB);
            if(UnitB != NULL){PriorityQueueMMADUnit_SetParent(UnitB,UnitV);}

            PriorityQueueMMADUnit_SetChild1(UnitU,UnitC);
            if(UnitC != NULL){PriorityQueueMMADUnit_SetParent(UnitC,UnitU);}

            if(!PriorityQueueMMADUnit_UpdateBalanceAVL(UnitV,RootRef,1,Errval)){
                PRINT_ERROR3;
                return 0;
            }

            PriorityQueueMMADUnit_SetParent(UnitW,Parent);
            *PParent = UnitW;
        }
    }else{
        UnitU = U;
        UnitV = PriorityQueueMMADUnit_GetChild2(U);
        UnitW = PriorityQueueMMADUnit_GetChild1(UnitV);

        if(PriorityQueueMMADUnit_GetBalance(UnitV) >= 0){   //Single Rotation
            UnitB = UnitW;

            #ifdef PRIORITYQUEUEMM_DISP_INFO
            printf("[INFO] Rebalance[SR] (U:%p V:%p B:%p)\n",UnitU,UnitV,UnitB);
            #endif // PRIORITYQUEUEMM_DISP_INFO

            PriorityQueueMMADUnit_SetChild1(UnitV,UnitU);
            PriorityQueueMMADUnit_SetParent(UnitU,UnitV);

            PriorityQueueMMADUnit_SetChild2(UnitU,UnitB);
            if(UnitB != NULL){PriorityQueueMMADUnit_SetParent(UnitB,UnitU);}

            PriorityQueueMMADUnit_SetParent(UnitV,Parent);
            *PParent = UnitV;
        }else{                                              //Double Rotation
            UnitB = PriorityQueueMMADUnit_GetChild1(UnitW);
            UnitC = PriorityQueueMMADUnit_GetChild2(UnitW);

            #ifdef PRIORITYQUEUEMM_DISP_INFO
            printf("[INFO] Rebalance[DR] (U:%p V:%p W:%p B:%p C:%p)\n",UnitU,UnitV,UnitW,UnitB,UnitC);
            #endif // PRIORITYQUEUEMM_DISP_INFO

            PriorityQueueMMADUnit_SetChild1(UnitW,UnitU);
            PriorityQueueMMADUnit_SetParent(UnitU,UnitW);
            PriorityQueueMMADUnit_SetChild2(UnitW,UnitV);
            PriorityQueueMMADUnit_SetParent(UnitV,UnitW);


            PriorityQueueMMADUnit_SetChild1(UnitV,UnitC);
            if(UnitC != NULL){PriorityQueueMMADUnit_SetParent(UnitC,UnitV);}

            PriorityQueueMMADUnit_SetChild2(UnitU,UnitB);
            if(UnitB != NULL){PriorityQueueMMADUnit_SetParent(UnitB,UnitU);}

            if(!PriorityQueueMMADUnit_UpdateBalanceAVL(UnitV,RootRef,1,Errval)){
                PRINT_ERROR3;
                return 0;
            }

            PriorityQueueMMADUnit_SetParent(UnitW,Parent);
            *PParent = UnitW;
        }
    }
    PriorityQueueMMADUnit_SetParent(*RootRef,NULL);
    return 1;
}

static int PriorityQueueMMADUnit_UpdateBalanceAVL(PriorityQueueMMADUnit* U,PriorityQueueMMADUnit** RootRef,int Updates,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    if(U == NULL){
        PRINT_ERROR("\"U\" is not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if((RootRef == NULL)||(*RootRef == NULL)){
        PRINT_ERROR("\"RootRef\" is not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    PriorityQueueMMADUnit* CurrentUnit = U;
    int Maxlength1;
    int Maxlength2;
    int Balance;

    #ifndef ABS
    #define ABS(Value)  (((Value) < 0)?(-(Value)):(Value))
    #endif // ABS

    #ifdef PRIORITYQUEUEMM_DISP_INFO
    printf("[INFO] Update Balance: (Start:%p)\n",CurrentUnit);
    #endif // PRIORITYQUEUEMM_DISP_INFO
    while((CurrentUnit != NULL)&&(Updates != 0)){
        Maxlength1 = PriorityQueueMMADUnit_GetChild1Maxlength(CurrentUnit);
        Maxlength2 = PriorityQueueMMADUnit_GetChild2Maxlength(CurrentUnit);
        Balance = Maxlength2 - Maxlength1;
        #ifndef USE_PRIORITYQUEUEMMAD_V2
        PriorityQueueMMADUnit_SetBalance(CurrentUnit,Balance);
        #endif // USE_PRIORITYQUEUEMMAD_V2
        PriorityQueueMMADUnit_SetMaxlength(CurrentUnit,((Maxlength1 > Maxlength2)?(Maxlength1):(Maxlength2)));
        #ifdef PRIORITYQUEUEMM_DISP_INFO
        printf("       Unit:%p (Start:%p Balance:%i MaxLength:%i)\n",CurrentUnit,PriorityQueueMMADUnit_GetItemStart(CurrentUnit),PriorityQueueMMADUnit_GetBalance(CurrentUnit),PriorityQueueMMADUnit_GetMaxlength(CurrentUnit));
        #endif // PRIORITYQUEUEMM_DISP_INFO
        if(ABS(Balance) > 1){
            if(!PriorityQueueMMADUnit_RebalanceAVL(CurrentUnit,RootRef,Errval)){
                PRINT_ERROR3;
                return 0;
            }
        }else{
            Updates = Updates - (Updates > 0);
            CurrentUnit = PriorityQueueMMADUnit_GetParent(CurrentUnit);
        }
    }
    return 1;
}

static int PriorityQueueMMADUnit_InsertIntoAVL(PriorityQueueMMADUnit* U,PriorityQueueMMADUnit** RootRef,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    if(U == NULL){
        PRINT_ERROR("\"U\" is not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if((RootRef == NULL)||(*RootRef == NULL)){
        PRINT_ERROR("\"RootRef\" is not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    PriorityQueueMMADUnit* CurUnit = *RootRef;
    PriorityQueueMMADUnit** NxtUnitRef = ((((uintptr_t)PriorityQueueMMADUnit_GetItemStart(CurUnit)) < ((uintptr_t)PriorityQueueMMADUnit_GetItemStart(U)))?(PriorityQueueMMADUnit_GetChild2Ref(CurUnit)):(PriorityQueueMMADUnit_GetChild1Ref(CurUnit)));
    while(*NxtUnitRef != NULL){
        CurUnit = *NxtUnitRef;
        NxtUnitRef = ((((uintptr_t)PriorityQueueMMADUnit_GetItemStart(CurUnit)) < ((uintptr_t)PriorityQueueMMADUnit_GetItemStart(U)))?(PriorityQueueMMADUnit_GetChild2Ref(CurUnit)):(PriorityQueueMMADUnit_GetChild1Ref(CurUnit)));
    }
    *NxtUnitRef = U;
    PriorityQueueMMADUnit_SetParent(U,CurUnit);
    if(!PriorityQueueMMADUnit_UpdateBalanceAVL(CurUnit,RootRef,-1,Errval)){
        PRINT_ERROR3;
        return 0;
    }
    return 1;
}

static int PriorityQueueMMADUnit_RemoveFromAVL(PriorityQueueMMADUnit* U,PriorityQueueMMADUnit** RootRef,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    if(U == NULL){
        PRINT_ERROR("\"U\" is not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if((RootRef == NULL)||(*RootRef == NULL)){
        PRINT_ERROR("\"RootRef\" is not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    PriorityQueueMMADUnit* Parent1 = PriorityQueueMMADUnit_GetParent(U);
    PriorityQueueMMADUnit* Parent2;
    PriorityQueueMMADUnit** PParent1 = ((Parent1 == NULL)?(RootRef):(((PriorityQueueMMADUnit_GetChild1(Parent1) == U)?(PriorityQueueMMADUnit_GetChild1Ref(Parent1)):(PriorityQueueMMADUnit_GetChild2Ref(Parent1)))));
    PriorityQueueMMADUnit** PParent2;
    PriorityQueueMMADUnit* Child1 = PriorityQueueMMADUnit_GetChild1(U);
    PriorityQueueMMADUnit* Child2 = PriorityQueueMMADUnit_GetChild2(U);
    PriorityQueueMMADUnit* Child3 = NULL;
    PriorityQueueMMADUnit* Closest = NULL;
    #ifdef PRIORITYQUEUEMM_DISP_INFO
    printf("[INFO] Remove From AVL:%p\n",U);
    #endif // PRIORITYQUEUEMM_DISP_INFO
    if((Child1 != NULL)||(Child2 != NULL)){
        if(PriorityQueueMMADUnit_GetBalance(U) > 0){

            //Go Right once and then Left as often as possible:
            //( => smallest Item that is greater than "U")

            if(PriorityQueueMMADUnit_GetChild1(Child2) == NULL){      //Child2 is THAT item:
                Parent2 = Child2;
                PParent2 = PriorityQueueMMADUnit_GetChild2Ref(Child2);
                Child3 = *PParent2;
                Closest = Child2;
            }else{
                Closest = Child2;
                while(PriorityQueueMMADUnit_GetChild1(Closest) != NULL){
                    Parent2 = Closest;
                    PParent2 = PriorityQueueMMADUnit_GetChild1Ref(Parent2);
                    Closest = *PParent2;
                }
                Child3 = PriorityQueueMMADUnit_GetChild2(Closest);
            }
        }else{

            //Go Left once and then Right as often as possible:
            //( => greatest Item that is smaller than "U")

            if(PriorityQueueMMADUnit_GetChild2(Child1) == NULL){      //Child1 is THAT item:
                Parent2 = Child1;
                PParent2 = PriorityQueueMMADUnit_GetChild1Ref(Child1);
                Child3 = *PParent2;
                Closest = Child1;
            }else{
                Closest = Child1;
                while(PriorityQueueMMADUnit_GetChild2(Closest) != NULL){
                    Parent2 = Closest;
                    PParent2 = PriorityQueueMMADUnit_GetChild2Ref(Parent2);
                    Closest = *PParent2;
                }
                Child3 = PriorityQueueMMADUnit_GetChild1(Closest);
            }
        }

        //"U"       : The Unit that should actually be removed from the internal AVL-Tree.
        //"Parent1" : The Parent of "U". Can be NULL if "U" is the Root.
        //"PParent1": Reference to the Child (either Child1 or Child2) in "Parent1" that is "U". ("Closest" should become this Child)
        //            IF "Parent1" IS NULL, "PParent1" SHOULD BE SET TO THE ROOT!

        //"Closest" : The Unit that is the SMALLEST GREATER or GREATEST SMALLER Unit in comparison to "U"
        //"Parent2" : Parent of "Closest"
        //"PParent2": Reference to the Child (either Child1 or Child2) in "Parent2" that is "Closest". ("Child3" should become this Child)
        //"Child3"  : The Child of "Closest". There can at most only be 1 (ONE) child (or no children at all)

        #ifdef PRIORITYQUEUEMM_DISP_INFO
        printf("       Parent1:%p Parent2:%p\n",Parent1,Parent2);
        printf("       Child1 :%p Child2 :%p\n",Child1,Child2);
        printf("       Closest:%p Child3 :%p\n",Closest,Child3);
        #endif // PRIORITYQUEUEMM_DISP_INFO

        *PParent1 = Closest;
        PriorityQueueMMADUnit_SetParent(Closest,Parent1);
        PriorityQueueMMADUnit_SetChild1(Closest,Child1);
        PriorityQueueMMADUnit_SetChild2(Closest,Child2);
        if((Child1 != NULL)&&(Child1 != Closest)){PriorityQueueMMADUnit_SetParent(Child1,Closest);}
        if((Child2 != NULL)&&(Child2 != Closest)){PriorityQueueMMADUnit_SetParent(Child2,Closest);}

        *PParent2 = Child3;
        if(Child3 != NULL){PriorityQueueMMADUnit_SetParent(Child3,Parent2);}
        #ifdef PRIORITYQUEUEMM_DISP_INFO
        if(Parent1 != NULL){
            printf("       Parent1:%p (Stt:%p Prt:%p Cl1:%p Cl2:%p)\n",Parent1,PriorityQueueMMADUnit_GetItemStart(Parent1),PriorityQueueMMADUnit_GetParent(Parent1),PriorityQueueMMADUnit_GetChild1(Parent1),PriorityQueueMMADUnit_GetChild2(Parent1));
        }
        if(Parent2 != NULL){
            printf("       Parent2:%p (Stt:%p Prt:%p Cl1:%p Cl2:%p)\n",Parent2,PriorityQueueMMADUnit_GetItemStart(Parent2),PriorityQueueMMADUnit_GetParent(Parent2),PriorityQueueMMADUnit_GetChild1(Parent2),PriorityQueueMMADUnit_GetChild2(Parent2));
        }
        if(Child1 != NULL){
            printf("       Child1 :%p (Stt:%p Prt:%p Cl1:%p Cl2:%p)\n",Child1,PriorityQueueMMADUnit_GetItemStart(Child1),PriorityQueueMMADUnit_GetParent(Child1),PriorityQueueMMADUnit_GetChild1(Child1),PriorityQueueMMADUnit_GetChild2(Child1));
        }
        if(Child2 != NULL){
            printf("       Child2 :%p (Stt:%p Prt:%p Cl1:%p Cl2:%p)\n",Child2,PriorityQueueMMADUnit_GetItemStart(Child2),PriorityQueueMMADUnit_GetParent(Child2),PriorityQueueMMADUnit_GetChild1(Child2),PriorityQueueMMADUnit_GetChild2(Child2));
        }
        if(Closest != NULL){
            printf("       Closest:%p (Stt:%p Prt:%p Cl1:%p Cl2:%p)\n",Closest,PriorityQueueMMADUnit_GetItemStart(Closest),PriorityQueueMMADUnit_GetParent(Closest),PriorityQueueMMADUnit_GetChild1(Closest),PriorityQueueMMADUnit_GetChild2(Closest));
        }
        if(Child3 != NULL){
            printf("       Child3 :%p (Stt:%p Prt:%p Cl1:%p Cl2:%p)\n",Child3,PriorityQueueMMADUnit_GetItemStart(Child3),PriorityQueueMMADUnit_GetParent(Child3),PriorityQueueMMADUnit_GetChild1(Child3),PriorityQueueMMADUnit_GetChild2(Child3));
        }
        #endif // PRIORITYQUEUEMM_DISP_INFO
        PriorityQueueMMADUnit_SetParent(U,NULL);
        PriorityQueueMMADUnit_SetChild1(U,NULL);
        PriorityQueueMMADUnit_SetChild2(U,NULL);
        if(!PriorityQueueMMADUnit_UpdateBalanceAVL(Parent2,RootRef,-1,Errval)){
            PRINT_ERROR3;
            return 0;
        }
    }else{
        *PParent1 = NULL;

        PriorityQueueMMADUnit_SetParent(U,NULL);
        PriorityQueueMMADUnit_SetChild1(U,NULL);
        PriorityQueueMMADUnit_SetChild2(U,NULL);

        if(Parent1 != NULL){
            if(!PriorityQueueMMADUnit_UpdateBalanceAVL(Parent1,RootRef,-1,Errval)){
                PRINT_ERROR3;
                return 0;
            }
        }
    }
    return 1;
}

#ifdef PRIORITYQUEUEMM_REM_AVL_INFO
#define PRIORITYQUEUEMM_DISP_INFO
#undef PRINT_INFO
#undef PRINT_INFO2
#define PRINT_INFO(msg)     _PRINT_INFO((msg))
#define PRINT_INFO2(msg)    _PRINT_INFO2((msg))
#endif // PRIORITYQUEUEMM_REM_AVL_INFO

#ifdef PRIORITYQUEUEMM_REM_ADU_INFO
#undef PRIORITYQUEUEMM_DISP_INFO
#undef PRINT_INFO
#undef PRINT_INFO2
#define PRINT_INFO(msg)     do{ }while(0)
#define PRINT_INFO2(msg)    do{ }while(0)
#endif // PRIORITYQUEUEMM_REM_ADU_INFO

#ifndef USE_PRIORITYQUEUEMMAD_V2
static PriorityQueueMMADUnit* PriorityQueueMMADUnit_Create(ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}

    if(PriorityQueueMMD_Shift < 0){
        if(sizeof(void*) == 1){PriorityQueueMMD_Shift = 0;}
        if(sizeof(void*) == 2){PriorityQueueMMD_Shift = 1;}
        if(sizeof(void*) == 4){PriorityQueueMMD_Shift = 2;}
        if(sizeof(void*) == 8){PriorityQueueMMD_Shift = 3;}

        //For Future systems:
        if(sizeof(void*) == 16){PriorityQueueMMD_Shift = 4;}
        if(sizeof(void*) == 32){PriorityQueueMMD_Shift = 5;}
        if(sizeof(void*) == 64){PriorityQueueMMD_Shift = 6;}
    }
    if(PriorityQueueMMD_Shift < 0){
        PRINT_ERROR("The Dynamic versions of \"PriorityQueueMM\" are currently not supported for Pointer-sizes that are not a power of 2!\0");
        if(Errval != NULL){*Errval = ERRVAL_NOT_SUPP;}
        return NULL;
    }

    void** Mem = (void**)PRIORITYQUEUEMM_ALLOCATE_MEM;

    if(Mem == NULL){
        PRINT_ERROR("Memory for \"PriorityQueueMMADUnit\" could not be allocated!\0");
        if(Errval != NULL){*Errval = ERRVAL_NO_MEM;}
        return NULL;
    }


    int FirstBlockIndex = (int)(((uintptr_t)Mem) & (PriorityQueueMMDBlock_Size - 1));
    if(FirstBlockIndex){FirstBlockIndex = (PriorityQueueMMDBlock_Size - FirstBlockIndex) >> PriorityQueueMMD_Shift;}
    int FrontMem = FirstBlockIndex;
    int BackMem = 32 - FrontMem;
    PriorityQueueMMADBlock* Block[3];
    PriorityQueueMMADUnit* UnitPtr = NULL;
    int i = 0;
    while(FrontMem >= 8){
        Block[i] = (PriorityQueueMMADBlock*)(&(Mem[(i << 3)]));
        FrontMem = FrontMem - 8;
        i++;
        if(i > 2){break;}
    }
    if(FrontMem >= 4){
        UnitPtr = (PriorityQueueMMADUnit*)(&(Mem[FirstBlockIndex - 4]));
        FrontMem = FrontMem - 4;
        if(FrontMem >= 2){UnitPtr->SpecBlock = &(Mem[FirstBlockIndex - 6]);
        }else{UnitPtr->SpecBlock = &(Mem[126]);}
    }
    int j = 0;
    if(i < 3){
        while(BackMem >= 8){
            Block[i] = (PriorityQueueMMADBlock*)(&(Mem[FirstBlockIndex + 96 + (j << 3)]));
            BackMem = BackMem - 8;
            i++;
            j++;
            if(i > 2){break;}
        }
    }
    if(UnitPtr == NULL){
        UnitPtr = (PriorityQueueMMADUnit*)(&(Mem[124]));
        if(FrontMem >= 2){UnitPtr->SpecBlock = &(Mem[FirstBlockIndex - 2]);
        }else{UnitPtr->SpecBlock = &(Mem[122]);}
    }

    //Block-Initialization:
    //---------------------
    Mem[FirstBlockIndex] = (void*)(Block[0]);
    Mem[FirstBlockIndex + 32] = (void*)(Block[1]);
    Mem[FirstBlockIndex + 64] = (void*)(Block[2]);
    for(i = 0;i < 3;i++){
        Block[i]->UnitPtr = UnitPtr;
        Block[i]->BackPtr = (void*)(&(Mem[FirstBlockIndex + (i << 5)]));
        Block[i]->FrstItem = NULL;
        (((void**)Block[i]->BackPtr)[1]) = (void*)(&(((void**)Block[i]->BackPtr)[2]));
        (((void**)Block[i]->BackPtr)[30]) = NULL;
    }
    (((void**)Block[0]->BackPtr)[31]) = (void*)(&(((void**)Block[0]->BackPtr)[32]));
    (((void**)Block[1]->BackPtr)[31]) = (void*)(&(((void**)Block[1]->BackPtr)[32]));
    (((void**)Block[2]->BackPtr)[31]) = NULL;
    Block[0]->Prev = Block[2];
    Block[0]->Next = Block[1];
    Block[1]->Prev = Block[0];
    Block[1]->Next = Block[2];
    Block[2]->Prev = Block[1];
    Block[2]->Next = Block[0];
    UnitPtr->Block1 = Block[0];
    UnitPtr->Block2 = Block[1];
    UnitPtr->Block3 = Block[2];


    //Unit-Initialization:
    //--------------------

    //Basic-Data:
    PriorityQueueMMADUnit_SetAlloc_Start(UnitPtr,((void*)Mem));
    PriorityQueueMMADUnit_SetOwner(UnitPtr,NULL);

    //AVL-Data:
    PriorityQueueMMADUnit_SetParent(UnitPtr,NULL);
    PriorityQueueMMADUnit_SetChild1(UnitPtr,NULL);
    PriorityQueueMMADUnit_SetChild2(UnitPtr,NULL);
    PriorityQueueMMADUnit_SetMaxlength(UnitPtr,0);
    PriorityQueueMMADUnit_SetBalance(UnitPtr,0);

    //Item-Management-Data:
    PriorityQueueMMADUnit_SetItemCount(UnitPtr,0);
    PriorityQueueMMADUnit_SetNextEmptyItem(UnitPtr,UnitPtr->Block1->BackPtr);
    PriorityQueueMMADUnit_SetNextEmptyUnit(UnitPtr,UnitPtr);
    PriorityQueueMMADUnit_SetPrevEmptyUnit(UnitPtr,UnitPtr);
    for(i = 1;i < 15;i++){
        (((void**)Block[0]->BackPtr)[(i << 1)]) = NULL;
        (((void**)Block[0]->BackPtr)[((i << 1) + 1)]) = (void*)(&(((void**)Block[0]->BackPtr)[((i << 1) + 2)]));
        (((void**)Block[1]->BackPtr)[(i << 1)]) = NULL;
        (((void**)Block[1]->BackPtr)[((i << 1) + 1)]) = (void*)(&(((void**)Block[1]->BackPtr)[((i << 1) + 2)]));
        (((void**)Block[2]->BackPtr)[(i << 1)]) = NULL;
        (((void**)Block[2]->BackPtr)[((i << 1) + 1)]) = (void*)(&(((void**)Block[2]->BackPtr)[((i << 1) + 2)]));
    }

    #ifdef PRIORITYQUEUEMM_DISP_INFO
    printf("[INFO] Created AUnit (Start:%p UnitPtr:%p):\n",PriorityQueueMMADUnit_GetAlloc_Start(UnitPtr),UnitPtr);
    printf("       Block 1: %p (Items: %p)\n",Block[0],Block[0]->BackPtr);
    printf("       Block 2: %p (Items: %p)\n",Block[1],Block[1]->BackPtr);
    printf("       Block 3: %p (Items: %p)\n",Block[2],Block[2]->BackPtr);
    #endif // PRIORITYQUEUEMM_DISP_INFO

    return UnitPtr;
}

static PriorityQueueMMAItem* PriorityQueueMMADUnit_GetNewItem(void* Owner,PriorityQueueMMADUnit** RootRef,PriorityQueueMMADUnit** CurUnitRef,PriorityQueueMMADUnit** LstUnitRef,int* UnitCount,int* ResItemCount,int TotalItemCount,ERRVAL_T* Errval){
    //PriorityQueueMMADUnit_SetPrev(Unit,Value)
    //PriorityQueueMMADUnit_SetNext(Unit,Value)

    //PriorityQueueMMADUnit_GetPrevEmptyUnit(Unit)            ((PriorityQueueMMADUnit*)((Unit)->Block1->Ptr1))
    //PriorityQueueMMADUnit_SetPrevEmptyUnit(Unit,Value)      (((Unit)->Block1->Ptr1) = ((void*)(Value)))
    //PriorityQueueMMADUnit_GetNextEmptyUnit(Unit)            ((PriorityQueueMMADUnit*)((Unit)->Block1->Ptr2))
    //PriorityQueueMMADUnit_SetNextEmptyUnit(Unit,Value)      (((Unit)->Block1->Ptr2) = ((void*)(Value)))


    if(*CurUnitRef == NULL){
        if(*UnitCount > 0){
            *CurUnitRef = PriorityQueueMMADUnit_Create2(RootRef,Errval);
            if(*CurUnitRef == NULL){PRINT_ERROR3;return NULL;}
            PriorityQueueMMADUnit* FstUnit = PriorityQueueMMADUnit_Next(*LstUnitRef);
            PriorityQueueMMADUnit_SetPrev(*CurUnitRef,*LstUnitRef);
            PriorityQueueMMADUnit_SetNext(*CurUnitRef,FstUnit);
            PriorityQueueMMADUnit_SetNext(*LstUnitRef,*CurUnitRef);
            PriorityQueueMMADUnit_SetPrev(FstUnit,*CurUnitRef);
            *LstUnitRef = *CurUnitRef;

            *UnitCount = *UnitCount + 1;
            *ResItemCount = *ResItemCount + 48;
        }else{
            *CurUnitRef = PriorityQueueMMADUnit_Create(Errval);
            if(*CurUnitRef == NULL){PRINT_ERROR3;return NULL;}
            *RootRef = *CurUnitRef;
            *LstUnitRef = *CurUnitRef;
            PriorityQueueMMADUnit_SetPrev(*CurUnitRef,*CurUnitRef);
            PriorityQueueMMADUnit_SetNext(*CurUnitRef,*CurUnitRef);
            PriorityQueueMMADUnit_SetOwner(*CurUnitRef,Owner);
            *UnitCount = 1;
            *ResItemCount = 48;
        }
    }

    int ItemCount = (PriorityQueueMMADUnit_GetItemCount(*CurUnitRef)) + 1;
    #ifdef PRIORITYQUEUEMM_DISP_INFO
    if(ItemCount == 48){printf("[INFO] Filled AUnit!\n");}
    #endif // PRIORITYQUEUEMM_DISP_INFO
    PriorityQueueMMAItem* res = PriorityQueueMMADUnit_GetNextEmptyItem(*CurUnitRef);
    #ifdef PRIORITYQUEUEMM_DISP_INFO
    if(ItemCount == 48){printf("       AItem:%p Next:%p\n",res,(PriorityQueueMMAItem_GetPtr2(res)));}
    #endif // PRIORITYQUEUEMM_DISP_INFO
    PriorityQueueMMADUnit_SetNextEmptyItem(*CurUnitRef,PriorityQueueMMAItem_GetPtr2(res));
    PriorityQueueMMADUnit_SetItemCount(*CurUnitRef,ItemCount);

    if(ItemCount == 48){
        #ifdef PRIORITYQUEUEMM_DISP_INFO
        printf("       Old Current Unit:%p\n",*CurUnitRef);
        #endif // PRIORITYQUEUEMM_DISP_INFO
        //*CurUnitRef = PriorityQueueMMADUnit_Next(*CurUnitRef);
        if(*CurUnitRef != PriorityQueueMMADUnit_GetNextEmptyUnit(*CurUnitRef)){
            PriorityQueueMMADUnit* Last = PriorityQueueMMADUnit_GetPrevEmptyUnit(*CurUnitRef);
            PriorityQueueMMADUnit_SetNextEmptyUnit(Last,PriorityQueueMMADUnit_GetNextEmptyUnit(*CurUnitRef));
            PriorityQueueMMADUnit_SetPrevEmptyUnit(*CurUnitRef,NULL);
            PriorityQueueMMADUnit_SetNextEmptyUnit(*CurUnitRef,NULL);
            *CurUnitRef = PriorityQueueMMADUnit_GetNextEmptyUnit(Last);
            PriorityQueueMMADUnit_SetPrevEmptyUnit(*CurUnitRef,Last);
        }else{
            PriorityQueueMMADUnit_SetPrevEmptyUnit(*CurUnitRef,NULL);
            PriorityQueueMMADUnit_SetNextEmptyUnit(*CurUnitRef,NULL);
            *CurUnitRef = NULL;
        }
        #ifdef PRIORITYQUEUEMM_DISP_INFO
        printf("       New Current Unit:%p\n",*CurUnitRef);
        #endif // PRIORITYQUEUEMM_DISP_INFO
    }
    return res;
}
static PriorityQueueMMADUnit* PriorityQueueMMADUnit_LookUpAVL(PriorityQueueMMAItem* Item,PriorityQueueMMADUnit** RootRef,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    if(Item == NULL){
        PRINT_ERROR("\"Item\" is not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    if(*RootRef == NULL){return NULL;}
    PriorityQueueMMADUnit* CurUnit = *RootRef;
    uintptr_t StartPtr;
    uintptr_t EndPtr;
    while(CurUnit != NULL){
        StartPtr = (uintptr_t)CurUnit->Block1->BackPtr;
        EndPtr = (uintptr_t)(&(((void**)CurUnit->Block3->BackPtr)[30]));
        if((((uintptr_t)Item) >= StartPtr)&&(((uintptr_t)Item) <= EndPtr)){break;}
        if(((uintptr_t)Item) < StartPtr){
            CurUnit = PriorityQueueMMADUnit_GetChild1(CurUnit);
        }else{
            CurUnit = PriorityQueueMMADUnit_GetChild2(CurUnit);
        }
    }
    if(CurUnit == NULL){return NULL;}
    int Index = (((uintptr_t)Item) - StartPtr) >> PriorityQueueMMD_Shift;
    if(Index & 1){return NULL;}
    if(PriorityQueueMMAItem_GetPtr1(Item) == NULL){return NULL;}
    return CurUnit;
}
static int PriorityQueueMMADUnit_RemoveItem(PriorityQueueMMAItem* Item,PriorityQueueMMADUnit** RootRef,PriorityQueueMMADUnit** CurUnitRef,PriorityQueueMMADUnit** LstUnitRef,int* UnitCount,int* ResItemCount,int TotalItemCount,ERRVAL_T* Errval){
    //PriorityQueueMMADUnit_Get(Ptr)                          (*((PriorityQueueMMADUnit**)(((uintptr_t)(Ptr)) & PriorityQueueMMDBlock_SizeMask)))
    //PriorityQueueMMADUnit_GetItemPtr(Unit,Index)            (&(((void**)(Unit)->BackPtr)[(Index)]))
    //PriorityQueueMMADUnit_GetIndexPtr(Unit,Index)           ((void*)(&(((void**)(Unit)->BackPtr)[(Index)])))
    //PriorityQueueMMADUnit_GetIndexValue(Unit,IndexPtr)      ((int)((((uintptr_t)(IndexPtr)) - ((uintptr_t)((Unit)->BackPtr))) >> PriorityQueueMMD_Shift))

    //PriorityQueueMMAItem_GetPtr1(AItem)
    //PriorityQueueMMAItem_GetPtr2(AItem)
    //PriorityQueueMMAItem_SetPtr1(AItem,Value)
    //PriorityQueueMMAItem_SetPtr2(AItem,Value)

    //PriorityQueueMMADUnit_SetPrev(Unit,Value)
    //PriorityQueueMMADUnit_SetNext(Unit,Value)

    //PriorityQueueMMADUnit_GetPrevEmptyUnit(Unit)            ((PriorityQueueMMADUnit*)((Unit)->Block1->Ptr1))
    //PriorityQueueMMADUnit_SetPrevEmptyUnit(Unit,Value)      (((Unit)->Block1->Ptr1) = ((void*)(Value)))
    //PriorityQueueMMADUnit_GetNextEmptyUnit(Unit)            ((PriorityQueueMMADUnit*)((Unit)->Block1->Ptr2))
    //PriorityQueueMMADUnit_SetNextEmptyUnit(Unit,Value)      (((Unit)->Block1->Ptr2) = ((void*)(Value)))

    PriorityQueueMMADBlock* B = PriorityQueueMMADBlock_Get(((void*)Item));
    PriorityQueueMMADUnit* U = B->UnitPtr;
    PriorityQueueMMAItem* PrevEmptyItem = PriorityQueueMMADUnit_GetNextEmptyItem(U);
    PriorityQueueMMAItem_SetPtr1(Item,NULL);
    PriorityQueueMMAItem_SetPtr2(Item,PrevEmptyItem);
    PriorityQueueMMADUnit_SetNextEmptyItem(U,Item);
    int ItemCount = (PriorityQueueMMADUnit_GetItemCount(U)) - 1;
    PriorityQueueMMADUnit_SetItemCount(U,ItemCount);



    if(ItemCount == 47){
        //Unit is no longer filled (as of this remove-operation)
        //=> Set it as new Current Unit

        if(*CurUnitRef == NULL){
            PriorityQueueMMADUnit_SetNextEmptyUnit(U,U);
            PriorityQueueMMADUnit_SetPrevEmptyUnit(U,U);
        }else{
            PriorityQueueMMADUnit* Last = PriorityQueueMMADUnit_GetPrevEmptyUnit(*CurUnitRef);
            PriorityQueueMMADUnit_SetPrevEmptyUnit(U,Last);
            PriorityQueueMMADUnit_SetNextEmptyUnit(U,*CurUnitRef);
            PriorityQueueMMADUnit_SetPrevEmptyUnit(*CurUnitRef,U);
            PriorityQueueMMADUnit_SetNextEmptyUnit(Last,U);
        }
        *CurUnitRef = U;
    }else if(ItemCount == 0){
        if(U == *CurUnitRef){
            //Current Unit is the empty Unit (as of this remove-operation)
            //=> Set the next Unit as Current Unit (which basically makes this Unit the Last not-filled Unit)

            *CurUnitRef = PriorityQueueMMADUnit_GetNextEmptyUnit(*CurUnitRef);
        }else if(U != PriorityQueueMMADUnit_GetPrevEmptyUnit(*CurUnitRef)){
            //The empty unit is not already the last not-filled unit
            //=> Remove the empty unit from this list and insert it before the Current Unit to make it the new last not-filled unit

            PriorityQueueMMADUnit* Prev = PriorityQueueMMADUnit_GetPrevEmptyUnit(U);
            PriorityQueueMMADUnit* Next = PriorityQueueMMADUnit_GetNextEmptyUnit(U);
            PriorityQueueMMADUnit_SetNextEmptyUnit(Prev,Next);
            PriorityQueueMMADUnit_SetPrevEmptyUnit(Next,Prev);

            Prev = PriorityQueueMMADUnit_GetPrevEmptyUnit(*CurUnitRef);
            PriorityQueueMMADUnit_SetPrevEmptyUnit(U,Prev);
            PriorityQueueMMADUnit_SetNextEmptyUnit(U,*CurUnitRef);

            PriorityQueueMMADUnit_SetPrevEmptyUnit(*CurUnitRef,U);
            PriorityQueueMMADUnit_SetNextEmptyUnit(Prev,U);
        }
    }

    if(TotalItemCount + PriorityQueueMMADUnit_BufferItems < *ResItemCount){
        PriorityQueueMMADUnit* Last = PriorityQueueMMADUnit_GetPrevEmptyUnit(*CurUnitRef);
        if(PriorityQueueMMADUnit_GetItemCount(Last) == 0){
            if(!PriorityQueueMMADUnit_Dispose(Last,RootRef,CurUnitRef,LstUnitRef,UnitCount,ResItemCount,TotalItemCount,Errval)){
                PRINT_ERROR3;
                return 0;
            }
        }
    }
    return 1;
}
static int PriorityQueueMMADUnit_Dispose(PriorityQueueMMADUnit* U,PriorityQueueMMADUnit** RootRef,PriorityQueueMMADUnit** CurUnitRef,PriorityQueueMMADUnit** LstUnitRef,int* UnitCount,int* ResItemCount,int TotalItemCount,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    if(U == NULL){
        PRINT_ERROR("\"U\" is not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL2

    if((*UnitCount > 1)&&(!PriorityQueueMMADUnit_RemoveFromAVL(U,RootRef,Errval))){
        PRINT_ERROR3;
        return 0;
    }

    PriorityQueueMMADUnit* Prev = PriorityQueueMMADUnit_Prev(U);
    PriorityQueueMMADUnit* Next = PriorityQueueMMADUnit_Next(U);

    if(Next != NULL){PriorityQueueMMADUnit_SetPrev(Next,Prev);}
    if(Prev != NULL){PriorityQueueMMADUnit_SetNext(Prev,Next);}
    if(U == *LstUnitRef){*LstUnitRef = Prev;}
    *ResItemCount = *ResItemCount - 48;
    *UnitCount = *UnitCount - 1;

    if(U == *CurUnitRef){
        if(*CurUnitRef != PriorityQueueMMADUnit_GetNextEmptyUnit(*CurUnitRef)){
            PriorityQueueMMADUnit* Last = PriorityQueueMMADUnit_GetPrevEmptyUnit(*CurUnitRef);
            PriorityQueueMMADUnit_SetNextEmptyUnit(Last,PriorityQueueMMADUnit_GetNextEmptyUnit(*CurUnitRef));
            PriorityQueueMMADUnit_SetPrevEmptyUnit(*CurUnitRef,NULL);
            PriorityQueueMMADUnit_SetNextEmptyUnit(*CurUnitRef,NULL);
            *CurUnitRef = PriorityQueueMMADUnit_GetNextEmptyUnit(Last);
            PriorityQueueMMADUnit_SetPrevEmptyUnit(*CurUnitRef,Last);
        }else{
            PriorityQueueMMADUnit_SetPrevEmptyUnit(*CurUnitRef,NULL);
            PriorityQueueMMADUnit_SetNextEmptyUnit(*CurUnitRef,NULL);
            *CurUnitRef = NULL;
        }
    }else{
        Prev = PriorityQueueMMADUnit_GetPrevEmptyUnit(U);
        Next = PriorityQueueMMADUnit_GetNextEmptyUnit(U);
        if((Prev != NULL)&&(Next != NULL)){
            PriorityQueueMMADUnit_SetPrevEmptyUnit(Next,Prev);
            PriorityQueueMMADUnit_SetNextEmptyUnit(Prev,Next);
        }
    }

    void* Alloc_Start = PriorityQueueMMADUnit_GetAlloc_Start(U);
    PRIORITYQUEUEMM_RELEASE_MEM(Alloc_Start);
    if(*UnitCount == 0){
        *CurUnitRef = NULL;
        *RootRef = NULL;
        *LstUnitRef = NULL;
    }
    return 1;
}

#else // USE_PRIORITYQUEUEMMAD_V2

static PriorityQueueMMADUnit* PriorityQueueMMADUnit_Create(ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}

    if(PriorityQueueMMD_Shift < 0){
        if(sizeof(void*) == 1){PriorityQueueMMD_Shift = 0;}
        if(sizeof(void*) == 2){PriorityQueueMMD_Shift = 1;}
        if(sizeof(void*) == 4){PriorityQueueMMD_Shift = 2;}
        if(sizeof(void*) == 8){PriorityQueueMMD_Shift = 3;}

        //For Future systems:
        if(sizeof(void*) == 16){PriorityQueueMMD_Shift = 4;}
        if(sizeof(void*) == 32){PriorityQueueMMD_Shift = 5;}
        if(sizeof(void*) == 64){PriorityQueueMMD_Shift = 6;}
    }
    if(PriorityQueueMMD_Shift < 0){
        PRINT_ERROR("The Dynamic versions of \"PriorityQueueMM\" are currently not supported for Pointer-sizes that are not a power of 2!\0");
        if(Errval != NULL){*Errval = ERRVAL_NOT_SUPP;}
        return NULL;
    }

    void** Mem = (void**)PRIORITYQUEUEMM_ALLOCATE_MEM;

    if(Mem == NULL){
        PRINT_ERROR("Memory for \"PriorityQueueMMADUnit\" could not be allocated!\0");
        if(Errval != NULL){*Errval = ERRVAL_NO_MEM;}
        return NULL;
    }


    int FirstBlockIndex = (int)(((uintptr_t)Mem) & (PriorityQueueMMDBlock_Size - 1));
    if(FirstBlockIndex){FirstBlockIndex = (PriorityQueueMMDBlock_Size - FirstBlockIndex) >> PriorityQueueMMD_Shift;}
    int FrontMem = FirstBlockIndex;
    int TotalMem = 128 - FrontMem;
    PriorityQueueMMADUnit* UnitPtr = NULL;

    if(FrontMem < 10){
        UnitPtr = (PriorityQueueMMADUnit*)(&(Mem[118]));
        TotalMem = TotalMem - 10;
        PriorityQueueMMADUnit_SetProp(UnitPtr,1);   //Needs to migrate
    }else{
        UnitPtr = (PriorityQueueMMADUnit*)(&(Mem[0]));
        FrontMem = FrontMem - 10;
        PriorityQueueMMADUnit_SetProp(UnitPtr,((FrontMem / 10) << 1));   //Might be able to "lodge" some unit-headers
    }
    TotalMem = TotalMem - (3 + (TotalMem > 96));
    PriorityQueueMMADUnit_SetMaxPtrCount(UnitPtr,TotalMem);
    UnitPtr->BackPtr = (void*)(&(Mem[FirstBlockIndex]));
    Mem[FirstBlockIndex] = (void*)UnitPtr;
    Mem[FirstBlockIndex + 32] = (void*)UnitPtr;
    Mem[FirstBlockIndex + 64] = (void*)UnitPtr;
    if(TotalMem > 93){Mem[FirstBlockIndex + 96] = (void*)UnitPtr;}


    //Unit-Initialization:
    //--------------------

    //Basic-Data:
    PriorityQueueMMADUnit_SetAlloc_Start(UnitPtr,((void*)Mem));
    PriorityQueueMMADUnit_SetOwner(UnitPtr,NULL);

    //AVL-Data:
    PriorityQueueMMADUnit_SetParent(UnitPtr,NULL);
    PriorityQueueMMADUnit_SetChild1(UnitPtr,NULL);
    PriorityQueueMMADUnit_SetChild2(UnitPtr,NULL);
    PriorityQueueMMADUnit_SetMaxlength(UnitPtr,0);

    //Item-Management-Data:
    PriorityQueueMMADUnit_SetItemCount(UnitPtr,0);
    PriorityQueueMMADUnit_SetNextEmptyItem(UnitPtr,((void*)(&(((void**)UnitPtr->BackPtr)[1]))));

    //"TotalMem": The reduced Count of usable pointer-slots (AT THIS POINT(!))
    //            To get the actual Item-Count: "TotalMem >> 1"
    //            The Maximum Index for the pointer-Slot of the last item is then: "((TotalMem >> 1) - 1) << 1"
    //            This can be simplified to: "(TotalMem & 254) - 2" (TotalMem is 124 at most)
    int i = 0;
    void** ItemArray = (void**)UnitPtr->BackPtr;
    PriorityQueueMMAItem* NxtItem = NULL;
    PriorityQueueMMAItem* CurItem;
    for(i = (TotalMem & 254) - 2;i >= 0;i = i - 2){
            CurItem = (PriorityQueueMMAItem*)(&(ItemArray[PriorityQueueMMADUnit_CorrectIndex(i)]));
            PriorityQueueMMAItem_SetPtr1(CurItem,NULL);
            PriorityQueueMMAItem_SetPtr2(CurItem,NxtItem);
            NxtItem = CurItem;
    }

    #ifdef PRIORITYQUEUEMM_DISP_INFO
    printf("[INFO] Created AUnit (Start:%p UnitPtr:%p Items:%p):\n",PriorityQueueMMADUnit_GetAlloc_Start(UnitPtr),UnitPtr,UnitPtr->BackPtr);
    if(PriorityQueueMMADUnit_GetProp(UnitPtr) > 1){
        printf("       Type: Lodger[Prop:%i] (Can lodge %i)\n",PriorityQueueMMADUnit_GetProp(UnitPtr),(PriorityQueueMMADUnit_GetProp(UnitPtr) >> 1));
        printf("       Max Capacity: %i AItems\n",(PriorityQueueMMADUnit_GetMaxPtrCount(UnitPtr) >> 1));
    }else if(PriorityQueueMMADUnit_GetProp(UnitPtr) == 1){
        printf("       Type: Immigrant[Prop:%i] (Needs to migrate)\n",PriorityQueueMMADUnit_GetProp(UnitPtr));
        printf("       Cur Capacity: %i AItems\n",(PriorityQueueMMADUnit_GetMaxPtrCount(UnitPtr) >> 1));
    }else{
        printf("       Type: Commoner[Prop:%i]\n",PriorityQueueMMADUnit_GetProp(UnitPtr));
        printf("       Max Capacity: %i AItems\n",(PriorityQueueMMADUnit_GetMaxPtrCount(UnitPtr) >> 1));
    }
    #endif // PRIORITYQUEUEMM_DISP_INFO

    return UnitPtr;
}

static PriorityQueueMMAItem* PriorityQueueMMADUnit_GetNewItem(void* Owner,PriorityQueueMMADUnit** RootRef,PriorityQueueMMADUnit** CurUnitRef,PriorityQueueMMADUnit** LstUnitRef,int* UnitCount,int* ResItemCount,int TotalItemCount,ERRVAL_T* Errval){
    if(*CurUnitRef == NULL){
        if(*UnitCount > 0){
            *CurUnitRef = PriorityQueueMMADUnit_Create2(RootRef,Errval);
            if(*CurUnitRef == NULL){PRINT_ERROR3;return NULL;}
            (*CurUnitRef)->Next = NULL;
            (*CurUnitRef)->Prev = NULL;

            *UnitCount = *UnitCount + 1;
            *ResItemCount = *ResItemCount + ((PriorityQueueMMADUnit_GetMaxPtrCount(*CurUnitRef)) >> 1);

            PriorityQueueMMADUnit_InsertCommonerUnit(*CurUnitRef,CurUnitRef,LstUnitRef);
        }else{
            *CurUnitRef = PriorityQueueMMADUnit_Create(Errval);
            if(*CurUnitRef == NULL){PRINT_ERROR3;return NULL;}
            *RootRef = *CurUnitRef;
            *LstUnitRef = *CurUnitRef;
            (*CurUnitRef)->Prev = *CurUnitRef;
            (*CurUnitRef)->Next = *CurUnitRef;
            PriorityQueueMMADUnit_SetOwner(*CurUnitRef,Owner);
            *UnitCount = 1;
            *ResItemCount = (PriorityQueueMMADUnit_GetMaxPtrCount(*CurUnitRef)) >> 1;
        }
    }

    //PriorityQueueMMAItem_GetPtr1(AItem)
    //PriorityQueueMMAItem_GetPtr2(AItem)
    //PriorityQueueMMAItem_SetPtr1(AItem,Value)
    //PriorityQueueMMAItem_SetPtr2(AItem,Value)

    PriorityQueueMMAItem* res = PriorityQueueMMADUnit_GetNextEmptyItem(*CurUnitRef);
    #ifdef PRIORITYQUEUEMM_DISP_INFO
    if(res == NULL){
        printf("[INFO] \"PriorityQueueMMADUnit_GetNextEmptyItem Failed!\n");
        PriorityQueueMMADUnit_PrintSegmentList(CurUnitRef,LstUnitRef,*UnitCount);
    }
    #endif // PRIORITYQUEUEMM_DISP_INFO
    PriorityQueueMMADUnit_SetNextEmptyItem(*CurUnitRef,PriorityQueueMMAItem_GetPtr2(res));
    int ItemCount = (PriorityQueueMMADUnit_GetItemCount(*CurUnitRef)) + 1;
    PriorityQueueMMADUnit_SetItemCount(*CurUnitRef,ItemCount);

    if(PriorityQueueMMADUnit_IsItemFilled(*CurUnitRef)){
        //PriorityQueueMMADUnit* FstUnit = (*LstUnitRef)->Next;
        PriorityQueueMMADUnit* CurUnit = *CurUnitRef;
        *CurUnitRef = ((CurUnit == *LstUnitRef)?(NULL):(CurUnit->Next));
        if(PriorityQueueMMADUnit_DoesMaxLodge(CurUnit)){
            PriorityQueueMMADUnit_InsertFilledLodger(CurUnit,CurUnitRef,LstUnitRef);
        }else if(PriorityQueueMMADUnit_CanLodge(CurUnit)){
            PriorityQueueMMADUnit_InsertItemFilledUnit(CurUnit,CurUnitRef,LstUnitRef);

            PriorityQueueMMADUnit* MigUnit = NULL;

            while((!PriorityQueueMMADUnit_IsFilledLodger(CurUnit))&&(PriorityQueueMMADUnit_IsWaitingImmigrant(CurUnit->Next))){
                MigUnit = CurUnit->Next;
                if(!PriorityQueueMMADUnit_Migrate(&MigUnit,RootRef,CurUnitRef,LstUnitRef)){break;}
                *ResItemCount = *ResItemCount + 5;
            }
        }else if(PriorityQueueMMADUnit_NeedsToMigrate(CurUnit)){
            if(!PriorityQueueMMADUnit_Migrate(&CurUnit,RootRef,CurUnitRef,LstUnitRef)){
                PriorityQueueMMADUnit_InsertItemFilledUnit(CurUnit,CurUnitRef,LstUnitRef);
            }else{
                *ResItemCount = *ResItemCount + 5;
            }
        }else{
            PriorityQueueMMADUnit_InsertItemFilledUnit(CurUnit,CurUnitRef,LstUnitRef);
        }

        if(TotalItemCount + PriorityQueueMMADUnit_BufferItems < *ResItemCount){
            if((!PriorityQueueMMADUnit_DoesLodge(*LstUnitRef))&&(!PriorityQueueMMADUnit_GetItemCount(*LstUnitRef))){
                if(!PriorityQueueMMADUnit_Dispose(*LstUnitRef,RootRef,CurUnitRef,LstUnitRef,UnitCount,ResItemCount,TotalItemCount,Errval)){
                    PRINT_ERROR3;
                }
            }
        }

        #ifdef PRIORITYQUEUEMM_DISP_INFO
        #ifndef PRIORITYQUEUEMM_REM_SEG_INFO
        PriorityQueueMMADUnit_PrintSegmentList(CurUnitRef,LstUnitRef,*UnitCount);
        #endif // PRIORITYQUEUEMM_REM_SEG_INFO
        #endif // PRIORITYQUEUEMM_DISP_INFO
    }
    return res;
}
static PriorityQueueMMADUnit* PriorityQueueMMADUnit_LookUpAVL(PriorityQueueMMAItem* Item,PriorityQueueMMADUnit** RootRef,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    if(Item == NULL){
        PRINT_ERROR("\"Item\" is not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    if(*RootRef == NULL){return NULL;}
    PriorityQueueMMADUnit* CurUnit = *RootRef;
    uintptr_t StartPtr;
    uintptr_t EndPtr;
    while(CurUnit != NULL){
        StartPtr = (uintptr_t)CurUnit->BackPtr;
        EndPtr = (uintptr_t)(((void**)CurUnit->BackPtr) + (PriorityQueueMMADUnit_CorrectIndex(((PriorityQueueMMADUnit_GetMaxPtrCount(CurUnit) & 254) - 2))));
        if((((uintptr_t)Item) >= StartPtr)&&(((uintptr_t)Item) <= EndPtr)){break;}
        if(((uintptr_t)Item) < StartPtr){
            CurUnit = PriorityQueueMMADUnit_GetChild1(CurUnit);
        }else{
            CurUnit = PriorityQueueMMADUnit_GetChild2(CurUnit);
        }
    }
    if(CurUnit == NULL){return NULL;}
    int Index = (((uintptr_t)Item) - StartPtr) >> PriorityQueueMMD_Shift;
    if(!(Index & 31)){return NULL;}
    Index = (((((Index << 5) - Index) - 31) >> 5) + (((Index - 1) & 31) != 0));     //Reverses "PriorityQueueMMADUnit_CorrectIndex()"
    if(Index & 1){return NULL;}
    if(PriorityQueueMMAItem_GetPtr1(Item) == NULL){return NULL;}
    return CurUnit;
}
static int PriorityQueueMMADUnit_RemoveItem(PriorityQueueMMAItem* Item,PriorityQueueMMADUnit** RootRef,PriorityQueueMMADUnit** CurUnitRef,PriorityQueueMMADUnit** LstUnitRef,int* UnitCount,int* ResItemCount,int TotalItemCount,ERRVAL_T* Errval){
    //PriorityQueueMMADUnit_Get(Ptr)                          (*((PriorityQueueMMADUnit**)(((uintptr_t)(Ptr)) & PriorityQueueMMDBlock_SizeMask)))
    //PriorityQueueMMADUnit_GetItemPtr(Unit,Index)            (&(((void**)(Unit)->BackPtr)[(Index)]))
    //PriorityQueueMMADUnit_GetIndexPtr(Unit,Index)           ((void*)(&(((void**)(Unit)->BackPtr)[(Index)])))
    //PriorityQueueMMADUnit_GetIndexValue(Unit,IndexPtr)      ((int)((((uintptr_t)(IndexPtr)) - ((uintptr_t)((Unit)->BackPtr))) >> PriorityQueueMMD_Shift))

    //PriorityQueueMMAItem_GetPtr1(AItem)
    //PriorityQueueMMAItem_GetPtr2(AItem)
    //PriorityQueueMMAItem_SetPtr1(AItem,Value)
    //PriorityQueueMMAItem_SetPtr2(AItem,Value)

    PriorityQueueMMADUnit* U = PriorityQueueMMADUnit_Get(((void*)Item));
    int IsFilled = PriorityQueueMMADUnit_IsItemFilled(U);
    PriorityQueueMMAItem* PrevEmptyItem = PriorityQueueMMADUnit_GetNextEmptyItem(U);
    PriorityQueueMMAItem_SetPtr1(Item,NULL);
    PriorityQueueMMAItem_SetPtr2(Item,PrevEmptyItem);
    PriorityQueueMMADUnit_SetNextEmptyItem(U,Item);
    int ItemCount = (PriorityQueueMMADUnit_GetItemCount(U)) - 1;
    PriorityQueueMMADUnit_SetItemCount(U,ItemCount);

    if((ItemCount <= 0)&&(!PriorityQueueMMADUnit_DoesLodge(U))){
        if(TotalItemCount + PriorityQueueMMADUnit_BufferItems < *ResItemCount){
            if(!PriorityQueueMMADUnit_Dispose(U,RootRef,CurUnitRef,LstUnitRef,UnitCount,ResItemCount,TotalItemCount,Errval)){
                PRINT_ERROR3;
                return 0;
            }
            #ifdef PRIORITYQUEUEMM_DISP_INFO
            #ifndef PRIORITYQUEUEMM_REM_SEG_INFO
            PriorityQueueMMADUnit_PrintSegmentList(CurUnitRef,LstUnitRef,*UnitCount);
            #endif // PRIORITYQUEUEMM_REM_SEG_INFO
            #endif // PRIORITYQUEUEMM_DISP_INFO
        }else{
            #ifdef PRIORITYQUEUEMM_DISP_INFO
            #ifndef PRIORITYQUEUEMM_REM_SEG_INFO
            if(!PriorityQueueMMADUnit_InsertCommonerUnit(U,CurUnitRef,LstUnitRef)){
                PriorityQueueMMADUnit_PrintSegmentList(CurUnitRef,LstUnitRef,*UnitCount);
                return 0;
            }
            PriorityQueueMMADUnit_PrintSegmentList(CurUnitRef,LstUnitRef,*UnitCount);
            return 1;
            #endif // PRIORITYQUEUEMM_REM_SEG_INFO
            #endif // PRIORITYQUEUEMM_DISP_INFO
            return PriorityQueueMMADUnit_InsertCommonerUnit(U,CurUnitRef,LstUnitRef);
        }
    }else if(IsFilled){
        if(PriorityQueueMMADUnit_DoesLodge(U)){
            #ifdef PRIORITYQUEUEMM_DISP_INFO
            #ifndef PRIORITYQUEUEMM_REM_SEG_INFO
            if(!PriorityQueueMMADUnit_InsertLodgerUnit(U,CurUnitRef,LstUnitRef)){
                PriorityQueueMMADUnit_PrintSegmentList(CurUnitRef,LstUnitRef,*UnitCount);
                return 0;
            }
            PriorityQueueMMADUnit_PrintSegmentList(CurUnitRef,LstUnitRef,*UnitCount);
            return 1;
            #endif // PRIORITYQUEUEMM_REM_SEG_INFO
            #endif // PRIORITYQUEUEMM_DISP_INFO
            return PriorityQueueMMADUnit_InsertLodgerUnit(U,CurUnitRef,LstUnitRef);
        }
        #ifdef PRIORITYQUEUEMM_DISP_INFO
        #ifndef PRIORITYQUEUEMM_REM_SEG_INFO
        if(!PriorityQueueMMADUnit_InsertCommonerUnit(U,CurUnitRef,LstUnitRef)){
            PriorityQueueMMADUnit_PrintSegmentList(CurUnitRef,LstUnitRef,*UnitCount);
            return 0;
        }
        PriorityQueueMMADUnit_PrintSegmentList(CurUnitRef,LstUnitRef,*UnitCount);
        return 1;
        #endif // PRIORITYQUEUEMM_REM_SEG_INFO
        #endif // PRIORITYQUEUEMM_DISP_INFO
        return PriorityQueueMMADUnit_InsertCommonerUnit(U,CurUnitRef,LstUnitRef);
    }
    return 1;
}

static int PriorityQueueMMADUnit_Dispose(PriorityQueueMMADUnit* U,PriorityQueueMMADUnit** RootRef,PriorityQueueMMADUnit** CurUnitRef,PriorityQueueMMADUnit** LstUnitRef,int* UnitCount,int* ResItemCount,int TotalItemCount,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    if(U == NULL){
        PRINT_ERROR("\"U\" is not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(PriorityQueueMMADUnit_DoesLodge(U)){
        PRINT_ERROR("\"U\" must not lodge any units!\0");
        if(Errval != NULL){*Errval = ERRVAL_TYPE_INVALID;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    if((*UnitCount > 1)&&(!PriorityQueueMMADUnit_RemoveFromAVL(U,RootRef,Errval))){
        PRINT_ERROR3;
        return 0;
    }

    void* Alloc_Start = PriorityQueueMMADUnit_GetAlloc_Start(U);
    uintptr_t MaxUnitPos = (uintptr_t)(&(((void**)Alloc_Start)[118]));

    #ifdef PRIORITYQUEUEMM_DISP_INFO
    printf("[INFO] Dispose AUnit (Start:%p UnitPtr:%p Items:%p):\n",PriorityQueueMMADUnit_GetAlloc_Start(U),U,U->BackPtr);
    if(PriorityQueueMMADUnit_GetProp(U) > 1){
        printf("       Type: Lodger[Prop:%i] (Can lodge %i)\n",PriorityQueueMMADUnit_GetProp(U),(PriorityQueueMMADUnit_GetProp(U) >> 1));
        printf("       Max Capacity: %i AItems\n",(PriorityQueueMMADUnit_GetMaxPtrCount(U) >> 1));
    }else if(PriorityQueueMMADUnit_GetProp(U) == 1){
        printf("       Type: Immigrant[Prop:%i] (Needs to migrate)\n",PriorityQueueMMADUnit_GetProp(U));
        printf("       Cur Capacity: %i AItems\n",(PriorityQueueMMADUnit_GetMaxPtrCount(U) >> 1));
    }else{
        if((((uintptr_t)U) < ((uintptr_t)Alloc_Start))||(((uintptr_t)U) > MaxUnitPos)){
            printf("       Type: Migrated Commoner[Prop:%i]\n",PriorityQueueMMADUnit_GetProp(U));
            PriorityQueueMMADUnit* LdgUnit = PriorityQueueMMADUnit_Get((((void**)U) + 32));
            printf("       Lodger:%p (Start:%p Items:%p)\n",LdgUnit,PriorityQueueMMADUnit_GetAlloc_Start(LdgUnit),LdgUnit->BackPtr);
        }else{
            printf("       Type: Commoner[Prop:%i]\n",PriorityQueueMMADUnit_GetProp(U));
        }
        printf("       Max Capacity: %i AItems\n",(PriorityQueueMMADUnit_GetMaxPtrCount(U) >> 1));
    }
    #endif // PRIORITYQUEUEMM_DISP_INFO

    PriorityQueueMMADUnit_RemoveSegmentItem(U,CurUnitRef,LstUnitRef);
    *ResItemCount = *ResItemCount - ((PriorityQueueMMADUnit_GetMaxPtrCount(U)) >> 1);
    *UnitCount = *UnitCount - 1;

    if((((uintptr_t)U) < ((uintptr_t)Alloc_Start))||(((uintptr_t)U) > MaxUnitPos)){
        PriorityQueueMMADUnit* LdgUnit = PriorityQueueMMADUnit_Get((((void**)U) + 32));
        int Slot = (((uintptr_t)U) - ((uintptr_t)LdgUnit)) / sizeof(PriorityQueueMMADUnit);
        int Prop = PriorityQueueMMADUnit_GetProp(LdgUnit);
        PriorityQueueMMADUnit_SetProp(LdgUnit,(Prop ^ Slot));
        if(PriorityQueueMMADUnit_IsItemFilled(LdgUnit)){
            PriorityQueueMMADUnit_InsertItemFilledUnit(LdgUnit,CurUnitRef,LstUnitRef);

            PriorityQueueMMADUnit* MigUnit = NULL;

            while((!PriorityQueueMMADUnit_IsFilledLodger(LdgUnit))&&(PriorityQueueMMADUnit_IsWaitingImmigrant(LdgUnit->Next))){
                MigUnit = LdgUnit->Next;
                if(!PriorityQueueMMADUnit_Migrate(&MigUnit,RootRef,CurUnitRef,LstUnitRef)){break;}
                *ResItemCount = *ResItemCount + 5;
            }
        }else{
            if(PriorityQueueMMADUnit_DoesLodge(LdgUnit)){
                PriorityQueueMMADUnit_InsertLodgerUnit(LdgUnit,CurUnitRef,LstUnitRef);
            }else{
                PriorityQueueMMADUnit_InsertCommonerUnit(LdgUnit,CurUnitRef,LstUnitRef);
            }
        }
    }
    PRIORITYQUEUEMM_RELEASE_MEM(Alloc_Start);
    if(*UnitCount == 0){
        *CurUnitRef = NULL;
        *RootRef = NULL;
        *LstUnitRef = NULL;
    }
    return 1;
}
#endif // USE_PRIORITYQUEUEMMAD_V2


static PriorityQueueMMADUnit* PriorityQueueMMADUnit_Create2(PriorityQueueMMADUnit** RootRef,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    if(RootRef == NULL){
        PRINT_ERROR("\"RootRef\" is not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    PriorityQueueMMADUnit* res = PriorityQueueMMADUnit_Create(Errval);
    if(res == NULL){PRINT_ERROR3;return NULL;}
    if(!PriorityQueueMMADUnit_InsertIntoAVL(res,RootRef,Errval)){
        PRINT_ERROR3;
        PRIORITYQUEUEMM_RELEASE_MEM(res);
        return NULL;
    }
    PriorityQueueMMADUnit_SetOwner(res,PriorityQueueMMADUnit_GetOwner(*RootRef));
    return res;
}

#ifdef PRIORITYQUEUEMM_REM_ADU_INFO
#define PRIORITYQUEUEMM_DISP_INFO
#undef PRINT_INFO
#undef PRINT_INFO2
#define PRINT_INFO(msg)     _PRINT_INFO((msg))
#define PRINT_INFO2(msg)    _PRINT_INFO2((msg))
#endif // PRIORITYQUEUEMM_REM_ADU_INFO

#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMAD
#endif // INCLUDE_D_SIZE_PRIORITYQUEUEMM

#ifdef PRIORITYQUEUEMM_REM_DEF_INFO
#undef PRIORITYQUEUEMM_DISP_INFO
#undef PRINT_INFO
#undef PRINT_INFO2
#define PRINT_INFO(msg)     do{ }while(0)
#define PRINT_INFO2(msg)    do{ }while(0)
#endif // PRIORITYQUEUEMM_REM_DEF_INFO

#ifdef INCLUDE_PRIORITYQUEUEMMSD

#ifndef PriorityQueueMMSD_Compare
#ifdef PRIORITYQUEUEMM_FAILABLE_COMP
#define PriorityQueueMMSD_Compare(PQueuePtr,Item1Ptr,Item2Ptr,ErrvalPtr)    (((PriorityQueueMMSD*)(PQueuePtr))->Compare((Item1Ptr),(Item2Ptr),(ErrvalPtr)))
#else // PRIORITYQUEUEMM_FAILABLE_COMP
#define PriorityQueueMMSD_Compare(PQueuePtr,Item1Ptr,Item2Ptr,ErrvalPtr)    (((PriorityQueueMMSD*)(PQueuePtr))->Compare((Item1Ptr),(Item2Ptr)))
#endif // PRIORITYQUEUEMM_FAILABLE_COMP
#endif // PriorityQueueMMSD_Compare

#ifndef PriorityQueueMMSD_DisposeItem
#define PriorityQueueMMSD_DisposeItem(PQueuePtr,ItemPtr,ErrvalPtr)          (((PriorityQueueMMSD*)(PQueuePtr))->DisposeItem((ItemPtr),(ErrvalPtr)))
#endif // PriorityQueueMMSD_DisposeItem

#ifndef PriorityQueueMMSD_DisposeSelf
#define PriorityQueueMMSD_DisposeSelf(PQueuePtr,ErrvalPtr)                  (((((PriorityQueueMMSD*)(PQueuePtr))->DisposeSelf) != NULL)?(((PriorityQueueMMSD*)(PQueuePtr))->DisposeSelf(((void*)(PQueuePtr)),((PriorityQueueMMSD*)(PQueuePtr))->arg,(ErrvalPtr))):(1))
#endif // PriorityQueueMMSD_DisposeSelf

static int PriorityQueueMMSD_SiftUp(PriorityQueueMMSD* Q,void* IndexPtr,int Modifier,ERRVAL_T* Errval){
    //Modifier = 1: Upper Tree with Min at Root (Root has Index "0")
    //Modifier =-1: Lower Tree with Max at Root (Root has Index "1")
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if((Modifier != -1)&&(Modifier != 1)){
        PRINT_ERROR("Modifier is invalid!\0");
        if(Errval != NULL){*Errval = ERRVAL_INVALID_VAL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    void** Item1Ptr;
    void** Item2Ptr;
    PriorityQueueMMDBlock* PrtBlock;
    PriorityQueueMMDBlock* CurBlock = PriorityQueueMMDBlock_Get(IndexPtr);
    int Index = PriorityQueueMMDBlock_GetIndexValue(CurBlock,IndexPtr);
    int TotalIndex = (int)(Index + CurBlock->Offset);
    #ifdef PRIORITYQUEUEMM_DISP_INFO
    printf("[INFO] Entered \"PriorityQueueMMSD_SiftUp\" with:\n");
    #ifndef PRIORITYQUEUEMM_REM_SDU_INFO
    printf("       IndexPtr:%p => Block%i:%p (Items:%p) Index:%i\n",IndexPtr,(((int)(CurBlock->Offset + 2)) >> 5),CurBlock,CurBlock->BackPtr,Index);
    #else // PRIORITYQUEUEMM_REM_SDU_INFO
    printf("       TotalIndex:%i\n",TotalIndex);
    #endif // PRIORITYQUEUEMM_REM_SDU_INFO
    #endif // PRIORITYQUEUEMM_DISP_INFO
    Item1Ptr = PriorityQueueMMDBlock_GetItemPtr(CurBlock,Index);
    void* SwapItem;
    int ParentIndex;
    #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
    int CompRes;
    #endif // PRIORITYQUEUEMM_FAILABLE_COMP
    while(TotalIndex > 61){
        PrtBlock = CurBlock->Parent;
        ParentIndex = ((TotalIndex >> 1) - 1) - ((int)PrtBlock->Offset);
        Item2Ptr = PriorityQueueMMDBlock_GetItemPtr(PrtBlock,ParentIndex);

        #define PriorityQueueMMSD_SiftUp_comp   (PriorityQueueMMSD_Compare(Q,*Item1Ptr,*Item2Ptr,Errval) != Modifier)

        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        CompRes = PriorityQueueMMSD_SiftUp_comp;
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return 0;
        }

        #undef PriorityQueueMMSD_SiftUp_comp
        #define PriorityQueueMMSD_SiftUp_comp   (CompRes)
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP

        if(PriorityQueueMMSD_SiftUp_comp){return 1;}
        #undef PriorityQueueMMSD_SiftUp_comp

        SwapItem = *Item2Ptr;
        *Item2Ptr = *Item1Ptr;
        *Item1Ptr = SwapItem;
        CurBlock = PrtBlock;
        Index = ParentIndex;
        TotalIndex = (int)(Index + CurBlock->Offset);
        Item1Ptr = Item2Ptr;
    }
    while(TotalIndex > 1){
        PrtBlock = CurBlock->Parent;
        ParentIndex = (TotalIndex >> 1) + 1;
        Item2Ptr = PriorityQueueMMDBlock_GetItemPtr(PrtBlock,ParentIndex);

        #define PriorityQueueMMSD_SiftUp_comp   (PriorityQueueMMSD_Compare(Q,*Item1Ptr,*Item2Ptr,Errval) != Modifier)

        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        CompRes = PriorityQueueMMSD_SiftUp_comp;
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return 0;
        }

        #undef PriorityQueueMMSD_SiftUp_comp
        #define PriorityQueueMMSD_SiftUp_comp   (CompRes)
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP

        if(PriorityQueueMMSD_SiftUp_comp){return 1;}
        #undef PriorityQueueMMSD_SiftUp_comp

        SwapItem = *Item2Ptr;
        *Item2Ptr = *Item1Ptr;
        *Item1Ptr = SwapItem;
        CurBlock = PrtBlock;
        Index = ParentIndex;
        TotalIndex = Index - 2;
        Item1Ptr = Item2Ptr;
    }
    return 1;
}

static int PriorityQueueMMSD_SiftDown(PriorityQueueMMSD* Q,void* IndexPtr,int Modifier,ERRVAL_T* Errval){
    //Modifier = 1: Upper Tree with Min at Root (Root has Index "0")
    //Modifier =-1: Lower Tree with Max at Root (Root has Index "1")
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if((Modifier != -1)&&(Modifier != 1)){
        PRINT_ERROR("Modifier is invalid!\0");
        if(Errval != NULL){*Errval = ERRVAL_INVALID_VAL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    void** Item1Ptr;
    void** Item2Ptr;
    PriorityQueueMMDBlock* CldBlock;
    PriorityQueueMMDBlock* CurBlock = PriorityQueueMMDBlock_Get(IndexPtr);
    int Index = PriorityQueueMMDBlock_GetIndexValue(CurBlock,IndexPtr);
    int TotalIndex = (int)(((intptr_t)Index) + CurBlock->Offset);
    #ifdef PRIORITYQUEUEMM_DISP_INFO
    printf("[INFO] Entered \"PriorityQueueMMSD_SiftDown\" with:\n");
    #ifndef PRIORITYQUEUEMM_REM_SDU_INFO
    printf("       IndexPtr:%p => Block%i:%p (Items:%p) Index:%i\n",IndexPtr,(((int)(CurBlock->Offset + 2)) >> 5),CurBlock,CurBlock->BackPtr,Index);
    #else // PRIORITYQUEUEMM_REM_SDU_INFO
    printf("       TotalIndex:%i\n",TotalIndex);
    #endif // PRIORITYQUEUEMM_REM_SDU_INFO
    #endif // PRIORITYQUEUEMM_DISP_INFO
    Item1Ptr = PriorityQueueMMDBlock_GetItemPtr(CurBlock,Index);
    void* SwapItem;
    int ChildIndex;
    int StopIndex2 = (Q->Count >> 1) - 1;
    int StopIndex1 = 14;
    if(StopIndex1 > StopIndex2){StopIndex1 = StopIndex2;}
    int CompRes;
    while(TotalIndex < StopIndex1){
        ChildIndex = (TotalIndex << 1) + 4;
        Item2Ptr = PriorityQueueMMDBlock_GetItemPtr(CurBlock,ChildIndex);
        CompRes = (PriorityQueueMMSD_Compare(Q,*Item2Ptr,Item2Ptr[1],Errval) != Modifier);
        ChildIndex = ChildIndex + CompRes;
        Item2Ptr = &(Item2Ptr[CompRes]);

        #define PriorityQueueMMSD_SiftDown_comp   (PriorityQueueMMSD_Compare(Q,*Item2Ptr,*Item1Ptr,Errval) != Modifier)

        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        CompRes = PriorityQueueMMSD_SiftDown_comp;
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return 0;
        }

        #undef PriorityQueueMMSD_SiftDown_comp
        #define PriorityQueueMMSD_SiftDown_comp   (CompRes)
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP

        if(PriorityQueueMMSD_SiftDown_comp){return 1;}
        #undef PriorityQueueMMSD_SiftDown_comp

        SwapItem = *Item2Ptr;
        *Item2Ptr = *Item1Ptr;
        *Item1Ptr = SwapItem;
        Index = ChildIndex;
        TotalIndex = Index - 2;
        Item1Ptr = Item2Ptr;
    }

    while(TotalIndex < StopIndex2){
        CldBlock = (((TotalIndex > 29)&&(Index > 15))?(PriorityQueueMMDBlock_GetNext((CurBlock->Child))):(CurBlock->Child));
        ChildIndex = (int)((intptr_t)((TotalIndex << 1) + 2) - CldBlock->Offset);
        if(ChildIndex){     //ChildIndex != 0:
            Item2Ptr = PriorityQueueMMDBlock_GetItemPtr(CldBlock,ChildIndex);
            CompRes = (PriorityQueueMMSD_Compare(Q,*Item2Ptr,Item2Ptr[1],Errval) != Modifier);
            ChildIndex = ChildIndex + CompRes;
            Item2Ptr = &(Item2Ptr[CompRes]);
        }else{              //Special Case (ChildIndex == 0):
            ChildIndex = ChildIndex + (PriorityQueueMMSD_Compare(Q,CldBlock->FrstItem,((void**)(CldBlock->BackPtr))[1],Errval) != Modifier);
            Item2Ptr = PriorityQueueMMDBlock_GetItemPtr(CldBlock,ChildIndex);
        }

        #define PriorityQueueMMSD_SiftDown_comp   (PriorityQueueMMSD_Compare(Q,*Item2Ptr,*Item1Ptr,Errval) != Modifier)

        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        CompRes = PriorityQueueMMSD_SiftDown_comp;
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return 0;
        }

        #undef PriorityQueueMMSD_SiftDown_comp
        #define PriorityQueueMMSD_SiftDown_comp   (CompRes)
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP

        if(PriorityQueueMMSD_SiftDown_comp){return 1;}
        #undef PriorityQueueMMSD_SiftDown_comp

        SwapItem = *Item2Ptr;
        *Item2Ptr = *Item1Ptr;
        *Item1Ptr = SwapItem;
        CurBlock = CldBlock;
        Index = ChildIndex;
        TotalIndex = Index + (int)CurBlock->Offset;
        Item1Ptr = Item2Ptr;
    }

    //Border-Case:
    if(((TotalIndex << 1) + 3) == Q->Count){
        if(TotalIndex < 30){
            CldBlock = ((TotalIndex > 13)?(CurBlock->Child):(CurBlock));
        }else{
            CldBlock = ((Index > 15)?(PriorityQueueMMDBlock_GetNext((CurBlock->Child))):(CurBlock->Child));
        }
        ChildIndex = Q->Count - 1 - (int)CldBlock->Offset;
        Item2Ptr = PriorityQueueMMDBlock_GetItemPtr(CldBlock,ChildIndex);

        #define PriorityQueueMMSD_SiftDown_comp     (PriorityQueueMMSD_Compare(Q,*Item2Ptr,*Item1Ptr,Errval) != Modifier)

        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        CompRes = PriorityQueueMMSD_SiftDown_comp;
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return 0;
        }

        #undef PriorityQueueMMSD_SiftDown_comp
        #define PriorityQueueMMSD_SiftDown_comp     (CompRes)
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP

        if(PriorityQueueMMSD_SiftDown_comp){return 1;}
        #undef PriorityQueueMMSD_SiftDown_comp
        SwapItem = *Item2Ptr;
        *Item2Ptr = *Item1Ptr;
        *Item1Ptr = SwapItem;
        CurBlock = CldBlock;
        Index = ChildIndex;
        TotalIndex = Index + (int)CurBlock->Offset;
        Item1Ptr = Item2Ptr;
    }

    //In Case the Change-Area is reached:
    ChildIndex = ((TotalIndex + (TotalIndex < Q->LstLayerStart)) << (TotalIndex < Q->LstLayerStart)) + (Modifier * ((Q->LstLayerStart >> 1) + 1));
    if((ChildIndex == Q->Count)&&(ChildIndex & 1)){ChildIndex = Q->Count - 1;}
    if(ChildIndex >= Q->Count){ChildIndex = (ChildIndex >> 1) - 1;}
    if(ChildIndex < StopIndex2){ChildIndex = (ChildIndex << 1) + 2;}

    if((CurBlock->Other != NULL)&&(((int)(CurBlock->Other->Offset)) <= ChildIndex)){
        CldBlock = CurBlock->Other;
        if(PriorityQueueMMDBlock_IsFirst(CldBlock)){
            if(ChildIndex > 29){CldBlock = CldBlock->Child;}
        }else{
            if(ChildIndex - ((int)CldBlock->Offset) >= 32){
                CldBlock = CldBlock->Child;
                if(ChildIndex - ((int)CldBlock->Offset) >= 32){CldBlock = PriorityQueueMMDBlock_GetNext((CldBlock));}
            }
        }
    }else{
        CldBlock = CurBlock->Parent->Other;
    }

    #ifdef PRIORITYQUEUEMM_DISP_INFO
    printf("[INFO] Do \"Other\"-Evaluation with:\n");
    printf("       TotalIndex1:%i TotalIndex2:%i\n",TotalIndex,ChildIndex);
    #endif // PRIORITYQUEUEMM_DISP_INFO


    if(((TotalIndex < Q->LstLayerStart)&&(ChildIndex >= Q->LstLayerStart)&&(ChildIndex + 1 < Q->Count))||((Modifier == -1)&&(TotalIndex + 1 == Q->Count)&&(!(TotalIndex & 1)))){
        ChildIndex = ((ChildIndex < 30)?(ChildIndex + 2):(ChildIndex - ((int)CldBlock->Offset)));
        if(ChildIndex){     //ChildIndex != 0:
            Item2Ptr = PriorityQueueMMDBlock_GetItemPtr(CldBlock,ChildIndex);
            CompRes = (PriorityQueueMMSD_Compare(Q,*Item2Ptr,Item2Ptr[1],Errval) != Modifier);
            ChildIndex = ChildIndex + CompRes;
            Item2Ptr = &(Item2Ptr[CompRes]);
        }else{              //Special Case (ChildIndex == 0):
            ChildIndex = ChildIndex + (PriorityQueueMMSD_Compare(Q,CldBlock->FrstItem,((void**)(CldBlock->BackPtr))[1],Errval) != Modifier);
            Item2Ptr = PriorityQueueMMDBlock_GetItemPtr(CldBlock,ChildIndex);
        }
    }else{
        ChildIndex = ((ChildIndex < 30)?(ChildIndex + 2):(ChildIndex - ((int)CldBlock->Offset)));
        Item2Ptr = PriorityQueueMMDBlock_GetItemPtr(CldBlock,ChildIndex);
    }

    #ifdef PRIORITYQUEUEMM_DISP_INFO
    #ifndef PRIORITYQUEUEMM_REM_SDU_INFO
    printf("       I1Ptr:%p (Block%i:%p (Items:%p) Index:%i Totalindex:%i)\n",Item1Ptr,(((int)(CurBlock->Offset + 2)) >> 5),CurBlock,CurBlock->BackPtr,Index,TotalIndex);
    printf("       I2Ptr:%p (Block%i:%p (Items:%p) Index:%i Totalindex:%i)\n",Item2Ptr,(((int)(CldBlock->Offset + 2)) >> 5),CldBlock,CldBlock->BackPtr,ChildIndex,((int)(ChildIndex + CldBlock->Offset)));
    #endif // PRIORITYQUEUEMM_REM_SDU_INFO
    #endif // PRIORITYQUEUEMM_DISP_INFO

    #define PriorityQueueMMSD_SiftDown_comp     (PriorityQueueMMSD_Compare(Q,*Item2Ptr,*Item1Ptr,Errval) != Modifier)

    #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
    CompRes = PriorityQueueMMSD_SiftDown_comp;
    if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
        PRINT_ERROR3;
        return 0;
    }

    #undef PriorityQueueMMSD_SiftDown_comp
    #define PriorityQueueMMSD_SiftDown_comp     (CompRes)
    #endif // PRIORITYQUEUEMM_FAILABLE_COMP

    if(PriorityQueueMMSD_SiftDown_comp){return 1;}
    #undef PriorityQueueMMSD_SiftDown_comp
    SwapItem = *Item2Ptr;
    *Item2Ptr = *Item1Ptr;
    *Item1Ptr = SwapItem;
    #ifdef PRIORITYQUEUEMM_DISP_INFO
    printf("[INFO] Call \"PriorityQueueMMSD_SiftUp\" with:\n");
    #ifndef PRIORITYQUEUEMM_REM_SDU_INFO
    printf("       Block%i:%p (Items:%p) Index:%i => %p\n",(((int)(CldBlock->Offset + 2)) >> 5),CldBlock,CldBlock->BackPtr,ChildIndex,PriorityQueueMMDBlock_GetIndexPtr(CldBlock,ChildIndex));
    #else // PRIORITYQUEUEMM_REM_SDU_INFO
    printf("       TotalIndex:%i\n",((((int)(CldBlock->Offset + 2)) + ChildIndex) - 2));
    #endif // PRIORITYQUEUEMM_REM_SDU_INFO
    #endif // PRIORITYQUEUEMM_DISP_INFO
    return PriorityQueueMMSD_SiftUp(Q,PriorityQueueMMDBlock_GetIndexPtr(CldBlock,ChildIndex),-Modifier,Errval);
}


#ifdef PRIORITYQUEUEMM_INHERITANCE
PriorityQueueMM* PriorityQueueMMSD_Get_PriorityQueueMM(PriorityQueueMMSD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return (PriorityQueueMM*)Q;
}
#endif // PRIORITYQUEUEMM_INHERITANCE

PriorityQueueMMSD* PriorityQueueMMSD_Create(void* MemPtr,size_t Size,PRIORITYQUEUEMM_COMP_FUNC_PTR,int(*disposeItem)(void*,ERRVAL_T*),int(*disposeSelf)(void*,void*,ERRVAL_T*),void* arg,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(MemPtr == NULL){
        PRINT_ERROR("Pointer to Memory \"MemPtr\" must not be NULL!\0");
        if(Errval != NULL){*Errval = ERRVAL_NO_MEM;}
        return NULL;
    }
    if(Size < sizeof(PriorityQueueMMSD)){
        PRINT_ERROR("\"Size\" too small!\0");
        if(Errval != NULL){*Errval = ERRVAL_NO_MEM;}
        return NULL;
    }
    if(compare == NULL){
        PRINT_ERROR("\"compare\"-function pointer must not be NULL!\0");
        if(Errval != NULL){*Errval = ERRVAL_OP_MISSING;}
        return NULL;
    }
    if(disposeItem == NULL){
        PRINT_ERROR("\"disposeItem\"-function pointer must not be NULL!\0");
        if(Errval != NULL){*Errval = ERRVAL_OP_MISSING;}
        return NULL;
    }
    if((disposeSelf == NULL)&&(arg != NULL)){
        PRINT_ERROR("\"arg\"-parameter must be NULL if \"disposeSelf\" is NULL!\0");
        if(Errval != NULL){*Errval = ERRVAL_INVALID_VAL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1

    PriorityQueueMMSD* res = (PriorityQueueMMSD*)MemPtr;

    #ifdef PRIORITYQUEUEMM_INHERITANCE
    res->Base.IFunc = &PriorityQueueMMSD_Funcs;
    res->Base.Compare = compare;
    res->Base.DisposeItem = disposeItem;
    res->Base.DisposeSelf = disposeSelf;
    res->Base.arg = arg;
    #else // PRIORITYQUEUEMM_INHERITANCE
    res->Compare = compare;
    res->DisposeItem = disposeItem;
    res->DisposeSelf = disposeSelf;
    res->arg = arg;
    #endif // PRIORITYQUEUEMM_INHERITANCE

    PriorityQueueMMDUnit* U = PriorityQueueMMDUnit_Create(Errval);
    if(U == NULL){
        PRINT_ERROR3;
        PriorityQueueMMSD_DisposeSelf(res,Errval);
        return NULL;
    }



    res->Top = PriorityQueueMMDUnit_FirstBlock(U);
    res->Bottom = res->Top;

    res->Count = 0;
    res->LstLayerStart = 0;
    res->UnitCount = 1;

    #ifdef PRIORITYQUEUEMM_DISP_INFO
    #ifndef PRIORITYQUEUEMM_REM_SDU_INFO
    PriorityQueueMMDBlock* Block[3];
    Block[0] = res->Top;
    Block[1] = (PriorityQueueMMDBlock*)(((void**)res->Top->BackPtr)[32]);
    Block[2] = (PriorityQueueMMDBlock*)(((void**)res->Top->BackPtr)[64]);

    printf("[INFO] Created Unit 1 (Start:%p UnitPtr:%p):\n",U->Alloc_Start,U);
    printf("       Block 0: %p (Items: %p)\n",Block[0],Block[0]->BackPtr);
    printf("       Block 1: %p (Items: %p)\n",Block[1],Block[1]->BackPtr);
    printf("       Block 2: %p (Items: %p)\n",Block[2],Block[2]->BackPtr);
    #endif // PRIORITYQUEUEMM_REM_SDU_INFO
    #endif // PRIORITYQUEUEMM_DISP_INFO


    #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
    int i;
    PriorityQueueMMDBlock* FirstNewBlock = res->Top;
    void** Items = (void**)FirstNewBlock->BackPtr;
    for(i = 1;i < 32;i++){
        Items[i] = NULL;
        Items[i + 32] = NULL;
        Items[i + 64] = NULL;
    }
    FirstNewBlock->FrstItem = NULL;
    FirstNewBlock = PriorityQueueMMDBlock_GetNext(FirstNewBlock);
    FirstNewBlock->FrstItem = NULL;
    FirstNewBlock = PriorityQueueMMDBlock_GetNext(FirstNewBlock);
    FirstNewBlock->FrstItem = NULL;
    #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
    return res;
}

int PriorityQueueMMSD_GetCount(PriorityQueueMMSD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->Count;
}

int PriorityQueueMMSD_GetReservedItems(PriorityQueueMMSD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->UnitCount * 96 - 2;
}

size_t PriorityQueueMMSD_GetReservedMemory(PriorityQueueMMSD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return (size_t)((Q->UnitCount * PriorityQueueMMDBlock_Size) + sizeof(PriorityQueueMMSD));
}

void* PriorityQueueMMSD_GetMin(PriorityQueueMMSD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return ((void**)Q->Top->BackPtr)[2];
}

void* PriorityQueueMMSD_GetMax(PriorityQueueMMSD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q->Count == 1){return ((void**)Q->Top->BackPtr)[2];}
    return ((void**)Q->Top->BackPtr)[3];
}

int PriorityQueueMMSD_Insert(PriorityQueueMMSD* Q,void* Item,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q->Count >= Q->UnitCount * 96 - 2){
        if(PriorityQueueMMDUnit_Create2(Q->Bottom->UnitPtr,Errval) == NULL){
            PRINT_ERROR3;
            return 0;
        }
        Q->UnitCount = Q->UnitCount + 1;
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        int i;
        PriorityQueueMMDBlock* FirstNewBlock = PriorityQueueMMDUnit_FirstBlock(Q->Top->UnitPtr->Prev->UnitPtr);
        void** Items = (void**)FirstNewBlock->BackPtr;
        for(i = 1;i < 32;i++){
            Items[i] = NULL;
            Items[i + 32] = NULL;
            Items[i + 64] = NULL;
        }
        FirstNewBlock->FrstItem = NULL;
        FirstNewBlock = PriorityQueueMMDBlock_GetNext(FirstNewBlock);
        FirstNewBlock->FrstItem = NULL;
        FirstNewBlock = PriorityQueueMMDBlock_GetNext(FirstNewBlock);
        FirstNewBlock->FrstItem = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
    }
    if(Q->Count >= (Q->Bottom->Offset + (intptr_t)32)){Q->Bottom = PriorityQueueMMDBlock_GetNext(Q->Bottom);}

    int TotalIndex = Q->Count;
    int Index = TotalIndex - (((int)(Q->Bottom->Offset + ((intptr_t)2))) - 2);
    void** Item1Ptr = PriorityQueueMMDBlock_GetItemPtr(Q->Bottom,Index);
    void** Item2Ptr;
    #ifdef PRIORITYQUEUEMM_DISP_INFO
    printf("[INFO] TotalIndex: %i\n",TotalIndex);
    #ifndef PRIORITYQUEUEMM_REM_SDU_INFO
    printf("[INFO] Index: %i\n",Index);
    printf("[INFO] Item1Ptr: %p\n",Item1Ptr);
    #endif // PRIORITYQUEUEMM_REM_SDU_INFO
    #endif // PRIORITYQUEUEMM_DISP_INFO
    *Item1Ptr = Item;
    Q->Count++;
    if(Q->Count == 1){return 1;}
    if((Q->LstLayerStart << 1) + 2 == TotalIndex){Q->LstLayerStart = TotalIndex;}
    int Modifier2 = ((TotalIndex - Q->LstLayerStart) < (Q->LstLayerStart >> 1) + 1);    //TRUE if item is a Upper-Tree item
    int Modifier = Modifier2 - !Modifier2;                                              //-1: Lower-Tree-Item, +1: Upper-Tree-Item
    int ChildIndex = ((TotalIndex - 1) + Modifier * (Q->LstLayerStart >> 1)) >> Modifier2;
    PriorityQueueMMDBlock* CldBlock;
    if(ChildIndex < 94){
        if(ChildIndex < 30){
            CldBlock = Q->Top;
            ChildIndex = ChildIndex + 2;
        }else if(ChildIndex < 62){
            CldBlock = PriorityQueueMMDBlock_GetNext(Q->Top);
            ChildIndex = ChildIndex - ((int)CldBlock->Offset);
        }else{
            CldBlock = PriorityQueueMMDUnit_LastBlock(Q->Top->UnitPtr);
            ChildIndex = ChildIndex - ((int)CldBlock->Offset);
        }
    }else{
        if(Modifier2){
            CldBlock = Q->Bottom->Parent->Other;
        }else{
            CldBlock = Q->Bottom->Other;
        }
        ChildIndex = ChildIndex - ((int)CldBlock->Offset);
    }

    if((!Modifier2)&&(Q->Count & 1)){
        void** Item3Ptr[2];
        Item3Ptr[0] = PriorityQueueMMDBlock_GetItemPtr(CldBlock,ChildIndex);
        Item3Ptr[1] = PriorityQueueMMDBlock_GetItemPtr(CldBlock,ChildIndex + 1);
        int CompRes = (PriorityQueueMMSD_Compare(Q,*(Item3Ptr[0]),*(Item3Ptr[1]),Errval) != Modifier);
        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return NULL;
        }
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP
        ChildIndex = ChildIndex + CompRes;
        Item2Ptr = Item3Ptr[CompRes];
    }else{
        Item2Ptr = PriorityQueueMMDBlock_GetItemPtr(CldBlock,ChildIndex);
    }

    #ifdef PRIORITYQUEUEMM_DISP_INFO
    #ifndef PRIORITYQUEUEMM_REM_SDU_INFO
    printf("[INFO] ItemPtr of Block %p and Index %i:%p\n",CldBlock,ChildIndex,Item2Ptr);
    #endif // PRIORITYQUEUEMM_REM_SDU_INFO
    #endif // PRIORITYQUEUEMM_DISP_INFO

    #define PriorityQueueMMSD_Insert_Comp   (PriorityQueueMMSD_Compare(Q,*Item2Ptr,*Item1Ptr,Errval) == Modifier)

    #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
    int CompRes = PriorityQueueMMSD_Insert_Comp;
    if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
        PRINT_ERROR3;
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        *Item1Ptr = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Count--;
        return 0;
    }
    #undef PriorityQueueMMSD_Insert_Comp
    #define PriorityQueueMMSD_Insert_Comp   (CompRes)
    #endif // PRIORITYQUEUEMM_FAILABLE_COMP

    if(PriorityQueueMMSD_Insert_Comp){
        *Item1Ptr = *Item2Ptr;
        *Item2Ptr = Item;
        #ifdef PRIORITYQUEUEMM_DISP_INFO
        printf("[INFO] Call \"PriorityQueueMMSD_SiftUp\" with:\n");
        #ifndef PRIORITYQUEUEMM_REM_SDU_INFO
        printf("       Block%i:%p (Items:%p) Index:%i => %p\n",(((int)(CldBlock->Offset + 2)) >> 5),CldBlock,CldBlock->BackPtr,ChildIndex,PriorityQueueMMDBlock_GetIndexPtr(CldBlock,ChildIndex));
        #else // PRIORITYQUEUEMM_REM_SDU_INFO
        printf("       TotalIndex:%i\n",((((int)(CldBlock->Offset + 2)) + ChildIndex) - 2));
        #endif // PRIORITYQUEUEMM_REM_SDU_INFO
        #endif // PRIORITYQUEUEMM_DISP_INFO
        return PriorityQueueMMSD_SiftUp(Q,PriorityQueueMMDBlock_GetIndexPtr(CldBlock,ChildIndex),-Modifier,Errval);
    }
    #undef PriorityQueueMMSD_Insert_Comp
    #ifdef PRIORITYQUEUEMM_DISP_INFO
    printf("[INFO] Call \"PriorityQueueMMSD_SiftUp\" with:\n");
    #ifndef PRIORITYQUEUEMM_REM_SDU_INFO
    printf("       Block%i:%p (Items:%p) Index:%i => %p\n",(((int)(Q->Bottom->Offset + 2)) >> 5),Q->Bottom,Q->Bottom->BackPtr,Index,PriorityQueueMMDBlock_GetIndexPtr(Q->Bottom,Index));
    #else // PRIORITYQUEUEMM_REM_SDU_INFO
    printf("       TotalIndex:%i\n",((((int)(Q->Bottom->Offset + 2)) + Index) - 2));
    #endif // PRIORITYQUEUEMM_REM_SDU_INFO
    #endif // PRIORITYQUEUEMM_DISP_INFO
    return PriorityQueueMMSD_SiftUp(Q,PriorityQueueMMDBlock_GetIndexPtr(Q->Bottom,Index),Modifier,Errval);
}

int PriorityQueueMMSD_RemoveMin(PriorityQueueMMSD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q->Count == 1){
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        void** Item2Ptr = &(((void**)Q->Top->BackPtr)[2]);
        *Item2Ptr = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Count = 0;
        return 1;
    }
    Q->Count--;
    int BottomIndex = Q->Count - (((int)(Q->Bottom->Offset + ((intptr_t)2))) - 2);
    void** Item1Ptr = PriorityQueueMMDBlock_GetItemPtr(Q->Bottom,BottomIndex);
    void** Item2Ptr = &(((void**)Q->Top->BackPtr)[2]);
    *Item2Ptr = *Item1Ptr;
    #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
    *Item1Ptr = NULL;
    #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
    if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
    if(Q->Count == 1){return 1;}
    if(Q->Count == Q->Bottom->Offset){Q->Bottom = PriorityQueueMMDBlock_GetPrev(Q->Bottom);}
    if((Q->UnitCount * 96 - 3 - Q->Count > 144)&&(PriorityQueueMMDUnit_Dispose(PriorityQueueMMDUnit_Next(Q->Bottom->UnitPtr),Errval))){Q->UnitCount = Q->UnitCount - 1;}
    int res = PriorityQueueMMSD_SiftDown(Q,((void*)Item2Ptr),1,Errval);

    if((res == 0)||(Q->Count < 5)){return res;}
    if((Q->Count & 1)&&(((Q->Count - 1) - Q->LstLayerStart) >= (Q->LstLayerStart >> 1) + 1)){
        BottomIndex = (Q->Count - 1) - (((int)(Q->Bottom->Offset + ((intptr_t)2))) - 2);
        return PriorityQueueMMSD_SiftDown(Q,PriorityQueueMMDBlock_GetIndexPtr(Q->Bottom,BottomIndex),-1,Errval);
    }
    return res;
}

int PriorityQueueMMSD_RemoveMax(PriorityQueueMMSD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    int res = 0;
    if(Q->Count > 2){
        Q->Count--;
        int BottomIndex = Q->Count - (((int)(Q->Bottom->Offset + ((intptr_t)2))) - 2);
        void** Item1Ptr = PriorityQueueMMDBlock_GetItemPtr(Q->Bottom,BottomIndex);
        void** Item2Ptr = &(((void**)Q->Top->BackPtr)[3]);
        *Item2Ptr = *Item1Ptr;
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        *Item1Ptr = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
        if(Q->Count == Q->Bottom->Offset){Q->Bottom = PriorityQueueMMDBlock_GetPrev(Q->Bottom);}
        if((Q->UnitCount * 96 - 3 - Q->Count > 144)&&(PriorityQueueMMDUnit_Dispose(PriorityQueueMMDUnit_Next(Q->Bottom->UnitPtr),Errval))){Q->UnitCount = Q->UnitCount - 1;}
        res = PriorityQueueMMSD_SiftDown(Q,((void*)Item2Ptr),-1,Errval);
        goto END;
    }

    Q->LstLayerStart = 0;

    if(Q->Count == 1){
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        void** Item2Ptr = &(((void**)Q->Top->BackPtr)[2]);
        *Item2Ptr = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Count = 0;
        return 1;
    }
    #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
    void** Item2Ptr =  &(((void**)Q->Top->BackPtr)[3]);
    *Item2Ptr = NULL;
    #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
    Q->Count = 1;
    return 1;

    END:
    if((res == 0)||(Q->Count < 5)){return res;}
    if((Q->Count & 1)&&(((Q->Count - 1) - Q->LstLayerStart) >= (Q->LstLayerStart >> 1) + 1)){
        int BottomIndex = (Q->Count - 1) - (((int)(Q->Bottom->Offset + ((intptr_t)2))) - 2);
        return PriorityQueueMMSD_SiftDown(Q,PriorityQueueMMDBlock_GetIndexPtr(Q->Bottom,BottomIndex),-1,Errval);
    }
    return res;
}

int PriorityQueueMMSD_RemoveMinSource(PriorityQueueMMSD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    void** Item2Ptr = &(((void**)Q->Top->BackPtr)[2]);
    if(!PriorityQueueMMSD_DisposeItem(Q,*Item2Ptr,Errval)){
        PRINT_ERROR3;
        return 0;
    }
    if(Q->Count == 1){
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        *Item2Ptr = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Count = 0;
        return 1;
    }
    Q->Count--;
    int BottomIndex = Q->Count - (((int)(Q->Bottom->Offset + ((intptr_t)2))) - 2);
    void** Item1Ptr = PriorityQueueMMDBlock_GetItemPtr(Q->Bottom,BottomIndex);
    *Item2Ptr = *Item1Ptr;
    #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
    *Item1Ptr = NULL;
    #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
    if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
    if(Q->Count == 1){return 1;}
    if(Q->Count == Q->Bottom->Offset){Q->Bottom = PriorityQueueMMDBlock_GetPrev(Q->Bottom);}
    if((Q->UnitCount * 96 - 3 - Q->Count > 144)&&(PriorityQueueMMDUnit_Dispose(PriorityQueueMMDUnit_Next(Q->Bottom->UnitPtr),Errval))){Q->UnitCount = Q->UnitCount - 1;}
    int res = PriorityQueueMMSD_SiftDown(Q,((void*)Item2Ptr),1,Errval);

    if((res == 0)||(Q->Count < 5)){return res;}
    if((Q->Count & 1)&&(((Q->Count - 1) - Q->LstLayerStart) >= (Q->LstLayerStart >> 1) + 1)){
        BottomIndex = (Q->Count - 1) - (((int)(Q->Bottom->Offset + ((intptr_t)2))) - 2);
        return PriorityQueueMMSD_SiftDown(Q,PriorityQueueMMDBlock_GetIndexPtr(Q->Bottom,BottomIndex),-1,Errval);
    }
    return res;
}

int PriorityQueueMMSD_RemoveMaxSource(PriorityQueueMMSD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    int res = 0;
    if(Q->Count > 2){
        void** Item2Ptr = &(((void**)Q->Top->BackPtr)[3]);
        if(!PriorityQueueMMSD_DisposeItem(Q,*Item2Ptr,Errval)){
            PRINT_ERROR3;
            return 0;
        }
        Q->Count--;
        int BottomIndex = Q->Count - (((int)(Q->Bottom->Offset + ((intptr_t)2))) - 2);
        void** Item1Ptr = PriorityQueueMMDBlock_GetItemPtr(Q->Bottom,BottomIndex);
        *Item2Ptr = *Item1Ptr;
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        *Item1Ptr = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
        if(Q->Count == Q->Bottom->Offset){Q->Bottom = PriorityQueueMMDBlock_GetPrev(Q->Bottom);}
        if((Q->UnitCount * 96 - 3 - Q->Count > 144)&&(PriorityQueueMMDUnit_Dispose(PriorityQueueMMDUnit_Next(Q->Bottom->UnitPtr),Errval))){Q->UnitCount = Q->UnitCount - 1;}
        res = PriorityQueueMMSD_SiftDown(Q,((void*)Item2Ptr),-1,Errval);
        goto END;
    }

    Q->LstLayerStart = 0;

    if(Q->Count == 1){
        void** Item2Ptr = &(((void**)Q->Top->BackPtr)[2]);
        if(!PriorityQueueMMSD_DisposeItem(Q,*Item2Ptr,Errval)){
            PRINT_ERROR3;
            return 0;
        }
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        *Item2Ptr = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Count = 0;
        return 1;
    }
    void** Item2Ptr =  &(((void**)Q->Top->BackPtr)[3]);
    if(!PriorityQueueMMSD_DisposeItem(Q,*Item2Ptr,Errval)){
        PRINT_ERROR3;
        return 0;
    }
    #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
    *Item2Ptr = NULL;
    #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
    Q->Count = 1;
    return 1;

    END:
    if((res == 0)||(Q->Count < 5)){return res;}
    if((Q->Count & 1)&&(((Q->Count - 1) - Q->LstLayerStart) >= (Q->LstLayerStart >> 1) + 1)){
        int BottomIndex = (Q->Count - 1) - (((int)(Q->Bottom->Offset + ((intptr_t)2))) - 2);
        return PriorityQueueMMSD_SiftDown(Q,PriorityQueueMMDBlock_GetIndexPtr(Q->Bottom,BottomIndex),-1,Errval);
    }
    return res;
}

int PriorityQueueMMSD_Clear(PriorityQueueMMSD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    PriorityQueueMMDUnit* TopUnit = Q->Top->UnitPtr;
    PriorityQueueMMDUnit* LstUnit = PriorityQueueMMDUnit_Prev(TopUnit);
    while(LstUnit != TopUnit){
        PriorityQueueMMDUnit_Dispose(LstUnit,Errval);
        LstUnit = PriorityQueueMMDUnit_Prev(TopUnit);
    }
    Q->Count = 0;
    Q->LstLayerStart = 0;
    Q->Bottom = Q->Top;
    Q->UnitCount = 1;
    #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
    int i;
    PriorityQueueMMDBlock* FirstNewBlock = Q->Top;
    void** Items = (void**)FirstNewBlock->BackPtr;
    for(i = 1;i < 32;i++){
        Items[i] = NULL;
        Items[i + 32] = NULL;
        Items[i + 64] = NULL;
    }
    FirstNewBlock->FrstItem = NULL;
    FirstNewBlock = PriorityQueueMMDBlock_GetNext(FirstNewBlock);
    FirstNewBlock->FrstItem = NULL;
    FirstNewBlock = PriorityQueueMMDBlock_GetNext(FirstNewBlock);
    FirstNewBlock->FrstItem = NULL;
    #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
    return 1;
}

int PriorityQueueMMSD_ClearSource(PriorityQueueMMSD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMSD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q->Count == 0){return 1;}
    int i;
    void** Items;
    int Index = Q->Count - (((int)(Q->Bottom->Offset + (intptr_t)2)) - 1);
    PriorityQueueMMDUnit* CurUnit = Q->Bottom->UnitPtr;
    while(1){
        Items = (void**)Q->Bottom->BackPtr;
        for(i = Index;i > 0;i--){
            if(!PriorityQueueMMSD_DisposeItem(Q,Items[i],Errval)){
                PRINT_ERROR3;
                return 0;
            }
            #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
            Items[i] = NULL;
            #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
            Q->Count--;
            if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
        }
        if(!PriorityQueueMMSD_DisposeItem(Q,Q->Bottom->FrstItem,Errval)){
            PRINT_ERROR3;
            return 0;
        }
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Bottom->FrstItem = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Count--;
        if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
        if(Q->Count == 0){return 1;}
        Q->Bottom = PriorityQueueMMDBlock_GetPrev(Q->Bottom);
        if(Q->Bottom->UnitPtr != CurUnit){
            if(!PriorityQueueMMDUnit_Dispose(CurUnit,Errval)){
                PRINT_ERROR3;
                return 0;
            }
            Q->UnitCount = Q->UnitCount - 1;
            CurUnit = Q->Bottom->UnitPtr;
        }
        Index = 31;
    }
}

int PriorityQueueMMSD_Dispose(PriorityQueueMMSD* Q,ERRVAL_T* Errval){
    if(!PriorityQueueMMSD_Clear(Q,Errval)){
        PRINT_ERROR3;
        return 0;
    }
    if(!PriorityQueueMMDUnit_Dispose(Q->Top->UnitPtr,Errval)){
        PRINT_ERROR3;
        return 0;
    }
    return PriorityQueueMMSD_DisposeSelf(Q,Errval);
}

int PriorityQueueMMSD_DisposeSource(PriorityQueueMMSD* Q,ERRVAL_T* Errval){
    if(!PriorityQueueMMSD_ClearSource(Q,Errval)){
        PRINT_ERROR3;
        return 0;
    }
    if(!PriorityQueueMMDUnit_Dispose(Q->Top->UnitPtr,Errval)){
        PRINT_ERROR3;
        return 0;
    }
    return PriorityQueueMMSD_DisposeSelf(Q,Errval);
}
#endif // INCLUDE_PRIORITYQUEUEMMSD


#ifdef INCLUDE_PRIORITYQUEUEMMAD

#define PriorityQueueMMAD_GetNewUnitItem(PQueuePtr,ErrvalPtr)               ((PriorityQueueMMAItem*)PriorityQueueMMADUnit_GetNewItem(((void*)(PQueuePtr)),&(((PriorityQueueMMAD*)(PQueuePtr))->Root),&(((PriorityQueueMMAD*)(PQueuePtr))->CurUnit),&(((PriorityQueueMMAD*)(PQueuePtr))->LstUnit),&(((PriorityQueueMMAD*)(PQueuePtr))->AUnitCount),&(((PriorityQueueMMAD*)(PQueuePtr))->AResItemCount),((PriorityQueueMMAD*)(PQueuePtr))->Count,(ErrvalPtr)))
#define PriorityQueueMMAD_LookUpUnitItem(PQueuePtr,AItemPtr,ErrvalPtr)      ((PriorityQueueMMADUnit*)PriorityQueueMMADUnit_LookUpAVL((AItemPtr),&(((PriorityQueueMMAD*)(PQueuePtr))->Root),(ErrvalPtr)))
#define PriorityQueueMMAD_RemoveUnitItem(PQueuePtr,AItemPtr,ErrvalPtr)      (PriorityQueueMMADUnit_RemoveItem((AItemPtr),&(((PriorityQueueMMAD*)(PQueuePtr))->Root),&(((PriorityQueueMMAD*)(PQueuePtr))->CurUnit),&(((PriorityQueueMMAD*)(PQueuePtr))->LstUnit),&(((PriorityQueueMMAD*)(PQueuePtr))->AUnitCount),&(((PriorityQueueMMAD*)(PQueuePtr))->AResItemCount),((PriorityQueueMMAD*)(PQueuePtr))->Count,(ErrvalPtr)))
#define PriorityQueueMMAD_DisposeUnit(PQueuePtr,UnitPtr,ErrvalPtr)          (PriorityQueueMMADUnit_Dispose((UnitPtr),&(((PriorityQueueMMAD*)(PQueuePtr))->Root),&(((PriorityQueueMMAD*)(PQueuePtr))->CurUnit),&(((PriorityQueueMMAD*)(PQueuePtr))->LstUnit),&(((PriorityQueueMMAD*)(PQueuePtr))->AUnitCount),&(((PriorityQueueMMAD*)(PQueuePtr))->AResItemCount),((PriorityQueueMMAD*)(PQueuePtr))->Count,(ErrvalPtr)))

#ifndef PriorityQueueMMAD_Compare
#ifdef PRIORITYQUEUEMM_FAILABLE_COMP
#define PriorityQueueMMAD_Compare(PQueuePtr,Item1Ptr,Item2Ptr,ErrvalPtr)    (((PriorityQueueMMAD*)(PQueuePtr))->Compare((Item1Ptr),(Item2Ptr),(ErrvalPtr)))
#else // PRIORITYQUEUEMM_FAILABLE_COMP
#define PriorityQueueMMAD_Compare(PQueuePtr,Item1Ptr,Item2Ptr,ErrvalPtr)    (((PriorityQueueMMAD*)(PQueuePtr))->Compare((Item1Ptr),(Item2Ptr)))
#endif // PRIORITYQUEUEMM_FAILABLE_COMP
#endif // PriorityQueueMMAD_Compare

#ifndef PriorityQueueMMAD_DisposeItem
#define PriorityQueueMMAD_DisposeItem(PQueuePtr,ItemPtr,ErrvalPtr)          (((PriorityQueueMMAD*)(PQueuePtr))->DisposeItem((ItemPtr),(ErrvalPtr)))
#endif // PriorityQueueMMAD_DisposeItem

#ifndef PriorityQueueMMAD_DisposeSelf
#define PriorityQueueMMAD_DisposeSelf(PQueuePtr,ErrvalPtr)                  (((((PriorityQueueMMAD*)(PQueuePtr))->DisposeSelf) != NULL)?(((PriorityQueueMMAD*)(PQueuePtr))->DisposeSelf(((void*)(PQueuePtr)),((PriorityQueueMMSD*)(PQueuePtr))->arg,(ErrvalPtr))):(1))
#endif // PriorityQueueMMAD_DisposeSelf

static int PriorityQueueMMAD_SiftUp(PriorityQueueMMAD* Q,void* IndexPtr,int Modifier,ERRVAL_T* Errval){
    //Modifier = 1: Upper Tree with Min at Root (Root has Index "0")
    //Modifier =-1: Lower Tree with Max at Root (Root has Index "1")
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if((Modifier != -1)&&(Modifier != 1)){
        PRINT_ERROR("Modifier is invalid!\0");
        if(Errval != NULL){*Errval = ERRVAL_INVALID_VAL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL2

    //PriorityQueueMMAItem_GetPtr1(AItem)
    //PriorityQueueMMAItem_GetPtr2(AItem)
    //PriorityQueueMMAItem_SetPtr1(AItem,Value)
    //PriorityQueueMMAItem_SetPtr2(AItem,Value)

    void** Item1Ptr;
    void** Item2Ptr;
    PriorityQueueMMDBlock* PrtBlock;
    PriorityQueueMMDBlock* CurBlock = PriorityQueueMMDBlock_Get(IndexPtr);
    int Index = PriorityQueueMMDBlock_GetIndexValue(CurBlock,IndexPtr);
    int TotalIndex = (int)(Index + CurBlock->Offset);
    #ifdef PRIORITYQUEUEMM_DISP_INFO
    printf("[INFO] Entered \"PriorityQueueMMAD_SiftUp\" with:\n");
    #ifndef PRIORITYQUEUEMM_REM_SDU_INFO
    printf("       IndexPtr:%p => Block%i:%p (Items:%p) Index:%i\n",IndexPtr,(((int)(CurBlock->Offset + 2)) >> 5),CurBlock,CurBlock->BackPtr,Index);
    #endif // PRIORITYQUEUEMM_REM_SDU_INFO
    #endif // PRIORITYQUEUEMM_DISP_INFO
    Item1Ptr = PriorityQueueMMDBlock_GetItemPtr(CurBlock,Index);
    PriorityQueueMMAItem* AItem1 = (PriorityQueueMMAItem*)(*Item1Ptr);
    PriorityQueueMMAItem* AItem2;
    #ifdef PRIORITYQUEUEMM_DISP_INFO
    PriorityQueueMMAItem_Print2A(AItem1);
    #ifdef PRIORITYQUEUEMM_REM_SDU_INFO
    printf("       TotalIndex:%i\n",TotalIndex);
    #endif // PRIORITYQUEUEMM_REM_SDU_INFO
    #endif // PRIORITYQUEUEMM_DISP_INFO
    void** AItem1Ptr2 = PriorityQueueMMAItem_GetPtr2Ref(AItem1);
    void** AItem2Ptr2;
    int ParentIndex;
    #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
    int CompRes;
    #endif // PRIORITYQUEUEMM_FAILABLE_COMP
    while(TotalIndex > 61){
        PrtBlock = CurBlock->Parent;
        ParentIndex = ((TotalIndex >> 1) - 1) - ((int)PrtBlock->Offset);
        Item2Ptr = PriorityQueueMMDBlock_GetItemPtr(PrtBlock,ParentIndex);
        AItem2 = (PriorityQueueMMAItem*)(*Item2Ptr);
        AItem2Ptr2 = PriorityQueueMMAItem_GetPtr2Ref(AItem2);

        #define PriorityQueueMMAD_SiftUp_comp   (PriorityQueueMMAD_Compare(Q,*AItem1Ptr2,*AItem2Ptr2,Errval) != Modifier)

        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        CompRes = PriorityQueueMMAD_SiftUp_comp;
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return 0;
        }

        #undef PriorityQueueMMAD_SiftUp_comp
        #define PriorityQueueMMAD_SiftUp_comp   (CompRes)
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP

        if(PriorityQueueMMAD_SiftUp_comp){return 1;}
        #undef PriorityQueueMMAD_SiftUp_comp

        *Item1Ptr = (void*)AItem2;
        *Item2Ptr = (void*)AItem1;
        PriorityQueueMMAItem_SetPtr1(AItem1,PriorityQueueMMDBlock_GetIndexPtr(PrtBlock,ParentIndex));
        PriorityQueueMMAItem_SetPtr1(AItem2,PriorityQueueMMDBlock_GetIndexPtr(CurBlock,Index));
        CurBlock = PrtBlock;
        Index = ParentIndex;
        TotalIndex = (int)(Index + CurBlock->Offset);
        Item1Ptr = Item2Ptr;
    }
    while(TotalIndex > 1){
        PrtBlock = CurBlock->Parent;
        ParentIndex = (TotalIndex >> 1) + 1;
        Item2Ptr = PriorityQueueMMDBlock_GetItemPtr(PrtBlock,ParentIndex);
        AItem2 = (PriorityQueueMMAItem*)(*Item2Ptr);
        AItem2Ptr2 = PriorityQueueMMAItem_GetPtr2Ref(AItem2);

        #define PriorityQueueMMAD_SiftUp_comp   (PriorityQueueMMAD_Compare(Q,*AItem1Ptr2,*AItem2Ptr2,Errval) != Modifier)

        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        CompRes = PriorityQueueMMAD_SiftUp_comp;
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return 0;
        }

        #undef PriorityQueueMMAD_SiftUp_comp
        #define PriorityQueueMMAD_SiftUp_comp   (CompRes)
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP

        if(PriorityQueueMMAD_SiftUp_comp){return 1;}
        #undef PriorityQueueMMAD_SiftUp_comp

        *Item1Ptr = (void*)AItem2;
        *Item2Ptr = (void*)AItem1;
        PriorityQueueMMAItem_SetPtr1(AItem1,PriorityQueueMMDBlock_GetIndexPtr(PrtBlock,ParentIndex));
        PriorityQueueMMAItem_SetPtr1(AItem2,PriorityQueueMMDBlock_GetIndexPtr(CurBlock,Index));
        CurBlock = PrtBlock;
        Index = ParentIndex;
        TotalIndex = Index - 2;
        Item1Ptr = Item2Ptr;
    }
    return 1;
}

static int PriorityQueueMMAD_SiftDown(PriorityQueueMMAD* Q,void* IndexPtr,int Modifier,ERRVAL_T* Errval){
    //Modifier = 1: Upper Tree with Min at Root (Root has Index "0")
    //Modifier =-1: Lower Tree with Max at Root (Root has Index "1")
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if((Modifier != -1)&&(Modifier != 1)){
        PRINT_ERROR("Modifier is invalid!\0");
        if(Errval != NULL){*Errval = ERRVAL_INVALID_VAL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL2
    void** Item1Ptr;
    void** Item2Ptr;
    PriorityQueueMMDBlock* CldBlock;
    PriorityQueueMMDBlock* CurBlock = PriorityQueueMMDBlock_Get(IndexPtr);
    int Index = PriorityQueueMMDBlock_GetIndexValue(CurBlock,IndexPtr);
    int TotalIndex = (int)(((intptr_t)Index) + CurBlock->Offset);
    #ifdef PRIORITYQUEUEMM_DISP_INFO
    printf("[INFO] Entered \"PriorityQueueMMAD_SiftDown\" with:\n");
    #ifndef PRIORITYQUEUEMM_REM_SDU_INFO
    printf("       IndexPtr:%p => Block%i:%p (Items:%p) Index:%i\n",IndexPtr,(((int)(CurBlock->Offset + 2)) >> 5),CurBlock,CurBlock->BackPtr,Index);
    #endif // PRIORITYQUEUEMM_REM_SDU_INFO
    #endif // PRIORITYQUEUEMM_DISP_INFO
    Item1Ptr = PriorityQueueMMDBlock_GetItemPtr(CurBlock,Index);
    PriorityQueueMMAItem* AItem1 = (PriorityQueueMMAItem*)(*Item1Ptr);
    PriorityQueueMMAItem* AItem2;
    #ifdef PRIORITYQUEUEMM_DISP_INFO
    PriorityQueueMMAItem_Print2A(AItem1);
    #ifdef PRIORITYQUEUEMM_REM_SDU_INFO
    printf("       TotalIndex:%i\n",TotalIndex);
    #endif // PRIORITYQUEUEMM_REM_SDU_INFO
    #endif // PRIORITYQUEUEMM_DISP_INFO
    void** AItem1Ptr2 = PriorityQueueMMAItem_GetPtr2Ref(AItem1);
    void** AItem2Ptr2;
    void** AItemPtr2s[2];
    int ChildIndex;
    int StopIndex2 = (Q->Count >> 1) - 1;
    int StopIndex1 = 14;
    if(StopIndex1 > StopIndex2){StopIndex1 = StopIndex2;}
    int CompRes;
    while(TotalIndex < StopIndex1){
        ChildIndex = (TotalIndex << 1) + 4;
        Item2Ptr = PriorityQueueMMDBlock_GetItemPtr(CurBlock,ChildIndex);
        AItemPtr2s[0] = PriorityQueueMMAItem_GetPtr2Ref(((PriorityQueueMMAItem*)(*Item2Ptr)));
        AItemPtr2s[1] = PriorityQueueMMAItem_GetPtr2Ref(((PriorityQueueMMAItem*)(Item2Ptr[1])));
        CompRes = (PriorityQueueMMAD_Compare(Q,*(AItemPtr2s[0]),*(AItemPtr2s[1]),Errval) != Modifier);
        ChildIndex = ChildIndex + CompRes;
        Item2Ptr = &(Item2Ptr[CompRes]);
        AItem2 = (PriorityQueueMMAItem*)(*Item2Ptr);
        AItem2Ptr2 = AItemPtr2s[CompRes];

        #define PriorityQueueMMAD_SiftDown_comp   (PriorityQueueMMAD_Compare(Q,*AItem2Ptr2,*AItem1Ptr2,Errval) != Modifier)

        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        CompRes = PriorityQueueMMAD_SiftDown_comp;
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return 0;
        }

        #undef PriorityQueueMMAD_SiftDown_comp
        #define PriorityQueueMMAD_SiftDown_comp   (CompRes)
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP

        if(PriorityQueueMMAD_SiftDown_comp){return 1;}
        #undef PriorityQueueMMAD_SiftDown_comp

        *Item1Ptr = (void*)AItem2;
        *Item2Ptr = (void*)AItem1;
        PriorityQueueMMAItem_SetPtr1(AItem1,PriorityQueueMMDBlock_GetIndexPtr(CurBlock,ChildIndex));
        PriorityQueueMMAItem_SetPtr1(AItem2,PriorityQueueMMDBlock_GetIndexPtr(CurBlock,Index));
        Index = ChildIndex;
        TotalIndex = Index - 2;
        Item1Ptr = Item2Ptr;
    }

    while(TotalIndex < StopIndex2){
        CldBlock = (((TotalIndex > 29)&&(Index > 15))?(PriorityQueueMMDBlock_GetNext((CurBlock->Child))):(CurBlock->Child));
        ChildIndex = (int)((intptr_t)((TotalIndex << 1) + 2) - CldBlock->Offset);
        if(ChildIndex){     //ChildIndex != 0:
            Item2Ptr = PriorityQueueMMDBlock_GetItemPtr(CldBlock,ChildIndex);
            AItemPtr2s[0] = PriorityQueueMMAItem_GetPtr2Ref(((PriorityQueueMMAItem*)(*Item2Ptr)));
            AItemPtr2s[1] = PriorityQueueMMAItem_GetPtr2Ref(((PriorityQueueMMAItem*)(Item2Ptr[1])));
            CompRes = (PriorityQueueMMAD_Compare(Q,*(AItemPtr2s[0]),*(AItemPtr2s[1]),Errval) != Modifier);
            ChildIndex = ChildIndex + CompRes;
            Item2Ptr = &(Item2Ptr[CompRes]);
        }else{              //Special Case (ChildIndex == 0):
            AItemPtr2s[0] = PriorityQueueMMAItem_GetPtr2Ref(((PriorityQueueMMAItem*)(CldBlock->FrstItem)));
            AItemPtr2s[1] = PriorityQueueMMAItem_GetPtr2Ref(((PriorityQueueMMAItem*)(((void**)(CldBlock->BackPtr))[1])));
            CompRes = (PriorityQueueMMAD_Compare(Q,*(AItemPtr2s[0]),*(AItemPtr2s[1]),Errval) != Modifier);
            ChildIndex = ChildIndex + CompRes;
            Item2Ptr = PriorityQueueMMDBlock_GetItemPtr(CldBlock,ChildIndex);
        }
        AItem2 = (PriorityQueueMMAItem*)(*Item2Ptr);
        AItem2Ptr2 = AItemPtr2s[CompRes];

        #define PriorityQueueMMAD_SiftDown_comp   (PriorityQueueMMAD_Compare(Q,*AItem2Ptr2,*AItem1Ptr2,Errval) != Modifier)

        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        CompRes = PriorityQueueMMAD_SiftDown_comp;
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return 0;
        }

        #undef PriorityQueueMMAD_SiftDown_comp
        #define PriorityQueueMMAD_SiftDown_comp   (CompRes)
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP

        if(PriorityQueueMMAD_SiftDown_comp){return 1;}
        #undef PriorityQueueMMAD_SiftDown_comp


        *Item1Ptr = (void*)AItem2;
        *Item2Ptr = (void*)AItem1;
        PriorityQueueMMAItem_SetPtr1(AItem1,PriorityQueueMMDBlock_GetIndexPtr(CldBlock,ChildIndex));
        PriorityQueueMMAItem_SetPtr1(AItem2,PriorityQueueMMDBlock_GetIndexPtr(CurBlock,Index));
        CurBlock = CldBlock;
        Index = ChildIndex;
        TotalIndex = Index + (int)CurBlock->Offset;
        Item1Ptr = Item2Ptr;
    }

    //Border-Case:
    if(((TotalIndex << 1) + 3) == Q->Count){
        if(TotalIndex < 30){
            CldBlock = ((TotalIndex > 13)?(CurBlock->Child):(CurBlock));
        }else{
            CldBlock = ((Index > 15)?(PriorityQueueMMDBlock_GetNext((CurBlock->Child))):(CurBlock->Child));
        }
        ChildIndex = Q->Count - 1 - (int)CldBlock->Offset;
        Item2Ptr = PriorityQueueMMDBlock_GetItemPtr(CldBlock,ChildIndex);
        AItem2 = (PriorityQueueMMAItem*)(*Item2Ptr);
        AItem2Ptr2 = PriorityQueueMMAItem_GetPtr2Ref(AItem2);

        #define PriorityQueueMMAD_SiftDown_comp     (PriorityQueueMMAD_Compare(Q,*AItem2Ptr2,*AItem1Ptr2,Errval) != Modifier)

        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        CompRes = PriorityQueueMMAD_SiftDown_comp;
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return 0;
        }

        #undef PriorityQueueMMAD_SiftDown_comp
        #define PriorityQueueMMAD_SiftDown_comp     (CompRes)
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP

        if(PriorityQueueMMAD_SiftDown_comp){return 1;}
        #undef PriorityQueueMMAD_SiftDown_comp

        *Item1Ptr = (void*)AItem2;
        *Item2Ptr = (void*)AItem1;
        PriorityQueueMMAItem_SetPtr1(AItem1,PriorityQueueMMDBlock_GetIndexPtr(CldBlock,ChildIndex));
        PriorityQueueMMAItem_SetPtr1(AItem2,PriorityQueueMMDBlock_GetIndexPtr(CurBlock,Index));
        CurBlock = CldBlock;
        Index = ChildIndex;
        TotalIndex = Index + (int)CurBlock->Offset;
        Item1Ptr = Item2Ptr;
    }

    //In Case the Change-Area is reached:
    ChildIndex = ((TotalIndex + (TotalIndex < Q->LstLayerStart)) << (TotalIndex < Q->LstLayerStart)) + (Modifier * ((Q->LstLayerStart >> 1) + 1));
    if((ChildIndex == Q->Count)&&(ChildIndex & 1)){ChildIndex = Q->Count - 1;}
    if(ChildIndex >= Q->Count){ChildIndex = (ChildIndex >> 1) - 1;}
    if(ChildIndex < StopIndex2){ChildIndex = (ChildIndex << 1) + 2;}

    if((CurBlock->Other != NULL)&&(((int)(CurBlock->Other->Offset)) <= ChildIndex)){
        CldBlock = CurBlock->Other;
        if(PriorityQueueMMDBlock_IsFirst(CldBlock)){
            if(ChildIndex > 29){CldBlock = CldBlock->Child;}
        }else{
            if(ChildIndex - ((int)CldBlock->Offset) >= 32){
                CldBlock = CldBlock->Child;
                if(ChildIndex - ((int)CldBlock->Offset) >= 32){CldBlock = PriorityQueueMMDBlock_GetNext((CldBlock));}
            }
        }
    }else{
        CldBlock = CurBlock->Parent->Other;
    }

    #ifdef PRIORITYQUEUEMM_DISP_INFO
    printf("[INFO] Do \"Other\"-Evaluation with:\n");
    printf("       TotalIndex1:%i TotalIndex2:%i\n",TotalIndex,ChildIndex);
    #endif // PRIORITYQUEUEMM_DISP_INFO


    if(((TotalIndex < Q->LstLayerStart)&&(ChildIndex >= Q->LstLayerStart)&&(ChildIndex + 1 < Q->Count))||((Modifier == -1)&&(TotalIndex + 1 == Q->Count)&&(!(TotalIndex & 1)))){
        ChildIndex = ((ChildIndex < 30)?(ChildIndex + 2):(ChildIndex - ((int)CldBlock->Offset)));
        if(ChildIndex){     //ChildIndex != 0:
            Item2Ptr = PriorityQueueMMDBlock_GetItemPtr(CldBlock,ChildIndex);
            AItemPtr2s[0] = PriorityQueueMMAItem_GetPtr2Ref(((PriorityQueueMMAItem*)(*Item2Ptr)));
            AItemPtr2s[1] = PriorityQueueMMAItem_GetPtr2Ref(((PriorityQueueMMAItem*)(Item2Ptr[1])));
            CompRes = (PriorityQueueMMAD_Compare(Q,*(AItemPtr2s[0]),*(AItemPtr2s[1]),Errval) != Modifier);
            ChildIndex = ChildIndex + CompRes;
            Item2Ptr = &(Item2Ptr[CompRes]);
        }else{              //Special Case (ChildIndex == 0):
            AItemPtr2s[0] = PriorityQueueMMAItem_GetPtr2Ref(((PriorityQueueMMAItem*)(CldBlock->FrstItem)));
            AItemPtr2s[1] = PriorityQueueMMAItem_GetPtr2Ref(((PriorityQueueMMAItem*)(((void**)(CldBlock->BackPtr))[1])));
            CompRes = (PriorityQueueMMAD_Compare(Q,*(AItemPtr2s[0]),*(AItemPtr2s[1]),Errval) != Modifier);
            ChildIndex = ChildIndex + CompRes;
            Item2Ptr = PriorityQueueMMDBlock_GetItemPtr(CldBlock,ChildIndex);
        }
        AItem2 = (PriorityQueueMMAItem*)(*Item2Ptr);
        AItem2Ptr2 = AItemPtr2s[CompRes];
    }else{
        ChildIndex = ((ChildIndex < 30)?(ChildIndex + 2):(ChildIndex - ((int)CldBlock->Offset)));
        Item2Ptr = PriorityQueueMMDBlock_GetItemPtr(CldBlock,ChildIndex);
        AItem2 = (PriorityQueueMMAItem*)(*Item2Ptr);
        AItem2Ptr2 = PriorityQueueMMAItem_GetPtr2Ref(AItem2);
    }

    #ifdef PRIORITYQUEUEMM_DISP_INFO
    #ifndef PRIORITYQUEUEMM_REM_SDU_INFO
    printf("       I1Ptr:%p (Block%i:%p (Items:%p) Index:%i Totalindex:%i)\n",Item1Ptr,(((int)(CurBlock->Offset + 2)) >> 5),CurBlock,CurBlock->BackPtr,Index,TotalIndex);
    printf("       I2Ptr:%p (Block%i:%p (Items:%p) Index:%i Totalindex:%i)\n",Item2Ptr,(((int)(CldBlock->Offset + 2)) >> 5),CldBlock,CldBlock->BackPtr,ChildIndex,((int)(ChildIndex + CldBlock->Offset)));
    #endif // PRIORITYQUEUEMM_REM_SDU_INFO
    #ifndef PRIORITYQUEUEMM_REM_ADU_INFO
    printf("       AItem1:");PriorityQueueMMAItem_Print3A(AItem1);
    printf("       AItem2:");PriorityQueueMMAItem_Print3A(AItem2);
    #endif // PRIORITYQUEUEMM_REM_ADU_INFO
    #endif // PRIORITYQUEUEMM_DISP_INFO

    #define PriorityQueueMMAD_SiftDown_comp     (PriorityQueueMMAD_Compare(Q,*AItem2Ptr2,*AItem1Ptr2,Errval) != Modifier)

    #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
    CompRes = PriorityQueueMMAD_SiftDown_comp;
    if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
        PRINT_ERROR3;
        return 0;
    }

    #undef PriorityQueueMMAD_SiftDown_comp
    #define PriorityQueueMMAD_SiftDown_comp     (CompRes)
    #endif // PRIORITYQUEUEMM_FAILABLE_COMP

    if(PriorityQueueMMAD_SiftDown_comp){return 1;}
    #undef PriorityQueueMMAD_SiftDown_comp

    *Item1Ptr = (void*)AItem2;
    *Item2Ptr = (void*)AItem1;
    PriorityQueueMMAItem_SetPtr1(AItem1,PriorityQueueMMDBlock_GetIndexPtr(CldBlock,ChildIndex));
    PriorityQueueMMAItem_SetPtr1(AItem2,PriorityQueueMMDBlock_GetIndexPtr(CurBlock,Index));
    #ifdef PRIORITYQUEUEMM_DISP_INFO
    printf("[INFO] Call \"PriorityQueueMMSD_SiftUp\" with:\n");
    #ifndef PRIORITYQUEUEMM_REM_SDU_INFO
    printf("       Block%i:%p (Items:%p) Index:%i => %p\n",(((int)(CldBlock->Offset + 2)) >> 5),CldBlock,CldBlock->BackPtr,ChildIndex,PriorityQueueMMDBlock_GetIndexPtr(CldBlock,ChildIndex));
    #endif // PRIORITYQUEUEMM_REM_SDU_INFO
    PriorityQueueMMAItem_Print2A(AItem1);
    #ifdef PRIORITYQUEUEMM_REM_SDU_INFO
    printf("       TotalIndex:%i\n",((((int)(CldBlock->Offset + 2)) + ChildIndex) - 2));
    #endif // PRIORITYQUEUEMM_REM_SDU_INFO
    #endif // PRIORITYQUEUEMM_DISP_INFO
    return PriorityQueueMMAD_SiftUp(Q,PriorityQueueMMDBlock_GetIndexPtr(CldBlock,ChildIndex),-Modifier,Errval);
}



#ifdef PRIORITYQUEUEMM_INHERITANCE
PriorityQueueMM* PriorityQueueMMAD_Get_PriorityQueueMM(PriorityQueueMMAD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return (PriorityQueueMM*)Q;
}
#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMA
PriorityQueueMMA* PriorityQueueMMAD_Get_PriorityQueueMMA(PriorityQueueMMAD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return (PriorityQueueMMA*)Q;
}
#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMA
#endif // PRIORITYQUEUEMM_INHERITANCE

PriorityQueueMMAD* PriorityQueueMMAD_Create(void* MemPtr,size_t Size,PRIORITYQUEUEMM_COMP_FUNC_PTR,int(*disposeItem)(void*,ERRVAL_T*),int(*disposeSelf)(void*,void*,ERRVAL_T*),void* arg,ERRVAL_T* Errval){
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(MemPtr == NULL){
        PRINT_ERROR("Pointer to Memory \"MemPtr\" must not be NULL!\0");
        if(Errval != NULL){*Errval = ERRVAL_NO_MEM;}
        return NULL;
    }
    if(Size < sizeof(PriorityQueueMMAD)){
        PRINT_ERROR("\"Size\" too small!\0");
        if(Errval != NULL){*Errval = ERRVAL_NO_MEM;}
        return NULL;
    }
    if(compare == NULL){
        PRINT_ERROR("\"compare\"-function pointer must not be NULL!\0");
        if(Errval != NULL){*Errval = ERRVAL_OP_MISSING;}
        return NULL;
    }
    if(disposeItem == NULL){
        PRINT_ERROR("\"disposeItem\"-function pointer must not be NULL!\0");
        if(Errval != NULL){*Errval = ERRVAL_OP_MISSING;}
        return NULL;
    }
    if((disposeSelf == NULL)&&(arg != NULL)){
        PRINT_ERROR("\"arg\"-parameter must be NULL if \"disposeSelf\" is NULL!\0");
        if(Errval != NULL){*Errval = ERRVAL_INVALID_VAL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1

    PriorityQueueMMAD* res = (PriorityQueueMMAD*)MemPtr;

    #ifdef PRIORITYQUEUEMM_INHERITANCE
    res->Base.IFunc = &PriorityQueueMMAD_AFuncs;
    res->Base.Base.IFunc = &PriorityQueueMMAD_Funcs;
    res->Base.Base.Compare = compare;
    res->Base.Base.DisposeItem = disposeItem;
    res->Base.Base.DisposeSelf = disposeSelf;
    res->Base.Base.arg = arg;
    #else // PRIORITYQUEUEMM_INHERITANCE
    res->Compare = compare;
    res->DisposeItem = disposeItem;
    res->DisposeSelf = disposeSelf;
    res->arg = arg;
    #endif // PRIORITYQUEUEMM_INHERITANCE

    PriorityQueueMMDUnit* U = PriorityQueueMMDUnit_Create(Errval);
    if(U == NULL){
        PRINT_ERROR3;
        PriorityQueueMMAD_DisposeSelf(res,Errval);
        return NULL;
    }

    res->Top = PriorityQueueMMDUnit_FirstBlock(U);
    res->Bottom = res->Top;

    res->Count = 0;
    res->LstLayerStart = 0;
    res->UnitCount = 1;

    res->AResItemCount = 0;
    res->AUnitCount = 0;
    res->Root = NULL;
    res->LstUnit = NULL;
    res->CurUnit = NULL;

    #ifdef PRIORITYQUEUEMM_DISP_INFO
    #ifndef PRIORITYQUEUEMM_REM_SDU_INFO
    PriorityQueueMMDBlock* Block[3];
    Block[0] = res->Top;
    Block[1] = (PriorityQueueMMDBlock*)(((void**)res->Top->BackPtr)[32]);
    Block[2] = (PriorityQueueMMDBlock*)(((void**)res->Top->BackPtr)[64]);

    printf("[INFO] Created Unit 1 (Start:%p UnitPtr:%p):\n",U->Alloc_Start,U);
    printf("       Block 0: %p (Items: %p)\n",Block[0],Block[0]->BackPtr);
    printf("       Block 1: %p (Items: %p)\n",Block[1],Block[1]->BackPtr);
    printf("       Block 2: %p (Items: %p)\n",Block[2],Block[2]->BackPtr);
    #endif // PRIORITYQUEUEMM_REM_SDU_INFO
    #endif // PRIORITYQUEUEMM_DISP_INFO


    #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
    int i;
    PriorityQueueMMDBlock* FirstNewBlock = res->Top;
    void** Items = (void**)FirstNewBlock->BackPtr;
    for(i = 1;i < 32;i++){
        Items[i] = NULL;
        Items[i + 32] = NULL;
        Items[i + 64] = NULL;
    }
    FirstNewBlock->FrstItem = NULL;
    FirstNewBlock = PriorityQueueMMDBlock_GetNext(FirstNewBlock);
    FirstNewBlock->FrstItem = NULL;
    FirstNewBlock = PriorityQueueMMDBlock_GetNext(FirstNewBlock);
    FirstNewBlock->FrstItem = NULL;
    #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
    return res;
}

int PriorityQueueMMAD_GetCount(PriorityQueueMMAD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return Q->Count;
}

int PriorityQueueMMAD_GetReservedItems(PriorityQueueMMAD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    int ResCount1 = Q->UnitCount * 96 - 2;
    return ((ResCount1 <= Q->AResItemCount)?(ResCount1):(Q->AResItemCount));
}

size_t PriorityQueueMMAD_GetReservedMemory(PriorityQueueMMAD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return (size_t)(((Q->UnitCount + Q->AUnitCount) * PriorityQueueMMDBlock_Size) + sizeof(PriorityQueueMMAD));
}

void* PriorityQueueMMAD_GetMin(PriorityQueueMMAD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1

    //PriorityQueueMMAItem_GetPtr1(AItem)
    //PriorityQueueMMAItem_GetPtr2(AItem)
    //PriorityQueueMMAItem_SetPtr1(AItem,Value)
    //PriorityQueueMMAItem_SetPtr2(AItem,Value)

    PriorityQueueMMAItem* Item = (PriorityQueueMMAItem*)(((void**)Q->Top->BackPtr)[2]);
    return PriorityQueueMMAItem_GetPtr2(Item);
}

void* PriorityQueueMMAD_GetMax(PriorityQueueMMAD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    PriorityQueueMMAItem* Item = (PriorityQueueMMAItem*)((Q->Count == 1)?(((void**)Q->Top->BackPtr)[2]):(((void**)Q->Top->BackPtr)[3]));
    return PriorityQueueMMAItem_GetPtr2(Item);
}

PriorityQueueMMAItem* PriorityQueueMMAD_GetMinItem(PriorityQueueMMAD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1

    //PriorityQueueMMAItem_GetPtr1(AItem)
    //PriorityQueueMMAItem_GetPtr2(AItem)
    //PriorityQueueMMAItem_SetPtr1(AItem,Value)
    //PriorityQueueMMAItem_SetPtr2(AItem,Value)

    PriorityQueueMMAItem* Item = (PriorityQueueMMAItem*)(((void**)Q->Top->BackPtr)[2]);
    return Item;
}

PriorityQueueMMAItem* PriorityQueueMMAD_GetMaxItem(PriorityQueueMMAD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    PriorityQueueMMAItem* Item = (PriorityQueueMMAItem*)((Q->Count == 1)?(((void**)Q->Top->BackPtr)[2]):(((void**)Q->Top->BackPtr)[3]));
    return Item;
}

int PriorityQueueMMAD_Insert(PriorityQueueMMAD* Q,void* Item,ERRVAL_T* Errval){
    return (PriorityQueueMMAD_GetInsertedItem(Q,Item,Errval) != NULL);
}

PriorityQueueMMAItem* PriorityQueueMMAD_GetInsertedItem(PriorityQueueMMAD* Q,void* Item,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q->Count >= Q->UnitCount * 96 - 2){
        if(PriorityQueueMMDUnit_Create2(Q->Bottom->UnitPtr,Errval) == NULL){
            PRINT_ERROR3;
            return NULL;
        }
        Q->UnitCount = Q->UnitCount + 1;
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        int i;
        PriorityQueueMMDBlock* FirstNewBlock = PriorityQueueMMDUnit_FirstBlock(Q->Top->UnitPtr->Prev->UnitPtr);
        void** Items = (void**)FirstNewBlock->BackPtr;
        for(i = 1;i < 32;i++){
            Items[i] = NULL;
            Items[i + 32] = NULL;
            Items[i + 64] = NULL;
        }
        FirstNewBlock->FrstItem = NULL;
        FirstNewBlock = PriorityQueueMMDBlock_GetNext(FirstNewBlock);
        FirstNewBlock->FrstItem = NULL;
        FirstNewBlock = PriorityQueueMMDBlock_GetNext(FirstNewBlock);
        FirstNewBlock->FrstItem = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
    }
    if(Q->Count >= (Q->Bottom->Offset + (intptr_t)32)){Q->Bottom = PriorityQueueMMDBlock_GetNext(Q->Bottom);}

    int TotalIndex = Q->Count;
    int Index = TotalIndex - (((int)(Q->Bottom->Offset + ((intptr_t)2))) - 2);
    void** Item1Ptr = PriorityQueueMMDBlock_GetItemPtr(Q->Bottom,Index);
    void** Item2Ptr;
    #ifdef PRIORITYQUEUEMM_DISP_INFO
    printf("[INFO] TotalIndex: %i\n",TotalIndex);
    #ifndef PRIORITYQUEUEMM_REM_SDU_INFO
    printf("[INFO] Index: %i\n",Index);
    printf("[INFO] Item1Ptr: %p\n",Item1Ptr);
    #endif // PRIORITYQUEUEMM_REM_SDU_INFO
    #endif // PRIORITYQUEUEMM_DISP_INFO

    PriorityQueueMMAItem* AItem1 = PriorityQueueMMAD_GetNewUnitItem(Q,Errval);
    PriorityQueueMMAItem_SetPtr1(AItem1,PriorityQueueMMDBlock_GetIndexPtr(Q->Bottom,Index));
    PriorityQueueMMAItem_SetPtr2(AItem1,Item);
    void** AItem1Ptr2 = PriorityQueueMMAItem_GetPtr2Ref(AItem1);
    *Item1Ptr = (void*)AItem1;
    Q->Count++;
    #ifdef PRIORITYQUEUEMM_DISP_INFO
    PriorityQueueMMAItem_Print1A(AItem1);
    #endif // PRIORITYQUEUEMM_DISP_INFO

    if(Q->Count == 1){return AItem1;}
    if((Q->LstLayerStart << 1) + 2 == TotalIndex){Q->LstLayerStart = TotalIndex;}
    int Modifier2 = ((TotalIndex - Q->LstLayerStart) < (Q->LstLayerStart >> 1) + 1);    //TRUE if item is a Upper-Tree item
    int Modifier = Modifier2 - !Modifier2;                                              //-1: Lower-Tree-Item, +1: Upper-Tree-Item
    int ChildIndex = ((TotalIndex - 1) + Modifier * (Q->LstLayerStart >> 1)) >> Modifier2;
    PriorityQueueMMDBlock* CldBlock;
    if(ChildIndex < 94){
        if(ChildIndex < 30){
            CldBlock = Q->Top;
            ChildIndex = ChildIndex + 2;
        }else if(ChildIndex < 62){
            CldBlock = PriorityQueueMMDBlock_GetNext(Q->Top);
            ChildIndex = ChildIndex - ((int)CldBlock->Offset);
        }else{
            CldBlock = PriorityQueueMMDUnit_LastBlock(Q->Top->UnitPtr);
            ChildIndex = ChildIndex - ((int)CldBlock->Offset);
        }
    }else{
        if(Modifier2){
            CldBlock = Q->Bottom->Parent->Other;
        }else{
            CldBlock = Q->Bottom->Other;
        }
        ChildIndex = ChildIndex - ((int)CldBlock->Offset);
    }

    void** AItem2Ptr2;
    PriorityQueueMMAItem* AItem2;
    if((!Modifier2)&&(Q->Count & 1)){
        void** AItem3Ptr[2];
        AItem3Ptr[0] = PriorityQueueMMAItem_GetPtr2Ref(*(PriorityQueueMMDBlock_GetItemPtr(CldBlock,ChildIndex)));
        AItem3Ptr[1] = PriorityQueueMMAItem_GetPtr2Ref(*(PriorityQueueMMDBlock_GetItemPtr(CldBlock,ChildIndex + 1)));
        int CompRes = (PriorityQueueMMAD_Compare(Q,*(AItem3Ptr[0]),*(AItem3Ptr[1]),Errval) != Modifier);
        #ifdef PRIORITYQUEUEMM_DISP_INFO
        printf("[INFO] Special Case: %i\n",CompRes);
        #endif // PRIORITYQUEUEMM_DISP_INFO
        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return NULL;
        }
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP
        ChildIndex = ChildIndex + CompRes;
        Item2Ptr = PriorityQueueMMDBlock_GetItemPtr(CldBlock,ChildIndex);
        AItem2 = (PriorityQueueMMAItem*)(*Item2Ptr);
        AItem2Ptr2 = AItem3Ptr[CompRes];
    }else{
        Item2Ptr = PriorityQueueMMDBlock_GetItemPtr(CldBlock,ChildIndex);
        AItem2 = (PriorityQueueMMAItem*)(*Item2Ptr);
        AItem2Ptr2 = PriorityQueueMMAItem_GetPtr2Ref(AItem2);
    }

    #ifdef PRIORITYQUEUEMM_DISP_INFO
    #ifndef PRIORITYQUEUEMM_REM_SDU_INFO
    printf("[INFO] ItemPtr of Block %p and Index %i:%p\n",CldBlock,ChildIndex,Item2Ptr);
    #endif // PRIORITYQUEUEMM_REM_SDU_INFO
    #endif // PRIORITYQUEUEMM_DISP_INFO

    #define PriorityQueueMMAD_Insert_Comp   (PriorityQueueMMAD_Compare(Q,*AItem2Ptr2,*AItem1Ptr2,Errval) == Modifier)

    #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
    int CompRes = PriorityQueueMMAD_Insert_Comp;
    if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
        PRINT_ERROR3;
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        *Item1Ptr = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Count--;
        PriorityQueueMMAD_RemoveUnitItem(Q,AItem1,Errval);
        return NULL;
    }
    #undef PriorityQueueMMAD_Insert_Comp
    #define PriorityQueueMMAD_Insert_Comp   (CompRes)
    #endif // PRIORITYQUEUEMM_FAILABLE_COMP

    if(PriorityQueueMMAD_Insert_Comp){
        *Item1Ptr = (void*)AItem2;
        *Item2Ptr = (void*)AItem1;
        PriorityQueueMMAItem_SetPtr1(AItem1,PriorityQueueMMDBlock_GetIndexPtr(CldBlock,ChildIndex));
        PriorityQueueMMAItem_SetPtr1(AItem2,PriorityQueueMMDBlock_GetIndexPtr(Q->Bottom,Index));
        #ifdef PRIORITYQUEUEMM_DISP_INFO
        printf("[INFO] Call \"PriorityQueueMMAD_SiftUp\" with:\n");
        #ifndef PRIORITYQUEUEMM_REM_SDU_INFO
        printf("       Block%i:%p (Items:%p) Index:%i => %p\n",(((int)(CldBlock->Offset + 2)) >> 5),CldBlock,CldBlock->BackPtr,ChildIndex,PriorityQueueMMDBlock_GetIndexPtr(CldBlock,ChildIndex));
        #endif // PRIORITYQUEUEMM_REM_SDU_INFO
        PriorityQueueMMAItem_Print2A(AItem1);
        #ifdef PRIORITYQUEUEMM_REM_SDU_INFO
        printf("       TotalIndex:%i\n",((((int)(CldBlock->Offset + 2)) + ChildIndex) - 2));
        #endif // PRIORITYQUEUEMM_REM_SDU_INFO
        #endif // PRIORITYQUEUEMM_DISP_INFO
        if(!PriorityQueueMMAD_SiftUp(Q,PriorityQueueMMDBlock_GetIndexPtr(CldBlock,ChildIndex),-Modifier,Errval)){return NULL;}
    }else{
        #ifdef PRIORITYQUEUEMM_DISP_INFO
        printf("[INFO] Call \"PriorityQueueMMAD_SiftUp\" with:\n");
        #ifndef PRIORITYQUEUEMM_REM_SDU_INFO
        printf("       Block%i:%p (Items:%p) Index:%i => %p\n",(((int)(Q->Bottom->Offset + 2)) >> 5),Q->Bottom,Q->Bottom->BackPtr,Index,PriorityQueueMMDBlock_GetIndexPtr(Q->Bottom,Index));
        #endif // PRIORITYQUEUEMM_REM_SDU_INFO
        PriorityQueueMMAItem_Print2A(AItem1);
        #ifdef PRIORITYQUEUEMM_REM_SDU_INFO
        printf("       TotalIndex:%i\n",((((int)(Q->Bottom->Offset + 2)) + Index) - 2));
        #endif // PRIORITYQUEUEMM_REM_SDU_INFO
        #endif // PRIORITYQUEUEMM_DISP_INFO
        if(!PriorityQueueMMAD_SiftUp(Q,PriorityQueueMMDBlock_GetIndexPtr(Q->Bottom,Index),Modifier,Errval)){return NULL;}
    }
    #undef PriorityQueueMMAD_Insert_Comp
    return AItem1;
}

void* PriorityQueueMMAD_GetItemOfItem(PriorityQueueMMAD* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    if(Item == NULL){
        PRINT_ERROR("PriorityQueueMMAItem \"Item\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return NULL;
    }
    #ifdef PRIORITYQUEUEMMAD_CHECK_REF
    if(PriorityQueueMMAD_LookUpUnitItem(Q,Item,Errval) == NULL){
        PRINT_ERROR("PriorityQueueMMAItem \"Item\" not member of the PriorityQueue!\0");
        if(Errval != NULL){*Errval = ERRVAL_NOT_MEMBER;}
        return NULL;
    }
    #else // PRIORITYQUEUEMMAD_CHECK_REF
    if(((uintptr_t)PriorityQueueMMADUnit_GetOwner(PriorityQueueMMADUnit_Get(Item))) != ((uintptr_t)Q)){
        PRINT_ERROR("PriorityQueueMMAItem \"Item\" not member of the PriorityQueue!\0");
        if(Errval != NULL){*Errval = ERRVAL_NOT_MEMBER;}
        return NULL;
    }
    #endif // PRIORITYQUEUEMMAD_CHECK_REF
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    return PriorityQueueMMAItem_GetPtr2(Item);
}

int PriorityQueueMMAD_SetItemOfItem(PriorityQueueMMAD* Q,PriorityQueueMMAItem* Item,void* ItemValue,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(Item == NULL){
        PRINT_ERROR("PriorityQueueMMAItem \"Item\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #ifdef PRIORITYQUEUEMMAD_CHECK_REF
    if(PriorityQueueMMAD_LookUpUnitItem(Q,Item,Errval) == NULL){
        PRINT_ERROR("PriorityQueueMMAItem \"Item\" not member of the PriorityQueue!\0");
        if(Errval != NULL){*Errval = ERRVAL_NOT_MEMBER;}
        return 0;
    }
    #else // PRIORITYQUEUEMMAD_CHECK_REF
    if(((uintptr_t)PriorityQueueMMADUnit_GetOwner(PriorityQueueMMADUnit_Get(Item))) != ((uintptr_t)Q)){
        PRINT_ERROR("PriorityQueueMMAItem \"Item\" not member of the PriorityQueue!\0");
        if(Errval != NULL){*Errval = ERRVAL_NOT_MEMBER;}
        return 0;
    }
    #endif // PRIORITYQUEUEMMAD_CHECK_REF
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1

    if(PriorityQueueMMAItem_GetPtr2(Item) == ItemValue){return PriorityQueueMMAD_UpdateItem(Q,Item,Errval);}
    void* IndexPtr = PriorityQueueMMAItem_GetPtr1(Item);
    PriorityQueueMMDBlock* B = PriorityQueueMMDBlock_Get(IndexPtr);
    int Index = PriorityQueueMMDBlock_GetIndexValue(B,IndexPtr);
    int TotalIndex = ((PriorityQueueMMDBlock_IsFirst(B))?(Index - 2):(Index + B->Offset));
    int Modifier = 1;
    int i;
    int j;
    if(TotalIndex > 1){
        j = 4;
        uintptr_t LayerStart = (uintptr_t)(TotalIndex + 2);
        LayerStart |= LayerStart >> 1;
        LayerStart |= LayerStart >> 2;
        LayerStart |= LayerStart >> 4;
        for(i = 1;i < sizeof(void*);i++){
            j = j << 1;
            LayerStart |= LayerStart >> j;
        }
        LayerStart = (LayerStart - 3) >> 1;

        Modifier = ((TotalIndex - LayerStart) < (LayerStart >> 1) + 1); //TRUE if item is a Upper-Tree item
        Modifier = Modifier - !Modifier;                                //-1: Lower-Tree-Item, +1: Upper-Tree-Item

        //Upper-Tree => Sift up smaller item : Comp(New,Old) ==  1 == Modifier
        //Lower-Tree => Sift up greater item : Comp(New,Old) == -1 == Modifier

        #define PriorityQueueMMAD_SetItemOfItem_Comp    (PriorityQueueMMAD_Compare(Q,ItemValue,PriorityQueueMMAItem_GetPtr2(Item),Errval) == Modifier)
        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        int CompRes = PriorityQueueMMAD_SetItemOfItem_Comp;
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return 0;
        }
        #undef PriorityQueueMMAD_SetItemOfItem_Comp
        #define PriorityQueueMMAD_SetItemOfItem_Comp    (CompRes)
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP

        if(PriorityQueueMMAD_SetItemOfItem_Comp){
            PriorityQueueMMAItem_SetPtr2(Item,ItemValue);
            return PriorityQueueMMAD_SiftUp(Q,PriorityQueueMMAItem_GetPtr1(Item),Modifier,Errval);
        }
        #undef PriorityQueueMMAD_SetItemOfItem_Comp
    }
    if(TotalIndex == 1){Modifier =-1;}
    PriorityQueueMMAItem_SetPtr2(Item,ItemValue);
    return PriorityQueueMMAD_SiftDown(Q,PriorityQueueMMAItem_GetPtr1(Item),Modifier,Errval);
}

int PriorityQueueMMAD_ContainsItem(PriorityQueueMMAD* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Item == NULL){return 0;}
    return (PriorityQueueMMAD_LookUpUnitItem(Q,Item,Errval) != NULL);
}

int PriorityQueueMMAD_UpdateItem(PriorityQueueMMAD* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(Item == NULL){
        PRINT_ERROR("PriorityQueueMMAItem \"Item\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #ifdef PRIORITYQUEUEMMAD_CHECK_REF
    if(PriorityQueueMMAD_LookUpUnitItem(Q,Item,Errval) == NULL){
        PRINT_ERROR("PriorityQueueMMAItem \"Item\" not member of the PriorityQueue!\0");
        if(Errval != NULL){*Errval = ERRVAL_NOT_MEMBER;}
        return 0;
    }
    #else // PRIORITYQUEUEMMAD_CHECK_REF
    if(((uintptr_t)PriorityQueueMMADUnit_GetOwner(PriorityQueueMMADUnit_Get(Item))) != ((uintptr_t)Q)){
        PRINT_ERROR("PriorityQueueMMAItem \"Item\" not member of the PriorityQueue!\0");
        if(Errval != NULL){*Errval = ERRVAL_NOT_MEMBER;}
        return 0;
    }
    #endif // PRIORITYQUEUEMMAD_CHECK_REF
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1

    void* IndexPtr = PriorityQueueMMAItem_GetPtr1(Item);
    PriorityQueueMMDBlock* CurBlock = PriorityQueueMMDBlock_Get(IndexPtr);
    int Index = PriorityQueueMMDBlock_GetIndexValue(CurBlock,IndexPtr);
    int TotalIndex = ((PriorityQueueMMDBlock_IsFirst(CurBlock))?(Index - 2):(Index + CurBlock->Offset));
    int Modifier = 1;
    int i;
    int j;
    if(TotalIndex > 1){
        j = 4;
        uintptr_t LayerStart = (uintptr_t)(TotalIndex + 2);
        LayerStart |= LayerStart >> 1;
        LayerStart |= LayerStart >> 2;
        LayerStart |= LayerStart >> 4;
        for(i = 1;i < sizeof(void*);i++){
            j = j << 1;
            LayerStart |= LayerStart >> j;
        }
        LayerStart = (LayerStart - 3) >> 1;

        Modifier = ((TotalIndex - LayerStart) < (LayerStart >> 1) + 1); //TRUE if item is a Upper-Tree item
        Modifier = Modifier - !Modifier;                                //-1: Lower-Tree-Item, +1: Upper-Tree-Item

        PriorityQueueMMDBlock* PrtBlock = ((TotalIndex < 30)?(CurBlock):(CurBlock->Parent));
        int ParentIndex = (TotalIndex >> 1) - 1;
        ParentIndex = ((ParentIndex < 30)?(ParentIndex + 2):(ParentIndex - PrtBlock->Offset));
        PriorityQueueMMAItem* Item2 = (PriorityQueueMMAItem*)(*(PriorityQueueMMDBlock_GetItemPtr(PrtBlock,ParentIndex)));


        //Upper-Tree => Sift up smaller item : Comp(New,Old) ==  1 == Modifier
        //Lower-Tree => Sift up greater item : Comp(New,Old) == -1 == Modifier

        #define PriorityQueueMMAD_UpdateItem_Comp    (PriorityQueueMMAD_Compare(Q,PriorityQueueMMAItem_GetPtr2(Item),PriorityQueueMMAItem_GetPtr2(Item2),Errval) == Modifier)
        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        int CompRes = PriorityQueueMMAD_UpdateItem_Comp;
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return 0;
        }
        #undef PriorityQueueMMAD_UpdateItem_Comp
        #define PriorityQueueMMAD_UpdateItem_Comp    (CompRes)
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP

        if(PriorityQueueMMAD_UpdateItem_Comp){
            return PriorityQueueMMAD_SiftUp(Q,PriorityQueueMMAItem_GetPtr1(Item),Modifier,Errval);
        }
        #undef PriorityQueueMMAD_UpdateItem_Comp
    }
    if(TotalIndex == 1){Modifier =-1;}
    return PriorityQueueMMAD_SiftDown(Q,PriorityQueueMMAItem_GetPtr1(Item),Modifier,Errval);
}

int PriorityQueueMMAD_RemoveMin(PriorityQueueMMAD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q->Count == 1){
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        void** Item2Ptr = &(((void**)Q->Top->BackPtr)[2]);
        PriorityQueueMMAItem* AItem2 = (PriorityQueueMMAItem*)(*Item2Ptr);
        PriorityQueueMMAD_RemoveUnitItem(Q,AItem2,Errval);
        *Item2Ptr = NULL;
        #else // PRIORITYQUEUEMM_INIT_WITH_NULL
        PriorityQueueMMAItem* AItem2 = (PriorityQueueMMAItem*)(((void**)Q->Top->BackPtr)[2]);
        PriorityQueueMMAD_RemoveUnitItem(Q,AItem2,Errval);
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Count = 0;
        return 1;
    }
    if(Q->Bottom->Offset == Q->Count){Q->Bottom = PriorityQueueMMDBlock_GetPrev(Q->Bottom);}
    Q->Count--;
    int BottomIndex = Q->Count - (((int)(Q->Bottom->Offset + ((intptr_t)2))) - 2);
    void** Item1Ptr = PriorityQueueMMDBlock_GetItemPtr(Q->Bottom,BottomIndex);
    void** Item2Ptr = &(((void**)Q->Top->BackPtr)[2]);
    PriorityQueueMMAItem* AItem1 = (PriorityQueueMMAItem*)(*Item1Ptr);
    PriorityQueueMMAItem* AItem2 = (PriorityQueueMMAItem*)(*Item2Ptr);
    PriorityQueueMMAItem_SetPtr1(AItem1,PriorityQueueMMAItem_GetPtr1(AItem2));
    *Item2Ptr = *Item1Ptr;
    #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
    *Item1Ptr = NULL;
    #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
    PriorityQueueMMAD_RemoveUnitItem(Q,AItem2,Errval);
    if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
    if(Q->Count == 1){return 1;}
    if(Q->Count == Q->Bottom->Offset){Q->Bottom = PriorityQueueMMDBlock_GetPrev(Q->Bottom);}
    if((Q->UnitCount * 96 - 3 - Q->Count > 144)&&(PriorityQueueMMDUnit_Dispose(PriorityQueueMMDUnit_Next(Q->Bottom->UnitPtr),Errval))){Q->UnitCount = Q->UnitCount - 1;}
    int res = PriorityQueueMMAD_SiftDown(Q,((void*)Item2Ptr),1,Errval);

    if((res == 0)||(Q->Count < 5)){return res;}
    if((Q->Count & 1)&&(((Q->Count - 1) - Q->LstLayerStart) >= (Q->LstLayerStart >> 1) + 1)){
        BottomIndex = (Q->Count - 1) - (((int)(Q->Bottom->Offset + ((intptr_t)2))) - 2);
        return PriorityQueueMMAD_SiftDown(Q,PriorityQueueMMDBlock_GetIndexPtr(Q->Bottom,BottomIndex),-1,Errval);
    }
    return res;
}

int PriorityQueueMMAD_RemoveMax(PriorityQueueMMAD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    int res = 0;
    if(Q->Count > 2){
        if(Q->Bottom->Offset == Q->Count){Q->Bottom = PriorityQueueMMDBlock_GetPrev(Q->Bottom);}
        Q->Count--;
        int BottomIndex = Q->Count - (((int)(Q->Bottom->Offset + ((intptr_t)2))) - 2);
        void** Item1Ptr = PriorityQueueMMDBlock_GetItemPtr(Q->Bottom,BottomIndex);
        void** Item2Ptr = &(((void**)Q->Top->BackPtr)[3]);
        PriorityQueueMMAItem* AItem1 = (PriorityQueueMMAItem*)(*Item1Ptr);
        PriorityQueueMMAItem* AItem2 = (PriorityQueueMMAItem*)(*Item2Ptr);
        PriorityQueueMMAItem_SetPtr1(AItem1,PriorityQueueMMAItem_GetPtr1(AItem2));
        *Item2Ptr = *Item1Ptr;
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        *Item1Ptr = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        PriorityQueueMMAD_RemoveUnitItem(Q,AItem2,Errval);
        if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
        if(Q->Count == Q->Bottom->Offset){Q->Bottom = PriorityQueueMMDBlock_GetPrev(Q->Bottom);}
        if((Q->UnitCount * 96 - 3 - Q->Count > 144)&&(PriorityQueueMMDUnit_Dispose(PriorityQueueMMDUnit_Next(Q->Bottom->UnitPtr),Errval))){Q->UnitCount = Q->UnitCount - 1;}
        res = PriorityQueueMMAD_SiftDown(Q,((void*)Item2Ptr),-1,Errval);
        goto END;
    }

    Q->LstLayerStart = 0;

    if(Q->Count == 1){
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        void** Item2Ptr = &(((void**)Q->Top->BackPtr)[2]);
        PriorityQueueMMAItem* AItem2 = (PriorityQueueMMAItem*)(*Item2Ptr);
        PriorityQueueMMAD_RemoveUnitItem(Q,AItem2,Errval);
        *Item2Ptr = NULL;
        #else // PRIORITYQUEUEMM_INIT_WITH_NULL
        PriorityQueueMMAItem* AItem2 = (PriorityQueueMMAItem*)(((void**)Q->Top->BackPtr)[2]);
        PriorityQueueMMAD_RemoveUnitItem(Q,AItem2,Errval);
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Count = 0;
        return 1;
    }
    #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
    void** Item2Ptr =  &(((void**)Q->Top->BackPtr)[3]);
    PriorityQueueMMAItem* AItem2 = (PriorityQueueMMAItem*)(*Item2Ptr);
    PriorityQueueMMAD_RemoveUnitItem(Q,AItem2,Errval);
    *Item2Ptr = NULL;
    #else // PRIORITYQUEUEMM_INIT_WITH_NULL
    PriorityQueueMMAItem* AItem2 = (PriorityQueueMMAItem*)(((void**)Q->Top->BackPtr)[3]);
    PriorityQueueMMAD_RemoveUnitItem(Q,AItem2,Errval);
    #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
    Q->Count = 1;
    return 1;

    END:
    if((res == 0)||(Q->Count < 5)){return res;}
    if((Q->Count & 1)&&(((Q->Count - 1) - Q->LstLayerStart) >= (Q->LstLayerStart >> 1) + 1)){
        int BottomIndex = (Q->Count - 1) - (((int)(Q->Bottom->Offset + ((intptr_t)2))) - 2);
        return PriorityQueueMMAD_SiftDown(Q,PriorityQueueMMDBlock_GetIndexPtr(Q->Bottom,BottomIndex),-1,Errval);
    }
    return res;
}

int PriorityQueueMMAD_RemoveItem(PriorityQueueMMAD* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(Item == NULL){
        PRINT_ERROR("PriorityQueueMMAItem \"Item\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #ifdef PRIORITYQUEUEMMAD_CHECK_REF
    if(PriorityQueueMMAD_LookUpUnitItem(Q,Item,Errval) == NULL){
        PRINT_ERROR("PriorityQueueMMAItem \"Item\" not member of the PriorityQueue!\0");
        if(Errval != NULL){*Errval = ERRVAL_NOT_MEMBER;}
        return 0;
    }
    #else // PRIORITYQUEUEMMAD_CHECK_REF
    if(((uintptr_t)PriorityQueueMMADUnit_GetOwner(PriorityQueueMMADUnit_Get(Item))) != ((uintptr_t)Q)){
        PRINT_ERROR("PriorityQueueMMAItem \"Item\" not member of the PriorityQueue!\0");
        if(Errval != NULL){*Errval = ERRVAL_NOT_MEMBER;}
        return 0;
    }
    #endif // PRIORITYQUEUEMMAD_CHECK_REF
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1

    int res = 0;
    void* IndexPtr = PriorityQueueMMAItem_GetPtr1(Item);

    PriorityQueueMMDBlock* CurBlock = PriorityQueueMMDBlock_Get(IndexPtr);
    int Index = PriorityQueueMMDBlock_GetIndexValue(CurBlock,IndexPtr);
    int TotalIndex = ((PriorityQueueMMDBlock_IsFirst(CurBlock))?(Index - 2):(Index + CurBlock->Offset));
    int Modifier = 1;
    int i;
    int j;
    if(TotalIndex > 1){
        if(Q->Bottom->Offset == Q->Count){Q->Bottom = PriorityQueueMMDBlock_GetPrev(Q->Bottom);}
        Q->Count--;
        int BottomIndex = Q->Count - (((int)(Q->Bottom->Offset + ((intptr_t)2))) - 2);
        void** Item2Ptr = PriorityQueueMMDBlock_GetItemPtr(Q->Bottom,BottomIndex);
        PriorityQueueMMAItem* Item2 = (PriorityQueueMMAItem*)(*Item2Ptr);
        if(Item2 == Item){
            #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
            *Item2Ptr = NULL;
            #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
            PriorityQueueMMAD_RemoveUnitItem(Q,Item2,Errval);
            if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
            res = 1;
            goto END;
        }

        j = 4;
        uintptr_t LayerStart = (uintptr_t)(TotalIndex + 2);
        LayerStart |= LayerStart >> 1;
        LayerStart |= LayerStart >> 2;
        LayerStart |= LayerStart >> 4;
        for(i = 1;i < sizeof(void*);i++){
            j = j << 1;
            LayerStart |= LayerStart >> j;
        }
        LayerStart = (LayerStart - 3) >> 1;

        Modifier = ((TotalIndex - LayerStart) < (LayerStart >> 1) + 1); //TRUE if item is a Upper-Tree item
        Modifier = Modifier - !Modifier;                                //-1: Lower-Tree-Item, +1: Upper-Tree-Item

        //Upper-Tree => Sift up smaller item : Comp(New,Old) ==  1 == Modifier
        //Lower-Tree => Sift up greater item : Comp(New,Old) == -1 == Modifier

        int CompRes = (PriorityQueueMMAD_Compare(Q,PriorityQueueMMAItem_GetPtr2(Item2),PriorityQueueMMAItem_GetPtr2(Item),Errval) == Modifier);
        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return 0;
        }
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP

        void** Item1Ptr = PriorityQueueMMDBlock_GetItemPtr(CurBlock,Index);
        PriorityQueueMMAItem_SetPtr1(Item2,PriorityQueueMMAItem_GetPtr1(Item));
        *Item1Ptr = *Item2Ptr;
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        *Item2Ptr = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        PriorityQueueMMAD_RemoveUnitItem(Q,Item,Errval);

        if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
        if(Q->Count == 1){return 1;}
        if(Q->Count == Q->Bottom->Offset){Q->Bottom = PriorityQueueMMDBlock_GetPrev(Q->Bottom);}
        if((Q->UnitCount * 96 - 3 - Q->Count > 144)&&(PriorityQueueMMDUnit_Dispose(PriorityQueueMMDUnit_Next(Q->Bottom->UnitPtr),Errval))){Q->UnitCount = Q->UnitCount - 1;}
        if(CompRes){res = PriorityQueueMMAD_SiftUp(Q,PriorityQueueMMAItem_GetPtr1(Item2),Modifier,Errval);goto END;}
        res = PriorityQueueMMAD_SiftDown(Q,PriorityQueueMMAItem_GetPtr1(Item2),Modifier,Errval);
        goto END;
    }
    if(TotalIndex == 1){return PriorityQueueMMAD_RemoveMax(Q,Errval);}
    return PriorityQueueMMAD_RemoveMin(Q,Errval);

    END:
    if((res == 0)||(Q->Count < 5)){return res;}
    if((Q->Count & 1)&&(((Q->Count - 1) - Q->LstLayerStart) >= (Q->LstLayerStart >> 1) + 1)){
        int BottomIndex = (Q->Count - 1) - (((int)(Q->Bottom->Offset + ((intptr_t)2))) - 2);
        return PriorityQueueMMAD_SiftDown(Q,PriorityQueueMMDBlock_GetIndexPtr(Q->Bottom,BottomIndex),-1,Errval);
    }
    return res;
}

int PriorityQueueMMAD_RemoveMinSource(PriorityQueueMMAD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1

    void** Item2Ptr = &(((void**)Q->Top->BackPtr)[2]);
    PriorityQueueMMAItem* AItem2 = (PriorityQueueMMAItem*)(*Item2Ptr);
    if(!PriorityQueueMMAD_DisposeItem(Q,PriorityQueueMMAItem_GetPtr2(AItem2),Errval)){
        PRINT_ERROR3;
        return 0;
    }
    if(Q->Count == 1){
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        *Item2Ptr = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        PriorityQueueMMAD_RemoveUnitItem(Q,AItem2,Errval);
        Q->Count = 0;
        return 1;
    }
    if(Q->Bottom->Offset == Q->Count){Q->Bottom = PriorityQueueMMDBlock_GetPrev(Q->Bottom);}
    Q->Count--;
    int BottomIndex = Q->Count - (((int)(Q->Bottom->Offset + ((intptr_t)2))) - 2);
    void** Item1Ptr = PriorityQueueMMDBlock_GetItemPtr(Q->Bottom,BottomIndex);
    PriorityQueueMMAItem* AItem1 = (PriorityQueueMMAItem*)(*Item1Ptr);
    PriorityQueueMMAItem_SetPtr1(AItem1,PriorityQueueMMAItem_GetPtr1(AItem2));
    *Item2Ptr = *Item1Ptr;
    #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
    *Item1Ptr = NULL;
    #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
    PriorityQueueMMAD_RemoveUnitItem(Q,AItem2,Errval);
    if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
    if(Q->Count == 1){return 1;}
    if(Q->Count == Q->Bottom->Offset){Q->Bottom = PriorityQueueMMDBlock_GetPrev(Q->Bottom);}
    if((Q->UnitCount * 96 - 3 - Q->Count > 144)&&(PriorityQueueMMDUnit_Dispose(PriorityQueueMMDUnit_Next(Q->Bottom->UnitPtr),Errval))){Q->UnitCount = Q->UnitCount - 1;}
    int res = PriorityQueueMMAD_SiftDown(Q,((void*)Item2Ptr),1,Errval);

    if((res == 0)||(Q->Count < 5)){return res;}
    if((Q->Count & 1)&&(((Q->Count - 1) - Q->LstLayerStart) >= (Q->LstLayerStart >> 1) + 1)){
        BottomIndex = (Q->Count - 1) - (((int)(Q->Bottom->Offset + ((intptr_t)2))) - 2);
        return PriorityQueueMMAD_SiftDown(Q,PriorityQueueMMDBlock_GetIndexPtr(Q->Bottom,BottomIndex),-1,Errval);
    }
    return res;
}

int PriorityQueueMMAD_RemoveMaxSource(PriorityQueueMMAD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(Q->Count <= 0){
        PRINT_ERROR("PriorityQueue is empty!\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_EMPTY;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    int res = 0;
    if(Q->Count > 2){
        void** Item2Ptr = &(((void**)Q->Top->BackPtr)[3]);
        PriorityQueueMMAItem* AItem2 = (PriorityQueueMMAItem*)(*Item2Ptr);
        if(!PriorityQueueMMAD_DisposeItem(Q,PriorityQueueMMAItem_GetPtr2(AItem2),Errval)){
            PRINT_ERROR3;
            return 0;
        }
        if(Q->Bottom->Offset == Q->Count){Q->Bottom = PriorityQueueMMDBlock_GetPrev(Q->Bottom);}
        Q->Count--;
        int BottomIndex = Q->Count - (((int)(Q->Bottom->Offset + ((intptr_t)2))) - 2);
        void** Item1Ptr = PriorityQueueMMDBlock_GetItemPtr(Q->Bottom,BottomIndex);
        PriorityQueueMMAItem* AItem1 = (PriorityQueueMMAItem*)(*Item1Ptr);
        PriorityQueueMMAItem_SetPtr1(AItem1,PriorityQueueMMAItem_GetPtr1(AItem2));
        *Item2Ptr = *Item1Ptr;
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        *Item1Ptr = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        PriorityQueueMMAD_RemoveUnitItem(Q,AItem2,Errval);
        if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
        if(Q->Count == Q->Bottom->Offset){Q->Bottom = PriorityQueueMMDBlock_GetPrev(Q->Bottom);}
        if((Q->UnitCount * 96 - 3 - Q->Count > 144)&&(PriorityQueueMMDUnit_Dispose(PriorityQueueMMDUnit_Next(Q->Bottom->UnitPtr),Errval))){Q->UnitCount = Q->UnitCount - 1;}
        res = PriorityQueueMMAD_SiftDown(Q,((void*)Item2Ptr),-1,Errval);
        goto END;
    }

    Q->LstLayerStart = 0;

    if(Q->Count == 1){
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        void** Item2Ptr = &(((void**)Q->Top->BackPtr)[2]);
        PriorityQueueMMAItem* AItem2 = (PriorityQueueMMAItem*)(*Item2Ptr);
        if(!PriorityQueueMMAD_DisposeItem(Q,PriorityQueueMMAItem_GetPtr2(AItem2),Errval)){
            PRINT_ERROR3;
            return 0;
        }
        PriorityQueueMMAD_RemoveUnitItem(Q,AItem2,Errval);
        *Item2Ptr = NULL;
        #else // PRIORITYQUEUEMM_INIT_WITH_NULL
        PriorityQueueMMAItem* AItem2 = (PriorityQueueMMAItem*)(((void**)Q->Top->BackPtr)[2]);
        PriorityQueueMMAD_RemoveUnitItem(Q,AItem2,Errval);
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Count = 0;
        return 1;
    }
    #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
    void** Item2Ptr =  &(((void**)Q->Top->BackPtr)[3]);
    PriorityQueueMMAItem* AItem2 = (PriorityQueueMMAItem*)(*Item2Ptr);
    if(!PriorityQueueMMAD_DisposeItem(Q,PriorityQueueMMAItem_GetPtr2(AItem2),Errval)){
        PRINT_ERROR3;
        return 0;
    }
    PriorityQueueMMAD_RemoveUnitItem(Q,AItem2,Errval);
    *Item2Ptr = NULL;
    #else // PRIORITYQUEUEMM_INIT_WITH_NULL
    PriorityQueueMMAItem* AItem2 = (PriorityQueueMMAItem*)(((void**)Q->Top->BackPtr)[3]);
    PriorityQueueMMAD_RemoveUnitItem(Q,AItem2,Errval);
    #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
    Q->Count = 1;
    return 1;

    END:
    if((res == 0)||(Q->Count < 5)){return res;}
    if((Q->Count & 1)&&(((Q->Count - 1) - Q->LstLayerStart) >= (Q->LstLayerStart >> 1) + 1)){
        int BottomIndex = (Q->Count - 1) - (((int)(Q->Bottom->Offset + ((intptr_t)2))) - 2);
        return PriorityQueueMMAD_SiftDown(Q,PriorityQueueMMDBlock_GetIndexPtr(Q->Bottom,BottomIndex),-1,Errval);
    }
    return res;
}

int PriorityQueueMMAD_RemoveItemSource(PriorityQueueMMAD* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    if(Item == NULL){
        PRINT_ERROR("PriorityQueueMMAItem \"Item\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #ifdef PRIORITYQUEUEMMAD_CHECK_REF
    if(PriorityQueueMMAD_LookUpUnitItem(Q,Item,Errval) == NULL){
        PRINT_ERROR("PriorityQueueMMAItem \"Item\" not member of the PriorityQueue!\0");
        if(Errval != NULL){*Errval = ERRVAL_NOT_MEMBER;}
        return 0;
    }
    #else // PRIORITYQUEUEMMAD_CHECK_REF
    if(((uintptr_t)PriorityQueueMMADUnit_GetOwner(PriorityQueueMMADUnit_Get(Item))) != ((uintptr_t)Q)){
        PRINT_ERROR("PriorityQueueMMAItem \"Item\" not member of the PriorityQueue!\0");
        if(Errval != NULL){*Errval = ERRVAL_NOT_MEMBER;}
        return 0;
    }
    #endif // PRIORITYQUEUEMMAD_CHECK_REF
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1

    //PriorityQueueMMAItem_GetPtr1(AItem)
    //PriorityQueueMMAItem_GetPtr2(AItem)
    //PriorityQueueMMAItem_SetPtr1(AItem,Value)
    //PriorityQueueMMAItem_SetPtr2(AItem,Value)

    //PriorityQueueMMDUnit_Prev(Unit)                         ((Unit)->Prev->UnitPtr)
    //PriorityQueueMMDUnit_Next(Unit)                         ((Unit)->Next->UnitPtr)
    //PriorityQueueMMDUnit_FirstBlock(Unit)                   ((Unit)->Prev->UnitPtr->Next)
    //PriorityQueueMMDUnit_LastBlock(Unit)                    ((Unit)->Next->UnitPtr->Prev)

    //PriorityQueueMMDBlock_Get(Ptr)                          (*((PriorityQueueMMDBlock**)(((uintptr_t)(Ptr)) & PriorityQueueMMDBlock_SizeMask)))
    //PriorityQueueMMDBlock_IsFirst(BlockPtr)                 (!((int)((BlockPtr)->Offset + 2)))
    //PriorityQueueMMDBlock_GetItemPtr(BlockPtr,Index)        ((Index)?(&(((void**)((BlockPtr)->BackPtr))[(Index)])):(&((BlockPtr)->FrstItem)))
    //PriorityQueueMMDBlock_GetItem(BlockPtr,Index)           ((Index)?(((void**)((BlockPtr)->BackPtr))[(Index)]):((BlockPtr)->FrstItem))
    //PriorityQueueMMDBlock_SetItem(BlockPtr,Index,Value)     ({void** _Item = PriorityQueueMMDBlock_GetItemPtr((BlockPtr),(Index));*_Item = (void*)(Value);})
    //PriorityQueueMMDBlock_GetIndexPtr(BlockPtr,Index)       ((void*)(&(((void**)(BlockPtr)->BackPtr)[(Index)])))
    //PriorityQueueMMDBlock_GetIndexValue(BlockPtr,IndexPtr)  ((int)((((uintptr_t)(IndexPtr)) - ((uintptr_t)((BlockPtr)->BackPtr))) >> PriorityQueueMMD_Shift))

    //PriorityQueueMMDBlock_GetPrev(BlockPtr)                 (((BlockPtr) != PriorityQueueMMDUnit_FirstBlock(((BlockPtr)->UnitPtr)))?(*((PriorityQueueMMDBlock**)(((BlockPtr)->BackPtr) - PriorityQueueMMDBlock_Size))):((BlockPtr)->UnitPtr->Prev))
    //PriorityQueueMMDBlock_GetNext(BlockPtr)                 (((BlockPtr) != PriorityQueueMMDUnit_LastBlock(((BlockPtr)->UnitPtr)))?(*((PriorityQueueMMDBlock**)(((BlockPtr)->BackPtr) + PriorityQueueMMDBlock_Size))):((BlockPtr)->UnitPtr->Next))
    //PriorityQueueMMDBlock_GetNumber(BlockPtr)               (((int)((BlockPtr)->Offset + 2)) >> 5)
    //PriorityQueueMMDBlock_GetParentIndex(BlockPtr,Index)    ((PriorityQueueMMDBlock_IsFirst((BlockPtr)))?((((int)((Index) + (BlockPtr)->Offset)) >> 1) - 3 - ((BlockPtr)->Parent->Offset + ((intptr_t)2))):((Index) >> 1))

    void* IndexPtr = PriorityQueueMMAItem_GetPtr1(Item);

    int res = 0;
    PriorityQueueMMDBlock* CurBlock = PriorityQueueMMDBlock_Get(IndexPtr);
    int Index = PriorityQueueMMDBlock_GetIndexValue(CurBlock,IndexPtr);
    int TotalIndex = ((PriorityQueueMMDBlock_IsFirst(CurBlock))?(Index - 2):(Index + CurBlock->Offset));
    int Modifier = 1;
    int i;
    int j;
    if(TotalIndex > 1){
        if(Q->Bottom->Offset == Q->Count){Q->Bottom = PriorityQueueMMDBlock_GetPrev(Q->Bottom);}
        Q->Count--;
        int BottomIndex = Q->Count - (((int)(Q->Bottom->Offset + ((intptr_t)2))) - 2);
        void** Item2Ptr = PriorityQueueMMDBlock_GetItemPtr(Q->Bottom,BottomIndex);
        PriorityQueueMMAItem* Item2 = (PriorityQueueMMAItem*)(*Item2Ptr);
        if(Item2 == Item){
            if(!PriorityQueueMMAD_DisposeItem(Q,PriorityQueueMMAItem_GetPtr2(Item),Errval)){
                PRINT_ERROR3;
                return 0;
            }
            #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
            *Item2Ptr = NULL;
            #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
            PriorityQueueMMAD_RemoveUnitItem(Q,Item2,Errval);
            if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
            res = 1;
            goto END;
        }

        j = 4;
        uintptr_t LayerStart = (uintptr_t)(TotalIndex + 2);
        LayerStart |= LayerStart >> 1;
        LayerStart |= LayerStart >> 2;
        LayerStart |= LayerStart >> 4;
        for(i = 1;i < sizeof(void*);i++){
            j = j << 1;
            LayerStart |= LayerStart >> j;
        }
        LayerStart = (LayerStart - 3) >> 1;

        Modifier = ((TotalIndex - LayerStart) < (LayerStart >> 1) + 1); //TRUE if item is a Upper-Tree item
        Modifier = Modifier - !Modifier;                                //-1: Lower-Tree-Item, +1: Upper-Tree-Item

        //Upper-Tree => Sift up smaller item : Comp(New,Old) ==  1 == Modifier
        //Lower-Tree => Sift up greater item : Comp(New,Old) == -1 == Modifier

        int CompRes = (PriorityQueueMMAD_Compare(Q,PriorityQueueMMAItem_GetPtr2(Item2),PriorityQueueMMAItem_GetPtr2(Item),Errval) == Modifier);
        #ifdef PRIORITYQUEUEMM_FAILABLE_COMP
        if((Errval != NULL)&&(*Errval != ERRVAL_NO_ERR)){
            PRINT_ERROR3;
            return 0;
        }
        #endif // PRIORITYQUEUEMM_FAILABLE_COMP
        if(!PriorityQueueMMAD_DisposeItem(Q,PriorityQueueMMAItem_GetPtr2(Item),Errval)){
            PRINT_ERROR3;
            return 0;
        }

        void** Item1Ptr = PriorityQueueMMDBlock_GetItemPtr(CurBlock,Index);
        PriorityQueueMMAItem_SetPtr1(Item2,PriorityQueueMMAItem_GetPtr1(Item));
        *Item1Ptr = *Item2Ptr;
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        *Item2Ptr = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        PriorityQueueMMAD_RemoveUnitItem(Q,Item,Errval);

        if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
        if(Q->Count == 1){return 1;}
        if(Q->Count == Q->Bottom->Offset){Q->Bottom = PriorityQueueMMDBlock_GetPrev(Q->Bottom);}
        if((Q->UnitCount * 96 - 3 - Q->Count > 144)&&(PriorityQueueMMDUnit_Dispose(PriorityQueueMMDUnit_Next(Q->Bottom->UnitPtr),Errval))){Q->UnitCount = Q->UnitCount - 1;}
        if(CompRes){res = PriorityQueueMMAD_SiftUp(Q,PriorityQueueMMAItem_GetPtr1(Item2),Modifier,Errval);goto END;}
        res = PriorityQueueMMAD_SiftDown(Q,PriorityQueueMMAItem_GetPtr1(Item2),Modifier,Errval);
        goto END;
    }
    if(TotalIndex == 1){return PriorityQueueMMAD_RemoveMaxSource(Q,Errval);}
    return PriorityQueueMMAD_RemoveMinSource(Q,Errval);

    END:
    if((res == 0)||(Q->Count < 5)){return res;}
    if((Q->Count & 1)&&(((Q->Count - 1) - Q->LstLayerStart) >= (Q->LstLayerStart >> 1) + 1)){
        int BottomIndex = (Q->Count - 1) - (((int)(Q->Bottom->Offset + ((intptr_t)2))) - 2);
        return PriorityQueueMMAD_SiftDown(Q,PriorityQueueMMDBlock_GetIndexPtr(Q->Bottom,BottomIndex),-1,Errval);
    }
    return res;
}

int PriorityQueueMMAD_Clear(PriorityQueueMMAD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    PriorityQueueMMDUnit* TopUnit = Q->Top->UnitPtr;
    PriorityQueueMMDUnit* LstUnit = PriorityQueueMMDUnit_Prev(TopUnit);
    while(LstUnit != TopUnit){
        PriorityQueueMMDUnit_Dispose(LstUnit,Errval);
        LstUnit = PriorityQueueMMDUnit_Prev(TopUnit);
    }
    while(Q->LstUnit != NULL){PriorityQueueMMAD_DisposeUnit(Q,Q->LstUnit,Errval);}
    Q->Count = 0;
    Q->LstLayerStart = 0;
    Q->Bottom = Q->Top;
    Q->UnitCount = 1;
    #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
    int i;
    PriorityQueueMMDBlock* FirstNewBlock = Q->Top;
    void** Items = (void**)FirstNewBlock->BackPtr;
    for(i = 1;i < 32;i++){
        Items[i] = NULL;
        Items[i + 32] = NULL;
        Items[i + 64] = NULL;
    }
    FirstNewBlock->FrstItem = NULL;
    FirstNewBlock = PriorityQueueMMDBlock_GetNext(FirstNewBlock);
    FirstNewBlock->FrstItem = NULL;
    FirstNewBlock = PriorityQueueMMDBlock_GetNext(FirstNewBlock);
    FirstNewBlock->FrstItem = NULL;
    #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
    return 1;
}

int PriorityQueueMMAD_ClearSource(PriorityQueueMMAD* Q,ERRVAL_T* Errval){
    if(Errval != NULL){*Errval = ERRVAL_NO_ERR;}
    #ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q == NULL){
        PRINT_ERROR("PriorityQueueMMAD \"Q\" not available! (NULL)\0");
        if(Errval != NULL){*Errval = ERRVAL_IS_NULL;}
        return 0;
    }
    #endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL1
    if(Q->Count == 0){return 1;}
    int i;
    void** Items;
    int Index = Q->Count - (((int)(Q->Bottom->Offset + (intptr_t)2)) - 1);
    PriorityQueueMMDUnit* CurUnit = Q->Bottom->UnitPtr;
    PriorityQueueMMAItem* AItem1;
    while(1){
        Items = (void**)Q->Bottom->BackPtr;
        for(i = Index;i > 0;i--){
            AItem1 = (PriorityQueueMMAItem*)(Items[i]);
            if(!PriorityQueueMMAD_DisposeItem(Q,PriorityQueueMMAItem_GetPtr2(AItem1),Errval)){
                PRINT_ERROR3;
                return 0;
            }
            #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
            Items[i] = NULL;
            #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
            Q->Count--;
            if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
            PriorityQueueMMAD_RemoveUnitItem(Q,AItem1,Errval);
        }
        AItem1 = (PriorityQueueMMAItem*)(Q->Bottom->FrstItem);
        if(!PriorityQueueMMAD_DisposeItem(Q,PriorityQueueMMAItem_GetPtr2(AItem1),Errval)){
            PRINT_ERROR3;
            return 0;
        }
        #ifdef PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Bottom->FrstItem = NULL;
        #endif // PRIORITYQUEUEMM_INIT_WITH_NULL
        Q->Count--;
        if(Q->Count <= Q->LstLayerStart){Q->LstLayerStart = (Q->LstLayerStart >> 1) - 1;}
        PriorityQueueMMAD_RemoveUnitItem(Q,AItem1,Errval);
        if(Q->Count == 0){return 1;}
        Q->Bottom = PriorityQueueMMDBlock_GetPrev(Q->Bottom);
        if(Q->Bottom->UnitPtr != CurUnit){
            if(!PriorityQueueMMDUnit_Dispose(CurUnit,Errval)){
                PRINT_ERROR3;
                return 0;
            }
            Q->UnitCount = Q->UnitCount - 1;
            CurUnit = Q->Bottom->UnitPtr;
        }
        Index = 31;
    }
}

int PriorityQueueMMAD_Dispose(PriorityQueueMMAD* Q,ERRVAL_T* Errval){
    if(!PriorityQueueMMAD_Clear(Q,Errval)){
        PRINT_ERROR3;
        return 0;
    }
    if(!PriorityQueueMMDUnit_Dispose(Q->Top->UnitPtr,Errval)){
        PRINT_ERROR3;
        return 0;
    }
    return PriorityQueueMMAD_DisposeSelf(Q,Errval);
}

int PriorityQueueMMAD_DisposeSource(PriorityQueueMMAD* Q,ERRVAL_T* Errval){
    if(!PriorityQueueMMAD_ClearSource(Q,Errval)){
        PRINT_ERROR3;
        return 0;
    }
    if(!PriorityQueueMMDUnit_Dispose(Q->Top->UnitPtr,Errval)){
        PRINT_ERROR3;
        return 0;
    }
    return PriorityQueueMMAD_DisposeSelf(Q,Errval);
}
#endif // INCLUDE_PRIORITYQUEUEMMAD

#ifdef PRIORITYQUEUEMM_REM_DEF_INFO
#define PRIORITYQUEUEMM_DISP_INFO
#undef PRINT_INFO
#undef PRINT_INFO2
#define PRINT_INFO(msg)     _PRINT_INFO((msg))
#define PRINT_INFO2(msg)    _PRINT_INFO2((msg))
#endif // PRIORITYQUEUEMM_REM_DEF_INFO

#ifdef INCLUDE_D_SIZE_PRIORITYQUEUEMM
#undef PriorityQueueMMDUnit_Prev
#undef PriorityQueueMMDUnit_Next
#undef PriorityQueueMMDUnit_FirstBlock
#undef PriorityQueueMMDUnit_LastBlock

#undef PriorityQueueMMDBlock_Get
#undef PriorityQueueMMDBlock_IsFirst
#undef PriorityQueueMMDBlock_GetItemPtr
#undef PriorityQueueMMDBlock_GetItem
#undef PriorityQueueMMDBlock_SetItem
#undef PriorityQueueMMDBlock_GetIndexPtr
#undef PriorityQueueMMDBlock_GetIndexValue

#undef PriorityQueueMMDBlock_GetPrev
#undef PriorityQueueMMDBlock_GetNext
#undef PriorityQueueMMDBlock_GetNumber
#undef PriorityQueueMMDBlock_GetParentIndex
#endif // INCLUDE_D_SIZE_PRIORITYQUEUEMM

#undef PRINT_ERROR
#undef PRINT_ERROR2
#undef PRINT_ERROR3

#undef PRINT_INFO
#undef PRINT_INFO2

#undef PRINT_WARNING

#endif // INCLUDE_PRIORITYQUEUEMM


