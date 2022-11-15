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
struct Graph2
{
  ll vertices;
  vector<vector<ll>> edges;
  bool is_directed;

  void init(ll n, bool dir = false)
  {
    vertices = n;
    edges.resize(n);
    is_directed = dir;
  }

  void add_edge(ll u, ll v)
  {
    edges[u].push_back(v);
    if (!is_directed)
      edges[v].push_back(u);
  }

  ll BFS(ll root, ll target)
  {
    vector<bool> visited(vertices, false);
    queue<ll> next_to_visit;

    next_to_visit.push(root);
    vector<pair<ll, ll>> dist(vertices, make_pair(INT64_MAX, 0));
    dist[root] = make_pair(0LL, 1LL);

    while (!next_to_visit.empty())
    {
      ll current_node = next_to_visit.front();
      next_to_visit.pop();
      if (visited[current_node])
        continue;

      visited[current_node] = true;

      for (auto &x : edges[current_node])
      {
        if (dist[x].first == dist[current_node].first + 1)
          dist[x].second = (dist[x].second + dist[current_node].second) % 1000000007;
        if (dist[x].first > dist[current_node].first + 1)
          dist[x] = make_pair(dist[current_node].first + 1, dist[current_node].second);
        next_to_visit.push(x);
      }
    }
    return dist[target].second;
  }
};
struct Graph
{
  LL vertices;
  V<V<LL>> edges;
  bool is_directed;

  void init(LL n, bool dir = false)
  {
    vertices = n;
    edges.resize(n);
    is_directed = dir;
  }

  void add_edge(LL u, LL v)
  {
    edges[u].PB(v);
    if (!is_directed)
      edges[v].PB(u);
  }
  LL BFS(LL root)
  {
    LL r = 0;
    V<bool> visited(vertices, false);
    queue<LL> next_to_visit;

    visited[root] = true;
    next_to_visit.push(root);
    V<LL> dist(vertices, INF);
    dist[root] = 0;
    while (!next_to_visit.empty())
    {
      LL current_node = next_to_visit.front();
      next_to_visit.pop();
      repauto(x, edges[current_node])
      {
        if (!visited[x])
        {
          dist[x] = dist[current_node] + 1;
          visited[x] = true;
          next_to_visit.push(x);
          r = max(r, dist[x]);
        }
      }
    }
    ret r;
  }
};
vector<pair<long long, long long>> move = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
V<PLL> move0 = {{-1, 0}, {0, -1}};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  LL rd(h, w);
  char c[h + 10][w + 10];
  LL ans = 0;
  Graph G;
  G.init(h * w);

  rep(i, h)
  {
    rep(j, w)
    {
      cin >> c[i][j];
      repauto(m, move0)
      {
        if (0 <= j + m.S && j + m.S < w && 0 <= i + m.F && i + m.F < h && c[i][j] == '.' && c[i + m.F][j + m.S] == '.')
        {
          G.add_edge(i * w + j, (i + m.F) * w + j + m.S);
          cout << i * w + j << " " << (i + m.F) * w + j + m.S << endl;
        }
      }
    }
  }

  rep(i, h)
  {
    rep(j, w)
    {
      ans = max(ans, G.BFS(i * w + j));
    }
  }
  pr(ans);
  PN;
  Ret;
}
