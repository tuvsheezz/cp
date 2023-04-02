#include <bits/stdc++.h>
using namespace std;

/*
  橋や関節点などを効率的に求める際に有効なアルゴリズム。
  グラフをDFSして, ord[idx] := DFS で頂点に訪れた順番,
  low[idx] := 頂点 idx からDFS木の葉方向の辺を 0 回以上,
  後退辺を 1 回以下通って到達可能な頂点の ord の最小値 を各頂点について求める。
  ある頂点 u が関節点であるとき,DFS木の根については子が 2つ以上,
  それ以外の頂点については 頂点 u のある子 v について ord[u] ≤ low[v] を満たす。
  ある辺(u, v) が橋であるとき, ord[u] < low[v] を満たす。
*/

struct Graph
{
  int V;
  vector<vector<int>> E;
  bool is_directed;
  int ans = 0;

  vector<int> ord, low;
  vector<int> articulations;      // 関節点
  vector<pair<int, int>> bridges; // 橋

  vector<bool> visited;

  Graph(int n, bool dir = false)
  {
    V = n;
    E.resize(n);
    is_directed = dir;
    visited.resize(n, false);
    ord.resize(n, 0);
    low.resize(n, 0);
  }

  void add_edge(int u, int v)
  {
    E[u].push_back(v);
    if (!is_directed)
      E[v].push_back(u);
  }

  void LowLink()
  {
    int k = 0;
    for (int i = 0; i < V; i++)
    {
      if (!visited[i])
        k = dfs(i, k, -1);
    }
  }

  int dfs(int idx, int k, int par)
  {
    visited[idx] = true;
    ord[idx] = k++;
    low[idx] = ord[idx];

    bool is_articulation = false;
    int cnt = 0;

    for (auto &to : E[idx])
    {
      if (!visited[to])
      {
        ++cnt;
        k = dfs(to, k, idx);

        low[idx] = min(low[idx], low[to]);
        is_articulation |= ~par && low[to] >= ord[idx];
        if (ord[idx] < low[to])
          bridges.emplace_back(minmax(idx, (int)to));
      }
      else if (to != par)
        low[idx] = min(low[idx], ord[to]);
    }
    is_articulation |= par == -1 && cnt > 1;
    if (is_articulation)
      articulations.push_back(idx);

    return k;
  }
};

int main()
{
  int n, m, u, v;
  cin >> n >> m;
  Graph G(n);
  for (int i = 0; i < m; i++)
  {
    cin >> u >> v;
    G.add_edge(u, v);
  }
  G.LowLink();
  sort(G.bridges.begin(), G.bridges.end());
  for (auto &x : G.bridges)
    cout << x.first << " " << x.second << endl;
  return 0;
}

// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A
// G.articulations

// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_B
// G.bridges
