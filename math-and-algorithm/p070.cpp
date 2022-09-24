#include <bits/stdc++.h>
#define ll long long
#define rep(i, e) for (ll i = 0; i < e; i++)
using namespace std;
int main()
{
    ll n, k, x1 = -1e15, x2 = 1e15, y1 = -1e15, y2 = 1e15, ans = 0;
    cin >> n >> k;
    vector<ll> X(n), Y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i] >> Y[i];
        x1 = max(x1, X[i]);
        x2 = min(x2, X[i]);
        y1 = max(y1, Y[i]);
        y2 = min(y2, Y[i]);
    }

    ans = (x1 - x2) * (y1 - y2);

    rep(t, n) rep(b, n) rep(l, n) rep(r, n)
    {
        ll c = 0;
        rep(i, n)
        {
            if (X[b] <= X[i] && X[i] <= X[t] && Y[l] <= Y[i] && Y[i] <= Y[r])
                c++;
        }
        if (c >= k)
            ans = min(ans, (X[t] - X[b]) * (Y[r] - Y[l]));
    }

    cout << ans << endl;
    return 0;
}
