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

template <class T>
struct Graph
{
  const T inf = INF;
  int V;
  vector<vector<pair<int, T>>> E; // PLL: (destination, cost)
  bool is_directed;

  Graph(int n, bool dir = false)
  {
    V = n;
    E.resize(n);
    is_directed = dir;
  }

  void add_edge(int u, int v, T cost)
  {
    E[u].push_back({v, cost});
    if (!is_directed)
      E[v].push_back({u, cost});
  }

  vector<vector<T>> WarshalFloyd()
  {
    vector<vector<T>> dist(V, vector<T>(V, inf));
    for (int i = 0; i < V; i++)
      dist[i][i] = 0;
    for (int i = 0; i < V; i++)
      for (auto &x : E[i])
        dist[i][x.first] = min(dist[i][x.first], x.second);

    for (int k = 0; k < V; k++)
      for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    return dist;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  LL rd(n, m);
  Graph<LL> G(n);

  V<PLL> x;

  while (m--)
  {
    LL rd(u, v, w);
    if (u > v)
      swap(u, v);

    if (u != 1 && v != 1)
      G.add_edge(u - 1, v - 1, w);
    else
      x.PB({v - 1, w});
  }

  auto dist = G.WarshalFloyd();

  LL ans = INF;
  rep(i, x.size()) repa(j, i + 1, x.size())
      ans = min(ans, dist[x[i].F][x[j].F] + x[i].S + x[j].S);

  if (ans == INF)
    prn(-1);
  else
    prn(ans);

  return 0;
}
