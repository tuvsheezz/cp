#include <bits/stdc++.h>
using namespace std;

template <class T>
struct Graph
{
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
  vector<tuple<int, int, T>> get_edges()
  {
    vector<tuple<int, int, T>> ret;
    for (int from = 0; from < V; from++)
      for (auto &[to, cost] : E[from])
        if (to > from)
          ret.push_back({from, to, cost});
    return ret;
  }
};

template <class T>
pair<T, Graph<T>> Prim(Graph<T> &G)
{
  const T INF = numeric_limits<T>::max();
  int n = G.V;
  T total = 0;

  Graph<T> MST(n);
  vector<bool> visited(n);
  vector<T> dist(n, INF);
  vector<int> pre(n, -1);

  priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> pq;

  for (int s = 0; s < G.V; s++)
  {
    if (!visited[s])
    {
      dist[s] = 0;
      pq.push({0, s});
      while (!pq.empty())
      {
        int from = pq.top().second;
        pq.pop();

        if (visited[from])
          continue;

        visited[from] = true;
        if (pre[from] != -1)
        {
          total += dist[from];
          MST.add_edge(from, pre[from], dist[from]);
        }

        for (auto &[to, cost] : G.E[from])
        {
          if (!visited[to] && dist[to] > cost)
          {
            dist[to] = cost;
            pre[to] = from;
            pq.push({dist[to], to});
          }
        }
      }
    }
  }
  return {total, MST};
}

int main()
{
  int n, m, u, v, w;
  cin >> n >> m;
  Graph<int> G(n);

  while (m--)
  {
    cin >> u >> v >> w;
    G.add_edge(u, v, w);
  }

  auto ans = Prim(G);

  // cout << ans.second.V << endl;
  // for (auto &[from, to, cost] : ans.second.get_edges())
  //   cout << from << " " << to << " " << cost << endl;

  cout << ans.first << endl;
  return 0;
}
