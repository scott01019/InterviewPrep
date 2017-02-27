#include <bitset>
#include <iostream>
using std::bitset;
using std::cout;

int SetBits(int, int, int, int);

int main() {
	int n = 0b10101011000;
	int m = 0b11;
	int i = 0;
	int j = 2;
	cout << bitset<32>(SetBits(n, m, i, j)) << "\n";
	return 0;
}

int SetBits(int n, int m, int i, int j) {
	int r = ~0;
	r << i;
}
