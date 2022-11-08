#include <bits/stdc++.h>
#define ll long long
using namespace std;

template <class T, class D>
struct imos2D
{
    vector<vector<T>> a;
    D h, w;

    void init(D hh, D ww)
    {
        h = hh;
        w = ww;
        a.resize(hh, vector<T>(ww, 0));
    }

    void add(D x1, D y1, D x2, D y2, T v)
    {
        a[x1][y1] += v;
        a[x2 + 1][y2 + 1] += v;
        a[x1][y2 + 1] -= v;
        a[x2 + 1][y1] -= v;
    }
    void calc()
    {
        // horizontal
        for (int y = 0; y < w; y++)
            for (int x = 0; x < h - 1; x++)
                a[x + 1][y] += a[x][y];

        // vertical
        for (int x = 0; x < h; x++)
            for (int y = 0; y < w - 1; y++)
                a[x][y + 1] += a[x][y];
    }

    T node_val(D x, D y) { return a[x][y]; }

    void check()
    {
        cout << h << " " << w << '\n';
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
                cout << a[i][j] << " ";
            cout << '\n';
        }
        cout << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, lx, ly, rx, ry, XMAX = 1010;
    cin >> n;
    vector<ll> ans(n + 1, 0);
    imos2D<ll, ll> imos2d;
    imos2d.init(XMAX, XMAX);
    for (int i = 0; i < n; i++)
    {
        cin >> lx >> ly >> rx >> ry;
        imos2d.add(lx, ly, rx - 1, ry - 1, 1);
    }
    imos2d.calc();
    for (int i = 0; i < XMAX; i++)
        for (int j = 0; j < XMAX; j++)
            ans[imos2d.node_val(i, j)]++;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';

    return 0;
}
