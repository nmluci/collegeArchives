#ifndef __CX_ERR__
    #define __CX_ERR_
    #include <stdio.h>
    
    extern void printError(char* moduleName, char* msg);
    extern void printWarning(char* moduleName, char* currentVal, char* expectedVal);
#endif