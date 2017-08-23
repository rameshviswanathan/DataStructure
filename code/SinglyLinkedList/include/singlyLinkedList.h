/**
* File: singlyLinkedList
* ----------------------
* Defines the interface for the single linked list.
*
* The single linked list is a dynamic data structure that holds a set of
* int values.  This is similar to array expect that the memory for storing
* new data entry is allocated on demand basis.
*/

#ifndef _singlyLinkedList_h
#define _singlyLinkedList_h

#include <stdio.h>	//  this header defines the C99 bool type

/**
* Type: Node
* ----------
* Node is simple structure that holds
* a) the data to be stored
* b) link to the next node
* A singled linked list is a sequence of nodes with each node having a reference
* to its following node.  The last node in the list will be NULL.
*/

typedef struct _node {
	int data;
	struct _node *next;
} Node;

/**
* --------------------------------------------------------
* Function : sListAddNodeAtBegin
* Usage    : sListAddNodeAtBegin(Node **headRef, int addData);
* Parameter: headRef is a pointer to list head node.
* Parameter: addData is an int value that needs to be added
*            to the begining of the list.
* Notes    : We pass pointer since adding new node is going to
*            change where the list head pointing to
* --------------------------------------------------------
*/
void sListAddNodeAtBegin(Node **headRef, int addData);

/**
* --------------------------------------------------------
* Function : sListAddNodeAtEnd
* Usage    : sListAddNodeAtEnd(Node **headRef, int addData);
* Parameter: headRef is a pointer to list head node.
* Parameter: addData is an int value that is added to end
* Notes    : We pass pointer since we may end up passing empty list.
* --------------------------------------------------------
*/
void sListAddNodeAtEnd(Node **headRef, int addData);

/**
* --------------------------------------------------------
* Function : sListAddNodeAtPos
* Usage    : sListAddNodeAtPos(Node **headRef, int addData, int pos);
* Parameter: headRef is a pointer to list head node.
* Parameter: addData is an int value that is added to end
* Pos      : position at which data to be added.  Position are
*            zero indexed.
* Notes    : We pass pointer since we may end up passing empty list.
* --------------------------------------------------------
*/
void sListAddNodeAtPos(Node **headRef, int addData, int pos);

/**
* --------------------------------------------------------
* Function : sListGetCountIterative
* Usage    : sListGetCountIterative(Node *head);
* Parameter: headRef is a pointer to list head node.
* Return   : The node count
* Notes    : Iterative based appraoch to find node count
* --------------------------------------------------------
*/
int sListGetCountIterative(Node *head);

/**
* --------------------------------------------------------
* Function : sListGetCountRecursive
* Usage    : sListGetCountRecursive(Node *head);
* Parameter: headRef is a pointer to list head node.
* Return   : The node count
* Notes    : Recursive based appraoch to find node count
* --------------------------------------------------------
*/
int sListGetCountRecursive(Node *head);

/**
* --------------------------------------------------------
* Function : sListDelNodeAtBegin
* Usage    : sListDelNodeAtBegin(Node **headRef);
* Parameter: headRef is a pointer to list head node.
* Notes    : Delete the first Node in the list
* --------------------------------------------------------
*/
int sListDelNodeAtBegin(Node **headRef);

/**
* --------------------------------------------------------
* Function : sListDelNodeAtEnd
* Usage    : sListDelNodeAtEnd(Node **headRef);
* Parameter: headRef is a pointer to list head node.
* Notes    : Delete the end Node in the list
* --------------------------------------------------------
*/
void sListDelNodeAtEnd(Node **headRef);

/**
* --------------------------------------------------------
* Function : sListDelNodeAtPos
* Usage    : sListDelNodeAtPos(Node **headRef, int pos);
* Parameter: headRef is a pointer to list head node.
* Notes    : Delete the node at a posisition pos in the list
* --------------------------------------------------------
*/
void sListDelNodeAtPos(Node **headRef, int pos);

/**
* --------------------------------------------------------
* Function : sListDelAllNodes
* Usage    : sListDelAllNodes(Node **headRef);
* Parameter: headRef is a pointer to list head node.
* Notes    : Trash the list. Remember to set *headRef to 0
* --------------------------------------------------------
*/
void sListDelAllNodes(Node **headRef);

/**
* --------------------------------------------------------
* Function : sListDelAllNodes
* Usage : sListDelAllNodes(Node **headRef);
* Parameter: headRef is a pointer to list head node.
* Notes : Trash the list.Remember to set *headRef to 0
* --------------------------------------------------------
*/
void sListDelRepeatOccurrences(Node **headRef, int data);

/**
* --------------------------------------------------------
* Function : sListDelRepeatOccurrences
* Usage    : sListDelRepeatOccurrences(Node *headRef, int data);
* Parameter: headRef is a pointer to list head node.
* Notes    : List walk through and printing data
* --------------------------------------------------------
*/
void sListTraverse(Node *head);

#endif	//_singlyLinkedList_h