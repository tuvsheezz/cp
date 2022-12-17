#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4000, x = 0;
    for (int i = 0; i < n; i++)
    {
        x += (n - i) / (i + 1);
    }
    cout << x;
    return 0;
}
