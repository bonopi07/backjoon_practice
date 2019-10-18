#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 10000

using namespace std;

vector<int> v(MAX_N);

int main()
{
	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
	}

	if (next_permutation(v.begin(), v.begin() + n)) {
		for (int i = 0; i < n; ++i)
			printf("%d ", v[i]);
		printf("\n");
	}
	else {
		printf("-1\n");
	}

	

	return 0;
}