/**
* File: ArrayQueue
* ----------------
* Defines the queue data structure implemented using arrays.
*
* Queue is a simple data structure that supports two operations
* enqueue and deque operations.
*/

#ifndef _ARRAY_QUEUE_H
#define _ARRAY_QUEUE_H

#define TRUE		1
#define FALSE		0

/**
* --------------------------------------------------------
* Function : aQueue_CreateQueue
* Usage    : aQueue_CreateQueue(unsigned int capacity);
* Parameter: Queue capacity entry with which the internal
*            Queue will be created.
* Parameter: resizable if set, will resize the internal storage
*            when the storage is full. Otherwise, it is
*            a queue with fixed size.
* Notes    : generates the Queue storage object.  This object
*            should be passed around between calls.
* Returns  : queue Object
* --------------------------------------------------------
*/
void *aQueue_CreateQueue(unsigned int capacity, int resizeable);

/**
* --------------------------------------------------------
* Function : aQueue_IsFull
* Usage    : aQueue_IsFull();
* Parameter: Queue object
* Returns  : 0 if it is not full and 1 for full
* Notes    : Query to check if the Queue is full
* --------------------------------------------------------
*/
int aQueue_IsFull(void *q);

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

#endif	// _ARRAY_QUEUE_H