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
#define pr(x) cout << x;
#define prd(x) cout << setprecision(50) << x;
#define pn() cout << '\n';
#define ps() cout << ' ';
#define MOD2 998244353
#define MAX_N 100100
ll zero = 0;

ll rl()
{
  ll n;
  cin >> n;
  return n;
}
dd rd()
{
  dd n;
  cin >> n;
  return n;
}
str rs()
{
  str n;
  cin >> n;
  return n;
}
iv rv(ll n)
{
  iv a(n, 0);
  rep(i, n) { cin >> a[i]; }
  return a;
}

int main()
{
  FAST;
  dd L = rd();
  prd(L * L * L / 27);
  pn();
  return 0;
}