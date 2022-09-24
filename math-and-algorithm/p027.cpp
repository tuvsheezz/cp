#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    vector<int> a(n);
    for (int i = 1; i <= n; i++)
        cin >> a[i - 1];
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++)
    {
        if (i > 1)
            cout << " ";
        cout << a[i - 1];
    }
    cout << endl;
    return 0;
}
