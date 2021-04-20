// Pseudocode of Student Biodata Information Centre
// Coded by Cxizaki

#include <stdio.h>
#include <conio.h> // Header used by getch()

// Main function
int main() {
    // Initialized Structure Datatype for storing student's biodata
    struct Biodata
    {
        char name[120]; // Student's name
        int id;         // Student ID
        float score;    // Float datatypes is being used so user can get a more precise score
    } student;
    
    // Receiving Input from user
    printf("Enter your name: ");
    scanf("%s", &(student.name));
    printf("Enter your id: ");
    scanf("%d", &(student.id));
    printf("Enter score: ");
    scanf("%f", &(student.score));

    // Print out the result to the console
    // with some formatting to make reading easier
    printf("A Student by a name %s (ID. %d) had scored %3.2f on their last exam.", student.name, student.id, student.score);
    getch();

    // Make sure the program gracefully exitted
    return 0;
}