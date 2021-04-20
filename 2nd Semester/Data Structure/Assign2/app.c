#include <stdio.h>
#include <stdlib.h> 
#include <string.h>  
#include <conio.h> 

int size = 0;

typedef struct item {
        int code;
        char name[20];
        char material[20];
        int quantity;
        int price;
    } items;


int toInt(char *val) {
    if (atoi(val) != 0) {
        return atoi(val); 
    } else {
        printf("Tolong Masukkan Angka\n");
        getch();
        exit(-1);
    }
}

void getInput(char *prompt, char *var) {
    char *buff = calloc(20, sizeof(char));
    printf("%s: ", prompt);
    fflush(stdin);
    fgets(buff, 20, stdin);
    buff = strtok(buff, "\n");
    strcpy(var, buff);
}

int menu() {
    int opt = 0;
    printf("%50s%s\n", " ", "Inventory System");
    printf("%52s%s\n", " ", "Toko Mebel");
    printf("%47s%s\n", " ", "Albertus Ivan Suryawan");
    printf("%50s%s\n\n", " ", "NIM. 2008561093");
    printf("\n\n");
    printf("%47s%s\n", " ", "[1] Masukkan Data");
    printf("%47s%s\n", " ", "[2] Tampilkan Daftar Barang");
    printf("%47s%s\n", " ", "[3] Keluar");
    printf("%47s%s", " ", "Pilihan [1/2/3]: ");
    scanf("%d", &opt);
    return opt;
}

void printInv(items *barang) {
    // system("cls");
    printf("| Kode Produk | Nama Produk | Bahan Produk | Jumlah | Harga (Rupiah) |\n", "");
    if (size == 0) {
        printf("\n%35s", "Tidak Ada Data");
        getch();
        // system("cls");
        return;
    }
    for (int i=0; i<size; i++) {
        printf("| %-11d | %-11s | %-12s | %-6d | Rp %-11d |\n",
                barang[i].code,
                barang[i].name,
                barang[i].material,
                barang[i].quantity,
                barang[i].price);
    }
    printf("\nJumlah barang: %d item\n", size);
    getch();
    // system("cls");
}

void addItem(items *barang) {
    // system("cls");
    size++;
    char temp[20];
    barang = realloc(barang, size*sizeof(items));
    if (barang == NULL) {
        printf("Realokasi memori gagal!\n");
        getch();
        exit(-1);
    }

    getInput("Kode Produk", temp);
    barang[size-1].code = toInt(temp);

    getInput("Nama Produk", barang[size-1].name);
    getInput("Bahan Produk", barang[size-1].material);

    getInput("Jumlah", temp);
    barang[size-1].quantity = toInt(temp);

    getInput("Harga Produk", temp);
    barang[size-1].price = toInt(temp);

    // system("cls");
}

int main() {
    items *barang = malloc(sizeof(items));
    int opt = 0;
    while(opt != 3) {
        opt = menu();
        if (opt == 1) {
            addItem(barang);
        } else if (opt == 2) {
            printInv(barang);
        }
    }
    free(barang);
    printf("Terima Kasih");
    return 0;
}