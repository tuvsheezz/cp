#include <bits/stdc++.h>
#define ll long long
#define rep(i, e) for (ll i = 0; i < e; i++)
using namespace std;
int main()
{
    ll n, sum = 0;
    cin >> n;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
        sum += a[i];
    }

    vector<vector<ll>> d(n + 1, vector<ll>(sum + 1, 0));
    d[0][0] = true;

    rep(i, n) rep(j, sum + 1)
    {
        if (j + a[i] <= sum && d[i][j] > 0)
            d[i + 1][j + a[i]] = 1;

        d[i + 1][j] += d[i][j];
    }

    ll ans = sum;

    rep(i, sum + 1)
    {
        if (d[n][i] > 0)
            ans = min(ans, max(i, sum - i));
    }
    cout << ans << endl;
    return 0;
}
