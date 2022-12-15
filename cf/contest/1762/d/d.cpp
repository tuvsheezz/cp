#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX_N 10010
ll M = 1e9 + 9;
ll P = 9973;

bool solve()
{
  ll n, pi, g = 0;
  cin >> n;

  vector<ll> d(n, 0);
  vector<ll> p(MAX_N);
  for (ll i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      p[j] = gcd(i, j);
    sort(p.begin(), p.end());
    g = 0;
    for (ll i = 0; i < n - 1; i++)
      g = ((g * P) % M + p[i]) % M;
    d[i] = g;
  }

  vector<ll> p2 = {0};
  for (ll i = 1; i < n; i++)
  {
    cout << "? 0 " << i << '\n';
    cout.flush();
    cin >> pi;
    // if (pi == 0)
    // {
    //   cout << "! " << i << " " << i << '\n';
    //   cout.flush();
    //   cin >> pi;
    //   return pi == 1;
    // }
    p2.push_back(pi);
  }
  sort(p2.begin(), p2.end());

  for (ll i = 0; i < n - 1; i++)
    g = ((g * P) % M + p2[i]) % M;

  ll q = 0;
  for (ll i = 0; i < MAX_N; i++)
  {
    if (g == d[i])
      q = i;
  }
  cout << q << endl;

  // cout << "! " << i << " " << i << '\n';
  // cout.flush();
  // cin >> pi;
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
