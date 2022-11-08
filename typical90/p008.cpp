#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(10, 0);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            a[0]++;
        if (s[i] == 't')
            a[1] = (a[1] + a[0]) % mod;
        if (s[i] == 'c')
            a[2] = (a[2] + a[1]) % mod;
        if (s[i] == 'o')
            a[3] = (a[3] + a[2]) % mod;
        if (s[i] == 'd')
            a[4] = (a[4] + a[3]) % mod;
        if (s[i] == 'e')
            a[5] = (a[5] + a[4]) % mod;
        if (s[i] == 'r')
            a[6] = (a[6] + a[5]) % mod;
    }
    cout << a[6] << endl;
    return 0;
}
