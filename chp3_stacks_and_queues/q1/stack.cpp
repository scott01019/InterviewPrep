#include "stack.h"

#include <iostream>
using std::cout;

int Stack::pop0() {
	if (top0 > -1) {
		int val = stack[top0];
		top0 -= 3;
		return val;
	} else return -999999;
}

int Stack::pop1() {
	if (top1 > 0) {
		int val = stack[top1];
		top1 -= 3;
		return val;
	} else return -999999;
}

int Stack::pop2() {
	if (top2 > 1) {
		int val = stack[top2];
		top2 -= 3;
		return val;
	} else return -999999;
}

void Stack::print() {
	for (int i = 0; i < top0; i += 3) {
		cout << stack[i] << " ";
	} cout << "\n";

	for (int i = 1; i < top1; i += 3) {
		cout << stack[i] << " ";
	} cout << "\n";

	for (int i = 2; i < top2; i += 3) {
		cout << stack[i] << " ";
	}	cout << "\n";
}

void Stack::push0(int val) {
	if (top0 < 100) {
		top0 += 3;
		stack[top0] = val;
	}
}

void Stack::push1(int val) {
	if (top1 < 101) {
		top1 += 3;
		stack[top1] = val;
	}
}

void Stack::push2(int val) {
	if (top2 < 102) {
		top2 += 3;
		stack[top2] = val;
	}
}
