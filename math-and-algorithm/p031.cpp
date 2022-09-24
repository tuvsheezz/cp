#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define v vector
using namespace std;

int main()
{
    ll n, q;
    cin >> n;
    v<pll> d(n + 1, make_pair(0LL, 0LL));

    for (int i = 0; i < n; i++)
    {
        cin >> q;
        d[i + 1].first = d[i].second + q;
        d[i + 1].second = max(d[i].first, d[i].second);
    }
    cout << max(d[n].first, d[n].second) << endl;
    return 0;
}
