#ifndef STACK_H_
#define STACK_H_

#include <iostream>
using std::cout;

struct Node {
	int min_;
	int val_;
	Node *next_;
};

class Stack {
	public:
		Stack();
		int min();
		int peek();
		int pop();
		void print() {
			Node* node = top_;
			while (node != bot_) {
				cout << node->val_ << " ";
				node = node->next_;
			} cout << "\n";
		}
		void push(int);
	private:
		Node * top_;
		Node * const bot_ = new Node();
};

#endif	//	STACK_H_
