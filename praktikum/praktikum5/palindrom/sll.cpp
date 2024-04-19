#include "sll.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  Insert node di akhir linked list (SLL)
void Insert_Node_SLL(struct Node_SLL** head, char data) {
    struct Node_SLL* newNode = (struct Node_SLL*)malloc(sizeof(struct Node_SLL));
    newNode->info = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node_SLL* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// cek linked list adalah palindrom atau bukan (SLL) menggunakan metode stack
int Cek_Palindrom_SLL(struct Node_SLL* head) {
    char stack[100];
    int top = -1;
    struct Node_SLL* current = head;

    // Traverse list dari head sampai node akhir dan simpan setiap node yang ditemukan ke dalam stack
    while (current != NULL) {
        stack[++top] = current->info;
        current = current->next;
    }

    // Traverse kembali list untuk membandingkan data yang ada di stack dengan list
    current = head;
    while (current != NULL) {
        if (current->info != stack[top]) {
            return 0;
        }
        top--;
        current = current->next;
    }
    return 1;
}

// print linked list (SLL)
void Print_List_SLL(struct Node_SLL* head) {
    printf("Single Linked List: ");
    struct Node_SLL* temp = head;
    while (temp != NULL) {
        printf("%c ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

// Menghapus semua node pada linked list (SLL)
void Delete_All_Nodes_SLL(struct Node_SLL** head) {
    struct Node_SLL* current = *head;
    struct Node_SLL* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    *head = NULL;
}