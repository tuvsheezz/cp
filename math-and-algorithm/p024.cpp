#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long n;
  double s = 0, p, q;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> p >> q;
    s += q / p;
  }
  cout << setprecision(10) << s << endl;
  return 0;
}
