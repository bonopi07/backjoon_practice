#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v(8);

int calculate(int n) {
	int sum = 0;
	for (int i = 0; i < n - 1; ++i) {
		sum += abs(v[i] - v[i + 1]);
	}
	return sum;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.begin() + n);

	int ans = 0;
	do {
		int value = calculate(n);
		ans = max(ans, value);
	} while (next_permutation(v.begin(), v.begin() + n));

	cout << ans << '\n';

	return 0;
}