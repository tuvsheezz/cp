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
#define vsorta(v) sort(v.begin(), v.end())
#define vsortd(v) sort(v.begin(), v.end(), greater<>())
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
  ll numbers_of_sets() { return count; }
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

ll n, Q, p, x, y;

int main()
{
  FAST;

  return 0;
}