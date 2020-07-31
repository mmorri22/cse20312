#include "../src/A_1.h"

#define COUT std::cout
#define ENDL std::endl

int main()  { 

	/* Initialize A objects */
	A<double, double> dblA;
	
	const A<char, char> a('G', 72); 
   
	A<int, char> b(71, 'H'); 
   
	/* Construct pointer to class A<int, float> */
	A<int, float>* c = new A<int, float>(10, (float)-35.7); 
   
	/* Print the address of each object */
	COUT << "Address of a on the heap: " << &dblA << ENDL;
	COUT << "Address of a on the heap: " << &a << ENDL;
	COUT << "Address of b on the heap: " << &b << ENDL;
	COUT << "Address of c on the heap: " << c << ENDL;
   
	/* A<int, float> destructor called since c is a pointer */
	delete c;
   
	return 0; 
} 


