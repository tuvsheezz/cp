#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, X, Y, a, b, x, y, ans = INT_MAX;
  cin >> n >> X >> Y;
  vector<vector<int>> dp(301, vector<int>(301, INT_MAX - 1));
  dp[0][0] = 0;
  while (n--)
  {
    cin >> a >> b;
    for (int i = 300; i >= 0; i--)
      for (int j = 300; j >= 0; j--)
      {
        x = min(300, i + a);
        y = min(300, j + b);
        dp[x][y] = min(dp[x][y], dp[i][j] + 1);
      }
  }

  for (int i = X; i < 301; i++)
    for (int j = Y; j < 301; j++)
      ans = min(ans, dp[i][j]);

  cout << ((ans != INT_MAX - 1) ? ans : -1) << endl;
  return 0;
}
