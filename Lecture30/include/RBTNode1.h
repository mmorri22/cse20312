// Set the constructors and Rule of 3 for RBTNode struct

#ifndef RBTNODE1_H
#define RBTNODE1_H

#include <cstdlib>
#include <iostream> 
  
enum COLOR { RED, BLACK }; 
  
template<class T>
struct RBTNode {  
 
 	T value; // Data itself
  	COLOR color; // Indicates if red or black
  	RBTNode<T> *left, *right, *parent; // Keeps track of the nodes for rotation

	// Default constructor
  	RBTNode<T>() : value(), color(RED), left(NULL), right(NULL), parent(NULL) { } 

	// Overloaded Constructor
  	RBTNode<T>(T valueIn) : value(valueIn), color(RED), left(NULL), right(NULL), parent(NULL) { } 
	
	// Destructor
	~RBTNode() {}
	
	// Copy Constructor
	RBTNode<T>(const RBTNode<T>& copy){
		if(this != &copy){
			
			this->value = copy->value;
			this->color = copy->color;
		}
	}
	
	// Assignment Operator
	RBTNode<T>& operator=(const RBTNode<T>& assign){
		
		if(this != &assign){
			
			this->value = assign->value;
			this->color = assign->color;
		}
		return *this;
	}

}; 

#endif
