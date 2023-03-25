#include <bits/stdc++.h>
using namespace std;

struct StringHash
{
  long long m, x;
  vector<long long> h, pw;

  StringHash(string s)
  {
    long long n = s.size();
    m = 1000000007;
    x = 199;
    h.resize(n + 1, 0);
    pw.resize(n + 1, 1);

    for (int i = 0; i < n; i++)
    {
      h[i + 1] = (h[i] * x + (s[i] - 'a' + 1)) % m;
      pw[i + 1] = x * pw[i] % m;
    }
  }

  // 1 <= l <= r <= n
  long long get_range(int l, int r)
  {
    long long ret = h[r] - h[l - 1] * pw[r - l + 1] % m;
    return (ret + m) % m;
  }
  // s[a..b] == s[c..d] ?
  bool same(int a, int b, int c, int d)
  {
    return get_range(a, b) == get_range(c, d);
  }
};

int main()
{
  int n, Q, a, b, c, d;
  string s;
  cin >> n >> Q >> s;

  StringHash sh(s);
  while (Q--)
  {
    cin >> a >> b >> c >> d;
    cout << (sh.same(a, b, c, d) ? "Yes" : "No") << endl;
  }
  return 0;
}
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bd
