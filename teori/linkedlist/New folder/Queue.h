/* Nama     : AMR FADHILAH ABIYYU ALIF BASYSYAR */
/* NIM      : 231524002                         */
/* Kelas    : 1A - D4                           */

#include <stdio.h>
#include <stdlib.h>

/*  D E K L A R A S I   T I P E   D A T A,   F U N G S I   D A N   P R O S E D U R  */

// Deklarasi tipe data Node
struct Node {
    int value;
    struct Node* next;
};

// Deklarasi struct Queue
struct Queue {
    struct Node *front, *rear;
};

// Deklarasi Constructor
struct Node* createNode(int);

// Deklarasi Accessor
int valueAtIndex(unsigned int);
int searchValue(int);
struct Node* minValue();

// Deklarasi Mutator
void initQueue();
void insertNode(int);
void deleteNode();
void sortList();

// Deklarasi I/O Operator
void printQueue();

// Deklarsi Destructor
void deallocNode(Node**);