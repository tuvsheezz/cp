#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, r = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
        r *= (i + 1);

    cout << r << endl;
    return 0;
}
