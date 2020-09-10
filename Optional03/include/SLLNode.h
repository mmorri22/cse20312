#ifndef SLLNODE_H
#define SLLNODE_H

#include <cstdlib>
#include <iostream>

/* NODE contains the data and a pointer to the next node */
template< class T >
struct node
{
	T     data;
	node<T>* next;
	
	/********************************************
	* Function Name  : checkMemory
	* Pre-conditions : none
	* Post-conditions: none
	* 
	* Checks to see if the *this pointer is 
	* pointing to a valid memory location.
	* Terminates program if not to prevent stack overfloe 
	********************************************/
	void checkMemory(){
		
		if (this == NULL)
		{
			std::cerr <<  "Out of Memory" << std::endl;
			exit (-1);
		} 
		
	}
	
	/********************************************
	* Function Name  : node
	* Pre-conditions : none
	* Post-conditions: none
	* 
	* Node Struct Default Constructor 
	********************************************/
	node() : data(), next(NULL) {
		
		// Check to ensure address properly allocated
		checkMemory();
		
	}
	
	
	/********************************************
	* Function Name  : node
	* Pre-conditions : none
	* Post-conditions: none
	* 
	* Node Struct Overloaded Constructor with data input 
	********************************************/
	node(T dataIn) : data(dataIn), next(NULL) {
		
		// Check to ensure address properly allocated				
		checkMemory();
		
	}
	

	/********************************************
	* Function Name  : ~node
	* Pre-conditions : none
	* Post-conditions: none
	*  
	* Delete operator required for PQC since it contains a 
	* private member which is a pointer
	********************************************/
	~node(){
		
		delete next;
		
	}
	

	/********************************************
	* Function Name  : node
	* Pre-conditions : const node& copy
	* Post-conditions: none
	*  
	* Rule of 3: Copy Constructor
	* Required for -weffc++ flag
	********************************************/
	node(const node<T>& copy){
		data = copy.data;
		next = copy.next;
	}
	
	
	/********************************************
	* Function Name  : operator=
	* Pre-conditions : const node& assign
	* Post-conditions: node&
	*
	* Rule of 3: Assignment Operator
	* Required for -weffc++ flag 
	********************************************/
	node<T>& operator=(const node<T>& assign){
		
		if(this != &assign){
			this->data = assign.data;
			this->next = assign.next;
		}
		return *this;
	}
	
	
	/********************************************
	* Function Name  : operator=
	* Pre-conditions : const node* assign
	* Post-conditions: node*
	* 
	* Assignment Operator for Pointer
	* Required for pointer assignment in SLList
	********************************************/
	node<T>* operator=(const node<T>* assign){
		
		if(this != (void *)&assign){
			this->data = assign->data;
			this->next = assign->next;
		}
		return *this;
	}
	
	
	/********************************************
	* Function Name  : operator!=
	* Pre-conditions : const node* rhs
	* Post-conditions: bool
	*  
	* != Operator for Pointer
	* Required for pointer comparison in SLList
	********************************************/
	bool operator!=(const node<T>* rhs){
		
		return this != (void *)&rhs;
		
	}
	
};
		
#endif