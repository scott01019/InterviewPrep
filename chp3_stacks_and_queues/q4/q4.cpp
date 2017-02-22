#include <iostream>
#include <stack>
using std::cout;
using std::stack;

void move(stack<int> &, stack<int> &);
void print(const stack<int> &);
void print_tower(const stack<int> &, 
		const stack<int> &, const stack<int> &);
void solve(int, stack<int> &, stack<int> &, stack<int> &);

int main() {
	int disks = 5;
	stack<int> peg0, peg1, peg2;
	for (int i = disks; i > 0; --i) peg0.push(i);
	print_tower(peg0, peg1, peg2);	
	solve(disks, peg0, peg1, peg2);
	print_tower(peg0, peg1, peg2);
	return 0;
}

void move(stack<int> &from, stack<int> &to) {
	to.push(from.top());
	from.pop();
}

void print(const stack<int> &stk) {
	for (stack<int> dump = stk; !dump.empty(); dump.pop()) {
		cout << dump.top() << " ";
	} cout << "\n";
}

void print_tower(const stack<int> &peg0, const stack<int> &peg1,
		const stack<int> &peg2) {
	cout << "src: "; print(peg0);
	cout << "buf: "; print(peg1);
	cout << "dest: "; print(peg2);
	cout << "\n";
}

void solve(int disk, stack<int> &src, stack<int> &buf, stack<int> &dest) {
	if (disk > 0) {
		solve(disk - 1, src, dest, buf);
		move(src, dest);
		solve(disk - 1, buf, src, dest);
	}
}
