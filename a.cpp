#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, D;
  cin >> D >> N;
  vector<int> T(D);
  vector<int> A(N), B(N), C(N);
  vector<vector<int>> dp(D, vector<int>(N, 0));
  for(int i = 0; i < D; i++) cin >> T[i];
  for(int i = 0; i < N; i++) cin >> A[i] >> B[i] >> C[i];

  for(int i = 0; i < N; i++) {
    if(A[i] > T[0] || T[0] > B[i]) dp[0][i] = -1;
  }

  for(int day = 1; day < D; day++) {
    for(int i = 0; i < N; i++) {
      if(A[i] > T[day] || T[day] > B[i])
        dp[day][i] = -1;
      else {
        for(int j = 0; j < N; j++) {
          if(dp[day - 1][j] == -1) continue;
          dp[day][i] = max(dp[day][i], dp[day - 1][j] + abs(C[i] - C[j]));
        }
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < N; i++) ans = max(ans, dp[D - 1][i]);
  cout << ans << endl;
  return 0;
}
