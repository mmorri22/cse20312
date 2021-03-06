#ifndef DYNARR2_H
#define DYNARR2_H

template<class T>
class DynArr{
	
		private:
		
			unsigned int length; // Current number of elements
			unsigned int capac; // Current capacity
			T* data;
		
		public:
		
			// Dynamic Array Constructor
			DynArr(const int lengthIn = 0) :
				length(0),
				capac(lengthIn),
				data(new T[capac]) {}


			~DynArr(){
				
				delete [] data;
				
			}	
};

#endif
