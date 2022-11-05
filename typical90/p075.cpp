#include <bits/stdc++.h>
#define ll long long
#define all(c) c.begin(), c.end()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repa(i, e, n) for (ll i = e; i < n; i++)
#define mod 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, ans = 0, c = 0;
    cin >> n;

    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            c++;
            n /= i;
        }
    }
    if (n > 1)
        c++;

    while (c > 1)
    {
        ans++;
        c = (c + 1) / 2;
    }

    cout << ans << endl;
    return 0;
}
