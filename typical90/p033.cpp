#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    if (h == 1 || w == 1)
        cout << h * w << endl;
    else
        cout << (h + 1) / 2 * ((w + 1) / 2) << endl;
    return 0;
}
