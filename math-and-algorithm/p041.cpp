#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n, Q, l, r;
    cin >> n >> Q;
    vector<ll> a(n + 2, 0);
    while (Q--)
    {
        cin >> l >> r;
        a[l + 1] += 1;
        a[r + 1] -= 1;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
        cout << a[i] << '\n';
    }

    return 0;
}
