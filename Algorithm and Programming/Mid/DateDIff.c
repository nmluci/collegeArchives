/* Albertus Ivan
 * NIM. 2008561093
 * Kelas C
 * Algoritma Jarak 2 Tanggal (dd:mm:yy)
 */
#include <stdio.h>
#include <conio.h>

int main() {
    // Init
    struct {
        int day;
        int month;
        int year;
    } date1, date2;

    int yearDiff, monthDiff, dayDiff, rawDiff;

    // Get Input
    printf("Masukkan tanggal pertama (dd:mm:yy) : ");
    scanf("%i:%i:%i", &date1.day, &date1.month, &date1.year);
    printf("Masukkan tanggal kedua (dd:mm:yy) : ");
    scanf("%i:%i:%i", &date2.day, &date2.month, &date2.year);
    
    // Calculate
    date1.day += date1.year*365 + date1.month*30;
    date2.day += date2.year*365 + date2.month*30;
    
    rawDiff = date2.day-date1.day;
    if (rawDiff < 0) rawDiff *= -1; // Absolute Value
    yearDiff = rawDiff / 365;
    monthDiff = (rawDiff % 365) / 30;
    dayDiff = (rawDiff % 365) % 30;

    // Print output
    printf("Jarak antara kedua tanggal adalah %i tahun, %i bulan, dan %i hari (%i hari)", yearDiff, monthDiff, dayDiff, rawDiff);
    getch();
}
