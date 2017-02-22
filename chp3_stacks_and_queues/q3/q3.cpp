#include "capacity_stack.h"
#include "stack_of_stacks.h"

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
	
	StackOfStacks sos;
	
	for (int i = 0; i < 30; ++i) { sos.push(rand()); }
	sos.print();
	
	for (int i = 0; i < 10; ++i) { sos.popAt(1); }
	sos.print();

	for (int i = 0; i < 10; ++i) { sos.popAt(2); }
	sos.print();

	for (int i = 0; i < 10; ++i) { sos.popAt(0); }
	
	sos.print();
	sos.push(5);
	sos.print();

	return 0;
}
