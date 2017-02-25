#include "binary_search_tree.h"

#include <chrono>
#include <functional>
#include <iostream>
#include <random>
#include <vector>
using std::chrono::system_clock;
using std::cout;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::vector;

int main() {
	unsigned int seed = system_clock::now().time_since_epoch().count();
	default_random_engine gen(seed);
	uniform_int_distribution<int> dist(0, 100);
	auto rand = std::bind(dist, gen);

	BinarySearchTree bst;

//	for (int i = 0; i < 20; ++i) bst.Add(rand());
	vector<int> v = { 7, 1, 0, 3, 2, 5, 9, 8, 10, 4, 6 };
	for (int i = 0; i < 11; ++i) bst.Add(v[i]);

	bst.InOrder(); cout << "\n\n";
	bst.PreOrder(); cout << "\n\n";
	bst.PostOrder(); cout << "\n\n";

	return 0;
}
