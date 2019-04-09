// ADT Queue
#include <stdio.h>
#include "ADT_queue.h"

typedef struct student {
	int id;
	int score;
} STD;

#define STD_N 20

int main() {

	int i;
	STD* std_ptr;

	// Queue Creation
	QUEUE* queue;
	queue = create_queue();

	// memory allocation
	// DO allocate STD of number of STD_N
	STD* c[STD_N];
	for (i = 0; i<STD_N; i++)
		c[i] = (STD*)malloc(sizeof(STD));


	// Prepare data
	for (i = 0; i<STD_N; i++) {
		c[i]->id = i;
		c[i]->score = i; // no meaning
	}

	// Data Insertion into Queue
	for (i = 0; i<STD_N; i++) {
		if (enqueue(queue, c[i]))
			printf("Enqueue: %d\n", c[i]->id);
		else {
			printf("Enqueue failed\n");
			return -1;
		}
	}

	// Data Extraction from Queue
	while (queue->count != 0) {
		std_ptr = (STD*)dequeue(queue);
		printf("Dequeue: %d\n", std_ptr->id);
	}

	// Re-insertion
	for (i = 0; i<STD_N; i++) {
		if (enqueue(queue, c[i]))
			printf("Enqueue: %d\n", c[i]->id);
		else {
			printf("Enqueue failed\n");
			return -1;
		}
	}

	// destroy all queue and data
	destroy_queue(queue);

	return 0;
}