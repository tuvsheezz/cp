#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, x = 0, y;
    cin >> n;
    while (n--)
    {
        cin >> y;
        x = gcd(x, y);
    }
    cout << x << endl;
    return 0;
}
