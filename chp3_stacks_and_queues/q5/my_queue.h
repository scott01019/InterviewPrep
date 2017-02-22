#ifndef MY_QUEUE_H_
#define MY_QUEUE_H_

#include <stack>
using std::stack;

class MyQueue {
	public:
		MyQueue() {}
		int remove();
		void add(int);
		int peek();
	private:
		stack<int> dequeue;
		stack<int> enqueue;
};

#endif	//	MY_QUEUE_H_
