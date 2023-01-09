#include <bits/stdc++.h>
using namespace std;

int main()
{
  double n;
  cin >> n;
  vector<double> p(n);
  for(int i = 0; i < n; i++) cin >> p[i];

  vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));
  dp[0][0] = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      dp[i + 1][j + 1] += dp[i][j] * p[i];
      dp[i + 1][j] += dp[i][j] * (1 - p[i]);
    }
  }
  cout << fixed << setprecision(10);
  double ans = 0;
  for(int i = n / 2 + 1; i <= n; i++) ans += dp[n][i];
  cout << ans << endl;
  return 0;
}
