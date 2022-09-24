#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n, m, now, ans = 0, q;
    cin >> n;
    vector<ll> a(n, 0);
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    cin >> m >> now;
    m--;
    while (m--)
    {
        cin >> q;
        ans += abs(a[q - 1] - a[now - 1]);
        now = q;
    }

    cout << ans << '\n';
    return 0;
}
