/**********************************************
* File: factHeaderEx.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file contains an introductory example of 
* using header files to simplify and re-use code 
**********************************************/

#include "factorial.h"

/********************************************
* Function Name  : printResult
* Pre-conditions : T input, U result
* Post-conditions: void
* 
* Will print the format input! = result 
* If result is -1, will not print anything 
********************************************/

template< class T, class U >
void printResult( T input, U result ){
	
	if(result != (U)-1){
		COUT << input << "! = " << result << "\n";
	}
	
}


/********************************************
* Function Name  : main
* Pre-conditions : void
* Post-conditions: int
* 
* This is the main driver function for the program 
********************************************/
int main(void){
	
	/* Check int max */
	printResult( MAX_INT_FACT, factInt(MAX_INT_FACT) );
	
	printResult( MAX_INT_FACT + 1, factInt(MAX_INT_FACT + 1) );
	
	
	/* Check float max */
	printResult( MAX_FLOAT_FACT, factFloat(MAX_FLOAT_FACT) );
	
	printResult( MAX_FLOAT_FACT + 1, factFloat(MAX_FLOAT_FACT + 1) );


	/* Check double max */
	printResult( MAX_DOUBLE_FACT, factDouble(MAX_DOUBLE_FACT) );
	
	printResult( MAX_DOUBLE_FACT + 1, factDouble(MAX_DOUBLE_FACT + 1) );
	

	return 0;
}
