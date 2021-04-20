#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct llist_t {
    int data;
    struct llist_t* next;
};
typedef struct llist_t* llist;

int count = 0;

llist init(llist obj, int range, int step);
void copy(llist obj, int* arr);
llist search(llist obj, int val); 
int binSearch(int* arr, int size, int val);
void printList(llist obj);
llist addData(llist obj, int val);

int main() {
    int val = 0;
    int range = 0;
    int step = 0;
    int menu = -1;
    int isExit = 0;
    int isInit = 0;
    llist mainList = malloc(sizeof(struct llist_t));
    mainList->data = -1;
    mainList->next = NULL;

    // Menu
    while (!isExit) {
        printf("Tugas Pertemuan ke-10 Struktur Data\n");
        printf("By. Kelompok 4\n");
        printf("[1] Inisialisasi\n");
        printf("[2] Cari dan Tambah Data\n");
        printf("[3] Tampilkan Data\n");
        printf("[4] Keluar\n");
        printf("Masukkan pilihan anda: ");
        scanf("%d", &menu);

        switch(menu) {
            case 1:
                printf("Masukkan batas atas list: ");
                scanf("%d", &range);
                printf("Masukkan jarak antar bilangan: ");
                scanf("%d", &step);
                mainList = init(mainList, range, step);
                isInit = 1;
                break;
            case 2: 
                if (isInit) {
                    printf("Masukkan angka yang ingin dicari: ");
                    scanf("%d", &val);
                    search(mainList, val);
                } else {
                    printf("Lakukan inisialisasi terlebih dahulu!");
                }
                break;
            case 3:
                if (isInit) {
                    printList(mainList);
                } else {
                    printf("Lakukan inisialisasi terlebih dahulu!");
                }
                break;
            case 4:
                printf("Terima kasih...");
                exit(0);
                break;
            default:
                printf("Masukkan pilihan yang tersedia (1-4)!\n");
        }
        getch();
        system("cls");
    }    
}

llist init(llist obj, int range, int step) {
    for (int i=0; i<range; i+=step) {
        obj = addData(obj, i);
    }
    return obj;
}

llist addData(llist obj, int val) {
    llist curr = obj;
    llist new = malloc(sizeof(struct llist_t));
    new->data = val;
    new->next = NULL;

    if (curr->data != -1) {
        while (curr->next != NULL) {
            curr = curr->next;
        };
        curr->next = new;
    } else {
        curr->data = val;
        curr->next = NULL;
    }
    return obj;
}

void copy(llist obj, int* arr) {
    llist curr = obj;
    int i = 0;
    do {
        arr[i] = curr->data;
        curr = curr->next;
        count++;
        i++;
    } while (curr != NULL);
}

int binSearch(int* arr, int size, int val) {
    int left = 0;
    int mid = -1;
    int right = size-1;

    while (left <= right) {
        mid = left + (right-left)/2;

        if (arr[mid] == val) {
            break;
        } else {
            if (arr[mid] < val) {
                left = ++mid;
            } else {
                right = --mid;
            }
        }
    }
    
    return mid;
}

llist search(llist obj, int val) {
    int* arr = calloc(50, sizeof(int));
    copy(obj, arr);

    llist prev;
    llist curr = obj;
    llist new = malloc(sizeof(struct llist_t));
    new->data = val;
    new->next = NULL;
    
    int res = binSearch(arr, count, val);
    if (val != arr[res]) {
        printf("Menambah elemen %d ", val);
        if (val > arr[res]) {
            printf("ke index ke-%d...\n", res+1);
            
            if (res == count) {
                do {
                    curr = curr->next;
                } while (curr->next != NULL);
                curr->next = new;
            } else {
                do {
                    curr = curr->next;
                } while (curr->data != arr[res]);
                new->next = curr->next;
                curr->next = new;
            }
            return obj;
        } else {
            printf("ke index ke=%d...\n", res-1);
            do {
                prev = curr;
                curr = curr->next;
            } while (curr->data != arr[res]);
            prev->next = new;
            new->next = curr;
            return obj;
        }
    } else {
        printf("Elemen ditemukan pada index ke-%d...\n", res);
        return obj;
    }
}

void printList(llist obj) {
    llist curr = obj;

    do {
        printf("%d ", curr->data);
        curr = curr->next;
    } while (curr != NULL);
}