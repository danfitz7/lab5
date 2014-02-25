#ifndef LISTNODE_H
#define LISTNODE_H

using namespace std;

template<class data_t> class listNode{
	private:
		data_t* dataPtr;
		listNode<data_t>* nextPtr;

	public:
		listNode(data_t* DATAPTR, listNode* nextPtr);	//constructor prototype
		listNode();										//default constructor prototype
		~listNode();									//destructor prototype
};

#endif
