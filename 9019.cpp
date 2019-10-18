#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

bool check[10000];
int dist[10000];
int from[10000];
char how[10000];

string solve(int a, int b) {
	queue<int> q;
	
	q.push(a);
	check[a] = true; dist[a] = 0; from[a] = -1;
	while (!q.empty()) {
		int n = q.front(); q.pop();

		// D
		int d = (n * 2) % 10000;
		if (!check[d]) {
			q.push(d);
			check[d] = true;
			dist[d] = dist[n] + 1;
			from[d] = n;
			how[d] = 'D';
		}

		// S
		int s = ((n == 0) ? 9999 : n - 1);
		if (!check[s]) {
			q.push(s);
			check[s] = true;
			dist[s] = dist[n] + 1;
			from[s] = n;
			how[s] = 'S';
		}

		// L
		int l = (n % 1000) * 10 + (n / 1000);
		if (!check[l]) {
			q.push(l);
			check[l] = true;
			dist[l] = dist[n] + 1;
			from[l] = n;
			how[l] = 'L';
		}
		
		// R
		int r = (n / 10) + (n % 10) * 1000;
		if (!check[r]) {
			q.push(r);
			check[r] = true;
			dist[r] = dist[n] + 1;
			from[r] = n;
			how[r] = 'R';
		}
	}

	string ans = "";
	int pivot = b;
	while (pivot != a) {
		ans += how[pivot];
		pivot = from[pivot];
	}
	reverse(ans.begin(), ans.end());

	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		memset(check, false, sizeof(check));
		memset(dist, 0, sizeof(dist));
		memset(from, 0, sizeof(from));
		memset(how, 0, sizeof(how));
		int a, b;
		cin >> a >> b;
		cout << solve(a, b) << '\n';
	}

	return 0;
}