
#include <bits/stdc++.h>

using namespace std;
#define PI 3.141592653589793238462643383279502884L
#define LL long long
#define DD double
#define ULL unsigned long long
#define STR string
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
#define MLL map<LL, LL>
#define MSL map<STR, LL>
#define MLB map<LL, bool>
template <class T>
using PQA = priority_queue<T, V<T>, greater<T>>;
template <class T>
using PQD = priority_queue<T, V<T>, less<T>>;
#define IT iterator
#define F first
#define S second
#define PB push_back
#define PLL pair<LL, LL>
#define MP make_pair
#define rep(i, e) for (LL i = 0; i < e; i++)
#define repa(i, s, e) for (LL i = s; i < e; i++)
#define repd(i, s, e) for (LL i = s; i >= e; i--)
#define repauto(x, s) for (auto x : s)
#define rd(...) \
  __VA_ARGS__;  \
  read(__VA_ARGS__)
#define rdv(value, ...) \
  value(__VA_ARGS__);   \
  cin >> value
template <class T>
auto &operator>>(istream &is, vector<T> &xs)
{
  for (auto &x : xs)
    is >> x;
  return is;
}
template <class T>
auto &operator<<(ostream &os, vector<T> &xs)
{
  int sz = xs.size();
  rep(i, sz) os << xs[i] << " \n"[i + 1 == sz];
  return os;
}
template <class T, class Y>
auto &operator<<(ostream &os, pair<T, Y> &xs)
{
  os << "{" << xs.first << ", " << xs.second << "}";
  return os;
}
template <class T, class Y>
auto &operator>>(istream &is, vector<pair<T, Y>> &xs)
{
  for (auto &[x1, x2] : xs)
    is >> x1 >> x2;
  return is;
}
template <class... Args>
auto &read(Args &...args) { return (cin >> ... >> args); }
#define vsorta(v) sort(v.begin(), v.end())
#define vsortd(v) sort(v.begin(), v.end(), greater<>())
#define sort_arr(v, n) sort(v, v + n)
#define rev(v) reverse(v.begin(), v.end())
#define pr(x) cout << x
#define prs(x) cout << x << ' '
#define prn(x) cout << x << '\n'
#define prd() cout << fixed << setprecision(50);
#define Yes cout << "Yes\n"
#define YES cout << "YES\n"
#define No cout << "No\n"
#define NO cout << "NO\n"
#define PN cout << '\n'
#define PS cout << ' '
#define INF (1LL << 60)
#define MOD1 1000000007
#define MOD2 998244353
#define MAX_N 100100

using namespace std;

// int main()
// {
//   LL rd(n);
//   VV<LL> a(n, V<LL>(n, 0));
//   VV<LL> b(n, V<LL>(n, 0));
//   VV<LL> c(n, V<LL>(n, 0));

//   {
//     LL rd(ma);
//     rep(i, ma)
//     {
//       LL rd(x, y);
//       a[x - 1][y - 1] = 1;
//     }
//   }
//   {
//     LL rd(ma);
//     rep(i, ma)
//     {
//       LL rd(x, y);
//       b[x - 1][y - 1] = 1;
//     }
//   }

//   rep(i, n)
//   {
//     repa(j, i + 1, n)
//     {
//       LL rd(x);
//       c[i][j] = x;
//       c[j][i] = x;
//     }
//   }

//   V<LL> x;
//   rep(i, n) x.push_back(i);
//   LL ans = INF;
//   do
//   {
//     LL cost = 0;
//     rep(i, n) rep(j, n)
//     {
//       if (a[x[i]][x[j]] != b[i][j])
//         cost += c[i][j];
//     }
//     ans = min(cost, ans);
//   } while (next_permutation(x.begin(), x.end()));
//   prn(ans / 2);
//   return 0;
// }

int main()
{
  LL rd(n);
  V<LL> rdv(a, n);
  V<LL> prev(n + 1, 0);
  LL ans = 0;
  rep(i, n)
  {
    LL len = n - prev[a[i]];
    ans += len * (len + 1) / 2;

    prev[a[i]] = i + 1;
  }
  prn(ans);
  return 0;
}