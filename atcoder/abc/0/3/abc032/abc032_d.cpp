#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;

int n;
ll W;
ll v[220], w[220];
 
void solve1() {
    vector<P> lv;
    int ln = n/2, rn = n - n/2;
    for (int i = 0; i < (1<<ln); i++) {
        ll vs = 0, ws = 0;
        for (int j = 0; j < ln; j++) {
            if (i & (1<<j)) {
                vs += v[j];
                ws += w[j];
            }
        }
        lv.push_back({ws, vs});
    }
    sort(lv.begin(), lv.end());
    int vs = (int)lv.size();
    for (int i = 1; i < vs; i++) {
        lv[i].second = max(lv[i].second, lv[i-1].second);
    }
    ll res = 0;
    for (int i = 0; i < (1<<rn); i++) {
        ll vs = 0, ws = 0;
        for (int j = 0; j < rn; j++) {
            if (i & (1<<j)) {
                vs += v[j+ln];
                ws += w[j+ln];
            }
        }
        if (W < ws) continue;
        res = max(res, vs + (--lower_bound(lv.begin(), lv.end(), P(W-ws, 1e18)))->second);
    }
    cout << res << endl;
}
 
void solve2() {
    const int MW = 200*1010;
    static ll dp[MW];
    for (int i = 0; i < n; i++) {
        for (int j = W; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
    }
    ll res = 0;
    for (int i = 0; i <= W; i++) {
        res = max(res, dp[i]);
    }
    cout << res << endl;
}
 
void solve3() {
    const int MV = 200*1010;
    static ll dp[MV];
    fill_n(dp, MV, 1LL<<55);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = MV-1; j >= v[i]; j--) {
            dp[j] = min(dp[j], dp[j-v[i]] + w[i]);
        }
    }
    ll res = 0;
    for (int i = MV-1; i >= 0; i--) {
        if (dp[i] <= W) {
            cout << i << endl;
            return; 
        }
    }
}
 
int main() {
    cin >> n >> W;
    ll vmax = -1, wmax = -1;
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> w[i];
        vmax = max(vmax, v[i]);
        wmax = max(wmax, w[i]);
    }
    if (n <= 30) solve1();
    else if (wmax <= 1000) solve2();
    else if (vmax <= 1000) solve3();
    return 0;
}