// Pseudocode of Time to Second Conversion Program
// Code by Cxizaki

#include <stdio.h>
#include <conio.h> // Header used by getch()

// Main function
int main() {
    // Variable Init.
    int hour, min, sec;

    // Receiving Input from user
    printf("Enter the hours: ");
    scanf("%d", &hour);
    printf("Enter the minutes: ");
    scanf("%d", &min);
    printf("Enter the seconds: ");
    scanf("%d", &sec);

    // Converting each type of data into seconds unit measurements.
    sec = hour*3600 + min*60 + sec;

    // Print out the conversion results.
    printf("Time passed in second(s): %d", sec);
    getch();
    
    // Make sure the program exit gracefully
    return 0;
}