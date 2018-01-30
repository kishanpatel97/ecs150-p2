#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

struct Node
{
	void *data;
	struct Node *next;
};

struct Node* newNode(void *data)
{
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	if (temp == NULL)
	return temp;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

struct queue {
	struct Node *front;
	struct Node *rear;
};

queue_t queue_create(void)
{
	queue_t myQ = (queue_t)malloc(sizeof(struct queue));
	if (myQ == NULL)
	return myQ;
	myQ->front = myQ->rear = NULL;
	return myQ;
}

int queue_destroy(queue_t queue)
{	
	if (queue == NULL || queue->front != NULL)
	{
	return -1
	}
	else 
	{
	free(queue);
	return 0;
	}
}

int queue_enqueue(queue_t queue, void *data)
{
	struct Node *temp = newNode(data);
	if (temp == NULL || data == NULL || queue == NULL)
	return -1;
	else if (queue->front == NULL)
	queue->front = queue->rear = temp;
	else
	{
	queue->rear->next = temp;
	queue->rear = temp;
	}
	return 0;
}

int queue_dequeue(queue_t queue, void **data)
{
	if (data == NULL || queue == NULL || queue->front == NULL)
	return -1;
	data = &queue->front->data;
	queue->front = queue->front->next;
	if (queue->front == NULL)
	queue->rear = NULL;
	return 0;
}

int queue_delete(queue_t queue, void *data)
{
	/* TODO Phase 1 */
}

int queue_iterate(queue_t queue, queue_func_t func, void *arg, void **data)
{
	/* TODO Phase 1 */
}

int queue_length(queue_t queue)
{
	/* TODO Phase 1 */
}
