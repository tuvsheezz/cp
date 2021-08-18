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
#define MOD 1000000007
#define MAX_N 3030

ll fac[MAX_N];

void set_fac()
{
  fac[0] = 0;
  fac[1] = 1;
  repa(i, 2, MAX_N)
  {
    fac[i] = (fac[i - 1] * i) % MOD;
  }
}

int main()
{
  FAST;
  ll n, a[MAX_N], b[MAX_N], ans, wq, wq1;

  set_fac();
  fac[1] = 0;
  cin >> n;
  repa(i, 0, n) cin >> a[i];
  repa(i, 0, n) cin >> b[i];
  ans = fac[n];
  wq = fac[n - 1];
  wq1 = fac[n - 1];
  repa(i, 0, n)
  {
    ll ind = n - i - 2;
    if (ind < 0)
      ind = 0;
    ans = (ans - wq + MOD) % MOD;
    wq = (wq - fac[ind] + MOD) % MOD;
    if (b[i] != a[i])
    {
      ans = (ans - wq1 + MOD) % MOD;
      ind--;
      if (ind < 0)
        ind = 0;
      wq1 = (wq1 - fac[ind] + MOD) % MOD;
    }
  }
  cout << ans << endl;
  return 0;
}