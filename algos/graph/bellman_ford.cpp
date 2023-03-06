#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BellmanFord
{
  struct edge
  {
    int from, to;
    T cost;
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
  };

  int V;
  const T inf = numeric_limits<T>::max() / 2;
  vector<edge> E;

  BellmanFord(int n) : V(n) {}

  void add_edge(int from, int to, T cost) { E.emplace_back(from, to, cost); }

  // yaj hereglehiin buu med
  bool find_negative_loop()
  {
    vector<T> dist(V, 0);
    bool updated = true;
    for (int i = 0; i < V; i++)
    {
      for (auto &e : E)
      {
        if (dist[e.from] + e.cost < dist[e.to])
        {
          dist[e.to] = dist[e.from] + e.cost;
          updated = true;
        }
      }
      if (!updated)
        return true;
      if (i == V - 1)
        return false;
      updated = false;
    }
  }
  // busad buh node ruu yvah.
  vector<T> shortest_path_to_all_vertices(int s)
  {
    vector<T> dist(V, inf);
    dist[s] = 0;
    bool updated = true;
    for (int i = 0; i < V; i++)
    {
      for (auto &e : E)
      {
        if (dist[e.from] != inf && dist[e.from] + e.cost < dist[e.to])
        {
          dist[e.to] = dist[e.from] + e.cost;
          updated = true;
        }
      }
      if (!updated)
        break;
      if (i == V - 1)
        return {};
      updated = false;
    }
    return dist;
  }
  // s-ees t ruu yvah. (hamaaralgui gazar uusch baigaa negative loop-g tootsohgui)
  vector<T> shortest_path_to_one_vertex(int s, int t)
  {
    vector<T> dist(V, inf);
    dist[s] = 0;
    for (int i = 0; i < 2 * V - 1; i++)
    {
      for (auto &e : E)
      {
        if (dist[e.from] != inf && dist[e.from] + e.cost < dist[e.to])
        {
          dist[e.to] = dist[e.from] + e.cost;
          if (i >= V - 1)
          {
            if (e.to == t)
              return {};
            dist[e.to] = -inf;
          }
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

  int V, E, r;
  cin >> V >> E >> r;

  BellmanFord<int> BF(V);

  for (int i = 0; i < E; i++)
  {
    int s, t, d;
    cin >> s >> t >> d;
    BF.add_edge(s, t, d);
  }

  auto ans = BF.shortest_path_to_all_vertices(r);
  if (ans.empty())
  {
    cout << "NEGATIVE CYCLE" << '\n';
    return 0;
  }
  for (int i = 0; i < V; i++)
  {
    if (ans[i] > 1e9)
      cout << "INF" << '\n';
    else
      cout << ans[i] << '\n';
  }
  return 0;
}

// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B
// O(V * E)