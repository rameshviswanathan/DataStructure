/* File: QueueArrayTest.c
* -----------------------
* A program to exercise some basic functionality of Queue data structure.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedQueue.h"

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
	void *QueueObj = aQueue_CreateQueue();
	verify(1, aQueue_IsEmpty(QueueObj), "aQueue_IsEmpty()");

	int i = 0;
	int arr[] = { 1, 2, 3, 4 };
	int arrSize = sizeof(arr) / sizeof(int);
	for (i = 0; i < arrSize; ++i) {
		aQueue_Enqueue(QueueObj, arr[i]);
	}

	i = 0;
	while (aQueue_IsEmpty(QueueObj) == 0) {
		verify(arr[i], aQueue_Deque(QueueObj), "aQueue_Deque");
		++i;
	}

	aQueue_DestroyQueue(QueueObj);

	return 0;
}