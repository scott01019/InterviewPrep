#include "linked_list.h"

#include <iostream>
using std::cout;

template <class T>
LinkedList<T>::LinkedList() {
	tail_ = new ListNode<T>();
	head_->next_ = tail_;
	tail_->next_ = nullptr;
}

template <class T>
LinkedList<T> LinkedList<T>::Add(LinkedList<T> a, LinkedList<T> b) {
	LinkedList<T> result;
	int carry = 0;
	ListNode<T> *a_current = a.head_->next_;
	ListNode<T> *b_current = b.head_->next_;
	while (a_current != a.tail_ && b_current != b.tail_) {
		int sum = a_current->value_ + b_current->value_ + carry;
		result.Append(sum % 10);
		carry = sum / 10;
		a_current = a_current->next_;
		b_current = b_current->next_;
	}

	if (b_current != b.tail_) {
		result.Append(b_current->value_ + carry);
		b_current = b_current->next_;
		while (b_current != b.tail_) {
			result.Append(b_current->value_);
			b_current = b_current->next_;
		}
	}

	if (a_current != a.tail_) {
		result.Append(a_current->value_ + carry);
		a_current = a_current->next_;
		while (a_current != a.tail_) {
			result.Append(a_current->value_);
			a_current = a_current->next_;
		}
	}
	return result;
}

template <class T>
void LinkedList<T>::AddToStart(const T &t) {
	ListNode<T> *next = head_->next_;
	head_->next_ = new ListNode<T>();
	head_->next_->value_ = t;
	head_->next_->next_ = next;
}

template <class T>
void LinkedList<T>::Append(const T &t) {
	if (head_->next_ == tail_) {
		head_->next_ = new ListNode<T>();
		head_->next_->value_ = t;
		head_->next_->next_ = tail_;
	} else {
		ListNode<T> *current = head_->next_;
		while (current->next_ != tail_) current = current->next_;
		current->next_ = new ListNode<T>();
		current->next_->next_ = tail_;
		current->next_->value_ = t;
	}
}

template <class T>
ListNode<T> *LinkedList<T>::NthToLast(int n) {
	if (head_->next_ == tail_ || n < 1) return nullptr;
	else {
		ListNode<T> *lead = head_->next_;
		ListNode<T> *result = head_->next_;
		for (int i = 0; i < n - 1; ++i) {
			if (lead->next_ != tail_) lead = lead->next_;
			else return nullptr;
		}
		while (lead->next_ != tail_) {
			lead = lead->next_;
			result = result->next_;
		}
		return result;
	}
}

template <class T>
void LinkedList<T>::Print() {
	ListNode<T> *current = head_->next_;
	while (current != tail_) {
		cout << current->value_ << " ";
		current = current->next_;
	} cout << "\n\n";
}

template <class T>
void LinkedList<T>::Remove(const T &t) {
	if (head_->next_ == tail_) return;
	if (head_->next_->value_ == t) head_->next_ = head_->next_->next_;
	else {
		ListNode<T> *current = head_->next_;
		while (current->next_ != tail_ && current->next_->value_ != t)
			current = current->next_;
		if (current->next_ == tail_) return;
		else current->next_ = current->next_->next_;
	}
}

template <class T>
void LinkedList<T>::Remove(ListNode<T> *node) { 
	if (node == nullptr || node->next_ == nullptr) return;
	if (node->next_ == tail_) {
		tail_ = node;
		tail_->next_ = nullptr;
	} else {
		node->value_ = node->next_->value_;
		node->next_ = node->next_->next_;
	}
}

template <class T>
void LinkedList<T>::RemoveDuplicates() {
	if (head_ == tail_) return;
	else {
		ListNode<T> *compare = head_->next_;
		while (compare != tail_) {
			ListNode<T> *current = compare;
			while (current != tail_) {
				if (current->next_ != tail_ 
						&& current->next_->value_ == compare->value_)
						current->next_ = current->next_->next_;
				else current = current->next_;
			}
			compare = compare->next_;
		}
	}
}
