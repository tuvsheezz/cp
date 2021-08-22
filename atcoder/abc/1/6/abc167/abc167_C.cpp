#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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
  ll n, m, exp, ans = 100100100100, pri;
  bool flag = false;
  cin >> n >> m >> exp;
  vector<vector<ll>> a(n, vector<ll>(m));
  vector<ll> price(n);
  repa(i, 0, n) {
    cin >> price[i];
    repa(j, 0, m) cin >> a[i][j];
  }

  repa(i, 0, 1 << n) {
    ll pri = 0;
    vector<ll> xp(m);
    repa(j, 0, n) {
      if (i >> j & 1) {
        pri += price[j];
        repa(k, 0, m) {
          xp[k] += a[j][k];
        }
      }
    }
    bool yes = true;
    repa(k, 0, m) if (xp[k] < exp) yes = false;
    if(yes) ans = min(ans, pri);
  }
  if(ans == 100100100100) cout << "-1\n";
  else cout << ans << '\n';
  return 0;
}