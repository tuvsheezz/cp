#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
      if(s[i] == t[j]) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
    }
  }
  string ans = "";
  while(n > 0 && m > 0) {
    if(dp[n][m] == dp[n - 1][m]) n--;
    else if(dp[n][m] == dp[n][m - 1]) m--;
    else {
      ans = s[n - 1] + ans;
      n--;
      m--;
    }
  }
  cout << ans << endl;
  return 0;
}
