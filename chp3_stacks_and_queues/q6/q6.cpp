#include <iostream>
#include <chrono>
#include <functional>
#include <random>
#include <stack>
using namespace std;

using std::chrono::system_clock;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::duration_cast;

void print(const stack<int> &);
stack<int> sort(stack<int> &);
stack<int> sort2(stack<int> &);

int main() {
	unsigned seed = system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	uniform_int_distribution<int> distribution(0, 1000000);
	auto rand = bind(distribution, generator);

	stack<int> s;
	for (int i = 0; i < 50000; ++i) s.push(rand());
	stack<int> s2 = s;

	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	s = sort(s);
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> diff = duration_cast<duration<double>>(t2 - t1);
	cout << "Duration for sort: " << diff.count() << "\n";

	t1 = high_resolution_clock::now();
	s2 = sort2(s2);
	t2 = high_resolution_clock::now();
	diff = duration_cast<duration<double>>(t2 - t1);
	cout << "Duration for sort2: " << diff.count() << "\n";

	return 0;
}

void print(const stack<int> &stk) {
	for (stack<int> s = stk; !s.empty(); s.pop())
		cout << s.top() << " ";
	cout << "\n\n";
}

stack<int> sort(stack<int> &stk) {
	stack<int> r;
	while (!stk.empty()) {
		int tmp = stk.top(); stk.pop();
		while (!r.empty() && r.top() > tmp) {
			stk.push(r.top()); r.pop();
		}
		r.push(tmp);
	}
	return r;
}

stack<int> sort2(stack<int> &s) {
	if (s.empty()) return s;

	int comp = s.top(); s.pop();
	if (s.empty()) {
		s.push(comp);
		return s;
	} 
	
	else {
		stack<int> less, more;
		while (!s.empty()) {
			int top = s.top(); s.pop();
			if (top >= comp) more.push(top);
			else less.push(top);
		}
		more = sort2(more);
		stack<int> rev_more;
		while (!more.empty()) {
			rev_more.push(more.top()); more.pop();
		}
		less = sort2(less);
		less.push(comp);
		while (!rev_more.empty()) {
			less.push(rev_more.top()); rev_more.pop();
		}
		return less;
	}
}
