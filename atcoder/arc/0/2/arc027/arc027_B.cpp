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
  ll ava[MAX_N];
  ll count;

  void init(ll n)
  {
    repa(i, 0, n)
    {
      par[i] = i;
      siz[i] = 1;
      ava[i] = 10;
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
    ava[x] = min(ava[x], ava[y]);
    ava[y] = min(ava[x], ava[y]);
    size_max = max(siz[x], size_max);
    count--;
  }
  void set_ava(ll x, ll v) { ava[root(x)] = min(ava[root(x)], v); }
  ll get_ava(ll x) { return ava[root(x)]; }
  ll numbers_of_sets() { return count; }
};

ll n, k;
UnionFind uf;
string s1, s2;
map<char, bool> used;

int main()
{
  FAST;
  uf.init(30);
  cin >> n;
  cin >> s1 >> s2;
  repa(i, 0, n)
  {
    k = 10;
    if (i == 0)
      k--;
    if ('0' <= s1[i] && s1[i] <= '9' && '0' <= s2[i] && s2[i] <= '9' && s1[i] != s2[i])
    {
      cout << 0 << endl;
      return 0;
    }
    if (('0' <= s1[i] && s1[i] <= '9') || ('0' <= s2[i] && s2[i] <= '9'))
    {
      k = 1;
    }
    if ('A' <= s1[i] && s1[i] <= 'Z')
      uf.set_ava(s1[i] - 'A', k);
    if ('A' <= s2[i] && s2[i] <= 'Z')
      uf.set_ava(s2[i] - 'A', k);
    if ('A' <= s1[i] && s1[i] <= 'Z' && 'A' <= s2[i] && s2[i] <= 'Z')
      uf.unite(s1[i] - 'A', s2[i] - 'A');
  }
  k = 1;
  repa(i, 0, n)
  {
    if (('0' <= s1[i] && s1[i] <= '9') || used[s1[i]] == true)
      continue;
    k *= uf.get_ava(s1[i] - 'A');
    used[s1[i]] = true;
  }
  cout << k << endl;
  return 0;
}
