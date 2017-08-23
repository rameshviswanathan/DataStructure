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
} stack;

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
* Function : aStack_IsFull
* Usage    : aStack_IsFull();
* Returns  : 0 if it is not full and 1 for full
* Notes    : Query to check if the stack is full
* --------------------------------------------------------
*/
int aStack_IsFull();

/**
* --------------------------------------------------------
* Function : aStack_IsEmpty
* Usage    : aStack_IsEmpty();
* Returns  : 1 if it is empty and 0 otherwise
* Notes    : Query to check if the stack is full
* --------------------------------------------------------
*/
int aStack_IsEmpty();

/**
* --------------------------------------------------------
* Function : aStack_Push
* Usage    : aStack_Push(int item);
* Parameter: item to be Pushed to top of stack
* Notes    : If stack is full, nothing get Pushed
* --------------------------------------------------------
*/
void aStack_Push(int item);

/**
* --------------------------------------------------------
* Function : aStack_Pop
* Usage    : aStack_Pop();
* Returns  : returns item from stack top
* Notes    : If stack is empty, returns INT_MIN to indicate
*            failure
* --------------------------------------------------------
*/
int aStack_Pop();

#endif	// _STACK_ARRAY_H