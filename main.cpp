#include <bits/stdc++.h>
using namespace std;

struct Graph
{
  int V;
  vector<vector<int>> edges;
  vector<vector<int>> t_edges;
  vector<bool> visited, t_visited;
  stack<int> order;
  vector<vector<int>> scc;
  vector<int> tmp;

  Graph(int n)
  {
    V = n;
    edges.resize(n);
    t_edges.resize(n);
    visited.resize(n, false);
    t_visited.resize(n, false);
  }

  void add_edge(int u, int v)
  {
    edges[u].push_back(v);
    t_edges[v].push_back(u);
  }

  void fill_order(int root)
  {
    visited[root] = true;
    for (auto &x : edges[root])
    {
      if (!visited[x])
        fill_order(x);
    }
    order.push(root);
  }

  void DFS(int root)
  {
    tmp.push_back(root);
    t_visited[root] = true;
    for (auto &x : t_edges[root])
    {
      if (!t_visited[x])
        DFS(x);
    }
  }

  vector<vector<int>> SCC()
  {
    for (int i = 0; i < V; i++)
    {
      if (!visited[i])
        fill_order(i);
    }

    while (!order.empty())
    {
      int x = order.top();
      order.pop();

      if (!t_visited[x])
      {
        tmp.clear();
        DFS(x);
        scc.push_back(tmp);
      }
    }
    return scc;
  }
};

struct UnionFind
{
  vector<int> parent, size;
  int size_max = 0, count;

  UnionFind(int n)
  {
    parent.resize(n, -1);
    size.resize(n, 1);
    count = n;
    size_max = 1;
  }

  int root(int x) { return parent[x] == -1 ? x : parent[x] = root(parent[x]); }
  bool same(int x, int y) { return root(x) == root(y); }
  void unite(int x, int y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
      return;

    if (size[x] < size[y])
      swap(x, y);
    parent[y] = x;
    size[x] += size[y];
    size_max = max(size[x], size_max);
    count--;
  }
  int count_of_sets() { return count; }
  int get_union_size(int x) { return size[root(x)]; }
};

int main()
{
  int n, m, Q, x, y;
  cin >> n >> m;

  Graph G(n);
  UnionFind uf(n);

  for (int i = 0; i < m; i++)
  {
    cin >> x >> y;
    G.add_edge(x, y);
  }

  auto cycles = G.SCC();
  for (auto &xx : cycles)
  {
    for (int i = 1; i < xx.size(); i++)
      uf.unite(xx[i], xx[i - 1]);
  }

  cin >> Q;

  while (Q--)
  {
    cin >> x >> y;
    cout << uf.same(x, y) << '\n';
  }
  return 0;
}

// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C