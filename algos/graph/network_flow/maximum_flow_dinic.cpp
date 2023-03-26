#include <bits/stdc++.h>
using namespace std;

template <class T>
struct Graph
{
  struct edge
  {
    int to;
    T cap, rev;
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

  T Dinic(int s, int t)
  {
    T flow = 0;
    while (true)
    {
      auto level = LevelGraph(s);
      if (level[t] == -1)
        break;

      T blocking_flow = 0;
      while ((blocking_flow = AugmentingPath(s, inf, t, level)) > 0)
        flow += blocking_flow;
    }
    return flow;
  }

  vector<int> LevelGraph(int s)
  {
    vector<int> level(V, -1);
    queue<int> next;
    level[s] = 0;
    next.push(s);
    while (!next.empty())
    {
      int v = next.front();
      next.pop();
      for (auto &e : E[v])
        if (0 < e.cap && level[e.to] == -1)
        {
          level[e.to] = level[v] + 1;
          next.push(e.to);
        }
    }
    return level;
  }

  T AugmentingPath(int v, T flow, int t, vector<int> &level)
  {
    if (v == t)
      return flow;
    for (int i = 0; i < E[v].size(); i++)
    {
      edge &e = E[v][i];

      if (0 < e.cap && level[v] < level[e.to])
      {
        T d = AugmentingPath(e.to, min(flow, e.cap), t, level);
        if (0 < d)
        {
          e.cap -= d;
          E[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
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
    u--, v--;
    G.add_edge(u, v, c);
  }

  cout << G.Dinic(0, n - 1) << endl;
  return 0;
}
// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
