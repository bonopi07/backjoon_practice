#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	int t;
	scanf("%d", &t);

	vector<int> v;
	while (t--) {
		int n;
		scanf("%d", &n);
		v.push_back(n);
	}

	int max = *max_element(v.begin(), v.end());
	int min = *min_element(v.begin(), v.end());

	printf("%d %d\n", min, max);

	return 0;
}