#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, x, y;
    cin >> n >> x >> y;
    if (n - abs(x) - abs(y) >= 0 && (n + x + y) % 2 == 0)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
