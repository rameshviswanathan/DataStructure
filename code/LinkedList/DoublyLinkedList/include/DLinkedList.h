/**
* File: DoublyLinkedList
* ----------------------
* Defines the interface for the doubly linked list.
*
* The doubly linked list is a dynamic data structure that holds a set of
* int values.  This is similar to array expect that the memory for storing
* new data entry is allocated on demand basis. It differs from single linked
* list in that every node maintains pointers to both previous and next nodes.
* It is easy to traverse both the direction as well to delete any given node
* without traversing.  All the necessary information is embedded in each node.
*/

#ifndef _DoublyLinkedList_h
#define _DoublyLinkedList_h

#include <stdio.h>	//  this header defines the C99 bool type

/**
* Type: Node
* ----------
* Node is simple structure that holds
* a) the data to be stored
* b) link to the previous node
* c) link to the next node
*
* A doubly linked list is a sequence of nodes with each node having a reference
* to both its preceding and following node.  The first node will have previous pointer
* to be NULL while the last node in the list have the next pointer to be NULL.
*/

typedef struct _node {
	int data;
	struct _node *prev;
	struct _node *next;
} Node;

/**
* --------------------------------------------------------
* Function : dListAddNodeAtBegin
* Usage    : dListAddNodeAtBegin(Node **headRef, int addData);
* Parameter: headRef is a pointer to list head node.
* Parameter: addData is an int value that needs to be added
*            to the begining of the list.
* Notes    : We pass pointer since adding new node is going to
*            change where the list head pointing to
* --------------------------------------------------------
*/
void dListAddNodeAtBegin(Node **headRef, int addData);

/**
* --------------------------------------------------------
* Function : dListAddNodeAtEnd
* Usage    : dListAddNodeAtEnd(Node **headRef, int addData);
* Parameter: headRef is a pointer to list head node.
* Parameter: addData is an int value that is added to end
* Notes    : We pass pointer since we may end up passing empty list.
* --------------------------------------------------------
*/
void dListAddNodeAtEnd(Node **headRef, int addData);

/**
* --------------------------------------------------------
* Function : dListAddNodeAtPos
* Usage    : dListAddNodeAtPos(Node **headRef, int addData, int pos);
* Parameter: headRef is a pointer to list head node.
* Parameter: addData is an int value that is added to end
* Pos      : position at which data to be added.  Position are
*            zero indexed.
* Notes    : We pass pointer since we may end up passing empty list.
* --------------------------------------------------------
*/
void dListAddNodeAtPos(Node **headRef, int addData, int pos);

/**
* --------------------------------------------------------
* Function : dListGetCountIterative
* Usage    : dListGetCountIterative(Node *head);
* Parameter: headRef is a pointer to list head node.
* Return   : The node count
* Notes    : Iterative based appraoch to find node count
* --------------------------------------------------------
*/
int dListGetCountIterative(Node *head);

/**
* --------------------------------------------------------
* Function : dListGetCountRecursive
* Usage    : dListGetCountRecursive(Node *head);
* Parameter: headRef is a pointer to list head node.
* Return   : The node count
* Notes    : Recursive based appraoch to find node count
* --------------------------------------------------------
*/
int dListGetCountRecursive(Node *head);

/**
* --------------------------------------------------------
* Function : dListDelNodeAtBegin
* Usage    : dListDelNodeAtBegin(Node **headRef);
* Parameter: headRef is a pointer to list head node.
* Notes    : Delete the first Node in the list
* --------------------------------------------------------
*/
int dListDelNodeAtBegin(Node **headRef);

/**
* --------------------------------------------------------
* Function : dListDelNodeAtEnd
* Usage    : dListDelNodeAtEnd(Node **headRef);
* Parameter: headRef is a pointer to list head node.
* Notes    : Delete the end Node in the list
* --------------------------------------------------------
*/
void dListDelNodeAtEnd(Node **headRef);

/**
* --------------------------------------------------------
* Function : dListDelNodeAtPos
* Usage    : dListDelNodeAtPos(Node **headRef, int pos);
* Parameter: headRef is a pointer to list head node.
* Notes    : Delete the node at a posisition pos in the list
* --------------------------------------------------------
*/
void dListDelNodeAtPos(Node **headRef, int pos);

/**
* --------------------------------------------------------
* Function : dListDelAllNodes
* Usage    : dListDelAllNodes(Node **headRef);
* Parameter: headRef is a pointer to list head node.
* Notes    : Trash the list. Remember to set *headRef to 0
* --------------------------------------------------------
*/
void dListDelAllNodes(Node **headRef);

/**
* --------------------------------------------------------
* Function : dListDelAllNodes
* Usage : dListDelAllNodes(Node **headRef);
* Parameter: headRef is a pointer to list head node.
* Notes : Trash the list.Remember to set *headRef to 0
* --------------------------------------------------------
*/
void dListDelRepeatOccurrences(Node **headRef, int data);

/**
* --------------------------------------------------------
* Function : dListDelRepeatOccurrences
* Usage    : dListDelRepeatOccurrences(Node *headRef, int data);
* Parameter: headRef is a pointer to list head node.
* Notes    : List walk through and printing data
* --------------------------------------------------------
*/
void dListTraverse(Node *head);

#endif	//_DoublyLinkedList_h