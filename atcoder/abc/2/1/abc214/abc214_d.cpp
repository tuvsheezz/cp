#include <bits/stdc++.h>
using namespace std;
#define FAST                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define ll long long
#define ull unsigned long long
#define str string
#define ivec vector<ll>
#define dvec vector<double>
#define repa(i, s, e) for (ll i = s; i < e; i++)
#define repd(i, s, e) for (ll i = s; i >= e; i--)
#define repin(a, n)          \
  for (ll i = 0; i < n; i++) \
  cin >> a[i]
#define sort_vec(v) sort(v.begin(), v.end())
#define sort_arr(v, n) sort(v, v + n)
#define MAX_N 100100

struct UnionFind
{
  ll par[MAX_N];
  ll siz[MAX_N];

  void init(ll n)
  {
    repa(i, 0, n)
    {
      par[i] = i;
      siz[i] = 1;
    }
  }

  ll root(ll x) { return par[x] == x ? x : par[x] = root(par[x]); }
  bool same(ll x, ll y) { return root(x) == root(y); }
  void unite(ll x, ll y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
      return;
    if (siz[x] < siz[y])
      swap(x, y);
    par[y] = x;
    siz[x] += siz[y];
  }
  ll get_size(ll x) { return siz[root(x)]; }
};

ll n, u, v, w, a = 0;
UnionFind uf;
multimap<ll, pair<ll, ll>> mp;

int main()
{
  FAST;
  cin >> n;
  uf.init(n);
  repa(i, 0, n - 1)
  {
    cin >> u >> v >> w;
    mp.emplace(w, make_pair(u, v));
  }
  for (auto const &x : mp)
  {
    // cout << x.first << " -> " << x.second.first << ": " << x.second.second << endl;
    a += uf.get_size(x.second.first) * uf.get_size(x.second.second) * x.first;
    uf.unite(x.second.first, x.second.second);
  }
  cout << a << endl;
  return 0;
}