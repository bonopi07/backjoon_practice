#include <cstdio>
#include <algorithm>
#define MAXN 100000

typedef struct {
	int age;
	char name[101];
}Person;

Person arr[MAXN];

bool cmpFunc(Person a, Person b)
{
	return a.age < b.age;
}

int main()
{
	freopen("input.txt", "r", stdin);

	int people;
	scanf("%d", &people);

	for (int i = 0; i < people; ++i) {
		scanf("%d %s", &arr[i].age, arr[i].name);
	}

	std::stable_sort(arr, arr + people, cmpFunc);

	for (int i = 0; i < people; ++i) {
		printf("%d %s\n", arr[i].age, arr[i].name);
	}

	return 0;
}