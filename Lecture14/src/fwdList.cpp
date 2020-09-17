/**********************************************
* File: fwdList.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Contains an example of std::forward_list
* which implements a Singly Linked List 
**********************************************/

#include<iostream> 
#include<forward_list>  // Implement Singly Linked List

template<class T>
void printValues(std::forward_list<T>& theList){
	std::cout << "The elements are : "; 
	
    for (T& a : theList) 
        std::cout << a << " "; 
	
    std::cout << std::endl; 
}

int main(){
	
    // Declaring forward list int
    std::forward_list<int> flistInt; 
	
    // Declaring forward list std::string
    std::forward_list< std::string > flistStr; 
  
    // Assigning values using assign() 
    flistInt.assign({1, 2, 3}); 
	printValues(flistInt);
	flistInt.push_front(4);  flistInt.push_front(5);
	printValues(flistInt);
	
	// Push on the front of the std::string list
	flistStr.push_front("Irish"); flistStr.push_front("Go");
	printValues(flistStr);
	
	// Delete the first element 
	flistInt.pop_front();
    printValues(flistInt);

	return 0;
}
