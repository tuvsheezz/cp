#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll k;
    cin >> k;
    if (k % 9 != 0)
        cout << 0 << endl;
    else
    {
        vector<ll> dp(k + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < k; i++)
            for (ll j = 0; j < 9; j++)
                if (i >= j)
                    dp[i + 1] = (dp[i + 1] + dp[i - j]) % mod;
        cout << dp[k] << endl;
    }
    return 0;
}