#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n, Q, l, r, x;
    cin >> n >> Q;
    vector<ll> a(n + 2, 0);
    while (Q--)
    {
        cin >> l >> r >> x;
        a[l] += x;
        a[r + 1] -= x;
    }
    for (int i = 1; i < n + 2; i++)
        a[i] += a[i - 1];

    for (int i = 2; i <= n; i++)
    {
        if (a[i] == a[i - 1])
            cout << '=';
        else if (a[i] > a[i - 1])
            cout << '<';
        else
            cout << '>';
    }
    cout << '\n';
    return 0;
}
