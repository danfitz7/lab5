#include "LinkedList.h"
#include "listNode.h"
#include "event.h"
#include <iostream>
using namespace std;

//template<class data_t>
LinkedList::LinkedList():
	headNodePtr(NULL)
{}

//template<class data_t>
LinkedList::LinkedList(event* firstNodeDataPtr):
	headNodePtr(new listNode(firstNodeDataPtr, NULL))
{}

//template<class data_t>
LinkedList::~LinkedList(){
	delete(headNodePtr);
}


//prints a list in order
//template<class data_t>
void LinkedList::print(){
	cout<<"EVENT LIST: "<<endl;
	listNode* curNodePtr=headNodePtr;
	while(curNodePtr){
		curNodePtr->dataPtr->print();
		curNodePtr=curNodePtr->nextPtr;
	}
}

//push an item to the end of the list (FIFO/FCFS Queue)
//template<class data_t>
void LinkedList::push(event* dataPtr){
	headNodePtr = new listNode(dataPtr, headNodePtr);	//make a new node and have it point to the old head	and use the new node as the new head
}

//pop an item off the from of the list
//template<class data_t>
event* LinkedList::pop(){
	if (headNodePtr){								//if the list is not empty
		event* oldHeadDataPtr = headNodePtr->dataPtr;//keep track of the data of the old head node that we will return
		listNode* oldHeadPtr = headNodePtr;			//keep track of the current head node that we are popping off
		headNodePtr=oldHeadPtr->nextPtr;			//off with the old head, in with it's child
		//delete(oldHeadPtr);						//delete the old head
		return oldHeadDataPtr;						//return the old head's data
	}else{											//if the list is empty, return none
		cout<<"ERROR: Popping from empty list!"<<endl;
		return NULL;
	}
}

//insert an item in the list in order
//template<class data_t>
void LinkedList::insert(event* newDataPtr){
//	cout<<endl<<"Inserting Node "<<newDataPtr->time<<endl;
	listNode** curNodeFromPtrPtr = &headNodePtr;	//address of the pointer that was used to access the current node (usually a pointer to the nextPtr of the previous node)
	listNode* curNodePtr=NULL;						//pointer to the current node
	while (*curNodeFromPtrPtr){						//while the current node exists
		//if the current node exists, check if the new node should be before it
		if (*newDataPtr < *((*curNodeFromPtrPtr)->dataPtr)){
//			cout<<"\tInserting "<<newDataPtr->time<<" before " <<(*curNodeFromPtrPtr)->dataPtr->time<<"."<<endl;
			break;
		}
		curNodePtr = (*curNodeFromPtrPtr)->nextPtr;		//update the current node to the next of the current node
		curNodeFromPtrPtr = &((*curNodeFromPtrPtr)->nextPtr);	//update the pointer to the current node to the address of it's own next node
	}
	
	//insert the new node between the previous and next
	*curNodeFromPtrPtr = new listNode(newDataPtr, curNodePtr);
	
	
	/*
	//using double pointers for the special case where we need to insert at the beginning of the list and change the headNodePtr itself.
	//otherwise this is the same as keeping track of the current node and it's parent, and inserting the new node between them.
	cout<<endl<<"inserting event "<<newDataPtr->time<<endl;
	listNode** curNodePtr = &headNodePtr;	//pointer to the node that should come after this new node
	listNode** prevNodePtr= &headNodePtr;	//pointer to the node that should come before this new node (came before that pointed to by curNodePtr)
	while(*curNodePtr){						//if there is a current node
		cout<<"comparing to current node "<<(*curNodePtr)->dataPtr->time<<endl;
		
		//if the new node comes before the current node, break the loop
		if (*newDataPtr < *((*curNodePtr)->dataPtr)){
			cout<<"it was less than the current node"<<endl;
			break;
		}else{
			cout<<"Not less than - moving on...."<<endl;
		}
		prevNodePtr=curNodePtr;					//update the previous node to the current node for the next loop
		curNodePtr = &((*curNodePtr)->nextPtr);	//update the current node to it's own child (which may be NULL)
	}
	cout<<"ended loop."<<endl;
	
	//if we reached the end of the list, set the last node to the new node. otherwise, set the current node to the new node. Set the new node to the next of the current node
	((*curNodePtr)? *prevNodePtr : *curNodePtr) = new listNode(newDataPtr, *curNodePtr);
	*/
	
	
	/*listNode* newNodePtr = new listNode(newDataPtr, *curNodePtr);
	if (! *curNodePtr){	//if we reached the end of the list
		*curNodePtr=newNodePtr;	//make the last node point to the new node
	}else{
		*prevNodePtr = newNodePtr;
	}												
	*/

}
