#include "binary_search_tree.h"
#include "bst_node.h"

BinarySearchTree::BinarySearchTree() {
	root_ = nullptr;
}

bool BinarySearchTree::Add(int val) {
	if (root_ == nullptr) {
		root_ = new BST_Node(val, nullptr, nullptr);
		return true;
	} else {
		return root_->Add(val);
	}
}

void BinarySearchTree::InOrder() {
	if (root_ == nullptr) return;
	else root_->InOrder();
}

void BinarySearchTree::PreOrder() {
	if (root_ == nullptr) return;
	else root_->PreOrder();
}

void BinarySearchTree::PostOrder() {
	if (root_ == nullptr) return;
	else root_->PostOrder();
}

BST_Node *BinarySearchTree::Search(int val) {
	if (root_ == nullptr) return nullptr;
	else return root_->Search(val);
}
