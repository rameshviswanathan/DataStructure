/* File: QueueArrayTest.c
* -----------------------
* A program to exercise some basic functionality of Queue data structure.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SimpleArrayQVer2.h"

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
	int capacity = 2;

	void *QueueObj = aQueue2_CreateQueue(capacity, 1);
	verify(1, aQueue2_IsEmpty(QueueObj), "aQueue2_IsEmpty()");
	verify(0, aQueue2_IsFull(QueueObj), "aQueue2_IsFull()");

	int i = 0;
	int arr[] = { 1, 2, 3, 4 };
	int arrSize = sizeof(arr) / sizeof(int);
	for (i = 0; i < arrSize; ++i) {
		aQueue2_Enqueue(QueueObj, arr[i]);
	}
	verify(0, aQueue2_IsFull(QueueObj), "aQueue2_IsFull()");

	i = 0;
	while (aQueue2_IsEmpty(QueueObj) == 0) {
		verify(arr[i], aQueue2_Deque(QueueObj), "aQueue2_Deque");
		++i;
	}

	aQueue2_DestroyQueue(QueueObj);

	return 0;
}