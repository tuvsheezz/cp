#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
template <class T>
using IS = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define PI 3.141592653589793238462643383279502884L
#define LL long long
#define DD double
#define ULL unsigned long long
#define STR string
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
#define MLL map<LL, LL>
#define MSL map<STR, LL>
#define MLB map<LL, bool>
template <class T>
using PQA = priority_queue<T, V<T>, greater<T>>;
template <class T>
using PQD = priority_queue<T, V<T>, less<T>>;
#define IT iterator
#define F first
#define S second
#define PB push_back
#define PLL pair<LL, LL>
#define MP make_pair
#define rep(i, e) for (LL i = 0; i < e; i++)
#define repa(i, s, e) for (LL i = s; i < e; i++)
#define repd(i, s, e) for (LL i = s; i >= e; i--)
#define repauto(x, s) for (auto x : s)
#define rd(...) \
  __VA_ARGS__;  \
  read(__VA_ARGS__)
#define rdv(value, ...) \
  value(__VA_ARGS__);   \
  cin >> value
template <class T>
auto &operator>>(istream &is, vector<T> &xs)
{
  for (auto &x : xs)
    is >> x;
  return is;
}
template <class T>
auto &operator<<(ostream &os, vector<T> &xs)
{
  int sz = xs.size();
  rep(i, sz) os << xs[i] << " \n"[i + 1 == sz];
  return os;
}
template <class T, class Y>
auto &operator<<(ostream &os, pair<T, Y> &xs)
{
  os << "{" << xs.first << ", " << xs.second << "}";
  return os;
}
template <class T, class Y>
auto &operator>>(istream &is, vector<pair<T, Y>> &xs)
{
  for (auto &[x1, x2] : xs)
    is >> x1 >> x2;
  return is;
}
template <class... Args>
auto &read(Args &...args) { return (cin >> ... >> args); }
#define vsorta(v) sort(v.begin(), v.end())
#define vsortd(v) sort(v.begin(), v.end(), greater<>())
#define sort_arr(v, n) sort(v, v + n)
#define rev(v) reverse(v.begin(), v.end())
#define pr(x) cout << x
#define prs(x) cout << x << ' '
#define prn(x) cout << x << '\n'
#define prd() cout << fixed << setprecision(50);
#define Yes cout << "Yes\n"
#define YES cout << "YES\n"
#define No cout << "No\n"
#define NO cout << "NO\n"
#define PN cout << '\n'
#define PS cout << ' '
#define Ret return 0
#define ret return
#define INF (1LL << 60)
#define MOD1 1000000007
#define MOD2 998244353
#define MAX_N 100100

struct Graph
{
  LL vertices;
  V<V<PLL>> edges;
  V<PQA<LL>> kth;
  bool is_directed;

  void init(LL n, bool dir = false)
  {
    vertices = n;
    edges.resize(n);
    kth.resize(n);
    is_directed = dir;
  }

  void add_edge(LL u, LL wu, LL v, LL wv)
  {
    edges[u].PB(MP(v, wv));
    if (!is_directed)
      edges[v].PB(MP(u, wu));
  }
  void BFS(LL root, V<LL> &w)
  {
    V<bool> visited(vertices, false);
    queue<LL> next_to_visit;

    visited[root] = true;
    next_to_visit.push(root);
    V<LL> dist(vertices, INF);
    dist[root] = 0;
    while (!next_to_visit.empty())
    {
      LL current_node = next_to_visit.front();
      next_to_visit.pop();
      repauto(x, edges[current_node])
      {
        if (!visited[x.F])
        {
          dist[x.F] = dist[current_node] + 1;
          visited[x.F] = true;
          next_to_visit.push(x.F);
        }
      }
    }

    V<PLL> z(vertices);
    rep(i, vertices)
    {
      z[i] = MP(dist[i], i);
      visited[i] = false;
    }

    vsortd(z);
    LL p;
    rep(i, vertices)
    {
      p = z[i].S;
      kth[p].push(w[p]);
      repauto(x, edges[p])
      {
        if (dist[x.F] < dist[p])
          continue;

        PQA<LL> tmp = kth[x.F];
        while (!tmp.empty())
        {
          if (kth[p].size() <= 20)
            kth[p].push(tmp.top());
          else if (kth[p].top() < tmp.top())
          {
            kth[p].push(tmp.top());
            kth[p].pop();
          }
          tmp.pop();
        }
      }
    }
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  LL rd(n, Q);
  Graph G;
  G.init(n);

  V<LL> rdv(w, n);
  rep(i, n - 1)
  {
    LL rd(u, v);
    u--, v--;
    G.add_edge(u, w[u], v, w[v]);
  }
  G.BFS(0, w);

  while (Q--)
  {
    LL rd(r, k);
    auto tmp = G.kth[r - 1];
    V<LL> tmp2;
    while (!tmp.empty())
    {
      tmp2.PB(tmp.top());
      tmp.pop();
    }
    vsortd(tmp2);
    prn(tmp2[k - 1]);
  }
  Ret;
}
