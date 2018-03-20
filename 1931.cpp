#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100000

int solve(std::vector<std::pair<int,int>>& v)
{
	int cnt = 1, size = v.size();
	int endTime = v[0].second;
	for (int i = 1; i < size; ++i) {
		if (endTime <= v[i].first) {
			++cnt;
			endTime = v[i].second;
		}
	}
	return cnt;
}

bool sortFunc(std::pair<int, int>& a, std::pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> v(n);

	for (int i = 0; i < n; ++i)
		std::cin >> v[i].first >> v[i].second;

	std::sort(v.begin(), v.end(), sortFunc);

	std::cout << solve(v) << '\n';

	return 0;
}