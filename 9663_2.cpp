#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

bool board[15][15];
bool check_col[15];
bool check_dig[40];
bool check_dig2[40];
int ans, n;


bool check(int r, int c) {
	// up direction
	if (check_col[c])
		return false;

	// up-left direction
	if (check_dig[r + c])
		return false;

	// up-right direction
	if (check_dig2[r - c + n])
		return false;

	return true;
}

// row가 주어졌을 때, col을 돌면서 퀸을 두고 가능한지
// 확인한다. 가능하면 다음줄 다시 계산.
// 불가능하면 두었던 퀸을 빼고, 다음 col을 확인한다.
// 즉, 0번줄부터 확인하긴 하는데, 맨 처음에 호출된 0번줄 calc은
// col에 대해 정해진 경우에만 다음 줄을 확인하고, 그외에는 넘어간다.
void calc(int row) {
	if (row == n) {
		++ans;
	}
	for (int col = 0; col < n; ++col) {
		if (check(row, col)) {
			check_dig[row + col] = true;
			check_dig2[row - col + n] = true;
			check_col[col] = true;
			board[row][col] = true;
			calc(row + 1);
			check_dig[row + col] = false;
			check_dig2[row - col + n] = false;
			check_col[col] = false;
			board[row][col] = false;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> n;

	calc(0);

	cout << ans << '\n';

	return 0;
}