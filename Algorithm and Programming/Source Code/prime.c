#include <stdio.h>
#include <string.h>

int main() {
    char cmd[20];
    strcpy(cmd, "cls");
    printf("Coded by Cxizaki");
    getch();
    system(cmd);
    
    printf("Current User [%s]\n", getenv("USERNAME"));

    int num;
    printf("Masukkan angka: ");
    scanf("%d", &num);
    int isPrime = prime(num);
    
    if (isPrime == 1) {
        printf("Kenya prima! %d Faktor", isPrime);
        getch();
        return 0;
    } else {
        printf("Bukan Prima! %d Faktor", isPrime);
        getch();
        return 0;
    };
}

int prime(int num) {
    int counter = 0;
    // printf("%d\n", num);
    if (num <= 1) {
        printf("Fuee\n");
        return 0;
    } else {
        for (int i=1; i<num; i++) {
            if (num % i == 0) {
                // printf("%d faktor ke-%d\n", i, counter+1);
                counter++;
            } 
        }
    };
    return counter;
}