#include <stdio.h>
#include <stdlib.h>

#include "nbtrees_h.h"

int main() {
    Isi_Tree myTree;
    int n;

    printf("Masukkan jumlah node dalam tree: ");
    scanf("%d", &n);

    Create_tree(myTree, n);
    return 0;
}