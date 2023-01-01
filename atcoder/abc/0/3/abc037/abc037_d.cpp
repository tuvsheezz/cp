// https://atcoder.jp/contests/abc037/tasks/abc037_d
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
#define Ret return 0
#define ret return
#define INF (1LL << 60)
#define MOD1 1000000007
#define MOD2 998244353
#define MAX_N 100100

struct Graph
{
  long long vertices;
  vector<vector<long long>> edges;
  vector<long long> cnt;
  bool is_directed;
  vector<bool> visited;
  long long ans = 0;

  Graph(long long n, bool dir = false)
  {
    vertices = n;
    edges.resize(n);
    cnt.resize(n, 0);
    is_directed = dir;
    visited.resize(n, false);
  }

  void add_edge(long long u, long long v)
  {
    edges[u].push_back(v);
    if (!is_directed)
      edges[v].push_back(u);
  }

  long long DFS(long long node)
  {
    if(visited[node] == true)
      return cnt[node];

    visited[node] = true;
    long long c = 1;
    for(auto &x: edges[node]) { c = (c + DFS(x)) % MOD1; }
    return cnt[node] = c;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  LL rd(h, w);
  Graph G(h * w, true);
  V<V<LL>> a(h, V<LL>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];
  rep(i, h) rep(j, w) {
    if(i > 0 && a[i - 1][j] > a[i][j])
      G.add_edge(i * w + j, (i - 1) * w + j);
    
    if(i > 0 && a[i - 1][j] < a[i][j])
      G.add_edge((i - 1) * w + j, i * w + j);
    
    if(j > 0 && a[i][j - 1] > a[i][j])
      G.add_edge(i * w + j, i * w + j - 1);
    if(j > 0 && a[i][j - 1] < a[i][j])
      G.add_edge(i * w + j - 1, i * w + j);
  }
  LL ans = 0;
  rep(i, h * w) ans = (ans + G.DFS(i)) % MOD1;
  prn(ans);
  
  Ret;
}
