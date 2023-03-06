#include <bits/stdc++.h>
using namespace std;

template <class T>
struct Graph
{
  int V;
  const T inf = numeric_limits<T>::max() / 2;
  vector<vector<pair<int, T>>> edges; // PLL: (destination, cost)
  bool is_directed;

  Graph(int n, bool dir = false)
  {
    V = n;
    edges.resize(n);
    is_directed = dir;
  }

  void add_edge(int u, int v, T cost)
  {
    edges[u].push_back({v, cost});
    if (!is_directed)
      edges[v].push_back({u, cost});
  }

  vector<int> Dijkstra(int s)
  {
    vector<T> dist(V, inf);
    vector<int> prev(V, -1);
    dist[s] = 0;
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> next_to_visit;

    next_to_visit.push({0, s});

    while (!next_to_visit.empty())
    {
      pair<T, int> current_node = next_to_visit.top();
      next_to_visit.pop();
      int v = current_node.second;

      if (dist[v] < current_node.first)
        continue;

      for (auto &edge : edges[v])
      {
        if (dist[edge.first] > dist[v] + edge.second)
        {
          dist[edge.first] = dist[v] + edge.second;
          prev[edge.first] = v;
          next_to_visit.push({dist[edge.first], edge.first});
        }
      }
    }
    return prev;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m, u, v, w;
  cin >> n >> m;
  Graph<long long> G(n);
  while (m--)
  {
    cin >> u >> v >> w;
    G.add_edge(u - 1, v - 1, w);
  }

  auto prev = G.Dijkstra(0);
  stack<int> st;
  st.push(n);
  while (st.top() != 1)
  {
    st.push(prev[st.top() - 1] + 1);
  }
  while (!st.empty())
  {
    cout << st.top() << " ";
    st.pop();
  }
  cout << '\n';
  return 0;
}

// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ek