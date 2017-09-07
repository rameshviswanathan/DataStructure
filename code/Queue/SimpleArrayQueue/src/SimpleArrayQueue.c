/**
* File: SimpleArrayQueue.c
* ------------------------
*/

#include "SimpleArrayQueue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>


#define NOT_YET_IMPLEMENTED printf("%s() not yet implemented!!!\n", __FUNCTION__); exit(1)	

/**
* Type: Queue
* -----------
* Queue strucure holds
* a) Queue capacity represents the maximum Queue size
* b) top which tracks the current entry of the Queue
* c) array to hold all Queue data elements
*/

typedef struct _Queue {
	unsigned int capacity;
	int front;
	int rear;
	int *array;
} Queue;

/*---------------------------------------------------------------------------*/

void *aQueue_CreateQueue(unsigned int capacity) {
	assert(capacity > 0);
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	assert(queue != NULL);

	queue->array = (int*)malloc(sizeof(int) * capacity);
	assert(queue->array != NULL);
	queue->front = -1;
	queue->rear = -1;
	queue->capacity = capacity;
	return queue;
}

/*---------------------------------------------------------------------------*/

int aQueue_IsFull(void *q) {
	assert(q != NULL);

	Queue *queue = (Queue *)q;
	if ((queue->rear + 1) % queue->capacity == queue->front)
		return TRUE;

	return FALSE;
}

/*---------------------------------------------------------------------------*/

int aQueue_IsEmpty(void *q) {
	assert(q != NULL);
	
	Queue *queue = (Queue *)q;
	if (queue->front == queue->rear) {
		queue->front = -1;
		queue->rear = -1;
		return TRUE;
	}
	return FALSE;
}

/*---------------------------------------------------------------------------*/

void aQueue_Enqueue(void *q, int item) {
	assert(q != NULL);

	Queue *queue = (Queue *)q;
	if (aQueue_IsFull(q))
		return;

	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;

	if (queue->front == -1)
		queue->front = 0;
}

/*---------------------------------------------------------------------------*/

int aQueue_Deque(void *q) {
	int ret = INT_MIN;
	assert(q != NULL);

	if (aQueue_IsEmpty(q) != TRUE) {
		Queue *queue = (Queue *)q;
		ret = queue->array[queue->front];
		queue->front = (queue->front + 1) % queue->capacity;
	}

	return ret;
}

/*---------------------------------------------------------------------------*/

void aQueue_DestroyQueue(void *q) {
	assert(q != NULL);

	Queue *queue = (Queue *)q;
	free(queue->array);
	queue->array = NULL;
	queue->front = queue->rear = -1;
	free(queue);
}

/*---------------------------------------------------------------------------*/
