#include <cstdio>
#include <cstring>

int main()
{
	freopen("input.txt", "r", stdin);
	int s = 0;

	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		char c[10];
		scanf("%s", c);

		if (strcmp("add", c) == 0) {
			scanf("%d", &n);
			s = s | (1 << (n - 1));
		}
		else if (strcmp("remove", c) == 0) {
			scanf("%d", &n);
			s = s & ~(1 << (n - 1));
		}
		else if (strcmp("check", c) == 0) {
			scanf("%d", &n);
			if ((s & (1 << (n - 1))))
				printf("1");
			else
				printf("0");
			printf("\n");
		}
		else if (strcmp("toggle", c) == 0) {
			scanf("%d", &n);
			s = s ^ (1 << (n - 1));
		}
		else if (strcmp("all", c) == 0) {
			s = (1 << 20) - 1;
		}
		else if (strcmp("empty", c) == 0) {
			s = 0;
		}
	}

	return 0;
}