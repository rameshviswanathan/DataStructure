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
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/

int aQueue2_IsFull(void *q) {
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/

int aQueue2_IsEmpty(void *q) {
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/
static void aQueue2_Resize(void *q) {
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/

void aQueue2_Enqueue(void *q, int item) {
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/

int aQueue2_Deque(void *q) {
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/

void aQueue2_DestroyQueue(void *q) {
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/
