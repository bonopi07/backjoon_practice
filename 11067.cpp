#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ascCmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;  // base case
}

bool descCmp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second > b.second;
}

void hw(vector<pair<int, int>>& v, int noCafe)
{
	// 1. �켱 ��������
	sort(v.begin(), v.end(), ascCmp);

	// 2. �κ� ��������
	int targetX = 0, targetY = 0;
	vector<pair<int, int>> tmpV;
	for (int i = 0; i < noCafe; ++i) {
		if ((i < noCafe-1) && (v[i].first == v[i + 1].first)) {  // ��������or�������� �����ؾ� ��
			tmpV.push_back(v[i]);
		}
		else {
			if (tmpV.size() != 0) {
				tmpV.push_back(v[i]);  // x���� �ٲ�� �� ������ ���� �ֱ�

				// x���� ���� ��ǥ �߿��� y ���� ���� min, max�� ã��
				int minValue, maxValue;
				for (int j = 1, minValue=maxValue=tmpV[0].second; j < tmpV.size(); ++j) {
					if (minValue > tmpV[j].second)
						minValue = tmpV[j].second;
					else if (maxValue < tmpV[j].second)
						maxValue = tmpV[j].second;
				}
				
				if (targetY == maxValue) {  // ������������ �ٲٱ�
					sort(tmpV.begin(), tmpV.end(), descCmp);
					swap_ranges(tmpV.begin(), tmpV.end(), v.begin() + targetX);
				}

				tmpV.clear();
			}
			targetX = i+1;
			targetY = v[i].second;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	int testCase;
	scanf("%d", &testCase);

	while (testCase--) {
		// ī�� ����
		int n;
		scanf("%d", &n);

		// ī�� ��ǥ �Է�
		vector<pair<int, int>> v;
		for (int i = 0; i < n; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			v.push_back(make_pair(a, b));
		}

		// �ñ��� ī�� ��ġ �޾ƿ���
		int questionCnt;
		scanf("%d", &questionCnt);

		vector<int> qv;
		for (int i = 0; i < questionCnt; ++i) {
			int a;
			scanf("%d", &a);
			qv.push_back(a);
		}

		hw(v, n);

		// ��� Ȯ��

		for (auto n : qv)
			cout << v[n-1].first << ' ' << v[n-1].second << endl;

	}

	return 0;
}