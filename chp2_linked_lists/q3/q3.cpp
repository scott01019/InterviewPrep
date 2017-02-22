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
	uniform_int_distribution<int> distribution(0, 10);
	auto rand = std::bind(distribution, generator);

	LinkedList<int> list;
	for (int i = 0; i < 25; ++i) list.AddToStart(rand());
	list.Print();
	ListNode<int> *del = list.NthToLast(10);
	cout << del->value_ << "\n";
	list.Remove(del);
	list.Print();
	list.Remove(new ListNode<int>());
	list.Print();
	list.Remove(list.NthToLast(1));
	list.Print();
	cout << list.NthToLast(5)->value_ << "\n";
	list.Remove(list.NthToLast(5));
	list.Print();
	return 0;
}
