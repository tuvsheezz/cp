#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
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

int main()
{
    ll n;
    cin >> n;
    cout << big_pow(3, mod - 2) * (mod + big_pow(4, n + 1) - 1) % mod << '\n';
    return 0;
}
