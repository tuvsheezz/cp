#include <bits/stdc++.h>
#define ll long long
#define dd double
#define rep(i, s, e) for (int i = s; i < e; i++)
using namespace std;

int main()
{
    ll n;
    cin >> n;
    vector<dd> a(n), b(n), c(n);
    rep(i, 0, n) cin >> a[i] >> b[i] >> c[i];

    dd ans = 0;
    rep(i, 0, n)
    {
        rep(j, i + 1, n)
        {
            dd fra = a[i] * b[j] - a[j] * b[i];
            if (fra == 0)
                continue;

            dd x = (b[j] * c[i] - b[i] * c[j]) / fra;
            dd y = (a[i] * c[j] - a[j] * c[i]) / fra;

            bool f = true;
            rep(k, 0, n)
            {
                if (a[k] * x + b[k] * y > c[k])
                    f = false;
            }

            if (f)
                ans = max(ans, x + y);
        }
    }
    cout << setprecision(15) << ans << endl;
    return 0;
}
