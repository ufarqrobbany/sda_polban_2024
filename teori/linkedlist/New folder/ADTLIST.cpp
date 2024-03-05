/* 	File		:	ADTLIST.cpp
	Deskripsi	:	File ini berisi implementasi dari Abstract Data Type (ADT) Linked List dalam bahasa pemrograman C. 
					
					ADT Linked List memungkinkan operasi-operasi berikut:
					1. Konstruktor: Menciptakan linked list baru.
					2. Destruktor: Menghapus seluruh node dalam linked list.
					3. Mutator:
					   - Menambahkan node baru:
					     * Di awal linked list
					     * Di akhir linked list
					     * Di antara dua node tertentu
					     * Pada posisi tertentu
					   - Menghapus node:
					     * Dari awal linked list
					     * Dari akhir linked list
					     * Di antara dua node tertentu
					     * Pada posisi tertentu
					   - Memperbarui nilai dari node pada posisi tertentu
					4. Selector:
					   - Mengambil nilai dari node pada posisi tertentu
					   - Mengambil panjang (jumlah node) linked list
					   - Mencari posisi node dengan nilai tertentu
					5. I/O Operations:
					   - Menampilkan isi linked list ke layar


	Author		:	Reqi Jumantara Hapid (231524023)
	Date		:	05 - 03 - 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include "ADTLIST.h"


/*
	/***Informasi Struct yang digunakan
	typedef struct Node {
	    int data;
	    struct Node *next;
	} Node;
	
	typedef struct {
	    Node *head;
	} List;
*/



/*****Body Sub Program*****/
// Constructor: Inisialisasi Linked List
void initLinkedList(List *L) 
	/*	Digunakan untuk meenginisialisasi suatu List
		IS : L masih tak tentu
		FS : L bagian head sudah memiliki nilai berupa NULL
	*/
{
    L->head = NULL;
}

// Constructor: Membuat Node Baru
Node* createNode (int value)
	/*  IS : Node belum terdefinisi
		FS : Node terbentuk dan 'data' sudah terisi oleh 'value'
			 Alokasi memori berhasil jika newNode tidak NULL
	*/
{
	Node *newNode = (Node*) malloc (sizeof(Node));
	if (newNode == NULL) {
        printf("Error! Memory tidak cukup.\n");
        exit(1);
    }
    
    newNode->data = value;
    newNode->next = NULL;
    
    return newNode;
}

// Destructor: Menghapus Seluruh Node
void deleteList(List *L) {
	/*	Digunakan untuk menghapus seluruh node dalam suatu list
		IS : Terdapat sekumpulan node membentuk suatu list
		FS : Seluruh node sudah terhapus dan memori bisa digunakan kembali
	*/
    Node *current = L->head;
    Node *next;
    while (current != NULL) { //traversal, berhenti saat current = NULL
        free(current);
        current = next;
    }
    L->head = NULL;
}


// Mutator: Menambahkan Node di Awal Linked List
void insertAtBeginning(List *L, int value) 
	/*	IS : List 'list' mungkin kosong atau memiliki elemen di dalamnya
		FS : Sebuah node baru telah ditambahkan di awal dari 'list'
			 Node baru memiliki nilai 'data' yang sama dengan nilai 'value'
			 'head' dari 'list' sudah menunjuk alamat yang baru
	*/
	{
    Node *newNode = createNode(value);
    	
    if (L->head == NULL){ //Jika list belum memiliki elemen
    	L->head = newNode;
    	newNode->next = NULL;
	} else {
   		newNode->next = L->head;
    	L->head = newNode;
	}
    
}


// Mutator: Menambahkan Node di Akhir Linked List
void insertAtEnd(List *L, int value) 
	/*	IS : List 'list' mungkin kosong atau memiliki elemen di dalamnya
		FS : Sebuah node baru telah ditambahkan di akhir dari 'list'
			 Node baru memiliki nilai 'data' yang sama dengan nilai 'value'
			 'head' dari 'list' berisi NULL
	*/
	{
    Node *newNode = createNode(value);
    
    if (L->head == NULL) {
        L->head = newNode;
        return;
    }

    Node *current = L->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Mutator : Fungsi untuk Menambahkan Node di Antara Dua Node yang Ada
void insertBetween(List *list, int value, int key) 
	/*  IS : Linked list list mungkin kosong atau memiliki node-node di dalamnya.
		FS : Sebuah node baru dengan nilai value telah disisipkan di antara dua node yang sudah ada dalam linked list.
		   	 Node baru ini memiliki posisi setelah node dengan nilai key.	
	*/
{
    Node *newNode = createNode(value);

    if (list->head == NULL) {
        printf("Linked List kosong, tidak ada node untuk disisipkan.\n");
        return;
    }
	
	Node *position = searchPos(list, value);
	if (position = NULL){
		printf("Key tidak ditemukan dalam linked list\n");
		return;
	}
	
	newNode->next = position->next;
	position->next = newNode;
}

// Mutator: Menambahkan Node pada Indeks (index khayalan) Tertentu
void insertAtIndex(List *L, int index, int value) 
	/*  IS : Linked list L memiliki beberapa node atau mungkin kosong (L->head dapat berupa NULL).
			 Sebuah nilai index diberikan yang menunjukkan posisi (indeks khayalan) di mana kita ingin menyisipkan node baru.
			 Sebuah nilai value diberikan yang merupakan nilai dari node baru yang akan disisipkan.
		FS : Linked list L memiliki node baru yang telah disisipkan pada indeks yang ditentukan (index).
			 Node baru memiliki nilai value yang telah ditetapkan.
			 Node baru terletak di antara node pada posisi (index-1) dan (index) dari linked list.
	*/
{
    Node *newNode = createNode(value);

    if (index == 0) {
        insertAtBeginning(L, value);
        return;
    }

    Node *current = L->head;
    int i;
    for (i = 0; i < index - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Error! Indeks melebihi ukuran linked list.\n");
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Mutator: Menghapus Node dari Awal Linked List
void deleteFromBeginning(List *L) 
	/*  IS : Linked list L memiliki beberapa node atau mungkin kosong (L->head dapat berupa NULL)
		FS : Linked list L memiliki node pertama yang telah dihapus
			 Node yang semula menjadi node kedua dalam linked list, sekarang menjadi node pertama
	*/
{
    if (L->head == NULL) {
        printf("Linked List kosong, tidak ada yang dihapus.\n");
        return;
    }
    Node *temp = L->head;
    L->head = L->head->next;
    free(temp);
}

// Mutator: Menghapus Node dari Akhir Linked List
void deleteFromEnd(List *L) 
	/*  IS : Linked list L memilik beberapa node atau mungkin kosong (L->head dapat berupa NULL)
		FS : Linked list L memiliki node terakhir yang telah dihapus
			 Node yag semula menjadi node kedua terakhir dalam linked list, sekarang menjadi node terakhir
	*/
{
    if (L->head == NULL) {
        printf("Linked List kosong, tidak ada yang dihapus.\n");
        return;
    }

    if (L->head->next == NULL) { //Hanya ada satu node dalam linked list tersebut
        free(L->head);
        L->head = NULL;
        return;
    }

    Node *secondLast = L->head;
    while (secondLast->next->next != NULL) {
        secondLast = secondLast->next;
    }

    free(secondLast->next);
    secondLast->next = NULL;
}


// Mutator: Menghapus Node yang memiliki nilai 'data' tertentu
void deleteNodeWithValue(List *L, int value)
	/*	IS : Linked list L memilik beberapa node atau mungkin kosong (L->head dapat berupa NULL)
		FS : Linked list L memiliki salah satu node (di antara anggota node lainnya) yang telah dihapus
	*/
{
    Node *current = L->head;
    Node *prev = NULL;

    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    // Jika node dengan nilai yang sesuai ditemukan
    if (current != NULL) {
    	
        // Hubungkan node sebelum dan setelah node yang akan dihapus
        if (prev == NULL) {
            // Jika yang dihapus adalah node pertama
            L->head = current->next;
        } else {
            prev->next = current->next;
        }

        // Bebaskan memori untuk node yang dihapus
        free(current);
    } else {
    	printf("Node dengan nilai data tersebut tidak ditemukan.\n");
	}
}


// Mutator: Menghapus Node pada Indeks (indeks khayalan) Tertentu
void deleteAtIndex(List *L, int index) 
	/*  IS : Linked list L memilik beberapa node atau mungkin kosong (L->head dapat berupa NULL)
		FS : Linked list L memiliki salah satu node pada indeks (khayalan) tertentu yang telah dihapus
	*/
{
    if (L->head == NULL) {
        printf("Linked List kosong, tidak ada yang dihapus.\n");
        return;
    }

    if (index == 0) {
        deleteFromBeginning(L);
        return;
    }

    Node *current = L->head;
    Node *prev = NULL;
    int i;
    for (i = 0; current != NULL && i < index; i++) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Error! Indeks melebihi ukuran linked list.\n");
        return;
    }

    prev->next = current->next;
    free(current); //node yang ditunjuk 'current' dihapus
}

// Mutator: Memperbarui Nilai Node pada Indeks Tertentu
void updateAtPos(List *L, int valuePos, int updateValue) 
	/*  IS : Linked list L memilik beberapa node atau mungkin kosong (L->head dapat berupa NULL)
		FS : Nilai 'data' pada salah satu node di linked list tersebut sudah berubah seseuai dengan nilai update data yang diinginkan 
	*/
{
    Node *position = searchPos(L, valuePos);

    if (position == NULL) {
        printf("Error! Indeks melebihi ukuran linked list.\n");
        return;
    }

    position->data = updateValue;
}

// Selector: Mendapatkan Nilai dari Node Pertama
/*Mengembalikan nilai 'data' dari node pertama dalam linked list tersebut*/
int getFirst(List *L) {
    if (L->head == NULL) {
        printf("Linked List kosong.\n");
        exit(1);
    }
    return L->head->data;
}

// Selector: Mendapatkan Nilai dari Node Terakhir
/*Mengembalikan nilai 'data' dari node terakhir dalam linked list tersebut*/
int getLast(List *L) {
    if (L->head == NULL) {
        printf("Linked List kosong.\n");
        exit(1);
    }
    
    Node *current = L->head;
    while (current->next != NULL) {
        current = current->next;
    }
    return current->data;
}

// Selector: Mendapatkan Nilai dari Node pada Indeks Tertentu
/*Mengembalikan nilai 'data' dari node pada indeks tertentu dalam linked list tersebut*/
int getAtIndex(List *L, int index) {
    Node *current = L->head;
    int i;
    for (i = 0; current != NULL && i < index; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Error! Indeks melebihi ukuran linked list.\n");
        exit(1);
    }
    return current->data;
}

// Selector: Mencari posisi dari suatu nilai
/* Mengembalikan alamat 'list' yang memiliki nilai 'data' yang dicari*/
Node* searchPos(List *L, int value) {
	Node *current = L->head;
	bool temu = false;
	while ((!temu) && (current != NULL)){
		if(current->data == value){
			temu = true;
			return current; //key ditemukan
		} else {
			current = current->next;
		}
	}
	return NULL;  //key tidak ditemukan
}

// Selector: Mendapatkan Jumlah Node dalam Linked List
/*Mengembalikan jumlah node yang ada dalam sebuah linked list*/
int size(List *L) {
    int count = 0;
    Node *current = L->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// I/O Operation: Menampilkan Isi Linked List
void displayLinkedList(List *L) 
	/*	IS : Layar kosong
		FS : Layar menampilkan isi 'data' dari setiap node pada linked list tersebut
	*/
{
    Node *current = L->head;
    if (current == NULL) {
        printf("Linked List kosong.\n");
        return;
    }
    printf("Isi Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


