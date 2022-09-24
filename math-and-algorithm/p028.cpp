#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), dp(n, INT32_MAX / 2);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        if (i - 1 >= 0)
            dp[i] = min(dp[i], dp[i - 1] + abs(a[i] - a[i - 1]));
        if (i - 2 >= 0)
            dp[i] = min(dp[i], dp[i - 2] + abs(a[i] - a[i - 2]));
    }
    cout << dp[n - 1] << endl;
    return 0;
}
