#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, x;
    cin >> n;
    vector<long long> a(5, 0);
    while (n--)
    {
        cin >> x;
        a[x / 100]++;
    }

    cout << a[1] * a[4] + a[2] * a[3] << endl;
    return 0;
}
