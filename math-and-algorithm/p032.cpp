#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, w, q;
    cin >> n >> w;

    for (int i = 0; i < n; i++)
    {
        cin >> q;
        if (q == w)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
