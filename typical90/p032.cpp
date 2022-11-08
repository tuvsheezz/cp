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
    ll n, m;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n, 0)), b(n, vector<ll>(n, 0));
    rep(i, n) rep(j, n) cin >> a[i][j];
    cin >> m;
    rep(i, m)
    {
        ll x, y;
        cin >> x >> y;
        b[x - 1][y - 1] = 1;
        b[y - 1][x - 1] = 1;
    }

    vector<ll> x(n);
    rep(i, n) x[i] = i + 1;
    ll ans = 1e18;

    do
    {
        ll c = 0;

        rep(i, n)
        {
            c += a[x[i] - 1][i];
            if (i < n - 1 && b[x[i] - 1][x[i + 1] - 1] == 1)
            {
                c = 1e18;
                break;
            }
        }
        ans = min(c, ans);
    } while (next_permutation(x.begin(), x.end()));

    cout << ((ans == 1e18) ? -1 : ans) << endl;
    return 0;
}
