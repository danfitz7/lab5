#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "listNode.h"

//template<class data_t>
class LinkedList{
	private:
		listNode* headNodePtr;
		//listNode<data_t>* tailNodePtr;
	
	public:
		LinkedList();
		LinkedList(event* firstNodeDataPtr);
		~LinkedList();
		
		void print();
		void push(event* dataPtr);
		event* pop();
		void insert(event* dataPtr);
		
	//template<event> class LinkedList;
};

#endif
