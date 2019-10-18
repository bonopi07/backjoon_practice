#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	vector<int> v;

	int a = 0, b = 0;
	for (int a = 0; a <= n/3; ++a) {
		for (int b = 0; b <= n/5; ++b) {
			if (3 * a + 5 * b == n)
				v.push_back(a + b);
		}
	}

	int result;
	if (v.size() == 0)
		result = -1;
	else
		result = *min_element(v.begin(), v.end());
	printf("%d\n", result);

	return 0;
}