#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include "bst_node.h"

class BinarySearchTree {
public:
	BinarySearchTree();
	bool Add(int);
	void InOrder();
	void PreOrder();
	void PostOrder();
	BST_Node *Search(int);
private:
	BST_Node *root_;
};

#endif	//	BINARY_SEARCH_TREE_H_
