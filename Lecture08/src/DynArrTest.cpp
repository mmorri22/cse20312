#include <cstdlib>
#include <iostream>
#include "../include/DynArr.h"

const int LENGTH = 10;

int main(void)
{
	// PQC requirws time(NULL) be cast to unsigned int
    srand( (unsigned int)time(NULL) );
	
	// Normal Allocation for Dynamic Array for float
   DynArr<float> floatArr;
   
   // Print initial size and capacity of y
   std::cout << "Initial: ";
   std::cout << "floatArr has a size of " << floatArr.length()
		<< " and a capacity of " << floatArr.capacity();
   std::cout << "\n" << std::endl;
   
   floatArr.push_back( (float)3.1 );		floatArr.push_back( (float)4.7 );
   floatArr.push_back( (float)-2.2 );		floatArr.push_back( (float)-7.65 );
   floatArr.push_back( (float)5.5e-7 );		floatArr.push_back( (float)-3.3e18 );
   floatArr.push_back( (float)-0.0102 );	floatArr.push_back( (float)4.4489 );
   floatArr.push_back( (float)22.46 );		floatArr.push_back( (float)3.2e-17 );
   
   std::cout << "y has a size of " << floatArr.length() << " and a capacity of " 
		<< floatArr.capacity() << ": ";
		
   for(unsigned int iter = 0; iter < floatArr.length(); ++iter){
	   
	   std::cout << floatArr[iter] << " ";
   }
   std::cout << std::endl << (char)10;
   
   // Update a specific value 
   std::cout << "floatArr[3] before = " << floatArr[3] << std::endl;
   floatArr[3] = (float)1842;
   std::cout << "floatArr[3] after  = " << floatArr[3] << "\n\n";
 
    // Initialize the templates int array pointers   
    DynArr<int> *x = new DynArr<int>(LENGTH);
	
   std::cout << "Initial: ";
   // Remember: (*x). and x-> are logically equivalent
   std::cout << "x has a size of " << x->length() << " and a capacity of " << (*x).capacity();
   std::cout << "\n" << std::endl;
   
   // Generate a random number for all 
    for (unsigned int i = 0; i < LENGTH; i++) {
    	(*x)[i] = rand() % 1000;
    }
   
   // Remember: (*x). and x-> are logically equivalent
   std::cout << "x has a size of " << (*x).length() << " and a capacity of " << x->capacity() << ": ";
   
   for(unsigned int iter = 0; iter < x->length(); ++iter){
	   
	   //(*x) de-references x, which then allows the [] operator to be called
	   std::cout << (*x)[iter] << " ";
   }
   std::cout << std::endl << (char)10;
   
   std::cout << "(*x)[3] before = " << (*x)[3]  << std::endl;
   (*x)[3]  = (float)27;
   std::cout << "(*x)[3]  after = " << (*x)[3] << "\n\n";
   
 
   delete x;    // "delete floatArr;" not necessary, since floatArr is not a pointer
   
   return 0;
}
