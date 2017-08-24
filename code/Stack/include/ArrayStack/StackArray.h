/**
* File: StackArray
* ----------------
* Defines the stack data structure implemented using arrays.
*
* Stack is a simple data structure that supports two operations
* Push and Pop operation.
*/

#ifndef _STACK_ARRAY_H
#define _STACK_ARRAY_H

#include <stdio.h>

#define TRUE		1
#define FALSE		0

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

/**
* --------------------------------------------------------
* Function : aStack_CreateStack
* Usage    : aStack_CreateStack(unsigned int capacity);
* Parameter: stack capacity entry with which the internal
*            stack will be created.
* Notes    : generates the stack storage object.  This object
*            should be passed around between calls.
* Returns  : stack Object
* --------------------------------------------------------
*/

void *aStack_CreateStack(unsigned int capacity);

/**
* --------------------------------------------------------
* Function : aStack_DestroyStack
* Usage    : aStack_DestroyStack(void *stack);
* Parameter: stack object to be freed
* Notes    : generates the stack storage object.  This object
*            should be passed around between calls.
* --------------------------------------------------------
*/

void aStack_DestroyStack(void *stack);

/**
* --------------------------------------------------------
* Function : aStack_IsFull
* Usage    : aStack_IsFull();
* Parameter: stack object
* Returns  : 0 if it is not full and 1 for full
* Notes    : Query to check if the stack is full
* --------------------------------------------------------
*/
int aStack_IsFull(void *stack);

/**
* --------------------------------------------------------
* Function : aStack_IsEmpty
* Usage    : aStack_IsEmpty();
* Parameter: stack object
* Returns  : 1 if it is empty and 0 otherwise
* Notes    : Query to check if the stack is full
* --------------------------------------------------------
*/
int aStack_IsEmpty(void *stack);

/**
* --------------------------------------------------------
* Function : aStack_Push
* Usage    : aStack_Push(int item);
* Parameter: stack object
* Parameter: item to be Pushed to top of stack
* Notes    : If stack is full, nothing get Pushed
* --------------------------------------------------------
*/
void aStack_Push(void *stack, int item);

/**
* --------------------------------------------------------
* Function : aStack_Pop
* Usage    : aStack_Pop();
* Parameter: stack object
* Returns  : returns item from stack top
* Notes    : If stack is empty, returns INT_MIN to indicate
*            failure
* --------------------------------------------------------
*/
int aStack_Pop(void *stack);

#endif	// _STACK_ARRAY_H