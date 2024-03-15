/*
----------------------------------------------------------------------------
File                : PTR21.cpp
Deskripsi           : contoh deklarasi list dan pemakaian makro
Dibuat oleh         : Tim Dosen SDP
Tanggal             : 13-09-2001
Dimodifikasi oleh   : Umar Faruq Robbany
Tanggal Modifikasi  : 14-03-2024
----------------------------------------------------------------------------
*/

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

/* Deklarasi modul */
void insertAwal(address *firstNode, infotype info);
void insertDiAntara(address *firstNode, infotype previnfo, infotype info);
void insertAkhir(address *firstNode, infotype info);
void tampilInfoNode(address node);

void deleteAwal(address *firstNode);
void deleteAkhir(address firstNode);
void deleteDiAntara(address firstNode, infotype previnfo);

/* Program Utama */
int main() {
    /* KAMUS */
    address First;
    address P, Q;

    /* PROGRAM */
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
    printf("\n\nInitial State");
    tampilInfoNode(First);

    /* Menambahkan node baru di awal linked list */
    printf("\n\nInsert node di awal");
    insertAwal(&First, 110);
    tampilInfoNode(First);

    /* Menambahkan node baru di antara 2 node (berdasarkan nilai info) */
    /* Setelah node dengan nilai info = 20 */
    printf("\n\nInsert node di antara");
    insertDiAntara(&First, 20, 220);
    tampilInfoNode(First);

    /* Menambahkan node baru di akhir linked list */
    printf("\n\nInsert node di akhir");
    insertAkhir(&First, 330);
    tampilInfoNode(First);

    /* Menghapus node awal di linked list */
    printf("\n\nHapus node di awal");
    deleteAwal(&First);
    tampilInfoNode(First);

    /* Menghapus node di antara 2 node (berdasarkan nilai info) */
    /* Hapus node dengan nilai info == 20 */
    printf("\n\nHapus node di tengah");
    deleteDiAntara(First, 20);
    tampilInfoNode(First);

    /* Menghapus node terakhir di linked list */
    printf("\n\nHapus node di akhir");
    deleteAkhir(First);
    tampilInfoNode(First);

    /* Tampilkan subvar info semua node */
    // tampilInfoNode(First);

    return 0;
}

/* Display */
void tampilInfoNode(address node) {
    address current = node;

    if (current == NULL) {
        // jika linked list kosong
        printf("Linked list kosong\n");
    } else {
        printf("\nIsi linked list : \n");
        printf("First = %d\n", info(current));
        while (current != Nil) {
            printf("%d -> ", info(current));
            current = next(current);
        }
        printf("Nil");
    }
}

/* Insertion */
void insertAwal(address *firstNode, infotype info) {
    // alokasi dan assign nilai node baru
    address nodeBaru = (address)malloc(sizeof(ElmtList));
    info(nodeBaru) = info;
    next(nodeBaru) = Nil;

    if (nodeBaru == Nil) {
        // jika alokasi gagal
        printf("Alokasi memori gagal\n");
    } else if ((*firstNode) == Nil) {
        // jika linked list kosong, tetapkan sbg node awal
        *firstNode = nodeBaru;
    } else {
        // masukkan node di awal linked list
        next(nodeBaru) = *firstNode;
        *firstNode = nodeBaru;
    }
}

void insertAkhir(address *firstNode, infotype info) {
    address current = *firstNode;

    // alokasi dan assign nilai node baru
    address nodeBaru = (address)malloc(sizeof(ElmtList));
    info(nodeBaru) = info;
    next(nodeBaru) = Nil;

    if (nodeBaru == Nil) {
        // jika alokasi gagal
        printf("Alokasi memori gagal\n");
    } else if ((*firstNode) == Nil) {
        // jika linked list kosong, tetapkan sbg node awal
        *firstNode = nodeBaru;
    } else {
        // masukkan node di akhir linked list
        while (next(current) != Nil) {
            current = next(current);
        }
        next(current) = nodeBaru;
    }
}

void insertDiAntara(address *firstNode, infotype previnfo, infotype info) {
    address current = *firstNode;

    // alokasi dan assign nilai node baru
    address nodeBaru = (address)malloc(sizeof(ElmtList));
    info(nodeBaru) = info;
    next(nodeBaru) = Nil;

    if (nodeBaru == Nil) {
        // jika alokasi gagal
        printf("Alokasi memori gagal\n");
    } else if ((*firstNode) == Nil) {
        // jika linked list kosong
        printf("Gagal menyisipkan node baru! linked list masih kosong");
    } else {
        // masukkan di setelah node dengan nilai info == previnfo

        // cari posisi node dengan nilai info == previnfo
        while ((current != Nil) && (info(current) != previnfo)) {
            current = next(current);
        }

        if (current != Nil && info(current) == previnfo) {
            // jika node ditemukan
            next(nodeBaru) = next(current);
            next(current) = nodeBaru;
        } else {
            // jika node tidak ditemukan
            printf("Gagal menyisipkan node baru! Node dengan nilai info = %d, tidak ditemukan.", previnfo);
        }
    }
}

/* Deletion */
void deleteAwal(address *firstNode) {
    address deleteNode = *firstNode;

    if ((*firstNode) == Nil) {
        // jika linked list kosong
        printf("Gagal menghapus node! linked list kosong");
    } else {
        *firstNode = next(*firstNode);
        free(deleteNode);
    }
}

void deleteAkhir(address firstNode) {
    address current = firstNode;

    if (firstNode == Nil) {
        // jika linked list kosong
        printf("Gagal menghapus node! linked list kosong");
    } else {
        while (next(next(current)) != Nil) {
            current = next(current);
        }

        free(next(next(current)));
        next(current) = Nil;
    }
}

void deleteDiAntara(address firstNode, infotype previnfo) {
    address current = firstNode;

    if (firstNode == Nil) {
        // jika linked list kosong
        printf("Gagal menghapus node! linked list kosong");
    } else if (info(current) == previnfo) {
        // jika posisi node yang dicari ada di awal linked list
        next(current) = next(next(current));

        free(next(current));
    } else {
        // cari posisi node sebelum node dengan nilai info == previnfo
        while ((next(current) != Nil) && (info(next(current)) != previnfo)) {
            current = next(current);
        }

        if ((next(current) != Nil) && (info(next(current)) == previnfo)) {
            // jika node ditemukan
            next(current) = next(next(current));
            free(next(current));
        } else {
            // jika node tidak ditemukan
            printf("Gagal menghapus node! Node dengan nilai info = %d, tidak ditemukan.", previnfo);
        }
    }
}