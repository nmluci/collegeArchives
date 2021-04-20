#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
void arrGen();
void bSort();
void swap();
void printArray();

int main() {
    FILE *file;
    char cmd[] = "Kyaa";
    char msg[] = "fff";
    file = fopen("firu.txt", "a");
    printf("[%s] %s", cmd, msg);
    fprintf(file, "[%s] %s", cmd, msg);
    fclose(file);
};
