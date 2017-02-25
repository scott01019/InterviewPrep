#ifndef BST_NODE_H_
#define BST_NODE_H_

class BST_Node {
	public:
		BST_Node(int val) : value_(val) { left_ = right_ = nullptr; }
		BST_Node(int, BST_Node *, BST_Node *);
		bool Add(int);
		int MaxDepthOfLeaves();
		int MinDepthOfLeaves();
		bool IsBalanced();
	
		int value() const { return value_; }
		BST_Node *left() const { return left_; }
		BST_Node *right() const { return right_; }
	private:
		int value_;
		BST_Node *left_;
		BST_Node *right_;
};

#endif	//	BST_NODE_H_
