/* File: doublyLinkedListTest.c
* -----------------------------
* A program to exercise some basic functionality of the doubly linked list.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DLinkedList.h"

/* Function: Verify
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
	Node *head = NULL;
	int data;

	printf("------------ Starting Simple test ------------\n");
	printf("Testing addNodeToListBegin ......\n");
	data = 7;

	dListAddNodeAtBegin(&head, data);
	verify(data, head->data, "dListAddNodeAtBegin");

	verify(1, dListGetCountIterative(head), "dListGetCountIterative");

	verify(data, dListDelNodeAtBegin(&head), "dListDelNodeAtBegin");
	verify((int)0, (int)(int *)head, "dListDelNodeAtBegin");

	dListAddNodeAtEnd(&head, 1);
	dListAddNodeAtEnd(&head, 2);
	dListAddNodeAtEnd(&head, 3);
	verify(3, dListGetCountIterative(head), "dListGetCountIterative");

	dListAddNodeAtPos(&head, 4, 3);
	dListAddNodeAtPos(&head, 0, 0);
	dListAddNodeAtEnd(&head, 5);
	verify(6, dListGetCountRecursive(head), "dListGetCountRecursive");

	dListTraverse(head);

	// Test deleting node
	dListDelNodeAtPos(&head, 2);
	dListTraverse(head);

	dListDelNodeAtPos(&head, 1);
	dListTraverse(head);

	dListDelNodeAtPos(&head, 0);
	dListTraverse(head);

	dListDelNodeAtEnd(&head);
	dListTraverse(head);

	dListDelNodeAtBegin(&head);
	dListTraverse(head);

	dListDelNodeAtEnd(&head);
	verify(0, dListGetCountRecursive(head), "dListGetCountRecursive");

	// Test all occurrence delete
	int constDataVal = 10;
	for (int i = 0; i < 5; ++i)
		dListAddNodeAtEnd(&head, 10);

	dListTraverse(head);
	dListDelRepeatOccurrences(&head, constDataVal);
	verify(0, dListGetCountRecursive(head), "dListGetCountRecursive");

	for (int i = 0; i < 5; ++i) {
		dListAddNodeAtEnd(&head, i);
		dListAddNodeAtEnd(&head, 10);
	}

	dListTraverse(head);
	dListDelRepeatOccurrences(&head, constDataVal);
	dListTraverse(head);
	verify(5, dListGetCountRecursive(head), "dListGetCountRecursive");

	dListDelAllNodes(&head);
	verify(0, dListGetCountRecursive(head), "dListGetCountRecursive");

	return 0;
}
