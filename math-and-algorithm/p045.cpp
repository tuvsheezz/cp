#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n, m, u, v, ans = 0;
    cin >> n >> m;
    vector<vector<ll>> g(n);

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    for (int i = 0; i < n; i++)
    {
        sort(g[i].begin(), g[i].end());
        if (g[i].size() == 1 && g[i][0] < i)
            ans++;
        if (g[i].size() > 1 && g[i][0] < i && g[i][1] > i)
            ans++;
    }

    cout << ans << '\n';
    return 0;
}
