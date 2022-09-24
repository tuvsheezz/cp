#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long n;
  double s = 0, p, q;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> p;
    s += p;
  }
  for (int i = 0; i < n; i++)
  {
    cin >> p;
    s += 2 * p;
  }
  cout << setprecision(14) << s / 3 << endl;
  return 0;
}
