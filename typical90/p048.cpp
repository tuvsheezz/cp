#include <bits/stdc++.h>
#define ll long long
#define all(c) c.begin(), c.end()
#define rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, k, ans = 0, x, y;
    cin >> n >> k;
    vector<int> a;
    rep(i, n)
    {
        cin >> x >> y;
        a.push_back(y);
        a.push_back(x - y);
    }
    sort(a.begin(), a.end(), greater<int>());
    rep(i, k) ans += a[i];
    cout << ans << '\n';
    return 0;
}
