#include <bits/stdc++.h>
using namespace std;

struct Graph
{
  int V;
  vector<vector<int>> E;
  bool is_directed;
  int ans = 0;

  vector<bool> visited;

  Graph(int n, bool dir = false)
  {
    V = n;
    E.resize(n);
    is_directed = dir;
    visited.resize(n, false);
  }

  void add_edge(int u, int v)
  {
    E[u].push_back(v);
    if (!is_directed)
      E[v].push_back(u);
  }

  void DFS(int node)
  {
    if (visited[node] == true)
      return;

    visited[node] = true;
    for (auto &x : E[node])
      DFS(x);
  }

  bool is_connected()
  {
    for (int i = 0; i < V; i++)
      if (!visited[i])
        return false;
    return true;
  }
};

int main()
{
  int n, m, u, v;
  cin >> n >> m;
  Graph G(n);
  while (m--)
  {
    cin >> u >> v;
    G.add_edge(u - 1, v - 1);
  }
  G.DFS(0);
  if (G.is_connected())
    cout << "The graph is connected.\n";
  else
    cout << "The graph is not connected.\n";
  return 0;
}

// https://atcoder.jp/contests/tessoku-book/tasks/math_and_algorithm_am