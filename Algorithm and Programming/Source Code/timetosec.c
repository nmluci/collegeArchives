#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

// Clear Screen Macro
void cls() {
    char cmd[20];
    strcpy(cmd, "cls");
    system(cmd);   
}

// Credit Function
int credit() {
    printf("Coded by Cxizaki");
    getch();
    cls();
    return 0;
}

int main() {
    time_t curtime;
    struct tm *loctime;
    curtime = time(NULL);
    loctime = localtime(&curtime);
    printf("Currently is %s", asctime(loctime));

    credit();
    struct cxtime {
        int hour;
        int min;
        int sec;
    } cxt;

    printf("Enter the hours: ");
    scanf("%d", &(cxt.hour));
    printf("Enter the minutes: ");
    scanf("%d", &(cxt.min));
    printf("Enter the seconds: ");
    scanf("%d", &(cxt.sec));
    cls();
    
    int tot_sec = (int)cxt.hour*3600 + (int)cxt.min*60 + (int)cxt.sec;
    printf("%d:%02d:%02d\nIn Seconds (%d)", cxt.hour, cxt.min, cxt.sec, tot_sec);
    getch();
    return 0;
}