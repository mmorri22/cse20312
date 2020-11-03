/**********************************************
* File: QuadraticProbing.h
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
*  
**********************************************/
#ifndef QUADRATIC_PROBING_H
#define QUADRATIC_PROBING_H

#include "QuadraticHash.h"

#include <vector>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;

int nextPrime( int n );

enum EntryType { ACTIVE, EMPTY, DELETED };

// QuadraticProbing Hash table class

template <typename HashedObj>
class HashTable
{
	private:
		struct HashEntry
		{
			HashedObj element;
			EntryType info;

			/********************************************
			* Function Name  : HashEntry
			* Pre-conditions :  const HashedObj & e = HashedObj{ }, EntryType i = EMPTY 
			* Post-conditions: none
			*  
			********************************************/
			HashEntry( const HashedObj & e = HashedObj{ }, EntryType i = EMPTY )
			  : element{ e }, info{ i } { }
			
			/********************************************
			* Function Name  : HashEntry
			* Pre-conditions :  HashedObj && e, EntryType i = EMPTY 
			* Post-conditions: none
			*  
			********************************************/
			HashEntry( HashedObj && e, EntryType i = EMPTY )
			  : element{ std::move( e ) }, info{ i } { }
		};
		
		vector<HashEntry> array;
		int currentSize;

		/********************************************
		* Function Name  : isActive
		* Pre-conditions :  int currentPos 
		* Post-conditions: bool
		*  
		********************************************/
		bool isActive( int currentPos ) const
		  { return array[ currentPos ].info == ACTIVE; }

		/********************************************
		* Function Name  : findPos
		* Pre-conditions :  const HashedObj & x 
		* Post-conditions: int
		* 
		* Performs Quadratic Probing with 
		* c1 = 0.5 and c2 = 0.5
		********************************************/
		int findPos( const HashedObj & x ) const
		{
			int offset = 1;
			int currentPos = myhash( x );
			double iter = 1;

			while( array[ currentPos ].info != EMPTY &&
				   array[ currentPos ].element != x )
			{
				double off = 0.5*iter + 0.5*iter*iter;
				currentPos = (currentPos + (int)off) % array.size();
				iter++;
			}

			return currentPos;
		}

		/********************************************
		* Function Name  : rehash
		* Pre-conditions :  
		* Post-conditions: none
		*  
		********************************************/
		void rehash( )
		{
			vector<HashEntry> oldArray = array;

				// Create new double-sized, empty table
			array.resize( nextPrime( 2 * oldArray.size( ) ) );
			for( auto & entry : array )
				entry.info = EMPTY;

				// Copy table over
			currentSize = 0;
			for( auto & entry : oldArray )
				if( entry.info == ACTIVE )
					insert( std::move( entry.element ) );
		}

		/********************************************
		* Function Name  : myhash
		* Pre-conditions :  const HashedObj & x 
		* Post-conditions: size_t
		*  
		********************************************/
		size_t myhash( const HashedObj & x ) const
		{
			static hash<HashedObj> hf;
			return hf( x ) % array.size( );
		}
	
  public:
    /********************************************
    * Function Name  : nextPrime
    * Pre-conditions :  size ) 
    * Post-conditions: explicit HashTable( int size = 101 ) : array(
    *  
    ********************************************/
    // explicit HashTable( int size ) : array( nextPrime( size ) )
	explicit HashTable( int size ) : array( size )
      {} //makeEmpty( ); }

    /********************************************
    * Function Name  : contains
    * Pre-conditions :  const HashedObj & x 
    * Post-conditions: bool
    *  
    ********************************************/
    bool contains( const HashedObj & x ) const
    {
        return isActive( findPos( x ) );
    }

    /********************************************
    * Function Name  : makeEmpty
    * Pre-conditions :  
    * Post-conditions: none
    *  
    ********************************************/
    void makeEmpty( )
    {
        currentSize = 0;
        for( auto & entry : array )
            entry.info = EMPTY;
    }

    /********************************************
    * Function Name  : insert
    * Pre-conditions :  const HashedObj & x 
    * Post-conditions: bool
    *  
    ********************************************/
    bool insert( const HashedObj & x )
    {
            // Insert x as active
        int currentPos = findPos( x );
        if( isActive( currentPos ) )
            return false;

        if( array[ currentPos ].info != DELETED )
            ++currentSize;

        array[ currentPos ].element = x;
        array[ currentPos ].info = ACTIVE;

            // Rehash; see Section 5.5
        //if( currentSize > array.size( ) / 2 ) 
            //rehash( );

        return true;
    }
    
    /********************************************
    * Function Name  : insert
    * Pre-conditions :  HashedObj && x 
    * Post-conditions: bool
    *  
    ********************************************/
    bool insert( HashedObj && x )
    {
            // Insert x as active
        int currentPos = findPos( x );
        if( isActive( currentPos ) )
            return false;

        if( array[ currentPos ].info != DELETED )
            ++currentSize;

        array[ currentPos ] = std::move( x );
        array[ currentPos ].info = ACTIVE;

            // Rehash; see Section 5.5
        //if( currentSize > array.size( ) / 2 )
            //rehash( );

        return true;
    }

    /********************************************
    * Function Name  : remove
    * Pre-conditions :  const HashedObj & x 
    * Post-conditions: bool
    *  
    ********************************************/
    bool remove( const HashedObj & x )
    {
        int currentPos = findPos( x );
        if( !isActive( currentPos ) )
            return false;

        array[ currentPos ].info = DELETED;
        return true;
    }
	
		std::ostream& printHash(std::ostream &out){
			
			for(int i = 0; i < array.size(); i++){
				
				out << i << " -> " << array[i].element << std::endl;
				
			}
			
			return out;
			
		}

};

#endif
