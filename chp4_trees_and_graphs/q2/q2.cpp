#include <chrono>
#include <functional>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>
#include <vector>
using std::cout;
using std::chrono::system_clock;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::unordered_set;
using std::vector;

struct Node {
	Node(int i) { id = i; }
	int id;
	vector<Node*>	paths;
	unordered_set<int> paths_set;
};

bool IsRoute(Node *, Node *);

int main() {
	unsigned seed = system_clock::now().time_since_epoch().count();
	default_random_engine gen(seed);
	uniform_int_distribution<int> dist_paths(0, 3), dist_nodes(0, 49);

	vector<Node> graph;
	for (int i = 0; i < 50; ++i) {
		graph.push_back(Node(i));
	}

	for (auto &node : graph) {
		int num_paths = dist_paths(gen);
		for (int i = 0; i < num_paths; ++i) {
			int id = dist_nodes(gen);
			if (node.paths_set.find(id) == node.paths_set.end() 
					&& node.id != id) {
				node.paths.push_back(&graph[id]);
			}
		}
	}

	for (int i = 0; i < 50; ++i) {
		Node *start = &graph[dist_nodes(gen)];
		Node *goal = &graph[dist_nodes(gen)];
		cout << IsRoute(start, goal) << " ";
	} cout << "\n\n";

	return 0;
}

bool IsRoute(Node *start, Node *goal) {
	std::stack<Node*> stk;
	std::unordered_set<Node *> visited;
	stk.push(start);
	while (!stk.empty()) {
		Node *current = stk.top(); stk.pop();
		visited.insert(current);
		if (current->id == goal->id) {
			return true;
		} else {
			for (auto node : current->paths) {
				if (visited.find(node) == visited.end())
					stk.push(node);
			}
		}
	}
	return false;
}
