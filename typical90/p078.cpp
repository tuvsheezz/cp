#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, u, v;
    cin >> n >> m;
    vector<int> g(n, 0);
    while (m--)
    {
        cin >> u >> v;
        if (u > v)
            g[u - 1]++;
        if (u < v)
            g[v - 1]++;
    }
    int ans = 0;
    for (auto &x : g)
        if (x == 1)
            ans++;
    cout << ans << endl;
    return 0;
}
