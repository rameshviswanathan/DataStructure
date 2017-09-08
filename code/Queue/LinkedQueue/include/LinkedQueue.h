/**
* File: LinkedQueue
* -----------------
* Defines the queue data structure implemented using linked list.
*
* Queue is a simple data structure that supports two operations
* enqueue and deque operations.
*/

#ifndef _LINKED_QUEUE_H_
#define _LINKED_QUEUE_H_

#define TRUE		1
#define FALSE		0

/**
* --------------------------------------------------------
* Function : aQueue_CreateQueue
* Usage    : aQueue_CreateQueue(unsigned int capacity);
* Notes    : generates the Queue storage object.  This object
*            should be passed around between calls.
* Returns  : queue Object
* --------------------------------------------------------
*/
void *aQueue_CreateQueue();

/**
* --------------------------------------------------------
* Function : aQueue_IsEmpty
* Usage    : aQueue_IsEmpty();
* Parameter: Queue object
* Returns  : 1 if it is empty and 0 otherwise
* Notes    : Query to check if the Queue is full
* --------------------------------------------------------
*/
int aQueue_IsEmpty(void *q);

/**
* --------------------------------------------------------
* Function : aQueue_Enqueue
* Usage    : aQueue_Enqueue(void * q, int item);
* Parameter: Queue object
* Parameter: item to be Pushed to rear of the Queue
* Notes    : If Queue is full, nothing get Pushed
* --------------------------------------------------------
*/
void aQueue_Enqueue(void *q, int item);

/**
* --------------------------------------------------------
* Function : aQueue_Pop
* Usage    : aQueue_Pop(void *q);
* Parameter: Queue object
* Returns  : returns item from Queue front
* Notes    : If Queue is empty, returns INT_MIN to indicate
*            failure
* --------------------------------------------------------
*/
int aQueue_Deque(void *q);

/**
* --------------------------------------------------------
* Function : aQueue_DestroyQueue
* Usage    : aQueue_DestroyQueue(void *q);
* Parameter: Queue object to be freed
* Notes    : generates the Queue storage object.  This object
*            should be passed around between calls.
* --------------------------------------------------------
*/
void aQueue_DestroyQueue(void *q);

#endif	// _LINKED_QUEUE_H_
