#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct stack_t {
    int top;
    int* data;
    int max;
};

typedef struct stack_t* stack;

stack newStack(size_t size) {
    stack newData = malloc(sizeof(struct stack_t));
    newData->data = malloc(size * sizeof(int));
    newData->top = -1;
    return newData;
}

void pushStack(stack obj, int data) {
    if (obj->top == obj->max-1) printf("Stack penuh!\n");
    obj->data[++obj->top] = data;
}

int popStack(stack obj) {
    return obj->data[obj->top--];
}

int viewStack(stack obj) {
    if (obj->top == -1) return 0;

    for (int i=obj->top; i>=0; i--) {
        if (i == obj->top) printf("[%d] <= TOP\n", obj->data[i]);
        else printf("[%d]\n", obj->data[i]);
    }
}

int main(int argc, char* argv[]) {
    int menu = 0;
    int len = -1;

    if (argc == 2) len = atoi(argv[1]);

    if (len == -1) {
        printf("Masukkan jumlah data yang ingin dimasukkan kedalam stack: ");
        scanf("%d", &len);
    };

    stack iniStack = newStack(len);

    printf("Implementasi Stack\n");
    printf("Albertus Ivan\n");
    printf("NIM. 2008561093\n");
    printf("MK Praktikum Algoritma dan Pemrograman\n");


    while (menu != 4) {
        int temp = 0;
        printf("\nMenu\n");
        printf("[1] Masukkan Data\n");
        printf("[2] Keluarkan Data\n");
        printf("[3] Tampilkan Data\n");
        printf("[4] Keluar\n");
        printf("Input: ");
        scanf("%d", &menu);

        switch(menu) {
            case 1:
                printf("Masukkan data: ");
                scanf("%d", &temp);
                pushStack(iniStack, temp);
                break;
            case 2:
                printf("Data %d berhasil dikeluarkan!\n", popStack(iniStack));
                getch();
                break;
            case 3:
                printf("Kondisi Stack: \n");
                if (iniStack->top == -1) printf("Kosong!\n");
                else viewStack(iniStack);
                getch();
                break;
            case 4:
                break;
            default: 
                printf("Masukkan Pilihan yang Sesuai!\n");
                getch();
        }
        system("cls");
    }
}