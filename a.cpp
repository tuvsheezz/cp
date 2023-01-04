#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e6));
  for(int i = 0; i <= n; i++) dp[i][0] = i;
  for(int j = 0; j <= m; j++) dp[0][j] = j;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(s[i] == t[j]) {
        dp[i + 1][j + 1] = dp[i][j];
      } else {
        // insert
        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j + 1] + 1);

        // delete
        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i + 1][j] + 1);

        // substitution
        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 1);
      }
    }
  }
  cout << dp[n][m] << endl;
  return 0;
}
