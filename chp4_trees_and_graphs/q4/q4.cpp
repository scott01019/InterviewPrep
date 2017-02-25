#include <iostream>
#include <iomanip>
#include <list>
#include <random>
#include <chrono>
using std::chrono::system_clock;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::cout;
using std::setw;
using std::list;
using std::vector;
using std::list;

struct Node {
	Node(int v, Node *l, Node *r) {
		val = v;
		left = l;
		right = r;
	}
	int val;
	Node *left;
	Node *right;
};

void Add(Node * &, int);
void PostOrder(Node *, int);
vector<list<Node *>> GetLists(Node *);
void CreateLists(Node *, vector<list<Node*>> &, int);


int main() {
	unsigned seed = system_clock::now().time_since_epoch().count();
	default_random_engine gen(seed);
	uniform_int_distribution<int> dist(0, 99);

	Node *root = nullptr;
	for (int i = 0; i < 20; ++i) {
		Add(root, dist(gen));
	}

	PostOrder(root, 0);

	vector<list<Node *>> lists = GetLists(root);
	for (int i = 0; i < lists.size(); ++i) {
		cout << "Depth " << i << ": ";
		for (auto node : lists[i]) {
			cout << node->val << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
	return 0;
}

vector<list<Node *>> GetLists(Node *node) {
	vector<list<Node *>> lists;
	CreateLists(node, lists, 0);
	return lists;
}

void CreateLists(Node *node, vector<list<Node*>> &lists, int depth) {
	if (node != nullptr) {
		if (lists.size() <= depth) {
			lists.push_back(list<Node *>());
		}
		lists[depth].push_back(node);
		CreateLists(node->left, lists, depth+1);
		CreateLists(node->right, lists, depth+1);
	}
}

void Add(Node * &node, int val) {
	if (node == nullptr) {
		node = new Node(val, nullptr, nullptr);
	} else {
		if (val < node->val) {
			if (node->left == nullptr) 
				node->left = new Node(val, nullptr, nullptr);
			else Add(node->left, val);
		} else {
			if (node->right == nullptr)
				node->right = new Node(val, nullptr, nullptr);
			else Add(node->right, val);
		}
	}
}

void PostOrder(Node *root, int indent) {
	if (root != nullptr) {
		if (root->right != nullptr) PostOrder(root->right, indent+4);
		if (root->left != nullptr) PostOrder(root->left, indent+4);
		if (indent) cout << setw(indent) << " ";
		cout << root->val << "\n";
	}
}
