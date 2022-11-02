#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, c, s;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n, 0)), b(2, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> c >> s;
        a[c - 1][i] = s;
    }
    for (int i = 0; i < n; i++)
    {
        b[0][i + 1] = b[0][i] + a[0][i];
        b[1][i + 1] = b[1][i] + a[1][i];
    }
    int Q, l, r;
    cin >> Q;
    while (Q--)
    {
        cin >> l >> r;
        cout << b[0][r] - b[0][l - 1] << " " << b[1][r] - b[1][l - 1] << endl;
    }
    return 0;
}
