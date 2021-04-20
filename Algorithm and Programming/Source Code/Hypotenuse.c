// Find the Hypotenuse Algorithm
// Coded by Cxizaki

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#define PROGNAME "TITLE Find the Hypotenuse Algorithm by Cxizaki"

void cls() {
    char cmd[10];
    strcpy(cmd, "cls");
    system(cmd);
}

void credits() {
    char cmd[100];
    strcpy(cmd, PROGNAME);
    system(cmd);
    printf("Coded by Cxizaki");
    getch();
    cls();
}

int main() {
    int adj, opp;
    double hyp, sum;
    credits();
    printf("Enter the length of the Adjacent Side: ");
    scanf("%d", &adj);
    printf("Enter the length of the Opposite Side : ");
    scanf("%d", &opp);
    
    // calculate the hypotenuse
    sum = pow(adj, 2) + pow(opp, 2);
    hyp = sqrt(sum);

    printf("The hypotenuse of a triangle with a length of %d by %d is %f", adj, opp, hyp);
    getch();
    return 0;
}