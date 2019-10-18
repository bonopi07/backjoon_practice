#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX_N 500000

using namespace std;

vector<pair<int, int>> v(MAX_N);
int main()
{
	freopen("input.txt", "r", stdin);
	int t; scanf("%d", &t);

	for (int i = 0; i < t; ++i) {
		int n; scanf("%d", &n);
		v[i] = make_pair(n, i);
	}

	sort(v.begin(), v.begin() + t);

	int answer = 0;
	for (int i = 0; i < t; ++i) {
		answer = max(v[i].second - i, answer);
	}

	printf("%d\n", answer + 1);
	return 0;
}