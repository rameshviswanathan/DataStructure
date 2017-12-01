/**
* File: EfficientDLinkedList.c
* ----------------------------
*/

#include "EfficientDLinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define NOT_YET_IMPLEMENTED printf("%s() not yet implemented!!!\n", __FUNCTION__); exit(1)	

static Node* dList2AllocateNode(int addData) {

	Node *newNode = (Node*)malloc(sizeof(Node));
	assert(newNode != NULL);

	newNode->data = addData;
	newNode->pDiff = NULL;

	return newNode;
}

/*---------------------------------------------------------------------------*/

static Node *dList2Xor(Node *prevNode, Node *nextNode) {
	return (Node *)((uintptr_t)prevNode ^ (uintptr_t)nextNode);
}

/*---------------------------------------------------------------------------*/

void dList2AddNodeAtBegin(Node **headRef, int addData) {
	assert(headRef != NULL);

	//allocate new node
	Node *newNode = dList2AllocateNode(addData);

	if (*headRef != NULL) {
		Node *curHead = *headRef;
		Node *curHead_next = dList2Xor(curHead->pDiff, NULL);
		curHead->pDiff = dList2Xor(newNode, curHead_next);
		newNode->pDiff = dList2Xor(NULL, curHead);
	}

	*headRef = newNode;
}

/*---------------------------------------------------------------------------*/

void dList2AddNodeAtEnd(Node **headRef, int addData) {
	assert(headRef != NULL);

	Node *newNode = dList2AllocateNode(addData);

	if (*headRef == NULL) {
		*headRef = newNode;
	}
	else {
		Node *curNode = *headRef;
		Node *prevNode = NULL;
		while (dList2Xor(prevNode, curNode->pDiff)) {
			Node *newCurNode = dList2Xor(prevNode, curNode->pDiff);
			prevNode = curNode;
			curNode = newCurNode;
		}
		curNode->pDiff = dList2Xor(prevNode, newNode);
		newNode->pDiff = dList2Xor(curNode, NULL);
	}
}

/*---------------------------------------------------------------------------*/

void dList2AddNodeAtPos(Node **headRef, int addData, int pos) {
	assert(headRef != NULL);
	assert(pos >= 0);

	if (pos == 0)
		dList2AddNodeAtBegin(headRef, addData);
	else {
		Node *newNode = dList2AllocateNode(addData);
		Node *curNode = *headRef;
		Node *prevNode = NULL;
		Node *nextNode = NULL;

		--pos;
		while (pos != 0 && (nextNode = dList2Xor(curNode->pDiff, prevNode)) != NULL) {
			prevNode = curNode;
			curNode = nextNode;
			--pos;
		}

		assert(pos == 0);
		nextNode = dList2Xor(curNode->pDiff, prevNode);
		curNode->pDiff = dList2Xor(prevNode, newNode);
		newNode->pDiff = dList2Xor(curNode, nextNode);

		Node *nextNextNode = dList2Xor(nextNode->pDiff, curNode);
		nextNode->pDiff = dList2Xor(nextNextNode, newNode);
	}
}

/*---------------------------------------------------------------------------*/

int dList2GetCountIterative(Node *head) {
	int count = 0;
	Node *prevNode = NULL;
	Node *curNode = head;

	while (curNode != NULL) {
		++count;
		Node * newCurNode = dList2Xor(prevNode, curNode->pDiff);
		prevNode = curNode;
		curNode = newCurNode;
	}

	return count;
}

/*---------------------------------------------------------------------------*/

int dList2GetCountRecursiveLocal(Node *curNode, Node *prevNode) {

	Node *nextNode = NULL;
	if ((nextNode = dList2Xor(curNode->pDiff, prevNode)) == NULL)
		return 1;
	else {
		prevNode = curNode;
		curNode = nextNode;
		return dList2GetCountRecursiveLocal(curNode, prevNode) + 1;
	}
}

/*---------------------------------------------------------------------------*/

int dList2GetCountRecursive(Node *head) {
	Node *prevNode = NULL;
	Node *curNode = head;
	assert(curNode != NULL);

	return dList2GetCountRecursiveLocal(curNode, prevNode);
}

/*---------------------------------------------------------------------------*/

int dList2DelNodeAtBegin(Node **headRef) {
	int data;

	assert(headRef != NULL);
	assert(*headRef != NULL);

	Node *delNode = *headRef;
	Node *nextNode = dList2Xor(delNode->pDiff, NULL);

	if (nextNode != NULL) {
		Node *nextNextNode = dList2Xor(delNode, nextNode->pDiff);
		nextNode->pDiff = dList2Xor(NULL, nextNextNode);
	}

	*headRef = nextNode;
	data = delNode->data;
	free(delNode);

	return data;
}

/*---------------------------------------------------------------------------*/

int dList2DelNodeAtEnd(Node **headRef) {
	int data;

	assert(headRef != NULL);
	assert(*headRef != NULL);

	Node *curNode = *headRef;
	if (!dList2Xor(NULL, curNode->pDiff)) {
		*headRef = NULL;
	}
	else {
		Node *prevNode = NULL;
		Node *nextNode = NULL;

		while ((nextNode = dList2Xor(prevNode, curNode->pDiff))) {
			prevNode = curNode;
			curNode = nextNode;
		}
		Node *prevPrevNode = dList2Xor(prevNode->pDiff, curNode);
		prevNode->pDiff = dList2Xor(prevPrevNode, NULL);
	}

	data = curNode->data;
	free(curNode);
	curNode = NULL;

	return data;
}

/*---------------------------------------------------------------------------*/

void dList2DelNodeAtPos(Node **headRef, int pos) {
	assert(headRef != 0);
	assert(*headRef != 0);
	assert(pos >= 0);

	if (pos == 0) {
		dList2DelNodeAtBegin(headRef);
	}
	else {
		Node *curNode = *headRef;
		Node *prevNode = NULL;
		Node *nextNode = NULL;

		while (pos != 0 && (nextNode = dList2Xor(prevNode, curNode->pDiff)) != NULL) {
			prevNode = curNode;
			curNode = nextNode;
			--pos;
		}

		assert(pos == 0);

		Node *prevPrevNode = dList2Xor(prevNode->pDiff, curNode);
		nextNode = dList2Xor(prevNode, curNode->pDiff);
		Node *nextNextNode = dList2Xor(nextNode->pDiff, curNode);


		prevNode->pDiff = dList2Xor(prevPrevNode, nextNode);
		nextNode->pDiff = dList2Xor(prevNode, nextNextNode);

		free(curNode);
	}
}

/*---------------------------------------------------------------------------*/

void dList2DelAllNodes(Node **headRef) {
	assert(headRef != NULL || *headRef != NULL);
	while (*headRef != NULL) {
		dList2DelNodeAtBegin(headRef);
	}
}

/*---------------------------------------------------------------------------*/

void dList2DelRepeatOccurrences(Node **headRef, int data) {
	assert(headRef != NULL || *headRef != NULL);

	Node *curNode = *headRef;
	Node *prevNode = NULL;
	Node *nextNode = NULL;
	Node *nextNextNode = NULL;
	while (curNode != NULL) {
		nextNode = dList2Xor(curNode->pDiff, prevNode);
		if (curNode->data == data) {
			if (nextNode) {
				nextNextNode = dList2Xor(nextNode->pDiff, curNode);
				nextNode->pDiff = dList2Xor(prevNode, nextNextNode);
			}


			if (prevNode == NULL)
				*headRef = nextNode;
			else {
				Node *prevPrevNode = dList2Xor(prevNode->pDiff, curNode);
				prevNode->pDiff = dList2Xor(prevPrevNode, nextNode);
			}

			Node *delNode = curNode;
			curNode = nextNode;
			free(delNode);
		}
		else {
			prevNode = curNode;
			curNode = nextNode;
		}
	}
}

/*---------------------------------------------------------------------------*/

void dList2Traverse(Node *head) {
	Node *prevNode = NULL;
	Node *curNode = head;

	while (curNode) {
		printf("%5d", curNode->data);
		Node * newCurNode = dList2Xor(prevNode, curNode->pDiff);
		prevNode = curNode;
		curNode = newCurNode;
	}
	printf("\n");
}

/*---------------------------------------------------------------------------*/
