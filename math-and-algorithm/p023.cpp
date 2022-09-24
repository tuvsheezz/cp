#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    double s = 0, q;
    cin >> n;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> q;
        s += q;
    }
    cout << setprecision(10) << s / n << endl;
    return 0;
}
