#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
  ll h, w, n;
  while(1) {
    cin >> h >> w;
    if(h == 0 && w == 0)
      break;
    cin >> n;
    ll dp[20][20] = {0};
    dp[0][0] = 1;

    map<pair<ll, ll>, ll> mp;
    
    for(int i = 0; i < n; i++) {
      ll x, y;
      cin >> x >> y;
      mp[{x - 1, y - 1}] = 1;
    }
    
    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) {
      if (mp.find({i, j}) != mp.end())
        continue;
      if (i > 0 && mp.find({i - 1, j}) == mp.end())
        dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
      if (j > 0 && mp.find({i, j - 1}) == mp.end())
        dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
    }
    cout << dp[h - 1][w - 1] << endl;
  }
  return 0;
}
