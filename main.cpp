#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 10

int n;
int cost[MAX_N][MAX_N];
std::vector<int> sumCostArr;

bool isVisitedAll(bool visited[])
{
  for (int i = 0; i < n; ++i)
    if (!visited[i])
      return false;

  return true;
}

int dfs(int from, int to, bool visited[])
{
  if (visited[to] == true || isVisitedAll(visited))
    return 0;

  visited[to] = true;
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      return cost[from][to] + dfs(to, i, visited);
    }
  }
  return 0;
}

int getCost(int start)
{
  int sum = 0;
  bool visited[MAX_N] = {false, };

  visited[start] = true;
  for (int i = 0; i < n; ++i) {
    if (i == start)
      continue;

    sum += dfs(start, i, visited);
    sum += cost[i][start];
  }

  return sum;
}

int main()
{
  freopen("input.txt", "r", stdin);

  std::cin >> n;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      scanf("%d", &cost[i][j]);

  for (int i = 0; i < n; ++i) {
    sumCostArr.push_back(getCost(i));
  }
  auto _min = std::min_element(sumCostArr.begin(), sumCostArr.end());

  std::cout << *_min << '\n';

  return 0;
}
