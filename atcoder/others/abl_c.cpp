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

ll par[MAX_N];
ll ran[MAX_N] = {0};

void init(ll n)
{
  repa(i, 0, n)
      par[i] = i;
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
  if (ran[x] < ran[y])
    par[x] = y;
  else
  {
    par[y] = x;
    if (ran[x] == ran[y])
      ran[x]++;
  }
}

ll n, m, x, y, c = 0;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  init(n);
  repa(i, 0, m)
  {
    cin >> x >> y;
    unite(x - 1, y - 1);
  }

  repa(i, 0, n)
  {
    if (!same(0, i))
    {
      unite(0, i);
      c++;
    }
  }

  cout << c << endl;
  return 0;
}