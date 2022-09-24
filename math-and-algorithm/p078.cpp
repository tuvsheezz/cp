#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n);
    vector<int> d(n, 120);
    vector<bool> vis(n, false);
    d[0] = 0;

    while (m--)
    {
        ll u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    queue<ll> nxt;
    nxt.push(0);

    while (!nxt.empty())
    {
        ll u = nxt.front();
        nxt.pop();
        if (vis[u])
            continue;

        vis[u] = true;
        for (auto &v : adj[u])
        {
            d[v] = min(d[v], d[u] + 1);
            nxt.push(v);
        }
    }

    for (ll i = 0; i < n; i++)
        cout << d[i] << endl;
    return 0;
}