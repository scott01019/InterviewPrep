#include <iostream>
#include <string>
#include <unordered_map>
using std::cout;
using std::string;
using std::unordered_map;

bool Anagrams(const string &, const string &);

int main() {
	string a = "abcdefgascbsfsdfc";
	string b = "abcdefgascdfscfsdfsdfs";
	cout << a << ", " << a << " " << Anagrams(a, a) << "\n";
	cout << a << ", " << b << " " << Anagrams(a, b) << "\n";
	cout << b << ", " << b << " " << Anagrams(b, b) << "\n";
	return 0;
}

bool Anagrams(const string &str1, const string & str2) {
	unordered_map<char, int> str1_count;
	for (auto i : str1)
		if (str1_count.find(i) == str1_count.end()) {
			str1_count[i] = 1;
		} else {
			str1_count[i] += 1;
		}

	for (auto i : str2)
		if (str1_count.find(i) == str1_count.end()) return false;
		else if (str1_count[i] == 1) str1_count.erase(i);
		else str1_count[i] -= 1;

	return !str1_count.size();
}
