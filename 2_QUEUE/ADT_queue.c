#include "ADT_queue.h"

QUEUE*
create_queue() {
	QUEUE* queue;
	queue = (QUEUE*)malloc(sizeof(QUEUE));
	if (queue) {
		queue->front = NULL;
		queue->rear = NULL;
		queue->count = 0;
		return queue;
	}
	else {
		return NULL;
	}
}

int
enqueue(QUEUE* queue, void* in) {
	QUEUE_NODE* new_node;
	new_node = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
	if (new_node == NULL)
		return 0;
	new_node->data_ptr = in;
	new_node->next = NULL;
	if (queue->count == 0) {
		queue->front = new_node;
		(queue->count)++;
		queue->rear = new_node;
	}
	else {
		queue->rear->next = new_node;
		(queue->count)++;
		queue->rear = new_node;
	}
	return 1;
}

void* dequeue(QUEUE* queue) {
	if (queue->count == 0) return NULL;
	void* item_ptr = queue->front->data_ptr;
	QUEUE_NODE* deleted_node;
	deleted_node = queue->front;
	if (queue->count == 1) {
		queue->front = NULL;
		queue->rear = NULL;
	}
	else {
		queue->front = queue->front->next;
	}
	free(deleted_node);
	(queue->count)--;
	return item_ptr;
}

void* queue_hook_front(QUEUE* queue) {
	if (queue->count == 0) return NULL;
	else return queue->front->data_ptr;
}

void* queue_hook_rear(QUEUE* queue) {
	if (queue->count == 0) return NULL;
	else return queue->rear->data_ptr;
}

void destroy_queue(QUEUE* queue) {
	if (queue != NULL) {
		int a = 0;
		while (queue->count != 0) {
			free(queue->front->data_ptr);
			dequeue(queue);
			printf("%d-th node is deleted\n", a);
			a++;
		}
	}
}