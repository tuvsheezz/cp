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
#define ivec vector<ll>
#define dvec vector<double>
#define repa(i, s, e) for (ll i = s; i < e; i++)
#define repd(i, s, e) for (ll i = s; i >= e; i--)
#define vsorta(v) sort(v.begin(), v.end())
#define vsortd(v) sort(v.begin(), v.end(), greater<>())
#define sort_arr(v, n) sort(v, v + n)
#define MOD2 998244353
#define MAX_N 100100

int main()
{
  FAST;
  map<ll, bool> checked;
  ll n;
  cin >> n;
  ll ans = n;
  for (ll i = 2; i * i <= n; i++)
  {
    ll c = i * i;
    while (c <= n)
    {
      if (!checked[c])
        ans--;
      checked[c] = true;
      c *= i;
    }
  }
  cout << ans << '\n';
  return 0;
}
