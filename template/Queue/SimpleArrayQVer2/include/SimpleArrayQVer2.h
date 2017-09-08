/**
* File: ArrayQueue
* ----------------
* Defines the queue data structure implemented using arrays.
*
* Queue is a simple data structure that supports two operations
* enqueue and deque operations.
*/

#ifndef _SIMPLE_ARRAY_QVER2_H_
#define _SIMPLE_ARRAY_QVER2_H_

#define TRUE		1
#define FALSE		0

/**
* --------------------------------------------------------
* Function : aQueue2_CreateQueue
* Usage    : aQueue2_CreateQueue(unsigned int capacity, int resizeable);
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
void *aQueue2_CreateQueue(unsigned int capacity, int resizeable);

/**
* --------------------------------------------------------
* Function : aQueue2_IsFull
* Usage    : aQueue2_IsFull(void *q);
* Parameter: Queue object
* Returns  : 0 if it is not full and 1 for full
* Notes    : Query to check if the Queue is full
* --------------------------------------------------------
*/
int aQueue2_IsFull(void *q);

/**
* --------------------------------------------------------
* Function : aQueue2_IsEmpty
* Usage    : aQueue2_IsEmpty(void *q);
* Parameter: Queue object
* Returns  : 1 if it is empty and 0 otherwise
* Notes    : Query to check if the Queue is full
* --------------------------------------------------------
*/
int aQueue2_IsEmpty(void *q);

/**
* --------------------------------------------------------
* Function : aQueue2_Enqueue
* Usage    : aQueue2_Enqueue(void * q, int item);
* Parameter: Queue object
* Parameter: item to be Pushed to rear of the Queue
* Notes    : If Queue is full, nothing get Pushed
* --------------------------------------------------------
*/
void aQueue2_Enqueue(void *q, int item);

/**
* --------------------------------------------------------
* Function : aQueue2_Pop
* Usage    : aQueue2_Pop(void *q);
* Parameter: Queue object
* Returns  : returns item from Queue front
* Notes    : If Queue is empty, returns INT_MIN to indicate
*            failure
* --------------------------------------------------------
*/
int aQueue2_Deque(void *q);

/**
* --------------------------------------------------------
* Function : aQueue2_DestroyQueue
* Usage    : aQueue2_DestroyQueue(void *q);
* Parameter: Queue object to be freed
* Notes    : generates the Queue storage object.  This object
*            should be passed around between calls.
* --------------------------------------------------------
*/
void aQueue2_DestroyQueue(void *q);

#endif	// _SIMPLE_ARRAY_QVER2_H_