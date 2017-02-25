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
	Node(int v, Node *l, Node *r, Node *p) {
		val = v;
		left = l;
		right = r;
		parent = p;
	}
	int val;
	Node *left;
	Node *right;
	Node *parent;
};

void Add(Node * &, int);
void PostOrder(Node *, int);
void InOrder(Node *);
Node *GetSuccessor(Node *);
Node *GetMin(Node *);

int main() {
	unsigned seed = system_clock::now().time_since_epoch().count();
	default_random_engine gen(seed);
	uniform_int_distribution<int> dist(0, 99);

	Node *root = nullptr;
	for (int i = 0; i < 20; ++i) {
		Add(root, dist(gen));
	}

	PostOrder(root, 0);
	cout << "\n";
	InOrder(root); 
	cout << "\n";

	cout << root->val << " ";
	Node *successor = GetSuccessor(root);
	for (int i = 0; i < 20; ++i) {
		if (successor != nullptr) {
			cout << successor->val << " ";
			successor = GetSuccessor(successor);
		}
	} cout << "\n";

	return 0;
}

Node *GetSuccessor(Node *node) {
	if (node == nullptr) return nullptr;
	if (node->right != nullptr) {
		return GetMin(node->right);
	} else {
		Node *par = node->parent;
		Node *child = node;
		while (par != nullptr && par->val <= node->val) {
			child = par;
			par = par->parent;
		}
		if (par != nullptr) return par;
		else {
			if (child->right == nullptr) return nullptr;
			else if (child->right->val > node->val) return child->right;
			else return nullptr;
		}
	}
}

void Add(Node * &node, int val) {
	if (node == nullptr) {
		node = new Node(val, nullptr, nullptr, nullptr);
	} else {
		if (val < node->val) {
			if (node->left == nullptr) 
				node->left = new Node(val, nullptr, nullptr, node);
			else Add(node->left, val);
		} else {
			if (node->right == nullptr)
				node->right = new Node(val, nullptr, nullptr, node);
			else Add(node->right, val);
		}
	}
}

Node *GetMin(Node *root) {
	if (root == nullptr) return nullptr;
	else if (root->left == nullptr) return root;
	else {
		Node *current = root->left;
		while (current->left != nullptr) current = current->left;
		return current;
	}
}

void InOrder(Node *node) {
	if (node != nullptr) {
		InOrder(node->left);
		cout << node->val << " ";
		InOrder(node->right);
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
