#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define dd double
#define str string
#define ivec vector<ll>
#define dvec vector<double>
#define repa(i, s, e) for(ll i = s; i < e; i++)
#define rep(n) for(ll i = 0; i < n; i++)
#define repa(i, s, e) for(ll i = s; i < e; i++)
#define repd(i, s, e) for(ll i = s; i >= e; i--)
#define vsorta(v) sort(v.begin(), v.end())
#define vsortd(v) sort(v.begin(), v.end(), greater<>())
#define sort_arr(v, n) sort(v, v + n)
#define MOD2 998244353
#define MAX_N 100100
ll rl() { ll n; cin >> n; return n; }
dd rd() { dd n; cin >> n; return n; }

int main()
{
  FAST;
  ll n = rl(), x = rl() * 100, ans = 0L, sum = 0L;
  rep(n) {
    ll v = rl(), p = rl();
    sum += v * p;
    if(x < sum && ans == 0) ans = i + 2;
  }
  cout << ans - 1 << '\n';
  return 0;
}
