#include <cstdio>
#include <cmath>

bool broken[10];

int possible(int n) {
	if (n == 0) {
		return broken[n] ? 0 : 1;
	}

	int len = 0;

	while (n) {
		if (broken[n % 10]) {
			return 0;
		}
		n /= 10;
		++len;
	}
	return len;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n, m;

	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int c;
		scanf("%d", &c);
		broken[c] = true;
	}

	int ans = abs(n - 100);
	for (int i = 0; i < 1000000; ++i) {
		int channel = i;

		int cnt = possible(channel);
		if (cnt > 0) {
			int press = abs(channel - n);
			if (ans > cnt + press)
				ans = cnt + press;
		}
	}
	
	printf("%d\n", ans);

	return 0;
}