#include <iostream>
#include <set>
#include <string>
using std::cout;
using std::set;
using std::string;

bool AllUniqueUsingSet(const string &);
bool AllUniqueInPlace(const string &);

int main() {
	string a = "abcdefag";
	string b = "";
	string c = "abcdefg";
	cout << a << ": " << AllUniqueUsingSet(a) << "\n";
	cout << b << ": " << AllUniqueUsingSet(b) << "\n";
	cout << c << ": " << AllUniqueUsingSet(c) << "\n";
	cout << a << ": " << AllUniqueInPlace(a) << "\n";
	cout << b << ": " << AllUniqueInPlace(b) << "\n";
	cout << c << ": " << AllUniqueInPlace(c) << "\n";
	return 0;
}

bool AllUniqueInPlace(const string &str) {
	auto i = str.begin();
	while (i != str.end()) {
		auto j = i + 1;
		while (j != str.end()) {
			if (*i == *j) return false;
			++j;
		}
		++i;
	}
	return true;
}

bool AllUniqueUsingSet(const string &str) {
	set<char> chars;
	for (auto i : str) {
		if (chars.find(i) == chars.end()) chars.insert(i);
		else return false;
	}	
	return true;
}
