#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, x;
    cin >> n;
    vector<long long> a(4, 0);
    while (n--)
    {
        cin >> x;
        a[x]++;
    }

    cout << (a[1] * (a[1] - 1) + a[2] * (a[2] - 1) + a[3] * (a[3] - 1)) / 2 << endl;
    return 0;
}
