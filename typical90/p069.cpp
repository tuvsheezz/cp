#include <bits/stdc++.h>
#define ll long long
#define all(c) c.begin(), c.end()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repa(i, e, n) for (ll i = e; i < n; i++)
#define mod 1000000007
using namespace std;

ll big_pow(ll a, ll b, ll m)
{
    ll d = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            d = d * a % m;
        b /= 2;
        a = a * a % m;
    }
    return d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, k;
    cin >> n >> k;
    k %= mod;

    ll ans = k * (k - 1) % mod;
    ans = (ans * big_pow(k - 2, n - 2, mod)) % mod;

    cout << ans << endl;
    return 0;
}
