#include <bits/stdc++.h>
#define ll long long
#define all(c) c.begin(), c.end()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repa(i, e, n) for (ll i = e; i < n; i++)
#define mod 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll h, w, ans = 0;
    cin >> h >> w;
    vector<vector<ll>> a(h, vector<ll>(w, 0)), b(h, vector<ll>(w, 0));

    rep(i, h) rep(j, w) cin >> a[i][j];
    rep(i, h) rep(j, w) cin >> b[i][j];

    rep(i, h - 1) rep(j, w - 1)
    {
        ll df = b[i][j] - a[i][j];
        ans += abs(df);
        rep(k, 2) rep(l, 2) a[i + k][j + l] += df;
    }
    rep(i, h) rep(j, w)
    {
        if (a[i][j] != b[i][j])
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    cout << ans << endl;
    return 0;
}
