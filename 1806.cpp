#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int a[100000];

int main()
{
	freopen("input.txt", "r", stdin);
	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int ans = n + 1;
	int i = 0, j = 0;
	int sum = a[0];

	while (i <= j && j < n) {
		if (sum <= s) {
			if (sum == s) {
				ans = min(ans, j - i + 1);
			}
			++j;
			if (j == n)
				break;
			sum += a[j];
		}
		else {
			ans = min(ans, j - i + 1);

			sum -= a[i++];
			if (i > j && i < n) {
				j = i;
				sum = a[i];
			}
		}
	}

	if (ans > n) ans = 0;

	cout << ans << '\n';

	return 0;
}