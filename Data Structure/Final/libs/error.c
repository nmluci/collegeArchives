#include "error.h"

void printError(char* moduleName, char* msg) {
    printf("%s: %s\n", moduleName, msg);
}

void printWarning(char* moduleName, char* currentVal, char* expectedVal) {
    printf("Warning [%s]: Nilai %s seharusnya bernilai %s!\n", moduleName, currentVal, expectedVal);
}
