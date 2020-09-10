/**********************************************
* File: findCircular2.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
*  
**********************************************/

#include <iostream>
#include <unordered_map>

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
		
		//delete next;
		
	}
	

	/********************************************
	* Function Name  : node
	* Pre-conditions : const node& copy
	* Post-conditions: none
	*  
	* Rule of 3: Copy Constructor
	* Required for -weffc++ flag
	********************************************/
	node(const node& copy) : data(copy.data), next(copy.next) {}
	
	
	/********************************************
	* Function Name  : operator=
	* Pre-conditions : const node& assign
	* Post-conditions: node&
	*
	* Rule of 3: Assignment Operator
	* Required for -weffc++ flag 
	********************************************/
	node& operator=(const node& assign){
		
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
	node* operator=(const node* assign){
		
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
	bool operator!=(const node* rhs){
		
		return this != (void *)&rhs;
		
	}
	
};


void findCircularRace(node<int>& head, node<int> *nodeSlow, node<int> *nodeFast){
	
	// Reset the counting pointers 
	nodeSlow = &head;
	nodeFast = &head;
	
	// Include a previous node to track the Previous Value
	node<int> *nodePrev = nodeFast;
	
	while(nodeFast->next != NULL){
		
		nodeSlow = nodeSlow->next;
		nodePrev = nodeFast->next;
		nodeFast = nodeFast->next->next;

		if(nodeSlow == nodeFast){
			break;
		}
	}
	
	if(nodeSlow == nodeFast){
		
		// Reset slow to the Head node 
		nodeSlow = &head;
		
		// Iterate until the nodes are equal 
		while(nodeSlow != nodeFast){
			nodePrev = nodeFast;
			nodeSlow = nodeSlow->next;
			nodeFast = nodeFast->next;
		}
		
		std::cout << "Circular Link exists!" << std::endl;
		std::cout << "Origin of Circular Link: Address is " << (void *)&nodePrev 
			<< " with data " << nodePrev->data << std::endl;
			
		std::cout << "Destination of Circular Link: Address is " << (void *)&(nodeSlow)
			<< " with data " << nodeSlow->data << std::endl;
		
	}
	else{
		
		std::cout << "No loop in the list" << std::endl;
	}

}

int main(){
	
	// Create the nodes
	node<int> node1(10);
	node<int> node2(20);
	node<int> node3(30);
	node<int> node4(40);
	node<int> node4b(45);
	node<int> node5(32);
	
	// Make the circular list
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	node5.next = &node1;	// Circular occurs here
	
	// Go through the nodes
	node<int> *nodeSlow = new node<int>();
	node<int> *nodeFast = new node<int>();
	
	findCircularRace(node1, nodeSlow, nodeFast);
	
	// Make the circular list odd length
	node4.next = &node4b;
	node4b.next = &node5;
	std::cout << "---------------------------------------\n";
	findCircularRace(node1, nodeSlow, nodeFast);
	
	// Move the loop to the node3
	node5.next = &node3;
	std::cout << "---------------------------------------\n";
	findCircularRace(node1, nodeSlow, nodeFast);
	
	// Remove loop 
	node5.next = new node<int>();
	std::cout << "---------------------------------------\n";
	findCircularRace(node1, nodeSlow, nodeFast);
	
	return 0;
	
}
