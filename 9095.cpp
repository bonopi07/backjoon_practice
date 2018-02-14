#include <cstdio>
#include <algorithm>
#define MAXN 1001

int dp[MAXN];

int main()
{
	freopen("input.txt", "r", stdin);

	int testCases;
	scanf("%d", &testCases);

	while (testCases--) {
		int n;
		scanf("%d", &n);

		std::fill(dp, dp + MAXN, 0);

		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (int i = 4; i <= n; ++i) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}

		printf("%d\n", dp[n]);
	}

	return 0;
}