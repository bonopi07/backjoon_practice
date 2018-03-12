#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#define MAXN 100000

typedef struct {
	std::string name;
	int kor;
	int eng;
	int mat;
}Person;

Person arr[MAXN];

bool cmpFunc(const Person &a, const Person &b)
{
	if (a.kor == b.kor) {
		if (a.eng == b.eng) {
			if (a.mat == b.mat)
				return a.name < b.name;
			return a.mat > b.mat;
		}
		return a.eng < b.eng;
	}
	else
		return a.kor > b.kor;
}

int main()
{
	freopen("input.txt", "r", stdin);

	int people;
	scanf("%d", &people);

	for (int i = 0; i < people; ++i) {
		std::cin >> arr[i].name;
		scanf("%d %d %d", &arr[i].kor, &arr[i].eng, &arr[i].mat);
	}

	std::sort(arr, arr + people, cmpFunc);

	for (int i = 0; i < people; ++i)
		std::cout << arr[i].name << '\n';

	return 0;
}