#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	int n, k;
	scanf("%d %d", &n, &k);

	vector<int> coins(n, 0);
	for (int i = 0; i < n; ++i)
		scanf("%d", &coins[i]);
	sort(coins.begin(), coins.end());

	vector<int> dp(k + 1, 0);
	for (int i = 1; i <= k; ++i) {
		vector<int> candidate;
		for (int j = 0; j < coins.size(); ++j) {
			if (i - coins[j] >= 0) {
				if (dp[i - coins[j]] != -1) {
					candidate.push_back(dp[i - coins[j]]);
				}
				continue;
			}
			break;
		}
		if (candidate.size() == 0)
			dp[i] = -1;
		else
			dp[i] = *min_element(candidate.begin(), candidate.end()) + 1;
	}

	printf("%d\n", dp[k]);

	return 0;
}