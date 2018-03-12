#include <cstdio>
#include <algorithm>
#define MAXN 5000000

int arr[MAXN];

int main()
{
	freopen("input.txt", "r", stdin);

	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	std::sort(arr, arr + n);

	printf("%d\n", arr[k-1]);

	return 0;
}