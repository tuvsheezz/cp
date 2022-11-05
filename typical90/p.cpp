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
    ll n, sum = 0, cur = 0, j = 0;
    cin >> n;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
        sum += a[i];
    }

    rep(i, 2 * n)
    {
        j = max(i, j);
        while (j < 2 * n && cur * 10 < sum)
        {
            cur += a[j % n];
            j++;
        }
        if (cur * 10 == sum)
        {
            cout << "Yes" << endl;
            return 0;
        }
        cur = max(0LL, cur - a[i % 10]);
    }

    cout << "No" << endl;
    return 0;
}
