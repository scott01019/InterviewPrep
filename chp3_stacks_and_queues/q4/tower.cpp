#include "tower.h"

#include <iostream>
#include <stack>
using std::cout;
using std::stack;

void Tower::Add(int i) {
	if (!disks_.empty() && disks_.top() <= i);
	else disks_.push(i);
}

void Tower::MoveTopTo(Tower &t) {
	int top = disks_.top();
	disks_.pop();
	t.Add(top);
}

void Tower::MoveDisks(int disk, Tower &dest, Tower &buf) {
	if (disk > 0) {
		MoveDisks(disk - 1, buf, dest);
		MoveTopTo(dest);
		buf.MoveDisks(disk - 1, dest, *this);
	}
}
