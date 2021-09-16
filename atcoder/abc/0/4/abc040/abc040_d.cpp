#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793238462643383279502884L
#define ll long long
#define dd double
#define ull unsigned long long
#define str string
#define iv vector<ll>
#define ivv vector<vector<ll>>
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
#define MAX_N 100100
ll ssize(str s)
{
  ret(ll) s.size();
}
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
  iv par, ran, siz;
  ll size_max = 0;
  ll count;

  void init(ll n)
  {
    par.resize(n);
    ran.resize(n, 0);
    siz.resize(n);
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
  ll get_size(ll x) { ret siz[root(x)]; }
  ll numbers_of_sets() { ret count; }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  UnionFind uf;
  ll n = rl(), m = rl();
  uf.init(n);
  vector<pair<ll, pair<ll, ll>>> br(m);
  rep(i, m)
  {
    ll u = rl(), w = rl(), b = rl();
    br[i] = MP(b, MP(u - 1, w - 1));
  }
  ll pc = rl();
  iv ans(pc, 0);
  vector<pair<ll, pair<ll, ll>>> pe(pc);
  rep(i, pc)
  {
    ll u = rl(), b = rl();
    pe[i] = MP(b, MP(u - 1, i));
  }
  ll i = 0;
  vsortd(pe);
  vsortd(br);
  repauto(x, pe)
  {
    while (x.F < br[i].F && i < (ll)br.size())
    {
      uf.unite(br[i].S.F, br[i].S.S);
      i++;
    }
    ans[x.S.S] = uf.get_size(x.S.F);
  }
  repauto(x, ans)
  {
    pr(x);
    PN;
  }
  Ret;
}
