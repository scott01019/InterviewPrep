#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>

using std::cout;
using std::chrono::system_clock;
using std::default_random_engine;
using std::uniform_int_distribution;

struct BST_Node {
	BST_Node(int val) {
		value = val;
		left = nullptr;
		right = nullptr;
	}
	int value;
	BST_Node *left;
	BST_Node *right;
};

BST_Node *CreateBalancedTree(int [], int, int);
void PostOrder(BST_Node *, int);

int main() {
	unsigned seed = system_clock::now().time_since_epoch().count();
	default_random_engine gen(seed);
	uniform_int_distribution<int> dist(0, 500);

	const int SIZE = 12;
	int arr[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		arr[i] = i;
	}

	std::sort(std::begin(arr), std::end(arr));

	for (auto i : arr) cout << i << " ";
	cout << "\n\n";

	BST_Node *root = CreateBalancedTree(arr, 0, SIZE - 1);

	PostOrder(root, 0);

	return 0;
}

BST_Node *CreateBalancedTree(int arr[], int start, int end) {
	if (end < start) return nullptr;
	int mid = (start + end) / 2;
	BST_Node *n = new BST_Node(arr[mid]);
	n->left = CreateBalancedTree(arr, start, mid - 1);
	n->right = CreateBalancedTree(arr, mid + 1, end);
	return n;
}

void PostOrder(BST_Node *node, int indent) {
	if (node != nullptr) {
		if (node->right != nullptr) PostOrder(node->right, indent+4);
		if (node->left != nullptr) PostOrder(node->left, indent+4);
		if (indent) std::cout << std::setw(indent) << " ";
		std::cout << node->value << "\n";
	}
}
