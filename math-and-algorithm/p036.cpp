#include <bits/stdc++.h>
#define dd double
using namespace std;

int main()
{
    dd a, b, h, m;
    cin >> a >> b >> h >> m;
    dd aa = 30 * h + 0.5 * m;
    dd ba = 6 * m;
    aa = min(abs(aa - ba), 360 - abs(aa - ba));
    cout << setprecision(30) << sqrt(a * a + b * b - 2 * a * b * cos(M_PI / 180 * aa)) << endl;
    return 0;
}
