#include "../include/BSTNode.h"
#include <iostream>
#include <algorithm>

#define COUT std::cout
#define ENDL std::endl

bool ValidBST( BSTNode<int>* currNode ){
	
	if( currNode == NULL ){
		
		return true;
	}
	
	bool leftCheck = false;
	bool rightCheck = false;
	
	// First, check the left subtree. A NULL subtree is valid
	if( currNode->left == NULL ){
		
		leftCheck = true;
	}
	// Check if a valid left child's data is greater than the current Node's data
	else if( currNode->left != NULL && currNode->left->data > currNode->data ){

		leftCheck = false;
	}
	// Otherwise, recursive check the left subtree
	else if( currNode->left != NULL && currNode->left->data <= currNode->data ){
		
		leftCheck = ValidBST( currNode->left );
	}
	
	
	// Next, check the right subtree. A NULL subtree is valid
	if( currNode->right == NULL ){
		
		rightCheck = true;
	}
	// Check if a valid right child's data is less than the current Node's data
	else if( currNode->right != NULL && currNode->right->data < currNode->data ){

		rightCheck =  false;
	}
	// Otherwise, recursive check the left subtree
	else if( currNode->right != NULL && currNode->right->data >= currNode->data ){
		
		rightCheck = ValidBST( currNode->right );
	}

	return leftCheck && rightCheck;

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
	
	// Pass the address of node0 to pass a pointer to the node
	COUT << "The tree is ";
	
	if( !ValidBST( &node0 ) ){
		
		COUT << "not ";
	}
	
	COUT << "a valid Binary Search Tree" << ENDL << ENDL;
	
	
}


void test2(){
	
    COUT << "----- TEST 2 -----" << ENDL;
    BSTNode<int> node0(10);
	BSTNode<int> node1(7);
	BSTNode<int> node2(12);
	node0.left = &node1;
	node0.right = &node2;
	
	BSTNode<int> node3(3);
	BSTNode<int> node4(8);
	node1.left = &node3;
	node1.right = &node4;
	
	BSTNode<int> node5(11);
	BSTNode<int> node6(15);
	node2.left = &node5;
	node2.right = &node6;	
	
	// Pass the address of node0 to pass a pointer to the node
	COUT << "The tree is ";
	
	if( !ValidBST( &node0 ) ){
		
		COUT << "not ";
	}
	
	COUT << "a valid Binary Search Tree" << ENDL << ENDL;
	
	
}


void test3(){
	
    COUT << "----- TEST 3 -----" << ENDL;
    BSTNode<int> node0;
	
	// Pass the address of node0 to pass a pointer to the node
	COUT << "The tree is ";
	
	if( !ValidBST( &node0 ) ){
		
		COUT << "not ";
	}
	
	COUT << "a valid Binary Search Tree" << ENDL << ENDL;
	
	
}


void test4(){
	
    COUT << "----- TEST 4 -----" << ENDL;
    BSTNode<int> node0(10);
	BSTNode<int> node1(7);
	BSTNode<int> node2(12);
	node0.left = &node1;
	node0.right = &node2;
	
	BSTNode<int> node3(3);
	BSTNode<int> node4(8);
	node1.left = &node3;
	node1.right = &node4;
	
	BSTNode<int> node5(15);
	BSTNode<int> node6(11);
	node2.left = &node5;
	node2.right = &node6;	
	
	// Pass the address of node0 to pass a pointer to the node
	COUT << "The tree is ";
	
	if( !ValidBST( &node0 ) ){
		
		COUT << "not ";
	}
	
	COUT << "a valid Binary Search Tree" << ENDL << ENDL;
	
	
}



int main(){
    
	test1();
	
	test2();
	
	test3();
	
	test4();
	
	return 0;
}
