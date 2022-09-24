#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n, k, sum = 0, q;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> q;
        sum += q;
    }

    if (sum <= k && (k - sum) % 2 == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
