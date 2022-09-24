#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll h, w;
    cin >> h >> w;
    if (h == 1 || w == 1)
        cout << 1 << endl;
    else
        cout << ((h + 1) / 2) * ((w + 1) / 2) + (w / 2) * (h / 2) << endl;
    return 0;
}
