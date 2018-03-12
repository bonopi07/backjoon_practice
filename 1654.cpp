#include <cstdio>
#include <algorithm>
#include <limits>
#define MAX_K 10000

int lanList[MAX_K];
int k, n; // 랜선 개수, 필요한 랜선 개수

long long bs(long long start, long long end)
{
	if (start > end)
		return 0;

	long long mid = (start + end) / 2;

	long long result = 0;
	for (int i = 0; i < k; ++i) {
		result += lanList[i] / mid;
	}

	if (result >= n) {
		return std::max(bs(mid + 1, end), mid);
	}
	else {
		return bs(start, mid - 1);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	int maxValue = 0;

	scanf("%d %d", &k, &n);
	for (int i = 0; i < k; ++i) {
		scanf("%d", &lanList[i]);
		if (maxValue < lanList[i])
			maxValue = lanList[i];
	}

	printf("%lld\n", bs(1, maxValue));

	return 0;
}