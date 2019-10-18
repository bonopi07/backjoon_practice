#include <cstdio>
#include <iostream>
using namespace std;

int arr[10000];

int main()
{
	freopen("input.txt", "r", stdin);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int i = 0, j = 0;
	int sum = arr[0];
	int ans = 0;

	while (i <= j && j < n) {
		if (sum < m) {
			sum += arr[++j];
		}
		else if (sum == m) {
			++ans;
			sum += arr[++j];
		}
		else if (sum > m) {
			sum -= arr[i++];
			if (i > j) {
				j = i;
				sum = arr[i];
			}
		}
	}

	cout << ans << '\n';

	return 0;
}