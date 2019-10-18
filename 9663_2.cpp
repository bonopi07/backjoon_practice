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

// row�� �־����� ��, col�� ���鼭 ���� �ΰ� ��������
// Ȯ���Ѵ�. �����ϸ� ������ �ٽ� ���.
// �Ұ����ϸ� �ξ��� ���� ����, ���� col�� Ȯ���Ѵ�.
// ��, 0���ٺ��� Ȯ���ϱ� �ϴµ�, �� ó���� ȣ��� 0���� calc��
// col�� ���� ������ ��쿡�� ���� ���� Ȯ���ϰ�, �׿ܿ��� �Ѿ��.
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