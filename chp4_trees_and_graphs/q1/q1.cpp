#include "bst_node.h"

#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
using std::cout;

void postorder(BST_Node *, int);

int main() {
	unsigned seed = 
		std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine gen(seed);
	std::uniform_int_distribution<int> distribution(0, 100);

	BST_Node root(50);
	root.Add(100);
	root.Add(75);
	root.Add(25);
	root.Add(40);
	root.Add(45);
	root.Add(70);
	root.Add(74);
	root.Add(60);
	//for (int i = 0; i < 25; ++i) {
	//	root.Add(distribution(gen));
	//}
	postorder(&root, 0);
	cout << root.MaxDepthOfLeaves() << "\n";
	cout << root.MinDepthOfLeaves() << "\n";
	cout << root.IsBalanced() << "\n\n";
}

void postorder(BST_Node *node, int indent) {
	if (node != nullptr) {
		if (node->right() != nullptr) postorder(node->right(), indent+4);
		if (node->left() != nullptr) postorder(node->left(), indent+4);
		if (indent) std::cout << std::setw(indent) << " ";
		std::cout << node->value() << "\n";
	}
}
