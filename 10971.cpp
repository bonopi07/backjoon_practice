#include <cstdio>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

vector<vector<int>> cost(10);

int possible(vector<int> v, int n) {
	int sum = 0;

	for (int i = 1; i < n; ++i) {
		if (cost[v[i-1]][v[i]] == 0)
			return 0;
		sum += cost[v[i - 1]][v[i]];
	}
	if (cost[v[n - 1]][v[0]] == 0)
		return 0;
	else
		sum += cost[v[n - 1]][v[0]];
	return sum;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		v[i] = i;
		vector<int> tmp(n);
		for (int j = 0; j < n; ++j) {
			cin >> tmp[j];
		}
		cost[i] = tmp;
	}

	int ans = INT_MAX;
	do {
		if (v[0] != 0)
			break;
		int tmp = possible(v, n);
		if (tmp) {
			ans = min(ans, tmp);
		}
	} while (next_permutation(v.begin() + 1, v.end()));

	cout << ans << '\n';

	return 0;
}