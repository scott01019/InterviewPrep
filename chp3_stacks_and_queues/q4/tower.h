#ifndef TOWER_H_
#define TOWER_H_

#include <stack>
using std::stack;

class Tower {
	public:
		Tower(int i) : index_(i) {}
		int index() const { return index_; }
		void Add(int);
		void MoveTopTo(Tower &);
		void MoveDisks(int, Tower &, Tower &);
	private:
		stack<int> disks_;
		int index_;
};

#endif // TOWER_H_
