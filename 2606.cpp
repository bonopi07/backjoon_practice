#include <iostream>
#define MAX_N 100

bool visited[MAX_N];
int computer[MAX_N][MAX_N];

void bfs(int n)
{
  if (visited[n])
    return;

  visited[n] = true;

  for (int i = 0; i < MAX_N; ++i) {
    if (computer[n][i]) {
      bfs(i);
    }
  }
}

int main()
{
  freopen("input.txt", "r", stdin);

  int comN, connN;
  std::cin >> comN >> connN;

  std::pair<int, int> _in;
  for (int i = 0; i < connN; ++i) {
    std::cin >> _in.first >> _in.second;
    _in.first -= 1; _in.second -= 1;
    computer[_in.first][_in.second] = computer[_in.second][_in.first] = 1;
  }

  bfs(0);

  int s = 0;
  for (int i = 1; i < comN; ++i) {
    if (visited[i]) {
      ++s;
    }
  }

  std::cout << s << '\n';

  return 0;
}
