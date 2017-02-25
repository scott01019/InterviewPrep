#ifndef TREE_NODE_H_
#define TREE_NODE_H_

#include <vector>
using std::vector;

class TreeNode {
	public:
		TreeNode(int val) : value_(val) { parent_ = nullptr; }
		TreeNode(int, TreeNode*);

		void Print() const;

		void Add(TreeNode *);
		void set_value(int value) { value_ = value; }
		void set_parent(TreeNode *parent) { parent_ = parent; }

		int value() const { return value_; }
		TreeNode *parent() const { return parent_; }
		const vector<TreeNode *> &children() const { return children_; }
	private:
	int value_;
	vector<TreeNode *> children_;
	TreeNode *parent_;
};

#endif	//	TREE_NODE_H_
