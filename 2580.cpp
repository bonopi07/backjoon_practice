#include <cstdio>
#include <iostream>
using namespace std;

int board[9][9];
bool cr[9][10]; // i행에 j값이 있으면 true
bool cc[9][10]; // i열에 j값이 있으면 true
bool cb[9][10]; // i번째 박스에 j값이 있으면 true

bool check(int r, int c, int n) {
	if (cr[r][n])
		return false;

	if (cc[c][n])
		return false;

	if (cb[(r / 3) * 3 + (c / 3)][n])
		return false;

	return true;
}

void solution(int row, int col) {
	if (row == 9) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}
	if (col == 9) {
		solution(row + 1, 0);
		return;
	}
	if (board[row][col]) {
		solution(row, col + 1);
		return;
	}
	for (int n = 1; n < 10; ++n) {
		if (check(row, col, n)) {
			board[row][col] = n;
			cr[row][n] = true;
			cc[col][n] = true;
			cb[(row / 3) * 3 + (col / 3)][n] = true;
			solution(row, col + 1);
			board[row][col] = 0;
			cr[row][n] = false;
			cc[col][n] = false;
			cb[(row / 3) * 3 + (col / 3)][n] = false;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (board[i][j]) {
				cr[i][board[i][j]] = true;
				cc[j][board[i][j]] = true;
				cb[(i / 3) * 3 + (j / 3)][board[i][j]] = true;
			}
		}
	}

	solution(0, 0);

	return 0;
}