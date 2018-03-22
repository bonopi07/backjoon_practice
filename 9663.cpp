#include <iostream>
#include <algorithm>
#include <vector>

int n;
int cnt;

bool isPossible(const std::vector<int>& v, const int row)
{
	int k = 0;

	while (k < row) {
		if (v[k] == v[row] || abs(v[row] - v[k]) == row - k)
			return false;
		++k;
	}
	return true;
}

void nQueen(std::vector<int>& v, const int row)
{
	if (isPossible(v, row)) {
		if (row == n - 1)
			cnt += 1;
		else {
			for (int i = 0; i < n; ++i) {
				v[row + 1] = i;
				nQueen(v, row + 1);
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	std::cin >> n;

	std::vector<int> board(n);

	for (int i = 0; i < n; ++i) {
		board[0] = i;
		nQueen(board, 0);
	}
	
	std::cout << cnt << '\n';

	return 0;
}