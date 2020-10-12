#include "../include/BTree1.h"

#include <string>


int main(){
	
	// Establish a B-Tree Node with Order 3 
	BTree< int > bTree1( 3 );
	
	bTree1.Insert( 7 );
	bTree1.printInOrderTraversal( );
	
	bTree1.Insert( 10 );
	bTree1.printInOrderTraversal( );
	
	bTree1.Insert( 11 );
	bTree1.printInOrderTraversal( );

	/* bTree1.Insert( 6 );
	bTree1.printInOrderTraversal( );

	bTree1.Insert( 12 );
	bTree1.printInOrderTraversal( );

	bTree1.Insert( 13 );
	bTree1.printInOrderTraversal( );
	
	bTree1.Insert( 14 );
	bTree1.printInOrderTraversal( );
	
	bTree1.Insert( 5 );
	bTree1.printInOrderTraversal( ); */
	
	return 0;
	
}