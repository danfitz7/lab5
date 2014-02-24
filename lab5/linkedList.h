#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;

template<class data_t> class linkedList{
	private:
		data_t* dataPtr;
		linkedList<data_t>* nextPtr;

	public:
		linkedList(data_t* DATAPTR, linkedList* nextPtr);	//constructor prototype
		linkedList();										//default constructor prototype
		~linkedList();										//destructor prototype
		
		void insert(data_t data);
		void print();
};

#endif
