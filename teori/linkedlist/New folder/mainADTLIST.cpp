/* 	File		:	mainADTLIST.cpp
	Author		:	Reqi Jumantara Hapid (231524023)
	Date		:	05 - 03 - 2024
*/


#include <stdio.h>
#include <stdlib.h>
#include "ADTLIST.h"


int main() {
    List myList;
    initLinkedList(&myList);

    insertAtBeginning(&myList, 98);
    insertAtBeginning(&myList, 37);
    insertAtBeginning(&myList, 14);
    insertAtBeginning(&myList, 5);

    displayLinkedList(&myList);

    insertAtEnd(&myList, 99);
    insertAtEnd(&myList, 3);

    displayLinkedList(&myList);

    insertAtIndex(&myList, 3, 77);

    displayLinkedList(&myList);

    deleteFromBeginning(&myList);

    displayLinkedList(&myList);

    deleteFromEnd(&myList);

    displayLinkedList(&myList);

    deleteAtIndex(&myList, 1);

    displayLinkedList(&myList);

    updateAtPos(&myList, 77, 25);

    displayLinkedList(&myList);

    printf("Nilai Node Pertama: %d\n", getFirst(&myList));
    printf("Nilai Node Terakhir: %d\n", getLast(&myList));
    printf("Nilai Node pada Indeks 2: %d\n", getAtIndex(&myList, 2));
    printf("Jumlah Node dalam Linked List: %d\n", size(&myList));

    deleteList(&myList);

    return 0;
}
