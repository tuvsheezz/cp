// https://atcoder.jp/contests/typical90/tasks/typical90_a
#include <bits/stdc++.h>
#define ll long long
#define all(c) c.begin(), c.end()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repa(i, e, n) for (ll i = e; i < n; i++)
#define mod 1000000007
using namespace std;

int main()
{
    ll n, l, k;
    cin >> n >> l >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    a.push_back(l);

    ll now = 0;
    rep(i, n + 1)
    {
        ll tmp = a[i];
        a[i] -= now;
        now = tmp;
    }
    n++;

    ll le = 0, r = 1e17;
    while (le + 1 < r)
    {
        ll m = le + (r - le) / 2, count = 0, sum = 0;

        rep(i, n)
        {
            sum += a[i];
            if (sum >= m)
            {
                sum = 0;
                count++;
            }
        }
        if (count < k + 1)
            r = m;
        else
            le = m;
    }
    cout << le << endl;
    return 0;
}