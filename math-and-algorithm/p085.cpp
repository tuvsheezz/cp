#include <bits/stdc++.h>
#define ll long long
#define rep(i, e) for (ll i = 0; i <= e; i++)
using namespace std;
int main()
{
    ll n, x, y;
    cin >> n >> x >> y;

    rep(i, n) rep(j, n) rep(k, n) rep(l, n)
    {
        if (i + j + k + l == x && i * j * k * l == y)
        {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
    return 0;
}
