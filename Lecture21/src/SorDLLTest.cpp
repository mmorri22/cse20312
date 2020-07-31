#include "../include/SorDLList.h"

#include <iostream>

int main(){
	
	SorDLList<int> theList;
	
	theList.Insert( 10 );
	std::cout << theList << std::endl;
	theList.Insert( 22 );
	std::cout << theList << std::endl;
	theList.Insert( 18 );
	std::cout << theList << std::endl;
	theList.Insert( 22 );
	std::cout << theList << std::endl;
	
	return 0;
	
}