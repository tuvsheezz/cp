#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << '\n';
            if (i * i != n)
                cout << n / i << '\n';
        }
    }
    return 0;
}
