#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int main()
{
    ll n, ans = 0;
    cin >> n;
    vector<ll> a(n + 1), b(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
        a[i + 1] = a[i] + b[i];
    }

    for (ll i = 0; i < n; i++)
        ans += a[n] - a[i + 1] - (n - i - 1) * b[i];

    cout << ans << endl;
    return 0;
}
