#include <bits/stdc++.h>
using namespace std;

struct Graph
{
  int V, LOG;
  vector<vector<int>> E, table;
  vector<int> depth;
  bool is_directed;

  Graph(int n, bool dir = false)
  {
    V = n;
    E.resize(n);
    depth.resize(n);
    is_directed = dir;

    table.resize(32, vector<int>(n, -1));
    LOG = 32;
  }

  void add_edge(int u, int v)
  {
    E[u].push_back(v);
    if (!is_directed)
      E[v].push_back(u);
  }

  void DFS(int index, int parent, int _depth)
  {
    table[0][index] = parent;
    depth[index] = _depth;
    for (auto &to : E[index])
    {
      if (to != parent)
        DFS(to, index, _depth + 1);
    }
  }

  void lca_build(int root = 0)
  {
    DFS(0, -1, 0);
    for (int k = 0; k + 1 < LOG; k++)
    {
      for (int i = 0; i < V; i++)
      {
        if (table[k][i] == -1)
          table[k + 1][i] = -1;
        else
          table[k + 1][i] = table[k][table[k][i]];
      }
    }
  }
  int lca_query(int u, int v)
  {
    if (depth[u] > depth[v])
      swap(u, v);
    for (int i = LOG - 1; i >= 0; i--)
    {
      if (((depth[v] - depth[u]) >> i) & 1)
        v = table[i][v];
    }
    if (u == v)
      return u;
    for (int i = LOG - 1; i >= 0; i--)
    {
      if (table[i][u] != table[i][v])
      {
        u = table[i][u];
        v = table[i][v];
      }
    }
    return table[0][u];
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, x, c, v;
  cin >> n;
  Graph G(n);
  for (int i = 0; i < n; i++)
  {
    cin >> c;
    for (int j = 0; j < c; j++)
    {
      cin >> x;
      G.add_edge(i, x);
    }
  }
  G.lca_build();
  cin >> x;
  while (x--)
  {
    cin >> c >> v;
    cout << G.lca_query(c, v) << endl;
  }

  return 0;
}

// https://atcoder.jp/contests/tessoku-book/tasks/abc007_3