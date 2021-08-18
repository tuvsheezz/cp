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
#define MOD2 998244353
#define MAX_N 200200

struct UnionFind
{
  ll par[MAX_N];
  ll ran[MAX_N] = {0};
  ll siz[MAX_N];
  ll size_max = 0;
  ll count;

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

  ll root(ll x)
  {
    return par[x] == x ? x : par[x] = root(par[x]);
  }

  bool same(ll x, ll y)
  {
    return root(x) == root(y);
  }

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
    size_max = max(siz[x], size_max);
    count--;
    // if (ran[x] < ran[y])
    //   swap(x, y);

    // par[y] = x;

    // if (ran[x] == ran[y])
    //   ran[x]++;
  }
  ll numbers_of_sets()
  {
    return count;
  }
};

ll big_pow(ll x, ll n, ll mod)
{
  if (n == 0)
    return 1;
  ll z = big_pow(x * x % mod, n / 2, mod);
  if (n & 1)
    z = z * x % mod;
  return z;
}

ll n, c;
UnionFind uf;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  uf.init(n);
  repa(i, 0, n)
  {
    cin >> c;
    uf.unite(i, c - 1);
  }

  cout << (big_pow(2, uf.numbers_of_sets(), MOD2) - 1) % MOD2 << endl;
  return 0;
}