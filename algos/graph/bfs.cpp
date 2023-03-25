#include <bits/stdc++.h>
using namespace std;

struct Graph
{
  int V;
  vector<vector<int>> E;
  bool is_directed;

  Graph(int n, bool dir = false)
  {
    V = n;
    E.resize(n);
    is_directed = dir;
  }

  void add_edge(int u, int v)
  {
    E[u].push_back(v);
    if (!is_directed)
      E[v].push_back(u);
  }
  int BFS(int root, int goal)
  {
    vector<bool> visited(V, false);
    queue<int> next;

    visited[root] = true;
    next.push(root);
    vector<int> dist(V, 1e8);

    dist[root] = 0;

    while (!next.empty())
    {
      int current_node = next.front();
      next.pop();
      for (auto &x : E[current_node])
      {
        if (!visited[x])
        {
          dist[x] = dist[current_node] + 1;
          visited[x] = true;
          next.push(x);
        }
      }
    }
    return dist[goal];
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int r, c, sx, sy, gx, gy;
  cin >> r >> c >> sx >> sy >> gx >> gy;
  int v = r * c, s = (sx - 1) * c + sy - 1, g = (gx - 1) * c + gy - 1;

  Graph G;
  G.init(v);
  vector<string> cc(r);
  for (int i = 0; i < r; i++)
  {
    cin >> cc[i];
    for (int j = 0; j < c; j++)
    {
      if (cc[i][j] == '#')
        continue;
      if (j > 0 && cc[i][j] == '.' && cc[i][j - 1] == '.')
        G.add_edge(i * c + j - 1, i * c + j);
      if (i > 0 && cc[i][j] == '.' && cc[i - 1][j] == '.')
        G.add_edge((i - 1) * c + j, i * c + j);
    }
  }
  cout << G.BFS(s, g) << '\n';
  return 0;
}

// https://atcoder.jp/contests/tessoku-book/tasks/abc007_3