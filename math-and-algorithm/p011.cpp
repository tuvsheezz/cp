#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<bool> p(n + 1, true);
    p[0] = false;
    p[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (!p[i])
            continue;
        for (int j = i * i; j <= n; j += i)
        {
            p[j] = false;
        }
    }
    cout << 2;
    for (int i = 3; i <= n; i++)
    {
        if (!p[i])
            continue;
        cout << " " << i;
    }
    cout << endl;

    return 0;
}
