#include <bits/stdc++.h>
using namespace std;

struct UnionFind
{
    vector<long long> parent, size;
    long long size_max = 0, count;

    UnionFind(long long n)
    {
        parent.resize(n, -1);
        size.resize(n, 1);
        count = n;
        size_max = 1;
    }

    long long root(long long x) { return parent[x] == -1 ? x : parent[x] = root(parent[x]); }
    bool same(long long x, long long y) { return root(x) == root(y); }
    void unite(long long x, long long y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return;

        if (size[x] < size[y])
            swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        size_max = max(size[x], size_max);
        count--;
    }
    long long count_of_sets() { return count; }
    long long get_union_size(long long x) { return size[root(x)]; }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long h, w, Q, com, ra, rb, ca, cb;
    cin >> h >> w >> Q;
    UnionFind uf(h * w);
    vector<long long> color(h * w, 0);
    vector<pair<long long, long long>> move = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    while (Q--)
    {
        cin >> com;
        if (com == 1)
        {
            cin >> ra >> ca;
            ra--, ca--;
            color[ra * w + ca] = 1;
            for (auto &mo : move)
            {
                if (0 <= ra + mo.first && ra + mo.first < h && 0 <= ca + mo.second && ca + mo.second < w && color[(ra + mo.first) * w + ca + mo.second] == 1)
                    uf.unite(ra * w + ca, (ra + mo.first) * w + ca + mo.second);
            }
        }
        else
        {
            cin >> ra >> ca >> rb >> cb;
            ra--, ca--, rb--, cb--;
            if (color[ra * w + ca] == 1 && color[rb * w + cb] && uf.same(ra * w + ca, rb * w + cb))
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}
