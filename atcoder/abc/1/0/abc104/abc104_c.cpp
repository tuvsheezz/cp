#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ll d, g, ans = INT64_MAX;
  cin >> d >> g;
  vector<ll> a(d), c(d);
  for (int i = 0; i < d; i++)
    cin >> a[i] >> c[i];

  for (int bit = 0; bit < (1 << d); bit++)
  {
    ll tmp = 0, cc = 0;
    vector<bool> used(d, false);
    for (int i = 0; i < d; i++)
    {
      if (bit >> i & 1)
      {
        cc += a[i];
        tmp += a[i] * 100 * (i + 1) + c[i];
      }
    }
    ll q = d - 1;
    while (tmp < g && q >= 0)
    {
      if ((bit >> q & 1) == 0)
      {
        if (a[q] * (q + 1) * 100 < g - tmp)
        {
          cc += a[q];
          tmp += a[q] * 100 * (q + 1) + c[q];
        }
        else
        {
          ll pp = (g - tmp + (q + 1) * 100 - 1) / ((q + 1) * 100);
          cc += pp;
          tmp += pp * (q + 1) * 100;
        }
      }
      q--;
    }
    ans = min(ans, cc);
  }
  cout << ans << endl;
  return 0;
}
