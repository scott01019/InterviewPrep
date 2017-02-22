#ifndef STACK_H_
#define STACK_H_

template <class T>
struct Node {
	T value_;
	Node<T> *next_;
};

template <class T>
class Stack {
	public:
		Stack();
		~Stack();
		bool Empty() const;
		const T &Peek() const;
		const T &Pop();
		void Print() const;
		void Push(const T &);
		int Size() const;
	private:
		int size_;
		Node<T> *top_;
		Node<T> * const bot_ = new Node<T>();
};

#include "stack.cpp"

#endif	//	STACK_H_
