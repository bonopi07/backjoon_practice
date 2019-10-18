#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#define MAX_N 100001
using namespace std;

bool visited[MAX_N];
queue<int> q;

int main()
{
	freopen("input.txt", "r", stdin);

	int n, k;
	cin >> n >> k;

	q.push(n);
	visited[n] = true;

	int time = 0;
	bool ok = false;
	int location;
	while (!q.empty()) {
		vector<int> v;
		while (!q.empty()) {
			location = q.front();
			q.pop();

			if (location == k) {
				ok = true;
				break;
			}

			
			if (location - 1 >= 0 && !visited[location - 1]) {
				v.push_back(location - 1);
				visited[location - 1] = true;
			}
			if (location + 1 < MAX_N && !visited[location + 1]) {
				v.push_back(location + 1);
				visited[location + 1] = true;
			}
			if (2 * location < MAX_N && !visited[2 * location]) {
				v.push_back(2 * location);
				visited[2 * location] = true;
			}
		}
		if (ok)
			break;

		for (auto each : v)
			q.push(each);
		++time;
	}
	cout << time << '\n';

	return 0;
}