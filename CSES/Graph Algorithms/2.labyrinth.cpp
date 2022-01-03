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
#define vsorta(v) sort(v.begin(), v.en())
#define vsortd(v) sort(v.begin(), v.en(), greater<>())
#define sort_arr(v, n) sort(v, v + n)
#define rev(v) reverse(v.begin(), v.en())
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
  V<PLL> BFS(LL root)
  {
    V<bool> visited(vertices, false);
    queue<LL> next_to_visit;

    visited[root] = true;
    next_to_visit.push(root);

    V<PLL> dist(vertices, MP(INF, INF));

    dist[root] = MP(0, root);

    while (!next_to_visit.empty())
    {
      LL current_node = next_to_visit.front();
      next_to_visit.pop();
      repauto(x, edges[current_node])
      {
        if (!visited[x])
        {
          dist[x] = MP(dist[current_node].F + 1, current_node);
          visited[x] = true;
          next_to_visit.push(x);
        }
      }
    }
    ret dist;
  }
};

V<PLL> move0 = {{-1, 0}, {0, -1}};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  LL rd(h, w);
  char c[h + 10][w + 10];
  LL st, en;
  Graph G;
  G.init(h * w);

  rep(i, h)
  {
    rep(j, w)
    {
      cin >> c[i][j];
      if (c[i][j] == 'A')
      {
        st = i * w + j;
        c[i][j] = '.';
      }
      if (c[i][j] == 'B')
      {
        en = i * w + j;
        c[i][j] = '.';
      }
      repauto(m, move0)
      {
        if (0 <= j + m.S && j + m.S < w && 0 <= i + m.F && i + m.F < h && c[i][j] == '.' && c[i + m.F][j + m.S] == '.')
          G.add_edge(i * w + j, (i + m.F) * w + j + m.S);
      }
    }
  }
  auto dist = G.BFS(st);
  if (dist[en].F == INF)
    pr("NO\n");
  else
  {
    pr("YES\n");
    pr(dist[en].F);
    stack<char> s;
    PN;
    while (0 < dist[en].F)
    {
      if (dist[en].S + 1 == en)
        s.push('R');
      else if (dist[en].S - 1 == en)
        s.push('L');
      else if (dist[en].S + w == en)
        s.push('D');
      else if (dist[en].S - w == en)
        s.push('U');
      en = dist[en].S;
    }
    while (!s.empty())
    {
      pr(s.top());
      s.pop();
    }
    PN;
  }
  Ret;
}
