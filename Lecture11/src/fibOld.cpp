#include <iostream>
#include <sstream>

double Fib(int n){
	
	if(n == 0){
		return 1;
	}
	else if(n == 1){
		return 1;
	}
	
	return Fib(n-1) + Fib(n-2);
	
}

int main(int argc, char**argv){
	
	if(argc != 2){
		std::cerr << "Incorrect Number of inputs" << std::endl;
		exit(-1);
	}
	
	// stringstream used for the conversion initialized with the contents of argv[1]
	int factNum;
	std::stringstream convert(argv[1]);

	//give the value to factNum using the characters in the string
	if ( !(convert >> factNum) ){
		std::cerr << "Not a valid input" << std::endl;
		exit(-1);
	}
	
	std::cout << Fib( factNum ) << std::endl;
	return 0;
	
}
