#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, x, ans = INT64_MIN;
    string s;
    cin >> n >> s;
    vector<ll> a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (s[i] == '1')
            a.push_back(x);
        else
            b.push_back(x);
    }
    ll N = a.size(), m = b.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (N == 0 || m == 0)
    {
        sort(a.begin(), a.end());
        cout << n << endl;
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        auto it = upper_bound(b.begin(), b.end(), a[i] - 1) - b.begin();
        ans = max(ans, N - i + it);
    }
    cout << ans << endl;
    return 0;
}
