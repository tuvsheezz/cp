#include <bits/stdc++.h>
#define ll long long
#define rep(i, e) for (ll i = 0; i < e; i++)
using namespace std;
int main()
{
    ll n, ans = 0;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    rep(i, n) ans += abs(a[i] - b[i]);
    cout << ans << endl;
    return 0;
}
