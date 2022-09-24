#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    ll n, k, ans = 0;
    cin >> n >> k;
    vector<ll> a(k);
    for (int i = 0; i < k; i++)
        cin >> a[i];

    for (ll bit = 1; bit < (1 << k); bit++)
    {
        ll p = 0;
        for (int i = 0; i < k; i++)
            if ((bit >> i) & 1)
                p = (p == 0) ? a[i] : p / gcd(p, a[i]) * a[i];
        if (__builtin_popcount(bit) % 2 == 1)
            ans += n / p;
        else
            ans -= n / p;
    }
    cout << ans << endl;
    return 0;
}
