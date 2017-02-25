#include "tree_node.h"

#include <iostream>
#include <vector>
using std::cout;
using std::vector;

TreeNode::TreeNode(int val, TreeNode *parent)
	: value_(val), parent_(parent) {}

void TreeNode::Add(TreeNode *tn) {
	children_.push_back(tn);
	tn->set_parent(this);
}

void TreeNode::Print() const {
	cout << value_ << ", ";
	if (parent_ == nullptr) cout << "nullptr";
	else cout << parent_->value_;
	cout << ": ";
	for (auto node : children_) cout << node->value_ << " ";
	cout << "\n";
}
