#include <bits/stdc++.h>
using namespace std;

template <class T>
struct Graph
{
  struct edge
  {
    T to, cap, rev;
  };

  int V;
  T inf;
  vector<bool> visited;
  vector<vector<edge>> E;

  Graph(int n, T _inf)
  {
    visited.resize(n, false);
    E.resize(n);
    V = n;
    inf = _inf;
  }

  void add_edge(int u, int v, T w)
  {
    int lu = E[u].size();
    int lv = E[v].size();

    E[u].push_back(edge{v, w, lv});
    E[v].push_back(edge{u, 0, lu});
  }

  T dfs(int pos, int goal, T fl)
  {

    if (pos == goal)
      return fl;
    visited[pos] = true;

    for (int i = 0; i < E[pos].size(); i++)
    {

      if (E[pos][i].cap == 0)
        continue;

      if (visited[E[pos][i].to] == true)
        continue;

      T flow = dfs(E[pos][i].to, goal, min(fl, E[pos][i].cap));

      if (flow >= 1)
      {
        E[pos][i].cap -= flow;
        E[E[pos][i].to][E[pos][i].rev].cap += flow;
        return flow;
      }
    }

    return 0;
  }

  int MaximumFlow(int s, int t)
  {
    int total = 0;
    while (true)
    {
      for (int i = 0; i < V; i++)
        visited[i] = false;
      int fl = dfs(s, t, inf);

      if (fl == 0)
        break;
      total += fl;
    }
    return total;
  }
};

int main()
{
  int n, m;
  cin >> n >> m;
  Graph<int> G(n, 1e8);
  for (int i = 0; i < m; i++)
  {
    int u, v, c;
    cin >> u >> v >> c;
    G.add_edge(u, v, c);
  }

  cout << G.MaximumFlow(0, n - 1) << endl;
  return 0;
}
// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A