/* File: singlyLinkedListTest.c
* -----------------------------
* A program to exercise some basic functionality of the singly linked list.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "singlyLinkedList.h"

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
	int arr[5] = { 1, 2, 3, 4, 5 };

	printf("------------ Starting Simple test ------------\n");
	printf("Testing addNodeToListBegin ......\n");
	data = 7;

	sListAddNodeAtBegin(&head, data);
	verify(data, head->data, "sListAddNodeAtBegin");

	verify(1, sListGetCountIterative(head), "sListGetCountIterative");

	verify(data, sListDelNodeAtBegin(&head), "sListDelNodeAtBegin");
	verify((int)0, (int *)head, "sListDelNodeAtBegin");

	sListAddNodeAtEnd(&head, 1);
	sListAddNodeAtEnd(&head, 2);
	sListAddNodeAtEnd(&head, 3);
	verify(3, sListGetCountIterative(head), "sListGetCountIterative");

	sListAddNodeAtPos(&head, 4, 3);
	sListAddNodeAtPos(&head, 0, 0);
	sListAddNodeAtEnd(&head, 5);
	verify(6, sListGetCountRecursive(head), "sListGetCountRecursive");

	sListTraverse(head);

	// Test deleting node
	sListDelNodeAtPos(&head, 2);
	sListTraverse(head);

	sListDelNodeAtPos(&head, 1);
	sListTraverse(head);

	sListDelNodeAtPos(&head, 0);
	sListTraverse(head);

	sListDelNodeAtEnd(&head);
	sListTraverse(head);

	sListDelNodeAtBegin(&head);
	sListTraverse(head);

	sListDelNodeAtEnd(&head);
	verify(0, sListGetCountRecursive(head), "sListGetCountRecursive");

	// Test all occurrence delete
	int constDataVal = 10;
	for (int i = 0; i < 5; ++i)
		sListAddNodeAtEnd(&head, 10);

	sListTraverse(head);
	sListDelRepeatOccurrences(&head, constDataVal);
	verify(0, sListGetCountRecursive(head), "sListGetCountRecursive");

	for (int i = 0; i < 5; ++i) {
		sListAddNodeAtEnd(&head, i);
		sListAddNodeAtEnd(&head, 10);
	}

	sListTraverse(head);
	sListDelRepeatOccurrences(&head, constDataVal);
	sListTraverse(head);
	verify(5, sListGetCountRecursive(head), "sListGetCountRecursive");

	sListDelAllNodes(&head);
	verify(0, sListGetCountRecursive(head), "sListGetCountRecursive");

	return 0;
}