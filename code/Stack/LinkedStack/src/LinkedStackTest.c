/* File: StackArrayTest.c
* -----------------------
* A program to exercise some basic functionality of stack data structure.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedStack.h"

/* Function: verify
* -----------------
* Used to compare a given result with what was expected and report on whether
* passed/failed.
*/

static void verify(int expected, int found, char *msg)
{
	printf("%s expect: %d found: %d. %s\n", msg, expected, found,
		(expected == found) ? "Seems ok." : "##### PROBLEM HERE #####");
}

int main() {
	Stack *stack = NULL;

	lStack_CreateStack(&stack);

	verify(1, lStack_IsEmpty(stack), "lStack_IsEmpty()");

	int i = 0;
	int arr[] = { 1, 2, 3, 4 };
	int arrSize = sizeof(arr) / sizeof(int);
	for (i = 0; i < arrSize; ++i) {
		lStack_Push(&stack, arr[i]);
	}

	i = arrSize - 1;
	while (lStack_IsEmpty(stack) == 0) {
		verify(arr[i], lStack_Pop(&stack), "lStack_Pop");
		--i;
	}

	lStack_DestroyStack(&stack);

	return 0;
}

/*---------------------------------------------------------------------------*/
