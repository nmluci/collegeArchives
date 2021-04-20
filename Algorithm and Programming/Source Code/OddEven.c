// 0dd or 3ven Algorithm
// Coded by Cxizaki

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define PROGNAME "TITLE Odd or Even"

void cls() {
    char cmd[10];
    strcpy(cmd, "cls");
    system(cmd);
}

int main() {
    long long num;
    int nums;

    printf("Enter the number: ");
    scanf("%d", &num);

    nums = num % 10;
    if (nums % 2 == 0) {
        printf("%d is an EVEN number", num);
    } else {
        printf("%d is an ODD number", num);
    }

    getch();
    return 0;
}