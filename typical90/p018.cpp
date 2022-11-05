#include <bits/stdc++.h>
#define PI 3.141592653589793238462643383279502884L
using namespace std;

int main()
{
    double t, l, x, y, q, e;
    cin >> t >> l >> x >> y;
    l /= 2.0;
    cin >> q;
    while (q--)
    {
        cin >> e;
        double alp = e / t * 2 * PI;
        double x1 = 0, y1 = -l * sin(alp), z1 = l - l * cos(alp);
        cout << fixed << setprecision(50);
        cout << 180 / PI * atan2(z1, sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1))) << endl;
    }
    return 0;
}
