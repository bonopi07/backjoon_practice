#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<long long> dp(n+1, 0);
	
	if (n >= 3)
		dp[3] = 2;
	if (n >= 2)
		dp[2] = 1;
	if (n >= 1)
		dp[1] = 1;

	vector<long long> dp_dp(n+1, 0);
	
	if (n >= 3)
		dp_dp[3] = 1;

	for (int i = 4; i <= n; ++i) {
		dp_dp[i] = dp_dp[i - 1] + dp_dp[i - 2];
		dp[i] = dp[i - 1] + dp_dp[i];
	}


	cout << dp[n] << endl;

	return 0;
}