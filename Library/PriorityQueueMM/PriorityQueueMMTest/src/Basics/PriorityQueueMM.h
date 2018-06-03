#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//--------------------------------------------------------------------------------------------------------------
//                                            Table of Content                 (Last Edited: 10th of April 2018)
//--------------------------------------------------------------------------------------------------------------

// 1. NOTE (Line 29, Medium Importance):
//    Creators note, reason for creative choices

// 2. Information (Line 61, HIGH IMPORTANCE):
//    General information, purpose of data-structures, intended usage, example

// 3. Details (Line 125, HIGH IMPORTANCE):
//    Information about when to use which data-structure for optimal efficiency

// 4. Configuration (Line 186, CRITICAL IMPORTANCE):
//    Enable/Disable features by removing or adding comments in front of "#define"-Statements

// 5. Code          (Line , low importance)
//    Actual implementation. DO NOT MODIFY!




//--------------------------------------------------------------------------------------------------------------
//                                                 NOTE                        (Last Edited: 10th of April 2018)
//--------------------------------------------------------------------------------------------------------------

//This data-structure was written by Philipp Franke between the 7th and 9th of April 2018 with the intention of
//showing the best of my abilities. I DO NOT CLAIM TO BE THE INVENTOR OF THIS DATA-STRUCTURES (IN THE CONTEXT OF
// BEING THE FIRST TO COME UP AND/OR CODE A DATA-STRUCTURE THAT IS CAPABLE OF DOING WHAT THIS DATA-STRUCTURE CAN).
// I would even be surprised if I was the first one to come up with this. WHAT I DO CLAIM HOWEVER IS, THAT I HAVE
// CREATED THIS DATA-STRUCTURE WITHOUT THE (CONSCIOUS) KNOWLEDGE OF A PRE-EXISTING DATA-STRUCTURE LIKE THIS WRITEN
// BY SOMEONE ELSE. This file does not contain the first version of this data-structure I have written. The first
// version is a dynamic version that is not nearly optimized enough. The data-structures in this file (at least the
// basic version ("PriorityQueueMMSF")) can be seen as a upgraded/extended version of the "Binary Heap"
// (https://en.wikipedia.org/wiki/Binary_heap).

//The goals for these data-structures were the following:
// - Maximizing Optimization
// - Minimizing Memory-Overhead
// - Maximizing versatility in usage

//For these goals, I have decided to make this file highly configurable to do both:
// - Giving the user access to as much as possible if they want or need it
// - To make it possible for the user to cut off as much as possible to use only what he or she needs.

//In addition to that, through adding all the optional features in this code, it was written with the hope that
//further modifications would not be necessary. Because of that, and the documentation, that should be provided
//with all the functions in a way that "CodeBlocks" should be able to display it to the user, very low readability
//of the implementation should not be that much of a problem and was as a result of that not much more than an
//afterthought.




//--------------------------------------------------------------------------------------------------------------
//                                              Information                    (Last Edited: 10th of April 2018)
//--------------------------------------------------------------------------------------------------------------
//This section provides general information about the purpose of the data-structure(s), the intended use and a
//possible example-situation in which that data-structure could be useful with an explanation why.

//General Information:
//--------------------
//This data-structure is called a Min-Max-PriorityQueue. Its' purpose is to combine two PriorityQueues into one:
// - One PriorityQueue to select the MINIMUM-Item (in regards to a comparison-function)
// - One PriorityQueue to select the MAXIMUM-Item (in regards to the same comparison-function).


//Reason for existence:
//---------------------
//By combining the functionality of two priority-queues into one the following effects were intended:
// - Minimizing the memory necessary (items only have to be stored once, not twice in two separate data-structures)
// - Allowing efficient removal of the Min- and the Max-Item. (*)

//(*) By combining both functionalities into one data-structure both operations can be done in O(log n) for both
//    at once. Otherwise it would either be O(log n) for the first data-structure and O(n) for the other, or
//    indirection would be necessary (which is actually done here for the "Advanced" versions ("PriorityQueueMMA"
//    and its "subclasses" like "PriorityQueueMMAF")). Those indirections would add a huge memory-overhead though
//    and would decrease the runtime at least slightly. The most efficient (and bare-bone) version
//    ("PriorityQueueMMSF") can do each of these two operations for a single item on the whole data in O(log n)
//    without indirections and almost no memory-overhead.


//Intended Use:
//-------------
//Use this data-structure if you need to be able to access and remove both the minimum- and the maximum-item in
//regards to a user-made comparison-function at a time of a collection of items.

//Example:
//You want to use a priority-queue that only selects the 10 smallest items to make further checks on them
//(maybe your memory is very limited, or because the checks are very computation-heavy and you only want to try
//the items that are most likely to be successful or return the best results).

//Possible solutions for this problem could be:
// - If memory was not the issue, you could just take a regular priority queue, put all the items into them and
//   then only use the first 10 items and discard the rest. But Insert-operations tend to become slower the more
//   items a data-structure contains (for some data-structures, but even if that is not a problem, the huge
//   memory overhead remains).
// - Another attempt could be an sorted array. This way you could instantly access the minimum and maximum item
//   and you could use the maximum-item (once you have reached the maximum allowed number of items) to filter out
//   the items that are already greater than the current maximum item. You can then find the position of the
//   remaining items by using binary search in O(log n) per item. After that, you have to move all the items that
//   that are either smaller or greater (depending on your implementation) though. This can be done very quickly
//   and might not be a problem for small arrays, for large arrays though it can, because that is done in O(m)
//   (m being the number of items that have to be moved).

//The Min-Max-PriorityQueue can solve this problem (at least for large arrays). First of all, you can access the
//Maximum-Item at all times (give that there is at least one item in the "queue"), so you can filter out all the
//items that are greater than the max-item once you have reached the maximum number of items in your queue. In
//addition to that, the insert-operation should run in O(log n) and should almost be as fast as the equivalent
//operation for a regular priority-queue with Binary-heap-implementation. Though it IS a little bit slower because
//of the selection of the tree the item should be inserted in in the beginning of the insert-operation.

//For the given example, the second suggestion might be faster then the Min-Max-PriorityQueue. Though with a large
//enough supported item-count, I am confident this should change.




//--------------------------------------------------------------------------------------------------------------
//                                                  Details                    (Last Edited: 10th of April 2018)
//--------------------------------------------------------------------------------------------------------------
//The purpose of this section is to inform the user about when to use what data-structure for optimal performance
//and what is necessary to enable in order to use the given data-structure


//Basic Data-structures:
//----------------------
//If possible, it is always recommended to use the basic data-structures to avoid unnecessary indirections.
//The following data-structures belong in this category:

//PriorityQueueMMSF:
// - RECOMMENDED USE: Integrated Systems, applications with hard real-time requirements, systems with low memory
// - REQUIRED CONFIGURATIONS: "INCLUDE_PRIORITYQUEUEMMSF"
// - DESCRIPTION:
//   This data-structure is the most basic version of all. The "S" and "F" in the end are abbreviations for
//   "Simple" and "Fixed-size". It can only contain a fixed number of items and only the basic functions are
//   available, BUT it is highly optimized for both speed and memory-usage. Apart from the header, it contains
//   no unnecessary overhead per item.

//PriorityQueueMMAF:
// - RECOMMENDED USE: Similar to "PriorityQueueMMSF" but with the necessity to remove items other than the Min-
//   and the Max-Item
// - REQUIRED CONFIGURATIONS: "INCLUDE_PRIORITYQUEUEMMAF"
// - DESCRIPTION:
//   This data-structure is the advanced version of "PriorityQueueMMSF". The "A" and "F" in the end are abbreviations
//   for "Advanced" and "Fixed-size". It can only contain a fixed number of items and only a third of "PriorityQueueMMSF"
//   with the same size, however this data-structure allows the removal of arbitrary items that are contained within this
//   data-structure. This is basically necessary if you need item "I" in the Min-Max-PriorityQueue "Q" and "I"
//   should be able to destroy itself. In this case you just use the "Insert"-Operation that return the "PriorityQueueMMAItem"
//   object, save that in "I" and when "I" needs to be destroyed, remove it from "Q".


//"Class"-Type Data-structures:
//-----------------------------
//Generally these data-structures can be used if you intend to use several different basic data-structures and
//call the right function for the given underlying data-structures. An example would be putting different
//Min-Max-PriorityQueues of different type, with different items but similar item-type and comparison-function in
//a list and trying to get the min/max item of one of the Min-Max-PriorityQueues. Using this feature is not
//recommended because of several level of indirection and additional necessary resources.
//To use these data-structures you will need to enable "PRIORITYQUEUEMM_INHERITANCE"
//The following data-structures belong in this category:

//PriorityQueueMM:
// - RECOMMENDED USE: Underlying type of Min-Max-PriorityQueue completely unknown
// - REQUIRED CONFIGURATIONS: "PRIORITYQUEUEMM_INHERITANCE"
// - DESCRIPTION:
//   This data-structure is the base-"class" of all Min-Max-PriorityQueues. As such its' underlying type can be
//   any basic Min-Max-PriorityQueue type. It only contains the most basic functions (those used in "PriorityQueueMMSF").

//PriorityQueueMMA:
// - RECOMMENDED USE: Underlying type of Min-Max-PriorityQueue is an advanced version of the Min-Max-PriorityQueue.
// - REQUIRED CONFIGURATIONS: "PRIORITYQUEUEMM_INHERITANCE", "INCLUDE_PRIORITYQUEUEMMAF"
// - DESCRIPTION:
//   This data-structure is the base-"class" of all advanced versions of Min-Max-PriorityQueues. As such it
//   contains all the functions "PriorityQueueMMAF" has.
//   NOTE: CURRENTLY USELESS BECAUSE THERE IS ONLY ONE ADVANCED VERSION!




//--------------------------------------------------------------------------------------------------------------
//                                              Configuration
//--------------------------------------------------------------------------------------------------------------
//Use the COMMENT-FUNCTIONALITY on the following "#define"-Statements to enable or disable features of the
//code that influence the way this code can be worked with.

#define PRIORITYQUEUEMM_INHERITANCE         //Allows the usage of "PriorityQueueMM" as "Base-Class". (Should decrease runtime SLIGHTLY to NOTABLY)
#define PRIORITYQUEUEMM_INIT_WITH_NULL      //FOR ADDITIONAL SAFETY RECOMMENDED (especially if "PriorityQueueMMAF" is used). Always sets "unused" items to "NULL".
                                            //(Should decrease runtime SLIGHTLY)
//#define PRIORITYQUEUEMM_FAILABLE_COMP       //NOT RECOMMENDED. Makes it possible for Comparisons to fail (with additional errorvalue). (Should decrease runtime NOTABLY)
                                            //It is recommended, that you disable this feature and write your comparison-function in a way it can not fail.


//Debug-Messages:
//---------------
//(Are ignored if "HIDE_ALL_MSGS" is defined)
//#define PRIORITYQUEUEMM_DISP_ERRORS     //Prints Error-Messages on the console
//#define PRIORITYQUEUEMM_DISP_INFO       //Prints Debug-Messages on the console
//#define PRIORITYQUEUEMM_DISP_WARNING    //Prints Warning-Messages on the console



//Special-Debug-Message-Config:
//-----------------------------
//(Disables Messages partially to avoid confusion)
//#define PRIORITYQUEUEMM_REM_DEF_INFO    //Disables the regular info
#define PRIORITYQUEUEMM_REM_SDU_INFO    //Disables the info for PriorityQueueMMDUnits
#define PRIORITYQUEUEMM_REM_ADU_INFO    //Disables the info for PriorityQueueMMADUnits
//#define PRIORITYQUEUEMM_REM_SEG_INFO    //Disables the advanced info for the Segment-Lists for PriorityQueueMMADUnits (Version 2)
#define PRIORITYQUEUEMM_REM_AVL_INFO    //Disables the info for the integrated AVL-Tree in PriorityQueueMMADUnits



//Safety-Check:
//-------------
//With what reliability will errors be caught. Higher level means results in more safety, though slower runtime. Not caught errors can result in crashes or undefined behavior.
//       NO SAFETYCHECK DEFINED             //Function calls assume you did all the functions are called correctly. Only errors, that can not be prevented
                                            //Like "NULL" as a result of "malloc" will be checked and caught. ONLY RECOMMENDED FOR EXTENSIVELY-TESTED SOFTWARE
                                            //WITH HARD REAL-TIME REQUIREMENTS.
#define PRIORITYQUEUEMM_SAFETYCHECK_LVL1    //RECOMMENDED DEFAULT. Will make safety-checks for all external function-calls
//#define PRIORITYQUEUEMM_SAFETYCHECK_LVL2    //FOR DEBUG AND MODIFICATION. Will make all safety-checks for internal function-calls in addition to the safety-checks
                                            //for "PRIORITYQUEUEMM_SAFETYCHECK_LVL1"



//Remove certain versions of the code:
//------------------------------------
//(to hopefully minimize the size of the application)
#define INCLUDE_PRIORITYQUEUEMMSF       //Includes the Simple, Fixed-Size Version of the Min-Max-PriorityQueue
#define INCLUDE_PRIORITYQUEUEMMAF       //Includes the Advanced, Fixed-Size Version of the Min-Max-PriorityQueue
#define INCLUDE_PRIORITYQUEUEMMSD       //Includes the Simple, Dynamic-Size Version of the Min-Max-PriorityQueue
#define INCLUDE_PRIORITYQUEUEMMAD       //Includes the Advanced, Dynamic-Size Version of the Min-Max-PriorityQueue

//Use a experimental version:
#define USE_PRIORITYQUEUEMMAD_V2        //Uses a modified Version of the Advanced, Dynamic-Size Version of the Min-Max-PriorityQueue.
                                        //This version is slower but has potentially a higher memory-efficiency:
                                        //      - Regular Version:
                                        //        Worst case: 75% (out of 128 Pointers exactly 96 Pointers can be used for Items)
                                        //        Best  case: 75% (out of 128 Pointers exactly 96 Pointers can be used for Items)
                                        //      - Version 2:
                                        //        Worst case: 72% (out of 128 Pointers exactly 93 Pointers can be used for Items)
                                        //        Best  case: 88% (out of 384 Pointers exactly 341 Pointers can be used for Items)



//Miscellaneous:
//--------------
#define PRIORITYQUEUEMMAD_BUFFER    2   //How many empty units should remain for the Advanced, Dynamic-Size Version of the Min-Max-PriorityQueue until empty units are released.
                                        //The greater the value, the less often Units have to be created and destroyed, but the more memory remains in use.
                                        //Both, the creation and the destruction of those Units is particular expensive. That is the reason why the user can configure this value.

#define PRIORITYQUEUEMMAD_CHECK_REF     //Checks the "PriorityQueueMMAItem", whether it is a valid "PriorityQueueMMAItem" for ANY "PriorityQueueMMAD" for the "PriorityQueueMMA"-
                                        //Operations that take a "PriorityQueueMMAItem". The lookup takes O(log n), with "n" being the number of "PriorityQueueMMADUnit"s (NOT
                                        //to confuse with "PriorityQueueMMDUnit" (!)). Deactivating this feature can lead to undefined behavior if the assumed "PriorityQueueMMAItem"
                                        //is not a valid "PriorityQueueMMAItem" for any "PriorityQueueMMAD". If you know that the "PriorityQueueMMAItem" is actually a valid
                                        //"PriorityQueueMMAItem" for a "PriorityQueueMMAD", it can then check in O(1) whether it actually belongs to the "PriorityQueueMMAD" of the
                                        //function-call.
                                        //REGARDLESS OF WHETHER THE FEATURE IS ENABLED OR NOT, YOU CAN CHECk WHETHER THE ASSUMED "PriorityQueueMMAItem" IS ACTUALLY A VALID
                                        //"PriorityQueueMMAItem" OF THE SPECIFIED "PriorityQueueMMDUnit" BY CALLING "PriorityQueueMMAD_ContainsItem()".


//Functions for Memory-Allocation:
//------------------------------
//(Necessary for the Dynamic data-structures. It is allowed to set the called functions as long as their
// functionality (described below) remains)
#define PRIORITYQUEUEMM_ALLOCATE_MEM        (malloc(sizeof(void*) << 7))    //(1)
#define PRIORITYQUEUEMM_RELEASE_MEM(Ptr)    (free(((void*)(Ptr))))          //(2)

//(1): Function that allocates memory in the heap (or "obtains" memory in some other way) of the size "128 * sizeof(void*)"
//     and "returns" a void-pointer to the beginning of said memory-location.
//     ORIGINALLY: (malloc(sizeof(void*) << 7))
//(2): Function that releases the memory that was allocated by "PRIORITYQUEUEMM_ALLOCATE_MEM"
//     ORIGINALLY: (free(((void*)(Ptr))))




//--------------------------------------------------------------------------------------------------------------
//                                              Code
//--------------------------------------------------------------------------------------------------------------
//Do not change or modify the following lines of code.

#ifndef PRIORITYQUEUEMM_ALLOCATE_MEM
#define PRIORITYQUEUEMM_ALLOCATE_MEM        (malloc(sizeof(void*) << 7))
#endif // PRIORITYQUEUEMM_ALLOCATE_MEM

#ifndef PRIORITYQUEUEMM_RELEASE_MEM
#define PRIORITYQUEUEMM_RELEASE_MEM(Ptr)    (free(((void*)(Ptr))))
#endif // PRIORITYQUEUEMM_RELEASE_MEM

#if (PRIORITYQUEUEMMAD_BUFFER < 1)
#undef PRIORITYQUEUEMMAD_BUFFER
#endif // (PRIORITYQUEUEMMAD_BUFFER < 1)

#ifndef PRIORITYQUEUEMMAD_BUFFER
#define PRIORITYQUEUEMMAD_BUFFER    2
#endif // PRIORITYQUEUEMMAD_BUFFER


#ifdef INCLUDE_PRIORITYQUEUEMMSF
    #define INCLUDE_STRUCT_PRIORITYQUEUEMMSF
    #define INCLUDE_F_SIZE_PRIORITYQUEUEMM
    #define INCLUDE_S_TYPE_PRIORITYQUEUEMM      //"Simple"-Type included
    #define PRIORITYQUEUEMM_SINGLE_B_TYPE       //Single "Base"-Type included
#endif // INCLUDE_PRIORITYQUEUEMMSF


#ifdef INCLUDE_PRIORITYQUEUEMMAF
    #ifndef PRIORITYQUEUEMM_INHERITANCE
        #define INCLUDE_STRUCT_PRIORITYQUEUEMMSF
    #else // PRIORITYQUEUEMM_INHERITANCE
        #define INCLUDE_STRUCT_PRIORITYQUEUEMMAF
        #define INCLUDE_STRUCT_PRIORITYQUEUEMMA
    #endif // PRIORITYQUEUEMM_INHERITANCE

    #define INCLUDE_PRIORITYQUEUEMMAITEM
    #define INCLUDE_F_SIZE_PRIORITYQUEUEMM

    #ifndef PRIORITYQUEUEMM_SINGLE_B_TYPE
        #define PRIORITYQUEUEMM_SINGLE_B_TYPE       //Single "Base"-Type included
    #else // PRIORITYQUEUEMM_SINGLE_B_TYPE
        #undef PRIORITYQUEUEMM_SINGLE_B_TYPE
        #define PRIORITYQUEUEMM_MULT_B_TYPE         //Multiple "Base"-Types included
    #endif // PRIORITYQUEUEMM_SINGLE_B_TYPE
#endif // INCLUDE_PRIORITYQUEUEMMAF


#ifdef INCLUDE_PRIORITYQUEUEMMSD
    #define INCLUDE_STRUCT_PRIORITYQUEUEMMSD
    #define INCLUDE_D_SIZE_PRIORITYQUEUEMM

    #ifndef PRIORITYQUEUEMM_MULT_B_TYPE
        #ifndef PRIORITYQUEUEMM_SINGLE_B_TYPE
            #define PRIORITYQUEUEMM_SINGLE_B_TYPE       //Single "Base"-Type included
        #else // PRIORITYQUEUEMM_SINGLE_B_TYPE
            #undef PRIORITYQUEUEMM_SINGLE_B_TYPE
            #define PRIORITYQUEUEMM_MULT_B_TYPE         //Multiple "Base"-Types included
        #endif // PRIORITYQUEUEMM_SINGLE_B_TYPE
    #endif // PRIORITYQUEUEMM_MULT_B_TYPE
#endif // INCLUDE_PRIORITYQUEUEMMSD


#ifdef INCLUDE_PRIORITYQUEUEMMAD
    #ifdef PRIORITYQUEUEMM_INHERITANCE
        #define INCLUDE_STRUCT_PRIORITYQUEUEMMA
    #endif // PRIORITYQUEUEMM_INHERITANCE

    #define INCLUDE_PRIORITYQUEUEMMAITEM
    #define INCLUDE_STRUCT_PRIORITYQUEUEMMAD
    #define INCLUDE_D_SIZE_PRIORITYQUEUEMM

    #ifndef PRIORITYQUEUEMM_MULT_B_TYPE
        #ifndef PRIORITYQUEUEMM_SINGLE_B_TYPE
            #define PRIORITYQUEUEMM_SINGLE_B_TYPE       //Single "Base"-Type included
        #else // PRIORITYQUEUEMM_SINGLE_B_TYPE
            #undef PRIORITYQUEUEMM_SINGLE_B_TYPE
            #define PRIORITYQUEUEMM_MULT_B_TYPE         //Multiple "Base"-Types included
        #endif // PRIORITYQUEUEMM_SINGLE_B_TYPE
    #endif // PRIORITYQUEUEMM_MULT_B_TYPE
#endif // INCLUDE_PRIORITYQUEUEMMAD


#ifdef PRIORITYQUEUEMM_SAFETYCHECK_LVL2
#define PRIORITYQUEUEMM_SAFETYCHECK_LVL1
#endif // PRIORITYQUEUEMM_SAFETYCHECK_LVL2


#ifndef ERRVAL_T
#define ERRVAL_T        uint64_t
#endif // ERRVAL_T

#ifndef ERRVAL_NO_ERR
#define ERRVAL_NO_ERR           0           //No error occurred
#endif // ERRVAL_NO_ERR

#ifndef ERRVAL_NOT_SUPP
#define ERRVAL_NOT_SUPP         2           //Something is not supported. For not supported Operations, use "ERRVAL_OP_NOT_SUPP"
#endif // ERRVAL_NOT_SUPP

#ifndef ERRVAL_OP_NOT_SUPP
#define ERRVAL_OP_NOT_SUPP      3           //Operation is not supported
#endif // ERRVAL_OP_NOT_SUPP

#ifndef ERRVAL_OP_MISSING
#define ERRVAL_OP_MISSING       4           //Required Operation is missing. (Usually because a function-pointer is "NULL")
#endif // ERRVAL_OP_MISSING

#ifndef ERRVAL_NO_MEM
#define ERRVAL_NO_MEM           10          //Memory could not be allocated
#endif // ERRVAL_NO_MEM

#ifndef ERRVAL_IS_NULL
#define ERRVAL_IS_NULL          20          //Pointer that should not be "NULL" is "NULL"
#endif // ERRVAL_IS_NULL

#ifndef ERRVAL_IS_EMPTY
#define ERRVAL_IS_EMPTY         22          //Container-Data-structure does not contain any items.
#endif // ERRVAL_IS_EMPTY

#ifndef ERRVAL_IS_FULL
#define ERRVAL_IS_FULL          23          //Container-Data-structure can not contain any more items.
#endif // ERRVAL_IS_FULL

#ifndef ERRVAL_NOT_MEMBER
#define ERRVAL_NOT_MEMBER       24          //Container-Data-structure does not contain the specified item.
#endif // ERRVAL_NOT_MEMBER

#ifndef ERRVAL_TYPE_INVALID
#define ERRVAL_TYPE_INVALID     25          //Type is not in a valid state. It was either not created correctly or got corrupted.
#endif // ERRVAL_TYPE_INVALID

#ifndef ERRVAL_INVALID_VAL
#define ERRVAL_INVALID_VAL      30          //Value of some variable is invalid
#endif // ERRVAL_INVALID_VAL

#ifndef ERRVAL_OUT_OF_RANGE
#define ERRVAL_OUT_OF_RANGE     31          //Value of some variable is out of the important range for this value.
#endif // ERRVAL_OUT_OF_RANGE




#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMSF
#define INCLUDE_PRIORITYQUEUEMM
#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMSF

#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMAF
#define INCLUDE_PRIORITYQUEUEMM
#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMAF

#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMSD
#define INCLUDE_PRIORITYQUEUEMM
#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMSD

#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMAD
#define INCLUDE_PRIORITYQUEUEMM
#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMAD

//Only if AT LEAST ONE version of the "PriorityQueueMM" data structure is included will the code actually be compiled
#ifdef INCLUDE_PRIORITYQUEUEMM

#ifdef PRIORITYQUEUEMM_INHERITANCE
typedef struct priorityqueuemm PriorityQueueMM;
typedef struct i_priorityqueuemm I_PriorityQueueMM;
#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMA
typedef struct priorityqueuemma PriorityQueueMMA;
typedef struct i_priorityqueuemma I_PriorityQueueMMA;
#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMA
#endif // PRIORITYQUEUEMM_INHERITANCE

#ifdef INCLUDE_PRIORITYQUEUEMMAITEM
typedef void* PriorityQueueMMAItem;
#endif // INCLUDE_PRIORITYQUEUEMMAITEM

#ifdef INCLUDE_PRIORITYQUEUEMMSF
typedef struct priorityqueuemmsf PriorityQueueMMSF;         //Simple, Fixed-Size Min-Max-PriorityQueue
#endif // INCLUDE_PRIORITYQUEUEMMSF

#ifdef INCLUDE_PRIORITYQUEUEMMAF
#ifndef PRIORITYQUEUEMM_INHERITANCE
typedef struct priorityqueuemmsf PriorityQueueMMAF;         //Advanced, Fixed-Size Min-Max-PriorityQueue
#else // PRIORITYQUEUEMM_INHERITANCE
typedef struct priorityqueuemmaf PriorityQueueMMAF;         //Advanced, Fixed-Size Min-Max-PriorityQueue
#endif // PRIORITYQUEUEMM_INHERITANCE
#endif // INCLUDE_PRIORITYQUEUEMMAF

#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMSD
typedef struct priorityqueuemmsd PriorityQueueMMSD;         //Simple, Dynamic Min-Max-PriorityQueue
#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMSD

#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMAD
typedef struct priorityqueuemmad PriorityQueueMMAD;         //Advanced, Dynamic Min-Max-PriorityQueue
#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMAD

#ifdef INCLUDE_D_SIZE_PRIORITYQUEUEMM
typedef struct priorityqueuemmdunit PriorityQueueMMDUnit;
typedef struct priorityqueuemmdblock PriorityQueueMMDBlock;
#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMAD
typedef struct priorityqueuemmadunit PriorityQueueMMADUnit;
#ifndef USE_PRIORITYQUEUEMMAD_V2
typedef struct priorityqueuemmadblock PriorityQueueMMADBlock;
#endif // USE_PRIORITYQUEUEMMAD_V2
#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMAD
#endif // INCLUDE_D_SIZE_PRIORITYQUEUEMM

#ifdef PRIORITYQUEUEMM_FAILABLE_COMP
    #define PRIORITYQUEUEMM_COMP_PTR        int (*Compare)(void* I1,void* I2,ERRVAL_T* Errval)
    #define PRIORITYQUEUEMM_COMP_FUNC_PTR   int(*compare)(void*,void*,ERRVAL_T*)
#else // PRIORITYQUEUEMM_FAILABLE_COMP
    #define PRIORITYQUEUEMM_COMP_PTR        int (*Compare)(void* I1,void* I2)
    #define PRIORITYQUEUEMM_COMP_FUNC_PTR   int(*compare)(void*,void*)
#endif // PRIORITYQUEUEMM_FAILABLE_COMP


#ifdef PRIORITYQUEUEMM_INHERITANCE
struct priorityqueuemm
{
    const I_PriorityQueueMM* IFunc;
    void* arg;

    PRIORITYQUEUEMM_COMP_PTR;
    int (*DisposeItem)(void* I,ERRVAL_T* Errval);
    int (*DisposeSelf)(void* I,void* arg,ERRVAL_T* Errval);
};

struct i_priorityqueuemm
{
    #ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMA
    PriorityQueueMMA* (*get_PriorityQueueMMA)(PriorityQueueMM* Q,ERRVAL_T* Errval);
    #endif // INCLUDE_STRUCT_PRIORITYQUEUEMMA

    #ifdef INCLUDE_PRIORITYQUEUEMMSF
    PriorityQueueMMSF* (*get_PriorityQueueMMSF)(PriorityQueueMM* Q,ERRVAL_T* Errval);
    #endif // INCLUDE_PRIORITYQUEUEMMSF

    #ifdef INCLUDE_PRIORITYQUEUEMMAF
    PriorityQueueMMAF* (*get_PriorityQueueMMAF)(PriorityQueueMM* Q,ERRVAL_T* Errval);
    #endif // INCLUDE_PRIORITYQUEUEMMAF

    #ifdef INCLUDE_PRIORITYQUEUEMMSD
    PriorityQueueMMSD* (*get_PriorityQueueMMSD)(PriorityQueueMM* Q,ERRVAL_T* Errval);
    #endif // INCLUDE_PRIORITYQUEUEMMSD

    #ifdef INCLUDE_PRIORITYQUEUEMMAD
    PriorityQueueMMAD* (*get_PriorityQueueMMAD)(PriorityQueueMM* Q,ERRVAL_T* Errval);
    #endif // INCLUDE_PRIORITYQUEUEMMAD

    int (*hasFixedSize)(PriorityQueueMM* Q,ERRVAL_T* Errval);
    int (*getCount)(PriorityQueueMM* Q,ERRVAL_T* Errval);
    int (*getReservedItems)(PriorityQueueMM* Q,ERRVAL_T* Errval);
    size_t (*getReservedMemory)(PriorityQueueMM* Q,ERRVAL_T* Errval);
    void* (*getMin)(PriorityQueueMM* Q,ERRVAL_T* Errval);
    void* (*getMax)(PriorityQueueMM* Q,ERRVAL_T* Errval);
    int (*Insert)(PriorityQueueMM* Q,void* Item,ERRVAL_T* Errval);
    int (*RemoveMin)(PriorityQueueMM* Q,ERRVAL_T* Errval);
    int (*RemoveMax)(PriorityQueueMM* Q,ERRVAL_T* Errval);
    int (*RemoveMinSource)(PriorityQueueMM* Q,ERRVAL_T* Errval);
    int (*RemoveMaxSource)(PriorityQueueMM* Q,ERRVAL_T* Errval);
    int (*Clear)(PriorityQueueMM* Q,ERRVAL_T* Errval);
    int (*ClearSource)(PriorityQueueMM* Q,ERRVAL_T* Errval);
    int (*Dispose)(PriorityQueueMM* Q,ERRVAL_T* Errval);
    int (*DisposeSource)(PriorityQueueMM* Q,ERRVAL_T* Errval);
};

#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMA
struct priorityqueuemma
{
    PriorityQueueMM Base;
    const I_PriorityQueueMMA* IFunc;
};

struct i_priorityqueuemma
{
    PriorityQueueMMAItem* (*getMinItem)(PriorityQueueMMA* Q,ERRVAL_T* Errval);
    PriorityQueueMMAItem* (*getMaxItem)(PriorityQueueMMA* Q,ERRVAL_T* Errval);
    PriorityQueueMMAItem* (*GetInsertedItem)(PriorityQueueMMA* Q,void* Item,ERRVAL_T* Errval);
    void* (*GetItemOfItem)(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval);
    int (*SetItemOfItem)(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,void* ItemValue,ERRVAL_T* Errval);
    int (*ContainsItem)(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval);
    int (*UpdateItem)(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval);
    int (*RemoveItem)(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval);
    int (*RemoveItemSource)(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval);
};

#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMA
#endif // PRIORITYQUEUEMM_INHERITANCE


#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMSF
struct priorityqueuemmsf
{
    #ifdef PRIORITYQUEUEMM_INHERITANCE
    PriorityQueueMM Base;
    #endif // PRIORITYQUEUEMM_INHERITANCE
    int Count;
    size_t Size;
    uint16_t LstLayerStart;

    #ifndef PRIORITYQUEUEMM_INHERITANCE
    void* arg;

    PRIORITYQUEUEMM_COMP_PTR;
    int (*DisposeItem)(void* I,ERRVAL_T* Errval);
    int (*DisposeSelf)(void* I,void* arg,ERRVAL_T* Errval);
    #endif // PRIORITYQUEUEMM_INHERITANCE

    void* Items[];
};
#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMF

#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMAF
struct priorityqueuemmaf
{
    PriorityQueueMMA Base;
    int Count;
    size_t Size;
    uint16_t LstLayerStart;
    void* Items[];
};
#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMAF

#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMSD
struct priorityqueuemmsd
{
    #ifdef PRIORITYQUEUEMM_INHERITANCE
    PriorityQueueMM Base;
    #endif // PRIORITYQUEUEMM_INHERITANCE
    int Count;
    int UnitCount;
    PriorityQueueMMDBlock* Top;
    PriorityQueueMMDBlock* Bottom;
    uint32_t LstLayerStart;

    #ifndef PRIORITYQUEUEMM_INHERITANCE
    void* arg;

    PRIORITYQUEUEMM_COMP_PTR;
    int (*DisposeItem)(void* I,ERRVAL_T* Errval);
    int (*DisposeSelf)(void* I,void* arg,ERRVAL_T* Errval);
    #endif // PRIORITYQUEUEMM_INHERITANCE
};
#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMSD

#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMAD
struct priorityqueuemmad
{
    #ifdef PRIORITYQUEUEMM_INHERITANCE
    PriorityQueueMMA Base;
    #endif // PRIORITYQUEUEMM_INHERITANCE
    int Count;
    int UnitCount;
    PriorityQueueMMDBlock* Top;
    PriorityQueueMMDBlock* Bottom;
    uint32_t LstLayerStart;

    int AUnitCount;
    int AResItemCount;
    PriorityQueueMMADUnit* Root;
    PriorityQueueMMADUnit* CurUnit;     //Current Unit that should be filled
    PriorityQueueMMADUnit* LstUnit;     //Unit where new units should be attached


    #ifndef PRIORITYQUEUEMM_INHERITANCE
    void* arg;

    PRIORITYQUEUEMM_COMP_PTR;
    int (*DisposeItem)(void* I,ERRVAL_T* Errval);
    int (*DisposeSelf)(void* I,void* arg,ERRVAL_T* Errval);
    #endif // PRIORITYQUEUEMM_INHERITANCE
};
#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMAD

#ifdef INCLUDE_D_SIZE_PRIORITYQUEUEMM

struct priorityqueuemmdunit
{
    void* Owner;
    void* Alloc_Start;
    PriorityQueueMMDBlock* Prev;
    PriorityQueueMMDBlock* Next;
};

struct priorityqueuemmdblock
{
    PriorityQueueMMDUnit* UnitPtr;
    PriorityQueueMMDBlock* Parent;
    PriorityQueueMMDBlock* Child;
    PriorityQueueMMDBlock* Other;
    uintptr_t Unused;               //Unused value that is necessary for the right block-header-size
    intptr_t Offset;
    void* BackPtr;
    void* FrstItem;
};

#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMAD
#ifndef USE_PRIORITYQUEUEMMAD_V2
struct priorityqueuemmadunit
{
    void** SpecBlock;
    PriorityQueueMMADBlock* Block1;
    PriorityQueueMMADBlock* Block2;
    PriorityQueueMMADBlock* Block3;
};

struct priorityqueuemmadblock
{
    PriorityQueueMMADUnit* UnitPtr;
    PriorityQueueMMADBlock* Prev;
    PriorityQueueMMADBlock* Next;
    void* BackPtr;
    void* FrstItem;

    //Additional Memory for the Unit:
    intptr_t Val1;
    void* Ptr1;
    void* Ptr2;
};
#else // USE_PRIORITYQUEUEMMAD_V2
struct priorityqueuemmadunit
{
    void* Owner;
    uintptr_t Data1;
    uintptr_t Data2;
    void* BackPtr;
    PriorityQueueMMADUnit* Prev;
    PriorityQueueMMADUnit* Next;
    PriorityQueueMMADUnit* Parent;
    PriorityQueueMMADUnit* Child1;
    PriorityQueueMMADUnit* Child2;
    intptr_t Maxlength;
};
#endif // USE_PRIORITYQUEUEMMAD_V2
#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMAD


#endif // INCLUDE_D_SIZE_PRIORITYQUEUEMM






//Constructors:
#ifdef INCLUDE_PRIORITYQUEUEMMSF
/** \brief Initializes a new Simple, Fixed-Size Min-Max-PriorityQueue at the specified memory-location with the specified size,comparison-function and resource-release-function for its items. Use "PriorityQueueMMSF_GetSizeFor()" to get the size necessary to contain a specified number of items.
*
* \param *MemPtr The Pointer to the memory-location that should be used for the Simple, Fixed-Size Min-Max-PriorityQueue.
* \param Size The Size the Min-Max-PriorityQueue has at its disposal. Use "PriorityQueueMMSF_GetSizeFor()" to get the size necessary to contain a specified number of items.
* \param *compare The comparison-function. Compares two items "I1" and "I2" and returns "-1" if "I1" > "I2", 0 if "I1" == "I2" and 1 if "I1" < "I2".
* \param *disposeItem The resource-release function for items.
* \param *disposeSelf The resource-release function for the memory of "MemPtr". Can be NULL.
* \param *arg Optional argument for "disposeSelf()". Can be NULL (and has to be NULL if "disposeSelf" is NULL).
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

PriorityQueueMMSF* PriorityQueueMMSF_Create(void* MemPtr,size_t Size,PRIORITYQUEUEMM_COMP_FUNC_PTR,int(*disposeItem)(void*,ERRVAL_T*),int(*disposeSelf)(void*,void*,ERRVAL_T*),void* arg,ERRVAL_T* Errval);
#endif // INCLUDE_PRIORITYQUEUEMMSF

#ifdef INCLUDE_PRIORITYQUEUEMMAF
/** \brief Initializes a new Advanced, Fixed-Size Min-Max-PriorityQueue at the specified memory-location with the specified size,comparison-function and resource-release-function for its items. Use "PriorityQueueMMAF_GetSizeFor()" to get the size necessary to contain a specified number of items.
*
* \param *MemPtr The Pointer to the memory-location that should be used for the Advanced, Fixed-Size Min-Max-PriorityQueue.
* \param Size The Size the Min-Max-PriorityQueue has at its disposal. Use "PriorityQueueMMAF_GetSizeFor()" to get the size necessary to contain a specified number of items.
* \param *compare The comparison-function. Compares two items "I1" and "I2" and returns "-1" if "I1" > "I2", 0 if "I1" == "I2" and 1 if "I1" < "I2".
* \param *disposeItem The resource-release function for items.
* \param *disposeSelf The resource-release function for the memory of "MemPtr". Can be NULL.
* \param *arg Optional argument for "disposeSelf()". Can be NULL (and has to be NULL if "disposeSelf" is NULL).
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

PriorityQueueMMAF* PriorityQueueMMAF_Create(void* MemPtr,size_t Size,PRIORITYQUEUEMM_COMP_FUNC_PTR,int(*disposeItem)(void*,ERRVAL_T*),int(*disposeSelf)(void*,void*,ERRVAL_T*),void* arg,ERRVAL_T* Errval);
#endif // INCLUDE_PRIORITYQUEUEMMAF

#ifdef INCLUDE_PRIORITYQUEUEMMSD
/** \brief Initializes a new Simple, Dynamic-Size Min-Max-PriorityQueue at the specified memory-location with the specified size,comparison-function and resource-release-function for its items. Use "sizeof(PriorityQueueMMSD)" to get the size necessary to create this Min-Max-PriorityQueue.
*
* \param *MemPtr The Pointer to the memory-location that should be used for the Simple, Dynamic-Size Min-Max-PriorityQueue.
* \param Size The Size of the available memory at "MemPtr". Use "sizeof(PriorityQueueMMSD)" to get the necessary size.
* \param *compare The comparison-function. Compares two items "I1" and "I2" and returns "-1" if "I1" > "I2", 0 if "I1" == "I2" and 1 if "I1" < "I2".
* \param *disposeItem The resource-release function for items.
* \param *disposeSelf The resource-release function for the memory of "MemPtr". Can be NULL.
* \param *arg Optional argument for "disposeSelf()". Can be NULL (and has to be NULL if "disposeSelf" is NULL).
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

PriorityQueueMMSD* PriorityQueueMMSD_Create(void* MemPtr,size_t Size,PRIORITYQUEUEMM_COMP_FUNC_PTR,int(*disposeItem)(void*,ERRVAL_T*),int(*disposeSelf)(void*,void*,ERRVAL_T*),void* arg,ERRVAL_T* Errval);
#endif // INCLUDE_PRIORITYQUEUEMMSD

#ifdef INCLUDE_PRIORITYQUEUEMMAD
/** \brief Initializes a new Advanced, Dynamic-Size Min-Max-PriorityQueue at the specified memory-location with the specified size,comparison-function and resource-release-function for its items. Use "sizeof(PriorityQueueMMAD)" to get the size necessary to create this Min-Max-PriorityQueue.
*
* \param *MemPtr The Pointer to the memory-location that should be used for the Advanced, Dynamic-Size Min-Max-PriorityQueue.
* \param Size The Size of the available memory at "MemPtr". Use "sizeof(PriorityQueueMMAD)" to get the necessary size.
* \param *compare The comparison-function. Compares two items "I1" and "I2" and returns "-1" if "I1" > "I2", 0 if "I1" == "I2" and 1 if "I1" < "I2".
* \param *disposeItem The resource-release function for items.
* \param *disposeSelf The resource-release function for the memory of "MemPtr". Can be NULL.
* \param *arg Optional argument for "disposeSelf()". Can be NULL (and has to be NULL if "disposeSelf" is NULL).
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

PriorityQueueMMAD* PriorityQueueMMAD_Create(void* MemPtr,size_t Size,PRIORITYQUEUEMM_COMP_FUNC_PTR,int(*disposeItem)(void*,ERRVAL_T*),int(*disposeSelf)(void*,void*,ERRVAL_T*),void* arg,ERRVAL_T* Errval);
#endif // INCLUDE_PRIORITYQUEUEMMAD





// All the member-functions:
#ifdef PRIORITYQUEUEMM_INHERITANCE

#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMA
/** \brief Returns the "PriorityQueueMMA" if the underlying PriorityQueue is of its' sub-types, otherwise "NULL".
*
* \param *Q The Min-Max-PriorityQueue whose underlying "PriorityQueueMMA" should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

PriorityQueueMMA* PriorityQueueMM_Get_PriorityQueueMMA(PriorityQueueMM* Q,ERRVAL_T* Errval);
#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMA

#ifdef INCLUDE_PRIORITYQUEUEMMSF
/** \brief Returns the "PriorityQueueMMSF" if the underlying PriorityQueue is of that type, otherwise "NULL".
*
* \param *Q The Min-Max-PriorityQueue whose underlying "PriorityQueueMMSF" should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

PriorityQueueMMSF* PriorityQueueMM_Get_PriorityQueueMMSF(PriorityQueueMM* Q,ERRVAL_T* Errval);
#endif // INCLUDE_PRIORITYQUEUEMMSF

#ifdef INCLUDE_PRIORITYQUEUEMMAF
/** \brief Returns the "PriorityQueueMMAF" if the underlying PriorityQueue is of that type, otherwise "NULL".
*
* \param *Q The Min-Max-PriorityQueue whose underlying "PriorityQueueMMAF" should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

PriorityQueueMMAF* PriorityQueueMM_Get_PriorityQueueMMAF(PriorityQueueMM* Q,ERRVAL_T* Errval);
#endif // INCLUDE_PRIORITYQUEUEMMAF

#ifdef INCLUDE_PRIORITYQUEUEMMSD
/** \brief Returns the "PriorityQueueMMSD" if the underlying PriorityQueue is of that type, otherwise "NULL".
*
* \param *Q The Min-Max-PriorityQueue whose underlying "PriorityQueueMMSD" should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

PriorityQueueMMSD* PriorityQueueMM_Get_PriorityQueueMMSD(PriorityQueueMM* Q,ERRVAL_T* Errval);
#endif // INCLUDE_PRIORITYQUEUEMMSD

/** \brief Returns "1" if the underlying type is a fixed-size Min-Max-PriorityQueue or "0" otherwise.
*
* \param *Q The Min-Max-PriorityQueue that should be checked whether its' underlying type is a fixed-Size PriorityQueue.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMM_HasFixedSize(PriorityQueueMM* Q,ERRVAL_T* Errval);

/** \brief Returns the number of items the Min-Max-PriorityQueue currently contains.
*
* \param *Q The Min-Max-PriorityQueue whose number of items should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMM_GetCount(PriorityQueueMM* Q,ERRVAL_T* Errval);

/** \brief Returns the number of currently reserved items of the Min-Max-PriorityQueue. For Fixed-Size data-structures this is also the maximum number of items this PriorityQueue can contain.
*
* \param *Q The Min-Max-PriorityQueue whose currently reserved item-count should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMM_GetReservedItems(PriorityQueueMM* Q,ERRVAL_T* Errval);

/** \brief Returns the total size of the memory (currently) reserved for this data-structure.
*
* \param *Q The Min-Max-PriorityQueue whose total size of reserved memory should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

size_t PriorityQueueMM_GetReservedMemory(PriorityQueueMM* Q,ERRVAL_T* Errval);

/** \brief Returns the min-item (in regards to the comparison-function) of the Min-Max-PriorityQueue or NULL.
*
* \param *Q The Min-Max-PriorityQueue whose min-item should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

void* PriorityQueueMM_GetMin(PriorityQueueMM* Q,ERRVAL_T* Errval);

/** \brief Returns the max-item (in regards to the comparison-function) of the Min-Max-PriorityQueue or NULL.
*
* \param *Q The Min-Max-PriorityQueue whose max-item should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

void* PriorityQueueMM_GetMax(PriorityQueueMM* Q,ERRVAL_T* Errval);

/** \brief Inserts a new item into the Min-Max-PriorityQueue. The item has to be of a valid type (the type the comparison-function works with) otherwise the behavior is undefined.
*
* \param *Q The Min-Max-PriorityQueue in which the item should be inserted.
* \param *Item The item that should be inserted. Has to be of the type the comparison-function works with.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMM_Insert(PriorityQueueMM* Q,void* Item,ERRVAL_T* Errval);

/** \brief Removes the min-item of the Min-Max-PriorityQueue without freeing its' the resources.
*
* \param *Q The Min-Max-PriorityQueue whose min-item should be removed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMM_RemoveMin(PriorityQueueMM* Q,ERRVAL_T* Errval);

/** \brief Removes the max-item of the Min-Max-PriorityQueue without freeing its' the resources.
*
* \param *Q The Min-Max-PriorityQueue whose max-item should be removed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMM_RemoveMax(PriorityQueueMM* Q,ERRVAL_T* Errval);

/** \brief Removes the min-item of the Min-Max-PriorityQueue and frees its' resources.
*
* \param *Q The Min-Max-PriorityQueue whose min-item should be removed and freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMM_RemoveMinSource(PriorityQueueMM* Q,ERRVAL_T* Errval);

/** \brief Removes the max-item of the Min-Max-PriorityQueue and frees its' resources.
*
* \param *Q The Min-Max-PriorityQueue whose max-item should be removed and freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMM_RemoveMaxSource(PriorityQueueMM* Q,ERRVAL_T* Errval);

/** \brief Removes all items of the Min-Max-PriorityQueue without freeing their resources.
*
* \param *Q The Min-Max-PriorityQueue whose items should be removed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMM_Clear(PriorityQueueMM* Q,ERRVAL_T* Errval);

/** \brief Removes all items of the Min-Max-PriorityQueue and frees their resources.
*
* \param *Q The Min-Max-PriorityQueue whose items should be removed and freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMM_ClearSource(PriorityQueueMM* Q,ERRVAL_T* Errval);

/** \brief Frees the Min-Max-PriorityQueue without freeing its' items.
*
* \param *Q The Min-Max-PriorityQueue that should be freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMM_Dispose(PriorityQueueMM* Q,ERRVAL_T* Errval);

/** \brief Frees the Min-Max-PriorityQueue and its' items.
*
* \param *Q The Min-Max-PriorityQueue that should be freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMM_DisposeSource(PriorityQueueMM* Q,ERRVAL_T* Errval);


#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMA

/** \brief Returns the "PriorityQueueMM" (the generalized type all other Min-Max-PriorityQueues are underlying types of).
*
* \param *Q The Advanced Min-Max-PriorityQueue whose "PriorityQueueMM" should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

PriorityQueueMM* PriorityQueueMMA_Get_PriorityQueueMM(PriorityQueueMMA* Q,ERRVAL_T* Errval);

#ifdef INCLUDE_PRIORITYQUEUEMMAF
/** \brief Returns the "PriorityQueueMMAF" if the underlying PriorityQueue is of that type, otherwise "NULL".
*
* \param *Q The Advanced Min-Max-PriorityQueue whose underlying "PriorityQueueMMAF" should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

PriorityQueueMMAF* PriorityQueueMMA_Get_PriorityQueueMMAF(PriorityQueueMMA* Q,ERRVAL_T* Errval);
#endif // INCLUDE_PRIORITYQUEUEMMAF

/** \brief Returns "1" if the underlying type is a fixed-size Min-Max-PriorityQueue or "0" otherwise.
*
* \param *Q The Advanced Min-Max-PriorityQueue that should be checked whether its' underlying type is a fixed-Size PriorityQueue.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMA_HasFixedSize(PriorityQueueMMA* Q,ERRVAL_T* Errval);

/** \brief Returns the number of items the Advanced Min-Max-PriorityQueue currently contains.
*
* \param *Q The Advanced Min-Max-PriorityQueue whose number of items should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMA_GetCount(PriorityQueueMMA* Q,ERRVAL_T* Errval);

/** \brief Returns the number of currently reserved items of the Advanced Min-Max-PriorityQueue. For Fixed-Size data-structures this is also the maximum number of items this PriorityQueue can contain.
*
* \param *Q The Advanced Min-Max-PriorityQueue whose currently reserved item-count should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMA_GetReservedItems(PriorityQueueMMA* Q,ERRVAL_T* Errval);

/** \brief Returns the total size of the memory reserved for this data-structure.
*
* \param *Q The Advanced Min-Max-PriorityQueue whose total size of reserved memory should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

size_t PriorityQueueMMA_GetReservedMemory(PriorityQueueMMA* Q,ERRVAL_T* Errval);

/** \brief Returns the min-item (in regards to the comparison-function) of the Advanced Min-Max-PriorityQueue or NULL.
*
* \param *Q The Advanced Min-Max-PriorityQueue whose min-item should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

void* PriorityQueueMMA_GetMin(PriorityQueueMMA* Q,ERRVAL_T* Errval);

/** \brief Returns the max-item (in regards to the comparison-function) of the Advanced Min-Max-PriorityQueue or NULL.
*
* \param *Q The Advanced Min-Max-PriorityQueue whose max-item should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

void* PriorityQueueMMA_GetMax(PriorityQueueMMA* Q,ERRVAL_T* Errval);

/** \brief Returns the PriorityQueueMMAItem of the min-item (in regards to the comparison-function) of the Advanced Min-Max-PriorityQueue or NULL.
*
* \param *Q The Advanced Min-Max-PriorityQueue whose PriorityQueueMMAItem of the min-item should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

PriorityQueueMMAItem* PriorityQueueMMA_GetMinItem(PriorityQueueMMA* Q,ERRVAL_T* Errval);

/** \brief Returns the PriorityQueueMMAItem of the max-item (in regards to the comparison-function) of the Advanced Min-Max-PriorityQueue or NULL.
*
* \param *Q The Advanced Min-Max-PriorityQueue whose PriorityQueueMMAItem of the max-item should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

PriorityQueueMMAItem* PriorityQueueMMA_GetMaxItem(PriorityQueueMMA* Q,ERRVAL_T* Errval);

/** \brief Inserts a new item into the Advanced Min-Max-PriorityQueue. The item has to be of a valid type (the type the comparison-function works with) otherwise the behavior is undefined.
*
* \param *Q The Advanced Min-Max-PriorityQueue in which the item should be inserted.
* \param *Item The item that should be inserted. Has to be of the type the comparison-function works with.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMA_Insert(PriorityQueueMMA* Q,void* Item,ERRVAL_T* Errval);

/** \brief Inserts a new item into the Advanced Min-Max-PriorityQueue and returns the PriorityQueueMMAItem of that item. The item has to be of a valid type (the type the comparison-function works with) otherwise the behavior is undefined.
*
* \param *Q The Advanced Min-Max-PriorityQueue in which the item should be inserted.
* \param *Item The item that should be inserted. Has to be of the type the comparison-function works with.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

PriorityQueueMMAItem* PriorityQueueMMA_GetInsertedItem(PriorityQueueMMA* Q,void* Item,ERRVAL_T* Errval);

/** \brief Returns the actual item of the PriorityQueueMMAItem in the Advanced Min-Max-PriorityQueue. The PriorityQueueMMAItem has to be an actual item of the PriorityQueue.
*
* \param *Q The Advanced Min-Max-PriorityQueue that contains the PriorityQueueMMAItem.
* \param *Item The PriorityQueueMMAItem whose actual item should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

void* PriorityQueueMMA_GetItemOfItem(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval);

/** \brief Sets the actual item of the PriorityQueueMMAItem to "ItemValue" and adjusts the position of the PriorityQueueMMAItem.
*
* \param *Q The Advanced Min-Max-PriorityQueue that has to contain the PriorityQueueMMAItem.
* \param *Item The PriorityQueueMMAItem whose actual item should be set. Has to be a valid member of the PriorityQueue.
* \param *ItemValue The actual item the PriorityQueueMMAItem should now have as its' actual item. Has to be of the type the comparison-function works with.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMA_SetItemOfItem(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,void* ItemValue,ERRVAL_T* Errval);

/** \brief Returns "1" if the PriorityQueueMMAItem is actually in the Advanced Min-Max-PriorityQueue or "0" otherwise.
*
* \param *Q The Advanced Min-Max-PriorityQueue that should be checked whether it contains the PriorityQueueMMAItem.
* \param *Item The PriorityQueueMMAItem that should be checked.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMA_ContainsItem(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval);

/** \brief Updates the position of the PriorityQueueMMAItem in the Advanced Min-Max-PriorityQueue. Should (and HAS TO) be called if attributes of the actual item of the PriorityQueueMMAItem that influence the comparison function have changed.
*
* \param *Q The Advanced Min-Max-PriorityQueue that has to contain the PriorityQueueMMAItem.
* \param *Item The PriorityQueueMMAItem whose attributes of the actual item have changed. Has to be a valid member of the PriorityQueue.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMA_UpdateItem(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval);

/** \brief Removes the min-item of the Advanced Min-Max-PriorityQueue without freeing its' the resources.
*
* \param *Q The Advanced Min-Max-PriorityQueue whose min-item should be removed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMA_RemoveMin(PriorityQueueMMA* Q,ERRVAL_T* Errval);

/** \brief Removes the max-item of the Advanced Min-Max-PriorityQueue without freeing its' the resources.
*
* \param *Q The Advanced Min-Max-PriorityQueue whose max-item should be removed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMA_RemoveMax(PriorityQueueMMA* Q,ERRVAL_T* Errval);

/** \brief Removes the PriorityQueueMMAItem from the Advanced Min-Max-PriorityQueue without freeing its' the resources. The PriorityQueueMMAItem has to be an actual item of the PriorityQueue.
*
* \param *Q The Advanced Min-Max-PriorityQueue the PriorityQueueMMAItem should be removed from.
* \param *Item The PriorityQueueMMAItem that should be removed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMA_RemoveItem(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval);

/** \brief Removes the min-item of the Advanced Min-Max-PriorityQueue and frees its' resources.
*
* \param *Q The Advanced Min-Max-PriorityQueue whose min-item should be removed and freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMA_RemoveMinSource(PriorityQueueMMA* Q,ERRVAL_T* Errval);

/** \brief Removes the max-item of the Advanced Min-Max-PriorityQueue and frees its' resources.
*
* \param *Q The Advanced Min-Max-PriorityQueue whose max-item should be removed and freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMA_RemoveMaxSource(PriorityQueueMMA* Q,ERRVAL_T* Errval);

/** \brief Removes the PriorityQueueMMAItem from the Advanced Min-Max-PriorityQueue and frees its' resources. The PriorityQueueMMAItem has to be an actual item of the PriorityQueue.
*
* \param *Q The Advanced Min-Max-PriorityQueue the PriorityQueueMMAItem should be removed from and whose actual item should also be freed.
* \param *Item The PriorityQueueMMAItem that should be removed and whose actual item should also be freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMA_RemoveItemSource(PriorityQueueMMA* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval);

/** \brief Removes all items of the Advanced Min-Max-PriorityQueue without freeing their resources.
*
* \param *Q The Advanced Min-Max-PriorityQueue whose items should be removed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMA_Clear(PriorityQueueMMA* Q,ERRVAL_T* Errval);

/** \brief Removes all items of the Advanced Min-Max-PriorityQueue and frees their resources.
*
* \param *Q The Advanced Min-Max-PriorityQueue whose items should be removed and freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMA_ClearSource(PriorityQueueMMA* Q,ERRVAL_T* Errval);

/** \brief Frees the Advanced Min-Max-PriorityQueue without freeing its' items.
*
* \param *Q The Advanced Min-Max-PriorityQueue that should be freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMA_Dispose(PriorityQueueMMA* Q,ERRVAL_T* Errval);

/** \brief Frees the Advanced Min-Max-PriorityQueue and its' items.
*
* \param *Q The Advanced Min-Max-PriorityQueue that should be freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMA_DisposeSource(PriorityQueueMMA* Q,ERRVAL_T* Errval);
#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMA
#endif // PRIORITYQUEUEMM_INHERITANCE


#ifdef INCLUDE_PRIORITYQUEUEMMSF

#ifdef PRIORITYQUEUEMM_INHERITANCE
/** \brief Returns the "PriorityQueueMM" (the generalized type all other Min-Max-PriorityQueues are underlying types of).
*
* \param *Q The Simple, Fixed-Size Min-Max-PriorityQueue whose "PriorityQueueMM" should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

PriorityQueueMM* PriorityQueueMMSF_Get_PriorityQueueMM(PriorityQueueMMSF* Q,ERRVAL_T* Errval);
#endif // PRIORITYQUEUEMM_INHERITANCE

/** \brief Returns the necessary size for a Simple, Fixed-Size Min-Max-PriorityQueue with the specified number of items.
*
* \param ItemCount The number of items the Min-Max-PriorityQueue should be able to contain.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

size_t PriorityQueueMMSF_GetSizeFor(uint16_t ItemCount,ERRVAL_T* Errval);

/** \brief Returns the possible number of items a Simple, Fixed-Size Min-Max-PriorityQueue of the specified size could contain.
*
* \param Size The available size for the Min-Max-PriorityQueue.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

uint16_t PriorityQueueMMSF_GetItemCountForSize(size_t Size,ERRVAL_T* Errval);

/** \brief Returns the number of items the Simple, Fixed-Size Min-Max-PriorityQueue currently contains.
*
* \param *Q The Simple, Fixed-Size Min-Max-PriorityQueue whose number of items should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMSF_GetCount(PriorityQueueMMSF* Q,ERRVAL_T* Errval);

/** \brief Returns the maximum number of items this Simple, Fixed-Size Min-Max-PriorityQueue can contain.
*
* \param *Q The Simple, Fixed-Size Min-Max-PriorityQueue whose maximum item-count should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMSF_GetReservedItems(PriorityQueueMMSF* Q,ERRVAL_T* Errval);

/** \brief Returns the total size of the memory reserved for this data-structure.
*
* \param *Q The Simple, Fixed-Size Min-Max-PriorityQueue whose total size of reserved memory should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

size_t PriorityQueueMMSF_GetReservedMemory(PriorityQueueMMSF* Q,ERRVAL_T* Errval);

/** \brief Returns the min-item (in regards to the comparison-function) of the Simple, Fixed-Size Min-Max-PriorityQueue or NULL.
*
* \param *Q The Simple, Fixed-Size Min-Max-PriorityQueue whose min-item should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

void* PriorityQueueMMSF_GetMin(PriorityQueueMMSF* Q,ERRVAL_T* Errval);

/** \brief Returns the max-item (in regards to the comparison-function) of the Simple, Fixed-Size Min-Max-PriorityQueue or NULL.
*
* \param *Q The Simple, Fixed-Size Min-Max-PriorityQueue whose max-item should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

void* PriorityQueueMMSF_GetMax(PriorityQueueMMSF* Q,ERRVAL_T* Errval);

/** \brief Inserts a new item into the Simple, Fixed-Size Min-Max-PriorityQueue. The item has to be of a valid type (the type the comparison-function works with) otherwise the behavior is undefined.
*
* \param *Q The Simple, Fixed-Size Min-Max-PriorityQueue in which the item should be inserted.
* \param *Item The item that should be inserted. Has to be of the type the comparison-function works with.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMSF_Insert(PriorityQueueMMSF* Q,void* Item,ERRVAL_T* Errval);

/** \brief Removes the min-item of the Simple, Fixed-Size Min-Max-PriorityQueue without freeing its' the resources.
*
* \param *Q The Simple, Fixed-Size Min-Max-PriorityQueue whose min-item should be removed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMSF_RemoveMin(PriorityQueueMMSF* Q,ERRVAL_T* Errval);

/** \brief Removes the max-item of the Simple, Fixed-Size Min-Max-PriorityQueue without freeing its' the resources.
*
* \param *Q The Simple, Fixed-Size Min-Max-PriorityQueue whose max-item should be removed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMSF_RemoveMax(PriorityQueueMMSF* Q,ERRVAL_T* Errval);

/** \brief Removes the min-item of the Simple, Fixed-Size Min-Max-PriorityQueue and frees its' resources.
*
* \param *Q The Simple, Fixed-Size Min-Max-PriorityQueue whose min-item should be removed and freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMSF_RemoveMinSource(PriorityQueueMMSF* Q,ERRVAL_T* Errval);

/** \brief Removes the max-item of the Simple, Fixed-Size Min-Max-PriorityQueue and frees its' resources.
*
* \param *Q The Simple, Fixed-Size Min-Max-PriorityQueue whose max-item should be removed and freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMSF_RemoveMaxSource(PriorityQueueMMSF* Q,ERRVAL_T* Errval);

/** \brief Removes all items of the Simple, Fixed-Size Min-Max-PriorityQueue without freeing their resources.
*
* \param *Q The Simple, Fixed-Size Min-Max-PriorityQueue whose items should be removed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMSF_Clear(PriorityQueueMMSF* Q,ERRVAL_T* Errval);

/** \brief Removes all items of the Simple, Fixed-Size Min-Max-PriorityQueue and frees their resources.
*
* \param *Q The Simple, Fixed-Size Min-Max-PriorityQueue whose items should be removed and freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMSF_ClearSource(PriorityQueueMMSF* Q,ERRVAL_T* Errval);

/** \brief Frees the Simple, Fixed-Size Min-Max-PriorityQueue without freeing its' items.
*
* \param *Q The Simple, Fixed-Size Min-Max-PriorityQueue that should be freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMSF_Dispose(PriorityQueueMMSF* Q,ERRVAL_T* Errval);

/** \brief Frees the Simple, Fixed-Size Min-Max-PriorityQueue and its' items.
*
* \param *Q The Simple, Fixed-Size Min-Max-PriorityQueue that should be freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMSF_DisposeSource(PriorityQueueMMSF* Q,ERRVAL_T* Errval);
#endif // INCLUDE_PRIORITYQUEUEMMSF


#ifdef INCLUDE_PRIORITYQUEUEMMAF

#ifdef PRIORITYQUEUEMM_INHERITANCE
/** \brief Returns the "PriorityQueueMM" (the generalized type all other Min-Max-PriorityQueues are underlying types of).
*
* \param *Q The Advanced, Fixed-Size Min-Max-PriorityQueue whose "PriorityQueueMM" should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

PriorityQueueMM* PriorityQueueMMAF_Get_PriorityQueueMM(PriorityQueueMMAF* Q,ERRVAL_T* Errval);

#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMA
/** \brief Returns the "PriorityQueueMMA" (the generalized type all other Advanced Min-Max-PriorityQueues are underlying types of).
*
* \param *Q The Advanced, Fixed-Size Min-Max-PriorityQueue whose "PriorityQueueMMA" should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

PriorityQueueMMA* PriorityQueueMMAF_Get_PriorityQueueMMA(PriorityQueueMMAF* Q,ERRVAL_T* Errval);
#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMA
#endif // PRIORITYQUEUEMM_INHERITANCE

/** \brief Returns the necessary size for an Advanced, Fixed-Size Min-Max-PriorityQueue with the specified number of items.
*
* \param ItemCount The number of items the Min-Max-PriorityQueue should be able to contain.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

size_t PriorityQueueMMAF_GetSizeFor(uint16_t ItemCount,ERRVAL_T* Errval);

/** \brief Returns the possible number of items an Advanced, Fixed-Size Min-Max-PriorityQueue of the specified size could contain.
*
* \param Size The available size for the Min-Max-PriorityQueue.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

uint16_t PriorityQueueMMAF_GetItemCountForSize(size_t Size,ERRVAL_T* Errval);

/** \brief Returns the number of items the Advanced, Fixed-Size Min-Max-PriorityQueue currently contains.
*
* \param *Q The Advanced, Fixed-Size Min-Max-PriorityQueue whose number of items should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAF_GetCount(PriorityQueueMMAF* Q,ERRVAL_T* Errval);

/** \brief Returns the maximum number of items this Advanced, Fixed-Size Min-Max-PriorityQueue can contain.
*
* \param *Q The Advanced, Fixed-Size Min-Max-PriorityQueue whose maximum item-count should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAF_GetReservedItems(PriorityQueueMMAF* Q,ERRVAL_T* Errval);

/** \brief Returns the total size of the memory reserved for this data-structure.
*
* \param *Q The Advanced, Fixed-Size Min-Max-PriorityQueue whose total size of reserved memory should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

size_t PriorityQueueMMAF_GetReservedMemory(PriorityQueueMMAF* Q,ERRVAL_T* Errval);

/** \brief Returns the min-item (in regards to the comparison-function) of the Advanced, Fixed-Size Min-Max-PriorityQueue or NULL.
*
* \param *Q The Advanced, Fixed-Size Min-Max-PriorityQueue whose min-item should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

void* PriorityQueueMMAF_GetMin(PriorityQueueMMAF* Q,ERRVAL_T* Errval);

/** \brief Returns the max-item (in regards to the comparison-function) of the Advanced, Fixed-Size Min-Max-PriorityQueue or NULL.
*
* \param *Q The Advanced, Fixed-Size Min-Max-PriorityQueue whose max-item should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

void* PriorityQueueMMAF_GetMax(PriorityQueueMMAF* Q,ERRVAL_T* Errval);

/** \brief Returns the PriorityQueueMMAItem of the min-item (in regards to the comparison-function) of the Advanced, Fixed-Size Min-Max-PriorityQueue or NULL.
*
* \param *Q The Advanced, Fixed-Size Min-Max-PriorityQueue whose PriorityQueueMMAItem of the min-item should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

PriorityQueueMMAItem* PriorityQueueMMAF_GetMinItem(PriorityQueueMMAF* Q,ERRVAL_T* Errval);

/** \brief Returns the PriorityQueueMMAItem of the max-item (in regards to the comparison-function) of the Advanced, Fixed-Size Min-Max-PriorityQueue or NULL.
*
* \param *Q The Advanced, Fixed-Size Min-Max-PriorityQueue whose PriorityQueueMMAItem of the max-item should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

PriorityQueueMMAItem* PriorityQueueMMAF_GetMaxItem(PriorityQueueMMAF* Q,ERRVAL_T* Errval);

/** \brief Inserts a new item into the Advanced, Fixed-Size Min-Max-PriorityQueue. The item has to be of a valid type (the type the comparison-function works with) otherwise the behavior is undefined.
*
* \param *Q The Advanced, Fixed-Size Min-Max-PriorityQueue in which the item should be inserted.
* \param *Item The item that should be inserted. Has to be of the type the comparison-function works with.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAF_Insert(PriorityQueueMMAF* Q,void* Item,ERRVAL_T* Errval);

/** \brief Inserts a new item into the Advanced, Fixed-Size Min-Max-PriorityQueue and returns the PriorityQueueMMAItem of that item. The item has to be of a valid type (the type the comparison-function works with) otherwise the behavior is undefined.
*
* \param *Q The Advanced, Fixed-Size Min-Max-PriorityQueue in which the item should be inserted.
* \param *Item The item that should be inserted. Has to be of the type the comparison-function works with.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

PriorityQueueMMAItem* PriorityQueueMMAF_GetInsertedItem(PriorityQueueMMAF* Q,void* Item,ERRVAL_T* Errval);

/** \brief Returns the actual item of the PriorityQueueMMAItem in the Advanced, Fixed-Size Min-Max-PriorityQueue. The PriorityQueueMMAItem has to be an actual item of the PriorityQueue.
*
* \param *Q The Advanced, Fixed-Size Min-Max-PriorityQueue that contains the PriorityQueueMMAItem.
* \param *Item The PriorityQueueMMAItem whose actual item should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

void* PriorityQueueMMAF_GetItemOfItem(PriorityQueueMMAF* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval);

/** \brief Sets the actual item of the PriorityQueueMMAItem to "ItemValue" and adjusts the position of the PriorityQueueMMAItem.
*
* \param *Q The Advanced, Fixed-Size Min-Max-PriorityQueue that has to contain the PriorityQueueMMAItem.
* \param *Item The PriorityQueueMMAItem whose actual item should be set. Has to be a valid member of the PriorityQueue.
* \param *ItemValue The actual item the PriorityQueueMMAItem should now have as its' actual item. Has to be of the type the comparison-function works with.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAF_SetItemOfItem(PriorityQueueMMAF* Q,PriorityQueueMMAItem* Item,void* ItemValue,ERRVAL_T* Errval);

/** \brief Returns "1" if the PriorityQueueMMAItem is actually in the Advanced, Fixed-Size Min-Max-PriorityQueue or "0" otherwise.
*
* \param *Q The Advanced, Fixed-Size Min-Max-PriorityQueue that should be checked whether it contains the PriorityQueueMMAItem.
* \param *Item The PriorityQueueMMAItem that should be checked.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAF_ContainsItem(PriorityQueueMMAF* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval);

/** \brief Updates the position of the PriorityQueueMMAItem in the Advanced, Fixed-Size Min-Max-PriorityQueue. Should (and HAS TO) be called if attributes of the actual item of the PriorityQueueMMAItem that influence the comparison function have changed.
*
* \param *Q The Advanced, Fixed-Size Min-Max-PriorityQueue that has to contain the PriorityQueueMMAItem.
* \param *Item The PriorityQueueMMAItem whose attributes of the actual item have changed. Has to be a valid member of the PriorityQueue.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAF_UpdateItem(PriorityQueueMMAF* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval);

/** \brief Removes the min-item of the Advanced, Fixed-Size Min-Max-PriorityQueue without freeing its' the resources.
*
* \param *Q The Advanced, Fixed-Size Min-Max-PriorityQueue whose min-item should be removed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAF_RemoveMin(PriorityQueueMMAF* Q,ERRVAL_T* Errval);

/** \brief Removes the max-item of the Advanced, Fixed-Size Min-Max-PriorityQueue without freeing its' the resources.
*
* \param *Q The Advanced, Fixed-Size Min-Max-PriorityQueue whose max-item should be removed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAF_RemoveMax(PriorityQueueMMAF* Q,ERRVAL_T* Errval);

/** \brief Removes the PriorityQueueMMAItem from the Advanced, Fixed-Size Min-Max-PriorityQueue without freeing its' the resources. The PriorityQueueMMAItem has to be an actual item of the PriorityQueue.
*
* \param *Q The Advanced, Fixed-Size Min-Max-PriorityQueue the PriorityQueueMMAItem should be removed from.
* \param *Item The PriorityQueueMMAItem that should be removed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAF_RemoveItem(PriorityQueueMMAF* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval);

/** \brief Removes the min-item of the Advanced, Fixed-Size Min-Max-PriorityQueue and frees its' resources.
*
* \param *Q The Advanced, Fixed-Size Min-Max-PriorityQueue whose min-item should be removed and freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAF_RemoveMinSource(PriorityQueueMMAF* Q,ERRVAL_T* Errval);

/** \brief Removes the max-item of the Advanced, Fixed-Size Min-Max-PriorityQueue and frees its' resources.
*
* \param *Q The Advanced, Fixed-Size Min-Max-PriorityQueue whose max-item should be removed and freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAF_RemoveMaxSource(PriorityQueueMMAF* Q,ERRVAL_T* Errval);

/** \brief Removes the PriorityQueueMMAItem from the Advanced, Fixed-Size Min-Max-PriorityQueue and frees its' resources. The PriorityQueueMMAItem has to be an actual item of the PriorityQueue.
*
* \param *Q The Advanced, Fixed-Size Min-Max-PriorityQueue the PriorityQueueMMAItem should be removed from and whose actual item should also be freed.
* \param *Item The PriorityQueueMMAItem that should be removed and whose actual item should also be freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAF_RemoveItemSource(PriorityQueueMMAF* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval);

/** \brief Removes all items of the Advanced, Fixed-Size Min-Max-PriorityQueue without freeing their resources.
*
* \param *Q The Advanced, Fixed-Size Min-Max-PriorityQueue whose items should be removed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAF_Clear(PriorityQueueMMAF* Q,ERRVAL_T* Errval);

/** \brief Removes all items of the Advanced, Fixed-Size Min-Max-PriorityQueue and frees their resources.
*
* \param *Q The Advanced, Fixed-Size Min-Max-PriorityQueue whose items should be removed and freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAF_ClearSource(PriorityQueueMMAF* Q,ERRVAL_T* Errval);

/** \brief Frees the Advanced, Fixed-Size Min-Max-PriorityQueue without freeing its' items.
*
* \param *Q The Advanced, Fixed-Size Min-Max-PriorityQueue that should be freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAF_Dispose(PriorityQueueMMAF* Q,ERRVAL_T* Errval);

/** \brief Frees the Advanced, Fixed-Size Min-Max-PriorityQueue and its' items.
*
* \param *Q The Advanced, Fixed-Size Min-Max-PriorityQueue that should be freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAF_DisposeSource(PriorityQueueMMAF* Q,ERRVAL_T* Errval);
#endif // INCLUDE_PRIORITYQUEUEMMAF


#ifdef INCLUDE_PRIORITYQUEUEMMSD

#ifdef PRIORITYQUEUEMM_INHERITANCE
/** \brief Returns the "PriorityQueueMM" (the generalized type all other Min-Max-PriorityQueues are underlying types of).
*
* \param *Q The Simple, Dynamic-Size Min-Max-PriorityQueue whose "PriorityQueueMM" should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

PriorityQueueMM* PriorityQueueMMSD_Get_PriorityQueueMM(PriorityQueueMMSD* Q,ERRVAL_T* Errval);
#endif // PRIORITYQUEUEMM_INHERITANCE

/** \brief Returns the number of items the Simple, Dynamic-Size Min-Max-PriorityQueue currently contains.
*
* \param *Q The Simple, Dynamic-Size Min-Max-PriorityQueue whose number of items should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMSD_GetCount(PriorityQueueMMSD* Q,ERRVAL_T* Errval);

/** \brief Returns the number of items this Simple, Dynamic-Size Min-Max-PriorityQueue can currently contain without reserving additional memory.
*
* \param *Q The Simple, Dynamic-Size Min-Max-PriorityQueue whose reserved item-count should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMSD_GetReservedItems(PriorityQueueMMSD* Q,ERRVAL_T* Errval);

/** \brief Returns the total size of the memory currently reserved for this data-structure.
*
* \param *Q The Simple, Dynamic-Size Min-Max-PriorityQueue whose current total size of reserved memory should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

size_t PriorityQueueMMSD_GetReservedMemory(PriorityQueueMMSD* Q,ERRVAL_T* Errval);

/** \brief Returns the min-item (in regards to the comparison-function) of the Simple, Dynamic-Size Min-Max-PriorityQueue or NULL.
*
* \param *Q The Simple, Dynamic-Size Min-Max-PriorityQueue whose min-item should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

void* PriorityQueueMMSD_GetMin(PriorityQueueMMSD* Q,ERRVAL_T* Errval);

/** \brief Returns the max-item (in regards to the comparison-function) of the Simple, Dynamic-Size Min-Max-PriorityQueue or NULL.
*
* \param *Q The Simple, Dynamic-Size Min-Max-PriorityQueue whose max-item should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

void* PriorityQueueMMSD_GetMax(PriorityQueueMMSD* Q,ERRVAL_T* Errval);

/** \brief Inserts a new item into the Simple, Dynamic-Size Min-Max-PriorityQueue. The item has to be of a valid type (the type the comparison-function works with) otherwise the behavior is undefined.
*
* \param *Q The Simple, Dynamic-Size Min-Max-PriorityQueue in which the item should be inserted.
* \param *Item The item that should be inserted. Has to be of the type the comparison-function works with.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMSD_Insert(PriorityQueueMMSD* Q,void* Item,ERRVAL_T* Errval);

/** \brief Removes the min-item of the Simple, Dynamic-Size Min-Max-PriorityQueue without freeing its' the resources.
*
* \param *Q The Simple, Dynamic-Size Min-Max-PriorityQueue whose min-item should be removed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMSD_RemoveMin(PriorityQueueMMSD* Q,ERRVAL_T* Errval);

/** \brief Removes the max-item of the Simple, Dynamic-Size Min-Max-PriorityQueue without freeing its' the resources.
*
* \param *Q The Simple, Dynamic-Size Min-Max-PriorityQueue whose max-item should be removed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMSD_RemoveMax(PriorityQueueMMSD* Q,ERRVAL_T* Errval);

/** \brief Removes the min-item of the Simple, Dynamic-Size Min-Max-PriorityQueue and frees its' resources.
*
* \param *Q The Simple, Dynamic-Size Min-Max-PriorityQueue whose min-item should be removed and freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMSD_RemoveMinSource(PriorityQueueMMSD* Q,ERRVAL_T* Errval);

/** \brief Removes the max-item of the Simple, Dynamic-Size Min-Max-PriorityQueue and frees its' resources.
*
* \param *Q The Simple, Dynamic-Size Min-Max-PriorityQueue whose max-item should be removed and freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMSD_RemoveMaxSource(PriorityQueueMMSD* Q,ERRVAL_T* Errval);

/** \brief Removes all items of the Simple, Dynamic-Size Min-Max-PriorityQueue without freeing their resources.
*
* \param *Q The Simple, Dynamic-Size Min-Max-PriorityQueue whose items should be removed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMSD_Clear(PriorityQueueMMSD* Q,ERRVAL_T* Errval);

/** \brief Removes all items of the Simple, Dynamic-Size Min-Max-PriorityQueue and frees their resources.
*
* \param *Q The Simple, Dynamic-Size Min-Max-PriorityQueue whose items should be removed and freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMSD_ClearSource(PriorityQueueMMSD* Q,ERRVAL_T* Errval);

/** \brief Frees the Simple, Dynamic-Size Min-Max-PriorityQueue without freeing its' items.
*
* \param *Q The Simple, Dynamic-Size Min-Max-PriorityQueue that should be freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMSD_Dispose(PriorityQueueMMSD* Q,ERRVAL_T* Errval);

/** \brief Frees the Simple, Dynamic-Size Min-Max-PriorityQueue and its' items.
*
* \param *Q The Simple, Dynamic-Size Min-Max-PriorityQueue that should be freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMSD_DisposeSource(PriorityQueueMMSD* Q,ERRVAL_T* Errval);
#endif // INCLUDE_PRIORITYQUEUEMMSD


#ifdef INCLUDE_PRIORITYQUEUEMMAD

#ifdef PRIORITYQUEUEMM_INHERITANCE
/** \brief Returns the "PriorityQueueMM" (the generalized type all other Min-Max-PriorityQueues are underlying types of).
*
* \param *Q The Advanced, Dynamic-Size Min-Max-PriorityQueue whose "PriorityQueueMM" should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

PriorityQueueMM* PriorityQueueMMAD_Get_PriorityQueueMM(PriorityQueueMMAD* Q,ERRVAL_T* Errval);

#ifdef INCLUDE_STRUCT_PRIORITYQUEUEMMA
/** \brief Returns the "PriorityQueueMMA" (the generalized type all other Advanced Min-Max-PriorityQueues are underlying types of).
*
* \param *Q The Advanced, Dynamic-Size Min-Max-PriorityQueue whose "PriorityQueueMMA" should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

PriorityQueueMMA* PriorityQueueMMAD_Get_PriorityQueueMMA(PriorityQueueMMAD* Q,ERRVAL_T* Errval);
#endif // INCLUDE_STRUCT_PRIORITYQUEUEMMA
#endif // PRIORITYQUEUEMM_INHERITANCE

/** \brief Returns the number of items the Advanced, Dynamic-Size Min-Max-PriorityQueue currently contains.
*
* \param *Q The Advanced, Dynamic-Size Min-Max-PriorityQueue whose number of items should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAD_GetCount(PriorityQueueMMAD* Q,ERRVAL_T* Errval);

/** \brief Returns the number of items this Advanced, Dynamic-Size Min-Max-PriorityQueue can currently contain without reserving additional memory.
*
* \param *Q The Advanced, Dynamic-Size Min-Max-PriorityQueue whose reserved item-count should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAD_GetReservedItems(PriorityQueueMMAD* Q,ERRVAL_T* Errval);

/** \brief Returns the total size of the memory currently reserved for this data-structure.
*
* \param *Q The Advanced, Dynamic-Size Min-Max-PriorityQueue whose current total size of reserved memory should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

size_t PriorityQueueMMAD_GetReservedMemory(PriorityQueueMMAD* Q,ERRVAL_T* Errval);

/** \brief Returns the min-item (in regards to the comparison-function) of the Advanced, Dynamic-Size Min-Max-PriorityQueue or NULL.
*
* \param *Q The Advanced, Dynamic-Size Min-Max-PriorityQueue whose min-item should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

void* PriorityQueueMMAD_GetMin(PriorityQueueMMAD* Q,ERRVAL_T* Errval);

/** \brief Returns the max-item (in regards to the comparison-function) of the Advanced, Dynamic-Size Min-Max-PriorityQueue or NULL.
*
* \param *Q The Advanced, Dynamic-Size Min-Max-PriorityQueue whose max-item should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

void* PriorityQueueMMAD_GetMax(PriorityQueueMMAD* Q,ERRVAL_T* Errval);

/** \brief Returns the PriorityQueueMMAItem of the min-item (in regards to the comparison-function) of the Advanced, Dynamic-Size Min-Max-PriorityQueue or NULL.
*
* \param *Q The Advanced, Dynamic-Size Min-Max-PriorityQueue whose PriorityQueueMMAItem of the min-item should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

PriorityQueueMMAItem* PriorityQueueMMAD_GetMinItem(PriorityQueueMMAD* Q,ERRVAL_T* Errval);

/** \brief Returns the PriorityQueueMMAItem of the max-item (in regards to the comparison-function) of the Advanced, Dynamic-Size Min-Max-PriorityQueue or NULL.
*
* \param *Q The Advanced, Dynamic-Size Min-Max-PriorityQueue whose PriorityQueueMMAItem of the max-item should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

PriorityQueueMMAItem* PriorityQueueMMAD_GetMaxItem(PriorityQueueMMAD* Q,ERRVAL_T* Errval);

/** \brief Inserts a new item into the Advanced, Dynamic-Size Min-Max-PriorityQueue. The item has to be of a valid type (the type the comparison-function works with) otherwise the behavior is undefined.
*
* \param *Q The Advanced, Dynamic-Size Min-Max-PriorityQueue in which the item should be inserted.
* \param *Item The item that should be inserted. Has to be of the type the comparison-function works with.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAD_Insert(PriorityQueueMMAD* Q,void* Item,ERRVAL_T* Errval);

/** \brief Inserts a new item into the Advanced, Dynamic-Size Min-Max-PriorityQueue and returns the PriorityQueueMMAItem of that item. The item has to be of a valid type (the type the comparison-function works with) otherwise the behavior is undefined.
*
* \param *Q The Advanced, Dynamic-Size Min-Max-PriorityQueue in which the item should be inserted.
* \param *Item The item that should be inserted. Has to be of the type the comparison-function works with.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

PriorityQueueMMAItem* PriorityQueueMMAD_GetInsertedItem(PriorityQueueMMAD* Q,void* Item,ERRVAL_T* Errval);

/** \brief Returns the actual item of the PriorityQueueMMAItem in the Advanced, Dynamic-Size Min-Max-PriorityQueue. The PriorityQueueMMAItem has to be an actual item of the PriorityQueue.
*
* \param *Q The Advanced, Dynamic-Size Min-Max-PriorityQueue that contains the PriorityQueueMMAItem.
* \param *Item The PriorityQueueMMAItem whose actual item should be returned.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

void* PriorityQueueMMAD_GetItemOfItem(PriorityQueueMMAD* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval);

/** \brief Sets the actual item of the PriorityQueueMMAItem to "ItemValue" and adjusts the position of the PriorityQueueMMAItem.
*
* \param *Q The Advanced, Dynamic-Size Min-Max-PriorityQueue that has to contain the PriorityQueueMMAItem.
* \param *Item The PriorityQueueMMAItem whose actual item should be set. Has to be a valid member of the PriorityQueue.
* \param *ItemValue The actual item the PriorityQueueMMAItem should now have as its' actual item. Has to be of the type the comparison-function works with.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAD_SetItemOfItem(PriorityQueueMMAD* Q,PriorityQueueMMAItem* Item,void* ItemValue,ERRVAL_T* Errval);

/** \brief Returns "1" if the PriorityQueueMMAItem is actually in the Advanced, Dynamic-Size Min-Max-PriorityQueue or "0" otherwise.
*
* \param *Q The Advanced, Dynamic-Size Min-Max-PriorityQueue that should be checked whether it contains the PriorityQueueMMAItem.
* \param *Item The PriorityQueueMMAItem that should be checked.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAD_ContainsItem(PriorityQueueMMAD* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval);

/** \brief Updates the position of the PriorityQueueMMAItem in the Advanced, Dynamic-Size Min-Max-PriorityQueue. Should (and HAS TO) be called if attributes of the actual item of the PriorityQueueMMAItem that influence the comparison function have changed.
*
* \param *Q The Advanced, Dynamic-Size Min-Max-PriorityQueue that has to contain the PriorityQueueMMAItem.
* \param *Item The PriorityQueueMMAItem whose attributes of the actual item have changed. Has to be a valid member of the PriorityQueue.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAD_UpdateItem(PriorityQueueMMAD* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval);

/** \brief Removes the min-item of the Advanced, Dynamic-Size Min-Max-PriorityQueue without freeing its' the resources.
*
* \param *Q The Advanced, Dynamic-Size Min-Max-PriorityQueue whose min-item should be removed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAD_RemoveMin(PriorityQueueMMAD* Q,ERRVAL_T* Errval);

/** \brief Removes the max-item of the Advanced, Dynamic-Size Min-Max-PriorityQueue without freeing its' the resources.
*
* \param *Q The Advanced, Dynamic-Size Min-Max-PriorityQueue whose max-item should be removed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAD_RemoveMax(PriorityQueueMMAD* Q,ERRVAL_T* Errval);

/** \brief Removes the PriorityQueueMMAItem from the Advanced, Dynamic-Size Min-Max-PriorityQueue without freeing its' the resources. The PriorityQueueMMAItem has to be an actual item of the PriorityQueue.
*
* \param *Q The Advanced, Dynamic-Size Min-Max-PriorityQueue the PriorityQueueMMAItem should be removed from.
* \param *Item The PriorityQueueMMAItem that should be removed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAD_RemoveItem(PriorityQueueMMAD* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval);

/** \brief Removes the min-item of the Advanced, Dynamic-Size Min-Max-PriorityQueue and frees its' resources.
*
* \param *Q The Advanced, Dynamic-Size Min-Max-PriorityQueue whose min-item should be removed and freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAD_RemoveMinSource(PriorityQueueMMAD* Q,ERRVAL_T* Errval);

/** \brief Removes the max-item of the Advanced, Dynamic-Size Min-Max-PriorityQueue and frees its' resources.
*
* \param *Q The Advanced, Dynamic-Size Min-Max-PriorityQueue whose max-item should be removed and freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAD_RemoveMaxSource(PriorityQueueMMAD* Q,ERRVAL_T* Errval);

/** \brief Removes the PriorityQueueMMAItem from the Advanced, Dynamic-Size Min-Max-PriorityQueue and frees its' resources. The PriorityQueueMMAItem has to be an actual item of the PriorityQueue.
*
* \param *Q The Advanced, Dynamic-Size Min-Max-PriorityQueue the PriorityQueueMMAItem should be removed from and whose actual item should also be freed.
* \param *Item The PriorityQueueMMAItem that should be removed and whose actual item should also be freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAD_RemoveItemSource(PriorityQueueMMAD* Q,PriorityQueueMMAItem* Item,ERRVAL_T* Errval);

/** \brief Removes all items of the Advanced, Dynamic-Size Min-Max-PriorityQueue without freeing their resources.
*
* \param *Q The Advanced, Dynamic-Size Min-Max-PriorityQueue whose items should be removed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAD_Clear(PriorityQueueMMAD* Q,ERRVAL_T* Errval);

/** \brief Removes all items of the Advanced, Dynamic-Size Min-Max-PriorityQueue and frees their resources.
*
* \param *Q The Advanced, Dynamic-Size Min-Max-PriorityQueue whose items should be removed and freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAD_ClearSource(PriorityQueueMMAD* Q,ERRVAL_T* Errval);

/** \brief Frees the Advanced, Dynamic-Size Min-Max-PriorityQueue without freeing its' items.
*
* \param *Q The Advanced, Dynamic-Size Min-Max-PriorityQueue that should be freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAD_Dispose(PriorityQueueMMAD* Q,ERRVAL_T* Errval);

/** \brief Frees the Advanced, Dynamic-Size Min-Max-PriorityQueue and its' items.
*
* \param *Q The Advanced, Dynamic-Size Min-Max-PriorityQueue that should be freed.
* \param *Errval Is set to a value that indicates the error if an error occurred. Can be NULL.
*/

int PriorityQueueMMAD_DisposeSource(PriorityQueueMMAD* Q,ERRVAL_T* Errval);
#endif // INCLUDE_PRIORITYQUEUEMMAD


#endif // INCLUDE_PRIORITYQUEUEMM
