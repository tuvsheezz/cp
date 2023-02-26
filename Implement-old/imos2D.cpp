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
#define prd(x) cout << fixed << setprecision(50) << x
#define Yes cout << "Yes\n"
#define YES cout << "YES\n"
#define No cout << "No\n"
#define NO cout << "NO\n"
#define PN cout << '\n'
#define PS cout << ' '
#define Ret return 0
#define ret return
#define INF (1LL << 60)
#define MOD1 1000000007
#define MOD2 998244353
#define MAX_N 100100

template <class T>
struct imos2D
{
  vector<vector<T>> a;
  long long h, w;
  void init(long long hh, long long ww) { h = hh, w = ww, a.resize(hh, vector<long long>(ww)); }

  void add(long long x1, long long y1, long long x2, long long y2, T v)
  {
    a[x1][y1] += v;
    a[x2 + 1][y2 + 1] += v;
    a[x1][y2 + 1] -= v;
    a[x2 + 1][y1] -= v;
  }
  void calc()
  {
    rep(y, w) rep(x, h - 1) a[x + 1][y] += a[x][y]; // horizontal
    rep(x, h) rep(y, w - 1) a[x][y + 1] += a[x][y]; // vertical
  }

  T node_val(long long x, long long y) { ret a[x][y]; }

  void check()
  {
    pr(h), pr(w), PN;
    rep(i, h)
    {
      rep(j, w) pr(a[i][j]), PS;
      PN;
    }
    PN;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  imos2D<LL> mp;
  LL XMAS = 1001;
  mp.init(XMAS, XMAS);
  LL rd(n);
  rep(i, n)
  {
    LL rd(x1, y1, x2, y2);
    mp.add(x1, y1, x2 - 1, y2 - 1, 1);
  }
  mp.calc();
  V<LL> ans(n + 1, 0);
  rep(i, XMAS) rep(j, XMAS) ans[mp.node_val(i, j)]++;
  rep(i, n) { pr(ans[i + 1]), PN; }
  Ret;
}
