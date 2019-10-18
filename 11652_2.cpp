#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

map<ll, int> m;

int main()
{
	//freopen("input.txt", "r", stdin);
	int t; scanf("%d", &t);

	for (int i = 0; i < t; ++i) {
		ll tmp; scanf("%lld", &tmp);

		m[tmp]++;
	}

	pair<ll, int> ans = { 0, 0 };
	for (auto it = m.begin(); it != m.end(); ++it) {
		if (ans.second < it->second) {
			ans.first = it->first;
			ans.second = it->second;
		}
		else if (ans.second == it->second) {
			ans.first = min(ans.first, it->first);
		}
	}

	printf("%lld\n", ans.first);

	return 0;
}