#include <stdio.h>
#include <stdlib.h>
#include <time.h> // time(0)
#include <math.h> // pow()
#include <string.h>
#include <conio.h> // getch()
#include <stdint.h>


#define ull unsigned long long
const int MAX_HASH = 150;


struct custInfo {
    char nama[20];
    char alamat[30];
    ull nomor;
};
typedef struct custInfo* data;

struct custInfo defaultData[] = { 
    {"Max Santosa", "Jakarta"},
    {"Surya Setiawan", "Banten"},
    {"John Maxwell", "Sulawesi"},
    {"Agus Setiadharma", "Semarang"},
    {"Shan Novel", "Jakarta"},
    {"Yuki Nasa", "Banten"},
    {"Raden Agus", "Jogja"},
    {"Bambang Purwono", "Surabaya"} 
};


void initHash(data* obj);
void addData(data* obj, char* name, char* addrs);
void removeData(data* obj, ull num);
void printData(data* obj);
void getInput(char* prompt, char* var, unsigned len);
int hashIndex(ull num);
unsigned lengthOfNum(const ull num);

int main() {
    int isExit = 0;
    int menu = -1;
    char* name = calloc(20, sizeof(char));
    char* alamat = calloc(30, sizeof(char));
    ull num;
    data dataPelanggan[MAX_HASH];
    initHash(dataPelanggan);

    while (!isExit) {
        printf("Telkom Phone Management\n");
        printf("[1] Tambah Data\n");
        printf("[2] Hapus Data\n");
        printf("{3] Tampilkan Data\n");
        printf("[4] Keluar\n");
        printf("input: ");
        scanf("%d", &menu);

        switch(menu) {
            case 1:
                getInput("Masukkan nama pelanggan", name, 20);
                getInput("Masukkan alamat pelanggan", alamat, 30);
                addData(dataPelanggan, name, alamat);
                break;
            case 2:
                printf("Masukkan nomor yang ingin dihapuskan: ");
                scanf("%llu", &num);
                removeData(dataPelanggan, num);
                break;
            case 3:
                printData(dataPelanggan);
                break;
            case 4:
                isExit = 1;
                break;
            default:
                printf("Masukkan pilihan yang benar!");
        }
        getch();
        system("cls");
    }
}

void initHash(data *obj) {
    for (int i = 0; i<MAX_HASH; i++) {
        obj[i] = NULL;
    }

    for (int i = 0; i<sizeof(defaultData)/sizeof(struct custInfo); i++) {
        addData(obj, defaultData[i].nama, defaultData[i].alamat);
    }
    printf("Pemuatan data awal selesai...\nTekan Enter untuk Melanjutkan!\n");
    getch();
    system("cls");
}

unsigned lengthOfNum(const ull num) {
    if (num < 10) return 1;
    return 1 + lengthOfNum(num/10);
}

int hashIndex(ull num) {
    int idx = 0;
    while (lengthOfNum(num) > 2) {
        idx += num%10;
        num = num/10;
    }
    return idx;
}

void addData(data* obj, char* name, char* addrs) {
    data cust = malloc(sizeof(struct custInfo));

    cust->nomor = 6281000000000 + (ull)pow(rand(), 4)%(ull)(pow(10, 9));
    int hashIdx = hashIndex(cust->nomor);

    strcpy(cust->nama, name);
    strcpy(cust->alamat, addrs);
    printf("Memuat: %-02d -> %-20s di %-30s [%12llu]\n", hashIdx, cust->nama, cust->alamat, cust->nomor);

    if (obj[hashIdx] == NULL) {
        obj[hashIdx] = cust;
    } else {
        int notAssigned = 1;
        while (notAssigned) {
            if (hashIdx >= MAX_HASH-1) {
                printf("Tidak ada ruang kosong dalam Tabel Hash!\n");
                notAssigned = 0;
            }
            if (obj[++hashIdx] == NULL) {
                obj[hashIdx] = cust;
                notAssigned = 0;
            }
        }
    }
}



void removeData(data* obj, ull num) {
    int hashIdx = hashIndex(num);
    if (obj[hashIdx] != NULL) {
        if (obj[hashIdx]->nomor == num) {
            obj[hashIdx] = NULL;
        }
    } else {
        int notFound = 1;
        while (notFound) {
            if (obj[++hashIdx] != NULL) {
                if (obj[hashIdx]->nomor == num) {
                    obj[hashIdx] = NULL;
                    notFound = 0;
                    break;
                }
            }
            if (hashIdx >= MAX_HASH-1) break;
        }
        if (notFound) printf("Nomor %llu tidak ditemukan!\n", num);
    }
}

void printData(data* obj) {
    printf("%-18s %-15s\n", " ", "Daftar Pelanggan");
    printf("%-4s %-13s %-20s %-30s\n", "No.", "Nomor Telp", "Nama Pelanggan", "Alamat");
    for (int i=0; i<MAX_HASH; i++) {
        if (obj[i] == NULL) continue;
        data curr = obj[i];
        printf("[%d] %llu %-20s %-30s\n", i, curr->nomor, curr->nama, curr->alamat);
    }
}

void getInput(char* prompt, char* var, unsigned len) {
    char* buff = calloc(len, sizeof(char));
    printf("%s: ", prompt);

    fflush(stdin);
    fgets(buff, len, stdin);
    buff = strtok(buff, "\n");
    strcpy(var, buff);
}