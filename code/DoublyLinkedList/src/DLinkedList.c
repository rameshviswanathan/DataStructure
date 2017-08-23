/**
* File: DLinkedList.c
* ------------------------
*/

#include "DlinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define NOT_YET_IMPLEMENTED printf("%s() not yet implemented!!!\n", __FUNCTION__); exit(1)	

static Node* dListAllocateNode(int addData) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	assert(newNode != NULL);

	newNode->data = addData;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

/*---------------------------------------------------------------------------*/

void dListAddNodeAtBegin(Node **headRef, int addData) {
	assert(headRef != NULL);

	//allocate new node
	Node *newNode = dListAllocateNode(addData);

	if (*headRef != NULL) {
		newNode->next = *headRef;
		(*headRef)->prev = newNode;
	}
	*headRef = newNode;
}

/*---------------------------------------------------------------------------*/

void dListAddNodeAtEnd(Node **headRef, int addData) {
	assert(headRef != NULL);

	// allocate node
	Node *newNode = dListAllocateNode(addData);

	// check if there is any node
	if (*headRef == NULL) {
		*headRef = newNode;
	}
	else {
		Node *curNode = *headRef;
		while (curNode->next != NULL) {
			curNode = curNode->next;
		}
		newNode->prev = curNode;
		curNode->next = newNode;
	}
}

/*---------------------------------------------------------------------------*/

void dListAddNodeAtPos(Node **headRef, int addData, int pos) {
	assert(headRef != NULL);
	if (pos == 0) {
		dListAddNodeAtBegin(headRef, addData);
	}
	else {
		pos--;
		Node *curNode = *headRef;
		while (pos > 0 && curNode != NULL) {
			--pos;
			curNode = curNode->next;
		}

		assert(pos == 0 || curNode != NULL);

		// Allocate new node
		Node *newNode = dListAllocateNode(addData);
		curNode->prev->next = newNode;
		newNode->prev = curNode->prev;
		newNode->next = curNode;
		curNode->prev = newNode;
	}
}

/*---------------------------------------------------------------------------*/

int dListGetCountIterative(Node *head) {
	int count = 0;
	while (head != NULL) {
		++count;
		head = head->next;
	}
	return count;
}

/*---------------------------------------------------------------------------*/

int dListGetCountRecursive(Node *head) {
	if (head == NULL)
		return 0;
	else {
		head = head->next;
		return dListGetCountRecursive(head) + 1;
	}
}

/*---------------------------------------------------------------------------*/

int dListDelNodeAtBegin(Node **headRef) {
	int nodeData = 0;
	assert(headRef != NULL || *headRef != NULL);
	Node *delNode = *headRef;

	*headRef = (*headRef)->next;

	// To take care of single node case
	if (*headRef != NULL)
		(*headRef)->prev = NULL;

	delNode->next = NULL;
	delNode->prev = NULL;
	nodeData = delNode->data;
	free(delNode);

	return nodeData;
}

/*---------------------------------------------------------------------------*/

void dListDelNodeAtEnd(Node **headRef) {
	assert(headRef != NULL && *headRef != NULL);

	Node *delNode = NULL;

	if ((*headRef)->next == NULL) {
		delNode = *headRef;
		*headRef = NULL;
	}
	else {
		delNode = *headRef;
		while (delNode->next != NULL) {
			delNode = delNode->next;
		}
		delNode->prev->next = NULL;
		delNode->prev = NULL;
	}
	free(delNode);
}

/*---------------------------------------------------------------------------*/

void dListDelNodeAtPos(Node **headRef, int pos) {
	assert(headRef != NULL && *headRef != NULL);
	if (pos == 0) {
		dListDelNodeAtBegin(headRef);
	}
	else {
		Node *curNode = *headRef;
		while (pos > 0 && curNode != NULL) {
			curNode = curNode->next;
			pos--;
		}
		assert(pos == 0 && curNode != NULL);
		curNode->prev->next = curNode->next;
		curNode->next->prev = curNode->prev;
		free(curNode);
	}
}

/*---------------------------------------------------------------------------*/

void dListDelAllNodes(Node **headRef) {
	assert(headRef != NULL);

	while (*headRef != NULL)
	{
		dListDelNodeAtBegin(headRef);
	}
}

/*---------------------------------------------------------------------------*/

void dListDelRepeatOccurrences(Node **headRef, int data) {
	assert(headRef != NULL && *headRef != NULL);
	while (*headRef != NULL && (*headRef)->data == data) {
		dListDelNodeAtBegin(headRef, data);
	}

	if (*headRef != NULL) {
		Node *curNode = *headRef;

		while (curNode != NULL) {
			if (curNode->data == data) {
				Node *delNode = curNode;
				curNode->prev->next = curNode->next;
				if (curNode->next != NULL)
					curNode->next->prev = curNode->prev;
				curNode = curNode->next;
				free(delNode);
			}
			else
				curNode = curNode->next;
		}
	}

}

/*---------------------------------------------------------------------------*/

void dListTraverse(Node *head) {
	while (head != NULL) {
		printf("%5d", head->data);
		head = head->next;
	}
	printf("\n");
}

/*---------------------------------------------------------------------------*/
