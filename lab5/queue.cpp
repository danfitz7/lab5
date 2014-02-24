#include "lab5.h"

#include <stdio.h>
#include <stdlib.h>

#include <queue.h>
#include <process.h>


//allocates memory for a new queue node, initializes that node, and returns a pointer to it
node* makeNode(process* PROCESSPTR, node* nextNodePtr){
	//allocate memory for a new node and set our parent to point to this new leaf
	node* newNodePtr = (node*)malloc(sizeof(node));

	if(newNodePtr){	//if we successfully allocated memory for the node
		//printf("\t\t\tMemory allocated - initializing node\n");
		newNodePtr->nextPtr=nextNodePtr;
		newNodePtr->processPtr=PROCESSPTR;
	}else{
		printf("ERROR: Could not allocate memory for new node!\n");
	}
	return newNodePtr;
}

//inserts the given process (given it's pointer) in the given queue (given a pointer to the pointer to the queues head) and returns a pointer to the inserted node
//insertion is in order of the process's arrival time
node* insert(node** parentPtr, process* newprocessPtr){
	//if(DEBUG){printf("\tInserting process ID %04u\n", newprocessPtr->process_id);}
		
	//check if the queue is empty or the process arrives before the current node's process does 
	//in both of these cases, the node should be inserted between the current node (if if the current is nulL) and it's parent (even if the parent is the head of the queue)
	if((*parentPtr) == NULL || (*parentPtr)->processPtr->arrival_time > newprocessPtr->arrival_time){	
		(*parentPtr)=makeNode(newprocessPtr, (*parentPtr));	//make our parent point instead to the new node, and make the new node point to whatever our parent had been pointing to							
		return (*parentPtr);								//return the value of our parent pointer, which we just set to point to the new node we created
	}else{
		return insert(&((*parentPtr)->nextPtr), newprocessPtr);	//the parent was not NULL and it's process came before the arrival time of the new event, so the new process should go further down the queue		
	}
}

//pops (removes) the head node from the list and returns a pointer to it
process* pop(node** headPtr){
	if(DEBUG){printf("\t\tPopping next node off a queue...\n");}
	
	node* poppedNode = *headPtr;	//get a pointer to the first node on the queue
	if (poppedNode){				//if that node exists
		if(DEBUG){printf("\t\tPopped process %4u off queue\n", poppedNode->processPtr->process_id);}
		*headPtr = poppedNode->nextPtr;	//update the head to point to the next node (or NULL if there was no next node)
	}else{
		if(DEBUG){printf("\tAttempted to pop off an empty queue!\n");}
		return NULL;
	}
	return poppedNode->processPtr;	//return the popped node's data
}

//pushes (appends) a node to the end of the queue
void push(node** headPtr, process* processToAppendPtr){
	node* newNodePtr=makeNode(processToAppendPtr, NULL);	//make our parent point instead to the new node, and make the new node point to whatever our parent had been pointing to
	node** tailNextPtr=getTailNextPtr(headPtr);				//get a pointer to the nextPtr of the tail node of the queue (or just the headPtr if queue is empty)
	(*tailNextPtr)=newNodePtr;								//make the current tail point to the new node
}

//returns a pointer to the nextPtr of the last node in a queue (or a pointer to the headPtr if queue is empty)
node** getTailNextPtr(node** headNodePtr){
	
	if (*headNodePtr){	//if the queue is not empty
		return getTailNextPtr(&((*headNodePtr)->nextPtr));	//return the address (pointer) of the first node's nextPtr member (recursive until the nextPtr is NULL)
	}else{
		return headNodePtr;	//return the pointer to its head
	}
	
	/*node** currentPtr=headNodePtr;					//start with the head node
	while ((*currentPtr) && (*currentPtr)->nextPtr){//while the current node is not NULL (haven't reached the end of the queue) AND it's child is also not NULL
		currentPtr = &((*currentPtr)->nextPtr);		//go to the next node
	}
	return currentPtr;								//return the address of the current node's pointer to the next node (or NULL if the queue was empty)
	*/
}

//helper function - print all events on the given queue
void printQueue(node* nodePtr){
	if (nodePtr){
		printProcess(nodePtr->processPtr);
		printQueue(nodePtr->nextPtr);
	}
}

//helper function - print the specified number of tabs
void printTabs(unsigned int n){
	for (unsigned int i=0;i<n;i++){
		printf("\t");
	}
}

