#include <stdio.h>
#include <string.h>

int main() {
    struct time
    {
        int hour;
        int min;
        int sec;
    } waktu;
    
    char cmd[20];
    strcpy(cmd, "cls");
    printf("Coded by Cxizaki");
    getch();

    system(cmd);
    printf("Masukkan jam: ");
    scanf("%d", &(waktu.hour));
    printf("Masukkan menit: ");
    scanf("%d", &(waktu.min));
    printf("Masukkan detik: ");
    scanf("%d", &(waktu.sec));
    system(cmd);

    int total = (int)waktu.hour*3600 + (int)waktu.min*60 + (int)waktu.sec;
    printf("%d:%02d:%02d\n", waktu.hour, waktu.min, waktu.sec);
    printf("Waktu dalam detik: %d\n\n", total);
    getch();

    printf("Ciee... Nyoba buka wwww");
    system(cmd);
    return 0;
};