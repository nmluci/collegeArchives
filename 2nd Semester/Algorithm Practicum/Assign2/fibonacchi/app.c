#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

void generateFibonacchi(int len);

int main() {
    int len;
    printf("Masukkan jumlah deret: ");
    scanf("%d", &len);

    generateFibonacchi(len);
}

void generateFibonacchi(int len) {
    int ctr = 1;
    uint64_t curr = 1;
    uint64_t prev = 0;

    while (ctr<=len) {
        printf("%d: %ju\n", ctr, curr);
        curr += prev;
        prev = curr-prev;
        ctr++;
    }
}