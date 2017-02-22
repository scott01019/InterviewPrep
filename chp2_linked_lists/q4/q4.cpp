#include "../linked_list.h"

#include <chrono>
#include <functional>
#include <iostream>
#include <random>
using std::chrono::system_clock;
using std::cout;
using std::default_random_engine;
using std::uniform_int_distribution;

int main() {
	unsigned seed = system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	uniform_int_distribution<int> distribution(0, 9);
	
	auto rand = std::bind(distribution, generator);

	LinkedList<int> a, b;

	for (int i = 0; i < 5; ++i) {
		a.Append(rand());
		b.Append(rand());
	}

	b.Append(9);
	b.Append(9);

	a.Print();
	b.Print();
	LinkedList<int> c = LinkedList<int>::Add(a, b);
	c.Print();

	return 0;
}
