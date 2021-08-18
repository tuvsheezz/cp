#include <bits/stdc++.h>
using namespace std;
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
str cyesno(bool cond)
{
  return cond ? "Yes" : "No";
}
str uyesno(bool cond)
{
  return (cond) ? "YES" : "NO";
}

struct UnionFind
{
  ll par[MAX_N];
  ll ran[MAX_N] = {0};
  ll siz[MAX_N];
  ll size_max = 0;
  ll count;
  ll fri[MAX_N] = {0};
  ll blo[MAX_N] = {0};
  void init(ll n)
  {
    repa(i, 0, n)
    {
      par[i] = i;
      siz[i] = 1;
    }
    count = n;
    size_max = 1;
  }
  ll root(ll x) { return par[x] == x ? x : par[x] = root(par[x]); }
  bool same(ll x, ll y) { return root(x) == root(y); }
  void unite(ll x, ll y)
  {
    fri[x]++;
    fri[y]++;
    x = root(x);
    y = root(y);
    if (x == y)
      return;

    if (siz[x] < siz[y])
      swap(x, y);
    par[y] = x;
    siz[x] += siz[y];
    size_max = max(siz[x], size_max);
    count--;
  }
  void block(ll x, ll y)
  {
    if (root(x) == root(y))
    {
      blo[x]++;
      blo[y]++;
    }
  }
  ll numbers_of_sets() { return count; }
  ll suggestion_count(ll x) { return siz[root(x)] - fri[x] - blo[x] - 1; }
};

ll n, m, k, a, b;
UnionFind uf;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  uf.init(n);
  repa(i, 0, m)
  {
    cin >> a >> b;
    uf.unite(a - 1, b - 1);
  }
  repa(i, 0, k)
  {
    cin >> a >> b;
    uf.block(a - 1, b - 1);
  }
  repa(i, 0, n)
  {
    cout << uf.suggestion_count(i) << " ";
  }
  cout << endl;
  return 0;
}