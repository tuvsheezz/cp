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
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, e) for (ll i = 0; i < e; i++)
#define repa(i, s, e) for (ll i = s; i < e; i++)
#define repd(i, s, e) for (ll i = s; i >= e; i--)
#define vsorta(v) sort(v.begin(), v.end())
#define vsortd(v) sort(v.begin(), v.end(), greater<>())
#define sort_arr(v, n) sort(v, v + n)
#define rev(v) reverse(v.begin(), v.end())
#define pr(x) cout << x
#define prd(x) cout << fixed << setprecision(50) << x
#define PN cout << '\n'
#define PS cout << ' '
#define ret return
#define INF (1LL << 60)
#define MOD2 998244353
#define MAX_N 100100

ll rl()
{
  ll n;
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

int main()
{
  FAST;
  ll n = rl(), ans = 0;
  iv x = rv(n), y = rv(n);
  rep(i, n) { ans += (x[i] > y[i]) ? x[i] - y[i] : 0; }
  pr(ans);
  PN;
  ret 0;
}