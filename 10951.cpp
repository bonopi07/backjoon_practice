#include <cstdio>

int main()
{
	freopen("input.txt", "r", stdin);

	int a, b;

	while (scanf("%d %d", &a, &b) == 2) {
		printf("%d\n", a + b);
	}


	return 0;
}