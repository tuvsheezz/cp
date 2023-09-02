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
  int r, c;
  cin >> r >> c;
  int v = r * c, s, g;

  Graph G(v);
  vector<string> cc(r);
  vector<vector<char>> ccc(r, vector<char>(c));
  for (int i = 0; i < r; i++)
  {
    cin >> cc[i];
  }

  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      ccc[i][j] = cc[i][j];
      if (cc[i][j] == 'S')
      {
        s = i * c + j;
        ccc[i][j] = '.';
      }
      if (cc[i][j] == 'G')
      {
        g = i * c + j;
        ccc[i][j] = '.';
      }
    }
  }

  for (int i = 0; i < r; i++)
  {
    // >
    bool f = false;
    for (int j = 0; j < c; j++)
    {
      if (cc[i][j] == '>')
        f = true;
      else if (cc[i][j] == '.')
      {
        if (f)
          ccc[i][j] = '#';
      }
      else
        f = false;
    }
  }
  for (int i = 0; i < r; i++)
  {
    // <
    bool f = false;
    for (int j = c - 1; j >= 0; j--)
    {
      if (cc[i][j] == '<')
        f = true;
      else if (cc[i][j] == '.')
      {
        if (f)
          ccc[i][j] = '#';
      }
      else
        f = false;
    }
  }

  for (int j = c - 1; j >= 0; j--)
  {
    // v
    bool f = false;

    for (int i = 0; i < r; i++)
    {
      if (cc[i][j] == 'v')
        f = true;
      else if (cc[i][j] == '.')
      {
        if (f)
          ccc[i][j] = '#';
      }
      else
        f = false;
    }
  }

  for (int j = c - 1; j >= 0; j--)
  {
    // ^
    bool f = false;

    for (int i = r - 1; i >= 0; i--)
    {
      if (cc[i][j] == '^')
        f = true;
      else if (cc[i][j] == '.')
      {
        if (f)
          ccc[i][j] = '#';
      }
      else
        f = false;
    }
  }

  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (ccc[i][j] != '.')
        continue;
      if (j > 0 && ccc[i][j] == '.' && ccc[i][j - 1] == '.')
        G.add_edge(i * c + j - 1, i * c + j);
      if (i > 0 && ccc[i][j] == '.' && ccc[i - 1][j] == '.')
        G.add_edge((i - 1) * c + j, i * c + j);
    }
  }
  auto ans = G.BFS(s, g);
  if (ans == 1e8)
    ans = -1;
  cout << ans << endl;
  return 0;
}
