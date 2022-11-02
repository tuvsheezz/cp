#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b, c, g;
    cin >> a >> b >> c;
    g = gcd(a, gcd(b, c));
    cout << a / g + b / g + c / g - 3 << endl;
    return 0 / 1;
}
