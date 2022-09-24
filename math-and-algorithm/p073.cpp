#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int main()
{
    ll n, x, p = 1, ans = 0;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> x;
        ans = (ans + (x * p) % mod) % mod;
        p = (p * 2) % mod;
    }
    cout << ans << endl;
    return 0;
}
