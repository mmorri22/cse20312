/**********************************************
* File: exp.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* The main driver for the exponential recursive
* solver 
**********************************************/
#include <cmath> 		// pow
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
		std::cout << "Not a valid double" << std::endl;
		exit(-1);
	}
	
	return factNum;
	
}


double factorial(unsigned int i){
	
	// Base case i = 0
	if(i == 0){
		return 1;
	}

	return (double)i * factorial(i-1);
}


double exponential(double x, int k){
	
	if(k == 0)
		return 1;
	
	double returnVal = (pow(x,k)/factorial(k)) + exponential(x,k-1);

	return returnVal;
  
}


int main(int argc, char** argv){
	
	double expVal = exponential(getArgv1Num(argc, argv), 30);
	
	std::cout << "Final Result: " << std::setprecision(12) << expVal << std::endl;
	
	return 0;
}
