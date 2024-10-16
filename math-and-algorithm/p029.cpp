#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] += dp[i - 1];
        if (i > 1)
            dp[i] += dp[i - 2];
    }
    cout << dp[n] << endl;
    return 0;
}
