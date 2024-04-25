#ifndef nbtrees_h
#define nbtrees_h

#include <stdio.h>
#include "boolean.h"

//Maksimal node yang dapat ditampung dalam array
#define jml_maks 20

//Arah traversal

#define kebawah  1
#define keatas   2
#define kekanan  3
#define nil	  0


/***************************/
/*  Type data */
/***************************/

/* Indeks dalam bahasa C dimulai dengan 0; tetapi indeks 0 tidak dipakai */

/* Kamus */

typedef char infotype;
typedef int address;
typedef struct { infotype  info;
   		  address ps_fs, ps_nb, ps_pr;}nbtree;


typedef nbtree Isi_Tree[jml_maks+1];



/***************************/
/*  S P E S I F I K A S I  */
/***************************/

void init_tree(Isi_Tree *X);
/* I.S: Pohon dalam keadaan kosong, semua elemen pada array Isi_Tree memiliki nilai default.
   F.S: Setelah fungsi init_tree dijalankan, semua elemen pada array Isi_Tree telah diinisialisasi dengan nilai default yang ditentukan, sehingga pohon dalam keadaan siap digunakan dan diisi dengan data. 
*/

void Create_tree(Isi_Tree X, int Jml_Node);
// Create Non Binary Tree sebanyak Jml_Node
// Tujuan mengentrykan Non Binary Tree ke array Isi_Tree dengan pola Level Order 
// Jml Node adalah banyaknya elemen dalam Tree yang menjadi parameter input


boolean IsEmpty (Isi_Tree P);
/* Mengirimkan true jika Isi_Tree KOSONG */



/***** Traversal *****/

void PreOrder (Isi_Tree P, int idx);
/* Traversal PreOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara PreOrder : Parent, fs, nb */

void InOrder (Isi_Tree P);
/* Traversal InOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara InOrder : fs, Parent, Sisa anak lain */

void PostOrder (Isi_Tree P);
/* Traversal PostOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara PostOrder :  fs, nb, Parent */

void Level_order(Isi_Tree X, int Maks_node);
/* Traversal LevelOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara Level Order */

void PrintTree(Isi_Tree p, address P, int level);
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditulis ke layar */
// Penggunaan pertama pada modul utama adalah
// PrintTree(X, 1, 0);
// Dimana X adalah variabel bertipe Isi_Tree yang menujuk pada Tree yang dimaksud
// 1 adalah index awal yang digunakan, jangan menggunakan 0 karena akan membuat sistem kebingungan antara null dan index ke 0
// 0 adalah initialisasi awal dari level, karena perlu mengunjungi root terlebih dahulu, maka diisi 0


/***** Search *****/

boolean Search (Isi_Tree P, infotype X);
/* Mengirimkan true jika ada node dari P yang bernilai X */

int NSearch (Isi_Tree P, infotype X);
/* Mengirimkan posisi/indeks node jika ada node dari P yang bernilai X */

/***** Fungsi Lain *****/

int nbElmt (Isi_Tree P);
/* Mengirimkan banyak elemen (node) di pohon non biner P */

int nbDaun (Isi_Tree P);
/* Mengirimkan banyak daun (node) pohon non biner P */

int Level (Isi_Tree P, infotype X);
/* Mengirimkan level dari node X yang merupakan salah satu simpul */ 
/* dr pohon P. Akar (P) levelnya adalah 0. Pohon tidak kosong */

int Depth (Isi_Tree T, address root);
/* Pohon Biner mungkin Kosong, mengirimkan 'depth' yaitu tinggi dari Pohon */
/* Basis : Pohon Kosong, tingginya Nol */

int Max (infotype Data1, infotype Data2);
/* Mengirimkan Nilai terbesar dari dua data */

int Derajat(Isi_Tree P,infotype X);
/* Pohon Non Biner mungkin Kosong, mengirimkan 'derajat' yaitu jml path satu node menuju terminal node */
/* Basis : Pohon Kosong, derajatnya Nol */
/* jml path menuju terminal node ujung paling jauh */

int Degree (Isi_Tree P, infotype X);
/* Pohon Non Biner mungkin Kosong, mengirimkan 'degree' yaitu jumlah anak dari satu node */
/* Basis : Pohon Kosong, degreenya Nol */

#endif

