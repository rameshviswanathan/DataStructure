/**
* File: LinkedStack.h
* -------------------
* Defines the stack data structure implemented using linked List.
*
* Stack is a simple data structure that supports two operations
* Push and Pop operation.
*/

#ifndef _LINKED_STACK_H
#define _LINKED_STACK_H

#include <stdio.h>

#define TRUE		1
#define FALSE		0

/**
* --------------------------------------------------------
* Function : lStack_CreateStack
* Usage    : lStack_CreateStack();
* Parameter: stack capacity entry with which the internal
*            stack will be created.
* Notes    : generates the stack storage object.  This object
*            should be passed around between calls.
* --------------------------------------------------------
*/

void lStack_CreateStack();

/**
* --------------------------------------------------------
* Function : lStack_DestroyStack
* Usage    : lStack_DestroyStack();
* Notes    : generates the stack storage object.  This object
*            should be passed around between calls.
* --------------------------------------------------------
*/

void lStack_DestroyStack();

/**
* --------------------------------------------------------
* Function : lStack_IsEmpty
* Usage    : lStack_IsEmpty();
* Returns  : 1 if it is empty and 0 otherwise
* Notes    : Query to check if the stack is full
* --------------------------------------------------------
*/
int lStack_IsEmpty();

/**
* --------------------------------------------------------
* Function : lStack_Push
* Usage    : lStack_Push(int item);
* Parameter: item to be Pushed to top of stack
* Notes    : If stack is full, nothing get Pushed
* --------------------------------------------------------
*/
void lStack_Push(int item);

/**
* --------------------------------------------------------
* Function : lStack_Pop
* Usage    : lStack_Pop();
* Returns  : returns item from stack top
* Notes    : If stack is empty, returns INT_MIN to indicate
*            failure
* --------------------------------------------------------
*/
int lStack_Pop();

#endif	// _LINKED_STACK_H