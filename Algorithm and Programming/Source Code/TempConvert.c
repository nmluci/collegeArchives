// Celcius to Reamur, Farenheit ,and Kelvin Converter
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define progname "TITLE Temperature Converter" 

void clear() {
    char cmd2[20];
    strcpy(cmd2, "cls");
    system(cmd2);
}
int main() {
    float base, rTemp, fTemp, kTemp;
    printf("Enter the base temperature in Celcius: ");
    scanf("%f", &base);
    clear();
    // convert into Fahrenheit
    fTemp = 1.8 * base + 32;
    rTemp = 0.8 * (float)base;
    kTemp = base + 273;

    printf("The temperature %2.2f, is equivalent to:\n %2.2f R \n %2.2f F\n %2.2f K", base, rTemp, fTemp, kTemp);
    getch();
    return 0;
}