#include <cstdio>

int main()
{
	freopen("input.txt", "r", stdin);

	int n;
	scanf("%d", &n);

	int i, sum = 0;
	while (scanf("%1d", &i) == 1) {
		sum += i;
	}
	printf("%d\n", sum);

	return 0;
}