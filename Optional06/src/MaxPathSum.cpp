#include "../include/BSTNode.h"
#include <iostream>
#include <algorithm>

#define COUT std::cout
#define ENDL std::endl

void MaxPathFunc( BSTNode<int>* currNode, int& MaxVal, int& MaxValPath ){
	
	// If the node is NULL, set both to 0
    if (currNode == NULL){
		
		MaxVal = 0;
        MaxValPath = 0;
		
		return;
    }
	
	// First, check the left
	int MaxValLeft = 0;
	int MaxValPathLeft = 0;
	
	MaxPathFunc( currNode->left, MaxValLeft, MaxValPathLeft );
	
	// Next, check the right
	int MaxValRight = 0;
	int MaxValPathRight = 0;
	
	MaxPathFunc( currNode->right, MaxValRight, MaxValPathRight );
	
	// Next, obtain the possible path solutions
	int SumAllPaths = currNode->data + MaxValLeft + MaxValRight;
	
	int SumLeftPath = currNode->data + MaxValLeft;
	
	int SumRightPath = currNode->data + MaxValRight;
	
	// Get the max of the paths 
	int MaxValPathLocal = std::max( std::max( SumAllPaths, SumLeftPath ), SumRightPath ); 
	
	// Get the maxValue from Left, right and middle
	int MaxValLocal = std::max( std::max( MaxValLeft, MaxValRight ), currNode->data ); 
	
	// If the Local Value is Greater than the Path Value
	if( MaxValLocal > MaxValPathLocal ){
		
		// Set the Call By Reference Local Value equal to the Local Value 
		MaxVal = MaxValLocal;
		
		// Set the Reference Path to 0 to Prevent Unintentional Additions
		MaxValPath = 0;
		
	}
	else{

		// Set the Call By Reference Local Value equal to the Local Path Value 
		MaxVal = MaxValPathLocal;
		
		// Set the Call By Reference Path Value equal to the Local Path Value 
		MaxValPath = MaxValPathLocal;		
		
	}

}

void test1(){
	
    COUT << "----- TEST 1 -----" << ENDL;
    BSTNode<int> node0(-10);
	BSTNode<int> node1(9);
	BSTNode<int> node2(20);
	node0.left = &node1;
	node0.right = &node2;
	BSTNode<int> node3(15);
	BSTNode<int> node4(7);
	node2.left = &node3;
	node2.right = &node4;	
	
	int MaxVal = 0;
	int MaxValPath = 0;
	
	MaxPathFunc( &node0, MaxVal, MaxValPath );
	
	COUT << "The Maximum Path Sum is " << std::max( MaxVal, MaxValPath ) << ENDL << ENDL;
	
	
}

void test2(){
	
    COUT << "----- TEST 2 -----" << ENDL;
    BSTNode<int> node0(2);
	BSTNode<int> node1(1);
	BSTNode<int> node2(3);
	node0.left = &node1;
	node0.right = &node2;
	
	int MaxVal = 0;
	int MaxValPath = 0;
	
	MaxPathFunc( &node0, MaxVal, MaxValPath );
	
	COUT << "The Maximum Path Sum is " << std::max( MaxVal, MaxValPath ) << ENDL << ENDL;
	
	
}


void test3(){
	
    COUT << "----- TEST 3 -----" << ENDL;
    BSTNode<int> node0(10);
	BSTNode<int> node1(9);
	BSTNode<int> node2(20);
	node0.left = &node1;
	node0.right = &node2;
	BSTNode<int> node3(15);
	BSTNode<int> node4(-7);
	node2.left = &node3;
	node2.right = &node4;	
	
	int MaxVal = 0;
	int MaxValPath = 0;
	
	MaxPathFunc( &node0, MaxVal, MaxValPath );
	
	COUT << "The Maximum Path Sum is " << std::max( MaxVal, MaxValPath ) << ENDL << ENDL;
	
	
}


int main(){
    
	test1();
	
	test2();
	
	test3();
	
	return 0;
}
