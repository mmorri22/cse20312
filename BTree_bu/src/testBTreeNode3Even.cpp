#include "../include/BTreeNode3.h"
#include <string>

template< class T >
void printSplitNode( BTreeNode< T >* parent ){
	
	// Print the child nodes to the left 
	COUT << "Left Child Node: " <<  parent->childPtrs[0]->count << " value(s) -> ";
	
	for(unsigned int iter = 0; iter < parent->childPtrs[0]->count; iter++ ){
		
		COUT << parent->childPtrs[0]->values[iter] << " ";
		
	}
	COUT << ENDL;
	
	// Print the parent's values:
	COUT << "New Parent Node: " << parent->count << " value(s) -> ";
	for(unsigned int iter = 0; iter < parent->count; iter++ ){
		
		COUT << parent->values[iter] << " ";
		
	}
	COUT << ENDL;
	
	// Print the child nodes to the right 
	COUT << "Right Child Node: " <<  parent->childPtrs[1]->count << " value(s) -> ";
	
	for(unsigned int iter = 0; iter < parent->childPtrs[1]->count; iter++ ){
		
		COUT << parent->childPtrs[1]->values[iter] << " ";
		
	}
	COUT << ENDL;	
	
	
}

void test1(){
	
	COUT << "--------------------------------" << ENDL;
	COUT << "Test 1 - Even Max Degree 4 - int - insert value max" << ENDL;
	
	// Establish B-Tree Nodes with Maximum Degree of 4
	BTreeNode< int >* bTreeNode1 = new BTreeNode<int>( 4 );
	
	// Set the first value as 7 and the second value as 10
	bTreeNode1->values[0] = 7;	bTreeNode1->values[1] = 10;		bTreeNode1->values[2] = 11;
	bTreeNode1->count = 3;
	
	// Find the location where 11 should be placed
	int newValue = 12;
	COUT << "bTreeNode1 12 should be at " << bTreeNode1->findValue( newValue ) << ENDL;
	
	// Create a Parent Node for Node 1
	BTreeNode<int>* bTreeNode1_Par = new BTreeNode<int>( 4 );
	
	// bTreeNode1 is full, so we can call splitChild . The parent is going to have the split
	if( bTreeNode1->isFull() ){
	
		bTreeNode1_Par->splitChild( newValue, bTreeNode1 );
		
	}	
	
	// Delete the old node
	delete bTreeNode1;
	
	// Print the Split Node 
	printSplitNode( bTreeNode1_Par );
	
	COUT << ENDL;
	
}



void test2(){
	
	COUT << "--------------------------------" << ENDL;
	COUT << "Test 2 - Even Max Degree 4 - std::string - insert value max" << ENDL;
	
	// Establish B-Tree Nodes with Maximum Degree of 3
	BTreeNode< std::string >* bTreeNode1 = new BTreeNode< std::string >( 4 );
	
	// Set the first value as 7 and the second value as 10
	bTreeNode1->values[0] = "Aardvark";		bTreeNode1->values[1] = "Manatee";	bTreeNode1->values[2] = "Rhino";
	bTreeNode1->count = 3;
	
	// Find the location where 11 should be placed
	std::string newValue = "Zebra";
	COUT << "bTreeNode1 'Zebra' should be at " << bTreeNode1->findValue( newValue ) << ENDL;
	
	// Create a Parent Node for Node 1
	BTreeNode< std::string >* bTreeNode1_Par = new BTreeNode< std::string >( bTreeNode1->maxDegree );
	
	// bTreeNode1 is full, so we can call splitChild . The parent is going to have the split
	if( bTreeNode1->isFull() ){
	
		bTreeNode1_Par->splitChild( newValue, bTreeNode1 );
		
	}	
	
	// Delete the old node
	delete bTreeNode1;
	
	// Print the Split Node 
	printSplitNode( bTreeNode1_Par );
	
	COUT << ENDL;
	
}


void test3(){
	
	COUT << "--------------------------------" << ENDL;
	COUT << "Test 3 - Even Max Degree 4 - int - insert value min" << ENDL;
	
	// Establish B-Tree Nodes with Maximum Degree of 3
	BTreeNode< int >* bTreeNode1 = new BTreeNode<int>( 4 );
	
	// Set the first value as 7 and the second value as 10
	bTreeNode1->values[0] = 7;	bTreeNode1->values[1] = 10;		bTreeNode1->values[2] = 12;
	bTreeNode1->count = 3;
	
	// Find the location where 4 should be placed
	int newValue = 4;
	COUT << "bTreeNode1 4 should be at " << bTreeNode1->findValue( newValue ) << ENDL;
	
	// Create a Parent Node for Node 1
	BTreeNode<int>* bTreeNode1_Par = new BTreeNode<int>( bTreeNode1->maxDegree );
	
	// bTreeNode1 is full, so we can call splitChild . The parent is going to have the split
	if( bTreeNode1->isFull() ){
	
		bTreeNode1_Par->splitChild( newValue, bTreeNode1 );
		
	}	
	
	// Delete the old node
	delete bTreeNode1;
	
	// Print the Split Node 
	printSplitNode( bTreeNode1_Par );
	
	COUT << ENDL;
	
}



void test4(){
	
	COUT << "--------------------------------" << ENDL;
	COUT << "Test 4 - Even Max Degree 4 - std::string - insert value min" << ENDL;
	
	// Establish B-Tree Nodes with Maximum Degree of 3
	BTreeNode< std::string >* bTreeNode1 = new BTreeNode< std::string >( 4 );
	
	// Set the first value as 7 and the second value as 10
	bTreeNode1->values[0] = "Manatee";		bTreeNode1->values[1] = "Mongoose";		bTreeNode1->values[2] = "Zebra";
	bTreeNode1->count = 3;
	
	// Find the location where 11 should be placed
	std::string newValue = "Beaver";
	COUT << "bTreeNode1 'Beaver' should be at " << bTreeNode1->findValue( newValue ) << ENDL;
	
	// Create a Parent Node for Node 1
	BTreeNode< std::string >* bTreeNode1_Par = new BTreeNode< std::string >( bTreeNode1->maxDegree );
	
	// bTreeNode1 is full, so we can call splitChild . The parent is going to have the split
	if( bTreeNode1->isFull() ){
	
		bTreeNode1_Par->splitChild( newValue, bTreeNode1 );
		
	}	
	
	// Delete the old node
	delete bTreeNode1;
	
	// Print the Split Node 
	printSplitNode( bTreeNode1_Par );
	
	COUT << ENDL;
	
}

void test5(){
	
	COUT << "--------------------------------" << ENDL;
	COUT << "Test 5 - Even Max Degree 4 - int - insert value middle" << ENDL;
	
	// Establish B-Tree Nodes with Maximum Degree of 3
	BTreeNode< int >* bTreeNode1 = new BTreeNode<int>( 4 );
	
	// Set the first value as 7 and the second value as 10
	bTreeNode1->values[0] = 7;	bTreeNode1->values[1] = 10;		bTreeNode1->values[2] = 12;
	bTreeNode1->count = 3;
	
	// Find the location where 4 should be placed
	int newValue = 8;
	COUT << "bTreeNode1 8 should be at " << bTreeNode1->findValue( newValue ) << ENDL;
	
	// Create a Parent Node for Node 1
	BTreeNode<int>* bTreeNode1_Par = new BTreeNode<int>( bTreeNode1->maxDegree );
	
	// bTreeNode1 is full, so we can call splitChild . The parent is going to have the split
	if( bTreeNode1->isFull() ){
	
		bTreeNode1_Par->splitChild( newValue, bTreeNode1 );
		
	}	
	
	// Delete the old node
	delete bTreeNode1;
	
	// Print the Split Node 
	printSplitNode( bTreeNode1_Par );
	
	COUT << ENDL;
	
}



void test6(){
	
	COUT << "--------------------------------" << ENDL;
	COUT << "Test 6 - Even Max Degree 4 - std::string - insert value middle" << ENDL;
	
	// Establish B-Tree Nodes with Maximum Degree of 3
	BTreeNode< std::string >* bTreeNode1 = new BTreeNode< std::string >( 4 );
	
	// Set the first value as 7 and the second value as 10
	bTreeNode1->values[0] = "Manatee";		bTreeNode1->values[1] = "Turtle";	bTreeNode1->values[2] = "Zebra";
	bTreeNode1->count = 3;
	
	// Find the location where 11 should be placed
	std::string newValue = "Mongoose";
	COUT << "bTreeNode1 'Mongoose' should be at " << bTreeNode1->findValue( newValue ) << ENDL;
	
	// Create a Parent Node for Node 1
	BTreeNode< std::string >* bTreeNode1_Par = new BTreeNode< std::string >( bTreeNode1->maxDegree );
	
	// bTreeNode1 is full, so we can call splitChild . The parent is going to have the split
	if( bTreeNode1->isFull() ){
	
		bTreeNode1_Par->splitChild( newValue, bTreeNode1 );
		
	}	
	
	// Delete the old node
	delete bTreeNode1;
	
	// Print the Split Node 
	printSplitNode( bTreeNode1_Par );
	
	COUT << ENDL;
	
}


void test7(){
	
	COUT << "--------------------------------" << ENDL;
	COUT << "Test 7 - Even Max Degree 4 - int - insert value middle" << ENDL;
	
	// Establish B-Tree Nodes with Maximum Degree of 4
	BTreeNode< int >* bTreeNode1 = new BTreeNode<int>( 4 );
	
	// Set the first value as 7 and the second value as 10
	bTreeNode1->values[0] = 7;	bTreeNode1->values[1] = 8;
	bTreeNode1->values[2] = 10;
	bTreeNode1->count = 3;
	
	// Find the location where 9 should be placed
	int newValue = 9;
	COUT << "bTreeNode1 9 should be at " << bTreeNode1->findValue( newValue ) << ENDL;
	
	// Create a Parent Node for Node 1
	BTreeNode<int>* bTreeNode1_Par = new BTreeNode<int>( bTreeNode1->maxDegree );
	
	// bTreeNode1 is full, so we can call splitChild . The parent is going to have the split
	if( bTreeNode1->isFull() ){
	
		bTreeNode1_Par->splitChild( newValue, bTreeNode1 );
		
	}	
	
	// Delete the old node
	delete bTreeNode1;
	
	// Print the Split Node 
	printSplitNode( bTreeNode1_Par );
	
	COUT << ENDL;
	
}


void test8(){
	
	COUT << "--------------------------------" << ENDL;
	COUT << "Test 8 - Even Max Degree 4 - std::string - insert value middle" << ENDL;
	
	// Establish B-Tree Nodes with Maximum Degree of 5
	BTreeNode< std::string >* bTreeNode1 = new BTreeNode<std::string>( 4 );
	
	// Set the first value as 7 and the second value as 10
	bTreeNode1->values[0] = "Apple";	bTreeNode1->values[1] = "Cherry";
	bTreeNode1->values[2] = "Grape";
	bTreeNode1->count = 3;
	
	// Find the location where 11 should be placed
	std::string newValue = "Elderberry";
	COUT << "bTreeNode1 'Elderberry' should be at " << bTreeNode1->findValue( newValue ) << ENDL;
	
	// Create a Parent Node for Node 1
	BTreeNode<std::string>* bTreeNode1_Par = new BTreeNode<std::string>( bTreeNode1->maxDegree );
	
	// bTreeNode1 is full, so we can call splitChild . The parent is going to have the split
	if( bTreeNode1->isFull() ){
	
		bTreeNode1_Par->splitChild( newValue, bTreeNode1 );
		
	}	
	
	// Delete the old node
	delete bTreeNode1;
	
	// Print the Split Node 
	printSplitNode( bTreeNode1_Par );
	
	COUT << ENDL;
	
}


void test9(){
	
	COUT << "--------------------------------" << ENDL;
	COUT << "Test 9 - Even Max Degree 6 - int - insert value min" << ENDL;
	
	// Establish B-Tree Nodes with Maximum Degree of 5
	BTreeNode< int >* bTreeNode1 = new BTreeNode<int>( 6 );
	
	// Set the first value as 7 and the second value as 10
	bTreeNode1->values[0] = 7;	bTreeNode1->values[1] = 8;
	bTreeNode1->values[2] = 9;	bTreeNode1->values[3] = 10;
	bTreeNode1->values[4] = 11;
	bTreeNode1->count = 5;
	
	// Find the location where 11 should be placed
	int newValue = 6;
	COUT << "bTreeNode1 6 should be at " << bTreeNode1->findValue( newValue ) << ENDL;
	
	// Create a Parent Node for Node 1
	BTreeNode<int>* bTreeNode1_Par = new BTreeNode<int>( bTreeNode1->maxDegree );
	
	// bTreeNode1 is full, so we can call splitChild . The parent is going to have the split
	if( bTreeNode1->isFull() ){
	
		bTreeNode1_Par->splitChild( newValue, bTreeNode1 );
		
	}	
	
	// Delete the old node
	delete bTreeNode1;
	
	// Print the Split Node 
	printSplitNode( bTreeNode1_Par );
	
	COUT << ENDL;
	
}


void test10(){
	
	COUT << "--------------------------------" << ENDL;
	COUT << "Test 10 - Even Max Degree 6 - std::string - insert value moddile" << ENDL;
	
	// Establish B-Tree Nodes with Maximum Degree of 6
	BTreeNode< std::string >* bTreeNode1 = new BTreeNode<std::string>( 6 );
	
	// Set the first value as 7 and the second value as 10
	bTreeNode1->values[0] = "Apple";	bTreeNode1->values[1] = "Banana";
	bTreeNode1->values[2] = "Elderberry";	bTreeNode1->values[3] = "Peach";
	bTreeNode1->values[4] = "Pear";
	bTreeNode1->count = 5;
	
	// Find the location where Apple should be placed
	std::string newValue = "Cherry";
	COUT << "bTreeNode1 'Cherry' should be at " << bTreeNode1->findValue( newValue ) << ENDL;
	
	// Create a Parent Node for Node 1
	BTreeNode<std::string>* bTreeNode1_Par = new BTreeNode<std::string>( bTreeNode1->maxDegree );
	
	// bTreeNode1 is full, so we can call splitChild . The parent is going to have the split
	if( bTreeNode1->isFull() ){
	
		bTreeNode1_Par->splitChild( newValue, bTreeNode1 );
		
	}	
	
	// Delete the old node
	delete bTreeNode1;
	
	// Print the Split Node 
	printSplitNode( bTreeNode1_Par );
	
	COUT << ENDL;
	
}


void test11(){
	
	COUT << "--------------------------------" << ENDL;
	COUT << "Test 11 - Even Max Degree 6 - int - insert value middle of right noe" << ENDL;
	
	// Establish B-Tree Nodes with Maximum Degree of 6
	BTreeNode< int >* bTreeNode1 = new BTreeNode<int>( 6 );
	
	// Set the first value as 7 and the second value as 10
	bTreeNode1->values[0] = 7;	bTreeNode1->values[1] = 8;
	bTreeNode1->values[2] = 9;	bTreeNode1->values[3] = 10;
	bTreeNode1->values[4] = 12;
	bTreeNode1->count = 5;
	
	// Find the location where 11 should be placed
	int newValue = 11;
	COUT << "bTreeNode1 11 should be at " << bTreeNode1->findValue( newValue ) << ENDL;
	
	// Create a Parent Node for Node 1
	BTreeNode<int>* bTreeNode1_Par = new BTreeNode<int>( bTreeNode1->maxDegree );
	
	// bTreeNode1 is full, so we can call splitChild . The parent is going to have the split
	if( bTreeNode1->isFull() ){
	
		bTreeNode1_Par->splitChild( newValue, bTreeNode1 );
		
	}	
	
	// Delete the old node
	delete bTreeNode1;
	
	// Print the Split Node 
	printSplitNode( bTreeNode1_Par );
	
	COUT << ENDL;
	
}


void test12(){
	
	COUT << "--------------------------------" << ENDL;
	COUT << "Test 12 - Even Max Degree 6 - std::string - insert value middle of left" << ENDL;
	
	// Establish B-Tree Nodes with Maximum Degree of 6
	BTreeNode< std::string >* bTreeNode1 = new BTreeNode<std::string>( 6 );
	
	// Set the first value as 7 and the second value as 10
	bTreeNode1->values[0] = "Apple";	bTreeNode1->values[1] = "Cherry";
	bTreeNode1->values[2] = "Elderberry";	bTreeNode1->values[3] = "Peach";
	bTreeNode1->values[4] = "Pear";
	bTreeNode1->count = 5;
	
	// Find the location where Apple should be placed
	std::string newValue = "Blueberry";
	COUT << "bTreeNode1 'Blueberry' should be at " << bTreeNode1->findValue( newValue ) << ENDL;
	
	// Create a Parent Node for Node 1
	BTreeNode<std::string>* bTreeNode1_Par = new BTreeNode<std::string>( bTreeNode1->maxDegree );
	
	// bTreeNode1 is full, so we can call splitChild . The parent is going to have the split
	if( bTreeNode1->isFull() ){
	
		bTreeNode1_Par->splitChild( newValue, bTreeNode1 );
		
	}	
	
	// Delete the old node
	delete bTreeNode1;
	
	// Print the Split Node 
	printSplitNode( bTreeNode1_Par );
	
	COUT << ENDL;
	
}


int main(){
	
	test1();

	test2();
	
	test3();

	test4();
	
	test5();

	test6();
	
	test7();
	
	test8();
	
	test9();
	
	test10();
	
	test11();
	
	test12();

	return 0;
}