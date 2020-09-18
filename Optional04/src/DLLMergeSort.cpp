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
	dllist1.merge2Sorted(dllist2);
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

	// 1 3 5 7 9
	dllist1.Insert(1);
	dllist1.Insert(3);
	dllist1.Insert(12);
	
	// Second: 2->4->6->8
	dllist2.Insert(2);
	dllist2.Insert(4);
	
	// First Merge
	mergeLists(dllist1, dllist2);
	
	// Empty Second
	mergeLists(dllist1, dlempty);	
	
	// Shorter list - Reinsert into empty list
	dllist2.Insert(10);
	mergeLists(dllist1, dllist2);
	
	
	// Put dllist2 as the first, dllist1 as the second
	dllist2.Insert(0);
	dllist2.Insert(5);
	dllist2.Insert(6);
	dllist2.Insert(7);
	dllist2.Insert(7);
	dllist2.Insert(13);
	dllist2.Insert(14);
	dllist2.Insert(15);	
	mergeLists(dllist1, dllist2);
	
	return 0;
}
