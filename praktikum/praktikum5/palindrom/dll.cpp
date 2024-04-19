#include "dll.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Insert node di akhir linked list (DLL)
void Insert_Node_DLL(struct Node_DLL** head, char data) {
    struct Node_DLL* newNode = (struct Node_DLL*)malloc(sizeof(struct Node_DLL));
    newNode->info = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        (*head)->prev = NULL;
    } else {
        struct Node_DLL* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// cek linked list adalah palindrom atau bukan (DLL)
int Cek_Palindrom_DLL(struct Node_DLL* head) {
    struct Node_DLL* first = head;
    struct Node_DLL* last = head;

    while (last->next != NULL) {
        last = last->next;
    }

    while (first != last && first->prev != last) {
        if (first->info != last->info) {
            return 0;
        }
        first = first->next;
        last = last->prev;
    }
    return 1;
}

// print linked list (DLL)
void Print_List_DLL(struct Node_DLL* head) {
    printf("Doubly Linked List: ");
    struct Node_DLL* temp = head;
    while (temp != NULL) {
        printf("%c ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

// Menghapus semua node pada linked list (DLL)
void Delete_All_Nodes_DLL(struct Node_DLL** head) {
    struct Node_DLL* current = *head;
    struct Node_DLL* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    *head = NULL;
}