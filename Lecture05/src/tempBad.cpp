#include "../src/A.h"

int main()  { 

   const A<char, char> a('G', 72); 
   A<char, char> b(71, 'H'); 
   A<int, int> c(10, (float)-35.7); 
   
   std::cout << "a: " << a << std::endl;
   std::cout << "b: " << b << std::endl;  
   std::cout << "c: " << c << std::endl;  
   
   /* Cannot compare since types do not match */
   if(a == c){
	   std::cout << "a == c" << std::endl;
   }
   
   b.setX(31); 
   /* Set will not work since float is not a valid char type */
   b.setY( (float)18.231 );
   std::cout << "b: " << b << std::endl;  
   
   return 0; 
} 
