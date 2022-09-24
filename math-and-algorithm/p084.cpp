#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int main()
{
    ll a, b, c;
    cin >> a >> b >> c;

    if (c > a + b && (c - a - b) * (c - a - b) > 4 * a * b)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
