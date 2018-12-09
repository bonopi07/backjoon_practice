#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int h, w;
  cin >> h >> w;

  vector<int> v(w);
  for (int i = 0; i < w; ++i) {
    cin >> v[i];
  }

  vector<int> left(w), right(w);
  int maxValue = v[0];
  for (int i = 1; i < w; ++i) {
    maxValue = max(maxValue, v[i]);
    left[i] = maxValue;
  }

  maxValue = v[w - 1];
  for (int i = w - 2; i >= 0; --i) {
    maxValue = max(maxValue, v[i]);
    right[i] = maxValue;
  }

  int result = 0;
  for (int i = 1; i < w - 1; ++i) {
    result += min(left[i], right[i]) - v[i];
  }

  cout << result << endl;
  return 0;
}
