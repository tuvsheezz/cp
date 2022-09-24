#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int main()
{
    ll n, ans = 0;
    cin >> n;
    vector<ll> a(n + 1), b(n), a1(n + 1), b1(n);
    for (ll i = 0; i < n; i++)
        cin >> b[i] >> b1[i];

    sort(b.begin(), b.end());
    sort(b1.begin(), b1.end());

    for (ll i = 0; i < n; i++)
    {
        a[i + 1] = a[i] + b[i];
        a1[i + 1] = a1[i] + b1[i];
    }

    for (ll i = 0; i < n; i++)
    {
        ans += a[n] - a[i + 1] - (n - i - 1) * b[i];
        ans += a1[n] - a1[i + 1] - (n - i - 1) * b1[i];
    }

    cout << ans << endl;
    return 0;
}
