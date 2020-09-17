/**********************************************
* File: DLLMerge.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Final Driver for the In-Class Assignment
**********************************************/

#include "../include/DLList.h"
#include <string>

template<class T>
void mergeLists(DLList<T>& dllist1, DLList<T>& dllist2){
	
	std::cout << "Initial Lists:" << std::endl;
	std::cout << "List 1: " << dllist1 << std::endl;
	std::cout << "List 2: " << dllist2 << std::endl;
	
	// Merge Lists
	dllist1.merge(dllist2);
	std::cout << std::endl;
	
	std::cout << std::endl << "Final Lists:" << std::endl;
	std::cout << "List 1: " << dllist1 << std::endl;
	std::cout << "List 2: " << dllist2 << std::endl;
	
	
	std::cout << "----------------------------------------------" << std::endl;
	
}

/********************************************
* Function Name  : main
* Pre-conditions : none
* Post-conditions: int
* 
* This is the main driver function 
********************************************/
int main(){

	// Test Doubly Linked Lists
	DLList<int> dllist1;
	DLList<int> dllist2;
	DLList<int> dlempty;

	// 5->7->17->13->11
	dllist1.Insert(5);
	dllist1.Insert(7);
	dllist1.Insert(17);
	dllist1.Insert(13);
	dllist1.Insert(11);
	
	// Second: 12->10->2->4->6
	dllist2.Insert(12);
	dllist2.Insert(10);
	dllist2.Insert(2);
	dllist2.Insert(4);
	
	// First Merge
	mergeLists(dllist1, dllist2);
	
	// Empty Second
	mergeLists(dllist1, dlempty);	
	
	// Empty First
	mergeLists(dlempty, dllist1);
	
	// Shorter list - Reinsert into empty list
	dllist2.Insert(30);
	dllist2.Insert(27);
	
	// Put dllist2 as the first, dllist1 as the second
	mergeLists(dllist2, dllist1);
	
	return 0;
}
