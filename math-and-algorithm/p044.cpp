#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n, m, u, v;
    cin >> n >> m;
    vector<ll> dist(n, INT64_MAX);
    dist[0] = 0;
    vector<vector<ll>> g(n);
    vector<bool> vis(n, false);

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    queue<ll> next;
    next.push(0);
    while (!next.empty())
    {
        ll cur = next.front();
        next.pop();
        vis[cur] = true;
        for (auto &x : g[cur])
        {
            if (!vis[x])
                next.push(x);
            dist[x] = min(dist[cur] + 1, dist[x]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INT64_MAX)
            cout << -1 << '\n';
        else
            cout << dist[i] << '\n';
    }
    return 0;
}
