#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, x = 1, y;
    cin >> n;
    while (n--)
    {
        cin >> y;
        x = lcm(x, y);
    }
    cout << x << endl;
    return 0;
}
