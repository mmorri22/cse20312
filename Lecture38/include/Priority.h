#ifndef PRIORITY_H
#define PRIORITY_H 

template<class T>
class Priority{
	
	private:
		T element;
		int weight;
	
	public:
	
		Priority( ) : element( ), weight( ) {}
		
		Priority( T elementIn, int weightIn ) : element( elementIn ), weight( weightIn ) {}
		
		~Priority(){}
		
		Priority( const Priority<T>& rhs ) : element( rhs.element ), weight( rhs.weight ) {}
		
		Priority<T>& operator=( const Priority<T>& rhs ){
			
			if( this != &rhs ){
				this->element = rhs.element;
				this->weight = rhs.weight;
			}
			return *this;
		}
		
		bool operator>=( const Priority<T>& rhs ) const{
			return weight >= rhs.weight;
		}
		
		bool operator>( const Priority<T>& rhs ) const{
			return weight > rhs.weight;
		}
		
		bool operator<=( const Priority<T>& rhs ) const{
			return weight <= rhs.weight;
		}
		
		bool operator<( const Priority<T>& rhs ) const{
			return weight < rhs.weight;
		}
		
		bool operator==( const Priority<T>& rhs ) const{
			return weight == rhs.weight;
		}
		
		friend std::ostream& operator<<( std::ostream& output, const Priority<T>& thePriority ){
			
			output << "{" << thePriority.element << ", " << thePriority.weight << "}";
			
			return output;
			
		}
	
};

#endif