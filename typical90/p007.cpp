#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, Q, x;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    cin >> Q;
    while (Q--)
    {
        cin >> x;
        auto it = lower_bound(a.begin(), a.end(), x);
        if (it == a.begin())
            cout << abs(x - *it) << endl;
        else if (it == a.end())
            cout << abs(x - *(--it)) << endl;
        else
        {
            auto it2 = it--;
            cout << min(abs(x - *it), abs(x - *it2)) << endl;
        }
    }
    return 0;
}
