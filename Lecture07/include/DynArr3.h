#ifndef DYNARR3_H
#define DYNARR3_H

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
};

#endif
