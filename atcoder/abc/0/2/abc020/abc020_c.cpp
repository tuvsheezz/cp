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

struct Graph
{
  long long vertices;
  vector<vector<pair<long long, long long>>> edges;
  bool is_directed;

  Graph(long long n, bool dir = false)
  {
    vertices = n;
    edges.resize(n);
    is_directed = dir;
  }

  void add_edge(long long u, long long v, long long cost)
  {
    edges[u].push_back({v, cost});
    if (!is_directed)
      edges[v].push_back({u, cost});
  }

  long long Dijkstra(long long s, long long goal)
  {
    vector<long long> dist(vertices, INF);
    dist[s] = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> next_to_visit;
    
    next_to_visit.push({0LL, s});

    while (!next_to_visit.empty())
    {
      pair<long long, long long> current_node = next_to_visit.top();
      next_to_visit.pop();
      long long v = current_node.second;

      if (dist[v] < current_node.first)
        continue;

      for(auto &edge: edges[v])
      {
        if (dist[edge.first] > dist[v] + edge.second)
        {
          dist[edge.first] = dist[v] + edge.second;
          next_to_visit.push({dist[edge.first], edge.first});
        }
      }
    }
    return dist[goal];
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  LL rd(h, w, t);
  LL start, goal;
  V<STR> rdv(s, h);
  rep(i, h) rep(j, w) {
    if(s[i][j] == 'S') {
      start = i * w + j;
      s[i][j] = '.';
    }
    if(s[i][j] == 'G') {
      goal = i * w + j;
      s[i][j] = '.';
    }
  }
  LL l = 1, r = 1e9 + 1, m;
  while(l + 1 < r) {
    m = l + (r - l) / 2;
    Graph G(h * w, true);
    rep(i, h) {
      rep(j, w) {
        if(i > 0 && s[i - 1][j] == '#')
          G.add_edge(i * w + j, (i - 1) * w + j, m);
        if(i > 0 && s[i - 1][j] == '.')
          G.add_edge(i * w + j, (i - 1) * w + j, 1);
        if(i > 0 && s[i][j] == '#')
          G.add_edge((i - 1) * w + j, i * w + j, m);
        if(i > 0 && s[i][j] == '.')
          G.add_edge((i - 1) * w + j, i * w + j, 1);
        if(j > 0 && s[i][j - 1] == '#')
          G.add_edge(i * w + j, i * w + j - 1, m);
        if(j > 0 && s[i][j - 1] == '.')
          G.add_edge(i * w + j, i * w + j - 1, 1);
        if(j > 0 && s[i][j] == '#')
          G.add_edge(i * w + j - 1, i * w + j, m);
        if(j > 0 && s[i][j] == '.')
          G.add_edge(i * w + j - 1, i * w + j, 1);
      }
    }
    auto x = G.Dijkstra(start, goal);
    if(x <= t)
      l = m;
    else
      r = m;
  }
  prn(l);
  return 0;
}
