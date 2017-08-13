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
	verify(data, head->data, "AddNodeToListBegin");


	return 0;
}