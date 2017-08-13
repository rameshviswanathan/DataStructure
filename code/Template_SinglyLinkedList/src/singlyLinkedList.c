/**
* File: singlyLinkedList.c
* ------------------------
*/

#include "singlyLinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOT_YET_IMPLEMENTED printf("%s() not yet implemented!!!\n", __FUNCTION__); exit(1)	

void addNodeToListBegin(Node **headRef, int addData) {
	//NOT_YET_IMPLEMENTED;
	// Step 1: Allocate new Node
	Node *newNode = (Node *)malloc(sizeof(Node));
	if (!newNode) {
		printf("Err: Cannot Allocate new Node\n");
		return;
	}

	newNode->data = addData;
	newNode->next = NULL;

	// Step2 Check if the headRef is NULL
	if (!headRef)
		return;

	newNode->next = *headRef;
	*headRef = newNode;
}

void addNodeToListEnd(Node **headRef, int addData) {
	NOT_YET_IMPLEMENTED;
}

int getListNodeCountIterative(Node *head) {
	NOT_YET_IMPLEMENTED;
}

int getListNodeCountRecursive(Node *head) {
	NOT_YET_IMPLEMENTED;
}

void deleteNodeAtListBegin(Node **headRef) {
	NOT_YET_IMPLEMENTED;
}
void deleteNodeAtListEnd(Node **headRef) {
	NOT_YET_IMPLEMENTED;
}

void deleteList(Node **headRef) {
	NOT_YET_IMPLEMENTED;
}





