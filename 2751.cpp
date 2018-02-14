#include <cstdio>
#include <algorithm>
#define MAXN 1000000

int arr[MAXN];

int main()
{
	freopen("input.txt", "r", stdin);

	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	std::sort(arr, arr + n);

	for (int i = 0; i < n; ++i)
		printf("%d\n", arr[i]);

	return 0;
}