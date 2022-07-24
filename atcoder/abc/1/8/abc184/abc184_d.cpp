#include <bits/stdc++.h>
using namespace std;
#define N 100
double dp[N + 10][N + 10][N + 10] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = N - 1; j >= 0; j--)
        {
            for (int k = N - 1; k >= 0; k--)
            {
                if (i + j + k == 0)
                    continue;
                dp[i][j][k] = (dp[i + 1][j][k] * i +
                               dp[i][j + 1][k] * j +
                               dp[i][j][k + 1] * k) /
                                  (i + j + k) +
                              1;
            }
        }
    }
    int a, b, c;
    cin >> a >> b >> c;
    cout << setprecision(20) << dp[a][b][c] << endl;
    return 0;
}
