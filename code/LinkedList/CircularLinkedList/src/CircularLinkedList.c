/**
* File: singlyLinkedList.c
* ------------------------
*/

#include "circularLinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define NOT_YET_IMPLEMENTED printf("%s() not yet implemented!!!\n", __FUNCTION__); exit(1)	

static Node* cListAllocateNode(int addData) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	assert(newNode != NULL);

	newNode->next = NULL;
	newNode->data = addData;

	return newNode;
}

/*---------------------------------------------------------------------------*/

void cListAddNodeAtBegin(Node **headRef, int addData) {

	//Step 1: Check if the headRef is NULL
	assert(headRef != NULL);

	//Step 2: Allocate new Node;
	Node *newNode = cListAllocateNode(addData);

	if (*headRef == NULL) {
		newNode->next = newNode;
	}
	else {
		newNode->next = *headRef;
		Node *curNode = *headRef;
		while (curNode != NULL && curNode->next != *headRef) {
			curNode = curNode->next;
		}
		assert(curNode != NULL);

		curNode->next = newNode;
	}
	*headRef = newNode;
}

/*---------------------------------------------------------------------------*/

void cListAddNodeAtEnd(Node **headRef, int addData) {
	assert(headRef != NULL);

	// Allocate new node
	Node *newNode = cListAllocateNode(addData);

	if (*headRef == NULL) {
		newNode->next = newNode;
		*headRef = newNode;
	}
	else {
		newNode->next = *headRef;
		Node *curNode = *headRef;

		while (curNode != NULL && curNode->next != *headRef)
			curNode = curNode->next;

		assert(curNode != NULL);
		curNode->next = newNode;
	}
}

/*---------------------------------------------------------------------------*/

void cListAddNodeAtPos(Node **headRef, int addData, int pos) {
	assert(headRef != NULL);

	if (pos == 0) {
		cListAddNodeAtBegin(headRef, addData);
	}
	else {

		--pos;

		Node *curNode = *headRef;

		while (pos > 0 && curNode != NULL && curNode->next != *headRef) {
			curNode = curNode->next;
			--pos;
		}

		assert(pos == 0 && curNode != NULL);

		//Allocate new node
		Node *newNode = cListAllocateNode(addData);
		newNode->next = curNode->next;
		curNode->next = newNode;
	}
}

/*---------------------------------------------------------------------------*/

int cListGetCountIterative(Node *head) {
	int cnt = 0;
	Node *curNode = head;

	if (curNode != NULL)
		cnt++;
	while (curNode != NULL && curNode->next != head) {
		++cnt;
		curNode = curNode->next;
	}
	return cnt;
}

/*---------------------------------------------------------------------------*/

static int cListRecurse(Node *head, Node *curNode) {
	if (curNode->next == head)
		return 1;
	else {
		assert(curNode != NULL);
		return cListRecurse(head, curNode->next) + 1;
	}
}

/*---------------------------------------------------------------------------*/

int cListGetCountRecursive(Node *head) {
	Node *curNode = head;
	if (head == NULL)
		return 0;
	return cListRecurse(head, curNode);
}

/*---------------------------------------------------------------------------*/

int cListDelNodeAtBegin(Node **headRef) {
	int retVal = 0;
	Node *delNode = NULL;

	assert(headRef != NULL && *headRef != NULL);
	delNode = *headRef;
	if (*headRef == (*headRef)->next) {
		*headRef = NULL;
	}
	else {
		Node *curNode = *headRef;

		while (curNode->next != *headRef) {
			curNode = curNode->next;
		}
		assert(curNode != NULL);
		delNode = *headRef;
		*headRef = (*headRef)->next;
		curNode->next = *headRef;
	}

	retVal = delNode->data;
	free(delNode);
	return retVal;
}

/*---------------------------------------------------------------------------*/

void cListDelNodeAtEnd(Node **headRef) {
	assert(headRef != NULL);

	Node *delNode = *headRef;

	if (delNode->next == *headRef) {
		*headRef = NULL;
		free(delNode);
	}
	else {
		Node *prevNode = *headRef;
		while (delNode != NULL && delNode->next != *headRef) {
			prevNode = delNode;
			delNode = delNode->next;
		}

		assert(delNode != NULL);
		prevNode->next = delNode->next;
		free(delNode);
	}

}

/*---------------------------------------------------------------------------*/

void cListDelNodeAtPos(Node **headRef, int pos) {
	assert(headRef != NULL);

	if (pos == 0) {
		cListDelNodeAtBegin(headRef);
	}
	else {
		Node *curNode = *headRef;
		Node *prevNode = curNode;
		while (pos > 0 && curNode != NULL && curNode->next != *headRef) {
			prevNode = curNode;
			curNode = curNode->next;
			--pos;
		}
		assert(pos == 0 && curNode != NULL);

		prevNode->next = curNode->next;
		free(curNode);
	}

}

/*---------------------------------------------------------------------------*/

void cListDelAllNodes(Node **headRef) {
	assert(headRef != NULL);
	while (*headRef != NULL) {
		cListDelNodeAtBegin(headRef);
	}
}

/*---------------------------------------------------------------------------*/

void cListDelRepeatOccurrences(Node **headRef, int data) {
	assert(headRef != NULL);

	Node *curNode = *headRef;
	Node *delNode = NULL;
	if (curNode->next == *headRef) {
		if (curNode->data == data)
			cListDelNodeAtBegin(headRef);
	}
	else {
		Node *prevNode = NULL;
		Node *curNode = *headRef;

		while (curNode != NULL && curNode->next != *headRef)
			curNode = curNode->next;

		prevNode = curNode;
		curNode = *headRef;

		while (curNode != NULL && curNode->next != *headRef) {
			if (curNode->data != data) {
				prevNode = curNode;
				curNode = curNode->next;
			}
			else {
				if (prevNode != NULL)
					prevNode->next = curNode->next;
				if (curNode == *headRef)
					*headRef = curNode->next;
				delNode = curNode;
				curNode = curNode->next;
				free(delNode);
				printf("After deleting one entry\n");
				cListTraverse(*headRef);
			}
		}
		if (curNode->data == data) {
			prevNode->next = curNode->next;
			if (curNode == prevNode)
				*headRef = NULL;
			free(curNode);
		}
	}
}

/*---------------------------------------------------------------------------*/

void cListTraverse(Node *head) {
	Node *curNode = head;

	while (curNode->next != head) {
		printf("%5d", curNode->data);
		curNode = curNode->next;
	}
	printf("%5d", curNode->data);

	printf("\n");
}

/*---------------------------------------------------------------------------*/
