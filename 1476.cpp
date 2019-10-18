#include <cstdio>

int main()
{
	freopen("input.txt", "r", stdin);

	int E, S, M;
	scanf("%d %d %d", &E, &S, &M);

	int answer = 1;
	int e = 1, s = 1, m = 1;

	while (true) {
		if (e == E && s == S && m == M)
			break;

		++answer;
		++e; ++s; ++m;

		if (e > 15) e = 1;
		if (s > 28) s = 1;
		if (m > 19) m = 1;
	}
	printf("%d\n", answer);

	return 0;
}