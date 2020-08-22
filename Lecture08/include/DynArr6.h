#ifndef DYNARR6_H
#define DYNARR6_H

template<class T>
class DynArr{
	
		private:
		
			unsigned int length; // Current number of elements
			unsigned int capac; // Current capacity
			T* data;

			// Added private method for use by copy constructor
			// and the assignment operator
			void copy(T* destin, T* origin, int len){
				
				for(unsigned int iter = 0; iter < len; ++iter){
					
					*(destin+iter) = origin[iter];
				}
			}

		public:
		
			// Dynamic Array Constructor
			DynArr(const int lengthIn = 0) :
				length(lengthIn),
				capac(lengthIn),
				data(new T[capac]) {}
				
			
			// Copy Constructor
			DynArr(const DynArr<T>& C) : 
				length(C.length), capac(C.capac), data(new T[capac])
			{
				copy(data, C.data, C.length);
			}
			
			
			// Assignment Operator
			DynArr<T>& operator=(const DynArr<T>& assign){
				
				if(this != &assign){
					length = assign.length;
					capac = assign.capac;
					data = new T[capac];
					
					copy(data, assign.data, length);
				}
				
				return *this;
			}

			// Operators for the Dynamic Array 
			T& begin(){
				
				return data[0];
			}
			
			const T& begin() const{
				
				return data[0];
			}

			T& end(){
				
				return data[length - 1];
			}
			
			const T& end() const{
				
				return data[length-1];
			}	
			
			unsigned int size() const{
				return length;
			}
			
			unsigned int capacity() const{
				return capac;
			}
			
			T& operator[](const unsigned int i){
				
				return data[i];
			}
			
			const T& operator[](const unsigned int i) const{
				
				return data[i];
			}

};

#endif
