#include "tree_node.h"

#include <iostream>
#include <random>
#include <chrono>
using std::chrono::system_clock;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::cout;
using std::vector;

TreeNode *GetAncestor(TreeNode *, TreeNode *, TreeNode *);
bool IsDescendant(TreeNode *, TreeNode *);

int main() {
	unsigned seed = system_clock::now().time_since_epoch().count();
	default_random_engine gen(seed);

	vector<vector<TreeNode *>> tree;
	for (int i = 0; i < 5; ++i) tree.push_back(vector<TreeNode *>());
	int id = 0;
	for (int i = 0; i < 5; ++i) {
		int nodes = i * 5;
		if (i == 0) {
			tree[0].push_back(new TreeNode(id, nullptr));
			++id;
		} else {
			for (int j = 0; j < nodes; ++j) {
				TreeNode *node = new TreeNode(id, nullptr);
				tree[i].push_back(node);
				if (i == 1) {
					tree[0][0]->Add(node);
				} else {
					uniform_int_distribution<int> dist(0, (i - 1) * 5 - 1);
					tree[i - 1][dist(gen)]->Add(node);
				}
				++id;
			}
		}
	}

	for (auto depth : tree) for (auto node : depth) node->Print();
	
	TreeNode *root = tree[0][0];
	TreeNode *a = tree[2][3];
	
	if (!(tree[2][3]->children().size() > 0)) {
		cout << "NO CHILDREN\n\n";
		return 0;
	}
	TreeNode *b = tree[2][3]->children()[0];

	cout << a->value() << ", " << a->parent()->value();
	cout << "\t" << b->value() << ", " << b->parent()->value() << ": ";
	TreeNode *c = GetAncestor(root, a, b);
	cout << c->value() << "\n\n";
	
	return 0;
}

TreeNode *GetAncestor(TreeNode *root, TreeNode *a, TreeNode *b) {
	for (auto child : root->children()) {
		if (IsDescendant(child, a) && IsDescendant(child, b))
			return GetAncestor(child, a, b);
	}
	return root;
}

bool IsDescendant(TreeNode *root, TreeNode *a) {
	for (auto child : root->children()) {
		if (child == a) return true;
		else return IsDescendant(child, a);
	}
	return false;
}
