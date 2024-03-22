#include <stdio.h>
#include <stdlib.h>

#define first(L) (L)->First
#define last(L) (L)->Last
#define info(P) (P)->info
#define next(P) (P)->next
#define Nil NULL

typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist {
    infotype info;
    address next;
} ElmtList;

typedef struct linkedList {
    address First;
    address Last;
} linkedList;

// ========== CONSTRUCTOR
// function untuk inisialisasi linked list
void initList(linkedList **list);
// function untuk mengalokasi memori dan inisialisasi node baru
address createNode(infotype info);

// ========== INSERT
// procedure untuk menambah node baru di awal linked list
void insertFirst(linkedList **list, infotype info);
// procedure untuk menambah node baru setelah node dengan nilai info tertentu
void insertAfterInfo(linkedList **list, infotype prev_info, infotype new_info);
// procedure untuk menambah node baru sebelum node dengan nilai info tertentu
void insertBeforeInfo(linkedList **list, infotype next_info, infotype new_info);
// procedure untuk menambah node baru di posisi tertentu
void insertAtPosition(linkedList **list, infotype info, int pos);
// procedure untuk menambah node baru di akhir linked list
void insertLast(linkedList **list, infotype info);

// ========== DELETE
// procedure untuk menghapus node di awal linked list
void deleteFirst(linkedList **list);
// procedure untuk menghapus node pertama yang memiliki nilai info tertentu
void deleteByInfo(linkedList **list, infotype info);
// procedure untuk menghapus semua node yang memiliki nilai info tertentu
void deleteAllByInfo(linkedList **list, infotype info);
// procedure untuk menghapus node pada posisi tertentu
void deleteAtPosition(linkedList **list, int pos);
// procedure untuk menghapus node di akhir linked list
void deleteLast(linkedList **list);
// procedure untuk menghapus semua node dalam linked list
void deleteAll(linkedList **list);

// ========== UPDATE
// procedure untuk mengubah nilai info pada node di awal linked list
void updateFirst(linkedList *list, infotype new_info);
// procedure untuk mengubah nilai info pada node di posisi tertentu
void updateAtPosition(linkedList *list, infotype new_info, int pos);
// procedure untuk mengubah nilai info pada node pertama yang memiliki nilai info tertentu
void updateByInfo(linkedList *list, infotype target_info, infotype new_info);
// procedure untuk mengubah nilai info pada semua node yang memiliki nilai info tertentu
void updateAllByInfo(linkedList *list, infotype target_info, infotype new_info);
// procedure untuk mengubah nilai info pada node di akhir linked list
void updateLast(linkedList *list, infotype new_info);

// ========== SEARCH
// function untuk mencari node berdasarkan nilai info
address searchByInfo(linkedList *list, infotype info);
// function untuk mencari node pada posisi tertentu
address searchAtPosition(linkedList *list, int pos);

// ========== INPUT/OUTPUT
// procedure untuk menampilkan isi info semua node pada linked list
void displayList(linkedList *list);