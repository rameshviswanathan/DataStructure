/* File: StackArrayTest.c
* -----------------------
* A program to exercise some basic functionality of stack data structure.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "StackArray.h"

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

	void * arrayStackObj = aStack_CreateStack(capacity);
	verify(1, aStack_IsEmpty(), "aStack_IsEmpty()");
	verify(0, aStack_IsFull(), "aStack_IsFull()");

	int i = 0;
	int arr[] = { 1, 2, 3, 4 };
	int arrSize = sizeof(arr) / sizeof(int);
	for (i = 0; i < arrSize; ++i) {
		aStack_Push(arr[i]);
	}

	i = arrSize - 1;
	while (aStack_IsEmpty() == 0) {
		verify(arr[i], aStack_Pop(), "aStack_Pop");
		--i;
	}

	return 0;
}