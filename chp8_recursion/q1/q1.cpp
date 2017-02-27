#include <iostream>
using std::cout;

int fib(int n);

int main() {
	for (int i = 0; i < 10; ++i) 
		cout << fib(i) << " ";
	cout << "\n\n";
	return 0;
}

int fib(int n) {
	if (n < 0) return -1;
	if (n == 0) return 0;
	if (n == 1) return 1;
	else return fib(n-1) + fib(n-2);
}
