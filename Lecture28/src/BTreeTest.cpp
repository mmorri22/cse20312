#include "../include/BTree.h"

template< class T >
void insertAndPrint( BTree<T>& theTree, T value ){
	
	COUT << "Inserting " << value << ": ";
	theTree.insert( value );
	
	theTree.printInOrder( std::cout );
}

int main(){
	
	unsigned int minDegree = 2;
	
	BTree<int> theTree(minDegree);
	
	insertAndPrint( theTree, 15 );
	insertAndPrint( theTree, 10 );
	insertAndPrint( theTree, 4 );
	insertAndPrint( theTree, 8 );
	insertAndPrint( theTree, 21 );
	insertAndPrint( theTree, 18 );
	insertAndPrint( theTree, 12 );
	insertAndPrint( theTree, 19 );
	insertAndPrint( theTree, 20 );
	insertAndPrint( theTree, 17 );
	insertAndPrint( theTree, 3 );
	insertAndPrint( theTree, 1 );	
	
	return 0;
}
