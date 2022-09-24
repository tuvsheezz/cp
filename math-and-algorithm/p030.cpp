#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n, W, w, v, ans = 0;
    cin >> n >> W;
    vector<vector<ll>> d(n + 1, vector<ll>(W + 1, 0));

    for (int i = 0; i < n; i++)
    {
        cin >> w >> v;
        for (int j = 0; j <= W; j++)
        {
            if (j - w >= 0)
                d[i + 1][j] = max(d[i][j], d[i][j - w] + v);
            else
                d[i + 1][j] = d[i][j];
        }
    }
    for (int i = 0; i <= W; i++)
        ans = max(ans, d[n][i]);
    cout << ans << endl;
    return 0;
}
