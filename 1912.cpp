#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int currSum = v[0];
	int totalSum = v[0];

	for (int i = 1; i < n; ++i) {
		currSum = max(currSum + v[i], v[i]);
		totalSum = max(currSum, totalSum);
	}

	cout << totalSum << endl;

	return 0;
}