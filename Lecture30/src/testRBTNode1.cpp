#include "../include/RBTNode1.h"
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
void inOrder( const RBTNode<T>* x ) { 

	if (x == NULL){
		return; 
	}
	
	// Call left 
	inOrder(x->left); 
	
	// Print values 
	printValues(x);
	
	// Call Right
	inOrder(x->right); 
} 

template< class T >
void preOrder( const RBTNode<T>* x) { 

	if (x == NULL){
		return; 
	}
	
	// Print values 
	printValues(x);
	
	// Call left 
	preOrder(x->left); 
	
	// Call Right
	preOrder(x->right); 
}


template< class T >
void postOrder( const RBTNode<T>* x ) { 

	if (x == NULL){
		return; 
	}
	
	// Call Right
	postOrder(x->right); 
	
	// Call left 
	postOrder(x->left); 
	
	// Print values 
	printValues(x);
	
} 

// Printing Post Order
template< class T >
void levelOrder( const RBTNode< T >* treeRoot ){
	
	// Return if currNode is null 
	if( treeRoot == NULL ){
		return;
	}
	
	// Create a queue of void pointers
	std::queue< void * > levelQueue;

	// Cast the treeRoot to void * and push onto the queue
	levelQueue.push( (void *)treeRoot );
	
	// Just like BFS, iterate until the queue is empty
	while( !levelQueue.empty() ){
		
		// Take the address from the front of the queue and 
		// cast to a RBTNode<T>* and set to a temp value currNode
		RBTNode< T >* currNode = ( RBTNode< T >* )levelQueue.front();
		
		// Remove the element from the front of the queue
		levelQueue.pop();
		
		// Print values 
		printValues(currNode);
		
		if( currNode->left != NULL ){
			levelQueue.push( (void *)(currNode->left) );
		}
		
		if( currNode->right != NULL ){
			levelQueue.push( (void *)(currNode->right) );
		}
	}
}

template< class T >
void printResults( RBTNode<T>* root ){
	
	// Print in-order traversal 
	COUT << "In-order traversal: ";
	inOrder( root );
	COUT << ENDL << ENDL;
	
	// Print pre-order traversal 
	COUT << "Pre-order traversal: ";
	preOrder( root );
	COUT << ENDL << ENDL;
	
	// Print post-order traversal 
	COUT << "Post-order traversal: ";
	postOrder( root );
	COUT << ENDL << ENDL;

	// Print leve;-order traversal 
	COUT << "Level-order traversal: ";
	levelOrder( root );
	COUT << ENDL << ENDL;
	
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
	printResults( root );
	
}