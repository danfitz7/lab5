//constructor from initial word and lineNumber number

#include "packet.h"
#include "lab5.h"
#include <iostream>
using namespace std;

Packet::Packet(unsigned int SENTTIME){
	sentTime=SENTTIME;
	arrivalTime=0;
}

//print the words in the tree recursively
void Packet::print(){
	cout<<"PACKET"<<endl;
}
