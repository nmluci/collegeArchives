#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node{
    int data;
    struct node* next;
} *llist;

llist createNode(int data);
llist insertAsHead(llist list, int data);
llist insertBefore(llist list, int data, int before);
llist insertAfter(llist list, int data, int after);
llist insertAsTail(llist list, int data);
llist deleteHead(llist list);
llist deleteNode(llist list, int data);
llist deleteTail(llist list);
int isEmpty(llist list);
int printList(llist list);

int main() {
    int ctr, before, after, data;
    int init = 0;
    llist mainList;

    while (ctr != 10) {
        system("cls");
        printf("Implementasi Single Linked List\n");
        printf("Oleh. Albertus Ivan (NIM. 2008561093\n");
        if (init) printList(mainList);
        printf("[1] Buat Linked List Baru\n");
        printf("[2] Insert Head\n");
        printf("[3] Insert Before\n");
        printf("[4] Insert After\n");
        printf("[5] Insert Tail\n");
        printf("[6] Delete Head\n");
        printf("[7] Delete Node\n");
        printf("[8] Delete Tail\n");
        printf("[9] Perika Kondisi List\n");
        printf("[10] Exit\n");
        printf("Input: ");
        scanf("%d", &ctr);

        switch (ctr)
        {
        case 1:
            printf("Masukkan Nilai Awal: ");
            scanf("%d", &data);
            mainList = createNode(data);
            init = 1;
            break;
        case 2:
            printf("Masukkan Nilai: ");
            scanf("%d", &data);
            mainList = insertAsHead(mainList, data);
            break;
        case 3:
            printf("Masukkan Nilai: ");
            scanf("%d", &data);
            printf("Sebelum Nilai: ");
            scanf("%d", &before);
            mainList = insertBefore(mainList, before, data);
            break;
        case 4:
            printf("Masukkan Nilai: ");
            scanf("%d", &data);
            printf("Setelah Nilai: ");
            scanf("%d", &after);
            mainList = insertAfter(mainList, after, data);
            break;
        case 5:
            printf("Masukkan Nilai: ");
            scanf("%d", &data);
            mainList = insertAsTail(mainList, data);
            break;
        case 6:
            mainList = deleteHead(mainList);
            break;
        case 7:
            printf("Masukkan Nilai: ");
            scanf("%d", &data);
            mainList = deleteNode(mainList, data);
            break;
        case 8:
            mainList = deleteTail(mainList);
            break;
        case 9:
            printf("List Kosong: %s\n", (isEmpty(mainList) ? "True" : "False"));
            getch();
            break;
        case 10:
            break;
        default:
            printf("Masukkan Angka Sesuai Yang Tertera!\n");
            getch();
            break;
        }
    }

    exit(0);
}

llist createNode(int data) {
    llist temp = malloc(sizeof(struct node));
    
    temp->data = data;
    temp->next = NULL;

    return temp;
}

llist insertAsHead(llist list, int data) {
    llist new = createNode(data);

    new->next = list;
    return new;
}

llist insertBefore(llist list, int before, int data) {
    llist new = createNode(data);
    llist curr = list;
    llist prev;

    if (isEmpty(list)) {
        printf("Data Kosong!");
        return 0;
    }

    if (list->data == before) {
        curr = insertAsHead(curr, data);
        return curr;
     } else {
        do {
            prev = curr;
            curr = curr->next;
        } while (curr->data != before);
        prev->next = new;
        new->next = curr;
        return list;
     }

}

llist insertAfter(llist list, int after, int data) {
    llist new = createNode(data);
    llist curr = list;
    
    if (isEmpty(list)) {
        printf("Data Kosong!");
        return 0;
    };

    do {
        curr = curr->next;
    } while (curr->data != after);

    new->next = curr->next;
    curr->next = new;
    return list;
}

llist insertAsTail(llist list, int data) {
    llist new = createNode(data);
    llist curr = list;
    
    do {
        curr = curr->next;
    } while (curr->next != NULL);
    curr->next = new;
    return list;
};

llist deleteHead(llist list) {
    if (isEmpty(list)) {
        printf("Data Kosong!");
        return 0;
    } else if (list->next != NULL) {
        llist new = list->next;
        free(list);
        return new;
    } else {
        free(list);
        list->next = NULL;
        return NULL;
    }
}

llist deleteNode(llist list, int data) {
    llist curr = list;
    llist prev;

    if (isEmpty(list)) {
        printf("Data Kosong!");
        return 0;
    } else if (curr->data == data) {
        curr = deleteHead(list);
        return curr;
    } else {
        do {
            prev = curr;
            curr = curr->next;
        } while (curr->data != data);

        prev->next = curr->next;
        free(curr);
        return list;
    }
}

llist deleteTail(llist list) {
    llist curr = list;
    llist prev;

    if (isEmpty(list)) {
        printf("Data Kosong!");
        return 0;
    };

    do {
        prev = curr;
        curr = curr->next;
    } while(curr->next != NULL);
    prev->next = NULL;
    free(curr);
    return list;
}

int printList(llist list) {
    llist curr = list;
    if (isEmpty(list)) {
        printf("Data Kosong!\n");
        return 0;
    };

    do {
        printf("%d -> ", curr->data);
        curr = curr->next;
    } while(curr != NULL);

    printf("\n");
}

int isEmpty(llist list) {
    return list == NULL;
}
