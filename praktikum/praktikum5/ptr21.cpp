/*----------------------------------------------------------------------------*/
/* File : PTR21.cpp */
/* Deskripsi : contoh deklarasi list dan pemakaian makro */
/* Dibuat oleh : Tim Dosen SDP */
/* Tanggal : 13-09-2001 */
/*----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

/*Definisi akses komponen type, standard kuliah Algoritma dan pemrograman*/
#define info(P) (P)->info
#define next(P) (P)->next
#define Nil NULL

/* Definisi TYPE global (sebenarnya untuk soal ini tidak perlu global) */
/* Element list linier */
typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist {
    infotype info;
    address next;
} ElmtList;

/* Program Utama */
int main() {
    /* kamus */
    address First;
    address P, Q;
    /* program */
    /* Create list kosong */
    First = Nil;
    /* Alokasi, insert as first elemen */
    P = (address)malloc(sizeof(ElmtList));
    info(P) = 10;
    next(P) = Nil;
    First = P;
    /* Alokasi, insert as first elemen */
    Q = (address)malloc(sizeof(ElmtList));
    info(Q) = 20;
    next(Q) = Nil;
    next(Q) = First;
    First = Q;
    /* Alokasi, insert as first elemen */
    P = (address)malloc(sizeof(ElmtList));
    info(P) = 30;
    next(P) = Nil;
    next(P) = First;
    First = P;

    // printf("%d \n", info(next(next(First))));

    address O = (address)malloc(sizeof(ElmtList));

    // tampilkan subvar info semua node
    address current = First;
    printf("\nFirst: %d\n", info(current));
    while (current != Nil) {
        printf("%d -> ", info(current));
        current = next(current);
    }
    printf("Nil");
    return 0;
}