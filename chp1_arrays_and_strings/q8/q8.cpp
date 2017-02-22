#include <iostream>
#include <string>
using std::cout;
using std::string;

bool IsRotation(const string &, const string &);

int main() {
	string a = "erbottlewat";
	string b = "waterbottle";
	string c = "watermanele";
	cout << a << " " << b << " " << IsRotation(a, b) << "\n\n";
	cout << a << " " << c << " " << IsRotation(a, c) << "\n\n";
	return 0;
}

bool IsRotation(const string &str1, const string &str2) {
	if (str1.length() == str2.length()) {
		string str1str1 = str1 + str1;
		return str1str1.find(str2) != string::npos;
	} else return false;
}
