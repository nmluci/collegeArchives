/* Albertus Ivan
 * NIM. 2008561093
 * Kelas C
 * Algoritma Tahun Kabisat
 */

// Pseudocode
// int year, boolKabisat = 0;
// printf("masukkan tahun: ");
// scanf("%i", &year);
// if (year % 400 == 0 || ((year % 400 != 0) && (year % 100 != 0) && (year % 4 == 0))) boolKabisat = 1;
// if (((year % 400 != 0) && (year % 100 == 0)) || ((year % 400 != 0) && (year % 100 != 0) && (year % 4 != 0))) boolKabisat = 0;
// if (boolKabisat) {
//     printf("%i adalah tahun kabisat", year);
// } else {
//     printf("%i bukan tahun kabisat", year);
// }


#include <stdio.h>
#include <conio.h>

int main() {
    // Init
    int year;
    int boolKabisat;

    // Input
    printf("Masukkan tahun: ");
    scanf("%i", &year);

    // Validation
    if (year % 400 == 0 || ((year % 400 != 0) && (year % 100 != 0) && (year % 4 == 0))) boolKabisat = 1;
    if (((year % 400 != 0) && (year % 100 == 0)) || ((year % 400 != 0) && (year % 100 != 0) && (year % 4 != 0))) boolKabisat = 0;

    // Output
    if (boolKabisat) {
        printf("%i adalah tahun kabisat\n", year);
        getch();
    } else {
        printf("%i bukan tahun kabisat\n", year);
        getch();
    }

}
