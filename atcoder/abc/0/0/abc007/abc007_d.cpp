#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long
using namespace std;

ll solve(ll x)
{
    if (x == 0)
        return 0;
    string a = to_string(x);
    ll n = a.size(), d[22][2][15] = {0};
    d[0][0][0] = 1;
    rep(dgt, n) rep(now, 10)
    {
        rep(nxt, 10)
        {
            if (nxt != 4 && nxt != 9)
                d[dgt + 1][1][nxt] += d[dgt][1][now];
        }
        ll q = a[dgt] - '0', tmp = 0;
        rep(nxt, 10) tmp += d[dgt][0][nxt];
        rep(nxt, q)
        {
            if (nxt != 4 && nxt != 9)
                d[dgt + 1][1][nxt] += d[dgt][0][now];
        }
        if (q != 4 && q != 9)
            d[dgt + 1][0][q] = tmp;
    }
    ll y = 0;
    rep(i, 10) y += d[n][0][i] + d[n][1][i];
    return x - y + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a, b;
    cin >> a >> b;
    cout << solve(b) - solve(a - 1) << endl;
    return 0;
}
