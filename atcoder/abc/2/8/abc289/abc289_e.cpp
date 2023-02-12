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
  int N;
  vector<vector<int>> edges;
  vector<vector<int>> eee;
  vector<vector<bool>> visited;
  vector<int> color;

  Graph(int n)
  {
    N = n;
    edges.resize(n);
    color.resize(n);
    eee.resize(n * n);
    visited.resize(n, vector<bool>(n, false));
  }
  void set_color(int u, int c)
  {
    color[u] = c;
  }
  void add_edge(int u, int v)
  {
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  void DFS(LL r1, LL r2)
  {
    if (visited[r1][r2] == true)
      return;

    visited[r1][r2] = true;
    repauto(r11, edges[r1])
    {
      repauto(r22, edges[r2])
      {
        if (color[r11] != color[r22])
        {
          eee[r11 * N + r22].push_back(r1 * N + r2);
          eee[r1 * N + r2].push_back(r11 * N + r22);
          DFS(r11, r22);
        }
      }
    }
  }
  int BFS(int root)
  {
    vector<bool> visited(N * N, false);
    queue<int> next_to_visit;

    visited[root] = true;
    next_to_visit.push(root);
    vector<int> dist(N * N, 1e8);
    dist[root] = 0;
    while (!next_to_visit.empty())
    {
      int current_node = next_to_visit.front();
      next_to_visit.pop();
      for (auto &x : eee[current_node])
      {
        if (!visited[x])
        {
          dist[x] = dist[current_node] + 1;
          visited[x] = true;
          next_to_visit.push(x);
        }
      }
    }
    return dist[(N - 1) * N];
  }
};

void solve()
{
  LL rd(n, m);
  Graph G(n);
  rep(i, n)
  {
    LL rd(c);
    G.set_color(i, c);
  }
  rep(i, m)
  {
    LL rd(u, v);
    G.add_edge(u - 1, v - 1);
  }
  G.DFS(0, n - 1);
  auto dist = G.BFS(n - 1);
  if (dist == 1e8)
    prn(-1);
  else
    prn(dist);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  LL rd(T);
  while (T--)
  {
    solve();
  }
  return 0;
}
