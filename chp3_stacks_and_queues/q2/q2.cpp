#include "stack.h"

#include <iostream>
#include <chrono>
#include <functional>
#include <random>
using std::cout;
using std::chrono::system_clock;
using std::default_random_engine;
using std::uniform_int_distribution;

int main() {
	unsigned seed = system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	uniform_int_distribution<int> distribution(0, 100);
	auto rand = std::bind(distribution, generator);

	Stack stack;
	
	for (int i = 0; i < 20; ++i) stack.push(rand());
	
	stack.print();
	cout << stack.min() << "\n";

	return 0;
}
