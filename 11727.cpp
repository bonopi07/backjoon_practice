#include <cstdio>
#define MAXN 1001

int dp[MAXN];

int main()
{
	freopen("input.txt", "r", stdin);

	int n;
	scanf("%d", &n);

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1] + 2 * dp[i - 2];
		dp[i] %= 10007;
	}

	printf("%d\n", dp[n]);
}