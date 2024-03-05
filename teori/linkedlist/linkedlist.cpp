#include "linkedlist.h"

// Constructor: Alokasi dan Inisiasi Node Baru
struct Node *createNode(int nilai) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Alokasi memori gagal.\n");
        exit(1);
    } else {
        node->data = nilai;
        node->next = NULL;
        return node;
    }
}

// Mutator: Inisialisasi List
void initList(List *L) {
    L->front = NULL;
    L->rear = NULL;
}

// Mutator: Menambahkan Node di Awal
void insertAtBeginning(List *L, int nilai) {
    struct Node *node = createNode(nilai);
    if (L->front == NULL) {
        L->front = node;
        L->rear = node;
        node->next = NULL;
    } else {
        node->next = L->front;
        L->front = node;
    }
}

// Mutator: Menambahkan Node di Akhir
void insertAtEnd(List *L, int nilai) {
    struct Node *node = createNode(nilai);
    if (L->rear == NULL) {
        L->front = node;
        L->rear = node;
    } else {
        L->rear->next = node;
        L->rear = node;
    }
}

// Mutator: Menghapus Node di Awal
void deleteFromBeginning(List *L) {
    if (L->front == NULL) {
        printf("List kosong\n");
    } else {
        struct Node *temp = L->front;
        L->front = L->front->next;
        if (L->front == NULL) {
            L->rear = L->front;
        }
        free(temp);
    }
}

// Mutator: Menghapus Node di Akhir
void deleteFromEnd(List *L) {
    if (L->rear == NULL) {
        printf("List kosong\n");
    } else if (L->front->next == NULL) {
        // Hanya ada satu node dalam list
        free(L->rear);
        L->front = NULL;
        L->rear = NULL;
    } else {
        struct Node *keduaAkhir = L->front;
        while (keduaAkhir->next->next != NULL) {
            keduaAkhir = keduaAkhir->next;
        }
        free(keduaAkhir->next);
        keduaAkhir->next = NULL;
        L->rear = keduaAkhir;
    }
}

// Accessor: Mendapatkan nilai data dari index tertentu
int getAtIndex(List *L, int index) {
    struct Node *p = L->front;
    for (int i = 0; (p != NULL) && (i < index); i++) {
        p = p->next;
    }
    if (p == NULL) {
        printf("Node tidak ditemukan\n");
        exit(1);
    }
    return p->data;
}

// I/O Operation: Tampilkan List
void displayList(List *L) {
    struct Node *p = L->front;
    if (p == NULL) {
        printf("Isi List: NULL\n");
        printf("Front: NULL, Rear: NULL\n\n");
    } else {
        printf("Isi List: ");
        while (p != NULL) {
            printf("%d -> ", p->data);
            p = p->next;
        }
        printf("NULL\n");
        printf("Front: %d, ", L->front->data);
        printf("Rear: %d\n\n", L->rear->data);
    }
}

// Destructor: Hapus dan dealokasi seluruh Node
void deleteList(List *L) {
    while (L->front != NULL) {
        deleteFromBeginning(L);
    }
}

// Body main
int main() {
    struct List linkedlist;
    initList(&linkedlist);
    displayList(&linkedlist);

    insertAtEnd(&linkedlist, 32);
    displayList(&linkedlist);

    insertAtBeginning(&linkedlist, 90);
    displayList(&linkedlist);

    insertAtBeginning(&linkedlist, 50);
    displayList(&linkedlist);

    insertAtEnd(&linkedlist, 12);
    displayList(&linkedlist);

    insertAtEnd(&linkedlist, 22);
    displayList(&linkedlist);

    insertAtBeginning(&linkedlist, 41);
    displayList(&linkedlist);

    deleteFromEnd(&linkedlist);
    displayList(&linkedlist);

    deleteFromBeginning(&linkedlist);
    displayList(&linkedlist);

    printf("Index ke-3: %d\n\n", getAtIndex(&linkedlist, 3));
    printf("Index ke-1: %d\n\n", getAtIndex(&linkedlist, 1));

    deleteList(&linkedlist);
    displayList(&linkedlist);
    return 0;
}