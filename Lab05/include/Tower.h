#ifndef TOWER_H
#define TOWER_H

#include "stack.h"

class Tower{
	
	private:
		int towerNum;
	
	public:
		stack<int> theStack;
		
		Tower(int tNum) : towerNum(tNum), theStack() {}
		
		int getTowerNum(){
			return towerNum;
		}
	
};

#endif
