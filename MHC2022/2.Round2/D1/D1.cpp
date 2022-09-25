#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
template <class T>
using IS = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
#define Ret return 0
#define ret return
#define INF (1LL << 60)
#define MOD1 1000000007
#define MOD2 998244353
#define MAX_N 100100

struct ST1
{
  V<LL> tree;
  LL tree_size, N, def = 0;

  void init(LL n)
  {
    while (__builtin_popcount(n) != 1)
    {
      n++;
    }
    tree.resize(2 * n, 0);
    tree_size = 2 * n;
    N = n;
  }

  LL get_range(LL ql, LL qr) { ret _get_range(1, 0, N - 1, ql, qr); }
  LL _get_range(LL node, LL sl, LL sr, LL ql, LL qr)
  {
    if (ql <= sl && sr <= qr)
      ret tree[node];
    if (sr < ql || qr < sl)
      ret def;
    ret _get_range(2 * node, sl, (sl + sr) / 2, ql, qr) + _get_range(2 * node + 1, (sl + sr) / 2 + 1, sr, ql, qr);
  }

  void update_node(LL ind, LL val)
  {
    tree[ind += N] = val;
    while (ind / 2 >= 1)
    {
      ind /= 2;
      tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
    }
  }
  void check_tree() { rep(i, tree_size) cout << i << ": " << tree[i] << "\n"; }
};

struct ST2
{
  V<V<LL>> tree;
  LL tree_size, N;
  V<LL> def = V<LL>(3, 0);

  void init(LL n)
  {
    while (__builtin_popcount(n) != 1)
    {
      n++;
    }
    tree.resize(2 * n, def);
    tree_size = 2 * n;
    N = n;
  }

  V<LL> get_range(LL ql, LL qr) { ret _get_range(1, 0, N - 1, ql, qr); }
  V<LL> _get_range(LL node, LL sl, LL sr, LL ql, LL qr)
  {
    if (ql <= sl && sr <= qr)
      ret tree[node];
    if (sr < ql || qr < sl)
      ret def;
    V<LL> r(3, 0);
    auto x = _get_range(2 * node, sl, (sl + sr) / 2, ql, qr);
    auto y = _get_range(2 * node + 1, (sl + sr) / 2 + 1, sr, ql, qr);
    rep(i, 3) r[i] = x[i] + y[i];
    return r;
  }

  void update_node(LL ind, V<LL> val)
  {
    tree[ind += N] = val;
    while (ind / 2 >= 1)
    {
      ind /= 2;
      V<LL> r(3, 0);
      rep(i, 3) r[i] = tree[2 * ind][i] + tree[2 * ind + 1][i];
      tree[ind] = r;
    }
  }
  void check_tree() { rep(i, tree_size) cout << i << ": " << tree[i] << "\n"; }
};

void solve(LL cs)
{
  LL rd(n, m);
  V<LL> rdv(a, n);
  LL ans = 0;
  ST1 sum;
  sum.init(n);
  ST2 count;
  count.init(n);
  rep(i, n)
  {
    sum.update_node(i, a[i]);
    if (a[i] == 1)
      count.update_node(i, {1, 0, 0});
    if (a[i] == 2)
      count.update_node(i, {0, 1, 0});
    if (a[i] == 3)
      count.update_node(i, {0, 0, 1});
  }
  while (m--)
  {
    LL rd(x, y, z);
    sum.update_node(x - 1, y);
    if (y == 1)
      count.update_node(x - 1, {1, 0, 0});
    if (y == 2)
      count.update_node(x - 1, {0, 1, 0});
    if (y == 3)
      count.update_node(x - 1, {0, 0, 1});
    LL sl = sum.get_range(0, z - 1);
    LL sr = sum.get_range(z, n);

    if (abs(sl - sr) & 1)
    {
      ans--;
      continue;
    }
    if (sl == sr)
      continue;

    V<LL> cl = count.get_range(0, z - 1);
    V<LL> cr = count.get_range(z, n);

    if (sl > sr)
    {
      LL x = sl - sr;

      LL two = min(cl[2], cr[0]);
      if (x / 4 >= two)
      {
        x -= two * 4;
        LL one = min(cl[1], cr[0] - two) + min(cl[2] - two, cr[1]);
        if (one * 2 < x)
          ans--;
        else
          ans += two + x / 2;
      }
      else
      {
        LL mn = INF;
        LL tmp = x;
        LL cc = tmp / 4;
        tmp -= cc * 4;
        LL one = min(cl[1], cr[0] - cc) + min(cl[2] - cc, cr[1]);
        if (one * 2 >= tmp)
          mn = min(mn, cc + tmp / 2);

        tmp = x;
        cc = (tmp + 3) / 4;
        tmp = cc * 4 - tmp;

        one = min(cr[1], cl[0] + cc) + min(cr[2] + cc, cl[1]);
        if (one * 2 >= tmp)
          mn = min(mn, cc + tmp / 2);
        if (mn == INF)
          ans--;
        else
          ans += mn;
      }
    }
    else if (sl < sr)
    {
      LL x = sr - sl;

      LL two = min(cr[2], cl[0]);
      if (x / 4 >= two)
      {
        x -= two * 4;
        LL one = min(cr[1], cl[0] - two) + min(cr[2] - two, cl[1]);
        if (one * 2 < x)
          ans--;
        else
          ans += two + x / 2;
      }

      else
      {
        LL mn = INF;
        LL tmp = x;
        LL cc = tmp / 4;
        tmp -= cc * 4;
        LL one = min(cr[1], cl[0] - cc) + min(cr[2] - cc, cl[1]);
        if (one * 2 >= tmp)
          mn = min(mn, cc + tmp / 2);

        tmp = x;
        cc = (tmp + 3) / 4;
        tmp = cc * 4 - tmp;

        one = min(cl[1], cr[0] + cc) + min(cl[2] + cc, cr[1]);
        if (one * 2 >= tmp)
          mn = min(mn, cc + tmp / 2);
        if (mn == INF)
          ans--;
        else
          ans += mn;
      }
    }
  }
  cout << "Case #" << cs << ": " << ans << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  LL rd(T);
  rep(i, T)
  {
    solve(i + 1);
  }
  Ret;
}
