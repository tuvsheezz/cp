#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct UnionFind
{
    vector<ll> parent, size;
    ll count;

    void init(ll n)
    {
        parent.resize(n, -1);
        size.resize(n, 1);
        count = n;
    }
    ll root(ll x) { return parent[x] == -1 ? x : parent[x] = root(parent[x]); }
    bool same(ll x, ll y) { return root(x) == root(y); }
    void unite(ll x, ll y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return;

        if (size[x] < size[y])
            swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        count--;
    }
};

int main()
{
    ll n, m, u, v;
    cin >> n >> m;
    UnionFind uf;
    uf.init(n);
    while (m--)
    {
        cin >> u >> v;
        uf.unite(u - 1, v - 1);
    }
    if (uf.count == 1)
        cout << "The graph is connected." << '\n';
    else
        cout << "The graph is not connected." << '\n';
    return 0;
}
