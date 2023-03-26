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

void bipartite_matching()
{
  int n;
  cin >> n;
  Graph<int> G(n + n + 2, 1e8);
  vector<pair<int, int>> A(n), B(n);

  for (int i = 0; i < n; i++)
  {
    G.add_edge(0, i + 1, 1);
    G.add_edge(n + i + 1, n + n + 1, 1);
  }

  for (int i = 0; i < n; i++)
    cin >> A[i].first >> A[i].second;
  for (int i = 0; i < n; i++)
    cin >> B[i].first >> B[i].second;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      if (A[i].first < B[j].first && A[i].second < B[j].second)
        G.add_edge(i + 1, j + 1 + n, 1);
    }
  cout << G.Dinic(0, n + n + 1) << endl;
}

int main()
{
  bipartite_matching();
  return 0;
}
