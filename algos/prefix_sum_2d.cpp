#include <bits/stdc++.h>
using namespace std;

template <class T>
struct PrefixSum2D
{
  vector<vector<T>> a;
  long long h, w;

  PrefixSum2D(vector<vector<T>> b)
  {
    h = b.size();
    w = b[0].size();
    a.resize(h + 1, vector<long long>(w + 1, 0));

    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        a[i + 1][j + 1] = a[i + 1][j] + b[i][j];

    for (int j = 0; j < w; j++)
      for (int i = 0; i < h; i++)
        a[i + 1][j + 1] += a[i][j + 1];
  }

  // 1 <= x1 <= h, 1 <= y1 <= w, 1 <= x2 <= h, 1 <= y2 <= w
  T query(long long x1, long long y1, long long x2, long long y2)
  {
    return a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1];
  }
};

int main()
{
  long long h, w;
  cin >> h >> w;
  vector<vector<long long>> a(h, vector<long long>(w));
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      cin >> a[i][j];

  PrefixSum2D<long long> ps(a);

  long long Q, x1, y1, x2, y2;
  cin >> Q;
  while (Q--)
  {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << ps.query(x1, y1, x2, y2) << '\n';
  }
  return 0;
}

// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_h
