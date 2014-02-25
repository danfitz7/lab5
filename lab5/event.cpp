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

//print the words in the tree recursively
void event::print(){
	cout<<"EVENT:"<<endl;
}
