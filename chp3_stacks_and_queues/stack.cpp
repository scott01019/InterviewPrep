#include "stack.h"

#include <iostream>
using std::cout;

template <class T>
Stack<T>::Stack() {
	bot_->next_ == nullptr;
	top_ = bot_;
	size_ = 0;
}

template <class T>
Stack<T>::~Stack() {
	delete top_;
	delete bot_;
}

template <class T>
bool Stack<T>::Empty() const {
	return top_ == bot_;
}

template <class T>
const T &Stack<T>::Peek() const {
	if (top_ == bot_) return nullptr;
	else return top_->value;
}

template <class T>
const T &Stack<T>::Pop() {
	T val = top_->value;
	top_ = top_->next_;
	--size_;
	return val;
}

template <class T>
void Stack<T>::Print() const {
	Node<T> *current = top_;
	while (current != bot_) {
		cout << current->value_ << " ";
		current = current->next_;
	} cout << "\n\n";
}

template <class T>
void Stack<T>::Push(const T &val) {
	Node<T> *node = new Node<T>();
	node->value_ = val;
	node->next_ = top_;
	top_ = node;
	++size_;
}

template <class T>
int Stack<T>::Size() const { return size_; }
