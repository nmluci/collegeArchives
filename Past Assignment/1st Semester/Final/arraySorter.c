#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>

// Main Function
int init();         // Initialization
void sort();        // Sort
void search();      // Search
void insert();      // Insert
void update();      // Update
void delete();      // Delete
int count();        // Count
void arrMin();      // Min
void arrMax();      // Max
void avg();         // Average
void odd();         // Odd
void even();        // Even
void bSort();       // bubble sort
void iSort();       // insertion sort
void sSort();       // selection sort
int binSearch();    // binary search
// Utilities
int arrCount();     // Count Quantity of an Array
int isPrime();      // Primality Test
void cls();         // ClearScreen Implementation for macOS, Unix-like, and WIN
void swap();        // Swap
void graceExit();   // Grace Exit
void printArray();  // Print Formatted Array
void printArrayCON();  // Print Formatted Array (to Terminal Only)
void printError();  // Print Error Message
void printInfo();   // Print Information
void menu();        // Menu

const int ARRLIMIT = 20;
char fName[50];
int isExit = 0;
int isInit = 0;
FILE *logFile;

int main() {
    int arr[20];
    int mode;
    int arrLen = 0;
    int num1 = 0;
    int num2 = 0;
    char args[3];
    char order[6];

    puts("*********************************");
    puts("**********  UAS ALPRO  **********");
    puts("**** Albertus Ivan Suryawan *****");
    puts("********** 2008561093 ***********");
    puts("*********************************");

    int choice=0;
    do {
        if (choice) {
            arrLen = arrCount(arr);
            if (choice != 1) printArrayCON(arr, arrLen, "Array");
        }
        puts("(1) init");
        puts("(2) sort");
        puts("(3) search");
        puts("(4) insert");
        puts("(5) update");
        puts("(6) delete");
        puts("(7) count");
        puts("(8) min");
        puts("(9) max");
        puts("(10) average");
        puts("(11) ganjil");
        puts("(12) genap");
        puts("(13) exit");
        puts("");
        printf("Masukkan pilihan berupa angka (1, 2, dst..): ");
        scanf("%d", &choice);

        cls();
        if (choice == 13) exit(0);

        if (isInit) {
            if (choice == 1) {
                printf("Masukan jumlah bilangan [max: 20]: "); scanf("%d", &arrLen);
                printf("Masukan tipe bilangan [n/p]: "); scanf("%s", args);
                init(arr, arrLen, args);
                isInit = 1;
            }

            if (choice == 2) {
                printf("Sorting Algorithm\n[1] Bubble Sort\n[2] Selection Sort\n[3] Insertion Sort\n");
                printf("Masukkan jenis algoritma yang digunakan [1, 2, 3]: ");
                scanf("%d", &mode);
                printf("\nPengurutan\n[asc] Ascending\n[desc] Descending\n");
                printf("\nMasukkan jenis pengurutan [asc/desc]: ");
                scanf("%s", order);
                sort(arr, arrLen, order, mode);
            }

            if (choice == 3) {
                printf("\nMasukkan nilai yang ingin dicari: ");
                scanf("%d", &num1);
                search(arr, arrLen, num1);
                printf("\n");
            }

            if (choice == 4) {
                printf("Masukkan nilai untuk dimasukkan: ");
                scanf("%d", &num1);
                printf("\nPengurutan\n[asc] Ascending\n[desc] Descending\n");
                printf("Masukkan jenis pengurutan [asc/desc]: ");
                scanf("%s", order);
                insert(arr, arrLen, num1, order);
            }

            if (choice == 5) {
                printf("Masukkan nilai yang lama: ");
                scanf("%d", &num1);
                printf("Masukkan nilai yang baru: ");
                scanf("%d", &num2);
                printf("\nPengurutan\n[asc] Ascending\n[desc] Descending\n");
                printf("Masukkan jenis pengurutan [asc/desc]: ");
                scanf("%s", order);
                update(arr, arrLen, num2, num1, order);
            }

            if (choice == 6) {
                printf("Masukkan nilai untuk dihapus: ");
                scanf("%d", &num1);
                printf("\nPengurutan\n[asc] Ascending\n[desc] Descending\n");
                printf("Masukkan jenis pengurutan [asc/desc]: ");
                scanf("%s", order);
                delete(arr, arrLen, num1, order);
            }

            if (choice == 7) {
                count(arr);
            }

            if (choice == 8) {
                arrMin(arr, arrLen);
            }

            if (choice == 9) {
                arrMax(arr, arrLen);
            }

            if (choice == 10) {
                avg(arr, arrLen);
            }

            if (choice == 11) {
                odd(arr, arrLen);
            }

            if (choice == 12) {
                even(arr, arrLen);
            }
            getch();
            cls();
        } else {
            if (choice == 1) {
                printf("Masukan jumlah bilangan [max: 20]: "); scanf("%d", &arrLen);
                printf("Masukan tipe bilangan [n/p]: "); scanf("%s", args);
                init(arr, arrLen, args);
                isInit = 1;
            } else {
                printError("menu", "Jalankan menu INIT terlebih dahulu!");
            }
            getch();
            cls();
        }
        
    } while(!isExit);
    graceExit();
}

int init(int arr[], int size, char *method) {
    char msg[20];
    snprintf(msg, sizeof(msg), "init(%s, %d)\n", method, size);
    printInfo("input", msg);
    srand(time(0)); // Seed randomized using time(0)
    int year, month, day, h, m, s;

    time_t now = time(0);
    struct tm local = *localtime(&now);
    year=local.tm_year+1900;
    month = local.tm_mon+1;
    day = local.tm_mday;
    h = local.tm_hour;
    m = local.tm_min;
    s = local.tm_sec; 
    char fileName[50];
    snprintf(fileName, sizeof(fileName), "%d%02d%02d_%02d%02d%02d.txt", year, month, day, h, m, s);

    logFile = fopen(fileName, "a");
    if (strcmp(method, "n") != 0 && strcmp(method, "p") != 0) {
        char err[15] = "Invalid option";
        printError("init", err);
    } else {
        for (int i=0; i < size; i++) {
            if (strcmp(method, "n") == 0) {
                arr[i] = rand();
            } else {
                int found = 0;
                while (!found) {
                    int temp = rand();
                    if (isPrime(temp) != 0) {
                        arr[i] = temp;
                        found = 1;
                    }
                }
            }
        }
        // make sures no garbage value
        for (int i=size; i < ARRLIMIT; i++) arr[i] = 0;
    }
    printArray(arr, 20, "init");
}

void sort(int sortArr[], int size, char *sortOrder, int sortMethod) {
    char msgInfo[20];
    snprintf(msgInfo, sizeof(msgInfo), "sort(%s, %d)\n", sortOrder, sortMethod);
    printInfo("input", msgInfo);
    if ((sortMethod != 1 && sortMethod != 2 && sortMethod != 3) || (strcmp(sortOrder, "asc") != 0 && strcmp(sortOrder, "desc") != 0)) {
        char err[20] = "Invalid Option";
        printError("sort", err);
    };
    int methodOrder;
    char *msgMethod;
    char *msgOrd;

    if (strcmp(sortOrder, "asc") == 0) {
        msgOrd = "Ascending";
        methodOrder = 1;
    } else {
        msgOrd = "Descending";
        methodOrder = 0;
    }
    
    if (sortMethod == 1) {
        bSort(sortArr, size, methodOrder);
        msgMethod = "Bubble";
    }
    if (sortMethod == 2) {
        sSort(sortArr, size, methodOrder);
        msgMethod = "Selection";
    }
    if (sortMethod == 3) {
        iSort(sortArr, size, methodOrder);
        msgMethod = "Insertion";
    }
    char msg[30];
    snprintf(msg, sizeof(msg), "Methode: %s (%s)\n", msgMethod, sortOrder);
    printInfo("sort", msg);
    printArray(sortArr, size, "sort");
}

void bSort(int arr[], int size, int method) {
    for (int i=0; i < size-1; i++) {
        for (int j=0; j < size-i-1; j++) {
            if (method) {
                if (arr[j] > arr[j+1]) swap(&arr[j], &arr[j+1]);
            } else {
                if (arr[j] < arr[j+1]) swap(&arr[j], &arr[j+1]);
            }
        }
    }
    arrCount(arr);
};


void sSort(int arr[], int size, int method) {
    for (int i=0; i < size - 1; i++) {
        int minIdx = i;
        for (int j=i+1; j < size; j++) {
            if (method) {
                if (arr[j] < arr[minIdx]) minIdx = j;
            } else {
                if (arr[j] > arr[minIdx]) minIdx = j;
            }
        }
        swap(&arr[minIdx], &arr[i]);
    }
    arrCount(arr);
};

void iSort(int arr[], int size, int method) {
    for (int i=1; i < size; i++) {
        int temp = arr[i];
        int j = i - 1;

        if (method) {
            while (temp < arr[j] && j >= 0) {
                arr[j+1] = arr[j];
                j--;
            }
        } else {
            while (temp > arr[j] && j >= 0) {
                arr[j+1] = arr[j];
                j--;
            }
        }
        arr[j+1] = temp;
    }
    arrCount(arr);
};

void search(int arr[], int size, int num) {
    char msg[50];
    snprintf(msg, sizeof(msg), "search(%d)\n", num);
    printInfo("input", msg);
    sort(arr, size, "asc", 1);
    int res = binSearch(arr, size, num);
    if (res == -1) printError("search", "Tidak ada!");
    char msgInfo[50];
    snprintf(msgInfo, sizeof(msgInfo), "%d ditemukan pada indeks ke-%d\n", arr[res], res);
    printInfo("search", msgInfo);
}

int binSearch(int arr[], int size, int num) {
    int left = 0;
    int right = size-1;
    int mid = -1;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (arr[mid] == num) {
            return mid;
        } else {
            if (arr[mid] < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
};

void insert(int arr[], int size, int num, char *sortOrder) {
    char msgInfo[20];
    snprintf(msgInfo, sizeof(msgInfo), "insert(%d, %s)\n", num, sortOrder);
    printInfo("input", msgInfo);
    if (size == ARRLIMIT) printError("insert", "Index Penuh!");
    arr[size] = num;
    int order = 1;
    int len = arrCount(arr); // Recheck the size after modification
    if (strcmp(sortOrder, "desc") == 0) order = 0;
    bSort(arr, len, order);
    printArray(arr, len, "insert");
}

void update(int arr[], int size, int num, int target, char *sortOrder) {
    char msgInfo[30];
    snprintf(msgInfo, sizeof(msgInfo), "update(%d, %d, %s)\n", num, target, sortOrder);
    printInfo("input", msgInfo);
    int order = 1;
    bSort(arr, size, 1);
    int res = binSearch(arr, size, target);
    if (res == -1) printError("update", "Element not found!");
    arr[res] = num;
    if (strcmp(sortOrder, "desc") == 0) order = 0;
    bSort(arr, size, order);
    printArray(arr, size, "update");
}

void delete(int arr[], int size, int num, char *sortOrder) {
    char msgInfo[20];
    snprintf(msgInfo, sizeof(msgInfo), "delete(%d, %s)\n", num, sortOrder);
    printInfo("input", msgInfo);
    int order = 1;
    char delMsg[50];
    bSort(arr, size, 1);
    int res = binSearch(arr, size, num);
    if (res == -1) {
        snprintf(delMsg, sizeof(delMsg), "Tidak ada elemen %d didalam array", num);
        printError("delete", delMsg);
    }
    arr[res] = 0;
    if (strcmp(sortOrder, "desc") == 0) order = 0;
    bSort(arr, size, order);
    int len = arrCount(arr);
    printArray(arr, len, "delete");
}

int count(int arr[]) {
    char msgInfo[20];
    snprintf(msgInfo, sizeof(msgInfo), "count(arr)\n");
    printInfo("input", msgInfo);
    int len = arrCount(arr);
    char val[3];
    snprintf(val, sizeof(val), "%d\n", len);
    printInfo("count", val);
}

void arrMax(int arr[], int size) {
    char msgInfo[20];
    snprintf(msgInfo, sizeof(msgInfo), "max(arr)\n");
    printInfo("input", msgInfo);
    bSort(arr, size, 1);
    char maxMsg[50];
    snprintf(maxMsg, sizeof(maxMsg), "Nilai maksimum dari array ini adalah %d\n", arr[size-1]);
    printInfo("max", maxMsg);
}

void arrMin(int arr[], int size) {
    char msgInfo[20];
    snprintf(msgInfo, sizeof(msgInfo), "min(arr)\n");
    printInfo("input", msgInfo);
    bSort(arr, size, 1);
    char minMsg[50];
    snprintf(minMsg, sizeof(minMsg), "Nilai minimum dari array ini adalah %d\n", arr[0]);
    printInfo("min", minMsg);
}

void avg(int arr[], int size) {
    char msgInfo[20];
    snprintf(msgInfo, sizeof(msgInfo), "average(arr)\n");
    printInfo("input", msgInfo);
    double sum = 0;
    for (int i=0; i<size; i++) sum += arr[i];
    char avgMsg[50];
    snprintf(avgMsg, sizeof(avgMsg), "Nilai rata-rata dari array ini adalah %.2f\n", (double)sum/size);
    printInfo("avg", avgMsg);
}

void odd(int arr[], int size) {
    char msgInfo[20];
    snprintf(msgInfo, sizeof(msgInfo), "ganjil(arr)\n");
    printInfo("input", msgInfo);
    int oddCount = 0;
    int oddArr[20];
    char oddMsg[50];
    for (int i=0; i<size; i++) {
        if (arr[i] % 2 != 0) {
            oddArr[oddCount] = arr[i];
            oddCount+=1;
        }
    }
    for (int j=oddCount; j<ARRLIMIT; j++) oddArr[j] = 0;
    printArray(oddArr, oddCount, "odd");
    snprintf(oddMsg, sizeof(oddMsg), "Terdapat %d elemen ganjil didalam array\n", arrCount(oddArr));
    printInfo("odd", oddMsg);
}

void even(int arr[], int size) {
    char msgInfo[20];
    snprintf(msgInfo, sizeof(msgInfo), "genap(arr)\n");
    printInfo("input", msgInfo);
    int evenCount = 0;
    int evenArr[20];
    char evenMsg[50];
    for (int i=0; i<size; i++) {
        if (arr[i] % 2 == 0) {
            evenArr[evenCount] = arr[i];
            evenCount+=1;
        }
    }
    for (int j=evenCount; j<ARRLIMIT; j++) evenArr[j] = 0;
    printArray(evenArr, evenCount, "even");
    snprintf(evenMsg, sizeof(evenMsg), "Terdapat %d elemen genap didalam array\n", arrCount(evenArr));
    printInfo("even", evenMsg);

}

// Utils Blocks
void graceExit() {
    fclose(logFile); // fclose put here to flush the buffer in one time
    exit(0);
}

int arrCount(int arr[]) {
    int arrLen = 0;
    for (int i=0; i<ARRLIMIT; i++) {
        if (arr[i] > 0) arrLen += 1;
    }
    return arrLen;
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
};

void printError(char *cmd, char *msg) {
    printf("[ERROR] %s di %s\n", msg, cmd);
    fprintf(logFile, "[ERROR] %s di %s\n", msg, cmd);
    getch();
    cls();
    main();
};

void printInfo(char *cmd, char *msg) {
    printf("[%s] %s", cmd, msg);
    fprintf(logFile, "[%s] %s", cmd, msg);
};

void printArray(int arr[], int size, char *cmd) {
    printf("[%s] ", cmd);
    fprintf(logFile, "[%s] ", cmd);
    for (int idx=0; idx < size; idx++) {
        if (arr[idx] > 0) {
            printf("[%d] ", arr[idx]);
            fprintf(logFile, "[%d] ", arr[idx]);
        }
        if (arr[idx] < 0) {
            printf("[] ");
            fprintf(logFile, "[] ");
        }
    }
    printf("\n");
    fprintf(logFile, "\n");
};


void printArrayCON(int arr[], int size, char *cmd) {
    printf("[%s] ", cmd);
    for (int idx=0; idx < size; idx++) {
        if (arr[idx] > 0) printf("[%d] ", arr[idx]);
        if (arr[idx] < 0) printf("[] ");
    }
    printf("\n");
};

int isPrime(int num) {
    for (int i = 2; i*i < num; i++) {
        if (num % i == 0) return 0;
    }
    return num;
};

void cls() {
    #ifdef __WIN32
        system("cls");
    #elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
        system("clear");
    #else
        printError("misc", "UNKOWN OS");
    #endif
}
