#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    Node *next;
} Node;

typedef struct LinkedList
{
    Node *ListNode = NULL;
    Node *front = NULL;
    Node *rear = NULL;
} LinkedList;

// ! METHOD CONSTRUCTOR
// ? PROCEDURE newNode (Node **node, int val) - Constructing new Node */
void newNode(Node **node, int val);
// ? PROCEDURE newNode (Node **node, int val, Node *next) - Constructing new Node 
void newNode(Node **node, int val, Node *next);
/* PROCEDURE newLinkedList (LinkedList *list, int val) - Constructing new LinkedList */
void newLinkedList(LinkedList *list, int val);
/* PROCEDURE newLinkedList (LinkedList *list, int val, Node *next) - Constructing new LinkedList */
void newLinkedList(LinkedList *list, int val, Node *next);

/* ACCESSOR METHOD */
// FUNCTION int getValFront(LinkedList list) - Return the value of the front Node
int getValFront(LinkedList list);
// FUNCTION int getValRear(LinkedList list) - Return the value of the rear Node
int getValRear(LinkedList list);
// int getValAt(LinkedList list, int index) - Return the value of the Node at a certain index
int getValAt(LinkedList list, int index);

/* MUTATOR METHOD */
// PROCEDURE setValFront(LinkedList *list, int val, int index) - Changing the value of a Node at the front of list.
void setValFront(LinkedList *list, int val);
// PROCEDURE setValFront(LinkedList *list, int val, int index) - Changing the value of a Node at the rear of list.
void setValRear(LinkedList *list, int val);
// PROCEDURE setValAt(LinkedList *list, int val, int index) - Changing the value of a Node at a certain index
void setValAt(LinkedList *list, int val, int index);
/* PROCEDURE pushNode (LinkedList *list, int val) - Adding new Node into the top of the list */
void pushNode(LinkedList *list, int val);
/* PROCEDURE appendNode (LinkedList *list, int val, int index) - Insert new Node into the end of the list */
void appendNode(LinkedList *list, int val);
/* PROCEDURE insertAt (LinkedList *list, int val, int index) - Insert new Node at given index*/
void insertAt(LinkedList *list, int val, int index);
// FUNCTION dequeueList(LinkedList *list) - return the value at the front of the list and dequeue
int dequequeList(LinkedList *list);
// FUNCTION popList(LinkedList *list) - return the value at the end of the list and pop
int popList(LinkedList *list);

/* METHOD I/O OPERATION */
/* INPUT OPERATION */
// inputNewNode(LinkedList *list) - Menginput node baru pada list
void inputNewNode(LinkedList *list);
/* OUTPUT OPERATION */
/* PROCEDURE showList(LinkedList) - print the LinkedList */
void showList(LinkedList list);
// FUNCTION searchVal(Linkedlist) - searching a value in the LinkedList
int searchVal(LinkedList list, int key);

/* DESTRUCTOR METHOD */
void destructList(LinkedList *list);