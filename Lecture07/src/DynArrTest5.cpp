#include <cstdlib>
#include <iostream>
#include "../include/DynArr5.h"

const int LENGTH = 10;

#define COUT std::cout
#define ENDL std::endl;

template<class T>
void printData( DynArr<T>& theArr ){
	
	// Print initial size and capacity of floatArr
	COUT << "Initial: ";
	COUT << "Array has a size of " << theArr.length()
		<< " and a capacity of " << theArr.capacity();
	COUT << "\n" << ENDL;	
	
}

int main(void)
{
	
	// Normal Allocation for Dynamic Array for float
	DynArr<float> floatArr;
   
	// Print initial size and capacity of floatArr
	COUT << "floatArr data:" << ENDL;
	printData(floatArr);

	// Normal Allocation for Dynamic Array for double
	DynArr<double> dblArr(6);
	
	// Print initial size and capacity of dblArr
	COUT << "dblArr data:" << ENDL;
	printData(dblArr);
   
	return 0;
}
