/**
* File: singlyLinkedList.c
* ------------------------
*/

#include "singlyLinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOT_YET_IMPLEMENTED printf("%s() not yet implemented!!!\n", __FUNCTION__); exit(1)	

void sListAddNodeAtBegin(Node **headRef, int addData) {
	//Step 1: Create a new node with addData as its value
	Node *newData = (Node *)malloc(sizeof(Node));
	if (!newData) {
		printf("memory allocation error \n");
		return;
	}
	newData->data = addData;
	newData->next = NULL;

	//Step 2: Check if headRef is NULL
	if (!headRef)
		return;

	//Step 3: Make newNode to be the first node
	newData->next = *headRef;
	*headRef = newData;
}

void sListAddNodeAtEnd(Node **headRef, int addData) {
	NOT_YET_IMPLEMENTED;
}

void sListAddNodeAtPos(Node **headRef, int addData, int pos) {
	NOT_YET_IMPLEMENTED;
}

int sListGetCountIterative(Node *head) {
	int cnt = 0;

	while (head != NULL) {
		++cnt;
		head = head->next;
	}

	return cnt;
}

int sListGetCountRecursive(Node *head) {
	if (head == NULL)
		return 0;
	else {
		head = head->next;
		return sListGetCountRecursive(head) + 1;
	}
}

int sListDelNodeAtBegin(Node **headRef) {
	Node *delNode;
	int retVal = 0;

	//Step1: Check input parameters
	if (!headRef || *headRef == NULL)
		return retVal;

	delNode = *headRef;
	retVal = delNode->data;
	*headRef = (*headRef)->next;

	free(delNode);
	return retVal;
}

void sListDelNodeAtEnd(Node **headRef) {
	NOT_YET_IMPLEMENTED;
}

void sListDelNodeAtPos(Node **headRef, int pos) {
	NOT_YET_IMPLEMENTED;
}

void sListDelAllNodes(Node **headRef) {
	Node *delNode;
	Node *curNode;

	// Step 1: Check for input parameters
	if (!headRef || *headRef == NULL)
		return;

	// Step 2: Iterate over and delete node;
	curNode = *headRef;

	while (curNode) {
		delNode = curNode;
		curNode = curNode->next;
		free(delNode);
	}

	*headRef = NULL;
}