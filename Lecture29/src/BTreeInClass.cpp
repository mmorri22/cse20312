
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
	BTree<std::string> inClass(4);
	
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
    inClass.traverse(); 
    std::cout << std::endl; 
	
	// The function calling your code here
	// Uncomment the next line, which will be your call 
	inClass.printFoundNodes("struggle");
	inClass.printFoundNodes("struggle bus");
	inClass.printFoundNodes("aardvark");
	inClass.printFoundNodes("structuralism");
	inClass.printFoundNodes("structuralize");
	inClass.printFoundNodes("structuralized");
	inClass.printFoundNodes("structures");
	inClass.printFoundNodes("zebra");

	return 0;
}
