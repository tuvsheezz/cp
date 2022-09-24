#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n, ans = 0;
    cin >> n;
    vector<ll> a(n + 2, 0);
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            a[j]++;
    for (int i = 1; i <= n; i++)
        ans += i * a[i];
    cout << ans << endl;
    return 0;
}
