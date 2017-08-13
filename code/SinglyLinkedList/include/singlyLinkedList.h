/**
* File: singlyLinkedList
* ----------------------
* Defines the interface for the single linked list.
*
* The single linked list is a dynamic data structure that holds a set of
* int values.  This is similar to array expect that the memory for storing
* new data entry is allocated on demand basis.
*/

#ifndef _singlyLinkedList_h
#define _singlyLinkedList_h

#include <stdio.h>	//  this header defines the C99 bool type

/**
* Type: Node
* ----------
* Node is simple structure that holds
* a) the data to be stored
* b) link to the next node
* A singled linked list is a sequence of nodes with each node having a reference
* to its following node.  The last node in the list will be NULL.
*/

typedef struct _node {
	int data;
	struct _node *next;
} Node;

/**
* Function: addNodeToListBegin
* Usage: addNodeAtListBegin(Node **headRef, int addData);
* -------------------------------------------------------
* Parameter: headRef is a pointer to list head node. We pass pointer
* since adding new node is going to change where the list head pointing to
* Parameter: addData is an int value that needs to be added
* to the begining of the list.
*/

void addNodeToListBegin(Node **headRef, int addData);

/**
* Function: addNodeToListEnd
* Usage: addNodeAtListEnd(Node **headRef, int addData);
* -------------------------------------------------------
* Parameter: headRef is a pointer to list head node. We pass pointer
* since we may end up passing empty list.
* Parameter: addData is an int value that needs to be added
* to the end of the list.
*/

void addNodeToListEnd(Node **headRef, int addData);

void addNodeToListEnd(Node **headRef, int addData);

int getListNodeCountIterative(Node *head);

int getListNodeCountRecursive(Node *head);

void deleteNodeAtListBegin(Node **headRef);

void deleteNodeAtListEnd(Node **headRef);

void deleteList(Node **headRef);

#endif	//_singlyLinkedList_h