#include "stdio.h" 
#include "stdlib.h" // exit()
#include "string.h" // strcmp()
#include "conio.h"  // getch()

typedef struct {
        int d; // Tanggal
        char m[10]; // Bulan
        int y; // Tahun
    } date;

int getUmur(date tanggalLahir) {
    // Helper Variable Initialization
    const int DAY_IN_MONTH = 31;
    int currDay = 15;
    int currMonth = 2;
    int currYear = 2021;
    int umur = 0;

    // Converting Months into days to ease up calculation
    int birthMonth = 0;
    if (strcmp(tanggalLahir.m, "januari") == 0) {
        birthMonth = 1;
    } else if (strcmp(tanggalLahir.m, "februari") == 0) {
        birthMonth = 2;
    } else if (strcmp(tanggalLahir.m, "maret") == 0) {
        birthMonth = 3;
    } else if (strcmp(tanggalLahir.m, "april") == 0) {
        birthMonth = 4;
    } else if (strcmp(tanggalLahir.m, "mei") == 0) {
        birthMonth = 5;
    } else if (strcmp(tanggalLahir.m, "juni") == 0) {
        birthMonth = 6;
    } else if (strcmp(tanggalLahir.m, "juli") == 0) {
        birthMonth = 7;
    } else if (strcmp(tanggalLahir.m, "agustus") == 0) {
        birthMonth = 8;
    } else if (strcmp(tanggalLahir.m, "september") == 0) {
        birthMonth = 9;
    } else if (strcmp(tanggalLahir.m, "oktober") == 0) {
        birthMonth = 10;
    } else if (strcmp(tanggalLahir.m, "november") == 0) {
        birthMonth = 11;
    } else if (strcmp(tanggalLahir.m, "desember") == 0) {
        birthMonth = 12;
    } else {
        birthMonth = -1;
    }

    if (birthMonth == -1) {
        printf("Masukkan nama bulan sesuai kajian KBBI!\n");
        getch();
        return -1;
    }

    umur = (currYear - tanggalLahir.y) * DAY_IN_MONTH*12;
    umur += (currMonth - birthMonth) * DAY_IN_MONTH;
    umur += currDay - tanggalLahir.d;
    umur = umur / (DAY_IN_MONTH*12);
    return umur;
}

int main() {
    // Initialization
    char name[50];
    char nim[12];
    char kelas[2];
    char alamat[100];
    char noHP[14];

    date tanggalLahir;
    
    // Input
    printf("Nama: ");
    fflush(stdin);
    fgets(name, 50, stdin);
    printf("NIM: ");
    scanf("%s", nim);
    printf("Kelas: ");
    scanf("%s", kelas);
    printf("Alamat: ");
    fflush(stdin);
    fgets(alamat, 100, stdin);
    printf("No Hp: ");
    scanf("%s", noHP);
    printf("Tanggal Lahir (dd M yyyy): ");
    scanf("%d %s %d", &tanggalLahir.d, tanggalLahir.m, &tanggalLahir.y);

    // Calculating User's Age
    int umur = getUmur(tanggalLahir);
    if (umur == -1) {
        exit(1);
    }

    // Menampilkan data yang telah diinput oleh user beserta prediksi umur
    // Showing the data user has inputted before and the age approximation
    // cls;
    printf("\n*********Data User*********\n");
    printf("Nama: %s", name);
    printf("NIM. %s\n", nim);
    printf("Kelas %s\n", kelas);
    printf("Alamat: %s", alamat);
    printf("No Hp: %s\n", noHP);
    printf("Tanggal Lahir: %d %s %d\n", tanggalLahir.d, tanggalLahir.m, tanggalLahir.y);
    printf("Umur %d", umur);
    getch();
    return 0;
}