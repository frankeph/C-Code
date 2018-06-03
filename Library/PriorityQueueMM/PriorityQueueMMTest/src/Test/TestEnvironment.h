#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#include "../Basics/StringOP.h"
#include "../Basics/MyRandom.h"
#include "../Basics/PriorityQueueMM.h"
#include "TestResults.h"
#include "TestPQSFSim.h"
#include "TestPQAFSim.h"
#include "TestPQSDSim.h"
#include "TestPQADSim.h"
#include "TestItemProvider.h"

//#define TESTENVIRONMENT_SHOWTRE
//#define TESTENVIRONMENT_SHOWALL
#define TESTENVIRONMENT_ENDLESS
//#define TESTENVIRONMENT_VALIDCALLS

int TestEnvironment_BaseTest_PriorityQueueMMSF(int TestOps);

int TestEnvironment_BaseTest_PriorityQueueMMAF(int TestOps);

int TestEnvironment_BaseTest_PriorityQueueMMSD(int TestOps);

int TestEnvironment_BaseTest_PriorityQueueMMAD(int TestOps);


int TestEnvironment_AdvTest_PriorityQueueMMAF(int TestOps);

int TestEnvironment_AdvTest_PriorityQueueMMAD(int TestOps);



