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
	assert(capacity > 0);
	Stack *stackObj = (Stack *)malloc(sizeof(Stack));
	assert(stackObj != NULL);

	stackObj->capacity = capacity;
	stackObj->top = -1;

	stackObj->array = (int *)malloc(sizeof(int) * capacity);
	assert(stackObj->array != NULL);

	return stackObj;
}

/*---------------------------------------------------------------------------*/

int aStack_IsFull(void *stack) {
	assert(stack != NULL);
	Stack *stackObj = (Stack *)stack;
	if (stackObj->capacity - 1 == stackObj->top)
		return TRUE;
	return FALSE;

}

/*---------------------------------------------------------------------------*/

int aStack_IsEmpty(void *stack) {
	assert(stack != NULL);
	Stack *stackObj = (Stack *)stack;

	if (stackObj->top == -1)
		return TRUE;

	return FALSE;
}

/*---------------------------------------------------------------------------*/

void aStack_Push(void *stack, int item) {
	assert(stack != NULL);
	Stack *stackObj = (Stack *)stack;

	if (aStack_IsFull(stack))
		return;

	stackObj->array[++stackObj->top] = item;
}

/*---------------------------------------------------------------------------*/

int aStack_Pop(void *stack) {
	assert(stack != NULL);
	Stack *stackObj = (Stack *)stack;

	if (aStack_IsEmpty(stack))
		return INT_MIN;

	return stackObj->array[stackObj->top--];
}

/*---------------------------------------------------------------------------*/

void aStack_DestroyStack(void *stack) {
	assert(stack != NULL);
	Stack *stackObj = (Stack *)stack;

	free(stackObj->array);
	free(stackObj);
	stackObj = NULL;
}

/*---------------------------------------------------------------------------*/
