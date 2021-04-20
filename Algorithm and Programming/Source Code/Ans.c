// Pseudocode of Translated Code
// Partially coded by Cxizaki

#include <stdio.h>
#include <conio.h>

int main() {
    int a, b;

    a = 10;
    b = 2*a - 5;
    a = b;
    a += 2;
    b += a;
    printf("%d, %d",a, b); // 17, 32
    getch();
    return 0;
}