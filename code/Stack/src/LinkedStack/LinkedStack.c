/**
* File: LinkedStack.c
* ------------------------
*/

#include "LinkedStack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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

/*---------------------------------------------------------------------------*/

static void *lStack_allocateNode(int data) {
	Node *newEntry = (Node *)malloc(sizeof(Node));
	assert(newEntry != NULL);

	newEntry->next = NULL;
	newEntry->data = data;

	return newEntry;
}

/*---------------------------------------------------------------------------*/

void **lStack_CreateStack() {
	Node *head = NULL;
	return &head;
}

/*---------------------------------------------------------------------------*/

int lStack_IsEmpty(void **stack) {
	assert(stack != NULL);
	Node **headNode = (Node **)stack;

	if (*headNode == NULL)
		return TRUE;

	return FALSE;
}

/*---------------------------------------------------------------------------*/

void lStack_Push(void **stack, int item) {
	assert(stack != NULL);
	Node **headNode = (Node **)stack;

	//allocate new node
	Node *newNode = lStack_allocateNode(item);
	newNode->next = *headNode;
	*headNode = newNode;
}

/*---------------------------------------------------------------------------*/

int lStack_Pop(void **stack) {
	assert(stack != NULL);
	Node **headNode = (Node **)stack;

	if (lStack_IsEmpty(stack))
		return INT_MIN;

	Node *retNode = *headNode;
	*headNode = retNode->next;

	int val = retNode->data;
	free(retNode);

	return val;
}

/*---------------------------------------------------------------------------*/

void lStack_DestroyStack(void **stack) {
	assert(stack != NULL);
	Node **headNode = (Node **)stack;

	while (!lStack_isEmpty(stack)) {
		lStack_Pop(stack);
	}
}

/*---------------------------------------------------------------------------*/
