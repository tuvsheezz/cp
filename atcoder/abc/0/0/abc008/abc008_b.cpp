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

int main()
{
  FAST;
  ll n, g;
  map<string, ll> mp;
  string x;
  cin >> n;
  repa(i, 0, n)
  {
    cin >> x;
    mp[x]++;
  }
  x = mp.begin()->first;
  g = mp.begin()->second;
  for (auto const &q : mp)
  {
    if (q.second >= g)
    {
      g = q.second;
      x = q.first;
    }
  }
  cout << x << endl;
  return 0;
}