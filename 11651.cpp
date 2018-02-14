#include <cstdio>
#include <algorithm>
#define MAXN 100000

typedef struct
{
	int x, y;
}Point;

Point arrN[MAXN];

bool cmpFunc(Point a, Point b)
{
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

int main()
{
	freopen("input.txt", "r", stdin);

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d %d", &arrN[i].x, &arrN[i].y);

	std::sort(arrN, arrN + n, cmpFunc);

	for (int i = 0; i < n; ++i)
		printf("%d %d\n", arrN[i].x, arrN[i].y);

	return 0;
}