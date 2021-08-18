
#include <iostream>
#include <vector>

using namespace std;

int solve(int a, int b, int c)
{
  int d = 0;
  if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1)
    return 0;
  if (a == b && b == c)
    return -1;
  while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0)
  {
    int t1 = a, t2 = b, t3 = c;
    a = (t2 + t3) / 2;
    b = (t1 + t3) / 2;
    c = (t1 + t2) / 2;
    d++;
  }
  return d;
}

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  cout << solve(a, b, c) << endl;
  return 0;
}
