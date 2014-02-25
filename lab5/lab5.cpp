/*
CS 2302 LAB5
Daniel Fitzgerald
2/24/14
Simulating Packet Transmissions in C++
*/

#include "lab5.h"

//used for input and string manipulation
#include <iostream>
/*#include <string>
#include <iomanip>
#include <cctype>
#include <sstream>*/

//used for data structure
#include "LinkedList.h"
#include "event.h"

using namespace std;

//function prototypes
void testLinkedLists();

/*
Assume you have two sending Host source nodes (S1 and S2) sending packets to one receiver Host node 
(R1). Two intermediate mule nodes (M1 and M2) employ FCFS packet queues. Both source hosts transmit 
packets to intermediate node M1. M1 transmits packets to M2. M2 transmits packets to the final destination R1. 
*/
int main(int argc, char* argv[]){
	if(DEBUG){cout<<endl<<endl<<"LAB5"<<endl;}
	
	//ensure there is the correct number of command line arguments (the first is the name of our program, the second should be the number of arguments to come from a file)
	if (argc!=1){
		cout<<"ERROR: Proper usage has no command line arguments."<<endl;
		return 0;
	}
	
	LinkedList eventQ();	//make an empty event queue
	
	testLinkedLists();
	
	cout<<"\nDONE."<<endl<<endl;
}

void testLinkedLists(){
	LinkedList testQ = LinkedList();
	
	testQ.push(new event(0,NULL));
	testQ.push(new event(1,NULL));
	testQ.push(new event(3,NULL));
	testQ.push(new event(4,NULL));
	testQ.push(new event(2,NULL));
	testQ.push(new event(5,NULL));
	
	cout<<"Pushed events."<<endl;
	testQ.print();
	cout<<"Popping..."<<endl;
	
	for (size_t i=0;i<=5;i++){
		testQ.pop()->print();
	}
	
	cout<<"new list"<<endl;
	testQ.print();
	
	cout<<"Inserting events..."<<endl;
	testQ.insert(new event(1,NULL));
	testQ.print();
	testQ.insert(new event(1,NULL));
	testQ.print();
	testQ.insert(new event(3,NULL));
	testQ.print();
	testQ.insert(new event(4,NULL));
	testQ.print();
	testQ.insert(new event(4,NULL));
	testQ.print();
	testQ.insert(new event(2,NULL));
	testQ.print();
	testQ.insert(new event(5,NULL));
	testQ.print();
	testQ.insert(new event(0,NULL));
	
	cout<<"Inserted events."<<endl;
	testQ.print();
}

