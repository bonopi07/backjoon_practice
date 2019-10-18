#include <cstdio>
#include <string>
#include <iostream>
typedef long long ll;

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	int a, b, c, d;

	cin >> a >> b >> c >> d;

	ll res1 = stoll(to_string(a) + to_string(b));
	ll res2 = stoll(to_string(c) + to_string(d));

	cout << res1 + res2 << '\n';

	return 0;
}