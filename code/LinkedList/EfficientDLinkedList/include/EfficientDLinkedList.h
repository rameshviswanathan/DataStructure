/**
* File: EfficientDLinkedList
* ----------------------
* Defines the interface for the doubly linked list.
*
* The doubly linked list is a dynamic data structure that holds a set of
* int values.  This is similar to array expect that the memory for storing
* new data entry is allocated on demand basis. This implemnetation differs
* from two pointer based Doubly Linked List in the sense that it uses 
* single pointer and use XOR logic to figure out the next/previous node in
* the list.
*/

#ifndef _EfficientDLinkedList_h
#define _EfficientDLinkedList_h

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
	struct _node *pDiff;
} Node;

/**
* --------------------------------------------------------
* Function : dList2AddNodeAtBegin
* Usage    : dList2AddNodeAtBegin(Node **headRef, int addData);
* Parameter: headRef is a pointer to list head node.
* Parameter: addData is an int value that needs to be added
*            to the begining of the list.
* Notes    : We pass pointer since adding new node is going to
*            change where the list head pointing to
* --------------------------------------------------------
*/
void dList2AddNodeAtBegin(Node **headRef, int addData);

/**
* --------------------------------------------------------
* Function : dList2AddNodeAtEnd
* Usage    : dList2AddNodeAtEnd(Node **headRef, int addData);
* Parameter: headRef is a pointer to list head node.
* Parameter: addData is an int value that is added to end
* Notes    : We pass pointer since we may end up passing empty list.
* --------------------------------------------------------
*/
void dList2AddNodeAtEnd(Node **headRef, int addData);

/**
* --------------------------------------------------------
* Function : dList2AddNodeAtPos
* Usage    : dList2AddNodeAtPos(Node **headRef, int addData, int pos);
* Parameter: headRef is a pointer to list head node.
* Parameter: addData is an int value that is added to end
* Pos      : position at which data to be added.  Position are
*            zero indexed.
* Notes    : We pass pointer since we may end up passing empty list.
* --------------------------------------------------------
*/
void dList2AddNodeAtPos(Node **headRef, int addData, int pos);

/**
* --------------------------------------------------------
* Function : dList2GetCountIterative
* Usage    : dList2GetCountIterative(Node *head);
* Parameter: headRef is a pointer to list head node.
* Return   : The node count
* Notes    : Iterative based appraoch to find node count
* --------------------------------------------------------
*/
int dList2GetCountIterative(Node *head);

/**
* --------------------------------------------------------
* Function : dList2GetCountRecursive
* Usage    : dList2GetCountRecursive(Node *head);
* Parameter: headRef is a pointer to list head node.
* Return   : The node count
* Notes    : Recursive based appraoch to find node count
* --------------------------------------------------------
*/
int dList2GetCountRecursive(Node *head);

/**
* --------------------------------------------------------
* Function : dList2DelNodeAtBegin
* Usage    : dList2DelNodeAtBegin(Node **headRef);
* Parameter: headRef is a pointer to list head node.
* Notes    : Delete the first Node in the list
* --------------------------------------------------------
*/
int dList2DelNodeAtBegin(Node **headRef);

/**
* --------------------------------------------------------
* Function : dList2DelNodeAtEnd
* Usage    : dList2DelNodeAtEnd(Node **headRef);
* Parameter: headRef is a pointer to list head node.
* Notes    : Delete the end Node in the list
* --------------------------------------------------------
*/
int dList2DelNodeAtEnd(Node **headRef);

/**
* --------------------------------------------------------
* Function : dList2DelNodeAtPos
* Usage    : dList2DelNodeAtPos(Node **headRef, int pos);
* Parameter: headRef is a pointer to list head node.
* Notes    : Delete the node at a posisition pos in the list
* --------------------------------------------------------
*/
void dList2DelNodeAtPos(Node **headRef, int pos);

/**
* --------------------------------------------------------
* Function : dList2DelAllNodes
* Usage    : dList2DelAllNodes(Node **headRef);
* Parameter: headRef is a pointer to list head node.
* Notes    : Trash the list. Remember to set *headRef to 0
* --------------------------------------------------------
*/
void dList2DelAllNodes(Node **headRef);

/**
* --------------------------------------------------------
* Function : dList2DelAllNodes
* Usage : dList2DelAllNodes(Node **headRef);
* Parameter: headRef is a pointer to list head node.
* Notes : Trash the list.Remember to set *headRef to 0
* --------------------------------------------------------
*/
void dList2DelRepeatOccurrences(Node **headRef, int data);

/**
* --------------------------------------------------------
* Function : dList2DelRepeatOccurrences
* Usage    : dList2DelRepeatOccurrences(Node *headRef, int data);
* Parameter: headRef is a pointer to list head node.
* Notes    : List walk through and printing data
* --------------------------------------------------------
*/
void dList2Traverse(Node *head);

#endif	//_EfficientDLinkedList_h