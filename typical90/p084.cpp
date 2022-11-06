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
    ll x = -1, o = -1, n, ans = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        (s[i] == 'o') ? o = i : x = i;
        if (x != -1 && o != -1)
            ans += (i + 1) - abs(x - o);
    }
    cout << ans << endl;
    return 0;
}