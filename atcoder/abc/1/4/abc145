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
#define pr(x) cout << x
#define prd(x) cout << fixed << setprecision(50) << x
#define pn() cout << '\n'
#define ps() cout << ' '
#define ret return
#define MOD2 998244353
#define MAX_N 100100
ll zero = 0;

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

dd dist(dv x, dv y, ll i, ll j)
{
  return pow((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]), 0.5);
}

int main()
{
  FAST;
  ll n = rl();
  dd ans = 0, f = 1;
  dv x(n), y(n), prm(n);
  rep(i, n)
  {
    cin >> x[i] >> y[i];
    f *= (i + 1);
    prm[i] = i + 1;
  }
  do
  {
    rep(i, n - 1)
    {
      ans += dist(x, y, prm[i] - 1, prm[i + 1] - 1);
    }
  } while (next_permutation(prm.begin(), prm.end()));
  prd(ans / f);
  pn();
  ret 0;
}