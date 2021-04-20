#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


// Global Variables
int arr[20];
int iArrLen;

// Constant Variable
const int ARR_LIMIT =  20;
const long long int MAX_NUM = UINT_MAX;

// Predefine Functions and Methods
int init();
int search(int n, int *arr[], char *sortStyle);
int sort(int *arr[], char *sortStyle, int sortMethod);
int insert(int n, char *sortStyle);
int update(int n, int m, int *sortStyle);
int delete(int n, int *sortStyle);
int count(int *arr[]);
void arrMin(int *arr[]);
void arrMax(int *arr[]);
void average(int *arr[]);
void ganjil(int *arr[]);
void genap(int *arr[]);
void printToFile(char cmd, char *msg);
int prime();

int main() {
    char mode[10];
    int invalid = 1;

    // Ensures doenst exceed limit given
    while (invalid) {
        printf("Enter the length of array: ");
        scanf("%d", &iArrLen);
        if (iArrLen <= 20) invalid = 0;
    }

    printf("Enter the type of array: ");
    scanf("%s", mode);

    init(iArrLen, mode);

    //continue to exit
    printf("\nPress any key to exit()");
    getch(); 
};

int init(int n, char *method) {
    srand(time(0));
    iArrLen = n;

    if (strcmp(method, "n") != 0 && strcmp(method, "p") != 0) {
        printf("[ERROR] %s: %s", "init", "Invalid option");
        getch();
        exit(0);
    } else {
        for (int i; i < iArrLen; i++) {
            if (strcmp(method, "n") == 0) {
                arr[i] = rand();
            } else {
                int found = 0;
                while (!found) {
                    int temp = rand() % MAX_NUM;
                    if (prime(temp) != 0) arr[i] = temp;
                }
            };
        };
    }

    // Print Result
    printf("Input: init(%d, %s)\n", n, method);
    printf("Output: \ninit: ");
    for (int idx; idx < ARR_LIMIT; idx++) {
        if (arr[idx] > 0) {
            printf("[%d] ", arr[idx]);
        } else {
            printf("[] ");
        }
    }
};

int prime(int num) {
    for (int i; i*i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return num;
}

int sort(int *arr[], char sortStyle[5], int sortMethod) {
    if (strcmp(sortStyle, "asc") != 0 && strcmp(sortStyle, "desc") != 0) {
        printf("[ERROR] %s: %s", "sort", "Invalid Command");
    }
    
    if (strcmp(sortStyle, "asc") == 0) {

    } else {

    };
};