#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<char> v(15);

bool check(string s) {
	int ja = 0, mo = 0;
	for (auto each : s) {
		if (each == 'a' || each == 'e' || each == 'i' || each == 'o' || each == 'u') {
			++mo;
		}
		else {
			++ja;
		}
	}
	return (ja >= 2 && mo >= 1);
}

void go(int l, string pw, int idx, int size) {
	if (pw.size() == l) {
		if (check(pw)) {
			cout << pw << '\n';
		}
		return;
	}

	if (idx >= size) return;
	go(l, pw + v[idx], idx + 1, size);
	go(l, pw, idx + 1, size);
}

int main()
{
	freopen("input.txt", "r", stdin);
	int l, c;
	cin >> l >> c;

	for (int i = 0; i < c; ++i) {
		cin >> v[i];
	}

	sort(v.begin(), v.begin() + c);
	go(l, "", 0, c);

	return 0;
}