#include <bits/stdc++.h>
#define ll long long
#define all(c) c.begin(), c.end()
#define rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, Q, T, x, y;
    deque<ll> dq;
    cin >> n >> Q;
    rep(i, n)
    {
        cin >> x;
        dq.push_back(x);
    }

    while (Q--)
    {
        cin >> T >> x >> y;
        if (T == 1)
            swap(dq[x - 1], dq[y - 1]);
        else if (T == 2)
        {
            x = dq.back();
            dq.pop_back();
            dq.push_front(x);
        }
        else
            cout << dq[x - 1] << '\n';
    }
    return 0;
}
