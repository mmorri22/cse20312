/**********************************************
* File: QuadraticProbing.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
*  
**********************************************/
#include "QuadraticProbing.h"
#include <iostream>
using namespace std;

/********************************************
* Function Name  : isPrime
* Pre-conditions :  int n 
* Post-conditions: bool
* 
* Internal method to test if a positive number is prime.
* Not an efficient algorithm. 
********************************************/
bool isPrime( int n )
{
    if( n == 2 || n == 3 )
        return true;

    if( n == 1 || n % 2 == 0 )
        return false;

    for( int i = 3; i * i <= n; i += 2 )
        if( n % i == 0 )
            return false;

    return true;
}

/********************************************
* Function Name  : nextPrime
* Pre-conditions :  int n 
* Post-conditions: int
*
* Internal method to return a prime number at least as large as n.
* Assumes n > 0. 
********************************************/
int nextPrime( int n )
{
    if( n % 2 == 0 )
        ++n;

    for( ; !isPrime( n ); n += 2 )
        ;

    return n;
}
