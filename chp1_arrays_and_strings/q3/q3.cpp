#include <iostream>
#include <string>
using std::cout;
using std::string;

void RemoveDuplicates(string *);

int main() {
	string a = "aaaaaaaaa";
	cout << a << ": ";
	RemoveDuplicates(&a);
	cout << a << "\n";
	return 0;
}

void RemoveDuplicates(string *str) {
	auto i = str->begin();
	while (i != str->end()) {
		auto j = i + 1;
		while (j != str->end()) {
			while (*j == *i) 
				j = str->erase(j);
			if (j != str->end()) ++j;
		}
		++i;
	}
}
