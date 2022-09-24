#include <bits/stdc++.h>
#define ll long long
#define rep(i, e) for (ll i = 0; i < e; i++)
using namespace std;
int main()
{
    ll n, x, ans = 0;
    cin >> n;
    vector<ll> a(n, INT32_MAX);

    rep(i, n - 1)
    {
        cin >> x;
        a[i] = min(a[i], x);
        a[i + 1] = min(a[i + 1], x);
        ans += a[i];
    }
    cout << ans + a[n - 1] << endl;
    return 0;
}
