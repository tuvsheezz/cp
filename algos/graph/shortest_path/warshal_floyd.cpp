#include <bits/stdc++.h>
using namespace std;

template <class T>
struct Graph
{
  const T inf = numeric_limits<T>::max() / 2;
  int V;
  vector<vector<pair<int, T>>> E; // PLL: (destination, cost)
  bool is_directed;

  Graph(int n, bool dir = false)
  {
    V = n;
    E.resize(n);
    is_directed = dir;
  }

  void add_edge(int u, int v, T cost)
  {
    E[u].push_back({v, cost});
    if (!is_directed)
      E[v].push_back({u, cost});
  }

  vector<vector<T>> WarshalFloyd()
  {
    vector<vector<T>> dist(V, vector<T>(V, inf));
    for (int i = 0; i < V; i++)
      dist[i][i] = 0;
    for (int i = 0; i < V; i++)
      for (auto &x : E[i])
        dist[i][x.first] = min(dist[i][x.first], x.second);

    for (int k = 0; k < V; k++)
      for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    return dist;
    // (dist[i][j] > numeric_limits<long long>::max() / 4) => INF
    // (dist[i][i] < 0) => Negative cycle
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m, u, v, w;
  cin >> n >> m;
  Graph<long long> G(n, true);
  while (m--)
  {
    cin >> u >> v >> w;
    G.add_edge(u, v, w);
  }

  auto dist = G.WarshalFloyd();
  for (int i = 0; i < n; i++)
  {
    if (dist[i][i] < 0)
    {
      cout << "NEGATIVE CYCLE\n";
      return 0;
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (dist[i][j] > numeric_limits<long long>::max() / 4)
        cout << "INF";
      else
        cout << dist[i][j];
      cout << (j == n - 1 ? '\n' : ' ');
    }
  }

  return 0;
}

// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C