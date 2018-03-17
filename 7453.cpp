#include <iostream>
#include <algorithm>
#define MAX_N 4000

int a[MAX_N];
int b[MAX_N];
int c[MAX_N];
int d[MAX_N];
int ab[MAX_N*MAX_N];
int cd[MAX_N*MAX_N];

int main()
{
	freopen("input.txt", "r", stdin);
	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
		std::cin >> a[i] >> b[i] >> c[i] >> d[i];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j) {
			ab[i*n + j] = a[i] + b[j];
			cd[i*n + j] = c[i] + d[j];
		}
	}

	std::sort(ab, ab + n * n);
	std::sort(cd, cd + n * n);

	long long cnt = 0;
	for (int i = 0; i < n*n; ++i) {
		int lowBnd = std::lower_bound(cd, cd + n * n, -ab[i]) - cd;
		int uppBnd = std::upper_bound(cd, cd + n * n, -ab[i]) - cd;

		cnt += (uppBnd - lowBnd);
	}
	std::cout << cnt << '\n';

	return 0;
}