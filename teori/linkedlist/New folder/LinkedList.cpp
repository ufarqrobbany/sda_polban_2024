#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

/**
 * typedef struct Node {
 *      int val;
 *      Node *next;
 * }
*/

/**
 * typedef struct LinkedList {
 *      Node *ListNode;
 *      Node *front;
 *      Node *rear;
 * }
*/

// ! METHOD CONSTRUCTOR
// * PROCEDURE newNode (Node **node, int val) - Constructor untuk tipe data Node
void newNode(Node **node, int val) {
    (*node) = (Node*) malloc(sizeof(Node)); // Alokasi Memori

    if ((*node) != NULL) { // Jika Alokasi Memori Berhasil
        (*node)->val = val;
        (*node)->next = NULL;
    }
    else { // Jika Alokasi Memori Gagal
        printf("Node.newNode: Memory Allocation Failed.\n");
    }
}
// * PROCEDURE newNode (Node **node, int val, Node *next) - Constructing new Node
void newNode(Node **node, int val, Node *next) {
    (*node) = (Node*) malloc(sizeof(Node)); // Alokasi Memori

    if ((*node) != NULL) { // Alokasi Memori Berhasil
        (*node)->val = val;
        (*node)->next = next;
    }
    else { // Alokasi Memori Gagal
        printf("Node.newNode: Memory Allocation Failed.\n");
    }
}
// * PROCEDURE newLinkedList (LinkedList *list, int val) - Constructing new LinkedList
void newLinkedList(LinkedList *list, int val) {
    Node *new_node; // Deklarasi new_node
    newNode(&new_node, val); // Alokasi new_node

    if (new_node != NULL) {
        list->ListNode = new_node;
        list->front = new_node;
        list->rear = new_node;
    }
    else
        printf("LinkedList.newLinkedList: Memory Allocation Failed.\n");
}
// * PROCEDURE newLinkedList (LinkedList *list, int val, Node *next) - Constructing new LinkedList
void newLinkedList(LinkedList *list, int val, Node *next) {
    Node *new_node;
    newNode(&new_node, val, next);

    if (new_node != NULL) {
        list->ListNode = new_node;
        list->front = new_node;
        list->rear = new_node->next;
    }
    else
        printf("LinkedList.newLinkedList: Memory Allocation Failed.\n");

}

// ! ACCESSOR METHOD
// FUNCTION int getValFront(LinkedList list) - Return the value of the front Node
int getValFront(LinkedList list) {
    if (list.front != NULL) 
        return list.front->val;
    else {
        printf("LinkedList.getValFront: Empty List.\n");
        return -999;
    }
}
// FUNCTION int getValRear(LinkedList list) - Return the value of the rear Node
int getValRear(LinkedList list) {
    if (list.rear != NULL)
        return list.rear->val;
    else {
        printf("LinkedList.getValRear: Empty List.\n");
        return -999;
    }
}
// int getValAt(LinkedList list, int index) - Return the value of the Node at a certain index
int getValAt(LinkedList list, int index) {
    int curIndex = 0;
    Node *cur = list.front;

    while (cur != NULL && curIndex < index) {
        cur = cur->next;
        curIndex++;
    }
    
    if (cur != NULL)
        return cur->val;
    else
    {
        printf("LinkedList.getValAt: Index Out of Bound.");
        return -999;
    }
    
}

// ! MUTATOR METHOD
// * PROCEDURE setValFront(LinkedList *list, int val, int index) - Changing the value of a Node at the front of list.
void setValFront(LinkedList *list, int val) {
    if (list->front != NULL)
        list->front->val = val;
    else
        printf("LinkedList.setValFront: Empty List.\n");
}
// * PROCEDURE setValFront(LinkedList *list, int val, int index) - Changing the value of a Node at the rear of list.
void setValRear(LinkedList *list, int val) {
    if (list->rear != NULL)
        list->rear->val = val;
    else
        printf("LinkedList.setValRear: Empty List.\n");
}
// * PROCEDURE setValAt(LinkedList *list, int val, int index) - Changing the value of a Node at a certain index
void setValAt(LinkedList *list, int val, int index) {
    int curIndex = 0;
    Node *cur = list->ListNode;

    while (curIndex < index && cur != NULL) {
        cur = cur->next;
        curIndex++;
    }
    if (cur != NULL)
        cur->val = val;
    else
        printf("LinkedList.setValAt: Out of Bound.\n");
}
// * PROCEDURE pushNode (LinkedList *list, int val) - Adding new Node into the top of the list
void pushNode(LinkedList *list, int val) {
    Node *new_node;
    newNode(&new_node, val, list->ListNode);

    list->front = new_node;
    list->ListNode = new_node;
}
// * PROCEDURE appendNode (LinkedList *list, int val, int index) - Insert new Node into the end of the list
void appendNode(LinkedList *list, int val) {
    // Allocating & Assigning new_node
    Node *new_node;
    newNode(&new_node, val);

    // Connecting node
    if (new_node != NULL) {
        list->rear->next = new_node;
        list->rear = new_node;
    }
}
// * PROCEDURE insertAt (LinkedList *list, int val, int index) - Insert new Node at given index
void insertAt(LinkedList *list, int val, int index) {
    // Declaring new_node
    Node *new_node;

    // Traversing until given index
    int curIndex = 0;
    Node *cur = list->ListNode;
    while (curIndex < index-1 && cur != NULL)
    {
        cur = cur->next;
        curIndex++;
    }
    if (cur == NULL) {
        printf("LinkedList.insertAt: Out of Bound.\n");
    }
    else {
        newNode(&new_node, val, cur->next);
        free(cur->next);
        cur->next = new_node;
    }
}

// ! METHOD I/O OPERATIONS
// ? INPUT OPERATION
// inputNewNode(LinkedList *list) - Menginput node baru pada list
void inputNewNode(LinkedList *list) {
    int val;
    printf("Insert Node Value: ");
    scanf("%d", &val);

    appendNode(list, val);
}
// ? OUTPUT OPERATION
// * PROCEDURE showList(LinkedList list) - Printing the list
void showList(LinkedList list) {
    Node *cur = list.front;

    if (cur == NULL) {
        printf("LinkedList.showList: Empty List.\n");
    }
    else {
        printf("[");
        while (cur != NULL)
        {
            if (cur->next == NULL) 
                printf("%d", cur->val);
            else
                printf("%d, ", cur->val);
            cur = cur->next;
        }
        printf("]\n");
    }
}
// FUNCTION searchVal(Linkedlist) - Mencari nilai pada suatu LinkedList
int searchVal(LinkedList list, int key) {
    Node *cur = list.front;

    while (cur != NULL) {
        if (cur->val == key)
            return 1;
        
        cur = cur->next;
    }
    return 0;
}
// FUNCTION dequeueList(LinkedList *list) - return the value at the front of the list and dequeue
int dequequeList(LinkedList *list) {
    if (list->ListNode == NULL) {
        printf("LinkedList.dequequelist: Empty List.\n");
        return -999;
    }

    int returnVal = list->front->val;
    list->ListNode = list->ListNode->next;
    free(list->front);
    list->front = list->ListNode;

    return returnVal;
}
// * FUNCTION popList(LinkedList *list) - return the value at the end of the list and pop
int popList(LinkedList *list) {
    if (list->ListNode == NULL) {
        printf("LinkedList.popList: Empty List.\n");
        return -999;
    }

    int returnVal = list->rear->val;
    Node *cur = list->front;
    while (cur->next != list->rear)
        cur = cur->next;
    free(cur->next);
    cur->next = NULL;
    list->rear = cur;
    
    return returnVal; 
}

// ! DESTRUCTOR METHOD
// * PROCEDURE destructList(LinkedList *list) - Deallocating the entire list.
void destructList(LinkedList *list) {
    Node *temp;
    while (list->front != NULL) {
        temp = list->front;
        list->front = list->front->next;
        temp->next = NULL;
        free(temp);
    }
}