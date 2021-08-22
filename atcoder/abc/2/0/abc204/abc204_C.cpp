#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define dd double
#define ull unsigned long long
#define str string
#define ivec vector<ll>
#define dvec vector<double>
#define repa(i, s, e) for (ll i = s; i < e; i++)
#define repd(i, s, e) for (ll i = s; i >= e; i--)
#define vsorta(v) sort(v.begin(), v.end())
#define vsortd(v) sort(v.begin(), v.end(), greater<>())
#define sort_arr(v, n) sort(v, v + n)
#define MOD2 998244353
#define MAX_N 100100

ll ans = 0;

class Graph
{
public:
  map<int, bool> visited;
  map<int, vector<int>> adj;
  void addEdge(int v, int w);
  void DFS(int v);
  void resetVisited();
};
void Graph::resetVisited() { visited.clear(); }
void Graph::addEdge(int v, int w) { adj[v].push_back(w); }
void Graph::DFS(int v)
{
  visited[v] = true;
  vector<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i) {
    if (!visited[*i]) {
      ans++;
      DFS(*i);
    }
  }
}

int main()
{
  FAST;
  Graph g;
  ll n, m, v, w;
  cin >> n >> m;
  repa(i, 0, m) {
    cin >> v >> w;
    g.addEdge(v, w);
  }
  repa(i, 1, n + 1) {
    g.DFS(i);
    g.resetVisited();
  }
  cout << ans + n << '\n';
  return 0;
}