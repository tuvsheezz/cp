#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    int a[2020][2020], r[2020] = {0}, c[2020] = {0};
    cin >> h >> w;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            cin >> a[i][j];
            r[i] += a[i][j];
            c[j] += a[i][j];
        }
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cout << r[i] + c[j] - a[i][j] << (j == w - 1 ? "\n" : " ");
    return 0;
}
