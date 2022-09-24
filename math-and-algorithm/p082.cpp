#include <bits/stdc++.h>
#define ll long long
#define rep(i, e) for (int i = 0; i < e; i++)
using namespace std;

int main()
{
    ll n, cur = 0, ans = 0;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    rep(i, n)
    {
        ll s, e;
        cin >> s >> e;
        a[i] = {s, e};
    }
    sort(a.begin(), a.end());
    rep(i, n)
    {
        if (a[i].first >= cur)
        {
            cur = a[i].second;
            ans++;
        }
        else if (cur > a[i].second)
            cur = a[i].second;
    }
    cout << ans << endl;
    return 0;
}
