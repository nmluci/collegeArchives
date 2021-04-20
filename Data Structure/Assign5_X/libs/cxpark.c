#include "cxpark.h"

// INITIALIZATION
queue newQueue(queue obj) {
    queue temp = malloc(sizeof(sizeof(struct queue_t)));
    temp->front = -1;
    temp->data = newList(temp->data, 0);
    temp->rear = -1;
    return temp;
}

llist newList(llist obj, int item) {
    llist new = malloc(sizeof(struct llist_t));
    new->data = item;
    new->next = NULL;
    return new;
}

stack newCache(stack obj) {
    stack new = malloc(sizeof(struct stack_t));
    new->top = -1;
    new->data = newList(new->data, 0);
}

void enqueueCar(queue obj, int item) {
    llist currItem = obj->data;
    llist new = newList(new, item);

    if (isEmptyQueue(obj)) {
        currItem->data = item;
        obj->front = 0;
    } else {
        while (currItem->next != NULL) {
            currItem = currItem->next;
        }
        currItem->next = new;
    }
    obj->rear += 1;
}

void dequeueCar(queue obj, int item) {
    llist currItem = obj->data;
    stack cache = newCache(cache);

    if (currItem->data == item) {
        obj->data = currItem->next;
    } else {
        llist new;

        do {
            pushCache(cache, currItem->data);
            currItem = currItem->next;
        } while (currItem->data != item);

        obj->data = currItem->next;
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

queue randPark(queue obj, unsigned size) {
    srand(time(0));
    queue new = newQueue(new);
    for (int i=0; i < size; i++) enqueueCar(new, (rand() % 251));
    return new;
}

void printPark(queue obj) {
    if (isEmptyQueue(obj)) {
        printf("Parkir Kosong!\n");
        return;
    }

    llist currItem = obj->data;
    do {
        printf("[%d]. ", currItem->data);
        currItem = currItem->next;
    } while (currItem != NULL);
    printf("\n");
}


void pushCache(stack obj, int item) {
    llist new = newList(new, item);
    llist currItem = obj->data;

    if (isEmptyStack(obj)) {
        currItem->data = item;
    } else {
        while (currItem->next != NULL) {
            currItem = currItem->next;
        }
        currItem->next = new;
    }

    obj->top++;
}

llist popCache(stack obj) {
    if (isEmptyStack(obj)) return NULL;

    llist currItem = obj->data;
    llist out;

    if (obj->top !=0) {
        while(currItem->next->next != NULL) {
            currItem = currItem->next;
        }

        out = currItem->next;
        currItem->next = NULL;
    } else {
        out = currItem;
        currItem = NULL;
    }
    obj->top--;
    return out;
}

void deleteCache(stack cache) {
    free(cache->data);
    free(cache);
}

int isEmptyStack(stack obj) {
    return obj->top == -1 ? 1 : 0;
}