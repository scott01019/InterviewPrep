#include "capacity_stack.h"
#include "stack_of_stacks.h"

#include <vector>
using std::vector;

StackOfStacks::StackOfStacks() {
	stacks_.push_back(CapacityStack());
}

void StackOfStacks::push(int val) {
	if (!stacks_.back().full()) {
		stacks_.back().push(val);
	} else {
		stacks_.push_back(CapacityStack());
		stacks_.back().push(val);
	}
}

int StackOfStacks::pop() {
	int val;
	for (int i = stacks_.size() - 1; i >= 0; --i) {
		if (!stacks_[i].empty()) {
			val = stacks_[i].peek();
			stacks_[i].pop();
		}
	}
	return val;
}

int StackOfStacks::popAt(int index) {
	int val;
	if (!stacks_[index].empty()) {
		val = stacks_[index].peek();
		stacks_[index].pop();
	}
	return val;
}
