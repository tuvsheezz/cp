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

  int shortest_cycle()
  {
    int ans = INT32_MAX;
    for (int i = 0; i < V; i++)
    {
      vector<int> dist(V, (int)(1e9));
      vector<int> par(V, -1);
      dist[i] = 0;
      queue<int> q;

      q.push(i);

      while (!q.empty())
      {
        int x = q.front();
        q.pop();
        for (int child : E[x])
        {
          if (dist[child] == (int)(1e9))
          {
            dist[child] = 1 + dist[x];
            par[child] = x;
            q.push(child);
          }

          else if (par[x] != child and par[child] != x)
            ans = min(ans, dist[x] + dist[child] + 1);
        }
      }
    }

    if (ans == INT_MAX)
      return -1;
    else
      return ans;
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

  cout << G.shortest_cycle() << '\n';
  return 0;
}
