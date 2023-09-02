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

struct Graph
{
  int V;
  vector<vector<int>> E;
  vector<int> degree, drev;
  vector<LL> tm;
  vector<bool> sa;

  Graph(int n)
  {
    V = n;
    E.resize(n);
    degree.resize(n, 0);
    tm.resize(n);
    sa.resize(n, false);
  }

  void add_edge(int u, int v)
  {
    E[u].push_back(v);
    degree[v]++;
  }

  vector<PLL> TopologicalSort()
  {
    PQA<pair<LL, PLL>> next;
    vector<PLL> ans;
    vector<LL> par(V, INF);

    for (int i = 0; i < V; i++)
    {
      if (degree[i] == 0)
      {
        next.push({tm[i], {i, INF}});
        sa[i] = true;
      }
    }
    while (!next.empty())
    {
      auto cur = next.top();
      next.pop();

      if (sa[cur.second.first] == false)
        par[cur.second.first] = min(par[cur.second.first], par[cur.second.second]);
      else
        par[cur.second.first] = ans.size();

      ans.push_back({cur.first, par[cur.second.first]});

      for (auto &x : E[cur.second.first])
      {
        degree[x]--;
        if (degree[x] == 0)
          next.push({tm[x], {x, par[cur.second.first]}});
      }
    }
    return ans;
  }
};

void solve()
{
  LL rd(n, m, k);
  V<LL> rdv(a, n);
  Graph G(n);
  rep(i, n) G.tm[i] = a[i];
  rep(i, m)
  {
    LL rd(u, v);
    u--;
    v--;
    G.add_edge(u, v);
  }

  auto ts = G.TopologicalSort();
  LL added = 0;

  repa(i, 1, n)
  {
    if (ts[i].F < ts[i - 1].F)
      added++;
  }
  V<LL> mn(n, INF);

  LL ans = added * k + ts[n - 1].F - ts[0].F;

  repd(i, n - 1, 0)
  {
    mn[i] = ts[i].second;
    if (i + 1 < n)
      mn[i] = min(mn[i], mn[i + 1]);
  }

  rep(i, n)
  {
    if (i > 0 && G.sa[i] == true && mn[i] == ts[i].S)
    {
      LL tmp = (added + 1) * k + ts[i - 1].F - ts[i].F;
      ans = min(ans, tmp);
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
  while (T--)
    solve();
  return 0;
}
