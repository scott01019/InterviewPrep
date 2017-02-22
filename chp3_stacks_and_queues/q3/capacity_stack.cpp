#include "capacity_stack.h"

#include <iostream>
#include <stack>
#include <vector>
using std::cout;
using std::stack;
using std::vector;

int CapacityStack::peek() const { return stack_.top(); }

void CapacityStack::pop() { 
	if (!stack_.empty()) stack_.pop();
}

void CapacityStack::push(int val) {
	if (!full()) stack_.push(val);
}

void CapacityStack::print() {
	for (stack<int> dump = stack_; !dump.empty(); dump.pop())
		cout << dump.top() << " ";
	cout << "\n";
}
