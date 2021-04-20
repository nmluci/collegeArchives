#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

int makeAcc();
int checkAcc();

struct account {
        int id;
        char name[120];
        char address[200];
        char city[50];
        int phone[15];
} acc;

// Datetime Macro
void datetime() {
    time_t loctime;
    struct tm *cxtime;
    loctime = time(NULL);
    cxtime = localtime(&loctime);
    printf("%s \n", asctime(cxtime));
}

// Clear Screen Macro
void cls() {
    char cmd[20];
    strcpy(cmd, "cls");
    system(cmd);
}

// Credits Macro
void credit() {
    datetime();
    printf("Coded by Cxizaki\n");
    getch();
    cls();
}

int menu() {
    char ans;
    printf("Welcome to Crux Saki Bank!\n");
    printf("May I know what do your need madam?\n");
    printf("[1] Register Account\n");
    printf("[2] Show Account\n");
    printf("[3] Exit\n \n");
    printf("Please type the number accordingly.\n> ");
    ans = getchar();
    return ans;
}

int main(char stats) {
    cls();
    credit();
    int ans;
    ans = menu();
    // if (stats == '2') {
    //     ans = '2';
    // } else {
    //     ans = menu();
    // }

    switch (ans) {
        case '1':
            makeAcc();
            break;
        case '2':
            checkAcc();
            break;
        case '3':
            return 0;
        default:
            printf("Invalid!\n");
            getch();
            main('3');
            break;
    }

    return 0;
}

int makeAcc() {
    char con;
    cls();
    printf("Welcome to the Registration Page!\n");
    printf("May I know your name?\n> ");
    scanf("%s", &(acc.name));
    printf("Enter your desired Bank Account ID\n> ");
    scanf("%d", &(acc.id));
    printf("Where do you lived?\n> ");
    scanf("%s", &(acc.address));
    printf("Which city?\n> ");
    scanf("%s", &(acc.city));
    printf("May I get your phone number for verification?\n> ");
    scanf("%d", &(acc.phone));
    cls();
    printf("| Name: %s\n| Bank ID: %d\n| Address: %s\n| City: %s\n| Phone Number: %d\n", acc.name, acc.id, acc.address, acc.city, acc.phone);
    getch();
    main('2');
}

int checkAcc() {
    cls();
    if (acc.id != 0) {
        printf("| Name: %s\n| Bank ID: %d\n| Address: %s\n| City: %s\n| Phone Number: %d\n", acc.name, acc.id, acc.address, acc.city, acc.phone);
        getch();
    } else {
        printf("No Data!");
        getch();
    }
    return 0;
}

