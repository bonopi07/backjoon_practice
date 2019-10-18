#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

bool prime[4000001];
int a[1000000];

int main() {
	int n;
	cin >> n;

	// 소수 구하기
	for (int i = 2; i <= sqrt(n); ++i) {
		if (!prime[i]) {
			for (int j = i+i; j <= n; j += i) {
				prime[j] = true;
			}
		}
	}

	int cnt = 0;
	for (int i = 2; i <= n; ++i) {
		prime[i] = !prime[i];
		if (prime[i]) {
			a[cnt++] = i;
		}
	}

	int i = 0, j = 0, sum = a[0], ans = 0;
	while (i <= j && j < cnt) {
		if (sum <= n) {
			if (sum == n) {
				++ans;
			}
			++j;
			if (j == cnt)
				break;
			sum += a[j];
		}
		else {
			sum -= a[i++];
			if (i > j && i == cnt)
				break;
		}
	}

	cout << ans << '\n';

	return 0;
}