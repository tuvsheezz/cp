#include <bits/stdc++.h>
#define ll long long
#define all(c) c.begin(), c.end()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repa(i, e, n) for (ll i = e; i < n; i++)
#define mod 1000000007
using namespace std;

ll big_pow(ll a, ll b)
{
    ll d = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            d = d * a % mod;
        b /= 2;
        a = a * a % mod;
    }
    return d;
}
ll func(ll n)
{
    ll r = 0, p = 1, d = 1;
    while (p <= n)
    {
        ll x = min(p * 10 - 1, n) % mod;
        ll z = ((x - p % mod + mod + 1) * (x + p % mod + mod) % mod) % mod * big_pow(2, mod - 2) % mod;
        r = (r + z * d) % mod;
        p *= 10;
        d++;
    }
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll l, r;
    cin >> l >> r;
    cout << (func(r) - func(l - 1) + mod) % mod << endl;
    return 0;
}