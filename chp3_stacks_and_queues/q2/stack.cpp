#include "stack.h"

Stack::Stack() {
	bot_->next_ = nullptr;
	bot_->min_ = 9999999;
	top_ = bot_;
}

int Stack::min() {
	if (top_ != bot_) {
		return top_->min_;
	} else return -999999;
}

int Stack::peek() {
	if (top_ != bot_) {
		return top_->val_;
	} else return -999999;
}

int Stack::pop() {
	if (top_ != bot_) {
		int val = top_->val_;
		top_ = top_->next_;
		return val;
	} else return -999999;
}

void Stack::push(int val) {
	Node *top = new Node();
	top->next_ = top_;
	top->val_ = val;
	if (val < top_->min_) top->min_ = val;
	else top->min_ = top_->min_;
	top_ = top;
}
