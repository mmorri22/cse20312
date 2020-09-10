#include <iostream>
#include "../include/SLList.h"

#define COUT std::cout 
#define ENDL std::endl

int main() {
	
	// Initial List
	SLList< int > list1;
	list1.Insert( 1 ); list1.Insert( 2 ); 
	list1.Insert( 3 ); list1.Insert( 4 );
	
	// Use the SLList copy constructor
	SLList< int > list2( list1 );
	list2.Insert( 5 );
	
	// Print the initial lists 
	COUT << list1 << ENDL;
	COUT << list2 << ENDL;
	
	// Reorder the lists 
	list1.reorderList();
	COUT << "Re-order - list1 result: " << list1 << ENDL;
	
	list2.reorderList();
	COUT << "Re-order - list2 result: " << list2 << ENDL;
	
	return 0;
}
