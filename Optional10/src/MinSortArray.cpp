#include <iostream>
#include <vector>

template< class T >
void printVec( std::vector< T >& printVec ){
	
	for( T& printVal : printVec ){
		
		std::cout << printVal << " ";
		
	}
}

template< class T >
T findMin( std::vector< T >& testVec, long unsigned int min, long unsigned int max ){
	
	std::cout << "curr min = " << testVec.at(min) << ", curr max = " << testVec.at(max) << std::endl;
	
	if( min == max ){
		return testVec.at(min);
	}
	
	long unsigned int mid = (max + min) / 2;
	
	if( testVec.at( min ) < testVec.at( mid ) ){
		
		T comp = findMin( testVec, mid, max );
		
		return ( testVec.at( min ) < comp ) ? testVec.at( min ) : comp ;
	}

	else if( testVec.at( max ) > testVec.at( mid ) ){
		
		T comp = findMin( testVec, min, mid );
		
		return ( testVec.at( max ) < comp ) ? testVec.at( max ) : comp ;		
	}
	
	else if( testVec.at( min ) == testVec.at( mid ) ){
		
		T comp = findMin( testVec, min + 1, mid );
		
		return ( testVec.at( min ) < comp ) ? testVec.at( min ) : comp ;			
	}
	else{	// testVec.at( max ) == testVec.at( mid )
		
		T comp = findMin( testVec, mid, max - 1 );
		
		return ( testVec.at( max ) < comp ) ? testVec.at( max ) : comp ;			
	}
}

template< class T >
void runTest( std::vector< T >& test ){
	
	std::cout << "---------------------" << std::endl;
	
	std::cout << "Recursive calls:" << std::endl;
	
	T result = findMin( test, 0, test.size() - 1 );
	
	std::cout << "The array { ";
	
	printVec( test );
	
	std::cout << "} has a minimum value of ";
	
	std::cout << result << std::endl;
}

int main(){
	
	std::vector< int > test1{ 4,5,6,7,0,1,2,3 };
	
	std::vector< unsigned int > test2{ 0,1,2,3,4,5,6,7 };
	
	std::vector< int > test3{ 3,4,5,1,2 };
	
	std::vector< int > test4{ 5, 6, 7, 8, 9, 0, 1, 2, 3, 4 };
	
	std::vector< unsigned int > test5{ 7, 8, 9, 0, 1, 2, 3, 4, 5, 6 };
	
	std::vector< unsigned int > test6{ 11, 12, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	std::vector< char > test7{ 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'b', 'c', 'd' };

	runTest( test1 );
	
	runTest( test2 );
	
	runTest( test3 );
	
	runTest( test4 );
	
	runTest( test5 );
	
	runTest( test6 );
	
	runTest( test7 );
	
	std::vector< unsigned int > testLarge;
	
	unsigned int initial = 12;
	for( unsigned int iter = 0; iter < 1000; iter++ ){
		
		if( initial == 1000 ){
			
			initial = 0;
		}
		
		testLarge.push_back( initial++ );
		
	}
	
	runTest( testLarge );
}