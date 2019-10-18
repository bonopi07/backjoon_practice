#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

char board[20][20];
bool check[20][20];
bool alpha[20];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int solution(int r, int c, int x, int y, int step) {
	int ans = 1;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < r && ny >= 0 && ny < c) { // 갈 수 있는지 확인
			if (!check[nx][ny] && !alpha[board[nx][ny]-'A']) { // 안간 알파벳이면
				check[nx][ny] = true;
				alpha[board[nx][ny] - 'A'] = true;
				ans = max(ans, solution(r, c, nx, ny, step + 1));
				check[nx][ny] = false;
				alpha[board[nx][ny] - 'A'] = false;
			}
			else {
				ans = max(ans, step);
			}
		}
	}
	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int r, c;
	scanf("%d %d\n", &r, &c);

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			scanf("%c ", &board[i][j]);
		}
	}

	check[0][0] = true;
	alpha[board[0][0] - 'A'] = true;
	printf("%d\n", solution(r, c, 0, 0, 1));

	return 0;
}