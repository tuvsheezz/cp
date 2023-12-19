#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

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

struct UnionFind
{
  vector<int> parent, size, pp;
  vector<bool> invalid;
  int size_max = 0, count;
  map<pair<int, int>, int> mp;
  UnionFind(int n)
  {
    parent.resize(n, -1);
    size.resize(n, 1);
    pp.resize(n, 0);
    invalid.resize(n, false);
    count = n;
    size_max = 1;
  }

  int root(int x) { return parent[x] == -1 ? x : parent[x] = root(parent[x]); }
  bool same(int x, int y) { return root(x) == root(y); }
  void unite(int x, int y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
      return;

    if (size[x] < size[y])
      swap(x, y);
    parent[y] = x;
    size[x] += size[y];
    pp[x] += pp[y];
    size_max = max(size[x], size_max);
    count--;
  }
  int count_of_sets() { return count; }
  int get_union_size(int x) { return size[root(x)]; }
  void update_invalid(int x) { invalid[root(x)] = false; }
  void update_count(int x, int y)
  {
    int ro = root(x);
    if (mp.find({ro, y}) == mp.end())
    {
      mp[{ro, y}] = 1;
      pp[ro]++;
    }
  }
};

void solve()
{
  LL rd(h, w);
  V<STR> rdv(s, h);
  UnionFind uf(h * w);
  vector<pair<int, int>> move = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  map<pair<int, int>, int> mp;
  rep(i, h) rep(j, w)
  {
    if (s[i][j] == 'W')
    {
      for (auto [x, y] : move)
        if (i + x >= 0 && i + x < h && j + y >= 0 && j + y < w && s[i + x][j + y] == 'W')
          uf.unite(i * w + j, (i + x) * w + j + y);
    }
  }
  rep(i, h) rep(j, w)
  {
    if (s[i][j] == 'W')
    {
      V<LL> cn;
      for (auto [x, y] : move)
        if (i + x >= 0 && i + x < h && j + y >= 0 && j + y < w && s[i + x][j + y] == '.')
          cn.PB((i + x) * h + j + y);
      if (cn.size() > 1)
        uf.update_invalid(i * w + j);
      if (cn.size() == 1)
        uf.update_count(i * w + j, cn[0]);
    }
  }
  LL ans = 0;

  rep(i, h) rep(j, w)
  {
    if (s[i][j] == '.')
    {
      LL tmp = 0;
      for (auto [x, y] : move)
        if (i + x >= 0 && i + x < h && j + y >= 0 && j + y < w && s[i + x][j + y] == 'W')
        {
          auto root = uf.root((i + x) * w + j + y);
          if (uf.invalid[root])
            continue;
          if (uf.pp[root] == 1 && mp.find({root, i * h + j}) == mp.end())
          {
            tmp += uf.size[root];
            mp[{root, i * h + j}] = 1;
          }
        }
      ans = max(ans, tmp);
    }
  }
  prn(ans);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  LL rd(T);
  rep(i, T)
  {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
  return 0;
}
