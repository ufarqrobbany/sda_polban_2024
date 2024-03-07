/* ------------------------------------------------------------------------------------------------------------------ */
/* File : PTR12.cpp */
/* Deskripsi : Penggunaan pointer ke fungsi (Procedure dengan parameter input/output sebagai parameter) */
/* Melakukan offset terhadap tabel tergantung fungsi f */
/* ------------------------------------------------------------------------------------------------------------------ */

#include <stdio.h>

/* Kamus Global */
int N; /* Ukuran efektif */

/* Prototype, fungsi yang diberikan sebagai parameter aktual */
void succ(int *i); /* Suksesor, berupa procedure by reference */
void pred(int *i); /* Predesesor */

/* Prosedur dengan parameter sebuah fungsi */
void geser(int *TT, void (*f)(int *));

/* Program Utama */
int main() {
    /* Kamus lokal */
    int MyTab[10];
    int i;

    /* Program */
    N = 10;

    /* Inisialisasi tabel MyTab */
    for (i = 0; i < N; i++) {
        MyTab[i] = i;
    }

    printf("Isi tabel dalam main sebelum pemanggilan:\n");
    for (i = 0; i < N; i++) {
        printf(" %d ", MyTab[i]);
    }
    printf("\n");

    /* Pakai geser dengan parameter succ */
    printf("Geser dengan succ\n");
    geser(MyTab, succ);
    printf(" dalam main\n");
    for (i = 0; i < N; i++) {
        printf(" %d ", MyTab[i]);
    }
    printf("\n");

    /* Pakai geser dengan parameter pred */
    printf("Geser dengan pred\n");
    geser(MyTab, pred);
    printf(" dalam main setelah aplikasi pred\n");
    for (i = 0; i < N; i++) {
        printf(" %d ", MyTab[i]);
    }
    printf("\n");

    return 0;
}

/* Body Function */

/* Prosedur untuk menginkrement nilai referensi */
void succ(int *i) {
    *i = *i + 1;
}

/* Prosedur untuk mendekrement nilai referensi */
void pred(int *i) {
    *i = *i - 1;
}

/* Prosedur untuk menggeser elemen-elemen tabel menggunakan fungsi f */
void geser(int *TT, void (*f)(int *)) {
    int i;
    printf(" dalam geser\n");
    for (i = 0; i < N; i++) {
        f(&TT[i]);
        printf(" %d ", TT[i]);
    }
    printf("\n");
}
