#include <bits/stdc++.h>
using namespace std;

int main()
{
    int f = 0, b = 0, Q, com, x;
    vector<int> vf, vb;
    cin >> Q;
    while (Q--)
    {
        cin >> com >> x;
        if (com == 1)
        {
            vf.push_back(x);
            f++;
        }
        else if (com == 2)
        {
            vb.push_back(x);
            b++;
        }
        else
        {
            if (x <= f)
                cout << vf[f - x] << endl;
            else
                cout << vb[x - f - 1] << endl;
        }
    }

    return 0;
}
