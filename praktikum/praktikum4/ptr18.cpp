/* ------------------------------------------------------------------------------------------------------------- */
/* File Program : PTR18.CPP */
/* Deskripsi : program array dinamis dan statis : mengisi dgn baca, menulis (Modular, program */
/* passing parameter tabel/array */
/* ------------------------------------------------------------------------------------------------------------- */
#include <stdio.h>

/* Definisi tabel integer */
typedef struct {
    int tab[10]; /* array integernya */
    int N;       /* Ukuran efektif */
} tabint;
/* Prototype */
void incTab(tabint *T);  /* Increment setiap elemen tabel */
void printTab(tabint T); /* Print tabel */
int main() {
    /* kamus */
    tabint T;
    int i;
    /* program */
    T.N = 3;
    printf("Isi dan print tabel untuk indeks 1..5 \n");
    /* isi dari pembacaan */
    for (i = 0; i < T.N; i++) {
        printf("Input tabel ke -[%d] = ", i);
        scanf("%d", &(T.tab[i]));
    };
    /* Print : perhatikan passing parameter by value */
    printTab(T);
    /* Increment : perhatikan passing parameter by reference */
    incTab(&T);
    printTab(T);
    return 0;
}
/* Body prototype */
void incTab(tabint *T)
/* Increment setiap elemen tabel */
{
    /* Kamus lokal */
    int i;
    /* Program */
    for (i = 0; i < (*T).N; i++) {
        (*T).tab[i] = (*T).tab[i] + 1;
    }
}
void printTab(tabint T)
/* Print setiap elemen tabel */
{ /* Kamus lokal */
    int i;
    /* Program untuk traversal print */
    for (i = 0; i < T.N; i++) {
        printf("T[%d] = %d \n", i, T.tab[i]);
    }
}
