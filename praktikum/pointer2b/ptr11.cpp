/* ----------------------------------------------------------------------------- */
/* File : PTR11.cpp */
/* Deskripsi : Penggunaan pointer ke fungsi (Function sebagai parameter) */
/* Melakukan offset terhadap tabel tergantung fungsi f */
/* ----------------------------------------------------------------------------- */

#include <stdio.h>

/* Kamus Global */
int N; /* Ukuran efektif */

/* Prototype, fungsi yang diberikan sebagai parameter aktual */
int succ(int i); /* succ -> singkatan dari suksesor */
int pred(int i); /* pred -> singkatan dari predesesor */

/* Prosedur dengan parameter sebuah fungsi */
void geser(int *TT, int (*f)(int));

/* Program Utama */
int main() {
    /* Kamus lokal */
    int MyTab[10];
    int i;

    /* Program */
    N = 10;

    /* Inisialisasi tabel MyTab */
    for (i = 0; i < N; i++) {
        MyTab[i] = i;  // assign nilai array myTab indeks ke-i dengan nilai i.
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

/* Fungsi untuk mengembalikan suksesor dari suatu nilai */
int succ(int i) {
    return (i + 1);
}

/* Fungsi untuk mengembalikan predesesor dari suatu nilai */
int pred(int i) {
    return (i - 1);
}

/* Prosedur untuk menggeser elemen-elemen tabel menggunakan fungsi f */
void geser(int *TT, int (*f)(int)) {
    int i;
    printf(" dalam geser\n");
    for (i = 0; i < N; i++) {
        TT[i] = f(TT[i]);
        printf(" %d ", TT[i]);
    }
    printf("\n");
}
