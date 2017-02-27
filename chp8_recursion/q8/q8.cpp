#include <iostream>
using std::cout;

bool CheckBoard(int **);
void PrintBoard(int **);
void PrintQueens();
void PrintQueensHelper(int **, int, int);

int main() {
	PrintQueens();
	return 0;
}

bool CheckBoard(int **board) {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (board[i][j] == 1) {
				for (int row = 0; row < 8; ++row)
					if (i != row && board[row][j] == 1) return false;
				for (int col = 0; col < 8; ++col)
					if (j != col && board[i][col] == 1) return false;
				for (int tl = 1; i - tl >= 0 && j - tl >= 0; ++tl)
					if (board[i-tl][j-tl] == 1) return false;
				for (int tr = 1; i + tr < 8 && j - tr >= 0; ++tr)
				 if (board[i+tr][j-tr] == 1) return false;
				for (int bl = 1; i - bl >= 0 && j + bl < 8; ++bl)
					if (board[i-bl][j+bl] == 1) return false;
				for (int br = 1; i + br < 8 && j + br < 8; ++br)
					if (board[i+br][j+br] == 1) return false;	
			}
		}
	}
	return true;
}

void PrintBoard(int **board) {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			cout << board[i][j] << " ";
		} cout << "\n";
	}
	cout << "\n\n";
}

void PrintQueens() {
	int **board = new int *[8];
	for (int i = 0; i < 8; ++i) board[i] = new int[8];
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j) board[i][j] = 0;
	PrintQueensHelper(board, 0, 0);
}

void PrintQueensHelper(int **board, int row, int col) {
	if (row >= 8 && CheckBoard(board)) PrintBoard(board);
	else if (row < 8 && col < 8) {
		board[row][col] = 1;
		PrintQueensHelper(board, row+1, 0);
		board[row][col] = 0;
		PrintQueensHelper(board, row, col+1);
	}
}
