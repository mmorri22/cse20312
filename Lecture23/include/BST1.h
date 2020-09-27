// Deliberate Compiler Error - Must have Assignment operator 

#ifndef BST1_H
#define BST1_H

#include "BSTNode2.h"
#include <iostream>

#define COUT std::cout
#define ENDL std::endl

template< class T >
class BST{
	
	private:
		
		BSTNode< T >* root;
		
	public: 
		
		BST() : root() {}
		
		~BST() { delete root; }
	
};

#endif