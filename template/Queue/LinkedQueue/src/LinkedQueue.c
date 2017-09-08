/**
* File: LinkedQueue.c
* -------------------
*/

#include "LinkedQueue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>


#define NOT_YET_IMPLEMENTED printf("%s() not yet implemented!!!\n", __FUNCTION__); exit(1)	

/**
* Type: Node
* -----------
* Node strucure holds
* a) data to be stored in the queue
* b) pointer to next element in the queue
*/

typedef struct _node {
	int data;
	struct _node *next;
} Node;

/**
* Type: Queue
* -----------
* Queue strucure holds
* a) front pointer of the queue
* b) rear pointer of the queue
*/

typedef struct _Queue {
	Node *front;
	Node *rear;
} Queue;

/*---------------------------------------------------------------------------*/

static Node *aQueue_AllocateNewNode(int data) {
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/

void *aQueue_CreateQueue() {
	NOT_YET_IMPLEMENTED;
}

/*---------------------------------------------------------------------------*/

int aQueue_IsEmpty(void *q) {
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
