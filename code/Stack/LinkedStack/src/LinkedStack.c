/**
* File: LinkedStack.c
* ------------------------
*/

#include "LinkedStack.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#define NOT_YET_IMPLEMENTED printf("%s() not yet implemented!!!\n", __FUNCTION__); exit(1)	

/*---------------------------------------------------------------------------*/

static void *lStack_allocateStack(int data) {
	Stack *newEntry = (Stack *)malloc(sizeof(Stack));
	assert(newEntry != NULL);

	newEntry->next = NULL;
	newEntry->data = data;

	return newEntry;
}

/*---------------------------------------------------------------------------*/

void lStack_CreateStack(Stack **stack) {
	assert(stack != NULL);
	*stack = NULL;
}

/*---------------------------------------------------------------------------*/

int lStack_IsEmpty(Stack *stack) {
	if (stack == NULL)
		return TRUE;

	return FALSE;
}

/*---------------------------------------------------------------------------*/

void lStack_Push(Stack **stack, int item) {
	assert(stack != NULL);
	
	//allocate new Stack
	Stack *newStack = lStack_allocateStack(item);
	newStack->next = *stack;
	*stack = newStack;
}

/*---------------------------------------------------------------------------*/

int lStack_Pop(Stack **stack) {
	assert(stack != NULL);

	if (lStack_IsEmpty(*stack))
		return INT_MIN;

	Stack *retStack = *stack;
	*stack = retStack->next;

	int val = retStack->data;
	free(retStack);

	return val;
}

/*---------------------------------------------------------------------------*/

void lStack_DestroyStack(Stack **stack) {
	assert(stack != NULL);
	while (!lStack_IsEmpty(*stack)) {
		(void)lStack_Pop(stack);
	}
}

/*---------------------------------------------------------------------------*/
