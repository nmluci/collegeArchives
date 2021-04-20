/* Albertus Ivan
 * NIM. 2008561093
 * Kelas C
 * Algoritma Pecahan Uang Rupiah
 */

// Pseudocode
// int m500, m100, m50, m25;
// uint64_t money, m1000;

// printf("Masukkan jumlah uang yang ingin dikonversikan dalam satuan rupiah: Rp. ");
// scanf("%ju", &money);
// m1000 = money / 1000;
// m500 = money % 1000 / 500;
// m100 = money % 1000 % 500 / 100;
// m50 = money % 1000 % 500 % 100 / 50;
// m25 = money % 1000 % 500 % 100 / 25;
// printf("Uang Rp. %ju setara dengan: \n%ju lembar Rp.1000, \n%i lembar Rp.100, \n%i lembar Rp.50, dan \n%i lembar Rp.25", 
//         money, m1000, m500, m100, m50, m25);

#include <stdio.h>
#include <conio.h>
#include <stdint.h>

int main() {
    // Init
    int m500, m100, m50, m25;
    uint64_t money, m1000;

    // Input
    printf("Masukkan jumlah uang yang ingin dikonversikan dalam satuan rupiah: Rp. ");
    scanf("%ju", &money);

    // Conversion
    m1000 = money / 1000;
    m500 = (money % 1000) / 500;
    m100 = ((money % 1000 ) % 500) / 100;
    m50 = (((money % 1000) % 500) % 100) / 50;
    m25 = ((((money % 1000) % 500) % 100) % 50) / 25;

    // Output
    printf("Uang Rp. %ju setara dengan:\n%ju lembar Rp.1000, \n%i lembar Rp.500, \n%i lembar Rp.100, \n%i lembar Rp.50, dan \n%i lembar Rp.25", 
            money, m1000, m500, m100, m50, m25);
    getch();
}