/* Albertus Ivan
 * NIM. 2008561093
 * Kelas C
 * Algoritma Jarak 2 Tanggal (dd:mm:yy)
 */
#include <stdio.h>
#include <conio.h>

int main() {
    // Init
    int y1, y2, m1, m2, d1, d2;
    int yearDiff, monthDiff, dayDiff, rawDiff;
    // Get Input
    printf("Masukkan tanggal pertama (dd:mm:yy) : ");
    scanf("%d:%d:%d", &d1, &m1, &y1);
    printf("Masukkan tanggal kedua (dd:mm:yy) : ");
    scanf("%d:%d:%d", &d2, &m2, &y2);

    // Calculate
    d1 += y1*365 + m1*30;
    d2 += y2*365 + m2*30;
    
    rawDiff = d2-d1;
    if (rawDiff < 0) rawDiff *= -1; // Absolute Value
    yearDiff = rawDiff / 365;
    monthDiff = (rawDiff % 365) / 30;
    dayDiff = (rawDiff%365) % 30;

    // Print output
    printf("Jarak antara kedua tanggal adalah %i tahun, %i bulan, dan %i hari (%i hari)", yearDiff, monthDiff, dayDiff, rawDiff);
    getch();
}
