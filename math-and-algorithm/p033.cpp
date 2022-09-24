#include <bits/stdc++.h>
using namespace std;

int main()
{
    long double ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    long double s = (ay - by) * cx + (cy - ay) * bx + (by - cy) * ax;
    long double a = (cx - bx) * (cx - bx) + (cy - by) * (cy - by);
    long double b = (cx - ax) * (cx - ax) + (cy - ay) * (cy - ay);
    long double c = (bx - ax) * (bx - ax) + (by - ay) * (by - ay);
    long double h = abs(s) / sqrt(a);
    if (a < c - h * h || a < b - h * h)
        cout << setprecision(30) << sqrt(min(b, c)) << endl;
    else
        cout << setprecision(30) << h << endl;
    return 0;
}
