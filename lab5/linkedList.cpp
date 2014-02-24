#include "lab5.h"
#import "linkedList.h"
#include <iostream>
using namespace std;

template<class data_t> linkedList<data_t>::linkedList(data_t* DATAPTR, linkedList* NEXTPTR):
	dataPtr(DATAPTR),
	nextPtr(NEXTPTR)
{}

//default constructor
template<class data_t> linkedList<data_t>::linkedList():
	dataPtr(NULL),
	nextPtr(NULL)
{}

//destructor
template<class data_t> linkedList<data_t>::~linkedList(){
	//delete(word);
	delete(dataPtr);
	delete(nextPtr);
}

template<class data_t> void linkedList<data_t>::print(){
	cout<<"linkedList:"<<endl;
}
