#ifndef LISTNODE_H
#define LISTNODE_H

#include "event.h"

using namespace std;

//template<class data_t> 
class listNode{
	friend class LinkedList;
	private:
		event* dataPtr;
		listNode* nextPtr;

	public:
		listNode(event* DATAPTR, listNode* nextPtr);	//constructor prototype
		listNode();										//default constructor prototype
		~listNode(){delete(nextPtr);};					//destructor prototype
};

#endif
