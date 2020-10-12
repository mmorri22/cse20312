#include "../include/BTree.h"
#include <string>

/********************************************
* Function Name  : main
* Pre-conditions : int argc, char** argv
* Post-conditions: int
*  
* This is the main driver function for the program
********************************************/
int main(){

	// Initial test code
	BTree<std::string> inClass(2);
	
	inClass.insert("structuralism");
	inClass.insert("structuralist");
	inClass.insert("structuralize");
	inClass.insert("structuralized");
	inClass.insert("structurally");
	inClass.insert("structure");
	inClass.insert("structured");
	inClass.insert("structureless");
	inClass.insert("structures");
	inClass.insert("strudel");
	inClass.insert("struggle");
	inClass.insert("struggle bus");
	
	// Initial print out!
    std::cout << "Traversal of tree constructed is\n"; 
    inClass.printInOrder( std::cout ); 
    std::cout << std::endl; 
	
	std::cout << "Finding 'structure'" << std::endl;
	// The function calling your code here
	// Uncomment the next line, which will be your call 
	inClass.printFoundNodes("struggle");

	return 0;
}
