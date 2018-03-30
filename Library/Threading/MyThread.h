#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef void* MyThread;

#include "Base/ThreadBase.h"
#include "Base/ThreadManager.h"

/** \brief Creates a new Thread and starts "start_routine"
*
* \param *Data Pointer to data the user can hand over to the thread. Can be accessed by "MyThread_GetData()" and changed by "MyThread_SetData()". Can be "NULL".
* \param start_routine The function the thread should start with.
* \param *arg The argument of the "start_routine" function. Can be accessed within "start_routine" or via "MyThread_GetArgument()". Can be "NULL".
* \param cleanup_routine Pointer to function that is called once the thread has stopped running. Can be changed by "MyThread_SetCleanupRoutine()". Can be "NULL".
*/

MyThread* MyThread_Create(void* Data,void*(start_routine(void*)),void* arg,void(cleanup_routine(MyThread*)));

/** \brief Returns the thread with the specified ID (or NULL)
*
* \param ID The id of the thread that should be returned.
*/

MyThread* MyThread_GetThreadFromID(uint64_t ID);

/** \brief Returns the thread that is running this function (or NULL). Will fail if this function is called by a thread that was NOT created by "MyThread_Create()".
*
*/

MyThread* MyThread_GetCurrentThread(void);

/** \brief Returns the thread-id of the specified thread.
*
* \param *T The thread whose id should be returned.
*/

uint64_t MyThread_GetID(MyThread* T);

/** \brief Returns the argument (the "*arg" of "MyThread_Create()") the specified thread was started with.
*
* \param *T The thread whose argument should be returned.
*/

void* MyThread_GetArgument(MyThread* T);

/** \brief Returns the user-specified data (the "*Data" of "MyThread_Create()") of the specified thread.
*
* \param *T The thread whose user-specified data should be returned.
*/

void* MyThread_GetData(MyThread* T);

/** \brief Sets the user-specified data (the "*Data" of "MyThread_Create()") of the specified thread. WARNING: THIS FUNCTION IS NOT THREAD-SAFE!
*
* \param *T The thread whose user-specified data should be set.
* \param *Data Pointer to the new user-specified data. Can be "NULL".
*/

int MyThread_SetData(MyThread* T,void* Data);

/** \brief Sets the cleanup-routine (the "cleanup_routine" of "MyThread_Create()") of the specified thread.
*
* \param *T The thread whose cleanup-routine should be set.
* \param cleanup_routine Pointer to function that is called once the thread has stopped running. Can be "NULL".
*/

int MyThread_SetCleanupRoutine(MyThread* T,void(cleanup_routine(MyThread*)));

/** \brief Terminates (permanently stops the execution of) the specified thread. The cleanup-routine will be called once the execution of the thread has stopped and the internal thread-resources will be freed. USE THIS WITH CAUTION AND ONLY FOR THREADS CREATED BY "MyThread_Create()"!
*
* \param *T The thread that should be terminated.
*/

int MyThread_Terminate(MyThread* T);

/** \brief Finishes the execution of the current thread. USE THIS ONLY FOR THREADS CREATED BY "MyThread_Create()"
*
* \param *ExitValue "return"-Value of the thread.
*/

int MyThread_Exit(void* ExitValue);


/** \brief Puts the current thread to sleep until the specified thread is no longer active (terminated or finished). USE THIS ONLY FOR THREADS CREATED BY "MyThread_Create()"!
*
* \param *T The thread the current thread should wait for.
* \param **ExitValue Pointer to the "return"-Value of that thread.
*/

int MyThread_WaitForTerminationOf(MyThread* T,void** ExitValue);

/** \brief Returns 1 if the specified thread is running. Otherwise 0 is returned.
*
* \param *T The thread that should be checked.
*/

int MyThread_IsRunning(MyThread* T);



