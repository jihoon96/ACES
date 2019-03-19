#ifndef _ADT_STACK_H_
#define _ADT_STACK_H_

#include <stdlib.h>
#include <stdbool.h>

// Stack Node
typedef struct node {
	void* 		 dataPtr;
	struct node* link;
} STACK_NODE;

// Stack ADT
typedef struct {
	int 		count;
	STACK_NODE* top;
} STACK;

// Interface;
STACK* createStack();
bool pushStack(STACK* stack, void* dataInPtr);
void* popStack(STACK* stack);
void* stackTop(STACK* stack);
bool emptyStack(STACK* stack);
bool fullStack(STACK* stack);
int stackCount(STACK* stack);
STACK* destroyStack(STACK* stack);

#endif // end of _ADT_STACK_H_
