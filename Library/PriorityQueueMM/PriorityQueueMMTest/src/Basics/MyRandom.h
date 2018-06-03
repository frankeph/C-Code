#pragma once
#include <stdio.h>
//#include <limits.h>
#include <stdint.h>
#include <time.h>

typedef void MyRandom;

//const uint64_t MyRandomPrime = (((uint64_t)1) << ((uint64_t)32)) - ((uint64_t)6);

/** \brief Creates a new random-number-generator with a seed taken from the system-time.
*
*/

MyRandom* MyRandom_Create(void);

/** \brief Creates a new random-number-generator.
*
* \param Seed The seed for the random-number-generator.
*/

MyRandom* MyRandom_Create2(uint32_t Seed);

/** \brief Creates a new random-number-generator.
*
* \param Seed The seed for the random-number-generator.
*/

MyRandom* MyRandom_Create3(uint64_t Seed);

/** \brief Returns a pseudo-random 32-bit unsigned integer.
*
* \param *R Random-number-generator that should be used to create the pseudo-random 32-bit unsigned integer.
*/

uint32_t MyRandom_GetInt(MyRandom* R);

/** \brief Returns a pseudo-random integer between "Min" and "Max".
*
* \param *R Random-number-generator that should be used to create the pseudo-random integer within the specified interval.
* \param Min The lower boundary of the interval the pseudo-random number should be in.
* \param Max The upper boundary of the interval the pseudo-random number should be in.
*/

int MyRandom_GetInt2(MyRandom* R,int Min,int Max);

/** \brief Returns the seed of the random-number-generator.
*
* \param *R Random-number-generator whose seed should be returned.
*/

uint64_t MyRandom_GetSeed(MyRandom* R);

/** \brief Returns the "counter"-value of random-number generator. The "counter"-value is a additional value that should increase the number of pseudo-random values until the values start repeating.
*
* \param *R Random-number-generator whose "counter"-value should be returned.
*/

uint64_t MyRandom_GetCounter(MyRandom* R);

/** \brief Resets the random-number-generator back to the state directly after it was created.
*
* \param *R Random-number-generator that should be reset.
*/

int MyRandom_Reset(MyRandom* R);

/** \brief Destroys the random-number-generator and frees all of its resources
*
* \param *R Random-number-generator that should be destroyed.
*/

void MyRandom_Dispose(MyRandom* R);



