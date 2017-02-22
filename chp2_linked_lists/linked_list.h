#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

template<class T>
struct ListNode {
	T value_;
	ListNode* next_;
};

template <class T>
class LinkedList {
	public:
		LinkedList();
		void AddToStart(const T &t);
		void Append(const T &t);
		ListNode<T> *NthToLast(int);
		void Print();
		void Remove(const T &t);
		void Remove(ListNode<T> *);
		void RemoveDuplicates();
	
		static LinkedList<T> Add(LinkedList<T>, LinkedList<T>);
	private:
		ListNode<T> * const head_ = new ListNode<T>();
		ListNode<T> *tail_;
};

#include "linked_list.cpp"

#endif	//	LINKED_LIST_H_
