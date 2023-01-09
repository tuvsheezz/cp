#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
  ll h, w, dp[1010][1010] = {0};
  cin >> h >> w;
  char a[h + 10][w + 10];
  for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) cin >> a[i][j];
  dp[0][0] = 1;

  for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) {
    if (a[i][j] == '#')
      continue;
    ll c = 0;
    if (i > 0 && a[i - 1][j] != '#')
      dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
    if (j > 0 && a[i][j - 1] != '#')
      dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
  }
  cout << dp[h - 1][w - 1] << endl;
  return 0;
}
