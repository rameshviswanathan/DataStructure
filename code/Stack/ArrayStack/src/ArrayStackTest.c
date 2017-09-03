/* File: StackArrayTest.c
* -----------------------
* A program to exercise some basic functionality of stack data structure.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayStack.h"

/* Function: verify
* ----------------
* Used to compare a given result with what was expected and report on whether
* passed/failed.
*/
static void verify(int expected, int found, char *msg)
{
	printf("%s expect: %d found: %d. %s\n", msg, expected, found,
		(expected == found) ? "Seems ok." : "##### PROBLEM HERE #####");
}

int main() {
	int capacity = 100;

	void *stackObj = aStack_CreateStack(capacity);
	verify(1, aStack_IsEmpty(stackObj), "aStack_IsEmpty()");
	verify(0, aStack_IsFull(stackObj), "aStack_IsFull()");

	int i = 0;
	int arr[] = { 1, 2, 3, 4 };
	int arrSize = sizeof(arr) / sizeof(int);
	for (i = 0; i < arrSize; ++i) {
		aStack_Push(stackObj, arr[i]);
	}

	i = arrSize - 1;
	while (aStack_IsEmpty(stackObj) == 0) {
		verify(arr[i], aStack_Pop(stackObj), "aStack_Pop");
		--i;
	}

	aStack_DestroyStack(stackObj);

	return 0;
}