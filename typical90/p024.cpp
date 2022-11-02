#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, tmp;
    cin >> n >> k;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a[i] -= tmp;
        k -= abs(a[i]);
    }
    if (k >= 0 && k % 2 == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
