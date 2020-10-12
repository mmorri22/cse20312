#include "../include/BTreeNode4.h"
#include <string>

template< class T >
void printSplitNode( BTreeNode< T >* parent ){
	
	// Print the child nodes to the left 
	if( parent->childPtrs[0] != NULL ){
		COUT << "Left Child Node: " <<  parent->childPtrs[0]->count << " value(s) -> ";
		
		for(unsigned int iter = 0; iter < parent->childPtrs[0]->count; iter++ ){
			
			COUT << parent->childPtrs[0]->values[iter] << " ";
			
		}
		COUT << ENDL;
	}
	
	// Print the parent's values:
	COUT << "New Parent Node: " << parent->count << " value(s) -> ";
	for(unsigned int iter = 0; iter < parent->count; iter++ ){
		
		COUT << parent->values[iter] << " ";
		
	}
	COUT << ENDL;
	
	if( parent->childPtrs[1] != NULL ){
		// Print the child nodes to the right 
		COUT << "Right Child Node: " <<  parent->childPtrs[1]->count << " value(s) -> ";
		
		for(unsigned int iter = 0; iter < parent->childPtrs[1]->count; iter++ ){
			
			COUT << parent->childPtrs[1]->values[iter] << " ";
			
		}
	}
	COUT << ENDL;	
	
	
}

void test1(){
	
	COUT << "--------------------------------" << ENDL;
	COUT << "Test 1 - Odd Degree 3 - int - Insert method test" << ENDL;
	
	// Establish B-Tree Nodes with Maximum Degree of 3
	BTreeNode< int >* bTreeNode1 = new BTreeNode<int>( 3 );
	
	// Values to insert
	
	bTreeNode1->Insert( 7 );
	bTreeNode1->Insert( 11 );
	//bTreeNode1->Insert( 10 );
	
	// Print the Split Node 
	printSplitNode( bTreeNode1 );
	
	COUT << ENDL;
	
}


int main(){
	
	test1();

	return 0;
}