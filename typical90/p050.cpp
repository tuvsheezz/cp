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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1, 0);
    a[0] = 1;
    rep(i, n) a[i + 1] = (a[i] + (i + 1 >= k ? a[i - k + 1] : 0)) % mod;
    cout << a[n] << '\n';
    return 0;
}
