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
struct BellmanFord
{
  struct edge
  {
    int from, to;
    T cost;
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
  };

  int V;
  const T inf = numeric_limits<T>::max() / 2;
  vector<edge> E;

  BellmanFord(int n) : V(n) {}

  void add_edge(int from, int to, T cost) { E.emplace_back(from, to, cost); }

  bool find_negative_loop()
  {
    vector<T> dist(V, 0);
    bool updated = true;
    for (int i = 0; i < V; i++)
    {
      for (auto &e : E)
      {
        if (dist[e.from] + e.cost < dist[e.to])
        {
          dist[e.to] = dist[e.from] + e.cost;
          updated = true;
        }
      }
      if (!updated)
        return true;
      if (i == V - 1)
        return false;
      updated = false;
    }
  }

  vector<T> shortest_path_to_all_vertices(int s)
  {
    vector<T> dist(V, inf);
    dist[s] = 0;
    bool updated = true;
    for (int i = 0; i < V; i++)
    {
      for (auto &e : E)
      {
        if (dist[e.from] != inf && dist[e.from] + e.cost < dist[e.to])
        {
          dist[e.to] = dist[e.from] + e.cost;
          updated = true;
        }
      }
      if (!updated)
        break;
      if (i == V - 1)
        return {};
      updated = false;
    }
    return dist;
  }

  vector<T> shortest_path_to_one_vertex(int s, int t)
  {
    vector<T> dist(V, inf);
    dist[s] = 0;
    for (int i = 0; i < 2 * V - 1; i++)
    {
      for (auto &e : E)
      {
        if (dist[e.from] != inf && dist[e.from] + e.cost < dist[e.to])
        {
          dist[e.to] = dist[e.from] + e.cost;
          if (i >= V - 1)
          {
            if (e.to == t)
              return {};
            dist[e.to] = -inf;
          }
        }
      }
    }
    return dist;
  }
};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  LL rd(n, m);
  BellmanFord<LL> BF(n);
  while (m--)
  {
    LL rd(u, v, w);
    BF.add_edge(u - 1, v - 1, -w);
  }

  auto dist = BF.shortest_path_to_one_vertex(0, n - 1);

  if (dist.empty())
    prn("inf");
  else
    prn(-dist[n - 1]);
  return 0;
}
