#include <cstdio>
#include <iostream>
#include <utility>

#define MAX_N 1000
#define MAX_M 1000

using namespace std;

bool visited[MAX_N][MAX_M] = { false, };
int arr[MAX_N][MAX_M];

int hw(int n, int m)
{
	// front-view
	for (int j = 0; j < m; ++j) {
		int maxValue = -1;
		pair<int, int> p;
		for (int i = 0; i < n; ++i) {
			if (maxValue <= arr[i][j]) {
				maxValue = arr[i][j];
				p = make_pair(i, j);
			}
		}
		visited[p.first][p.second] = true;
	}

	// side-view
	for (int i = 0; i < n; ++i) {
		int maxValue = -1;
		pair<int, int> p;
		for (int j = 0; j < m; ++j) {
			if (maxValue <= arr[i][j]) {
				maxValue = arr[i][j];
				p = make_pair(i, j);
			}
		}
		visited[p.first][p.second] = true;
	}

	// sum
	int result = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (visited[i][j] == false) {
				result += arr[i][j];
			}
		}
	}

	return result;
}

int main()
{
	freopen("input.txt", "r", stdin);

	int n, m; scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			scanf("%d", &arr[i][j]);
	}

	cout << hw(n, m) << endl;

	return 0;
}