/* 	File		:	ADTLIST.h
	Author		:	Reqi Jumantara Hapid (231524023)
	Date		:	05 - 03 - 2024
*/
	
	#ifndef adtlist_h
	#define adtlist_h
	
	#include <stdio.h>
	#include <stdlib.h>
	
	
	typedef struct Node {
	    int data;
	    struct Node *next;
	} Node;
	
	typedef struct {
	    Node *head;
	} List;
	
	/***Constructor***/
	void initLinkedList(List *L);
	Node* createNode (int value);
	
	/***Destructor***/
	void deleteList(List *L);

	/***Mutator***/
	void insertAtBeginning(List *L, int value);
	void insertAtEnd(List *L, int value);
	void insertBetween(List *list, int value, int key);
	void insertAtIndex(List *L, int index, int value);
	void deleteFromBeginning(List *L);
	void deleteFromEnd(List *L);
	void deleteNodeWithValue(List *L, int value);
	void deleteAtIndex(List *L, int index);
	void updateAtPos(List *L, int valuePos, int updateValue);
	
	/***Selector***/
	int getFirst(List *L);
	int getLast(List *L);
	int getAtIndex(List *L, int index);
	Node* searchPos(List *L, int value);
	int size(List *L);
	
	/***I/O Operation***/
	void displayLinkedList(List *L);
	
#endif

