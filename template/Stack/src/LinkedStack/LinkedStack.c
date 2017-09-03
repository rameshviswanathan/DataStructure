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

static Node *head = NULL;

/*---------------------------------------------------------------------------*/

static void *lStack_allocateNode(int data) {
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/

void lStack_CreateStack() {
}

/*---------------------------------------------------------------------------*/

int lStack_IsEmpty() {
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/

void lStack_Push(int item) {
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/

int lStack_Pop() {
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/

void lStack_DestroyStack() {
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/
