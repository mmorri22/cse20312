#ifndef DYNARR1_H
#define DYNARR1_H

template<class T>
class DynArr{
	
		private:
		
			unsigned int length; // Current number of elements
			unsigned int capac; // Current capacity
			T* data;
		
		public:
		
			// Dynamic Array Constructor
			DynArr(const int lengthIn = 0) :
				length(lengthIn),
				capac(lengthIn),
				data(new T[capac]) {}
				
};

#endif
