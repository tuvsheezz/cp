#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n, ans = 0;
    cin >> n;
    n /= 1000;
    ans += n / 10;
    n %= 10;
    ans += n / 5 + n % 5;
    cout << ans << endl;
    return 0;
}
