#include <bits/stdc++.h>
using namespace std;

struct Graph
{
  int V;
  const int inf = 1e9;
  vector<vector<pair<int, int>>> E; // PLL: (destination, cost)
  bool is_directed;

  Graph(int n, bool dir = false)
  {
    V = n;
    E.resize(n);
    is_directed = dir;
  }

  void add_edge(int u, int v, int cost)
  {
    E[u].push_back({v, cost});
    if (!is_directed)
      E[v].push_back({u, cost});
  }

  vector<int> ZeroOneBFS(int s)
  {
    vector<int> dist(V, inf);
    dist[s] = 0;

    deque<int> next;
    next.push_back(s);

    while (next.size())
    {
      int from = next.front();
      next.pop_front();
      for (auto [to, cost] : E[from])
      {
        int d = dist[from] + cost;
        if (d < dist[to])
        {
          dist[to] = d;
          if (cost)
            next.push_back(to);
          else
            next.push_front(to);
        }
      }
    }
    return dist;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<pair<int, int>> move = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  Graph G(h * w, true);

  for (int i = 0; i < h; i++)
    cin >> s[i];

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      for (auto [x, y] : move)
        if (i + x >= 0 && i + x < h && j + y >= 0 && j + y < w && s[i + x][j + y] == '.')
          G.add_edge(i * w + j, (i + x) * w + j + y, 0);

      for (int x = -2; x < 3; x++)
        for (int y = -2; y < 3; y++)
          if (!(abs(x) == 2 && abs(y) == 2) && i + x >= 0 && i + x < h && j + y >= 0 && j + y < w)
            G.add_edge(i * w + j, (i + x) * w + j + y, 1);
    }
  }
  auto dist = G.ZeroOneBFS(0);
  cout << dist[h * w - 1] << '\n';
  return 0;
}
