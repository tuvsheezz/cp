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

  // 頂点数 N の残余グラフを準備
  Graph(int n, T _inf)
  {
    visited.resize(n, false);
    E.resize(n);
    V = n;
    inf = _inf;
  }

  void add_edge(int u, int v, T w)
  {
    int lu = E[u].size(); // 現時点での E[u] の要素数
    int lv = E[v].size(); // 現時点での E[v] の要素数

    E[u].push_back(edge{v, w, lv});
    E[v].push_back(edge{u, 0, lu});
  }

  // 深さ優先探索（fl はスタートから pos に到達する過程での " 残余グラフの辺の容量 " の最小値）
  // 返り値は流したフローの量（流せない場合は 0 を返す）

  T AugmentingPath(int pos, int goal, T fl)
  {
    // ゴールに到着：フローを流せる！
    if (pos == goal)
      return fl;
    visited[pos] = true;

    // 探索する
    for (int i = 0; i < E[pos].size(); i++)
    {
      // 容量 0 の辺は使えない
      if (E[pos][i].cap == 0)
        continue;

      // 既に訪問した頂点に行っても意味がない
      if (visited[E[pos][i].to] == true)
        continue;

      // 目的地までのパスを探す
      T flow = AugmentingPath(E[pos][i].to, goal, min(fl, E[pos][i].cap));

      // フローを流せる場合、残余グラフの容量を flow だけ増減させる
      if (flow >= 1)
      {
        E[pos][i].cap -= flow;
        E[E[pos][i].to][E[pos][i].rev].cap += flow;
        return flow;
      }
    }

    // すべての辺を探索しても見つからなかった ･･･
    return 0;
  }

  // 頂点 s から頂点 t までの最大フローの総流量を返す
  int MaximumFlow(int s, int t)
  {
    int total = 0;
    while (true)
    {
      for (int i = 0; i < V; i++)
        visited[i] = false;
      int fl = AugmentingPath(s, t, inf);

      // フローを流せなくなったら操作終了
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