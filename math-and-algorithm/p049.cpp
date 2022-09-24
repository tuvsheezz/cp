#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    a[0] = a[1] = 1;
    for (int i = 2; i < n; i++)
        a[i] = (a[i - 1] + a[i - 2]) % mod;
    cout << a[n - 1] << '\n';
    return 0;
}
