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
  int L, R, m;
  cin >> L >> R >> m;
  // 二部グラフ 𝐺=(𝐿∪𝑅,𝐸) に対応する以下のようなフローネットワーク 𝐺′ を作る
  // 1. 𝐺 にソース 𝑠 とシンク 𝑡 を加える
  Graph<int> G(L + R + 2, 1e8);
  // 2. sからLのすべての頂点に対して容量 1 の有向辺を加える(sはここでは０)
  for (int i = 0; i < L; i++)
    G.add_edge(0, i + 1, 1);

  // 3. 𝑅 のすべての頂点から 𝑡 に対して容量 1 の有向辺を加える
  for (int i = 0; i < R; i++)
    G.add_edge(L + i + 1, L + R + 1, 1);

  // 4. 𝐿 の頂点と 𝑅 の頂点を結ぶ辺は、𝐿 から 𝑅 への容量 1 の有向辺とする
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    G.add_edge(u + 1, v + 1 + L, 1);
  }
  // 5. 𝐺′ の最大フローを求めると、その流量は最大マッチングのサイズと一致する
  cout << G.Dinic(0, L + R + 1) << endl;
}

int main()
{
  bipartite_matching();
  return 0;
}
// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_7_A
