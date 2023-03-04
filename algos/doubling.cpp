#include <bits/stdc++.h>
using namespace std;

struct Doubling
{
  vector<vector<long long>> table;
  long long n, ROW = 60;

  // 0 .. n - 1
  Doubling(vector<long long> a)
  {
    n = a.size();
    table.resize(ROW, vector<long long>(n, 0));
    for (long long i = 0; i < n; i++)
      table[0][i] = a[i];

    for (long long row = 1; row < ROW; row++)
      for (long long i = 0; i < n; i++)
        table[row][i] = table[row - 1][table[row - 1][i]];
  }

  long long query(long long x, long long step)
  {
    long long now = x;
    for (long long i = 0; i < ROW; i++)
      if ((step >> i) & 1)
        now = table[i][now];
    return now + 1;
  }

  void debug()
  {
    for (long long i = 0; i < 6; i++)
    {
      for (long long j = 0; j < n; j++)
        cout << table[i][j] << " ";
      cout << '\n';
    }
  }
};

int main()
{
  long long n, Q, x, y;
  cin >> n >> Q;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i]--;
  }
  Doubling db(a);

  while (Q--)
  {
    cin >> x >> y;
    cout << db.query(x - 1, y) << '\n';
  }

  return 0;
}

// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_be
