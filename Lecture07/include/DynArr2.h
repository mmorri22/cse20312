#ifndef DYNARR2_H
#define DYNARR2_H

template<class T>
class DynArr{
	
		private:
		
			unsigned int size; // Current number of elements
			unsigned int capac; // Current capacity
			T* data;
		
		public:
		
			// Dynamic Array Constructor
			DynArr(const int sizeIn = 0) :
				size(sizeIn),
				capac(sizeIn),
				data(new T[capac]) {}
				
};

#endif
