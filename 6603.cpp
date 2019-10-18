#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);

	int k;
	while (true) {
		cin >> k;
		if (k == 0)
			break;

		vector<int> v(k), w(k);
		for (int i = 0; i < k; ++i) {
			cin >> v[i];
			w[i] = 0;
		}
		for (int i = k - 6; i < k; ++i) {
			w[i] = 1;
		}
		
		vector<vector<int>> ans;
		do {
			vector<int> cur;
			for (int i = 0; i < k; ++i) {
				if (w[i]) {
					cur.push_back(v[i]);
				}
			}
			ans.push_back(cur);
		} while (next_permutation(w.begin(), w.end()));

		sort(ans.begin(), ans.end());

		for (auto each : ans) {
			for (int i = 0; i < (int)each.size(); ++i)
				cout << each[i] << ' ';
			cout << '\n';
		}
		cout << '\n';
	}

	return 0;
}