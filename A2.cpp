#include <bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[], int src, int dest)
{
  adj[src].push_back(dest);
}

bool BFS(vector<int> adj[], int src, int dest, int v, int pred[], int dist[])
{
  list<int> queue;
  bool visited[v];
  for (int i = 0; i < v; i++)
  {
    visited[i] = false;
    dist[i] = INT_MAX;
    pred[i] = -1;
  }

  visited[src] = true;
  dist[src] = 0;
  queue.push_back(src);

  while (!queue.empty())
  {
    int u = queue.front();
    queue.pop_front();
    for (int i = 0; i < adj[u].size(); i++)
    {
      if (visited[adj[u][i]] == false)
      {
        visited[adj[u][i]] = true;
        dist[adj[u][i]] = min(dist[adj[u][i]], dist[u] + 1);
        pred[adj[u][i]] = u;
        queue.push_back(adj[u][i]);

        if (adj[u][i] == dest)
          return true;
      }
    }
  }

  return false;
}

int shortestDistance(vector<int> adj[], int s, int dest, int v)
{
  int pred[v], dist[v];

  if (BFS(adj, s, dest, v, pred, dist) == false)
  {
    return -1;
  }

  return dist[dest];
}

int solve()
{
  vector<int> adj[30];
  int a[30][30], K;
  string S;
  cin >> S;
  cin >> K;
  vector<int> cand;
  while (K--)
  {
    string P;
    cin >> P;
    int x = P[0] - 'A', y = P[1] - 'A';
    add_edge(adj, x, y);
  }
  for (int i = 0; i < 30; i++)
    for (int j = 0; j < 30; j++)
      a[i][j] = shortestDistance(adj, i, j, 30);
  for (int i = 0; i < 26; i++)
  {
    bool flag = true;
    int cost = 0;
    for (int j = 0; j < S.size(); j++)
    {
      int x = S[j] - 'A';
      if (i == x)
        continue;
      if (a[x][i] == -1)
      {
        flag = false;
        break;
      }
      else
        cost += a[x][i];
    }
    if (flag)
      cand.push_back(cost);
  }
  if (cand.empty())
  {
    return -1;
  }
  sort(cand.begin(), cand.end());
  return cand[0];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++)
    printf("Case #%d: %d\n", i, solve());
  return 0;
}