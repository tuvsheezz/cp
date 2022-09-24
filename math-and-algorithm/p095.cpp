#include <bits/stdc++.h>
#define ll long long
#define rep(i, e) for (ll i = 0; i < e; i++)
using namespace std;
int main()
{
    ll n, x, y, ans = 0, Q;
    cin >> n;
    vector<vector<ll>> a(2, vector<ll>(n + 1, 0));

    rep(i, n)
    {
        cin >> x >> y;
        a[x - 1][i + 1] += y;
        a[0][i + 1] += a[0][i];
        a[1][i + 1] += a[1][i];
    }
    cin >> Q;
    while (Q--)
    {
        cin >> x >> y;
        cout << a[0][y] - a[0][x - 1] << " " << a[1][y] - a[1][x - 1] << endl;
    }
    return 0;
}
