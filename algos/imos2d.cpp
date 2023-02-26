#include <bits/stdc++.h>
using namespace std;

template <class T>
struct imos2D
{
  vector<vector<T>> a;
  long long h, w;
  imos2D(long long hh, long long ww) { h = hh, w = ww, a.resize(hh + 2, vector<long long>(ww + 2)); }

  void add(long long x1, long long y1, long long x2, long long y2, T v)
  {
    a[x1][y1] += v;
    a[x2 + 1][y2 + 1] += v;
    a[x1][y2 + 1] -= v;
    a[x2 + 1][y1] -= v;
  }
  void calc()
  {
    for (int y = 0; y < w + 1; y++)
      for (int x = 0; x < h; x++)
        a[x + 1][y] += a[x][y];

    for (int x = 0; x < h + 1; x++)
      for (int y = 0; y < w; y++)
        a[x][y + 1] += a[x][y];
  }

  T query(long long x, long long y) { return a[x][y]; }

  void print()
  {
    for (int i = 1; i < h + 1; i++)
      for (int j = 1; j < w + 1; j++)
        cout << a[i][j] << ((j == w) ? '\n' : ' ');
  }
};

int main()
{
  long long h, w, Q, x1, y1, x2, y2;
  cin >> h >> w >> Q;
  imos2D<long long> im(h, w);
  while (Q--)
  {
    cin >> x1 >> y1 >> x2 >> y2;
    im.add(x1, y1, x2, y2, 1);
  }

  im.calc();
  im.print();

  return 0;
}

// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_i
