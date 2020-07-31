/**********************************************
* File: DLLTest2.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Second test with push_front for DLList 
**********************************************/

#include "../include/DLList.h"
#include <string>

/********************************************
* Function Name  : main
* Pre-conditions : none
* Post-conditions: int
* 
* This is the main driver function 
********************************************/
int main(){

	DLList<std::string> strDLL;

	strDLL.push_front("Irish"); strDLL.Insert("Here");
	strDLL.push_front("Go");	strDLL.push_front("We");
	strDLL.Insert("We");		strDLL.push_front("Here");
	strDLL.Insert("Go");
	strDLL.push_back("Data Structures");

	std::cout << strDLL << std::endl;
	
	DLList<float> *floatDLL = new DLList<float>();
	
	floatDLL->Insert( (float)22.1 );	floatDLL->Insert( (float)-19.46 );
	floatDLL->Insert( (float)1.4e-7 );	floatDLL->push_front( (float)1 );
	std::cout << *floatDLL << std::endl;
	
	floatDLL->Delete( (float)-19.46 );
	std::cout << *floatDLL << std::endl;
	
	delete floatDLL;

	return 0;
}
