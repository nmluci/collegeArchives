/* Albertus Ivan
 * NIM. 2008561093
 * Kelas C
 * Algoritma Jumlah Deret Fibonacci
 */

#include <stdio.h>
#include <conio.h>

int main() {
    // Init
    int a = 0, b = 1;
    int n, temp, z; 
    int sum = 0;
    // Input
    printf("Masukan jumlah angka deret fibonacci: ");
    scanf("%i", &n);
    
    // Calculation
    for (int i; i < n; i++) {
        temp = a + b;
        z = a; // Save value of a to temp variable
        a = b;
        b = temp;
        // Split then sum each number
        while (z > 0) {
            temp = z % 10;
            sum += temp;
            z = z / 10;
        }
    }

    printf("Jumlah deret: %i", sum);
    getch();
}
