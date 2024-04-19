#include "nbtrees_h.h"

#include <stdio.h>

void Create_tree(Isi_Tree X, int Jml_Node) {
    int i;
    infotype data;

    for (i = 1; i <= Jml_Node; i++) {
        if (i == 1) {
            printf("Root : ");
            scanf(" %c", &data);
        } else {
            printf("Masukkan data untuk node ke-%d : ", i);
            scanf(" %c", &data);
        }

        X[i].info = data;
        X[i].ps_fs = nil;
        X[i].ps_nb = nil;
        X[i].ps_pr = nil;
    }
}

boolean IsEmpty(Isi_Tree P) {
    // Implementasi fungsi IsEmpty
    return false;
}

void PreOrder(Isi_Tree P) {
    // Implementasi fungsi PreOrder
}

void InOrder(Isi_Tree P) {
    // Implementasi fungsi InOrder
}

void PostOrder(Isi_Tree P) {
    // Implementasi fungsi PostOrder
}

void Level_order(Isi_Tree X, int Maks_node) {
    // Implementasi fungsi Level_order
}

void PrintTree(Isi_Tree P) {
    // Implementasi fungsi PrintTree
}

boolean Search(Isi_Tree P, infotype X) {
    // Implementasi fungsi Search
    return false;
}

int nbElmt(Isi_Tree P) {
    // Implementasi fungsi nbElmt
    return 0;
}

int nbDaun(Isi_Tree P) {
    // Implementasi fungsi nbDaun
    return 0;
}

int Level(Isi_Tree P, infotype X) {
    // Implementasi fungsi Level
    return 0;
}

int Depth(Isi_Tree P) {
    // Implementasi fungsi Depth
    return 0;
}

int Max(infotype Data1, infotype Data2) {
    // Implementasi fungsi Max
    return 0;
}
