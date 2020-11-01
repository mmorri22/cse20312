/**********************************************
* File: CuckooHashTable.h
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
*  
**********************************************/
#ifndef CUCKOO_HASH_TABLE_H
#define CUCKOO_HASH_TABLE_H

#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include "UniformRandom.h"
using namespace std;

template <typename AnyType>
class CuckooHashFamily
{
  public:
    /********************************************
    * Function Name  : hash
    * Pre-conditions :  const AnyType & x, int which 
    * Post-conditions: size_t
    *  
    ********************************************/
    size_t hash( const AnyType & x, int which ) const;

    /********************************************
    * Function Name  : getNumberOfFunctions
    * Pre-conditions :  
    * Post-conditions: int
    *  
    ********************************************/
    int getNumberOfFunctions( );

    /********************************************
    * Function Name  : generateNewFunctions
    * Pre-conditions :  
    * Post-conditions: none
    *  
    ********************************************/
    void generateNewFunctions( );
};

template <int count>
class StringHashFamily
{
  public:
    /********************************************
    * Function Name  : MULTIPLIERS
    * Pre-conditions :  count 
    * Post-conditions: StringHashFamily( ) :
    *  
    ********************************************/
    StringHashFamily( ) : MULTIPLIERS( count )
    {
        generateNewFunctions( );
    }
    
    /********************************************
    * Function Name  : getNumberOfFunctions
    * Pre-conditions :  
    * Post-conditions: int
    *  
    ********************************************/
    int getNumberOfFunctions( ) const
    {
        return count;
    }
    
    /********************************************
    * Function Name  : generateNewFunctions
    * Pre-conditions :  
    * Post-conditions: none
    *  
    ********************************************/
    void generateNewFunctions( )
    {
        for( auto & mult : MULTIPLIERS )
            mult = r.nextInt( );
    }
    
    /********************************************
    * Function Name  : hash
    * Pre-conditions :  const string & x, int which 
    * Post-conditions: size_t
    *  
    ********************************************/
    size_t hash( const string & x, int which ) const
    {
        const int multiplier = MULTIPLIERS[ which ];
        size_t hashVal = 0;

        for( auto ch : x )
            hashVal = multiplier * hashVal + ch;
        
        return hashVal;
    }

  private:
    vector<int> MULTIPLIERS;
    UniformRandom r;
};



int nextPrime( int n );


#define MAX_LOAD 0.40  /* g++ 4.6 does not support static const double */

// CuckooHashing Hash table class
//
// CONSTRUCTION: an approximate initial size or default of 101
//
// ******************PUBLIC OPERATIONS*********************
// bool insert( x )       --> Insert x
// bool remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// void makeEmpty( )      --> Remove all items
// int hashCode( string str ) --> Global method to hash strings

template <typename AnyType, typename HashFamily>
class HashTable
{
  public:
    /********************************************
    * Function Name  : nextPrime
    * Pre-conditions :  size ) 
    * Post-conditions: explicit HashTable( int size = 101 ) : array(
    *  
    ********************************************/
    explicit HashTable( int size = 101 ) : array( nextPrime( size ) )
    {
        numHashFunctions = hashFunctions.getNumberOfFunctions( );
        rehashes = 0;
        makeEmpty( );
    }

    /********************************************
    * Function Name  : contains
    * Pre-conditions :  const AnyType & x 
    * Post-conditions: bool
    *  
    ********************************************/
    bool contains( const AnyType & x ) const
    {
        return findPos( x ) != -1;
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
            entry.isActive = false;
    }

    /********************************************
    * Function Name  : insert
    * Pre-conditions :  const AnyType & x 
    * Post-conditions: bool
    *  
    ********************************************/
    bool insert( const AnyType & x )
    {
        if( contains( x ) ) 
            return false;
        
        if( currentSize >= array.size( ) * MAX_LOAD )
            expand( );
        
        return insertHelper1( x );
    }
    
    /********************************************
    * Function Name  : insert
    * Pre-conditions :  AnyType && x 
    * Post-conditions: bool
    *  
    ********************************************/
    bool insert( AnyType && x )
    {
        if( contains( x ) ) 
            return false;
        
        if( currentSize >= array.size( ) * MAX_LOAD )
            expand( );
        
        return insertHelper1( std::move( x ) );
    }

    /********************************************
    * Function Name  : size
    * Pre-conditions :  
    * Post-conditions: int
    *  
    ********************************************/
    int size( ) const
    {
        return currentSize;
    }
    
    /********************************************
    * Function Name  : capacity
    * Pre-conditions :  
    * Post-conditions: int
    *  
    ********************************************/
    int capacity( ) const
    {
        return array.size( );
    }
    
    /********************************************
    * Function Name  : remove
    * Pre-conditions :  const AnyType & x 
    * Post-conditions: bool
    *  
    ********************************************/
    bool remove( const AnyType & x )
    {
        int currentPos = findPos( x );
        if( !isActive( currentPos ) )
            return false;

        array[ currentPos ].isActive = false;
        return true;
    }

  private:
      
    struct HashEntry
    {
        AnyType element;
        bool isActive;

        /********************************************
        * Function Name  : AnyType
        * Pre-conditions :  ), bool a = false 
        * Post-conditions: HashEntry( const AnyType & e =
        *  
        ********************************************/
        HashEntry( const AnyType & e = AnyType( ), bool a = false )
          : element{ e }, isActive{ a } { }    

        /********************************************
        * Function Name  : HashEntry
        * Pre-conditions :  AnyType && e, bool a = false 
        * Post-conditions: none
        *  
        ********************************************/
        HashEntry( AnyType && e, bool a = false )
          : element{ std::move( e ) }, isActive{ a } { }
    };
    
    vector<HashEntry> array;
    int currentSize;
    int numHashFunctions;
    int rehashes;
    UniformRandom r;
    HashFamily hashFunctions;

  //  static const double MAX_LOAD = 0.40;  // Not supported in g++ 4.6
    static const int ALLOWED_REHASHES = 5;
    
    /********************************************
    * Function Name  : insertHelper1
    * Pre-conditions :  const AnyType & xx 
    * Post-conditions: bool
    *  
    ********************************************/
    bool insertHelper1( const AnyType & xx )
    {
        const int COUNT_LIMIT = 100;
        AnyType x = xx;
        
        while( true )
        {
            int lastPos = -1;
            int pos;
            
            for( int count = 0; count < COUNT_LIMIT; ++count )
            {
                for( int i = 0; i < numHashFunctions; ++i )
                {
                    pos = myhash( x, i );
                    
                    if( !isActive( pos ) )
                    {
                        array[ pos ] = std::move( HashEntry{ std::move( x ), true } );
                        ++currentSize;
                        return true;
                    }
                }
                
                // None of the spots are available. Kick out random one
                int i = 0;
                do
                {
                    pos = myhash( x, r.nextInt( numHashFunctions ) );
                } while( pos == lastPos && i++ < 5 );
              
                lastPos = pos;
                std::swap( x, array[ pos ].element );
            }
            
            if( ++rehashes > ALLOWED_REHASHES )
            {
                expand( );     // Make the table bigger
                rehashes = 0;
            }
            else
                rehash( );
        }
    }
    
    /********************************************
    * Function Name  : insertHelper1
    * Pre-conditions :  AnyType && x 
    * Post-conditions: bool
    *  
    ********************************************/
    bool insertHelper1( AnyType && x )
    {
        const int COUNT_LIMIT = 100;
        
        while( true )
        {
            int lastPos = -1;
            int pos;
            
            for( int count = 0; count < COUNT_LIMIT; ++count )
            {
                for( int i = 0; i < numHashFunctions; ++i )
                {
                    pos = myhash( x, i );
                    
                    if( !isActive( pos ) )
                    {
                        array[ pos ] = std::move( HashEntry{ std::move( x ), true } );
                        ++currentSize;
                        return true;
                    }
                }
                
                // None of the spots are available. Kick out random one
                int i = 0;
                do
                {
                    pos = myhash( x, r.nextInt( numHashFunctions ) );
                } while( pos == lastPos && i++ < 5 );
              
                lastPos = pos;
                std::swap( x, array[ pos ].element );
            }
            
            if( ++rehashes > ALLOWED_REHASHES )
            {
                expand( );     // Make the table bigger
                rehashes = 0;
            }
            else
                rehash( );
        }
    }

    /********************************************
    * Function Name  : isActive
    * Pre-conditions :  int currentPos 
    * Post-conditions: bool
    *  
    ********************************************/
    bool isActive( int currentPos ) const
      {  return currentPos != -1 &&  array[ currentPos ].isActive; }

    // Method that search all hash function places
    /********************************************
    * Function Name  : findPos
    * Pre-conditions :  const AnyType & x 
    * Post-conditions: int
    *  
    ********************************************/
    int findPos( const AnyType & x ) const
    {
        for( int i = 0; i < numHashFunctions; ++i )
        {
            int pos = myhash( x, i );
            
            if( isActive( pos ) && array[ pos ].element == x )
                return pos;
        }

        return -1;
    }

    /********************************************
    * Function Name  : expand
    * Pre-conditions :  
    * Post-conditions: none
    *  
    ********************************************/
    void expand( )
    {
        rehash( static_cast<int>( array.size( ) / MAX_LOAD ) );
    }
    
    /********************************************
    * Function Name  : rehash
    * Pre-conditions :  
    * Post-conditions: none
    *  
    ********************************************/
    void rehash( )
    {
        hashFunctions.generateNewFunctions( );
        rehash( array.size( ) );
    }
    
    /********************************************
    * Function Name  : rehash
    * Pre-conditions :  int newSize 
    * Post-conditions: none
    *  
    ********************************************/
    void rehash( int newSize )
    {
        vector<HashEntry> oldArray = array;

            // Create new double-sized, empty table
        array.resize( nextPrime( newSize ) );
        for( auto & entry : array )
            entry.isActive = false;
        
            // Copy table over
        currentSize = 0;
        for( auto & entry : oldArray )
            if( entry.isActive )
                insert( std::move( entry.element ) );
    }
    
    
    /********************************************
    * Function Name  : myhash
    * Pre-conditions :  const AnyType & x, int which 
    * Post-conditions: size_t
    *  
    ********************************************/
    size_t myhash( const AnyType & x, int which ) const
    {
        return hashFunctions.hash( x, which ) % array.size( );
    }
};


#endif
