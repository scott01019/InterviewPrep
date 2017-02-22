#ifndef STACK_H_
#define STACK_H_

class Stack {
	public:
		Stack() : top0(-3), top1(-2), top2(-1) {}
		int pop0();
		int pop1();
		int pop2();
		void print();
		void push0(int);
		void push1(int);
		void push2(int);
	private:
		int stack[102];
		int top0, top1, top2;
};

#endif	//	STACK_H_
