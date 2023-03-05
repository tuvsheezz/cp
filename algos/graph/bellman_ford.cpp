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

  int n;
  const T inf = numeric_limits<T>::max() / 2;
  vector<T> d;
  vector<edge> es;

  BellmanFord(int n) : n(n), d(n) {}

  void add_edge(int from, int to, T cost) { es.emplace_back(from, to, cost); }

  bool find_negative_loop()
  {
    fill(d.begin(), d.end(), 0);
    for (int i = 0, updated = 1; i < n && exchange(updated, 0); i++)
    {
      for (auto &e : es)
      {
        if (d[e.from] + e.cost < d[e.to])
        {
          d[e.to] = d[e.from] + e.cost;
          updated = 1;
        }
      }
      if (!updated)
        return true;
      if (i == n - 1)
        return false;
    }
  }

  vector<T> solve(int s)
  {
    fill(d.begin(), d.end(), inf);
    d[s] = 0;
    for (int i = 0, updated = 1; i < n and exchange(updated, 0); i++)
    {
      for (auto &e : es)
      {
        if (d[e.from] != inf and d[e.from] + e.cost < d[e.to])
        {
          d[e.to] = d[e.from] + e.cost;
          updated = 1;
        }
      }
      if (!updated)
        break;
      if (i == n - 1)
        return {};
    }
    return d;
  }

  vector<T> shortest_path(int s, int t)
  {
    fill(d.begin(), d.end(), inf);
    d[s] = 0;
    for (int i = 0; i < 2 * n - 1; i++)
    {
      for (auto &e : es)
      {
        if (d[e.from] != inf and d[e.from] + e.cost < d[e.to])
        {
          d[e.to] = d[e.from] + e.cost;
          if (i >= n - 1)
          {
            if (e.to == t)
              return {};
            d[e.to] = -inf;
          }
        }
      }
    }
    return d;
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

  auto ans = BF.solve(r);
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