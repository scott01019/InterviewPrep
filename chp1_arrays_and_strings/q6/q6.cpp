#include <iostream>
using std::cout;

void RotateMatrix(int [][5]);

int main() {
	int matrix[][5] = {
		{ 0, 1, 2, 3, 4 },
		{ 5, 6, 7, 8, 9 },
		{ 10, 11, 12, 13, 14 },
		{ 15, 16, 17, 18, 19 },
		{ 20, 21, 22, 23, 24 }
	};
	
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) cout << matrix[i][j] << "\t";
		cout << "\n";
	} cout << "\n\n";

	RotateMatrix(matrix);

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) cout << matrix[i][j] << "\t";
		cout << "\n";
	}
}

void RotateMatrix(int matrix[][5]) {
	int start_row = 0;
	int end_row = 4;
	int start_col = 0;
	int end_col = 4;
	int max_layer = 2;
	for (int layer = 0; layer < max_layer; ++layer) {
		for (int i = 0; i < end_row - start_row; ++i) {
			int temp = matrix[start_row][start_col + i];
			matrix[start_row][start_col + i] = matrix[end_row - i][start_col];
			matrix[end_row - i][start_col] = matrix[end_row][end_col - i];
			matrix[end_row][end_col - i] = matrix[start_row + i][end_col];
			matrix[start_row+i][end_col] = temp;
		}
		++start_row;
		++start_col;
		--end_row;
		--end_col;
	}
}
