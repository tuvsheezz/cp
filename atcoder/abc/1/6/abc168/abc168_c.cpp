#include <bits/stdc++.h>
using namespace std;
#define FAST                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define M_PI 3.141592653589793238462643383279502884L
#define ll long long
#define dd long double
#define ull unsigned long long
#define str string
#define ivec vector<ll>
#define dvec vector<double>
#define repa(i, s, e) for (ll i = s; i < e; i++)
#define repd(i, s, e) for (ll i = s; i >= e; i--)
#define vsorta(v) sort(v.begin(), v.end())
#define vsortd(v) sort(v.begin(), v.end(), greater<>())
#define sort_arr(v, n) sort(v, v + n)
#define MOD2 998244353
#define MAX_N 100100

int main()
{
  FAST;
  dd a, b, h, m;
  cin >> a >> b >> h >> m;
  dd aa = 30 * h + 0.5 * m;
  dd ba = 6 * m;
  aa = min(abs(aa - ba), 360 - abs(aa - ba));
  cout << setprecision(30) << sqrt(a * a + b * b - 2 * a * b * cos(M_PI / 180 * aa)) << endl;
  return 0;
}