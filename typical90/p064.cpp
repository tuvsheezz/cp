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
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n + 1, 0), b(n + 1, 0);
    ll total = 0, tmp;
    rep(i, n) { cin >> a[i + 1]; }
    repa(i, 1, n)
    {
        total += abs(a[i] - a[i + 1]);
        b[i] = a[i + 1] - a[i];
    }

    while (q--)
    {
        ll l, r, v;
        cin >> l >> r >> v;

        tmp = -abs(b[l - 1]) - abs(b[r]);
        if (l > 1)
            b[l - 1] += v;

        if (r < n)
            b[r] -= v;

        tmp += abs(b[l - 1]) + abs(b[r]);
        total += tmp;
        cout << total << '\n';
    }
    return 0;
}
