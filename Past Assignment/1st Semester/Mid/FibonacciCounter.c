/* Albertus Ivan
 * NIM. 2008561093
 * Kelas C
 * Algoritma Jumlah Deret Fibonacci
 */

// Pseudocode

// unsigned long long a = 0, b = 1;
// int n, temp, z, sum = 0;
// printf("Masukkan jumlah angka deret fibonacci: ");
// scanf("%d", %n);
// for (int i; i < n; i++) {
//     temp = a+b;
//     z = a;
//     a = b;
//     b = temp;

//     while (z>0) {
//         temp = z % 10;
//         sum = sum + temp;
//         z = z / 10;
//     }
// }
// printf("Jumlah dere: %d", sum);

#include <stdio.h>
#include <conio.h>

int main() {
    // Init
    unsigned long long a = 0, b = 1; 
    int n, temp, z; 
    int sum = 0;
    // Input
    printf("Masukan jumlah angka deret fibonacci: ");
    scanf("%ju", &n);
    
    // Calculation
    for (int i; i < n; i++) {
        temp = a + b;
        z = a; // Save value of a to temp
        a = b;
        b = temp;
        // Split then sum each number
        while (z > 0) {
            printf("(%ju) ", z);
            temp = z / 10;
            sum += temp;
            // if (temp == 0) break;
            z = z % 10;
        }
    }

    printf("Jumlah deret: %ju", sum);
    getch();
}
