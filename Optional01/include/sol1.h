#ifndef SOL1_H
#define SOL1_H

#include "DynArr.h"
#include <iostream>

#define COUT std::cout
#define ENDL std::endl

void printArray(const DynArr<int>& array){
	
	COUT << "Input: [";
	
	for(unsigned int iter = 0; iter < array.length(); iter++){
		
		COUT << array[iter];
		
		if( iter < array.length() - 1){
			
			COUT << ",";
		}
		
	}
	
	COUT << "]" << ENDL;
	
}

#endif
