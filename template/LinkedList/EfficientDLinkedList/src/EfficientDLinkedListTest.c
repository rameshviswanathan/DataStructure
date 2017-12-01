/* File: doublyLinkedListTest.c
* -----------------------------
* A program to exercise some basic functionality of the doubly linked list.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "EfficientDLinkedList.h"

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
	int count = 0;

	printf("------------ Starting Simple test ------------\n");
	printf("Testing addNodeToListBegin ......\n");
	data = 7;

	dList2AddNodeAtBegin(&head, data);
	++count;
	verify(data, head->data, "dList2AddNodeAtBegin");

	data = 6;
	dList2AddNodeAtBegin(&head, data);
	++count;

	data = 5;
	++count;
	dList2AddNodeAtEnd(&head, data);

	dList2Traverse(head);

	verify(count, dList2GetCountIterative(head), "dList2GetCountIterative");
	verify(count, dList2GetCountRecursive(head), "dList2GetCountRecursive");

	verify(6, dList2DelNodeAtBegin(&head), "dList2DelNodeAtBegin");
	--count;
	verify(count, dList2GetCountIterative(head), "dList2GetCountIterative");
	verify(count, dList2GetCountRecursive(head), "dList2GetCountRecursive");

	dList2AddNodeAtEnd(&head, 1);
	++count;

	dList2AddNodeAtEnd(&head, 2);
	++count;

	dList2AddNodeAtEnd(&head, 3);
	++count;

	verify(count, dList2GetCountIterative(head), "dList2GetCountIterative");
	verify(count, dList2GetCountRecursive(head), "dList2GetCountRecursive");

	dList2Traverse(head);

	data = 4;
	int pos = 3;
	dList2AddNodeAtPos(&head, data, pos);
	++count;

	printf("Traversing after adding newnode at pos: %d\n", pos);
	dList2Traverse(head);

	data = 0;
	pos = 0;
	dList2AddNodeAtPos(&head, data, pos);
	++count;

	printf("Traversing after adding newnode at pos: %d\n", pos);
	dList2Traverse(head);

	dList2AddNodeAtEnd(&head, 5);
	++count;
	verify(count, dList2GetCountIterative(head), "dList2GetCountIterative");

	dList2Traverse(head);

	// Test deleting node
	pos = 2;
	dList2DelNodeAtPos(&head, pos);
	--count;
	verify(count, dList2GetCountIterative(head), "dList2GetCountIterative");
	printf("Traversing after deleting node at pos: %d\n", pos);
	dList2Traverse(head);

	pos = 1;
	dList2DelNodeAtPos(&head, pos);
	--count;
	verify(count, dList2GetCountIterative(head), "dList2GetCountIterative");
	printf("Traversing after deleting node at pos: %d\n", pos);
	dList2Traverse(head);

	pos = 0;
	dList2DelNodeAtPos(&head, pos);
	--count;
	verify(count, dList2GetCountIterative(head), "dList2GetCountIterative");
	printf("Traversing after deleting node at pos: %d\n", pos);
	dList2Traverse(head);

	dList2DelNodeAtEnd(&head);
	--count;
	verify(count, dList2GetCountIterative(head), "dList2GetCountIterative");
	printf("Traversing after deleting node at end\n");
	dList2Traverse(head);

	dList2DelNodeAtBegin(&head);
	--count;
	verify(count, dList2GetCountIterative(head), "dList2GetCountIterative");
	printf("Traversing after deleting node at begin\n");
	dList2Traverse(head);

	// Test all occurrence delete
	int constDataVal = 10;
	int addAtBegin = 1;
	for (int i = 0; i < 5; ++i) {
		if (addAtBegin) {
			dList2AddNodeAtBegin(&head, constDataVal);
			addAtBegin = 0;
		}
		else {
			dList2AddNodeAtEnd(&head, constDataVal);
			addAtBegin = 1;
		}
	}

	dList2Traverse(head);
	dList2DelRepeatOccurrences(&head, constDataVal);
	verify(count, dList2GetCountIterative(head), "dList2GetCountIterative");

	for (int i = 0; i < 5; ++i) {
		dList2AddNodeAtEnd(&head, i);
		++count;
		dList2AddNodeAtEnd(&head, 10);
	}

	dList2Traverse(head);
	dList2DelRepeatOccurrences(&head, constDataVal);
	dList2Traverse(head);
	verify(count, dList2GetCountIterative(head), "dList2GetCountIterative");

	dList2DelAllNodes(&head);
	verify(0, dList2GetCountIterative(head), "dList2GetCountIterative");

	return 0;
}
