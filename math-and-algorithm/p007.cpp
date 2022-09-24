#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    cout << n / x + n / y - n / (x * y / gcd(x, y)) << endl;
    return 0;
}
