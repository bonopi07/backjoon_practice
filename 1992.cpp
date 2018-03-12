#include <cstdio>
#define MAXN 64

char a[MAXN][MAXN];

bool isChecked(int start_row, int start_col, int end_row, int end_col, int pivot)
{
	for (int i = start_row; i <= end_row; ++i) {
		for (int j = start_col; j <= end_col; ++j) {
			if (pivot != a[i][j]-'0') {
				return false;
			}
		}
	}

	return true;
}

void dnc(int start_row, int start_col, int end_row, int end_col, int n)
{
	int pivot = a[start_row][start_col] - '0';

	if (start_row >= end_row || start_col >= end_col) {
		printf("%d", pivot);
		return;
	}
	
	if (isChecked(start_row, start_col, end_row, end_col, pivot))
		printf("%c", pivot + '0');
	else {
		int m = n / 2;
		printf("(");
		dnc(start_row, start_col, start_row + m - 1, start_col + m - 1, m);
		dnc(start_row, start_col + m, start_row + m - 1, end_col, m);
		dnc(start_row + m, start_col, end_row, start_col + m - 1, m);
		dnc(start_row + m, start_col + m, end_row, end_col, m);
		printf(")");
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%s", a[i]);

	dnc(0, 0, n-1, n-1, n);
	printf("\n");

	return 0;
}