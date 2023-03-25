#include <bits/stdc++.h>
using namespace std;

struct Graph
{
  int V;
  vector<vector<int>> E;
  bool is_directed, has_cycle;
  int ans = 0;

  vector<bool> visited;

  Graph(int n, bool dir = false)
  {
    V = n;
    E.resize(n);
    is_directed = dir;
    has_cycle = false;
    visited.resize(n, false);
  }

  void add_edge(int u, int v)
  {
    E[u].push_back(v);
    if (!is_directed)
      E[v].push_back(u);
  }

  bool is_DAG()
  {
    vector<int> degree(V);
    for (int u = 0; u < V; u++)
      for (int v : E[u])
        degree[v]++;

    int cnt = 0;
    queue<int> next;

    for (int u = 0; u < V; u++)
      if (degree[u] == 0)
        next.push(u);

    while (!next.empty())
    {
      int u = next.front();
      next.pop();
      cnt++;
      for (int v : E[u])
      {
        degree[v]--;
        if (degree[v] == 0)
          next.push(v);
      }
    }

    return cnt == V;
  }
};

int main()
{
  int n, m, u, v;
  cin >> n >> m;
  Graph G(n, true);
  while (m--)
  {
    cin >> u >> v;
    G.add_edge(u, v);
  }

  cout << !G.is_DAG() << '\n';
  return 0;
}

// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_A