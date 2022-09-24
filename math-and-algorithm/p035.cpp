#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll ax, ay, ar, bx, by, br;
    cin >> ax >> ay >> ar >> bx >> by >> br;

    ll dist = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);

    if ((ar - br) * (ar - br) > dist)
    {
        cout << 1 << endl;
        return 0;
    }
    if ((ar - br) * (ar - br) == dist)
    {
        cout << 2 << endl;
        return 0;
    }
    if (dist > (ar + br) * (ar + br))
    {
        cout << 5 << endl;
        return 0;
    }
    if (dist == (ar + br) * (ar + br))
    {
        cout << 4 << endl;
        return 0;
    }
    cout << 3 << endl;
    return 0;
}
