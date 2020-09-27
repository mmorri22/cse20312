#ifndef DOUBLEHASH_H
#define DOUBLEHASH_H

#include "LinearProbe.h"

template<class Key, class Value>
class DoubleHash : public HashTable<Key, Value>{
	
	private:

		// Translate to unsigned int for int
		long unsigned int HashFunc1( const int& keyToTranslate ) const{
				
			if (keyToTranslate < 0){
				return (long unsigned int)(-1 * keyToTranslate);
			}
			
			return (long unsigned int) keyToTranslate;
			
		}
		
		// Translate to unsigned int for int
		long unsigned int HashFunc2( const int& keyToTranslate ) const{
				
			if (keyToTranslate < 0){
				return (long unsigned int)(-1 * keyToTranslate);
			}
			
			return (long unsigned int) (3 - keyToTranslate % 3);
			
		}

		// Translate to long unsigned int for std::string		
		long unsigned int HashFunc1( const std::string& keyToTranslate ) const{
			
			return keyToTranslate.size();
			
		}

		// Translate to long unsigned int for std::string		
		long unsigned int HashFunc2( const std::string& keyToTranslate ) const{
			
			return 3 - keyToTranslate.size() % 3 ;
			
		}
		
		
		long unsigned int findPos( const Key& theKey ) const{
			
			long unsigned int currentPos;
			long unsigned int iter = 0;
			const long unsigned int STEPSIZE = 1;
			
			do{
				// Hash Function determines current position
				long unsigned int intermediate1 = HashFunc1(theKey)%this->array.capacity();
				long unsigned int intermediate2 = iter*HashFunc2(theKey);
				
				currentPos = ( intermediate1 + intermediate2 + iter * STEPSIZE) % this->array.capacity();
				++iter;
			}
			while(
				this->array.at( currentPos ).state != EMPTY
				&& this->array.at( currentPos ).state != DELETED
				&& this->array.at( currentPos ).key != theKey
				&& iter < this->array.capacity()
			);
			
			// Return capacity if the current value isn't the key. For safety
			if(this->array.at( currentPos ).state == ACTIVE 
				&& this->array.at( currentPos ).key != theKey ){
					
					return this->array.capacity();
					
				}
			
			return currentPos;
			
		}
	
	
	public:
	
		// Constructor
		DoubleHash(const unsigned int size = 0) : HashTable<Key, Value>(size) {}
		
		
		// Overloaded Friend Operator
		friend std::ostream& operator<<( std::ostream& output, const DoubleHash<Key, Value>& theTable ){
			
			output << "Hash Table Size: " << theTable.array.size() << std::endl;
			output << "Hashed Elements: " << theTable.numHash << std::endl;
			
			for(unsigned int iter = 0; iter < theTable.array.size(); iter++){
				
				output << "{" << iter << ": ";
				
				if( theTable.array[iter].state == ACTIVE ){
				
					output << "ACTIVE, ";
				
				}
				else if( theTable.array[iter].state == DELETED ){
				
					output << "DELETED, ";
				
				}
				else{
					
					output << "EMPTY, ";
				}
				
				output << theTable.array[iter].key << ", ";
				
				output << theTable.array[iter].value << "}" << std::endl;
				
			}
			
			return output;
		}
	
};


#endif