#include <cstdio>
#include <iostream>
using namespace std;

int arr[20];

int solution(int n, int s, int sum, int idx) {
	if (idx == n) {
		if (s == sum)
			return 1;
		return 0;
	}

	int ans = 0;
	ans += solution(n, s, sum + arr[idx], idx+1);
	ans += solution(n, s, sum, idx + 1);

	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int ans = solution(n, s, 0, 0);
	if (s == 0) --ans;

	cout << ans << '\n';

	return 0;
}