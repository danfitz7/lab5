#include "LinkedList.h"
#include "listNode.h"
#include <iostream>
using namespace std;

//printing
template<class data_t> void LinkedList<data_t>::print(){
	/*if (dataPtr){
		cout<<"LinkedList:"<<endl;
	}
	if (nextPtr){
		nextPtr->print();
	}*/
}

//push an item to the end of the list (FIFO/FCFS Queue)
template<class data_t> void LinkedList<data_t>::push(data_t* dataPtr){
	listNode* newHeadNodePtr = listNode(dataPtr, headNodePtr);
	headNodePtr=newHeadNodePtr;
}

//pop an item off the from of the list
template<class data_t> data_t* LinkedList<data_t>::pop(){
	if (headNodePtr){
		listnode<data_t> oldHeadPtr = headNodePtr;
		data_t oldHeadDataPtr = oldHeadPtr->dataPtr;
		headNodePtr=headNodePtr->nextPtr;
		delete(oldHeadPtr);
		return oldHeadDataPtr;
	}else{
		return NULL;
	}
}

//insert an item in the list
template<class data_t> void LinkedList<data_t>::insert(data_t* dataPtr){
	listnode* curNodePtr=headNodePtr;
	listnode* prevNodePtr=NULL;
	while(curNodePtr){
		if (*dataPtr < *(curNodePtr->dataPtr)){
			break;
		}
		prevNodePtr=curNodePtr;
		curNodePtr=curNodePtr->nextPtr;
	}
	listnode* newNodePtr= new listnode(dataPtr, curNodePtr);
	prevNodePtr=newNodePtr;
	
	
	//does this work?
	listNode** parentNodePtr;
	for (parentNodePtr = &headNodePtr; *parentNodePtr != NULL && (*parentNodePtr)->data != oldvalue; parentNodePtr = &(parentNodePtr->next));
	listnode* newNodePtr = new listnode(dataPtr, (*parentNodePtr));
	*parentNodePtr=newNodePtr;
}
