#include <cstdio>
#include <algorithm>
#define MAXN 1000000

long long arr[MAXN];

bool desc(const long long &a, const long long &b) {
	return a > b;
}

int main()
{
	freopen("input.txt", "r", stdin);

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%lld", &arr[i]);

	std::sort(arr, arr + n, desc);

	int cnt = 1;
	int max_cnt = 1;
	long long max_value = arr[0];
	for (int i = 0; i < n-1; ++i) {
		if (arr[i] != arr[i + 1]) {
			if (max_cnt <= cnt) {
				max_cnt = cnt;
				max_value = arr[i];
				cnt = 1;
			}
		}
		else
			++cnt;

		if (i == n - 2) {
			if (max_cnt <= cnt) {
				max_cnt = cnt;
				max_value = arr[i];
			}
		}
	}

	printf("%lld\n", max_value);
	return 0;
}