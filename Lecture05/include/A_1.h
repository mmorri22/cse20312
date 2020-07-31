#ifndef A_1_H
#define A_1_H

#include <iostream>

template<class T, class U>
class A{
	
	private:
		T x;
		U y;
		
	public:
	
		/* Default constructor */
		A() : x(), y() {
			std::cout << "Address of object on the heap: " << this << std::endl;
		}
		
		/* Overloaded Constructor */
		A(T inX, U inY) : x(inX), y(inY) {
			std::cout << "Address of object on the heap: " << this << std::endl;
		}
		
};

#endif

