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
#define MOD2 998244353

#define MAX_N 1000000

ll n, m, k, x, y, mx = 0;
vector<pair<ll, ll>> c;
vector<pair<ll, ll>> d;

int main()
{
  FAST;
  cin >> n >> m;
  repa(i, 0, m)
  {
    cin >> x >> y;
    c.push_back(make_pair(x, y));
  }
  cin >> k;
  repa(i, 0, k)
  {
    cin >> x >> y;
    d.push_back(make_pair(x, y));
  }

  repa(i, 0, 1 << k)
  {
    x = 0;
    map<ll, bool> mp;
    repd(j, k - 1, 0)
    {
      if (i & (1 << j))
        mp[d[j].first] = true;
      else
        mp[d[j].second] = true;
    }

    repa(q, 0, m)
    {
      if (mp[c[q].first] && mp[c[q].second])
        x++;
    }
    mx = max(mx, x);
  }
  cout << mx << endl;
  return 0;
}