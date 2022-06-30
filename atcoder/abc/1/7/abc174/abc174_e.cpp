#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ll n, k, l = 0, r = INT64_MAX, m, tmp;
  cin >> n >> k;
  vector<ll> a(n);

  for (int i = 0; i < n; i++)
    cin >> a[i];

  while (l < r - 1)
  {
    tmp = 0;
    m = l + (r - l) / 2;
    for (int i = 0; i < n; i++)
      tmp += (a[i] + m - 1) / m - 1;

    if (tmp > k)
      l = m;
    else
      r = m;
  }
  cout << r << endl;
  return 0;
}
