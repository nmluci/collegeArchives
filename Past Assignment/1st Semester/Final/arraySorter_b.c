#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <time.h>

int arr[20];
int arrLen;

int ARRLIMIT = 20;

int init();
int search();
int sort();
int insert();
int update();
int delete();
int count();
int arrMin();
int arrMax();
int avg();
int odd();
int even();

void printToFile();
int prime();

int main() {
    char mode[10];
    int invalid = 1;

    while (invalid) {
        printf("Enter the length of array: ");
        scanf("%d", &arrLen);
        if (arrLen <= 20) invalid = 0;
    }

    printf("Enter the type of array: ");
    scanf("%s", mode);

    init(arrLen, mode);

    for (int idx=0; idx < ARRLIMIT; idx++) {
        if (arr[idx] > 0) {
            printf("[%d] ", arr[idx]);
        } else {
            printf("[] ");
        };
    }

    printf("Press any key to exit");
    getch();
}

int init(int n, char *method) {
    srand(time(0));
    
    if (strcmp(method, "n") != 0 && strcmp(method, "p") != 0) {
        printf("[ERROR] %s: %s", "init", "Invalid option");
        getch();
        exit(0);
    } else {
        for (int i; i < arrLen; i++) {
            if (strcmp(method, "n") == 0) {
                arr[i] = rand();
            } else {
                int found = 0;
                while (!found) {
                    int temp = rand();
                    if (prime(temp) != 0) {
                        arr[i] = temp;
                        found = 1;
                    }
                }
            }
        }
    }

}


int prime(int num) {
    for (int i = 2; i*i < num; i++) {
        if (num % i == 0) return 0;
    }
    return num;
}

// int prime(int num) {
//     int ctr = 0;
//     for (int i = 2; i < num; i++) {
//         if (num % i == 0) ctr++;
//         if (ctr >= 3) break;
//     }
//     if (ctr == 2) {
//         return num;
//     } else {
//         return 0;
//     }
// }