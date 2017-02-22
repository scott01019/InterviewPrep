#include "my_queue.h"

#include <stack>
using std::stack;

int MyQueue::remove() {
	if (!dequeue.empty()) {
		int val = dequeue.top();
		dequeue.pop();
		return val;
	}	else {
		while (!enqueue.empty()) {
			dequeue.push(enqueue.top());
			enqueue.pop();
		}
		int val = dequeue.top();
		dequeue.pop();
		return val;
	}
}

void MyQueue::add(int val) {
	enqueue.push(val);
}

int MyQueue::peek() {
	if (!dequeue.empty()) {
		return dequeue.top();
	} else {
		while (!enqueue.empty()) {
			dequeue.push(enqueue.top());
			enqueue.pop();
		}
		return dequeue.top();
	}
}
