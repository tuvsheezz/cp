#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, c, x, ans = INT64_MAX;
    cin >> n >> c;
    vector C(c, vector<ll>(c)), a(n, vector<ll>(n));
    vector q(c, 0), w(c, 0), e(c, 0);

    for (int i = 0; i < c; i++)
        for (int j = 0; j < c; j++)
            cin >> C[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            if ((i + j) % 3 == 0)
                q[x - 1]++;
            if ((i + j) % 3 == 1)
                w[x - 1]++;
            if ((i + j) % 3 == 2)
                e[x - 1]++;
        }

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == j)
                continue;
            for (int k = 0; k < c; k++)
            {
                if (i == k || j == k)
                    continue;
                ll tmp = 0;

                for (int l = 0; l < c; l++)
                {
                    tmp += C[l][i] * q[l];
                    tmp += C[l][j] * w[l];
                    tmp += C[l][k] * e[l];
                }
                ans = min(ans, tmp);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
