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
#define INF 2e63

int main()
{
  FAST;
  ll n, orr, xorr, ans = INF; cin >> n;
  vector<ll> a(n);
  for(auto &i : a) cin >> i;
  repa(i, 0, 1 << (n - 1)) {
    orr = 0; xorr = 0;
    repa(j, 0, n + 1) {
      if(j < n) orr |= a[j];
      if(j == n || (i >> j & 1)) {
        xorr ^= orr;
        orr = 0;
      }
    }
    ans = min(ans, xorr);
  }
  cout << ans << '\n';
  return 0;
}