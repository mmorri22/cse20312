#include "../include/Lab04.h"


void test1(){
	
	COUT << "-------------------------" << ENDL;
	COUT << "Test 1: " << ENDL;
	
	VECTOR< VECTOR<int> > v = {{1,4},{6,9}};
	VECTOR<int> v1 = {2,5};
	
	COUT << "Inputs: " << ENDL;
	COUT << "Intervals: ";
	printVecVec( v );
	COUT << "Input Interval: ";
	printVector( v1 );
	
	COUT << ENDL << "Solution: " << ENDL;
	printVecVec( insert(v, v1) );	

}


void test2(){
	
	COUT << "-------------------------" << ENDL;
	COUT << "Test 2: " << ENDL;
	
	VECTOR< VECTOR<int> > v = {{1,3},{6,9}};
	VECTOR<int> v1 = {2,8};
	
	COUT << "Inputs: " << ENDL;
	COUT << "Intervals: ";
	printVecVec( v );
	COUT << "Input Interval: ";
	printVector( v1 );
	
	COUT << ENDL << "Solution: " << ENDL;
	printVecVec( insert(v, v1) );	

}


void test3(){
	
	COUT << "-------------------------" << ENDL;
	COUT << "Test 3: " << ENDL;
	
	VECTOR< VECTOR<int> > v = { {1,2}, {3,5}, {6,7}, {8,10}, {12,16} };
	VECTOR<int> v1 = {4,8};
	
	COUT << "Inputs: " << ENDL;
	COUT << "Intervals: ";
	printVecVec( v );
	COUT << "Input Interval: ";
	printVector( v1 );
	
	COUT << ENDL << "Solution: " << ENDL;
	printVecVec( insert(v, v1) );	

}

int main(){
	
	test1();
	
	test2();
	
	test3();

	return 0;
	
}