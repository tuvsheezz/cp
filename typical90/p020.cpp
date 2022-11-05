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
    ll a, b, c, q = 1;
    cin >> a >> b >> c;
    while (b--)
        q *= c;
    cout << (a >= q ? "No" : "Yes") << endl;
    return 0;
}
