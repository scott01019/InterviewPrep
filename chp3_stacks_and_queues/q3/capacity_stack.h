#ifndef CAPACITY_STACK_H_
#define CAPACITY_STACK_H_

#include <iostream>
#include <stack>
using std::cout;
using std::stack;

class CapacityStack {
	public:
		CapacityStack() : capacity_(10) {}
		int capacity() const { return capacity_; }
		bool empty() const { return stack_.empty(); }
		bool full() const { return stack_.size() == capacity_; }
		int peek() const;
		void pop();
		void push(int);
		void print(); 
		int size() const { return stack_.size(); }
	private:
		int capacity_;
		stack<int> stack_;
};

#endif	//	CAPACITY_STACK_H_
