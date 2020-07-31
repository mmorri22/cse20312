#ifndef DYNARR4_H
#define DYNARR4_H

template<class T>
class DynArr{
	
		private:
		
			unsigned int size; // Current number of elements
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
			DynArr(const int sizeIn = 0) :
				size(sizeIn),
				capac(sizeIn),
				data(new T[capac]) {}

			~DynArr(){
				
				delete [] data;
				
			}				
			
			// Copy Constructor
			DynArr(const DynArr<T>& C) : 
				size(C.size), capac(C.capac), data(new T[capac])
			{
				copy(data, C.data, C.size);
			}
			
			
			// Assignment Operator
			DynArr<T>& operator=(const DynArr<T>& assign){
				
				if(this != &assign){
					size = assign.size;
					capac = assign.capac;
					data = new T[capac];
					
					copy(data, assign.data, size);
				}
				
				return *this;
			}
				
};

#endif
