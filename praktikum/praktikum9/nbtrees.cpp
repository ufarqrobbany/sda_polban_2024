#include "nbtrees.h"

#include <stdio.h>

void Init_tree(Isi_Tree X) {
    for (int i = 1; i <= jml_maks; i++) {
        X[i].info = ' ';
        X[i].ps_fs = nil;
        X[i].ps_nb = nil;
        X[i].ps_pr = nil;
    }
}

void Create_tree(Isi_Tree X, int Jml_Node) {
    char rootInfo, parentInfo, sonInfo;
    int totalNodes, currentNodeIndex, totalSon, fsIndex, sonIndex;

    Init_tree(X);

    printf("\nRoot : ");
    scanf(" %c", &rootInfo);
    X[1].info = rootInfo;

    totalNodes = 1;
    currentNodeIndex = 1;

    while (currentNodeIndex <= totalNodes) {
        parentInfo = X[currentNodeIndex].info;

        printf("\nParent : %c\n", parentInfo);
        printf("Jumlah Anak : ");
        scanf("%d", &totalSon);

        if (totalSon > 0) {
            int fsIndex = totalNodes + 1;
            int lastChildIndex = fsIndex + totalSon - 1;

            if (lastChildIndex > Jml_Node) {
                printf("\nJumlah anak sudah melebihi jumlah maksimum node\n");
                return;
            }

            for (int j = 0; j < totalSon; j++) {
                sonIndex = fsIndex + j;

                printf("Anak ke-%d : ", j + 1);
                scanf(" %c", &sonInfo);

                X[sonIndex].info = sonInfo;
                X[sonIndex].ps_pr = currentNodeIndex;

                if (j == 0) {
                    X[currentNodeIndex].ps_fs = sonIndex;
                } else {
                    X[fsIndex + j - 1].ps_nb = sonIndex;
                }

                totalNodes++;
            }
        }
        currentNodeIndex++;
    }
}

void PrintTree(Isi_Tree P) {
    printf("\n");
    int i = 1;
    while (P[i].info != ' ' && i < jml_maks) {
        printf("--> Indeks ke-%d\n", i);
        printf("------------------------------------\n");
        printf("Info array ke-%d \t: %c\n", i, P[i].info);
        printf("First Son array ke-%d \t: %d\n", i, P[i].ps_fs);
        printf("Next Brother array ke-%d : %d\n", i, P[i].ps_nb);
        printf("Parent array ke-%d \t: %d\n", i, P[i].ps_pr);
        printf("------------------------------------\n\n");
        i++;
    }
}