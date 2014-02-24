#include "lab5.h"
#include "packet.h"
#include "event.h"
#include <iostream>
using namespace std;

//constructor from initial word and lineNumber number
event::event(unsigned int TIME, Packet* PACKETPTR):
	time(TIME),
	packetPtr(PACKETPTR)
{}

//default constructor
//event::event(){
//	time=0;
//	packetPtr=NULL;
//}

//destructor
event::~event(){
	delete(packetPtr);
}

//print the words in the tree recursively
void event::print(){
	cout<<"EVENT:"<<endl;
}
