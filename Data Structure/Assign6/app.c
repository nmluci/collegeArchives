/* 
 * Albertus Ivan (NIM. 2008561093)
 * Implementasi Menara Hanoi Secara Rekursif
 * Bahasa C (C99)
*/

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void hanoi(int disk, char* src, char* buff, char* dest) {
    if (disk <= 1) {
        printf("%s -> %s\n", src, dest);
    } else {
        hanoi(disk-1, src, dest, buff);
        printf("%s -> %s\n", src, dest);
        hanoi(disk-1, buff, src, dest);
    }

};

int main(int argc, char* argv[]) {
    int len = 0;
    char* src = malloc(10*sizeof(char));
    char* buff = malloc(10*sizeof(char));
    char* dest = malloc(10*sizeof(char));

    if (argc != 5) {
        printf("app.exe [jumlah piringan] [inisial asal] [inisial buffer] [inisial tujuan]\n");
        printf("Masukkan jumlah piringan: ");
        scanf("%d", &len);

        printf("Masukkan jumlah inisial tunggak asal (max. 10 char): ");
        scanf("%s", src);

        printf("Masukkan inisial tunggak bantu (max. 10 char): ");
        scanf("%s", buff);

        printf("Masukkan inisial tunggak tujuan (max. 10 char): ");
        scanf("%s", dest);

    } else {
        len = atoi(argv[1]);
        snprintf(src, 10, "%s", argv[2]);
        snprintf(buff, 10, "%s", argv[3]);
        snprintf(dest, 10, "%s", argv[4]);
    }

    printf("Piringan: %d | Asal: %s | Buffer: %s | Tujuan: %s\n", len, src, buff, dest);
    if (len >= 3 & len <= 9) hanoi(len, src, buff, dest);
    else printf("Tidak dalam jangkauan yang dibatasi!"); return -1;
}