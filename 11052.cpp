#include <cstdio>
#define MAXN 1001

int dp[MAXN];
int p[MAXN];

int main()
{
	freopen("input.txt", "r", stdin);

	int count;
	scanf("%d", &count);

	for (int i = 1; i <= count; ++i)
		scanf("%d", &p[i]);

	dp[0] = 0;
	dp[1] = p[1];
	for (int i = 2; i <= count; ++i) {
		int max = 0;
		for (int j = 0; j < i; ++j) {
			if (max < dp[j] + p[i - j])
				max = dp[j] + p[i - j];
		}
		dp[i] = max;
	}

	printf("%d\n", dp[count]);

	return 0;
}