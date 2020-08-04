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
	
	std::cout << x << " " << k << " " 
		<< std::setprecision(6) << returnVal << std::endl;

	return returnVal;
  
}


int main(){
	
	double expVal = exponential(4, 30);
	
	std::cout << "Final Result: " << std::setprecision(6) << expVal << std::endl;
	
	return 0;
}
