#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s, x;
    cin >> n >> s;
    vector<bool> dp(s + 1);
    dp[0] = true;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        for (int i = s; i >= 0; i--)
        {
            if (i >= x && dp[i - x])
                dp[i] = true;
        }
    }

    cout << (dp[s] ? "Yes" : "No") << endl;
    return 0;
}
