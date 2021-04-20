#include "stdio.h"
#include "string.h"
#include "conio.h"

int main() {
    char sen[255];
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;

    printf("Masukkan kalimat: ");
    scanf("%s", sen);

    for (int i=0; i<strlen(sen); i++) {
        if (sen[i] == "a") {
            if (b+c+d+e == 0) {
                a++;
            } else {
                printf("Tidak Ajaib!");
                getch();
                return 0;
            }
        };
        if (sen[i] == "i") {
            if (a+c+d+e == 0) {
                b++;
            } else {
                printf("Tidak Ajaib!");
                getch();
                return 0; 
            }
        };
        if (strcmp(sen[i], "u") == 0) {
            if (a+b+d+e == 0) {
                c++;
            } else {
                return printf("Tidak Ajaib!");
            }
        };
        if (strcmp(sen[i], "e") == 0) {
            if (a+b+c+e == 0) {
                d++;
            } else {
                return printf("Tidak Ajaib!");
            }
        };
        if (strcmp(sen[i], "o") == 0) {
            if (a+b+c+d == 0) {
                e++;
            } else {
                return printf("Tidak Ajaib!");
            }
        };
        
    }
    printf("Ajaib!");
    getch();
}