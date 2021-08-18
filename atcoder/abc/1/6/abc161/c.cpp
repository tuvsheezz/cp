#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long

int main()
{
  ll a, b;
  cin >> a >> b;
  cout << min(a % b, abs(b - a % b)) << endl;
  return 0;
}