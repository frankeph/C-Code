#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define WINVER 0x0A00
#define _WIN32_WINNT 0x0A00
//#define _WIN32_WINNT 0x0500
#include <windows.h>

char* Prog_Name = NULL;

char* GetProgName(void){
    return Prog_Name;
}

#define PROG_NAME (GetProgName())

//#define WINVER 0x0A00
//#define _WIN32_WINNT 0x0A00


 #ifdef _WIN32
 #ifdef main
 #undef main
 #endif
 #endif // _WIN32

#include "src/Basics/StringOP.h"
#include "src/Test/TestEnvironment.h"

int main(int argc, char* argv[]) {

    #ifdef DRAWING3D_HIDE_CONSOLE
    HWND hWnd = GetConsoleWindow();
    ShowWindow( hWnd, SW_MINIMIZE );  //won't hide the window without SW_MINIMIZE
    ShowWindow( hWnd, SW_HIDE );
    #endif // DRAWING3D_HIDE_CONSOLE
    char* Prog_Path = StringOP_Copy(argv[0]);
    printf("Starting: \"%s\"\n",Prog_Path);

    int MaxIndex = StringOP_LastIndexOfR2(Prog_Path,StringOP_Copy("/\0")) + 1;
    int MaxIndex2 = StringOP_LastIndexOfR2(Prog_Path,StringOP_Copy("\\\0")) + 1;
    if(MaxIndex2 > MaxIndex){MaxIndex = MaxIndex2;}

    char* ExtendedName = StringOP_Substring(Prog_Path,MaxIndex);
    Prog_Name = StringOP_RemoveR(ExtendedName,StringOP_IndexOfR2(ExtendedName,StringOP_Copy(".\0")));

    int a = 0;
    int index = -1;
    int fitindex = -1;
    while(index == -1){
        if((fitindex == -1)&&(argv[0][a] == Prog_Name[0])){
            fitindex = a;
        }
        if((fitindex != -1)&&(argv[0][a] != Prog_Name[a - fitindex])){
            if(Prog_Name[a - fitindex] == '\0'){
                index = a;
            }else{
                a = fitindex;
                fitindex = -1;
            }
        }
        if(argv[0][a] == '.'){index = -2;}
        a = a + 1;
    }
    if(index == -2){
        printf("[ERROR] Execution directory could not be found!\n");
        printf("        Terminating program!\n");
        return 0;
    }
    //printf("\nAbschneide-Position:%i",index);
    char* path = (char*)malloc((index + 2) * sizeof(char));
    int laenge0 = index + 1;
    for(a = 0; a < laenge0; a++){
        path[a] = argv[0][a];
    }
    path[laenge0] = '\0';
    printf("Base-Path found: \"%s\"\n",path);

    //TestEnvironment_BaseTest_PriorityQueueMMSF(1000000);
    //TestEnvironment_BaseTest_PriorityQueueMMAF(10000);
    //TestEnvironment_BaseTest_PriorityQueueMMSD(10000);
    //TestEnvironment_BaseTest_PriorityQueueMMAD(10000);

    //TestEnvironment_AdvTest_PriorityQueueMMAF(10000);
    TestEnvironment_AdvTest_PriorityQueueMMAD(10000);
    getchar();

    return 0;
}
