#include "stdio.h"
#include "string.h"
#include "conio.h"

int main() {
    char print[50];
    int ctr;

    printf("Range: ");
    scanf("%d", &ctr);

    for (int i=0; i <= ctr; i++) {
        for (int j=0; j < i; j++) {
            printf(" ");
        };
        printf("*");
        printf("\n");
    }
    getch();
}