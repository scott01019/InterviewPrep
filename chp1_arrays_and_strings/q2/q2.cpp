// Reverse a C-Style String
#include <iostream>
using std::cout;

void reverse_cstring(char *);

int main() {
	char a[] = "abcdefg";
	char b[] = "";
	char c[] = "abcdef";
	cout << a << ": ";
 	reverse_cstring(a); 
	cout << a << "\n";
	cout << b << ": ";
 	reverse_cstring(b);
  cout	<< "\n";
	cout << c << ": ";
 	reverse_cstring(c); 
	cout << c << "\n";
	return 0;
}

void reverse_cstring(char *str) {
	char *end = str;
	while (*end != '\0') {
		++end;
	}
	--end;
	while (str < end) {
		char temp = *str;
		*str = *end;
		*end = temp;
		str++;
		--end;
	}
}
