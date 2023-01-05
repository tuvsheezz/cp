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
  vector<vector<pair<long long, long long>>> edges; // PLL: (destination, cost)
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

  vector<long long> Dijkstra(long long s)
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
    return dist;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  LL rd(n, m);
  VV<V<LL>> dp(110, VV<LL>(110, V<LL>(110, 0)));
  rep(i, n) {
    LL rd(a, b, c, w);
    dp[a][b][c] = max(dp[a][b][c], w);
  }
  rep(i, 101) rep(j, 101) rep(k, 101) {
    rep(ii, 2) rep(jj, 2) rep(kk, 2) {
      dp[i + ii][j + jj][k + kk] = max(dp[i + ii][j + jj][k + kk], dp[i][j][k]);  
    }
  }

  rep(i, m) {
    LL rd(a, b, c);
    prn(dp[a][b][c]);
  }
  return 0;
}
