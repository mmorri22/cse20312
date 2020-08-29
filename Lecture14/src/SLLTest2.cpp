/**********************************************
* File: SLLTest2.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Second test with push_front for SLList 
**********************************************/

#include "../include/SLList.h"
#include <string>

/********************************************
* Function Name  : main
* Pre-conditions : none
* Post-conditions: int
* 
* This is the main driver function 
********************************************/
int main(){

	SLList<std::string> strSLL;

	strSLL.push_front("Irish"); strSLL.Insert("Here");
	strSLL.push_front("Go");	strSLL.push_front("We");
	strSLL.Insert("We");		strSLL.push_front("Here");
	strSLL.Insert("Go");

	std::cout << strSLL << std::endl;
	
	SLList<float> *floatSLL = new SLList<float>();
	
	floatSLL->Insert( (float)22.1 );	floatSLL->Insert( (float)-19.46 );
	floatSLL->Insert( (float)1.4e-7 );	floatSLL->push_front( (float)1 );
	std::cout << *floatSLL << std::endl;
	
	floatSLL->Delete( (float)-19.46 );
	std::cout << *floatSLL << std::endl;
	
	delete floatSLL;

	return 0;
}
