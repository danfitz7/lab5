#include "lab5.h"
#import "listNode.h"
#include <iostream>
using namespace std;

//template<class data_t>
listNode::listNode(event* DATAPTR, listNode* NEXTPTR):
	dataPtr(DATAPTR),
	nextPtr(NEXTPTR)
{}

//default constructor
//template<class data_t>
listNode::listNode():
	dataPtr(NULL),
	nextPtr(NULL)
{}

/*
//destructor
template<class data_t> listNode<data_t>::~listNode(){
	//delete(word);
	delete(nextPtr);
}
*/
