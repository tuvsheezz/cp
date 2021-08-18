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
#define MAX_N 100100

ll n, t, mn = 0, md = 0, a, k;
map<ll, ll> mp;

int main()
{
  FAST;
  cin >> n >> t;
  cin >> a;
  mn = a;
  if (n == 1)
  {
    cout << 0 << endl;
    return 0;
  }
  repa(i, 1, n)
  {
    cin >> a;
    k = a - mn;
    if (k > md)
      md = k;
    mp[k]++;
    if (a < mn)
      mn = a;
  }
  cout << mp[md] << endl;
  return 0;
}