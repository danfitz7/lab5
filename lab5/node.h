#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//A Tree Node has a word, a vector of occurrences of that word, and pointers to left and right nodes.
class Node {

private:
	string word;
	vector<int> lineNumbers;
	Node* left;
	Node* right;

public:
	Node(string newWord, int line);		//constructor prototype
	Node();								//default constructor prototype
	~Node();							//destructor prototype
	
	void insert(string word, int line);
	int print();
};

#endif
