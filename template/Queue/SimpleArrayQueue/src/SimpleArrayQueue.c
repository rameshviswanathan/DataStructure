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
	int resizebale;
} Queue;

/*---------------------------------------------------------------------------*/

void *aQueue_CreateQueue(unsigned int capacity, int resizable) {
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/

int aQueue_IsFull(void *q) {
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/

int aQueue_IsEmpty(void *q) {
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/
static void aQueue_Resize(void *q) {
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/

void aQueue_Enqueue(void *q, int item) {
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/

int aQueue_Deque(void *q) {
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/

void aQueue_DestroyQueue(void *q) {
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/
