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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  LL rd(n, m, Q);
  V<LL> rdv(a, n);
  V<LL> rdv(b, m);
  V<LL> A(n), B(m);
  rep(i, n)
  {
    if (a[i] < b[0])
      A[i] = b[0] - a[i];
    else if (a[i] > b[m - 1])
      A[i] = a[i] - b[m - 1];
    else
    {
      auto it = lower_bound(b.begin(), b.end(), a[i]);
      A[i] = *it - a[i];
      it--;
      A[i] = min(a[i] - *it, A[i]);
    }
  }
  rep(i, m)
  {
    if (b[i] < a[0])
      B[i] = a[0] - b[i];
    else if (b[i] > a[n - 1])
      B[i] = b[i] - a[n - 1];
    else
    {
      auto it = lower_bound(a.begin(), a.end(), b[i]);
      B[i] = *it - b[i];
      it--;
      B[i] = min(b[i] - *it, B[i]);
    }
  }

  while (Q--)
  {
    LL rd(x);
    LL dist = INF;

    if (x <= a[0])
      dist = min(dist, a[0] - x + A[0]);
    else if (x >= a[n - 1])
      dist = min(dist, x - a[n - 1] + A[n - 1]);
    else
    {
      auto it = lower_bound(a.begin(), a.end(), x);
      dist = min(dist, *it - x + A[it - a.begin()]);
      it--;
      dist = min(dist, x - *it + A[it - a.begin()]);
    }

    if (x <= b[0])
      dist = min(dist, b[0] - x + B[0]);
    else if (x >= b[m - 1])
      dist = min(dist, x - b[m - 1] + B[m - 1]);
    else
    {
      auto it = lower_bound(b.begin(), b.end(), x);
      dist = min(dist, *it - x + B[it - b.begin()]);
      it--;
      dist = min(dist, x - *it + B[it - b.begin()]);
    }
    prn(dist);
  }

  return 0;
}
