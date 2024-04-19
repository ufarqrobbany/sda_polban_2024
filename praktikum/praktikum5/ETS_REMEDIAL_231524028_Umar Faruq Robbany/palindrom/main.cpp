#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dll.h"
#include "sll.h"

int main() {
    struct Node_DLL* first_DLL = NULL;
    struct Node_SLL* first_SLL = NULL;
    char input[100];
    int menu, len;

    system("cls");

    while (true) {
        printf("\nCek Palindrom\n");
        printf("1. Non Restricted Single Linked List\n");
        printf("2. Doubly Linked List\n");
        printf("3. Keluar\n");
        printf("Pilih jenis linked list : ");
        scanf("%d", &menu);

        // pilih menu
        switch (menu) {
            case 1:
                // masukkan kata atau frasa
                printf("\nMasukkan kata atau frasa: ");
                scanf("%s", input);

                // insert setiap huruf menjadi node ke linked list (SLL)
                len = strlen(input);
                for (int i = 0; i < len; i++) {
                    Insert_Node_SLL(&first_SLL, input[i]);
                }

                // tampilkan linked list
                Print_List_SLL(first_SLL);

                // cek palindrom
                if (Cek_Palindrom_SLL(first_SLL)) {
                    printf("Palindrom\n");
                } else {
                    printf("Bukan Palindrom\n");
                }

                Delete_All_Nodes_SLL(&first_SLL);

                break;
            case 2:
                // masukkan kata atau frasa
                printf("\nMasukkan kata atau frasa: ");
                scanf("%s", input);

                // insert setiap huruf menjadi node ke linked list (DLL)
                len = strlen(input);
                for (int i = 0; i < len; i++) {
                    Insert_Node_DLL(&first_DLL, input[i]);
                }

                // tampilkan linked list
                Print_List_DLL(first_DLL);

                // cek palindrom
                if (Cek_Palindrom_DLL(first_DLL)) {
                    printf("Palindrom\n");
                } else {
                    printf("Bukan Palindrom\n");
                }

                Delete_All_Nodes_DLL(&first_DLL);

                break;
            case 3:
                exit(1);
                break;
            default:
                break;
        }
    }

    return 0;
}

// Perbedaan Single Linked List dan Doubly Linked List dalam pengecekan palindrom
// Single Linked List:
// Terdapat beberapa cara untuk mengecek suatu kata atau frasa adalah palindrom atau bukan jika menggunakan struktur data SLL
// dalam program ini, saya menggunakan cara stack
// yaitu terdapat 2 kali traversal, yang pertama untuk menyalin list ke dalam stack, dan yang kedua untuk membandingkan data pada list dan stack

// Doubly Linked List:
// Karena pada DLL bisa mengakses node sebelumnya, traversal bisa dilakukan hanya sekali