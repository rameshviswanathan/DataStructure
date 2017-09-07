/**
* File: SimpleArrayQVer2.c
* ------------------------
*/

#include "SimpleArrayQVer2.h"

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
	int resizebale;
	int cur_size;
} Queue;

/*---------------------------------------------------------------------------*/

void *aQueue2_CreateQueue(unsigned int capacity, int resizable) {
	assert(capacity > 0);
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	assert(queue != NULL);

	queue->array = (int*)malloc(sizeof(int) * capacity);
	assert(queue->array != NULL);
	queue->front = 0;
	queue->rear = capacity - 1;
	queue->capacity = capacity;
	queue->resizebale = resizable;
	queue->cur_size = 0;
	return queue;
}

/*---------------------------------------------------------------------------*/

int aQueue2_IsFull(void *q) {
	assert(q != NULL);

	Queue *queue = (Queue *)q;
	if (queue->resizebale)
		return FALSE;

	return queue->cur_size == queue->capacity;
}

/*---------------------------------------------------------------------------*/

int aQueue2_IsEmpty(void *q) {
	assert(q != NULL);

	Queue *queue = (Queue *)q;
	return queue->cur_size == 0;
}

/*---------------------------------------------------------------------------*/
static void aQueue2_Resize(void *q) {
	Queue *queue = (Queue *)q;

	queue->array = realloc(queue->array, sizeof(int) * (queue->capacity) * 2);
	assert(queue->array != NULL);

	if (queue->front < queue->rear) {
		for (int i = 0; i < queue->front; ++i)
			queue->array[queue->capacity + i] = queue->array[i];
		queue->rear += queue->front;
	}
	queue->capacity *= 2;
}

/*---------------------------------------------------------------------------*/

void aQueue2_Enqueue(void *q, int item) {
	assert(q != NULL);

	Queue *queue = (Queue *)q;
	if (queue->cur_size == queue->capacity)
		if (queue->resizebale)
			aQueue2_Resize(queue);
		else
			return;

	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	++queue->cur_size;
}

/*---------------------------------------------------------------------------*/

int aQueue2_Deque(void *q) {
	int ret = INT_MIN;
	assert(q != NULL);

	if (aQueue2_IsEmpty(q) != TRUE) {
		Queue *queue = (Queue *)q;
		ret = queue->array[queue->front];
		queue->front = (queue->front + 1) % queue->capacity;
		--queue->cur_size;
	}

	return ret;
}

/*---------------------------------------------------------------------------*/

void aQueue2_DestroyQueue(void *q) {
	assert(q != NULL);

	Queue *queue = (Queue *)q;
	free(queue->array);
	queue->array = NULL;
	queue->front = queue->rear = -1;
	free(queue);
}

/*---------------------------------------------------------------------------*/
