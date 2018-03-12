#include <cstdio>
#include <algorithm>

int visited[10001];

int main()
{
	//freopen("input.txt", "r", stdin);
	int n, _n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &_n);
		visited[_n] += 1;
	}

	for (int i = 1; i <= 10000; ++i) {
		if (visited[i]) {
			for (int j = 1; j <= visited[i]; ++j)
				printf("%d\n", i);
		}
	}

	return 0;
}