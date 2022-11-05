#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    long long g = gcd(a, b);
    if (a / g > 1000000000000000000 / b)
        cout << "Large\n";
    else
        cout << (a / g) * b << '\n';
    return 0;
}
