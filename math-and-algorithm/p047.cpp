#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n, m, u, v, ans = 0;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    vector<ll> q(n, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    queue<ll> next;
    for (int i = 0; i < n; i++)
    {
        if (q[i] != 0)
            continue;

        q[i] = -1;
        next.push(i);
        while (!next.empty())
        {
            ll cur = next.front();
            next.pop();
            for (auto &x : g[cur])
            {
                if (q[x] == 0)
                {
                    next.push(x);
                    q[x] = -q[cur];
                }
                else if (q[x] == q[cur])
                {
                    cout << "No\n";
                    return 0;
                }
            }
        }
    }

    cout << "Yes\n";
    return 0;
}
