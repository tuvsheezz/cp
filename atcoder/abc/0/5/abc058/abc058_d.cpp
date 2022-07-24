#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int main()
{
    ll n, m, X = 0, Y = 0;
    cin >> n >> m;
    vector<ll> a(n), b(m), c(n), d(m);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    for (int i = 1; i < n; i++)
    {
        c[i] = a[i] - a[i - 1];
        c[i] = (c[i] * i % mod + c[i - 1]) % mod;
        X = (X + c[i]) % mod;
    }
    for (int i = 1; i < m; i++)
    {
        d[i] = b[i] - b[i - 1];
        d[i] = (d[i] * i % mod + d[i - 1]) % mod;
        Y = (Y + d[i]) % mod;
    }
    cout << X * Y % mod << endl;
    return 0;
}
