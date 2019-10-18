#include <cstdio>
#include <vector>

using namespace std;

long long f[21] = { 1, };
bool c[21];

int main()
{
	for (int i = 1; i <= 20; ++i) {
		f[i] = f[i - 1] * i;
	}

	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);

	int what;
	scanf("%d", &what);

	vector<int> v(n);
	if (what == 1) {
		long long k;
		scanf("%lld", &k);
		for (int i = 0; i < n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (c[j]) {
					continue;
				}
				if (f[n - i - 1] < k) {
					k -= f[n - i - 1];
				}
				else {
					v[i] = j;
					c[j] = true;
					break;
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			printf("%d ", v[i]);
		}
		printf("\n");
	}
	else if (what == 2) {
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		
		long long answer = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 1; j < v[i]; ++j) {
				if (!c[j]) {
					answer += f[n - i - 1];
				}
			}
			c[v[i]] = true;
		}
		printf("%lld\n", answer);
	}

	return 0;
}