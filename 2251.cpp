#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool check[201][201];
bool ans[201];

int main()
{
	freopen("input.txt", "r", stdin);
	int a, b, c;
	cin >> a >> b >> c;

	queue<pair<int, int>> q;

	q.push(make_pair(0, 0));
	check[0][0] = true;
	ans[c] = true;

	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();

		int nx = now.first, ny = now.second, nz = c - nx - ny;
		// x -> y
		ny += nx; nx = 0;
		if (ny >= b) {
			nx = ny - b;
			ny = b;
		}
		if (!check[nx][ny]) {
			q.push(make_pair(nx, ny));
			check[nx][ny] = true;
			if (nx == 0)
				ans[nz] = true;
		}

		nx = now.first, ny = now.second, nz = c - nx - ny;
		// x -> z
		nz += nx; nx = 0;
		if (nz >= c) {
			nx = nz - c;
			nz = c;
		}
		if (!check[nx][ny]) {
			q.push(make_pair(nx, ny));
			check[nx][ny] = true;
			if (nx == 0)
				ans[nz] = true;
		}

		nx = now.first, ny = now.second, nz = c - nx - ny;
		// y -> x
		nx += ny; ny = 0;
		if (nx >= a) {
			ny = nx - a;
			nx = a;
		}
		if (!check[nx][ny]) {
			q.push(make_pair(nx, ny));
			check[nx][ny] = true;
			if (nx == 0)
				ans[nz] = true;
		}

		nx = now.first, ny = now.second, nz = c - nx - ny;
		// y -> z
		nz += ny; ny = 0;
		if (nz >= c) {
			ny = nz - c;
			nz = c;
		}
		if (!check[nx][ny]) {
			q.push(make_pair(nx, ny));
			check[nx][ny] = true;
			if (nx == 0)
				ans[nz] = true;
		}

		nx = now.first, ny = now.second, nz = c - nx - ny;
		// z -> x
		nx += nz; nz = 0;
		if (nx >= a) {
			nz = nx - a;
			nx = a;
		}
		if (!check[nx][ny]) {
			q.push(make_pair(nx, ny));
			check[nx][ny] = true;
			if (nx == 0)
				ans[nz] = true;
		}

		nx = now.first, ny = now.second, nz = c - nx - ny;
		// z -> y
		ny += nz; nz = 0;
		if (ny >= b) {
			nz = ny - b;
			ny = b;
		}
		if (!check[nx][ny]) {
			q.push(make_pair(nx, ny));
			check[nx][ny] = true;
			if (nx == 0)
				ans[nz] = true;
		}
	}

	for (int i = 0; i <= c; ++i) {
		if (ans[i])
			cout << i << ' ';
	}
	cout << '\n';
	return 0;
}