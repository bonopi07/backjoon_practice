#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool visited[10000];  // 1000 ~ 9999¸¸ »ç¿ë
int time[10000];
bool prime[10000];

int convert(int n, int idx, int value) {
	if (idx == 0 && value == 0)
		return -1;
	string s = to_string(n);

	s[idx] = value + '0';

	return stoi(s);
}

int main()
{
	freopen("input.txt", "r", stdin);

	for (int i = 2; i < 10000; ++i) {
		if (prime[i] == false) {
			for (int j = i + i; j < 10000; j += i)
				prime[j] = true;
		}
	}
	for (int i = 2; i < 10000; ++i)
		prime[i] = !prime[i];

	int t;
	cin >> t;

	while (t--) {
		int src, dst;
		cin >> src >> dst;

		memset(visited, false, sizeof(visited));
		memset(time, 0, sizeof(time));

		queue<int> q;
		q.push(src);
		time[src] = 0;
		visited[src] = true;

		while (!q.empty()) {
			int current = q.front();
			q.pop();

			for (int i = 0; i < 4; ++i) {
				for (int j = 0; j < 10; ++j) {
					int tmp = convert(current, i, j);
					if (tmp != -1) {
						if (prime[tmp] && !visited[tmp]) {
							q.push(tmp);
							time[tmp] = time[current] + 1;
							visited[tmp] = true;
						}
					}
				}
			}
		}

		cout << time[dst] << '\n';
	}

	return 0;
}