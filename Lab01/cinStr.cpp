/**********************************************
* File: cinStr.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file demonstrates the benefits of cin in C++
* while providing improved tests with the string library
**********************************************/

#include <iostream> /*C++ version of stdio.h*/
#include <cstdlib> /* Equivalent of stdlib.h */
#include <string> /* String Library */
#include <sstream> /* String Stream for inputting to variables */

#define COUT std::cout
#define ENDL std::endl
#define STRING std::string
#define SSTREAM std::stringstream

/********************************************
* Function Name  : noBadChars
* Pre-conditions : STRING testString
* Post-conditions: bool
* 
* Returns false if any character other than 0-9
* '.', or '-' appears in the string
********************************************/
bool noBadChars(STRING testString){
	
	for(unsigned int i = 0; i < testString.length(); i++){
		
		/* Return false if - is outside of the first char */
		if(  (testString[i] < '0' || testString[i] > '9') ){
					
				/* Return false if negative sign is not at i == 0 */
				if(testString[i] == '-'){
					
					if(i != 0)
						return false;
					
				}
				
				/* Do not return false if there is a . here */
				else if(testString[i] != '.'){
					return false;
				} 
		}
		
	}
	
	return true;
}

/********************************************
* Function Name  : main
* Pre-conditions : none
* Post-conditions: int
* 
* This is the main driver function 
********************************************/
int main(){

	STRING strX;
	int tempX;
	
	STRING strUnsigX;
	unsigned int unsigX;
	
	STRING strFloatX;
	float floatY;
	
	COUT << "Input an integer: ";
	std::cin >> strX;
	
	/* Check if the int input has no chars AND if the string contains . */
	if(SSTREAM(strX) >> tempX 
		&& noBadChars(strX)
		&& strX.find(".") == STRING::npos){
		
		COUT << "The integer is " << tempX << ENDL;
		
	}
	else{
		std::cerr << strX << " is not a valid Integer" << ENDL;
		exit(-1);
	}	
	
	COUT << "Input an unsigned integer: ";	
	std::cin >> strUnsigX;

	/* Check if the int input has no chars AND if the string contains . AND if the string contains -*/
	if(SSTREAM(strUnsigX) >> unsigX 
		&& noBadChars(strUnsigX)
		&& strUnsigX.find(".") == STRING::npos 
		&& strUnsigX.find("-") == STRING::npos){
			
		COUT << "The unsigned integer value is " << unsigX << ENDL;
	
	}
	else{
		
		std::cerr << strUnsigX << " is not a valid unsigned Integer" << ENDL;
		exit(-1);
		
	}
	
	
	COUT << "Input a float: ";
	std::cin >> strFloatX;
	if(SSTREAM(strFloatX) >> floatY
		&& noBadChars(strFloatX) ){
		
		COUT << "The float value is " << floatY << ENDL;
		
	}
	else{
		
		std::cerr << strFloatX << " is not a valid Float" << ENDL;
		exit(-1);
		
	}
		
	return 0;
}
