#include <bits/stdc++.h>
using namespace std;

struct Graph
{
  int V;
  vector<vector<int>> E;
  vector<int> degree;

  Graph(int n)
  {
    V = n;
    E.resize(n);
    degree.resize(n, 0);
  }

  void add_edge(int u, int v)
  {
    E[u].push_back(v);
    degree[v]++;
  }

  vector<int> TopologicalSort()
  {
    priority_queue<int, vector<int>, greater<int>> next;
    vector<int> ans;
    for (int i = 0; i < V; i++)
      if (degree[i] == 0)
        next.push(i);

    while (!next.empty())
    {
      int cur = next.top();
      next.pop();
      ans.push_back(cur);
      for (auto &x : E[cur])
      {
        degree[x]--;
        if (degree[x] == 0)
          next.push(x);
      }
    }
    return ans;
  }
};

int main()
{
  int n, m, u, v;
  cin >> n >> m;
  Graph G(n);
  while (m--)
  {
    cin >> u >> v;
    G.add_edge(u, v);
  }

  auto ts = G.TopologicalSort();
  // ts-iin size n 0 baival, cycle baigaa gesn ug ym shig bn lee.

  for (auto &x : ts)
    cout << x << '\n';
  return 0;
}

// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B