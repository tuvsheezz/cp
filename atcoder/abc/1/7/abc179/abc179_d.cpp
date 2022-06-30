#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ll n, k, l, r;
  cin >> n >> k;
  vector<ll> dp(n, 0);
  vector<ll> cs(n + 1, 0);
  dp[0] = 1;
  cs[1] = 1;
  vector<pair<ll, ll>> c(k);
  for (int i = 0; i < k; i++)
  {
    cin >> l >> r;
    c[i] = make_pair(l, r);
  }

  sort(c.begin(), c.end());

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < k; j++)
    {
      l = max(0LL, i - c[j].second);
      r = max(0LL, i - c[j].first + 1);
      dp[i] = (dp[i] + cs[r] - cs[l] + mod) % mod;
    }
    cs[i + 1] = (cs[i] + dp[i]) % mod;
  }
  cout << dp[n - 1] << endl;
  return 0;
}
