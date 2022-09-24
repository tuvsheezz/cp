#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, r, ans = 1;
    cin >> n >> r;
    for (long long i = 1; i <= n; i++)
        ans *= i;
    for (long long i = 1; i <= r; i++)
        ans /= i;
    for (long long i = 1; i <= (n - r); i++)
        ans /= i;

    cout << ans << endl;
    return 0;
}
