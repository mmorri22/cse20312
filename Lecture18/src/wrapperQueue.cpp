#include "../include/queue.h"
#include <iostream>
#include <string>

template<class T>
void printInitial( queue<T> theQueue ){
	
	std::cout << "The queue has an initial size of " << theQueue.size();
	std::cout << " and a maximum size of " << theQueue.max_size() << std::endl;	
}


template<class T>
void pushAndPrint( queue<T>& theQueue, T elem ){
	
	std::cout << "Pushing " << elem << "... ";

	theQueue.push( elem );
	
	std::cout << "The front element is now " << theQueue.front() << std::endl;
	std::cout << "The back element is now " << theQueue.back() << std::endl;

}


template<class T>
void popAndPrint( queue<T>& theQueue){
	
	if( !theQueue.empty() ){
		std::cout << "Popping " << theQueue.front() << "... ";
	}
	else{
		std::cout << "The queue is empty" << std::endl;
		return;
	}

	theQueue.pop();
	
	if( !theQueue.empty() ){
		std::cout << "The front element is now " << theQueue.front() << std::endl;
		std::cout << "The back element is now " << theQueue.back() << std::endl;
	}
	else{
		std::cout << "The queue is now empty" << std::endl;
	}
}


int main(){
	
	queue<int> queue1;
	printInitial(queue1);
	
	pushAndPrint(queue1, 10);
	pushAndPrint(queue1, 15);
	pushAndPrint(queue1, -8);
	pushAndPrint(queue1, 45);

	popAndPrint(queue1);
	popAndPrint(queue1);
	popAndPrint(queue1);
	popAndPrint(queue1);
	
	std::cout << "---------------------" << std::endl;
	
	queue<std::string> queue2(5);
	printInitial(queue2);
	
	pushAndPrint(queue2, std::string("Cheer") );
	pushAndPrint(queue2, std::string("Cheer") );
	pushAndPrint(queue2, std::string("for") );
	pushAndPrint(queue2, std::string("Old") );
	pushAndPrint(queue2, std::string("Notre") );
	pushAndPrint(queue2, std::string("Dame") );
	popAndPrint(queue2);
	popAndPrint(queue2);
	popAndPrint(queue2);
	popAndPrint(queue2);
	popAndPrint(queue2);
	
	return 0;
	
}