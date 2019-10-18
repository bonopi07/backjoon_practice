#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
vector<vector<int>> board(3);

int convert() {
	string s = "";
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			s += to_string(board[i][j]);
		}
	}
	return stoi(s);
}

void update(int n) {
	string s = to_string(n);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			board[i][j] = s[3 * i + j] - '0';
		}
	}
}

void find_9(int &x, int &y) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (board[i][j] == 9) {
				x = i, y = j;
				return;
			}
		}
	}
}

int bfs() {
	queue<int> q;
	map<int, int> m;

	int sign = convert();
	q.push(sign);
	m[sign] = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		update(now);

		if (now == 123456789)
			break;

		// 9 Ã£±â
		int x, y;
		find_9(x, y);

		for (int i = 0; i < 4; ++i) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x >= 0 && next_x < 3 && next_y >= 0 && next_y < 3) {
				int tmp = board[x][y];
				board[x][y] = board[next_x][next_y];
				board[next_x][next_y] = tmp;

				sign = convert();
				if (m.find(sign) == m.end()) {
					q.push(sign);
					m[sign] = m[now] + 1;
				}

				tmp = board[x][y];
				board[x][y] = board[next_x][next_y];
				board[next_x][next_y] = tmp;
			}
		}
	}
	if (m.find(123456789) == m.end())
		return -1;
	else
		return m[123456789];
}

int main()
{
	freopen("input.txt", "r", stdin);
	for (int i = 0; i < 3; ++i) {
		vector<int> tmp(3);
		for (int j = 0; j < 3; ++j) {
			cin >> tmp[j];
			if (tmp[j] == 0)
				tmp[j] = 9;
		}
		board[i] = tmp;
	}

	cout << bfs() << '\n';

	return 0;
}