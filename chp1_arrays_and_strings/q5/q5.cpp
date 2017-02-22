#include <iostream>
#include <string>
using std::cout;
using std::string;

void ReplaceSpace(string &);

int main() {
	string a = " to be or not to be ";
	cout << a << "\n";
	ReplaceSpace(a);
	cout << a << "\n";
	return 0;
}

void ReplaceSpace(string &str) {
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == ' ') {
			if (i == 0) str = "%20" + str.substr(1);
			else str = str.substr(0, i) + "%20" + str.substr(i+1);
		}
	}
}
