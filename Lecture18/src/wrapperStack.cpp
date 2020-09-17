#include "../include/stack.h"
#include <iostream>
#include <string>

template<class T>
void printInitial( stack<T> theStack ){
	
	std::cout << "The stack has an initial size of " << theStack.size();
	std::cout << " and a maximum size of " << theStack.max_size() << std::endl;	
}


template<class T>
void pushAndPrint( stack<T>& theStack, T elem ){
	
	std::cout << "Pushing " << elem << "... ";

	theStack.push( elem );
	
	std::cout << "The top element is now " << theStack.top() << std::endl;
}


template<class T>
void popAndPrint( stack<T>& theStack){
	
	if( !theStack.empty() ){
		std::cout << "Popping " << theStack.top() << "... ";
	}
	else{
		std::cout << "The stack is empty" << std::endl;
		return;
	}

	theStack.pop();
	
	if( !theStack.empty() ){
		std::cout << "The top element is now " << theStack.top() << std::endl;
	}
	else{
		std::cout << "The stack is now empty" << std::endl;
	}
}


int main(){
	
	stack<int> stack1;
	printInitial(stack1);
	
	pushAndPrint(stack1, 10);
	pushAndPrint(stack1, 15);
	pushAndPrint(stack1, -8);
	pushAndPrint(stack1, 45);

	popAndPrint(stack1);
	popAndPrint(stack1);
	popAndPrint(stack1);
	popAndPrint(stack1);
	
	std::cout << "---------------------" << std::endl;
	
	stack<std::string> stack2(5);
	printInitial(stack2);
	
	pushAndPrint(stack2, std::string("Cheer") );
	pushAndPrint(stack2, std::string("Cheer") );
	pushAndPrint(stack2, std::string("for") );
	pushAndPrint(stack2, std::string("Old") );
	pushAndPrint(stack2, std::string("Notre") );
	pushAndPrint(stack2, std::string("Dame") );
	popAndPrint(stack2);
	popAndPrint(stack2);
	popAndPrint(stack2);
	popAndPrint(stack2);
	popAndPrint(stack2);
	popAndPrint(stack2);
	
	return 0;
	
}