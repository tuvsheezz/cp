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

struct Graph
{
  LL vertices;
  VV<PLL> edges; // PLL: (destination, cost)
  bool is_directed;

  void init(LL n, bool dir = false)
  {
    vertices = n;
    edges.resize(n);
    is_directed = dir;
  }

  void add_edge(LL u, LL v, LL cost)
  {
    edges[u].PB(MP(v, cost));
    if (!is_directed)
      edges[v].PB(MP(u, cost));
  }

  V<LL> Dijkstra(LL s)
  {
    V<LL> dist(vertices, INF);
    dist[s] = 0;

    PQA<PLL> next_to_visit;
    next_to_visit.push(MP(0LL, s));

    while (!next_to_visit.empty())
    {
      PLL current_node = next_to_visit.top();
      next_to_visit.pop();
      LL v = current_node.S;

      if (dist[v] < current_node.F)
        continue;

      repauto(edge, edges[v])
      {
        if (dist[edge.F] > dist[v] + edge.S)
        {
          dist[edge.F] = dist[v] + edge.S;
          next_to_visit.push(MP(dist[edge.F], edge.F));
        }
      }
    }
    ret dist;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  LL rd(n, m);
  Graph G;
  G.init(n);
  while (m--)
  {
    LL rd(u, v, c);
    G.add_edge(u - 1, v - 1, c);
  }

  V<LL> q1 = G.Dijkstra(0), q2 = G.Dijkstra(n - 1);

  rep(i, n)
  {
    pr(q1[i] + q2[i]);
    PN;
  }
  Ret;
}
