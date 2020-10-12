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
	COUT << "Test 1 - Odd Max Degree 3 - int - insert value max" << ENDL;
	
	// Establish B-Tree Nodes with Maximum Degree of 3
	BTreeNode< int >* bTreeNode1 = new BTreeNode<int>( 3 );
	
	// Set the first value as 7 and the second value as 10
	bTreeNode1->values[0] = 7;	bTreeNode1->values[1] = 10;
	bTreeNode1->count = 2;
	
	// Find the location where 11 should be placed
	COUT << "bTreeNode1 11 should be at " << bTreeNode1->findValue( 11 ) << ENDL;
	
	// Create a Parent Node for Node 1
	BTreeNode<int>* bTreeNode1_Par = new BTreeNode<int>( 3 );
	
	// bTreeNode1 is full, so we can call splitChild . The parent is going to have the split
	if( bTreeNode1->isFull() ){
	
		int newValue = 11;
	
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
	COUT << "Test 2 - Odd Max Degree 3 - std::string - insert value max" << ENDL;
	
	// Establish B-Tree Nodes with Maximum Degree of 3
	BTreeNode< std::string >* bTreeNode1 = new BTreeNode< std::string >( 3 );
	
	// Set the first value as 7 and the second value as 10
	bTreeNode1->values[0] = "Aardvark";		bTreeNode1->values[1] = "Zebra";
	bTreeNode1->count = 2;
	
	// Find the location where 11 should be placed
	std::string newValue = "Manatee";
	COUT << "bTreeNode1 'Manatee' should be at " << bTreeNode1->findValue( newValue ) << ENDL;
	
	// Create a Parent Node for Node 1
	BTreeNode< std::string >* bTreeNode1_Par = new BTreeNode< std::string >( 3 );
	
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
	COUT << "Test 3 - Odd Max Degree 3 - int - insert value min" << ENDL;
	
	// Establish B-Tree Nodes with Maximum Degree of 3
	BTreeNode< int >* bTreeNode1 = new BTreeNode<int>( 3 );
	
	// Set the first value as 7 and the second value as 10
	bTreeNode1->values[0] = 7;	bTreeNode1->values[1] = 10;
	bTreeNode1->count = 2;
	
	// Find the location where 4 should be placed
	int newValue = 4;
	COUT << "bTreeNode1 4 should be at " << bTreeNode1->findValue( 4 ) << ENDL;
	
	// Create a Parent Node for Node 1
	BTreeNode<int>* bTreeNode1_Par = new BTreeNode<int>( 3 );
	
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
	COUT << "Test 3 - Odd Max Degree 3 - std::string - insert value min" << ENDL;
	
	// Establish B-Tree Nodes with Maximum Degree of 3
	BTreeNode< std::string >* bTreeNode1 = new BTreeNode< std::string >( 3 );
	
	// Set the first value as 7 and the second value as 10
	bTreeNode1->values[0] = "Manatee";		bTreeNode1->values[1] = "Zebra";
	bTreeNode1->count = 2;
	
	// Find the location where 11 should be placed
	std::string newValue = "Beaver";
	COUT << "bTreeNode1 'Beaver' should be at " << bTreeNode1->findValue( newValue ) << ENDL;
	
	// Create a Parent Node for Node 1
	BTreeNode< std::string >* bTreeNode1_Par = new BTreeNode< std::string >( 3 );
	
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
	COUT << "Test 3 - Odd Max Degree 3 - int - insert value min" << ENDL;
	
	// Establish B-Tree Nodes with Maximum Degree of 3
	BTreeNode< int >* bTreeNode1 = new BTreeNode<int>( 3 );
	
	// Set the first value as 7 and the second value as 10
	bTreeNode1->values[0] = 7;	bTreeNode1->values[1] = 10;
	bTreeNode1->count = 2;
	
	// Find the location where 4 should be placed
	int newValue = 8;
	COUT << "bTreeNode1 8 should be at " << bTreeNode1->findValue( newValue ) << ENDL;
	
	// Create a Parent Node for Node 1
	BTreeNode<int>* bTreeNode1_Par = new BTreeNode<int>( 3 );
	
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
	COUT << "Test 3 - Odd Max Degree 3 - std::string - insert value min" << ENDL;
	
	// Establish B-Tree Nodes with Maximum Degree of 3
	BTreeNode< std::string >* bTreeNode1 = new BTreeNode< std::string >( 3 );
	
	// Set the first value as 7 and the second value as 10
	bTreeNode1->values[0] = "Manatee";		bTreeNode1->values[1] = "Zebra";
	bTreeNode1->count = 2;
	
	// Find the location where 11 should be placed
	std::string newValue = "Rabbit";
	COUT << "bTreeNode1 'Rabbit' should be at " << bTreeNode1->findValue( newValue ) << ENDL;
	
	// Create a Parent Node for Node 1
	BTreeNode< std::string >* bTreeNode1_Par = new BTreeNode< std::string >( 3 );
	
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
	COUT << "Test 7 - Odd Max Degree 5 - int - insert value max" << ENDL;
	
	// Establish B-Tree Nodes with Maximum Degree of 5
	BTreeNode< int >* bTreeNode1 = new BTreeNode<int>( 5 );
	
	// Set the first value as 7 and the second value as 10
	bTreeNode1->values[0] = 7;	bTreeNode1->values[1] = 8;
	bTreeNode1->values[2] = 9;	bTreeNode1->values[3] = 10;
	bTreeNode1->count = 4;
	
	// Find the location where 11 should be placed
	int newValue = 11;
	COUT << "bTreeNode1 11 should be at " << bTreeNode1->findValue( 11 ) << ENDL;
	
	// Create a Parent Node for Node 1
	BTreeNode<int>* bTreeNode1_Par = new BTreeNode<int>( 5 );
	
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
	COUT << "Test 8 - Odd Max Degree 5 - std::string - insert value max" << ENDL;
	
	// Establish B-Tree Nodes with Maximum Degree of 5
	BTreeNode< std::string >* bTreeNode1 = new BTreeNode<std::string>( 5 );
	
	// Set the first value as 7 and the second value as 10
	bTreeNode1->values[0] = "Apple";	bTreeNode1->values[1] = "Banana";
	bTreeNode1->values[2] = "Cherry";	bTreeNode1->values[3] = "Grape";
	bTreeNode1->count = 4;
	
	// Find the location where 11 should be placed
	std::string newValue = "Zucchini";
	COUT << "bTreeNode1 'Zucchini' should be at " << bTreeNode1->findValue( newValue ) << ENDL;
	
	// Create a Parent Node for Node 1
	BTreeNode<std::string>* bTreeNode1_Par = new BTreeNode<std::string>( 5 );
	
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
	COUT << "Test 9 - Odd Max Degree 5 - int - insert value min" << ENDL;
	
	// Establish B-Tree Nodes with Maximum Degree of 5
	BTreeNode< int >* bTreeNode1 = new BTreeNode<int>( 5 );
	
	// Set the first value as 7 and the second value as 10
	bTreeNode1->values[0] = 7;	bTreeNode1->values[1] = 8;
	bTreeNode1->values[2] = 9;	bTreeNode1->values[3] = 10;
	bTreeNode1->count = 4;
	
	// Find the location where 11 should be placed
	int newValue = 6;
	COUT << "bTreeNode1 6 should be at " << bTreeNode1->findValue( newValue ) << ENDL;
	
	// Create a Parent Node for Node 1
	BTreeNode<int>* bTreeNode1_Par = new BTreeNode<int>( 5 );
	
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
	COUT << "Test 10 - Odd Max Degree 5 - std::string - insert value min" << ENDL;
	
	// Establish B-Tree Nodes with Maximum Degree of 5
	BTreeNode< std::string >* bTreeNode1 = new BTreeNode<std::string>( 5 );
	
	// Set the first value as 7 and the second value as 10
	bTreeNode1->values[0] = "Banana";	bTreeNode1->values[1] = "Cherry";
	bTreeNode1->values[2] = "Grape";	bTreeNode1->values[3] = "Pear";
	bTreeNode1->count = 4;
	
	// Find the location where Apple should be placed
	std::string newValue = "Apple";
	COUT << "bTreeNode1 'Apple' should be at " << bTreeNode1->findValue( newValue ) << ENDL;
	
	// Create a Parent Node for Node 1
	BTreeNode<std::string>* bTreeNode1_Par = new BTreeNode<std::string>( 5 );
	
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
	COUT << "Test 11 - Odd Max Degree 5 - int - insert value middle" << ENDL;
	
	// Establish B-Tree Nodes with Maximum Degree of 5
	BTreeNode< int >* bTreeNode1 = new BTreeNode<int>( 5 );
	
	// Set the first value as 7 and the second value as 10
	bTreeNode1->values[0] = 7;	bTreeNode1->values[1] = 8;
	bTreeNode1->values[2] = 12;	bTreeNode1->values[3] = 13;
	bTreeNode1->count = 4;
	
	// Find the location where 11 should be placed
	int newValue = 10;
	COUT << "bTreeNode1 10 should be at " << bTreeNode1->findValue( newValue ) << ENDL;
	
	// Create a Parent Node for Node 1
	BTreeNode<int>* bTreeNode1_Par = new BTreeNode<int>( 5 );
	
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
	COUT << "Test 12 - Odd Max Degree 5 - std::string - insert value min" << ENDL;
	
	// Establish B-Tree Nodes with Maximum Degree of 5
	BTreeNode< std::string >* bTreeNode1 = new BTreeNode<std::string>( 5 );
	
	// Set the first value as 7 and the second value as 12
	bTreeNode1->values[0] = "Apple";	bTreeNode1->values[1] = "Banana";
	bTreeNode1->values[2] = "Peach";	bTreeNode1->values[3] = "Pear";
	bTreeNode1->count = 4;
	
	// Find the location where Grape should be placed
	std::string newValue = "Grape";
	COUT << "bTreeNode1 'Grape' should be at " << bTreeNode1->findValue( newValue ) << ENDL;
	
	// Create a Parent Node for Node 1
	BTreeNode<std::string>* bTreeNode1_Par = new BTreeNode<std::string>( 5 );
	
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