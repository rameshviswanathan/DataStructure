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
	Node *newNode = (Node *)malloc(sizeof(Node));
	assert(newNode != NULL);

	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

/*---------------------------------------------------------------------------*/

void *aQueue_CreateQueue() {
	Queue *q = (Queue *)malloc(sizeof(Queue));
	assert(q != NULL);

	q->front = NULL;
	q->rear = NULL;

	return q;
}

/*---------------------------------------------------------------------------*/

int aQueue_IsEmpty(void *q) {
	assert(q != NULL);

	Queue *queue = (Queue *)q;
	return queue->front == NULL;
}

/*---------------------------------------------------------------------------*/

void aQueue_Enqueue(void *q, int item) {
	assert(q != NULL);

	Queue *queue = (Queue *)q;

	// Allocate new node
	Node *newNode = aQueue_AllocateNewNode(item);

	if (queue->rear != NULL) {
		queue->rear->next = newNode;
		queue->rear = newNode;
	}
	else {
		queue->rear = queue->front = newNode;
	}
}

/*---------------------------------------------------------------------------*/

int aQueue_Deque(void *q) {
	int ret = INT_MIN;
	assert(q != NULL);

	if (aQueue_IsEmpty(q) != TRUE) {
		Queue *queue = (Queue *)q;
		Node *removeNode = queue->front;
		queue->front = queue->front->next;

		if (queue->front == NULL)
			queue->rear = NULL;

		ret = removeNode->data;
		free(removeNode);
	}
	return ret;

}

/*---------------------------------------------------------------------------*/

void aQueue_DestroyQueue(void *q) {
	assert(q != NULL);

	Queue *queue = (Queue *)q;
	while (!aQueue_IsEmpty(q)) {
		aQueue_Deque(q);
	}
}

/*---------------------------------------------------------------------------*/
