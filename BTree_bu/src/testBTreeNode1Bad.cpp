#include "../include/BTreeNode1Bad.h"

#include <iostream>
#include <string>

#define COUT std::cout
#define ENDL std::endl


int main(){
	
	// Establish a B-Tree Node with Maximum Degree of 3
	BTreeNode< int > bTree1( 3 );
	
	// Test Copy Constructor
	BTreeNode< int > bTree2( bTree1 );
	
	// Establish a B-Tree Node with Maximum Degree of 5
	BTreeNode< std::string > bTree3( 5 );
	
	// Test Assignment Operator 
	BTreeNode< std::string > bTree4 = bTree3;
	
	// Test Pointer Assignment Operator 
	BTreeNode< std::string >* nodePtr = &bTree3;
	
	// Test print out results 
	COUT << "bTree1 maxDegree = " << bTree1.maxDegree << ENDL;
	COUT << "bTree2 maxDegree = " << bTree2.maxDegree << ENDL;
	COUT << "bTree3 maxDegree = " << bTree3.maxDegree << ENDL;
	COUT << "bTree4 maxDegree = " << bTree4.maxDegree << ENDL;
	COUT << "nodePtr maxDegree = " << nodePtr->maxDegree << ENDL << ENDL;
	
	// Create a new BTreeNode and set bTree3's first pointer to bTree6
	BTreeNode< std::string > bTree6( 5 );
	bTree3.childPtrs[0] = &bTree6;
	
	// Print both the bTree3's child pointer...
	COUT << "bTree3 childPtrs[0] maxDegree = " << bTree3.childPtrs[0]->maxDegree << ENDL;
	
	// ... as well as the nodePtr's child pointer. Should both print 7
	COUT << "nodePtr childPtrs[0] maxDegree = " << nodePtr->childPtrs[0]->maxDegree << ENDL << ENDL;
	
	delete nodePtr;
	
	return 0;
}
