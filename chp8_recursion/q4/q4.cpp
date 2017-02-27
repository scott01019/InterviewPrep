#include <algorithm>
#include <iostream>
using std::cout;

void permute(char *, int, int);

int main() {
	char str[] = "abcdef";
	permute(str, 0, 5);
	return 0;
}

void permute(char *str, int left, int right) {
	if (left == right) cout << str << "\n";
	else {
		for (int i = left; i <= right; ++i) {
		//	cout << "swapping " << str[left] << " and " << str[i] << "\n";
			std::swap(str[left], str[i]);
		//	cout << "calling permute(" << str << " " << left + 1 << " " << right << ")\n";
			permute(str, left+1, right);
		//	cout << "swapping " << str[left] << " and " << str[i] << "\n";
			std::swap(str[left], str[i]);
		}
	}
}
