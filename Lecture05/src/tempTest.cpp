#include "../include/A.h"

int main()  { 

   const A<char, char> a('G', 72); 
   A<char, char> b(71, 'H'); 
   /* Construct pointer to class A<int, float> */
   A<int, float>* c = new A<int, float>(10, (float)-35.7); 
   
   std::cout << "a: " << a << std::endl;
   std::cout << "b: " << b << std::endl;  
   std::cout << "c: " << *c << std::endl;  // Must de-reference
   
   if(a == b){
	   std::cout << "a == b" << std::endl;
   }
   
   c->setX( 31 ); // Use -> to dereference pointer to call method
   (*c).setY( (float)18.231 ); // Showing (*c). and c-> are equivalent
   
   // Print the location in memory of C
   std::cout << "Location in memory of c: " << c << std::endl;
   
   // Print the location of the register holding the location of C 
   std::cout << "Base register address c: " << &c << std::endl;
   
   // Actual Value of c
   std::cout << "c: " << *c << std::endl;  // Must de-reference 
   
   /* Calling assignment operator, with c de-referenced */
   A<int, float> d = *c;
   A<char, char> e(a);
   
   std::cout << "d: " << d << std::endl; 
   std::cout << "e: " << e << std::endl; 
   
   /* A<int, float> destructor called since c is a pointer */
   delete c;
   
   return 0; 
} 


