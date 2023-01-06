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

void solve()
{
  LL rd(n);
  V<LL> rdv(a, n);
  V<PLL> x(n);
  rep(i, n) x[i] = {a[i], i};
  vsortd(x);
  V<bool> f(n, false), f2(n, false);
  V<LL> p(n), q(n);
  PQA<PLL> pqp, pqq;
  rep(i, n) {
    if(!f[x[i].F - 1]) {
      p[x[i].S] = x[i].F;
      f[x[i].F - 1] = true;
      pqp.push(x[i]);
    } else if(!f2[x[i].F - 1]) {
      q[x[i].S] = x[i].F;
      f2[x[i].F - 1] = true;
      pqq.push(x[i]);
    } else {
      NO;
      return;
    }
  }
  rep(i, n) {
    if(f[i]) continue;
    if(pqq.empty() || pqq.top().F - 1 < i) {
      NO;
      return;
    }
    p[pqq.top().S] = i + 1;
    pqq.pop();
  }
  rep(i, n) {
    if(f2[i]) continue;
    if(pqp.empty() || pqp.top().F - 1 < i) {
      NO;
      return;
    }
    q[pqp.top().S] = i + 1;
    pqp.pop();
  }
  YES;
  pr(p);
  pr(q);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  LL rd(T);
  while (T--)
  {
    solve();
  }
  return 0;
}
