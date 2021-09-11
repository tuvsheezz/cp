#include <bits/stdc++.h>
using namespace std;
#define FAST                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define ll long long
#define dd double
#define ull unsigned long long
#define str string
#define iv vector<ll>
#define dv vector<double>
#define MLL map<ll, ll>
#define MSL map<str, ll>
#define MLB map<ll, bool>
#define PQA priority_queue<ll, vector<ll>, greater<ll>>
#define PQD priority_queue<ll, vector<ll>, less<ll>>
#define IT iterator
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, e) for (ll i = 0; i < e; i++)
#define repa(i, s, e) for (ll i = s; i < e; i++)
#define repd(i, s, e) for (ll i = s; i >= e; i--)
#define repauto(x, s) for (auto const &x : s)
#define vsorta(v) sort(v.begin(), v.end())
#define vsortd(v) sort(v.begin(), v.end(), greater<>())
#define sort_arr(v, n) sort(v, v + n)
#define rev(v) reverse(v.begin(), v.end())
#define pr(x) cout << x
#define prd(x) cout << fixed << setprecision(50) << x
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
#define MAX_N 200100
ll rl()
{
  ll n;
  cin >> n;
  ret n;
}
dd rd()
{
  dd n;
  cin >> n;
  ret n;
}
str rs()
{
  str n;
  cin >> n;
  ret n;
}
iv rv(ll n)
{
  iv a(n, 0);
  rep(i, n) { cin >> a[i]; }
  ret a;
}
dv rvd(ll n)
{
  dv a(n, 0);
  rep(i, n) { cin >> a[i]; }
  ret a;
}
ll vsum(iv v)
{
  ll s = 0;
  rep(i, (ll)v.size()) { s += v[i]; }
  ret s;
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

  ll root(ll x) { ret par[x] == x ? x : par[x] = root(par[x]); }
  bool same(ll x, ll y) { ret root(x) == root(y); }
  void unite(ll x, ll y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
      ret;

    if (siz[x] < siz[y])
      swap(x, y);
    par[y] = x;
    siz[x] += siz[y];
    size_max = max(siz[x], size_max);
    count--;
  }
  ll numbers_of_sets() { ret count; }
};

int main()
{
  FAST;
  ll n = rl(), m = rl(), ans = 0;
  iv vans;
  UnionFind uf;
  vector<pair<ll, pair<ll, ll>>> vp;
  uf.init(n);
  rep(i, m)
  {
    ll a = rl(), b = rl(), c = rl();
    vp.PB(MP(c, MP(a, b)));
  }
  vsorta(vp);

  repauto(x, vp)
  {
    if (uf.count == 1)
      vans.PB(x.F);
    else
    {
      if (uf.same(x.S.F, x.S.S) == true)
        vans.PB(x.F);
      else
      {
        uf.unite(x.S.F, x.S.S);
      }
    }
  }

  repauto(x, vans)
  {
    ans += max(x, (ll)0);
  }
  pr(ans);
  PN;
  Ret;
}
