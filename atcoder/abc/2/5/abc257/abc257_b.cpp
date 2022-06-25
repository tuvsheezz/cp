#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, q, x;
    cin >> n >> k >> q;
    vector<bool> a(n, false);
    vector<int> b(k);
    for (int i = 0; i < k; i++)
    {
        cin >> b[i];
        a[--b[i]] = true;
    }
    while (q--)
    {
        cin >> x;
        if (b[x - 1] == n - 1)
            continue;

        if (a[b[x - 1] + 1] == true)
            continue;
        a[b[x - 1] + 1] = true;
        a[b[x - 1]] = false;
        b[x - 1]++;
    }
    for (int i = 0; i < k; i++)
    {
        if (i > 0)
            cout << " ";
        cout << b[i] + 1;
    }
    cout << endl;
    return 0;
}
