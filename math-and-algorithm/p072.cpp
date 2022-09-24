#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll a, b, ans = 1;
    cin >> a >> b;
    for (ll i = a; i <= b; i++)
    {
        for (ll j = 1; j * j <= i; j++)
        {
            if (i % j == 0 && i + j <= b)
                ans = max(ans, j);
            if (i % j == 0 && i + i / j <= b)
                ans = max(ans, i / j);
        }
    }
    cout << ans << endl;
    return 0;
}
