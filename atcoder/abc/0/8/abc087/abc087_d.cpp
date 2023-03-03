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

template <typename T>
struct WeightedUnionFind
{
  vector<int> parent, size, rank;
  int size_max, count;
  vector<T> wd;
  WeightedUnionFind(int n)
  {
    parent.resize(n, -1);
    size.resize(n, 1);
    rank.resize(n, 0);
    count = n;
    size_max = 1;
    wd.resize(n, 0);
  }

  int root(int x)
  {
    if (parent[x] == -1)
      return x;
    else
    {
      int parent_x = root(parent[x]);
      wd[x] += wd[parent[x]];
      return parent[x] = parent_x;
    }
  }

  bool same(int x, int y) { return root(x) == root(y); }

  T weight(int x)
  {
    root(x);
    return wd[x];
  }

  void unite(int x, int y, T w)
  {
    w += weight(x);
    w -= weight(y);
    x = root(x);
    y = root(y);
    if (x == y)
      return;

    if (rank[x] < rank[y])
    {
      swap(x, y);
      w = -w;
    }

    parent[y] = x;
    size[x] += size[y];
    rank[x] += (rank[x] == rank[y]);
    wd[y] = w;
    size_max = max(size[x], size_max);
    count--;
  }

  T diff(int x, int y) { return weight(y) - weight(x); }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  LL rd(n, m);
  WeightedUnionFind<LL> uf(n);

  while (m--)
  {
    LL rd(x, y, w);
    x--;
    y--;
    if (!uf.same(x, y))
      uf.unite(x, y, w);
    else
    {
      if (uf.diff(x, y) != w)
      {
        No;
        return 0;
      }
    }
  }
  Yes;
  return 0;
}
