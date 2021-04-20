#include <stdio.h>
#include <stdlib.h> // rand()
#include <string.h>
#include <time.h> // time()

const int MAX_QUEUE = 25;
typedef struct Queue {
    int head;
    int *body;
    int tail;
} queue;

// Basic Operation
queue *createQueue(size_t size);
int isEmpty(queue *obj);
int isFull(queue *obj);
int enqueue(queue *obj, int item);
int dequeue(queue *obj);
void printQueue(queue *obj);
void clearQueue(queue *obj);

// Extended Operation
int search(queue *obj, int item);
int edit(queue *obj, int dest, int item);
int average(queue *obj);
int sum(queue *obj);
int max(queue *obj);
int min(queue *obj);

// Utils
void init(queue *obj, size_t size);
int getRand();
void editQueue(queue *obj);
void searchQueue(queue *obj);

int main() {
    int size;
    printf("Masukkan ukuran queue: ");
    scanf("%d", &size);

    queue *antrian = createQueue(size);
    if (antrian == NULL) return -1;
    init(antrian, size);
    printQueue(antrian);
    printf("Min. value: %d\n", min(antrian));
    printf("Max. value: %d\n", max(antrian));
    printf("Avg. value: %d\n", average(antrian));
    printf("Sum value: %d\n", sum(antrian));

    searchQueue(antrian);
    editQueue(antrian);
    printQueue(antrian);
}

void searchQueue(queue *obj) {
    int val;
    printf("Masukkan nilai yang ingin dicari: ");
    scanf("%d", &val);
    
    int res = search(obj, val);
    if (res == -1) {
        printf("Nilai tidak ditemukan!\n");
    } else {
        printf("%d ditemukan pada indeks ke-%d\n", val, res);
    }
}

void editQueue(queue *obj) {
    int dest;
    int val;

    printf("Masukkan nilai yang ingin diedit: ");
    scanf("%d", &dest);
    printf("Masukkan nilai baru: ");
    scanf("%d", &val);
    edit(obj, dest, val);
}

queue *createQueue(size_t size) {
    queue *Queue = malloc(sizeof(queue));

    Queue->head = -1;
    Queue->body = malloc(size * sizeof(int *));
    Queue->tail = -1;

    return Queue;
}

int isFull(queue *obj) {
    if (obj->tail != MAX_QUEUE-1) {
        return 0;
    } else {
        return 1;
    }
}

int isEmpty(queue *obj) {
    if (obj->tail == -1) {
        return 1;
    } else {
        return 0;
    }
}

int enqueue(queue *obj, int item) {
    if (item == -1) return -1;
    if (isEmpty(obj)) {
        obj->head = 0;
        obj->body[++obj->tail] = item;
    } else if (!isFull(obj)) {
        obj->body[++obj->tail] = item;
    } else {
        return -1;
    }
}

int dequeue(queue *obj) {
    if (!isEmpty(obj)) {
        int item = obj->body[obj->head];
        for (int i=obj->head; i <= obj->tail-1; i++) {
            obj->body[i] = obj->body[i+1];
        }
        obj->tail--;
        return item;
    } else {
        return -1;
    }
}

void init(queue *obj, size_t size) {
    srand(time(0));
    for (int i=0; i<size; i++) {
        enqueue(obj, getRand());
    }
}

int getRand() {
    int temp = rand();
    if (temp > 10000) return temp/10;
    return temp;
}

void clearQueue(queue *obj) {
    obj->head = obj->tail = -1;
}

void printQueue(queue *obj) {
    for (int i=obj->head; i <= obj->tail; i++) {
        printf("%d, ", obj->body[i]);
    }
    printf("\n");
}

int sum(queue *obj) {
    int sum = 0;
    for (int i=0; i <= obj->tail; i++) {
        sum += obj->body[i];
    }
    return sum;
}

int average(queue *obj) {
    return sum(obj) / obj->tail;
}
int min(queue *obj) {
    int min = obj->body[0];
    if (!isEmpty(obj)) {
        for (int i=0; i <= obj->tail; i++) {
            if (obj->body[i] < min) min = obj->body[i];
        }
    }
    printf("\n");
    return min;
}

int max(queue *obj) {
    int max = obj->body[obj->tail];
    if (!isEmpty(obj)) {
        for (int i=0; i <= obj->tail; i++) {
            if (obj->body[i] > max) max = obj->body[i];
        }
    }
    return max;
}

int search(queue *obj, int item) {
    if (!isEmpty(obj)) {
        for (int i=0; i <= obj->tail; i++) {
            if (obj->body[i] == item) return i;
        }
        return -1;
    } else {
        return -1;
    }
}

int edit(queue *obj, int dest, int item) {
    if (!isEmpty(obj)) {
        queue *temp = createQueue(obj->tail);
        int len = obj->tail;
        int index = search(obj, dest);
        if (index == -1) return -1;
        
        for (int i=0; i < index; i++) enqueue(temp, dequeue(obj));
        enqueue(temp, item);
        dequeue(obj);
        for (int i=0; obj->body[i]; i++) enqueue(temp, dequeue(obj));
        for (int i=0; temp->body[i]; i++) enqueue(obj, dequeue(temp));
    } else {
        return -1;
    }

}