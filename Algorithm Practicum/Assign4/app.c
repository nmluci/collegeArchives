#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int isPalindrome(char* str);
void flipString(char* src, char* dest);
void getInput(char* prompt, char* dest);
void removeSpace(char* src, char* dest);

int main() {
    char* string = malloc(100*sizeof(char));
    getInput("Masukkan String", string);
    printf("%s adalah %s\n", string, (isPalindrome(string) ? "Palindrom" : "Bukan Palindrom"));
}

void getInput(char* prompt, char* dest) {
    printf("%s: ", prompt);
    char* buff = calloc(100, sizeof(char));
    fflush(stdin);
    fgets(buff, 100, stdin);
    buff = strtok(buff, "\n");
    strcpy(dest, buff);
}

void removeSpace(char* src, char* dest) {
    do {
        if (*src != ' ') *dest++ = *src;
    } while (*src++ != '\0');
}

void flipString(char* src, char* dest) {
    size_t len = strlen(src);

    for (int i=0; i<=len; i++) {
        dest[i] = src[len-i-1];
    }
    
    dest[len+1] = '\0';
}

int isPalindrome(char* str) {
    char* trimmed = calloc(100, sizeof(char));
    char* flipped = calloc(100, sizeof(char));

    removeSpace(str, trimmed);
    flipString(trimmed, flipped);
    
    for (int i=0; i<=strlen(trimmed); i++) {
        if (*trimmed++ != *flipped++) return 0;
    }

    return 1;
}