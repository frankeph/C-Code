#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "Stringbuilder.h"
//#include "ArrayList.h"

/** \brief Checks, whether the string is Empty.
*
* \param *s The string to check (ends with '\0')
*/

int StringOP_IsEmpty(char* s);

/** \brief Returns an Empty String that only contains '\0'.
*/

char* StringOP_Empty(void);

/** \brief Combines two strings and makes one out of them. The resulting string is a copy saved in the heap.
*
* \param *s1 The first string (ends with '\0')
* \param *s2 The second string (ends with '\0')
*/

char* StringOP_Concat(char* s1, char* s2);

/** \brief Combines two strings, makes one out of them and frees "s1" and "s2". The resulting string is a copy saved in the heap.
*
* \param *s1 The first string (ends with '\0')
* \param *s2 The second string (ends with '\0')
*/

char* StringOP_ConcatR(char* s1, char* s2);

/** \brief Combines two strings, makes one out of them and frees "s1". The resulting string is a copy saved in the heap.
*
* \param *s1 The first string (ends with '\0')
* \param *s2 The second string (ends with '\0')
*/

char* StringOP_ConcatR1(char* s1, char* s2);

/** \brief Combines two strings, makes one out of them and frees "s2". The resulting string is a copy saved in the heap.
*
* \param *s1 The first string (ends with '\0')
* \param *s2 The second string (ends with '\0')
*/

char* StringOP_ConcatR2(char* s1, char* s2);

/** \brief Creates a substring of the string starting with the letter on position "index". The resulting string is a copy saved in the heap.
*
* \param *s The string from which the substring should be taken (ends with '\0')
* \param index The letter-position starting with 0 for the first letter and so on.
*/

char* StringOP_Substring(char* s, int index);

/** \brief Creates a substring of the string starting with the letter on position "index" and frees "s". The resulting string is a copy saved in the heap.
*
* \param *s The string from which the substring should be taken (ends with '\0')
* \param index The letter-position starting with 0 for the first letter and so on.
*/

char* StringOP_SubstringR(char* s, int index);

/** \brief Replaces all instances of string "f" with string "r" in string "s". The resulting string is a copy saved in the heap.
*
* \param *s The string from which instances of "f" should be replaced (ends with '\0')
* \param *f The string that should be replaced (ends with '\0')
* \param *r The replacement string (ends with '\0')
*/

char* StringOP_Replace(char* s,char* f,char* r);

/** \brief Replaces all instances of string "f" with string "r" in string "s" and frees "s", "f" and "r". The resulting string is a copy saved in the heap.
*
* \param *s The string from which instances of "f" should be replaced (ends with '\0')
* \param *f The string that should be replaced (ends with '\0')
* \param *r The replacement string (ends with '\0')
*/

char* StringOP_ReplaceR(char* s,char* f,char* r);

/** \brief Replaces all instances of string "f" with string "r" in string "s" and frees "s". The resulting string is a copy saved in the heap.
*
* \param *s The string from which instances of "f" should be replaced (ends with '\0')
* \param *f The string that should be replaced (ends with '\0')
* \param *r The replacement string (ends with '\0')
*/

char* StringOP_ReplaceR1(char* s,char* f,char* r);

/** \brief Replaces all instances of string "f" with string "r" in string "s" and frees "f". The resulting string is a copy saved in the heap.
*
* \param *s The string from which instances of "f" should be replaced (ends with '\0')
* \param *f The string that should be replaced (ends with '\0')
* \param *r The replacement string (ends with '\0')
*/

char* StringOP_ReplaceR2(char* s,char* f,char* r);

/** \brief Replaces all instances of string "f" with string "r" in string "s" and frees "r". The resulting string is a copy saved in the heap.
*
* \param *s The string from which instances of "f" should be replaced (ends with '\0')
* \param *f The string that should be replaced (ends with '\0')
* \param *r The replacement string (ends with '\0')
*/

char* StringOP_ReplaceR3(char* s,char* f,char* r);

/** \brief Replaces all instances of string "f" with string "r" in string "s" and frees "s" and "f". The resulting string is a copy saved in the heap.
*
* \param *s The string from which instances of "f" should be replaced (ends with '\0')
* \param *f The string that should be replaced (ends with '\0')
* \param *r The replacement string (ends with '\0')
*/

char* StringOP_ReplaceR12(char* s,char* f,char* r);

/** \brief Replaces all instances of string "f" with string "r" in string "s" and frees "s" and "r". The resulting string is a copy saved in the heap.
*
* \param *s The string from which instances of "f" should be replaced (ends with '\0')
* \param *f The string that should be replaced (ends with '\0')
* \param *r The replacement string (ends with '\0')
*/

char* StringOP_ReplaceR13(char* s,char* f,char* r);

/** \brief Replaces all instances of string "f" with string "r" in string "s" and frees "f" and "r". The resulting string is a copy saved in the heap.
*
* \param *s The string from which instances of "f" should be replaced (ends with '\0')
* \param *f The string that should be replaced (ends with '\0')
* \param *r The replacement string (ends with '\0')
*/

char* StringOP_ReplaceR23(char* s,char* f,char* r);

/** \brief Removes the rest of the string starting with the letter on position index. The resulting string is a copy saved in the heap.
*
* \param *s The string which should be shortened (ends with '\0')
* \param index The letter-position starting with 0 for the first letter and so on.
*/

char* StringOP_Remove(char* s, int index);

/** \brief Removes the rest of the string starting with the letter on position index and frees "s". The resulting string is a copy saved in the heap.
*
* \param *s The string which should be shortened (ends with '\0')
* \param index The letter-position starting with 0 for the first letter and so on.
*/

char* StringOP_RemoveR(char* s, int index);

/** \brief Removes the a specific number of letters starting on a specific position from a string. The resulting string is a copy saved in the heap.
*
* \param *s The string from which letters should be removed (ends with '\0')
* \param index The letter-position starting with 0 for the first letter and so on that defines the first letter that should be removed.
* \param length The number of letters that should be removed.
*/

char* StringOP_RemoveRange(char* s, int index, int length);

/** \brief Removes the a specific number of letters starting on a specific position from a string and frees "s". The resulting string is a copy saved in the heap.
*
* \param *s The string from which letters should be removed (ends with '\0')
* \param index The letter-position starting with 0 for the first letter and so on that defines the first letter that should be removed.
* \param length The number of letters that should be removed.
*/

char* StringOP_RemoveRangeR(char* s, int index, int length);

/** \brief Copies the string and saves the copy in the heap.
*
* \param *s The string that should be copied (ends with '\0')
*/

char* StringOP_Copy(char* s);

/** \brief Returns the string-representation of an integer. The string is saved in the heap.
*
* \param v The integer-value that should be "converted" to a string.
*/

char* StringOP_IntToString(int v);

/** \brief Returns the string-representation of an long long. The string is saved in the heap.
*
* \param v The long long-value that should be "converted" to a string.
*/

char* StringOP_LongToString(long long v);

/** \brief Returns the string-representation of an unsigned long long. The string is saved in the heap.
*
* \param v The long long-value that should be "converted" to a string.
*/

char* StringOP_UnsignedLongToString(unsigned long long v);

/** \brief Returns the string-representation of an double. The string is saved in the heap.
*
* \param v The double-value that should be "converted" to a string.
*/

char* StringOP_DoubleToString(double v);

/** \brief Returns the string-representation of a pointer. The string is saved in the heap.
*
* \param *v The pointer-value that should be "converted" to a string.
*/

char* StringOP_PointerToString(void* v);

/** \brief Returns the position of the first letter of the first occurrence of string "s2" in string "s1" or -1.
*
* \param *s1 The string in which s2 is searched for (ends with '\0')
* \param *s2 The string after which is searched in s1 (ends with '\0')
*/

int StringOP_IndexOf(char* s1, char* s2);

/** \brief Returns the position of the first letter of the first occurrence of string "s2" in string "s1" or -1 and frees "s1" and "s2".
*
* \param *s1 The string in which s2 is searched for (ends with '\0')
* \param *s2 The string after which is searched in s1 (ends with '\0')
*/

int StringOP_IndexOfR(char* s1, char* s2);

/** \brief Returns the position of the first letter of the first occurrence of string "s2" in string "s1" or -1 and frees "s1".
*
* \param *s1 The string in which s2 is searched for (ends with '\0')
* \param *s2 The string after which is searched in s1 (ends with '\0')
*/

int StringOP_IndexOfR1(char* s1, char* s2);

/** \brief Returns the position of the first letter of the first occurrence of string "s2" in string "s1" or -1 and frees "s2".
*
* \param *s1 The string in which s2 is searched for (ends with '\0')
* \param *s2 The string after which is searched in s1 (ends with '\0')
*/

int StringOP_IndexOfR2(char* s1, char* s2);

/** \brief Returns the position of the first letter of the last occurrence of string "s2" in string "s1" or -1.
*
* \param *s1 The string in which s2 is searched for (ends with '\0')
* \param *s2 The string after which is searched in s1 (ends with '\0')
*/

int StringOP_LastIndexOf(char* s1, char* s2);

/** \brief Returns the position of the first letter of the last occurrence of string "s2" in string "s1" or -1 and frees "s1" and "s2".
*
* \param *s1 The string in which s2 is searched for (ends with '\0')
* \param *s2 The string after which is searched in s1 (ends with '\0')
*/

int StringOP_LastIndexOfR(char* s1, char* s2);

/** \brief Returns the position of the first letter of the last occurrence of string "s2" in string "s1" or -1 and frees "s1".
*
* \param *s1 The string in which s2 is searched for (ends with '\0')
* \param *s2 The string after which is searched in s1 (ends with '\0')
*/

int StringOP_LastIndexOfR1(char* s1, char* s2);

/** \brief Returns the position of the first letter of the last occurrence of string "s2" in string "s1" or -1 and frees "s2".
*
* \param *s1 The string in which s2 is searched for (ends with '\0')
* \param *s2 The string after which is searched in s1 (ends with '\0')
*/

int StringOP_LastIndexOfR2(char* s1, char* s2);

/** \brief Returns the Integer-value that is represented in the string.
*
* \param *s The string whose Integer-value should be calculated!
*/

long long StringOP_ToInt(char* s);

/** \brief Returns the Integer-value that is represented in the string and frees "s".
*
* \param *s The string whose Integer-value should be calculated!
*/

long long StringOP_ToIntR(char* s);

/** \brief Returns the double-value that is represented in the string.
*
* \param *s The string whose double-value should be calculated!
*/

double StringOP_ToDouble(char* s);

/** \brief Returns the double-value that is represented in the string and frees "s".
*
* \param *s The string whose double-value should be calculated!
*/

double StringOP_ToDoubleR(char* s);

/** \brief Returns the length of a string.
*
* \param *s The string whose length should be determined (ends with '\0')
*/

int StringOP_Length(char* s);

/** \brief Compares two strings and returns -1 if s1 > s2, 0 if s1 == s2 and 1 if s1 < s2.
*
* \param *s1 The first string (ends with '\0')
* \param *s2 The second string (ends with '\0')
*/

int StringOP_Compare(char* s1, char* s2);

/** \brief Fills in characters until the String is centered. The new String is saved in the Heap
*
* \param *s The first string (ends with '\0')
* \param Length The Length of the Output-String. MUST NOT BE SMALLER THAN THE LENGTH OF THE ORIGINAL STRING
* \param Filler The character that is filled in
*/

char* StringOP_Center(char* s,int Length,char Filler);
