#include <cstdio>
#include <algorithm>

#define MAX_N 1000001

int dp[MAX_N];

int main()
{
	freopen("input.txt", "r", stdin);

	int n;
	scanf("%d", &n);

	dp[1] = 0;
	for (int i = 2; i <= n; ++i) {
		int min = MAX_N;
		if (i % 3 == 0)
			if (min > dp[i / 3])
				min = dp[i / 3];
		if (i % 2 == 0)
			if (min > dp[i / 2])
				min = dp[i / 2];
		if (min > dp[i - 1])
			min = dp[i - 1];

		dp[i] = min + 1;
	}

	printf("%d\n", dp[n]);

	return 0;
}