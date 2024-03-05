#include <stdio.h>
#include <stdlib.h>

// Deklarasi tipe data Node
struct Node {
    int data;
    struct Node* next;
};

struct List {
    struct Node *front, *rear;
};

// Constructor
struct Node* createNode(int nilai);

// Mutator
void initList(List* L);
void insertAtBeginning(List* L, int nilai);
void insertAtEnd(List* L, int nilai);
void deleteFromBeginning(List* L);
void deleteFromEnd(List* L);

// Accessor
int getAtIndex(List* L, int index);

// Destructor
void deleteList(List* L);

// I/O Operation
void displayList(List* L);