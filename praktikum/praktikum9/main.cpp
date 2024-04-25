#include <stdio.h>
#include <stdlib.h>

#include "nbtrees.h"

int main() {
    Isi_Tree tree;
    int totalNode, option;

    system("cls");

    printf("Masukkan Jumlah Node (maksimal 20) : ");
    scanf("%d", &totalNode);
    Create_tree(tree, totalNode);

    do {
        printf("\n1. Print Tree\n");
        printf("2. Exit\n");
        printf("Pilih Menu : ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                PrintTree(tree);
                break;
            case 2:
                printf("Keluar...\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while (option != 2);

    return 0;
}
