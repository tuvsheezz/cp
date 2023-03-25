#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main()
{
  string s;
  cin >> s;

  long long n = s.size();
  vector<vector<vector<long long>>>
      dp(11, vector<vector<long long>>(2, vector<long long>(11, 0)));

  dp[0][0][0] = 1;

  for (int i = 0; i < n; i++)
  {
    int dig = (s[i] - '0');
    for (int j = 0; j < 10; j++)
    {
      // i桁目まででNより小さいならi+1桁目は何でも良い
      dp[i + 1][1][j] += dp[i][1][j] * 9;
      dp[i + 1][1][j + 1] += dp[i][1][j];

      // i桁目までNと同じで、i+1桁目はNより小さい数の時
      if (dig > 1)
      {
        dp[i + 1][1][j] += dp[i][0][j] * (dig - 1);
        dp[i + 1][1][j + 1] += dp[i][0][j];
      }
      else if (dig == 1)
        dp[i + 1][1][j] += dp[i][0][j];

      //  i桁目までNと同じで、i+1桁目もNと同じ数の時
      if (dig == 1)
        dp[i + 1][0][j + 1] = dp[i][0][j];
      else
        dp[i + 1][0][j] = dp[i][0][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < 10; i++)
    ans += i * (dp[n][1][i] + dp[n][0][i]);

  cout << ans << endl;
  return 0;
}

// https://atcoder.jp/contests/abc029/tasks/abc029_d