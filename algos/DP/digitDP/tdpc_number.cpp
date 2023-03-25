#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main()
{
  long long d;
  string s;
  cin >> d >> s;
  long long n = s.size();

  vector<vector<vector<long long>>>
      dp(n + 1, vector<vector<long long>>(2, vector<long long>(d, 0)));

  dp[0][0][0] = 1;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < d; j++)
    {
      // i桁目まででNより小さいならi+1桁目は何でも良い
      for (int k = 0; k < 10; k++)
        dp[i + 1][1][(j + k) % d] = (dp[i + 1][1][(j + k) % d] + dp[i][1][j]) % mod;

      int dig = (s[i] - '0');

      // i桁目までNと同じで、i+1桁目はNより小さい数の時
      for (int k = 0; k < dig; k++)
        dp[i + 1][1][(j + k) % d] = (dp[i + 1][1][(j + k) % d] + dp[i][0][j]) % mod;

      //  i桁目までNと同じで、i+1桁目もNと同じ数の時
      dp[i + 1][0][(j + dig) % d] = dp[i][0][j];
    }
  }
  cout << dp[n][0][0] + dp[n][1][0] - 1 << endl;
  return 0;
}

// https://atcoder.jp/contests/tdpc/tasks/tdpc_number