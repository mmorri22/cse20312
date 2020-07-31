#include <cstdlib>
#include <iostream>
#include "../include/DynArr6.h"

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
	
	// Print Values in dblArray
	for(unsigned int i = 0; i < dblArr.length(); i++){
		
		COUT << dblArr[i] << ENDL;
		
	}
	
	COUT << ENDL;
	
	// Update values in dblArray - T& operator[] permits this
	dblArr[0] = 1.2;
	dblArr[1] = -33.4;
	dblArr[2] = 18.7;
	dblArr[3] = 44.92;
	dblArr[4] = 1842;
	dblArr[5] = 30.23;

	// Print Values in dblArray after update
	for(unsigned int i = 0; i < dblArr.length(); i++){
		
		COUT << dblArr[i] << ENDL;
		
	}

	return 0;
}
