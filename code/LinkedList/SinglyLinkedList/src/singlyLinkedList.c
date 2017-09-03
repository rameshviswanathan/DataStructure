/**
* File: singlyLinkedList.c
* ------------------------
*/

#include "singlyLinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define NOT_YET_IMPLEMENTED printf("%s() not yet implemented!!!\n", __FUNCTION__); exit(1)	

static Node* sListAllocateNode(int addData) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	assert(newNode != NULL);

	newNode->data = addData;
	newNode->next = NULL;

	return newNode;
}

/*---------------------------------------------------------------------------*/

void sListAddNodeAtBegin(Node **headRef, int addData) {

	//Step 1: Check if headRef is NULL
	assert(headRef != NULL);

	//Step 2: Create a new node with addData as its value
	Node *newNode = sListAllocateNode(addData);

	//Step 3: Make newNode to be the first node
	newNode->next = *headRef;
	*headRef = newNode;
}

/*---------------------------------------------------------------------------*/

void sListAddNodeAtEnd(Node **headRef, int addData) {
	//Step 1: Check if headRef is NULL
	assert(headRef != NULL);

	//Step 2: Create a new node with addData as its value
	Node *newNode = sListAllocateNode(addData);

	if (*headRef == NULL) {
		*headRef = newNode;
	}
	else {
		Node *curNode = *headRef;
		while (curNode->next != NULL)
			curNode = curNode->next;
		curNode->next = newNode;
	}
}

/*---------------------------------------------------------------------------*/

void sListAddNodeAtPos(Node **headRef, int addData, int pos) {
	assert(headRef != NULL);

	Node *nodeBeforeInsert = *headRef;
	if (pos != 0) {
		pos--;
		while (nodeBeforeInsert != NULL && pos > 0) {
			nodeBeforeInsert = nodeBeforeInsert->next;
			pos--;
		}

		if (pos != 0)
			return;
	}

	// create a new node with teh addData value
	Node *newNode = sListAllocateNode(addData);

	if (nodeBeforeInsert == *headRef) {
		newNode->next = *headRef;
		*headRef = newNode;
	}
	else {
		newNode->next = nodeBeforeInsert->next;
		nodeBeforeInsert->next = newNode;
	}
}

/*---------------------------------------------------------------------------*/

int sListGetCountIterative(Node *head) {
	int cnt = 0;

	while (head != NULL) {
		++cnt;
		head = head->next;
	}

	return cnt;
}

/*---------------------------------------------------------------------------*/

int sListGetCountRecursive(Node *head) {
	if (head == NULL)
		return 0;
	else {
		head = head->next;
		return sListGetCountRecursive(head) + 1;
	}
}

/*---------------------------------------------------------------------------*/

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

/*---------------------------------------------------------------------------*/

void sListDelNodeAtEnd(Node **headRef) {
	assert(headRef != NULL);

	Node *curNode = *headRef;
	if (curNode->next == NULL) {
		free(curNode);
		*headRef = NULL;
	}
	else {
		Node *prevNode = curNode;
		while (curNode->next != NULL) {
			prevNode = curNode;
			curNode = curNode->next;
		}
		free(curNode);
		prevNode->next = NULL;
	}
}

/*---------------------------------------------------------------------------*/

void sListDelNodeAtPos(Node **headRef, int pos) {
	assert(headRef != NULL);

	Node *curNode = *headRef;

	if (pos == 0) {
		*headRef = curNode->next;
		free(curNode);
	}
	else {
		pos--;
		while (pos > 0 && curNode != NULL) {
			curNode = curNode->next;
			--pos;
		}

		assert(curNode->next != NULL);
		Node *delNode = curNode->next;
		curNode->next = curNode->next->next;
		free(delNode);
	}
}

/*---------------------------------------------------------------------------*/

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

/*---------------------------------------------------------------------------*/

void sListDelRepeatOccurrences(Node **headRef, int data) {
	assert(headRef != NULL);

	while (*headRef != NULL && (*headRef)->data == data) {
		Node *delNode = *headRef;
		*headRef = delNode->next;
		free(delNode);
	}

	Node *curNode = *headRef;
	Node *prevNode = *headRef;
	while (curNode != NULL) {
		if (curNode->data == data) {
			Node *delNode = curNode;
			prevNode->next = curNode->next;
			curNode = curNode->next;
			free(delNode);
		}
		else {
			prevNode = curNode;
			curNode = curNode->next;
		}
	}
}

/*---------------------------------------------------------------------------*/

void sListTraverse(Node *head) {
	while (head != NULL) {
		printf("%5d", head->data);
		head = head->next;
	}
	printf("\n");
}

/*---------------------------------------------------------------------------*/
