#include "bst_node.h"

#include <iostream>
using std::cout;

BST_Node::BST_Node() {
	left_ = nullptr;
	right_ = nullptr;
}

BST_Node::BST_Node(int val, BST_Node *left, BST_Node *right) {
	value_ = val;
	left_ = left;
	right_ = right;
}

bool BST_Node::Add(int val) {
	if (val < value_) {
		if (left_ != nullptr) {
			return left_->Add(val);
		}	else {
			left_ = new BST_Node(val, nullptr, nullptr);
			return true;
		}
	} else {
		if (right_ != nullptr) {
			return right_->Add(val);
		} else {
			right_ = new BST_Node(val, nullptr, nullptr);
			return true;
		}
	}
}

void BST_Node::InOrder() {
	if (left_ != nullptr) left_->InOrder();
	Print();
	if (right_ != nullptr) right_->InOrder();
}

BST_Node *BST_Node::Min() {
	if (left_ == nullptr) return this;
	else return left_->Min();
}

void BST_Node::PreOrder() {
	Print();
	if (left_ != nullptr) left_->PreOrder();
	if (right_ != nullptr) right_->PreOrder();
}

void BST_Node::Print() {
	cout << value_ << " ";
}

void BST_Node::PostOrder() {
	if (left_ != nullptr) left_->PostOrder();
	if (right_ != nullptr) right_->PostOrder();
	Print();
}

void BST_Node::Set(BST_Node *node) {
	value_ = node->value_;
	left_ = node->left_;
	right_ = node->right_;
}

BST_Node *BST_Node::Search(int val) {
	if (val == value_) return this;
	else if (val < value_) {
		if (left_ != nullptr) return left_->Search(val);
		else return nullptr;
	} else {
		if (right_ != nullptr) return right_->Search(val);
		else return nullptr;
	}
}
