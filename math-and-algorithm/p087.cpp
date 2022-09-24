#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
    ll n;
    cin >> n;
    ll a = (n + 1) * n / 2;
    a %= mod;
    cout << a * a % mod << endl;
    return 0;
}
