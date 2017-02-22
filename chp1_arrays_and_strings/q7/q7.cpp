#include <iostream>
#include <vector>
using std::cout;
using std::vector;

void RemoveRowsAndCols(int [][10]);

int main() {
	int matrix[10][10] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },      
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 }
	};

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) cout << matrix[i][j] << " ";
		cout << "\n";
	}
	cout << "\n\n";

	RemoveRowsAndCols(matrix);

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) cout << matrix[i][j] << " ";
		cout << "\n";
	}
	return 0;
}


void RemoveRowsAndCols(int matrix[10][10]) {
	vector<int> rows;
	vector<int> cols;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (matrix[i][j] == 0) {
				rows.push_back(i);
				cols.push_back(j);
			}
		}
	}

	for (auto i : rows) {
		for (int j = 0; j < 10; ++j)
			matrix[i][j] = 0;
	}

	for (auto j : cols) {
		for (int i = 0; i < 10; ++i)
			matrix[i][j] = 0;
	}
}
