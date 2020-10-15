#include "../include/RBTNode2.h"
#include <iostream>
#include <queue>

#define COUT std::cout
#define ENDL std::endl

template< class T >
void setNode( RBTNode< T >& theNode, COLOR color, RBTNode< T >* parent, 
	RBTNode< T >* left, RBTNode< T >* right){
	
	// Set node1
	theNode.parent = parent;
	theNode.color = color;
	theNode.left = left;
	theNode.right = right;	
}

template< class T >
void printValues( const RBTNode<T>* x ){
	
	// Print values 
	COUT << "{" << x->value;
	
	// Print Color 
	if( x->color == RED ){
		COUT << ", Color: RED} ";
	}
	else{
		COUT << ", Color: BLACK} ";
	}
	
}

template< class T >
void printUncle( const RBTNode<T>* x ) { 

	if (x == NULL){
		COUT << "Cannot print NULL pointer" << ENDL;
		return; 
	}
	
	// Get the uncle
	RBTNode<T>* uncle = x->uncle();
	
	// If the Uncle is NULL, print NULL 
	if( uncle == NULL ){
		COUT << x->value << " has a NULL Uncle" << ENDL;
		return;
	}
	
	// Otherwise, print the Uncle
	COUT << x->value << "'s uncle is: ";
	printValues( uncle );
	COUT << ENDL;
	
} 

// Create the tress found at the end of Lecture 19 - Part 1 - Slide 28
int main(){
	
	RBTNode< int > node1( 15 );
	RBTNode< int > node2( 10 );
	RBTNode< int > node3( 25 );
	RBTNode< int > node4( 4 );
	RBTNode< int > node5( 12 );
	RBTNode< int > node6( 3 );
	RBTNode< int > node7( 5 );
	
	// Set root node as a pointer to node 1
	RBTNode< int >* root = &node1;
	
	// Create a null pointer to pass to functions 
	RBTNode< int >* rbtNULL = NULL;
	
	// Set node1
	setNode( node1, BLACK, rbtNULL, &node2, &node3 );

	// Set node2
	setNode( node2, RED, &node1, &node4, &node5 );

	// Set node3 - Pass null pointers as left and right child
	setNode( node3, BLACK, &node1, rbtNULL, rbtNULL );

	// Set node4 
	setNode( node4, BLACK, &node2, &node6, &node7 );

	// Set node5 - Pass null pointers as left and right child
	setNode( node5, BLACK, &node2, rbtNULL, rbtNULL );

	// Set node6 - Pass null pointers as left and right child
	setNode( node6, RED, &node4, rbtNULL, rbtNULL );
	
	// Set node7 - Pass null pointers as left and right child
	setNode( node7, RED, &node4, rbtNULL, rbtNULL );

	// Print the results 
	printUncle( root );
	printUncle( &node1 );
	printUncle( &node2 );
	printUncle( &node3 );
	printUncle( &node4 );
	printUncle( &node5 );
	printUncle( &node6 );
	printUncle( &node7 );
	
	return 0;
	
}