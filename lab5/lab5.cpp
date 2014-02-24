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
#include "linkedList.h"
#include "event.h"

using namespace std;

//function prototypes


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
	
	linkedList<event> eventQ();	//make an empty event queue
	
	
	cout<<"\nDONE."<<endl<<endl;
}
