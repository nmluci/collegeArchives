/* Albertus Ivan
 * NIM. 2008561093
 * Kelas C
 * Algoritma n bilangan Prima 
 */
#include <stdio.h>
#include <conio.h>

int main() {
    int num, ctr, faktor = 0;

    // Input
    printf("Masukkan jumlah bilangan: ");
    scanf("%i", &num);
    
    // Prime Number
    printf("\n%i bilangan prima pertama: \n", num);
    for (int i=1;; i++) { 
        if (ctr>=num) break;
        faktor = 0;
        for (int j=1; j<=i; j++) {
            if (i % j == 0) faktor += 1;
            if (faktor >= 3) break;
        }
        if (faktor == 2) {
            ctr += 1;
            printf("%4i ", i);
        }
    }
    getch();
}
