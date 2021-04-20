#include <stdio.h>
#include <conio.h>
#include <stdint.h>

unsigned int crc32(unsigned char *message) {
    int i, j;
    unsigned int byte, crc, mask;

    i = 0;
    crc = 0xFFFFFFFF;
    while (message[i] != 0) {
        byte = message[i];
        crc = crc ^ byte;
        for (j = 7; j >= 0; j--) {
            mask = ~(crc & 1);
            crc = (crc >> 1) ^ (0xEDB88320 & mask);
        }
        i += 1;
    }
    return ~crc;
}

int main() {
    unsigned char *msg;
    printf("CRC32 Error-Checking");
    printf("Enter da data: ");
    scanf("%hhu", &msg);
    printf("%hhu",(unsigned char)msg);
    getch();
}