#include "../include/BST.h"
#include <iostream>

#define COUT std::cout
#define ENDL std::endl


int main(){
    
	BST<int> theTree;
	
	theTree.Insert( 10 );		theTree.Insert( 15 );
	theTree.Insert( 12 );		theTree.Insert( 7 );
	theTree.Insert( 31 );		theTree.Insert( 3 );
	theTree.Insert( 8 );		theTree.Insert( 20 );	
	theTree.Insert( 22 );		theTree.Insert( 35 );
	theTree.Insert( 1 );		theTree.Insert( 30 );
	
	COUT << theTree << ENDL;
	
	for( unsigned int iter = 1; iter <= 12; iter++ ){
		
		COUT << "The " << iter << "-smallest is: ";
		
		COUT << theTree.kthSmallest(iter) << ENDL;
	}

	return 0;
}
