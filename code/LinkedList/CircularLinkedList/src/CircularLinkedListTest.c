/* File: circularLinkedListTest.c
* -------------------------------
* A program to exercise some basic functionality of the circular linked list.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "circularLinkedList.h"

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

	cListAddNodeAtBegin(&head, data);
	verify(data, head->data, "cListAddNodeAtBegin");

	verify(1, cListGetCountIterative(head), "cListGetCountIterative");

	verify(data, cListDelNodeAtBegin(&head), "cListDelNodeAtBegin");
	verify((int)0, (int)(int *)head, "cListDelNodeAtBegin");

	cListAddNodeAtEnd(&head, 1);
	cListAddNodeAtEnd(&head, 2);
	cListAddNodeAtEnd(&head, 3);
	verify(3, cListGetCountIterative(head), "cListGetCountIterative");

	cListAddNodeAtPos(&head, 4, 3);
	cListAddNodeAtPos(&head, 0, 0);
	cListAddNodeAtEnd(&head, 5);
	verify(6, cListGetCountRecursive(head), "cListGetCountRecursive");
	cListTraverse(head);

	// Test deleting node
	int pos = 2;
	cListDelNodeAtPos(&head, pos);
	printf("After deleting data pos=%d\n", pos);
	cListTraverse(head);

	pos = 1;
	cListDelNodeAtPos(&head, pos);
	printf("After deleting data pos=%d\n", pos);
	cListTraverse(head);

	pos = 0;
	cListDelNodeAtEnd(&head);
	printf("After deleting Last node\n");
	cListTraverse(head);

	cListDelNodeAtBegin(&head);
	printf("After deleting beginning node\n");
	cListTraverse(head);

	cListDelNodeAtEnd(&head);
	printf("After deleting Last node\n");
	cListTraverse(head);
	verify(1, cListGetCountRecursive(head), "cListGetCountRecursive");

	cListDelNodeAtEnd(&head);

	// Test all occurrence delete
	int constDataVal = 10;
	for (int i = 0; i < 5; ++i)
		cListAddNodeAtEnd(&head, 10);

	cListTraverse(head);
	cListDelRepeatOccurrences(&head, constDataVal);
	verify(0, cListGetCountRecursive(head), "cListGetCountRecursive");

	for (int i = 0; i < 5; ++i) {
		cListAddNodeAtEnd(&head, i);
		cListAddNodeAtEnd(&head, 10);
	}

	cListTraverse(head);
	cListDelRepeatOccurrences(&head, constDataVal);
	cListTraverse(head);
	verify(5, cListGetCountRecursive(head), "cListGetCountRecursive");

	cListDelAllNodes(&head);
	verify(0, cListGetCountRecursive(head), "cListGetCountRecursive");

	return 0;
}
