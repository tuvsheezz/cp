#include <bits/stdc++.h>
#define ll long long
#define pll pair<long long, long long>
using namespace std;
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<pll>> adj(n);
    vector<int> d(n, INT32_MAX);
    d[0] = 0;

    while (m--)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        adj[u - 1].push_back({v - 1, c});
        adj[v - 1].push_back({u - 1, c});
    }
    priority_queue<pll, vector<pll>, greater<pll>> next_to_visit;
    next_to_visit.push({0, 0});

    while (!next_to_visit.empty())
    {
        pll current_node = next_to_visit.top();
        next_to_visit.pop();
        ll v = current_node.second;

        if (d[v] < current_node.first)
            continue;

        for (auto &x : adj[v])
        {
            if (d[x.first] > d[v] + x.second)
            {
                d[x.first] = d[v] + x.second;
                next_to_visit.push({d[x.first], x.first});
            }
        }
    }

    if (d[n - 1] < INT32_MAX)
        cout << d[n - 1] << endl;
    else
        cout << -1 << endl;
    return 0;
}