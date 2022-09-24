#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll h, w;
    cin >> h >> w;
    vector<vector<ll>> g(h, vector<ll>(w));
    vector<ll> a(h), b(w);
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            cin >> g[i][j];
            a[i] += g[i][j];
            b[j] += g[i][j];
        }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (j > 0)
                cout << ' ';
            cout << a[i] + b[j] - g[i][j];
        }
        cout << '\n';
    }
    return 0;
}
