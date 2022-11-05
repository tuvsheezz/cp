#include <bits/stdc++.h>
#define ll long long
#define all(c) c.begin(), c.end()
#define rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;

vector<ll> geeet(ll n)
{
    ll x;
    vector<ll> a(46);
    rep(i, n)
    {
        cin >> x;
        a[x % 46]++;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, ans = 0;
    cin >> n;
    vector<ll> a = geeet(n), b = geeet(n), c = geeet(n);
    rep(i, 46) rep(j, 46) rep(k, 46)
    {
        if ((i + j + k) % 46 == 0)
            ans += a[i] * b[j] * c[k];
    }
    cout << ans << endl;
    return 0;
}
