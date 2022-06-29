#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll h, w;
  cin >> h >> w;
  vector<vector<char>> s(h, vector<char>(w));
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      cin >> s[i][j];

  vector<vector<ll>> dp(h + 1, vector<ll>(w + 1, 0));
  vector<vector<ll>> dpx(h + 1, vector<ll>(w + 1, 0));
  vector<vector<ll>> dpy(h + 1, vector<ll>(w + 1, 0));
  vector<vector<ll>> dpd(h + 1, vector<ll>(w + 1, 0));

  dpx[1][1] = 1;
  dpy[1][1] = 1;
  dpd[1][1] = 1;
  for (int i = 1; i <= h; i++)
  {
    for (int j = 1; j <= w; j++)
    {
      if (s[i - 1][j - 1] == '#')
        continue;
      dp[i][j] = (dpx[i - 1][j] + dpy[i][j - 1] + dpd[i - 1][j - 1]) % mod;
      dpx[i][j] += (dp[i][j] + dpx[i - 1][j]) % mod;
      dpy[i][j] += (dp[i][j] + dpy[i][j - 1]) % mod;
      dpd[i][j] += (dp[i][j] + dpd[i - 1][j - 1]) % mod;
    }
  }
  cout << dp[h][w] % mod << endl;
  return 0;
}
