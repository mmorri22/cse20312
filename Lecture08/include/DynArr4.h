#ifndef DYNARR4_H
#define DYNARR4_H

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
				length(0),
				capac(lengthIn),
				data(new T[capac]) {}

			~DynArr(){
				
				delete [] data;
				
			}				
			
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
				
};

#endif
