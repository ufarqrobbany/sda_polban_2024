/* ------------------------------------------------------------------------------
------------------------------------ */
/* File : PTR13.cpp */
/* Deskripsi : Pointer ke function (Procedure dengan parameter input/output
sebagai parameter) */
/* Melakukan offset terhadap tabel tergantung fungsi f */
/* ------------------------------------------------------------------------------
------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
/* Kamus Global */
int N; /* ukuran efektif */
enum MyType {
    bulat,
    karakter
};
/* Prototype, fungsi yang diberikan sebagai parameter aktual */
void succI(int *i);  /* suksessor, berupa procedure by ref */
void predI(int *i);  /* predesessor */
void succC(char *c); /* suksessor, berupa procedure by ref */
void predC(char *c); /* predesessor */
/* print tabel yang belum ketahuan typenya */
void printtab(void *T, enum MyType Ty);
/* Prosedur dengan parameter sebuah fungsi */
void geser(int *TT, void (*f)(int *));
void geser(char *TT, void (*f)(char *));
/* Program Utama */
int main() {
    /* kamus lokal */
    /*Pointer ke tipe data void
    pointer fleksibel dan tidak terikat dengan tipe data apapun
    hanya berfungsi sebagai penunjuk ke alamat memori
    */
    void *MyTabInt;  // menginisialisasi pointer ke tipe data void
    void *MyTabC;    // menginisialisasi pointer ke tipe data void
    int i;
    /* program */

    N = 10;
    MyTabInt = (int *)malloc(N * sizeof(int));
    // mengalokasikan memori untuk MyTabInt sebesar N elemen bertipe int
    MyTabC = (char *)malloc(N * sizeof(char));
    // mengalokasikan memori untuk MyTabC sebesar N elemen bertipe char
    // mengisi nilai arrat MyTabInt dan MyTabC
    *(int *)MyTabInt = 1;
    for (i = 0; i < N; i++) {
        *((int *)MyTabInt + i) = i;
        *((char *)MyTabC + i) = 'A' + i;
    }
    /*Mencetak isi kedua array sebelum pergeseran*/
    printf("Isi tabel dalam main sebelum pemanggilan : \n");
    printf(" Tabel integer \n");
    printtab(MyTabInt, bulat);
    printf("\n");
    printf(" Tabel charakter \n");
    printtab(MyTabC, karakter);
    printf("\n");
    /* Pakai geser dengan parameter succ */
    printf("\n");
    printf("Geser dengan succ \n");
    geser((int *)MyTabInt, succI);  // menggeser nilai dalam array
    geser((char *)MyTabC, succC);   // menggeser nilai dalam array
    /*Mencetak isi kedua array setelah pergeseran*/
    printf(" dalam main \n");
    printf(" Tabel integer \n");
    printtab(MyTabInt, bulat);
    printf("\n");
    printf(" Tabel charakter \n");
    printtab(MyTabC, karakter);
    printf("\n");
    /* Pakai geser dengan parameter pred */
    printf("\n");
    printf("Geser dengan pred \n");
    geser((int *)MyTabInt, predI);  // menggeser nilai dalam array
    geser((char *)MyTabC, predC);   // menggeser nilai dalam array
    /*Mencetak isi kedua array setelah pergeseran*/
    printf(" dalam main \n");

    printf(" Tabel integer \n");
    printtab(MyTabInt, bulat);
    printf("\n");
    printf(" Tabel charakter \n");
    printtab(MyTabC, karakter);
    printf("\n");
    return 0;
}
/* Body Function */
void succI(int *i) {
    /* Parameter:
    i: parameter input output bertipe int
    Program:
    nilai i sbg parameter input akan diterima kemudian ditambah 1
    dan dikembalikan sbg parameter output
    */
    *i = *i + 1;
}
void predI(int *i) {
    /* Parameter:
    i: parameter input output bertipe int
    Program:
    nilai i sbg parameter input akan diterima kemudian dikurangi 1
    dan dikembalikan sbg parameter output
    */
    *i = *i - 1;
}
void succC(char *c) {
    /* Parameter:
    c: parameter input output bertipe char
    Program:
    nilai c sbg parameter input akan diterima kemudian ditambah 1
    dan dikembalikan sbg parameter output
    */
    *c = *c + 1;
}
void predC(char *c) {
    /* Parameter:
    c: parameter input output bertipe char
    Program:

    19

    nilai c sbg parameter input akan diterima kemudian dikurangi 1
    dan dikembalikan sbg parameter output
    */
    *c = *c - 1;
}
/*Berfungsi untuk menggeser ke angka selanjutnya atau sebelumnya*/
void geser(int *TT, void (*f)(int *)) {
    /* Parameter:
    *TT: Parameter input output bertipe integer
    (*f) (int *): parameter input output betipe void yang memiliki parameter
    (int *)
    */
    int i;
    printf(" dalam geser \n");
    for (i = 0; i < N; i++) {
        f(&TT[i]);
        printf(" %d ", TT[i]);
    }
    printf("\n");
}
/*Befungsi untuk menggeser ke karakter selanjutnya/sebelumnya dalam ASCII)*/
void geser(char *TT, void (*f)(char *)) {
    /* Parameter:
    *TT: Parameter input output bertipe integer
    (*f) (char *): parameter input output betipe void yang memiliki parameter
    (char *)
    */
    int i;
    printf(" dalam geser \n");
    for (i = 0; i < N; i++) {
        f(&TT[i]);
        printf(" %c ", TT[i]);
    }
    printf("\n");
}
/*Mencetak isi dari tabel dengan mengakses setiap elemennya
menggunakan tipe data yang sesuai*/
void printtab(void *T, enum MyType Ty) {
    /* Parameter:
    *T: Parameter input output bertipe void

    20
    enum: Parameter input bertipe enum(struct)
    */
    int i;
    for (i = 0; i < N; i++) {
        switch (Ty) {
            case bulat:
                printf(" %d ", *((int *)T + i));
                break;
            case karakter:
                printf(" %c ", *((char *)T + i));
                break;
        }
    }
}