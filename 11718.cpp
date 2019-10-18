#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	string s;

	while (getline(cin, s)) {
		cout << s << endl;
	}

	return 0;
}