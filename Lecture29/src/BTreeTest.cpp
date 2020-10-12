#include "../include/BTree.h"

int main(){
	
	unsigned int numVals = 2;
	
	BTree<int> theTree(numVals);
	
	// Insertion as shown in Lecture 25 - Videos 4 and 5
	theTree.insert(15);
	theTree.insert(10);
	theTree.printInOrder( std::cout );
	//theTree.search(15);
	theTree.insert(4);
	theTree.printInOrder( std::cout );
	theTree.insert(8);
	theTree.printInOrder( std::cout );

	//theTree.search(10);
	//theTree.search(15);	
	//theTree.search(4);

	
/*	theTree.insert(21);
	theTree.insert(8);
	theTree.insert(18);
	theTree.insert(12);
	theTree.insert(19);
	theTree.insert(20); */
	
	return 0;
	
}