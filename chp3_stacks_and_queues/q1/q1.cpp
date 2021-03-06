#include "stack.h"

#include <chrono>
#include <functional>
#include <random>
using std::chrono::system_clock;
using std::default_random_engine;
using std::uniform_int_distribution;

int main() {
	unsigned seed = system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	uniform_int_distribution<int> distribution(0, 100);
	auto rand = std::bind(distribution, generator);

	Stack stack;

	stack.print();

	for (int i = 0; i < 10; ++i) {
		stack.push0(rand());
		stack.push1(rand());
		stack.push2(rand());
	}	

	stack.print();

	for (int i = 0; i < 3; ++i) {
		stack.pop0(); stack.pop1(); stack.pop2();
	}

	stack.print();

	return 0;
}
