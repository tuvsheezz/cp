#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Graph
{
  vector<vector<ll>> edges;
  vector<bool> vis;
  vector<ll> b;

  void init(ll n)
  {
    edges.resize(n);
    vis.resize(n);
    b.resize(n, INT64_MAX);
  }
  void add_edge(ll v, ll u) { edges[v].push_back(u); }

  void DFS(ll node, vector<ll> &a)
  {
    vis[node] = true;
    for (auto &x : edges[node])
    {
      if (!vis[x])
        DFS(x, a);
      b[node] = min({b[node], b[x], a[x]});
    }
  }
};

int main()
{
  ll n, m, u, v, ans = INT64_MIN;
  Graph G;
  vector<ll> a;

  cin >> n >> m;

  G.init(n);
  a.resize(n);

  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < m; i++)
  {
    cin >> u >> v;
    G.add_edge(v - 1, u - 1);
  }

  for (int i = 0; i < n; i++)
  {
    if (!G.vis[i])
      G.DFS(i, a);
    ans = max(ans, a[i] - G.b[i]);
  }

  cout << ans << endl;
  return 0;
}
