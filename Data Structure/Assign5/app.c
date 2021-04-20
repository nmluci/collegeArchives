#include <stdio.h>
#include <stdlib.h>
#include <time.h> // time(0)

int isInit = 0;


struct llist_t {
    int data;
    struct llist_t* next;
};
typedef struct llist_t* llist; // singly linked list

struct queue_t {
    int front;
    llist data;
    int rear;
};

struct stack_t {
    int top;
    llist data;
};

typedef struct queue_t* queue; // queue
typedef struct stack_t* stack; // stack


// Queue Operation
queue newQueue(queue obj);
void enqueueCar(queue obj, int item);
void dequeueCar(queue obj, int item);
int isEmptyQueue(queue obj);

// Utils
llist newList(llist obj, int item);
queue randPark(queue obj, int size);
void printPark(queue obj);

// Caching System
stack newCache(stack obj);
void pushCache(stack obj, int item);
llist popCache(stack obj);
void deleteCache(stack obj);
int isEmptyStack(stack obj);

int main() {
    queue carPark;
    int ans = 0;
    int item;
    size_t size;

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
        if (ans !=4) system("cls");
    }
    printf("Terima Kasih!");
}

queue newQueue(queue obj) {
    queue temp = malloc(sizeof(struct queue_t));
    temp->front = -1;
    temp->data = newList(temp->data, 0);
    temp->rear = -1;
    return temp;
}

stack newStack(stack obj) {
    stack temp = malloc(sizeof(struct stack_t));
    temp->top = -1;
    temp->data = newList(temp->data, -1);
    return temp;
}

void enqueueCar(queue obj, int item) {
    llist curr = obj->data;
    llist prev;
    llist new = newList(new, item);

    if (isEmptyQueue(obj)) {
        curr->data = item;
    } else {
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new;
    }
    obj->front = 0;
    obj->rear += 1;
}

void dequeueCar(queue obj, int item) {
    llist curr = obj->data;
    stack cache = newStack(cache);

    if (curr->data == item) {
        obj->data = curr->next;
    } else {
        llist new;

        do {
            pushCache(cache, curr->data);
            curr = curr->next;
        } while (curr->data != item);

        obj->data = curr->next;
        while (!isEmptyStack(cache)) {
            new = popCache(cache);
            new->next = obj->data;
            obj->data = new;
        }
        deleteCache(cache);
    }
}

int isEmptyQueue(queue obj) {
    return obj->rear == -1 ? 1 : 0;
}

int isEmptyStack(stack obj) {
    return obj->top == -1 ? 1 : 0;
}

queue randPark(queue obj, int sum) {
    srand(time(0));
    queue new = newQueue(new);
    for (int i=0; i<sum; i++) enqueueCar(new, (rand() % 251));
    return new;
}

llist newList(llist obj, int item) {
    llist new = malloc(sizeof(struct llist_t));
    new->data = item;
    new->next = NULL;
    return new;
}

void printPark(queue obj) {
    if (isEmptyQueue(obj)) {
        printf("Parkir Kosong!\n");
        return;
    };

    llist curr = obj->data;
    do {
        printf("[%d]. ", curr->data);
        curr = curr->next;
    } while (curr != NULL);
    printf("\n");
}

stack newCache(stack obj) {
    stack new = malloc(sizeof(struct stack_t));
    new->top = -1;
    new->data = newList(new->data, 0);
}

void pushCache(stack obj, int item) {
    llist new = newList(new, item);
    llist curr = obj->data;

    if (isEmptyStack(obj)) {
        curr->data = item;
    } else {
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new;
    }

    obj->top++;
}

llist popCache(stack obj) {
    if (isEmptyStack(obj)) return NULL;

    llist curr = obj->data;
    llist out;

    if (obj->top != 0) {
        while (curr->next->next != NULL) {
            curr = curr->next;
        }

        out = curr->next;
        curr->next = NULL;
    } else {
        out = curr;
        curr = NULL;
    }
    obj->top--;
    return out;
}

void deleteCache(stack cache) {
    free(cache->data);
    free(cache);
}