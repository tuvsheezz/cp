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
  V<LL> sou;
  Graph(LL n)
  {
    vertices = n;
    edges.resize(n);
    sou.resize(n);
  }

  void add_edge(LL u, LL v)
  {
    edges[u].push_back(v);
  }

  void set_A(V<LL> x)
  {
    rep(i, vertices) sou[i] = x[i];
  }

  vector<PLL> BFS(LL root)
  {
    vector<bool> visited(vertices, false);
    queue<LL> next_to_visit;

    visited[root] = true;
    next_to_visit.push(root);
    vector<PLL> dist(vertices, {INF, -INF});
    dist[root] = {0, sou[root]};
    while (!next_to_visit.empty())
    {
      LL cn = next_to_visit.front();
      next_to_visit.pop();
      for (auto &x : edges[cn])
      {
        if (!visited[x])
        {
          dist[x] = {dist[cn].F + 1, dist[cn].S + sou[x]};
          visited[x] = true;
          next_to_visit.push(x);
        } else if(dist[x].F == dist[cn].F + 1 && dist[x].S < dist[cn].S + sou[x]) {
            dist[x].S = dist[cn].S + sou[x];
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
  LL rd(n);
  Graph G(n);
  V<LL> rdv(a, n);
  G.set_A(a);
  rep(i, n) {
    STR rd(s);
    rep(j, n) {
      if(s[j] == 'Y')
        G.add_edge(i, j);
    }
  }
  VV<PLL> x(n);
  rep(i, n) { x[i] = G.BFS(i); }
  LL rd(Q);
  while(Q--) {
    LL rd(s, t);
    if(x[s - 1][t - 1].F == INF)
      prn("Impossible");
    else
      cout << x[s - 1][t - 1].F << " " << x[s - 1][t - 1].S << endl; 
  }
  return 0;
}
