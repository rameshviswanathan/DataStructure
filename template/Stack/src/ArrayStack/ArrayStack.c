/**
* File: StackArray.c
* ------------------------
*/

#include "ArrayStack.h"

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

typedef struct _stack {
	unsigned int capacity;
	int top;
	int *array;
} Stack;

/*---------------------------------------------------------------------------*/

void *aStack_CreateStack(unsigned int capacity) {
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/

int aStack_IsFull(void *stack) {
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/

int aStack_IsEmpty(void *stack) {
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/

void aStack_Push(void *stack, int item) {
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/

int aStack_Pop(void *stack) {
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/

void aStack_DestroyStack(void *stack) {
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/
