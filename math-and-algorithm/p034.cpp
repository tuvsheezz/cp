#include <bits/stdc++.h>
#define dd double
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<dd> a(n), b(n);
    dd ans = INT64_MAX;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            ans = min(ans, sqrt((a[i] - a[j]) * (a[i] - a[j]) + (b[i] - b[j]) * (b[i] - b[j])));
    cout << setprecision(30) << ans << endl;
    return 0;
}
