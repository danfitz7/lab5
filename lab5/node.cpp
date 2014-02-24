#include "lab5.h"
#include "node.h"

#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <iomanip>

#include "prog4.h"

//constructor from initial word and lineNumber number
Node::Node(string newWord, int lineNumber){
	word = newWord;
	lineNumbers.push_back(lineNumber);
	left = NULL;
	right = NULL;
}

//default constructor
Node::Node(){
	word="";
	//lineNumbers = new vector<int>;
	left=NULL;
	right=NULL;
}

//destructor
Node::~Node(){
	//delete(word);
	lineNumbers.clear();
	delete(left);
	delete(right);
}

//print the words in the tree recursively
int Node::print(){
	//if(DEBUG){cout<<"Printing Node..."<<endl;}
	
	int leftNode = 0, rightNode = 0;
	
	//print left side (lower)
	if (left){
		leftNode = left->print();
	}
	
	//print this node
	cout << "\"" << word << "\""; //prints word
	for (size_t i=24; i>word.length() + 2;i-=8) //done to properly space columns, adds in appropriate number of tabs depending on the length of the word
		cout << "\t";
	cout << "|" << lineNumbers.size() << "\t" << "|" << lineNumbers[0]; //prints count and first line number
	size_t count = lineNumbers.size();
	int j = 1;
	for(size_t i=1;i<count;i++){ //prints out all line number
		if (lineNumbers[i - 1] != lineNumbers[i]) //prevents repeat of lines
		{
			if (j % 10 == 0) cout << endl << "\t\t\t|\t|"; //done to properly space line numbers
			else cout << ", ";
			cout << lineNumbers[i];
			j++;
		}
	}
	cout<<endl;
	
	//print right side (higher)
	if(right){
		rightNode = right->print();
	}
	return 1 + leftNode + rightNode;
}


/*insert the given word and corresponding lineNumber number in to the tree
if the word is the same as this node, add it's lineNumber number to this node's numbers
otherwise find what branch (left or right) the word belongs on
if the branch exists, insert the word there (recursive)
if the branch does not exist, make a new leaf node for the word.
*/
void Node::insert(string insertedWord, int lineNumber){
		
	signed char comparison = (signed char)word.compare(insertedWord);
	if (comparison == 0){	//same word - increment this node
//		if(DEBUG){cout<<"\t'"<<insertedWord<<"' is a duplicate of this node - adding it's lineNumber number"<<endl;}
		lineNumbers.push_back(lineNumber);
		
	//different word - traverse one of the branches of this tree
	}else{
		
		//if this node is uninitialized
		if (lineNumbers.size()==0){
//			if(DEBUG){cout<<"Initializing this empty tree with "<<insertedWord<<" from line "<<lineNumber<<endl;}
			word=insertedWord;					//make ourselves match the new word
			lineNumbers.push_back(lineNumber);	//add the (only) line number
		
		//this node was initialized with a word and at-least one occurrence
		}else{
//			if(DEBUG){cout<<"This node "<<word<<" has "<<lineNumbers.size()<<" occurrences"<<endl;}
		
			//decide which branch to traverse (left, right) based on comparison
			Node** nextBranchPtrPtr=(comparison>0)? &left: &right;
			
			if (*nextBranchPtrPtr){	//if the branch exists
//				if(DEBUG){cout<<"Recursing on one of our branches..."<<endl;}
				(*nextBranchPtrPtr)->insert(insertedWord, lineNumber);	//recurs down the tree
			}else{	//if the branch doesn't exist
//				if(DEBUG){cout<<"Making a new leaf node here..."<<endl;}
				Node* newNodePtr = new Node(insertedWord, lineNumber);	//make a new node
				*nextBranchPtrPtr=newNodePtr;							//point our branch to it
			}
		}
	}
} //end insert function

