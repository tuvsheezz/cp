#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n, Q, l, r;
    cin >> n >> Q;
    vector<ll> a(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i + 1];
        a[i + 1] += a[i];
    }
    while (Q--)
    {
        cin >> l >> r;
        cout << a[r] - a[l - 1] << '\n';
    }
    return 0;
}
