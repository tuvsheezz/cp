#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, sum = 0;
    cin >> n;
    while (n--)
    {
        cin >> x;
        sum += x;
    }
    cout << sum % 100 << endl;
    return 0;
}
