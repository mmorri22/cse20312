#include "../include/BST.h"
#include <iostream>
#include <algorithm>

#define COUT std::cout
#define ENDL std::endl


bool checkSubTree( BSTNode<int>* leftTree, BSTNode<int>* rightTree ){
	
	// For safety, we always check NULL cases first 
	
	if( leftTree == NULL && rightTree == NULL ){
		return true;
	}
	
	else if( leftTree == NULL && rightTree != NULL ){
		return false;
	}
	
	else if( rightTree == NULL && leftTree != NULL ){
		return false;
	}
	
	bool middle = leftTree->data == rightTree->data;
	
	bool left = checkSubTree( leftTree->left, rightTree->left );

	bool right = checkSubTree( leftTree->right, rightTree->right );
	
	return left && middle && right;
	
}


void runSubTree( BST<int>& tree1, BST<int>& tree2 ){
	
	COUT << "Tree 1:" << ENDL;
	COUT << tree1 << ENDL << ENDL;
	
	COUT << "Tree 2:" << ENDL;
	COUT << tree2 << ENDL << ENDL;
	
	// Get the root of the right tree
	BSTNode<int>* rightTreePtr = tree2.getRoot();
	
	// Get the sub-tree root of the left tree
	BSTNode<int>* subTreeRoot = tree1.getNodeAtValue( rightTreePtr->data );
	
	if( subTreeRoot == NULL ){
		
		COUT << rightTreePtr->data << " not in tree, there not a valid subtree" << ENDL;
	}
	else{
	
		COUT << "Tree 2 is ";
		
		if( !checkSubTree( subTreeRoot, rightTreePtr ) ){
			
			COUT << "not ";
			
		}
		
		COUT << "a valid subtree of Tree 1" << ENDL;
	}
		
}


void test1(){
	
	COUT << "Test 1 --------------------" << ENDL;
	
	BST<int> tree1;
	BST<int> tree2;
	
	tree1.Insert( 6 );
	tree1.Insert( 8 );
	
	tree1.Insert( 4 );
	tree2.Insert( 4 );
	
	tree1.Insert( 1 );
	tree2.Insert( 1 );
	
	tree1.Insert( 5 );
	tree2.Insert( 5 );
	
	runSubTree( tree1, tree2 );	
	
	COUT << ENDL;
}


void test2(){
	
	COUT << "Test 2 --------------------" << ENDL;
	
	BST<int> tree1;
	BST<int> tree2;
	
	tree1.Insert( 3 );
	tree1.Insert( 8 );
	
	tree1.Insert( 4 );
	tree2.Insert( 4 );
	
	tree1.Insert( 1 );
	tree2.Insert( 1 );
	
	tree1.Insert( 5 );
	tree2.Insert( 5 );
	
	tree1.Insert( 0 );
	
	runSubTree( tree1, tree2 );	
	
	COUT << ENDL;
}


void test3(){
	
	COUT << "Test 3 --------------------" << ENDL;
	
	BST<int> tree1;
	BST<int> tree2;
	
	tree1.Insert( 10 );		tree1.Insert( 15 );
	tree1.Insert( 12 );		tree1.Insert( 7 );
	tree1.Insert( 30 );		tree1.Insert( 3 );
	tree1.Insert( 8 );		tree1.Insert( 20 );	
	tree1.Insert( 22 );		tree1.Insert( 35 );
	tree1.Insert( 1 );		tree1.Insert( 31 );
	
	tree2.Insert( 15 );		tree2.Insert( 12 );	
	tree2.Insert( 30 );		tree2.Insert( 20 );	
	tree2.Insert( 22 );		tree2.Insert( 35 );
	tree2.Insert( 31 );
	
	runSubTree( tree1, tree2 );	
	
	COUT << ENDL;
}


int main(){
    
	test1();
	
	test2();
	
	test3();

	return 0;
}
