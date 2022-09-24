#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n, ans = 1e13;
    cin >> n;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
            ans = min(ans, 2 * (i + n / i));
    }
    cout << ans << endl;
    return 0;
}
