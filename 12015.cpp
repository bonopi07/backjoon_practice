#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

// {10 20 10 30 20 50} {10
// {3 2 5 2 3 1 4} {1 
int solution(vector <int> seq) {
	int ans = 0;
	int size = seq.size();

	vector<int> v;

	v.push_back(seq[0]);
	for (int i = 1; i < size; ++i) {
		auto idx = lower_bound(v.begin(), v.end(), seq[i]);

		if (idx == v.end())
			v.push_back(seq[i]);
		else
			*idx = seq[i];
	}

	ans = v.size();

	return ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	vector <int> seq(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &seq[i]);
	printf("%d\n", solution(seq));
	return 0;
}