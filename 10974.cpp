#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX_N 8

using namespace std;

vector<int> v(MAX_N);

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		v[i] = i + 1;

	do {
		for (int i = 0; i < n; ++i) {
			printf("%d ", v[i]);
		}
		printf("\n");
	} while (next_permutation(v.begin(), v.begin() + n));

	return 0;
}