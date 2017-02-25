#ifndef BST_NODE_H_
#define BST_NODE_H_

class BST_Node {
	public:
		BST_Node();
		BST_Node(int, BST_Node *, BST_Node *);
		bool Add(int);
		void InOrder();
		BST_Node *Min();
		void PreOrder();
		void Print();
		void PostOrder();
		void Set(BST_Node *);
		BST_Node *Search(int);

		BST_Node *left() const { return left_; }
		BST_Node *right() const { return right_; }
		int value() const { return value_; }
	
		void set_left(BST_Node *left) { left_ = left; }
		void set_right(BST_Node *right) { right_ = right; }
		void set_value(int val) { value_ = val; }
	private:
		int value_;
		BST_Node *left_;
		BST_Node *right_;
};

#endif	//	BST_NODE_H_
