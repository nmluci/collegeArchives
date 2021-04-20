#include "libs\cxpark.h"

int isInit = 0;

int main() {
    queue carPark;
    int ans = 0;
    int item;
    unsigned size;

    while (ans<=3) {
        printf("Parking System\n");
        printf("===============\n");

        if (isInit) {
            printf("Kondisi Parkiran\n");
            printPark(carPark);
            printf("===============\n");
        }
        printf("[1] Randomisasi Antrean Parkir\n");
        printf("[2] Masukkan Mobil\n");
        printf("[3] Keluarkan Mobil\n");
        printf("[4] Keluar\n");
        printf("Ketikkan Pilihan Anda: ");
        scanf("%d", &ans);

        ans = (isInit == 0 && ans >= 2) ? 0 : ans;
        switch (ans)
        {
            case 1:
                printf("Masukkan ukuran: ");
                scanf("%d", &size);
                carPark = randPark(carPark, size);
                isInit = 1;
                break;
            case 2:
                printf("Masukkan item yang ingin dimasukkan (numerik): ");
                scanf("%d", &item);
                enqueueCar(carPark, item);
                break;
            case 3:
                printf("Masukkan item yang ingin dikeluarkan (numerik): ");
                scanf("%d", &item);
                dequeueCar(carPark, item);
                break;
            case 4:
                break;
            default:
                printf("Masukkan angka sesuai menu!\n");
                exit(-1);
        }
        // if (ans !=4) system("cls");
    }
    printf("Terima Kasih!");
}