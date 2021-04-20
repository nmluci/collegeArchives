#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void flipString(char* src, char* dest);
int isPalindrome(char* str);

int main() {
    char* str = malloc(30*sizeof(char));
    printf("Masukkan angka: ");
    scanf("%s", str);

    printf("%s is %s\n", str, isPalindrome(str) ? "Palindrome" : "not Palindrome");
}

void flipString(char* src, char* dest) {
    size_t len = strlen(src);

    for (int i=0; i<len; i++) {
        dest[i] = src[len-i-1];
    }
    dest[len+1] = '\0';
    
}

int isPalindrome(char* str) {
    size_t len = strlen(str);
    char* inv = malloc(30*sizeof(char));
    int diff;
    
    flipString(str, inv);

    for (int i=0; i<len; i++) {
        if (str[i] != inv[i]) diff++;
    }

    return diff == 0 ? 1 : 0;
}