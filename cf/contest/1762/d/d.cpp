#include <bits/stdc++.h>
using namespace std;
#define ll long long;

bool solve()
{
  ll n, pi;
  cin >> n;
  vector<ll> p(n);
  for (ll i = 1; i < n; i++)
  {
    cout << "? 0 " << i << '\n';
    cout.flush();
    cin >> p[i];
  }

  cout << "! " << i << " " << i << '\n';
  cout.flush();
  cin >> pi;
  return pi == 1;
}

int main()
{
  ll t;
  cin >> t;
  while (t--)
  {
    auto x = solve();
    if (!x)
      return 0;
  }
  return 0;
}
