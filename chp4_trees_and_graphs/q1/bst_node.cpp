#include "bst_node.h"


BST_Node::BST_Node(int val, BST_Node *left, BST_Node *right) {
	value_ = val;
	left_ = left;
	right_ = right;
}

bool BST_Node::Add(int val) {
	if (val < value_) {
		if (left_ == nullptr) left_ = new BST_Node(val, nullptr, nullptr);
		else return left_->Add(val);
	} else {
		if (right_ == nullptr) right_ = new BST_Node(val, nullptr, nullptr);
		else return right_->Add(val);
	}
	return true;
}

int BST_Node::MaxDepthOfLeaves() {
	if (left_ == nullptr && right_ == nullptr) return 0;
	if (right_ == nullptr) return 1 + left_->MaxDepthOfLeaves();
	if (left_ == nullptr) return 1 + right_->MaxDepthOfLeaves();	
	
	int left_depth = 1 + left_->MaxDepthOfLeaves();
	int right_depth = 1 + right_->MaxDepthOfLeaves();

	return (left_depth > right_depth) ? left_depth : right_depth;
}

int BST_Node::MinDepthOfLeaves() {
	if (left_ == nullptr && right_ == nullptr) return 0;
	if (right_ == nullptr) return 1 + left_->MinDepthOfLeaves();
	if (left_ == nullptr) return 1 + right_->MinDepthOfLeaves();

	int left_depth = 1 + left_->MinDepthOfLeaves();
	int right_depth = 1 + right_->MinDepthOfLeaves();

	return (left_depth < right_depth) ? left_depth : right_depth;
}

bool BST_Node::IsBalanced() {
	return (MaxDepthOfLeaves() - MinDepthOfLeaves()) < 2;
}
