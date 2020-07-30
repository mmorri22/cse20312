/**********************************************
* File: template.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file demonstrates an example of templates
* where the function is in the header file.
* template.h includes the function definition
* in the header file.
*
* Lecture 03 - Slides 36-38
**********************************************/

#include <iostream> /*C++ version of stdio.h*/

/********************************************
* Function Name  : printFunc
* Pre-conditions : T t_var
* Post-conditions: none
* 
* Initial Example of a Templated Class 
********************************************/
template<class T>
void printFunc(T t_var){
	
	std::cout << t_var << std::endl;
	
}

/********************************************
* Function Name  : main
* Pre-conditions : none
* Post-conditions: int
* 
* This is the main driver function 
********************************************/
int main(){

	int i = 1842;
    double j = 3.14;
    std::string k = "Go Irish!";
    printFunc(i); printFunc(j); printFunc(k);
		
	return 0;
}
