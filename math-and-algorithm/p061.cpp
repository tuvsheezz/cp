#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, c = 1;
    cin >> n;

    for (int i = 0; i < 60; i++)
    {
        if (n == c - 1)
        {
            cout << "Second\n";
            return 0;
        }
        c += c;
    }

    cout << "First\n";
    return 0;
}
