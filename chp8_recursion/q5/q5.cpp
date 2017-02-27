#include <iostream>
#include <vector>
using std::cout;
using std::vector;

void Parentheses(int, int, const vector<char> &);

int main() {
	int n = 10;
	Parentheses(n, n, vector<char>());
	return 0;
}

void Parentheses(int left, int right, const vector<char> &str) {
	if (left == 0 && right == 0) {
		for (auto s : str) cout << s;
		cout << "\n";
	} else {
		if (left >= right) {
			vector<char> st = str;
			st.push_back('(');
			Parentheses(left-1, right, st);
		} else if (left == 0) {
			vector<char> st = str;
			st.push_back(')');
			Parentheses(left, right-1, st);
		} else {
			vector<char> st = str, s = str;
			st.push_back('(');
			Parentheses(left-1, right, st);
			s.push_back(')');
			Parentheses(left, right-1, s);
		}
	}
}
