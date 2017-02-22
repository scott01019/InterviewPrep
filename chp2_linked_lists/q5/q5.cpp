#include <chrono>
#include <functional>
#include <iostream>
#include <random>
#include <unordered_set>
using std::chrono::system_clock;
using std::cout;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::unordered_set;

struct ListNode {
	int value_;
	ListNode *next_;
};

ListNode *FindCircle(ListNode *);

int main() {
	unsigned seed = system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	uniform_int_distribution<int> distribution(1, 10);
	
	auto rand = std::bind(distribution, generator);

	ListNode *first = new ListNode();
	first->value_ = rand();
	first->next_ = nullptr;

	ListNode *second = first;
	for (int i = 0; i < 20; ++i) {
		second->next_ = new ListNode();
		second->next_->next_ = nullptr;
		second->next_->value_ = rand();
		second = second->next_;
	}

	ListNode *third = second;
	for (int i = 0; i < 20; ++i) {
		third->next_ = new ListNode();
		third->next_->next_ = nullptr;
		third->next_->value_ = rand();
		third = third->next_;
	}

	third->next_ = second;

	cout << second << " " << second->value_ << "\n";
	ListNode *result = FindCircle(first);
	cout << result << " " << result->value_ << "\n";
	return 0;
}

ListNode *FindCircle(ListNode *start) {
	unordered_set<ListNode *> visited;
	while (start != nullptr) {
		if (visited.find(start) != visited.end()) { 
			cout << visited.size() << "\n";
			return start;
		}
		else {
			visited.insert(start);
			start = start->next_;
		}
	}
}
