#include <bits/stdc++.h>
#define ll long long
#define all(c) c.begin(), c.end()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define mod 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, x, ans = 1;
    cin >> n;
    rep(i, n)
    {
        ll q = 0;
        rep(j, 6)
        {
            cin >> x;
            q += x;
        }
        ans = (ans * q) % mod;
    }
    cout << ans << '\n';
    return 0;
}
