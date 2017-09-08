/**
* File: circularLinkedList
* ------------------------
* Defines the interface for the circular linked list.
*
* The circular linked list is a dynamic data structure that holds a set of
* int values.  This differs from singly linked list in that the last node
* points to the first node instead of pointing to NULL
*/

#ifndef _circularLinkedList_H
#define _circularLinkedList_H

/**
* Type: Node
* ----------
* Node is simple structure that holds
* a) the data to be stored
* b) link to the next node
* A circular linked list is a sequence of nodes with each node having a reference
* to its following node.  The last node in the list will be NULL.
*/

typedef struct _node {
	int data;
	struct _node *next;
} Node;

/**
* --------------------------------------------------------
* Function : cListAddNodeAtBegin
* Usage    : cListAddNodeAtBegin(Node **headRef, int addData);
* Parameter: headRef is a pointer to list head node.
* Parameter: addData is an int value that needs to be added
*            to the begining of the list.
* Notes    : We pass pointer since adding new node is going to
*            change where the list head pointing to
* --------------------------------------------------------
*/
void cListAddNodeAtBegin(Node **headRef, int addData);

/**
* --------------------------------------------------------
* Function : cListAddNodeAtEnd
* Usage    : cListAddNodeAtEnd(Node **headRef, int addData);
* Parameter: headRef is a pointer to list head node.
* Parameter: addData is an int value that is added to end
* Notes    : We pass pointer since we may end up passing empty list.
* --------------------------------------------------------
*/
void cListAddNodeAtEnd(Node **headRef, int addData);

/**
* --------------------------------------------------------
* Function : cListAddNodeAtPos
* Usage    : cListAddNodeAtPos(Node **headRef, int addData, int pos);
* Parameter: headRef is a pointer to list head node.
* Parameter: addData is an int value that is added to end
* Pos      : position at which data to be added.  Position are
*            zero indexed.
* Notes    : We pass pointer since we may end up passing empty list.
* --------------------------------------------------------
*/
void cListAddNodeAtPos(Node **headRef, int addData, int pos);

/**
* --------------------------------------------------------
* Function : cListGetCountIterative
* Usage    : cListGetCountIterative(Node *head);
* Parameter: headRef is a pointer to list head node.
* Return   : The node count
* Notes    : Iterative based appraoch to find node count
* --------------------------------------------------------
*/
int cListGetCountIterative(Node *head);

/**
* --------------------------------------------------------
* Function : cListGetCountRecursive
* Usage    : cListGetCountRecursive(Node *head);
* Parameter: headRef is a pointer to list head node.
* Return   : The node count
* Notes    : Recursive based appraoch to find node count
* --------------------------------------------------------
*/
int cListGetCountRecursive(Node *head);

/**
* --------------------------------------------------------
* Function : cListDelNodeAtBegin
* Usage    : cListDelNodeAtBegin(Node **headRef);
* Parameter: headRef is a pointer to list head node.
* Notes    : Delete the first Node in the list
* --------------------------------------------------------
*/
int cListDelNodeAtBegin(Node **headRef);

/**
* --------------------------------------------------------
* Function : cListDelNodeAtEnd
* Usage    : cListDelNodeAtEnd(Node **headRef);
* Parameter: headRef is a pointer to list head node.
* Notes    : Delete the end Node in the list
* --------------------------------------------------------
*/
void cListDelNodeAtEnd(Node **headRef);

/**
* --------------------------------------------------------
* Function : cListDelNodeAtPos
* Usage    : cListDelNodeAtPos(Node **headRef, int pos);
* Parameter: headRef is a pointer to list head node.
* Notes    : Delete the node at a posisition pos in the list
* --------------------------------------------------------
*/
void cListDelNodeAtPos(Node **headRef, int pos);

/**
* --------------------------------------------------------
* Function : cListDelAllNodes
* Usage    : cListDelAllNodes(Node **headRef);
* Parameter: headRef is a pointer to list head node.
* Notes    : Trash the list. Remember to set *headRef to 0
* --------------------------------------------------------
*/
void cListDelAllNodes(Node **headRef);

/**
* --------------------------------------------------------
* Function : cListDelAllNodes
* Usage : cListDelAllNodes(Node **headRef);
* Parameter: headRef is a pointer to list head node.
* Notes : Trash the list.Remember to set *headRef to 0
* --------------------------------------------------------
*/
void cListDelRepeatOccurrences(Node **headRef, int data);

/**
* --------------------------------------------------------
* Function : cListDelRepeatOccurrences
* Usage    : cListDelRepeatOccurrences(Node *headRef, int data);
* Parameter: headRef is a pointer to list head node.
* Notes    : List walk through and printing data
* --------------------------------------------------------
*/
void cListTraverse(Node *head);

#endif	//_circularLinkedList_H