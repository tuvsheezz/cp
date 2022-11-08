#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k, cur = 0, ans = 0, j = 0;
    map<int, int> mp;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        while (cur <= k && j < n)
        {
            if (mp[a[j]] == 0 && cur == k)
                break;
            if (mp[a[j]] == 0)
                cur++;
            mp[a[j]]++;
            j++;
        }

        ans = max(ans, j - i);
        mp[a[i]]--;
        if (mp[a[i]] == 0)
            cur--;
    }
    cout << ans << endl;
    return 0;
}