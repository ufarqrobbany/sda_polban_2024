/* -------------------------------------------------------------- */
/* File : PTR10.cpp */
/* Deskripsi : Contoh penggunaan pointer dan fungsi/prosedur */
/* -------------------------------------------------------------- */

#include <stdio.h>

/* Prototype fungsi */
void f1(void);
void f2(void);
void f3(void);
void f4(void);

/* Kamus Global */
#define true 1
#define false 0
int quit = false;

int main() {
    /* Kamus lokal */
    /* Definisi tabel yang elemennya adalah pointer ke fungsi */
    /* Elemen tabel ke-i mengakses fungsi ke-i */
    /* Pilihan menjadi indeks tabel, digunakan untuk mengaktifkan fungsi yang sesuai */
    void (*tab[4])() = {f1, f2, f3, f4}; /* Pointer ke prosedur */

    /* Program */
    printf("Pointer to function:\n");

    /* Menu */
    do {
        printf("Pilih salah satu:\n");
        printf("1. Buka file hanya untuk baca\n");
        printf("2. Tutup file\n");
        printf("3. Edit file\n");
        printf("4. Quit\n");
        tab[getchar() - '1'](); /* Memanggil fungsi berdasarkan pilihan */
        getchar();              /* Untuk membuang karakter newline */
    } while (!quit);            // lakukan looping selama quit = false

    return 0;
}

/* Implementasi Fungsi */
void f1() {
    printf("Ini fungsi f1\n");
}

void f2() {
    printf("Ini fungsi f2\n");
}

void f3() {
    printf("Ini fungsi f3\n");
}

void f4() {
    quit = true;  // untuk menghentikan looping
    printf("Keluar...\n");
}
