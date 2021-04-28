#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct data_t {
    char* title;
    double score;
};
typedef struct data_t *data;
const int lines = 5;

void loadData(data parsedData);
void saveData(data parsedData, char* filename);
void printData(data parsedData, char* prompt);
void sort(data parsedData, int mode);

int main() {
    int sortMode = -1;
    struct data_t parsed[5];

    loadData(parsed);
    
    printData(parsed, "Unsorted Data");
    printf("\nSorting Mode (Ascending 1, Descending 0): ");
    scanf("%d", &sortMode);
    sort(parsed, sortMode);

    if (sortMode) {
        printData(parsed, "Ascendingly Sorted Data (Sorted Using Bubble Sort)");
    } else {
        printData(parsed, "Descendingly Sorted Data (Sorted Using Bubble Sort)");
    }
} 

void sort(data parsedData, int mode) {
    struct data_t temp;

    for (int i=0; i<lines-1; i++) {
        for (int j=0; j<lines-i-1; j++) {
            if (mode) {
                if (parsedData[j].score > parsedData[j+1].score) {
                    temp = parsedData[j];
                    parsedData[j] = parsedData[j+1];
                    parsedData[j+1] = temp;
                }
                saveData(parsedData, "ascending.txt");
            } else {
                if (parsedData[j].score < parsedData[j+1].score) {
                    temp = parsedData[j];
                    parsedData[j] = parsedData[j+1];
                    parsedData[j+1] = temp;
                }
                saveData(parsedData, "descending.txt");
            }
        }
    }
}

void printData(data parseData, char* prompt) {
    printf("%s:\n", prompt);

    for (int i=0; i<lines; i++) {
        printf("%-14s %2.1f\n", parseData[i].title, parseData[i].score);
    }
}

void saveData(data parseData, char* filename) {
    FILE* rawData = fopen(filename, "w");
    fprintf(rawData, "\nSorted:\n");

    for (int i=0; i<lines; i++) {
        fprintf(rawData, "%-14s %2.1f\n", parseData[i].title, parseData[i].score);
    }
    fclose(rawData);
}

void loadData(data parseData) {
    FILE* rawData = fopen("movies.txt", "r");
    char* buff = malloc(255 * sizeof(char));
    
    for (int i=0; i<lines; i++) {
        fgets(buff, 255, rawData);
        buff = strtok(buff, " ");
        parseData[i].title = buff;
        buff = strtok(NULL, " ");
        parseData[i].score = atof(buff);
    }
    fclose(rawData);
}