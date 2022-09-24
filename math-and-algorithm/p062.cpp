#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n, k, now, pre = 0;
    cin >> n >> k;
    vector<ll> a(n), b;
    vector<bool> vis(n + 1, false);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    now = a[0];

    while (!vis[now])
    {
        b.push_back(now);
        vis[now] = true;
        now = a[now - 1];
    }

    for (auto &x : b)
    {
        if (x == now)
            break;
        pre++;
    }
    if (k < pre)
        cout << b[k - 1] << endl;
    else
    {
        k -= pre;
        ll x = (b.size() - pre);
        k = (k % x - 1 + x) % x;
        cout << b[pre + k] << endl;
    }
    return 0;
}
