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
  LL vertices;
  vector<vector<LL>> edges;
  vector<queue<LL>> alp;
  vector<LL> a;

  Graph(LL n, bool dir = false)
  {
    vertices = n;
    edges.resize(n);
    alp.resize(26);
    a.resize(n, -1);
  }

  void add_edge(LL u, LL v)
  {
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  void set_alp(LL u, LL w) {
    a[u] = w;
    alp[w].push(u);
  }

  vector<LL> BFS(LL root)
  {
    vector<bool> visited(vertices, false);
    queue<LL> next_to_visit;

    visited[root] = true;
    next_to_visit.push(root);
    vector<LL> dist(vertices, 1e8);
    dist[root] = 0;
    while (!next_to_visit.empty())
    {
      LL current_node = next_to_visit.front();
      next_to_visit.pop();
      if(a[current_node] != -1) {
        while(!alp[a[current_node]].empty()) {
          auto x = alp[a[current_node]].front();
          if(x != current_node) {
            dist[x] = min(dist[x], dist[current_node] + 1);
            visited[x] = true;
            next_to_visit.push(x);
          } 
          alp[a[current_node]].pop();
        }
      }
      for (auto &x: edges[current_node])
      {
        if (!visited[x])
        {
          dist[x] = min(dist[x], dist[current_node] + 1);
          visited[x] = true;
          next_to_visit.push(x);
        }
      }
    }
    return dist;
  }
};

V<PLL> move0 = {{-1, 0}, {0, -1}};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  LL rd(h, w);
  LL start, goal;
  V<STR> rdv(a, h);
  
  Graph G(h * w);
  rep(i, h) {
    rep(j, w) {
      repauto(m, move0)
      {
        if (0 <= j + m.S && j + m.S < w && 0 <= i + m.F && i + m.F < h && a[i][j] != '#' && a[i + m.F][j + m.S] != '#')
        {
          G.add_edge(i * w + j, (i + m.F) * w + j + m.S);
        }
      }
      if('a' <= a[i][j] && a[i][j] <= 'z') G.set_alp(i * w + j, a[i][j] - 'a');
      if(a[i][j] == 'S') start = i * w + j;
      if(a[i][j] == 'G') goal = i * w + j;
    }
  }
  auto dist = G.BFS(start);
  if(dist[goal] != 1e8)
    prn(dist[goal]);
  else
    prn(-1);
  return 0;
}
