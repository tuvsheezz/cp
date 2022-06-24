#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  ll n, a, s = 0, ans = 0;
  cin >> n >> a;
  vector<ll> p(n);
  for (ll i = 0; i < n; i++)
  {
    cin >> p[i];
    s += p[i];
  }

  vector dp(n + 1, vector<ll>(s + 1, 0));
  dp[0][0] = 1;
  for (ll i = 0; i < n; i++)
    for (ll row = n; row > 0; row--)
      for (ll j = p[i]; j <= s; j++)
        dp[row][j] += dp[row - 1][j - p[i]];

  for (ll i = 1; i <= n; i++)
    for (ll j = 1; j <= s; j++)
      if (j % i == 0 && j / i == a)
        ans += dp[i][j];

  cout << ans << endl;
  return 0;
}
