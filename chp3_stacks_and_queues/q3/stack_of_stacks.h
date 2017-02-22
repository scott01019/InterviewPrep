#ifndef STACK_OF_STACKS_H_
#define STACK_OF_STACKS_H_

#include "capacity_stack.h"

#include <iostream>
#include <vector>
using std::cout;
using std::vector;

class StackOfStacks {
	public:
		StackOfStacks();
		
		
		void push(int);
		int pop();
		int popAt(int);
		
		
		void print() const { 
			int i = 0;
			for (CapacityStack stack : stacks_) {
				cout << i << ": ";
				stack.print();
				++i;	
			} cout << "\n";
		}
	private:
		vector<CapacityStack> stacks_;
};

#endif	//	STACK_OF_STACKS_H_
