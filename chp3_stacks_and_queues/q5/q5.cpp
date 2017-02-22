#include "my_queue.h"

#include <iostream>
#include <chrono>
#include <functional>
#include <random>
using std::cout;
using std::chrono::system_clock;
using std::default_random_engine;
using std::uniform_int_distribution;

#include <vector>
using std::vector;

int main() {
	unsigned seed = system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	uniform_int_distribution<int> distribution(0, 100);
	auto rand = std::bind(distribution, generator);

	vector<int> v;
	for (int i = 0; i < 20; ++i) v.push_back(rand());
	for (int i : v) cout << i << " ";
	cout << "\n\n";

	MyQueue q;
	for (int i : v) q.add(i);
	for (int i = 0; i < 20; ++i) {
		cout << q.remove() << " ";
	}	cout << "\n";
	return 0;
}
