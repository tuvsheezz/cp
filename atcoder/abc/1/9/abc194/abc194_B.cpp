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
  ll n, ans = 10e15, a[2][1010]; cin >> n;
  repa(i, 0, n) { cin >> a[0][i] >> a[1][i]; }
  repa(i, 0, n) {
    repa(j, 0, n) {
      if(i == j)
        ans = min(ans, a[0][i] + a[1][i]);
      else
        ans = min(ans, max(a[0][i], a[1][j]));
    }
  }
  cout << ans << '\n';
  return 0;
}
