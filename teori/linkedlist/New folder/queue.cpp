/* Nama     : AMR FADHILAH ABIYYU ALIF BASYSYAR */
/* NIM      : 231524002                         */
/* Kelas    : 1A - D4                           */

#include "Queue.h"

/*  I M P L E M E N T A S I   F U N G S I   D A N   P R O S E D U R  */

// Deklarasi Variabel Global Bertipe Queue
extern struct Queue Antrian;

/* Implementasi Constructor */

// Melakukan Alokasi dan Inisialisasi Node Baru
struct Node* createNode(int val) {
    struct Node *node;
    node = (struct Node *) malloc(sizeof(struct Node));
    node->value = val;
    node->next = NULL;
    return node;
}


/* Implementasi Accessor */

// Mengambil Nilai Urutan ke-idx
int valueAtIndex(unsigned int idx) {
    struct Node *current = Antrian.front;
    int i = 0;
    while (current != NULL && i != idx) {
        current = current->next;
        i++;
    }
    if (i == idx) {
        return current->value;
    }
    // Jika index melebihi jumlah data
    printf("Index melebihi jumlah data.\n");
    return -9999;
}

// Mencari Urutan Dengan Nilai val
int searchValue(int val) {
    struct Node *current = Antrian.front;
    int idx = 0;
    while (current != NULL && current->value != val) {
        current = current->next;
        idx++;
    }
    if (current->value == val) {
        return idx; 
    }
    // Jika nilai tidak ditemukan
    printf("Nilai tidak ditemukan.\n");
    return -9999;
}

// Mengembalikan Node dengan Nilai Terkecil
struct Node* minValue() {
    struct Node* current = Antrian.front;
    struct Node* min = NULL;
    if  (current != NULL) {
        min = createNode(current->value);
        current = current->next;
    }
    while (current != NULL) {
        if (current->value < min->value) {
            min->value = current->value;
        }
        current = current->next;
    }
    return min;
}


/* Implementasi Mutator */ 

// Menginisialisasikan Queue
void initQueue() {
    Antrian.front = NULL;
    Antrian.rear = NULL;
}

// Menambahkan Node Baru di Belakang
void insertNode(int val) {
    if (Antrian.front == NULL) {
        Antrian.front = createNode(val);
        Antrian.rear = Antrian.front;
    } else {
        Antrian.rear->next = createNode(val);
        Antrian.rear = Antrian.rear->next;
    }
}

// Menghapus Node yang berada di Depan
void deleteNode() {
    if (Antrian.front == NULL) {
        printf("Antrian Kosong.\n");
    } else {
        struct Node *temp = Antrian.front;
        Antrian.front = Antrian.front->next;
        temp->next = NULL;
        free(temp);
    }
}

// Mengurutkan Seluruh Elemen yang Ada Pada Queue
void sortList() {
    struct Queue antrianTemp;
    antrianTemp.front = NULL;
    antrianTemp.rear = (struct Node*) malloc(sizeof(struct Node));
    struct Node* tempMin = NULL;
    struct Node *current = Antrian.front;
    // Selection Sort (Dimodifikasi untuk Linked List)
    while (current != NULL) {
        tempMin = minValue();
        antrianTemp.rear->value = tempMin->value;
        if (antrianTemp.front == NULL) {
            antrianTemp.front = antrianTemp.rear;
        }
        if (current->next == NULL) {
            antrianTemp.rear->next = NULL;
            break;
        }
        antrianTemp.rear->next = (struct Node*) malloc(sizeof(struct Node));
        antrianTemp.rear = antrianTemp.rear->next;
        struct Node *temp = current;
        while (temp != NULL) {
            if (temp->next->value == tempMin->value) {
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
        }
    }
    Antrian = antrianTemp;
}


/* Impelementasi I/O Operator */

// Mencetak Seluruh isi Node Antrian
void printQueue() {
    struct Node *current = Antrian.front;
    while (current != NULL) {
        printf("Value: %d\n", current->value);
        current = current->next;
    }
}


/* Implementasi Destructor */

// Melakukan Dealokasi Seluruh Node
void deallocNode(Node** front) {
    if ((*front)->next != NULL) {
        deallocNode(&((*front)->next));
    }
    free(*front);
}