#include <bits/stdc++.h>
#define ll long long
#define all(c) c.begin(), c.end()
#define rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a, b, c, n, ans = INT64_MAX;
    cin >> n >> a >> b >> c;

    for (ll i = 0; i < 10000; i++)
    {
        if (i * a > n)
            break;
        for (ll j = 0; j < 10000; j++)
        {
            ll tmp = i * a + j * b;
            if (i + j >= 10000 || tmp > n)
                break;

            if ((n - tmp) % c == 0)
                ans = min(ans, i + j + (n - tmp) / c);
        }
    }
    cout << ans << endl;
    return 0;
}
