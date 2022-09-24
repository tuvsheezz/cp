#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long n;
  double s = 0;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    s += 1.0 * n / i;
  }
  cout << setprecision(14) << s << endl;
  return 0;
}
