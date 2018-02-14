#include <cstdio>

int gcd(int a, int b) {
	if (a == 0)
		return b;
	
	return gcd(b%a, a);
}

int main()
{
	freopen("input.txt", "r", stdin);

	int a, b;

	scanf("%d %d", &a, &b);

	if (a > b) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	int g = gcd(a, b);

	printf("%d\n%d\n", g, a*b / g);


	return 0;
}