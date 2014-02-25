#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "listNode.h"

template<class data_t> class LinkedList{
	private:
		listNode<data_t>* headNodePtr;
		listNode<data_t>* tailNodePtr;
	
	public:
		void print();
		void push(data_t* dataPtr);
		data_t* pop();
		void insert(data_t* dataPtr);
};

#endif
