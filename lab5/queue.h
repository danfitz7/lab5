#ifndef QUEUE_H
#define QUEUE_H

#include <process.h>

//basic node of a queue of processes
typedef struct node_t{
	struct node_t* nextPtr;
	process* processPtr;
}node;

//function prototypes
node* makeNode(process* processPtr, node* nextNodePtr);
node* insert(node** parentPtr, process* newProcessPtr);
void push(node** parentPtr, process* newProcessPtr);
process* pop(node** parentPtr);
void printTabs(unsigned int n);
void printQueue(node* headPtr);
node** getTailNextPtr(node** headPtr);
#endif
