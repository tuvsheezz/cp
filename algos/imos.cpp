#include <bits/stdc++.h>
using namespace std;

template <class T>
struct Imos
{
  vector<T> a;
  long long n;

  Imos(long long nn) { n = nn, a.resize(nn + 1, 0); }

  void set(long long l, long long r, long long val)
  {
    a[l - 1] += val;
    a[r] -= val;
  }

  void calc()
  {
    for (int i = 0; i < n; i++)
      a[i + 1] += a[i];
  }
  T query(long long ind) { return a[ind]; }
};

int main()
{
  long long n, Q, l, r;
  cin >> n >> Q;
  Imos<long long> im(n);
  while (Q--)
  {
    cin >> l >> r;
    im.set(l, r, 1);
  }
  im.calc();

  for (int i = 0; i < n; i++)
  {
    cout << im.query(i) << " ";
  }
  cout << '\n';
  return 0;
}

// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_g
