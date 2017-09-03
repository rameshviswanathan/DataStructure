/**
* File: LinkedStack.c
* ------------------------
*/

#include "LinkedStack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#define NOT_YET_IMPLEMENTED printf("%s() not yet implemented!!!\n", __FUNCTION__); exit(1)	

/**
* Type: Stack
* -----------
* Stack strucure holds
* a) stack capacity represents the maximum stack size
* b) top which tracks the current entry of the stack
* c) array to hold all stack data elements
*/

typedef struct _node {
	int data;
	struct _node *next;
} Node;

static Node *head = NULL;

/*---------------------------------------------------------------------------*/

static void *lStack_allocateNode(int data) {
	Node *newEntry = (Node *)malloc(sizeof(Node));
	assert(newEntry != NULL);

	newEntry->next = NULL;
	newEntry->data = data;

	return newEntry;
}

/*---------------------------------------------------------------------------*/

void lStack_CreateStack() {
}

/*---------------------------------------------------------------------------*/

int lStack_IsEmpty() {
	if (head == NULL)
		return TRUE;

	return FALSE;
}

/*---------------------------------------------------------------------------*/

void lStack_Push(int item) {

	//allocate new node
	Node *newNode = lStack_allocateNode(item);
	newNode->next = head;
	head = newNode;
}

/*---------------------------------------------------------------------------*/

int lStack_Pop() {
	if (lStack_IsEmpty())
		return INT_MIN;

	Node *retNode = head;
	head = retNode->next;

	int val = retNode->data;
	free(retNode);

	return val;
}

/*---------------------------------------------------------------------------*/

void lStack_DestroyStack() {
	while (!lStack_IsEmpty()) {
		(void)lStack_Pop();
	}
}

/*---------------------------------------------------------------------------*/
