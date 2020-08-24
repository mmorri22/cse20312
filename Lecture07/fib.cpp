/**********************************************
* File: fib.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Contains the main driver function for a Fibonacci
* solver 
**********************************************/

#include <iostream>
#include <string>       // std::string
#include <iostream>     // std::cout
#include <iomanip>		// std::setprecision
#include <sstream>      // std::stringstream
#include <cstdlib>		// exitr

double getArgv1Num(int argc, char** argv){
	
	if(argc != 2){
		std::cout << "Incorrect number of inputs" << std::endl;
		exit(-1);
	}
	
	// stringstream used for the conversion initialized with the contents of argv[1]
	double factNum;
	std::stringstream convert(argv[1]);

	//give the value to factNum using the characters in the string
	if ( !(convert >> factNum) ){
		std::cout << "Not a valid integer" << std::endl;
		exit(-1);
	}
	
	return factNum;
	
}

double Fib(double n){
	
	if(n == 0){
		return 1;
	}
	else if(n == 1){
		return 1;
	}
	
	return Fib(n-1) + Fib(n-2);
	
}

/********************************************
* Function Name  : main
* Pre-conditions : int argc, char **argv
* Post-conditions: int
* 
* Main driver function for Fibonacci solver 
********************************************/
int main(int argc, char **argv){

	std::cout << Fib(getArgv1Num(argc, argv)) << std::endl;

	return 0;
}
